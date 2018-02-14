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
NwchemTest subclass source code.

Date Created: Mon Jan 29 14:56:30 MST 2018

Author: Cormac Garvey

*/

#include "nwchemtest.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> NwchemTest::nwchem_inputs_ = {
R"(title "formaldehyde ECP deck"

start ecpchho

geometry units au
  C         0.000000  0.000000 -1.025176
  O         0.000000  0.000000  1.280289
  H         0.000000  1.767475 -2.045628
  H         0.000000 -1.767475 -2.045628
end

basis 
  C  SP
   0.1675097360D+02 -0.7812840500D-01  0.3088908800D-01
   0.2888377460D+01 -0.3741108860D+00  0.2645728130D+00
   0.6904575040D+00  0.1229059640D+01  0.8225024920D+00
  C  SP
   0.1813976910D+00  0.1000000000D+01  0.1000000000D+01
  C  D
   0.8000000000D+00  0.1000000000D+01
  C  F
   0.1000000000D+01  0.1000000000D+01
  O  SP
   0.1842936330D+02 -0.1218775590D+00  0.5975796600D-01
   0.4047420810D+01 -0.1962142380D+00  0.3267825930D+00
   0.1093836980D+01  0.1156987900D+01  0.7484058930D+00
  O  SP
   0.2906290230D+00  0.1000000000D+01  0.1000000000D+01
  O  D
   0.8000000000D+00  0.1000000000D+01
  O  F
   0.1100000000D+01  0.1000000000D+01
  H  S
   0.1873113696D+02  0.3349460434D-01
   0.2825394365D+01  0.2347269535D+00
   0.6401216923D+00  0.8137573262D+00
  H  S   
   0.1612777588D+00  0.1000000000D+01
end

ecp
  C nelec 2
  C ul
        1       80.0000000       -1.60000000
        1       30.0000000       -0.40000000
        2        0.5498205       -0.03990210
  C s
        0        0.7374760        0.63810832
        0      135.2354832       11.00916230
        2        8.5605569       20.13797020
  C p
        2       10.6863587       -3.24684280
        2       23.4979897        0.78505765
  O nelec 2
  O ul
        1       80.0000000       -1.60000000
        1       30.0000000       -0.40000000
        2        1.0953760       -0.06623814
  O s
        0        0.9212952        0.39552179
        0       28.6481971        2.51654843
        2        9.3033500       17.04478500
  O p
        2       52.3427019       27.97790770
        2       30.7220233      -16.49630500
end

scf
  vectors input hcore
  maxiter 20
end

task scf)"
}; // vector nwchem_inputs_


std::string NwchemTest::exeAppTest(std::ofstream &flog, std::ofstream &fresult, const jobscript::JOBSCRIPT &job_script, const std::string &dir_path) const {
  std::string script_cmd_result;
  std::string module_load_result;
  std::string script_cmd;
  std::string modules_str;

//  job_script.generate();
  fresult << module_name_version(job_script.getModules()[job_script.getModules().size()-1]) << "\t" << dir_path << "\t" << job_script.getJobName() << std::endl;
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



NwchemTest::NwchemTest(const jobscript::JOBSCRIPT &p_s): AppTest("nwchem", "", p_s ,nwchem_inputs_.size()),
                                                     log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                     result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                     flog_(log_file_name_,std::ios_base::app),
                                                     fresult_(result_file_name_,std::ios_base::app) {}


NwchemTest::NwchemTest(const jobscript::JOBSCRIPT &p_s, const std::string &e_n): AppTest("nwchem", "", p_s ,nwchem_inputs_.size(), e_n),
                                                                             log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                                             result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                                             flog_(log_file_name_,std::ios_base::app),
                                                                             fresult_(result_file_name_,std::ios_base::app) {}


void NwchemTest::runTest() {
  std::string cmd_result;
  std::string script_cmd_result;
  std::string nwchem_dir;
//  std::cout << "Execute runTest member function from NwchemTest object " << __FILE__ << "\t" <<__LINE__ << "\t" << getTestObjectCount() << "\t" << getTestNumber() << std::endl;
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
  for (auto nwchem_input: nwchem_inputs_) {
    nwchem_dir = "nwchem_" + std::to_string(getTestNumber()) + "_" + std::to_string(c_i);
    makeDir(nwchem_dir);
    changeDir(nwchem_dir);
    createFileFromStr(getInputFileNames()[c_i], nwchem_input);
    script_cmd_result = exeAppTest(flog_, fresult_, getJobScripts()[c_i], nwchem_dir);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    changeDir("..");
    ++c_i;
  }
}


} // namespace hpcswtest

