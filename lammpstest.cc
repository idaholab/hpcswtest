/*

Copyright 2017 Battelle Energy Alliance, LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


Description
-----------
HPC Software testing suite.
LammpsTest subclass source code.

Date Created: Mon Jan 29 14:56:30 MST 2018

Author: Cormac Garvey

*/

#include "lammpstest.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> LammpsTest::lammps_inputs_ = {
R"(units           lj
atom_style	sphere
dimension	2

lattice		sq 0.01
region		box block 0 30 0 30 -0.5 0.5
create_box	2 box
create_atoms	1 box

set		group all type/fraction 2 0.96 23984

set		type 1 mass 9
set		type 2 mass 1

velocity	all create 1.44 87287 loop geom

# multi neighbor and comm for efficiency

neighbor	1 multi
neigh_modify	delay 0
comm_modify     mode multi

# colloid potential

pair_style	colloid 12.5
pair_coeff	1 1  1.0 1.0 5.0 5.0 12.5
pair_coeff	1 2  5.0 1.0 5.0 0.0 7.0
pair_coeff	2 2 10.0 1.0 0.0 0.0 2.5

fix		1 all npt temp 2.0 2.0 1.0 iso 0.0 1.0 10.0 drag 1.0 &
	        mtk no pchain 0 tchain 1
fix		2 all enforce2d

#dump		1 all atom 1000 dump.colloid

#dump		2 all image 1000 image.*.jpg type type &
#		zoom 1.5 center d 0.5 0.5 0.5
#dump_modify	2 pad 5 adiam 1 5.0 adiam 2 1.5

#dump		3 all movie 1000 movie.mpg type type &
#		zoom 1.5 center d 0.5 0.5 0.5
#dump_modify	3 pad 5 adiam 1 5.0 adiam 2 1.5

thermo_style	custom step temp epair etotal press vol
thermo		1000

timestep	0.005

run		50000)"
}; // vector lammps_inputs_


std::string LammpsTest::exeAppTest(std::ofstream &flog, std::ofstream &fresult, const jobscript::JOBSCRIPT &job_script, const std::string &dir_path) const {
  std::string script_cmd_result;
  std::string module_load_result;
  std::string script_cmd;
  std::string modules_str;

//  job_script.generate();
  fresult << module_name_version(job_script.getModules()[job_script.getModules().size()-1]) << "\t" << dir_path << "\t" << job_script.getJobName() << " job." << std::endl;
//  std::cout << job_script.getExeName() << " " << job_script.getExeArgs() << std::endl;
  if (modules_load(flog, job_script.getModules(), module_load_result)) {
    modules_str = modules_string(job_script.getModules());
#ifdef SLURM
    script_cmd = "module purge;" + modules_str + ";" + job_script.getExeName() + " " + job_script.getExeArgs() + " 2>&1";
#else
    script_cmd = "module purge;module load pbs;" + modules_str + ";" + job_script.getExeName() + " " + job_script.getExeArgs() + " 2>&1";
#endif
    flog << "Submit Command: " << script_cmd << std::endl;
    script_cmd_result = exec(script_cmd.c_str());
  } else {
    script_cmd_result = "fatal";
  }
  return script_cmd_result;
}



LammpsTest::LammpsTest(const jobscript::JOBSCRIPT &p_s): AppTest("lammps", "", p_s ,lammps_inputs_.size()),
                                                     log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                     result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                     flog_(log_file_name_,std::ios_base::app),
                                                     fresult_(result_file_name_,std::ios_base::app) {}


LammpsTest::LammpsTest(const jobscript::JOBSCRIPT &p_s, const std::string &e_n): AppTest("lammps", "", p_s ,lammps_inputs_.size(), e_n),
                                                                             log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                                             result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                                             flog_(log_file_name_,std::ios_base::app),
                                                                             fresult_(result_file_name_,std::ios_base::app) {}


void LammpsTest::runTest() {
  std::string cmd_result;
  std::string script_cmd_result;
  std::string lammps_dir;
//  std::cout << "Execute runTest member function from LammpsTest object " << __FILE__ << "\t" <<__LINE__ << "\t" << getTestObjectCount() << "\t" << getTestNumber() << std::endl;
  if (!flog_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << log_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  if (!fresult_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << result_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  std::cout << "Testing: " << module_name_version(getJobScripts()[0].getModules()[getJobScripts()[0].getModules().size()-1]) << std::endl;
  int c_i = 0;
  for (auto lammps_input: lammps_inputs_) {
    lammps_dir = "lammps_" + std::to_string(getTestNumber()) + "_" + std::to_string(c_i);
    makeDir(lammps_dir);
    changeDir(lammps_dir);
    createFileFromStr(getInputFileNames()[c_i], lammps_input);
    script_cmd_result = exeAppTest(flog_, fresult_, getJobScripts()[c_i], lammps_dir);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    changeDir("..");
    ++c_i;
  }
}


} // namespace hpcswtest

