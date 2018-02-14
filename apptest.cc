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
HPC Software Testing Suite.
class AppTest source code.

Date Created: Fri Nov 20 20:36:35 MST 2015

Author: Cormac Garvey

*/

#include "apptest.h"

#include <iostream>  // debugging only


namespace hpcswtest {


std::string AppTest::calcStarccmSubArgs(const jobscript::JOBSCRIPT &p_s_o, const std::string &i_f_n, const std::string &j_n) const {
  std::string sub_args_tmp;
  sub_args_tmp = "-i Heated_Fin.sim -b " + i_f_n +
                 " -j " + j_n +
                 " -w " + p_s_o.getWallTime() +
                 " -n " + std::to_string(p_s_o.getTotalNumProcs()) + 
                 " -N " +  std::to_string(p_s_o.getMaxNumProcsPerNode()) + 
                 " -q " + p_s_o.getQueueName();
  return sub_args_tmp;
}


std::string AppTest::calcSubArgs(const jobscript::JOBSCRIPT &p_s_o, const std::string &i_f_n, const std::string &j_n) const {
  std::string sub_args_tmp;
  sub_args_tmp = "-i " + i_f_n +
                 " -j " + j_n +
                 " -w " + p_s_o.getWallTime() +
                 " -n " + std::to_string(p_s_o.getTotalNumProcs()) + 
                 " -N " +  std::to_string(p_s_o.getMaxNumProcsPerNode()) + 
                 " -q " + p_s_o.getQueueName();
  return sub_args_tmp;
}


std::string AppTest::calcGaussianSubArgs(const jobscript::JOBSCRIPT &p_s_o, const std::string &i_f_n, const std::string &j_n) const {
  std::string sub_args_tmp;
  sub_args_tmp = "-i " + i_f_n +
                 " -o " + i_f_n + ".out" +
                 " -j " + j_n +
                 " -w " + p_s_o.getWallTime() +
                 " -q " + p_s_o.getQueueName();
  return sub_args_tmp;
}


std::string AppTest::calcAbaqusSubArgs(const jobscript::JOBSCRIPT &p_s_o, const std::string &i_f_n, const std::string &j_n) const {
  std::string sub_args_tmp;
  sub_args_tmp = "-i " + i_f_n +
                 " -j " + j_n +
                 " -J " + j_n +
                 " -w " + p_s_o.getWallTime() +
                 " -n " + std::to_string(p_s_o.getTotalNumProcs()) + 
                 " -N " +  std::to_string(p_s_o.getMaxNumProcsPerNode()) + 
                 " -q " + p_s_o.getQueueName();
  return sub_args_tmp;
}


std::string AppTest::calcVaspSubArgs(const jobscript::JOBSCRIPT &p_s_o, const std::string &j_n) const {
  std::string sub_args_tmp;
  sub_args_tmp = " -j " + j_n +
                 " -w " + p_s_o.getWallTime() +
                 " -n " + std::to_string(p_s_o.getTotalNumProcs()) + 
                 " -N " +  std::to_string(p_s_o.getMaxNumProcsPerNode()) + 
                 " -q " + p_s_o.getQueueName();
  return sub_args_tmp;
}


std::string AppTest::calcExeArgs(const jobscript::JOBSCRIPT &p_s_o, const std::string &i_f_n) const {
  std::string exe_args_local = p_s_o.getExeArgs();
  exe_args_local = replaceStr(exe_args_local, "INFILE", i_f_n);
  return exe_args_local;
}


std::vector<jobscript::JOBSCRIPT> AppTest::calcJobScripts(const std::string &test_name, const jobscript::JOBSCRIPT &p_s_o, const std::string &e_n) const {
  modules::modules_type ms_tmp(p_s_o.getModules());
  std::vector<jobscript::JOBSCRIPT> p_s_o_tmp;
  std::string exe_args_tmp;
  int ic = 0;
//  std::cout << "Enter AppTest::calcJobScripts sub_app_version" << std::endl;
  for (auto i_f_n: input_file_names_) {
    std::string j_n_local = test_name + "_" + std::to_string(getTestObjectCount()) + "_" + std::to_string(ic);
    if (e_n.find("vasp") != std::string::npos) {
       exe_args_tmp = calcVaspSubArgs(p_s_o, j_n_local);
    } else if (e_n.find("starccm") != std::string::npos) {
       exe_args_tmp = calcStarccmSubArgs(p_s_o, i_f_n, j_n_local);
    } else if (e_n.find("abaqus") != std::string::npos) {
       exe_args_tmp = calcAbaqusSubArgs(p_s_o, i_f_n, j_n_local);
    } else if (e_n.find("gaussian") != std::string::npos) {
       exe_args_tmp = calcGaussianSubArgs(p_s_o, i_f_n, j_n_local);
    } else {
       exe_args_tmp = calcSubArgs(p_s_o, i_f_n, j_n_local);
    }
#ifdef SLURM
    jobscript::SlurmScript job_script(ms_tmp, p_s_o.getTotalNumProcs(), p_s_o.getMaxNumProcsPerNode(), p_s_o.getMpiCmdName(), p_s_o.getMpiCmdArgs(), e_n, exe_args_tmp, j_n_local + ".sbatch", j_n_local, p_s_o.getQueueName(), p_s_o.getWallTime());
#else
    exe_args_tmp = exe_args_tmp + " -P hpc";
    if (p_s_o.getCpuType() != "haswell") {
      exe_args_tmp = exe_args_tmp + " -t " + p_s_o.getCpuType();
    }
    jobscript::PbsScript job_script(ms_tmp, p_s_o.getTotalNumProcs(), p_s_o.getMaxNumProcsPerNode(), p_s_o.getMpiCmdName(), p_s_o.getMpiCmdArgs(), e_n, exe_args_tmp, j_n_local + ".pbs", j_n_local, p_s_o.getQueueName(), p_s_o.getCpuType(), p_s_o.getWallTime(), p_s_o.getPbsArrangement(), p_s_o.getPbsSharing());
#endif
    p_s_o_tmp.push_back(job_script);
    ++ic;
  }
 //  std::cout << "Exit AppTest::calcJobScripts" << std::endl;
  return p_s_o_tmp;
}


std::vector<jobscript::JOBSCRIPT> AppTest::calcJobScripts(const std::string &test_name, const jobscript::JOBSCRIPT &p_s_o) const {
  modules::modules_type ms_tmp(p_s_o.getModules());
  std::vector<jobscript::JOBSCRIPT> p_s_o_tmp;
  std::string exe_args_tmp;
  int ic = 0;
//  std::cout << "Enter AppTest::calcJobScripts job" << std::endl;
  for (auto i_f_n: input_file_names_) {
    std::string j_n_local = test_name + "_" + std::to_string(getTestObjectCount()) + "_" + std::to_string(ic);
    exe_args_tmp = calcExeArgs(p_s_o, i_f_n);
//    std::cout << "(calcJobScripts) exe_args_temp = " << exe_args_tmp << std::endl;
#ifdef SLURM
    jobscript::SlurmScript job_script(ms_tmp, p_s_o.getTotalNumProcs(), p_s_o.getMaxNumProcsPerNode(), p_s_o.getMpiCmdName(), p_s_o.getMpiCmdArgs(), p_s_o.getExeName(), exe_args_tmp, j_n_local + ".sbatch", j_n_local, p_s_o.getQueueName(), p_s_o.getWallTime());
#else
    jobscript::PbsScript job_script(ms_tmp, p_s_o.getTotalNumProcs(), p_s_o.getMaxNumProcsPerNode(), p_s_o.getMpiCmdName(), p_s_o.getMpiCmdArgs(), p_s_o.getExeName(), exe_args_tmp, j_n_local + ".pbs", j_n_local, p_s_o.getQueueName(), p_s_o.getCpuType(), p_s_o.getWallTime(), p_s_o.getPbsArrangement(), p_s_o.getPbsSharing());
#endif
    p_s_o_tmp.push_back(job_script);
    ++ic;
  }
 //  std::cout << "Exit AppTest::calcJobScripts" << std::endl;
  return p_s_o_tmp;
}


AppTest::AppTest(const std::string &s, const std::string &i_f_e, const jobscript::JOBSCRIPT &p_s, int n_inputs, const std::string &e_n): HpcSwTest(s),
                                                                                                                                         job_scripts_(calcJobScripts(s, p_s, e_n)),
                                                                                                                                         input_file_names_(calcInputNames(s, n_inputs, i_f_e)) {}


AppTest::AppTest(const std::string &s, const std::string &i_f_e, const jobscript::JOBSCRIPT &p_s, int n_inputs): HpcSwTest(s), 
                                                                                                                 job_scripts_(calcJobScripts(s, p_s)),
                                                                                                                 input_file_names_(calcInputNames(s, n_inputs, i_f_e)) {}


std::vector<std::string> AppTest::calcInputNames(const std::string &test_name, int n_inputs, const std::string &input_file_ext) const {
  std::vector<std::string> input_file_names_tmp;
  for (auto i=0; i<n_inputs; ++i) {
    input_file_names_tmp.push_back(test_name + "_" + std::to_string(getTestObjectCount()) + "_" + std::to_string(i) + input_file_ext);
  }
  return input_file_names_tmp;
}


std::string AppTest::exeAppTest(std::ofstream &flog, std::ofstream &fresult, const jobscript::JOBSCRIPT &job_script, const std::string &check_file_name) const {
  std::string script_cmd_result;
  std::string module_load_result;
  std::string script_cmd;
  std::string modules_str;

  fresult << module_name_version(job_script.getModules()[job_script.getModules().size()-1]) << "\t" << check_file_name << std::endl;
//  std::cout << job_script.getExeName() << " " << job_script.getExeArgs() << std::endl;
  if (modules_load(flog, job_script.getModules(), module_load_result)) {
    modules_str = modules_string(job_script.getModules());
    script_cmd = " { " + modules_str + ";" + job_script.getExeName() + " " + job_script.getExeArgs() + "; }" + " 2>&1";
    flog << "Submit Command: " << script_cmd << std::endl;
    script_cmd_result = exec(script_cmd.c_str());
  } else {
    script_cmd_result = "fatal";
  }
  return script_cmd_result;
}


std::vector<jobscript::JOBSCRIPT> AppTest::getJobScripts(void) const {
  return job_scripts_;
}


void AppTest::runTest(void) {
  std::cout << "Execute runTest member function from AppTest object" << std::endl;
}


void AppTest::setRunCmd(const std::string &r_c) {
  run_cmd_ = r_c;
}


std::string AppTest::getRunCmd(void) const {
  return run_cmd_;
}


std::vector<std::string> AppTest::getInputFileNames(void) const {
  return input_file_names_;
}



} // namespace hpcswtest

