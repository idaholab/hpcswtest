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
SrcTest subclass source code, abstract base class is HpcSwTest.
Part of HPC Software Testing Suite.

Date Created: Wed Nov 11 12:08:14 MST 2015

Author: Cormac Garvey

*/


#include "srctest.h"

#include <iostream>      // only for debugging
#include <cstdlib>    // exit


namespace hpcswtest {


std::vector<jobscript::JOBSCRIPT> SrcTest::calcCJobScripts(const jobscript::JOBSCRIPT &p_s_o) const {
  modules::modules_type ms_tmp(p_s_o.getModules());
  std::vector<jobscript::JOBSCRIPT> p_s_o_tmp;
  int ic = 0;
//  std::cout << "Enter CompilerTest::calcCJobScripts" << std::endl;
  for (auto c_e_n: c_exe_names_) {
#ifdef SLURM
    jobscript::SlurmScript job_script(ms_tmp, p_s_o.getTotalNumProcs(), p_s_o.getMaxNumProcsPerNode(), p_s_o.getMpiCmdName(), p_s_o.getMpiCmdArgs(), c_e_n, "", "c_script_" + std::to_string(getTestObjectCount()) + "_" +  std::to_string(ic) + ".sbatch", "c_script_" + std::to_string(getTestObjectCount()) + "_" + std::to_string(ic), p_s_o.getQueueName(), p_s_o.getCpuType(), p_s_o.getWallTime());
#else
    jobscript::PbsScript job_script(ms_tmp, p_s_o.getTotalNumProcs(), p_s_o.getMaxNumProcsPerNode(), p_s_o.getMpiCmdName(), p_s_o.getMpiCmdArgs(), c_e_n, "", "c_script_" + std::to_string(getTestObjectCount()) + "_" +  std::to_string(ic) + ".pbs", "c_script_" + std::to_string(getTestObjectCount()) + "_" + std::to_string(ic), p_s_o.getQueueName(), p_s_o.getCpuType(), p_s_o.getWallTime(), p_s_o.getPbsArrangement(), p_s_o.getPbsSharing());
#endif
     p_s_o_tmp.push_back(job_script);
     ++ic;
  }                                                                          
//  std::cout << "Exit CompilerTest::calcCJobScripts" << std::endl;            
  return p_s_o_tmp;
}


std::vector<jobscript::JOBSCRIPT> SrcTest::calcCppJobScripts(const jobscript::JOBSCRIPT &p_s_o) const {
  modules::modules_type ms_tmp(p_s_o.getModules());
  std::vector<jobscript::JOBSCRIPT> p_s_o_tmp;
  int ic = 0;
//  std::cout << "Enter CompilerTest::calcCppJobScripts" << std::endl;
  for (auto cpp_e_n: cpp_exe_names_) {
#ifdef SLURM
    jobscript::SlurmScript job_script(ms_tmp, p_s_o.getTotalNumProcs(), p_s_o.getMaxNumProcsPerNode(), p_s_o.getMpiCmdName(), p_s_o.getMpiCmdArgs(), cpp_e_n, "", "cpp_script_" + std::to_string(getTestObjectCount()) + "_" +  std::to_string(ic) + ".sbatch", "cpp_script_" + std::to_string(getTestObjectCount()) + "_" + std::to_string(ic), p_s_o.getQueueName(), p_s_o.getCpuType(), p_s_o.getWallTime());
#else
    jobscript::JOBSCRIPT job_script(ms_tmp, p_s_o.getTotalNumProcs(), p_s_o.getMaxNumProcsPerNode(), p_s_o.getMpiCmdName(), p_s_o.getMpiCmdArgs(), cpp_e_n, "", "cpp_script_" + std::to_string(getTestObjectCount()) + "_" +  std::to_string(ic) + ".pbs", "cpp_script_" + std::to_string(getTestObjectCount()) + "_" + std::to_string(ic), p_s_o.getQueueName(), p_s_o.getCpuType(), p_s_o.getWallTime(), p_s_o.getPbsArrangement(), p_s_o.getPbsSharing());
#endif
     p_s_o_tmp.push_back(job_script);
     ++ic;
  }                                                                          
//  std::cout << "Exit CompilerTest::calcCppJobScripts" << std::endl;            
  return p_s_o_tmp;
}


std::vector<jobscript::JOBSCRIPT> SrcTest::calcFJobScripts(const jobscript::JOBSCRIPT &p_s_o) const {
  modules::modules_type ms_tmp(p_s_o.getModules());
  std::vector<jobscript::JOBSCRIPT> p_s_o_tmp;
  int ic = 0;
//  std::cout << "Enter CompilerTest::calcFJobScripts" << std::endl;
  for (auto f_e_n: f_exe_names_) {
#ifdef SLURM
    jobscript::SlurmScript job_script(ms_tmp, p_s_o.getTotalNumProcs(), p_s_o.getMaxNumProcsPerNode(), p_s_o.getMpiCmdName(), p_s_o.getMpiCmdArgs(), f_e_n, "", "f_script_" + std::to_string(getTestObjectCount()) + "_" +  std::to_string(ic) + ".sbatch", "f_script_" + std::to_string(getTestObjectCount()) + "_" + std::to_string(ic), p_s_o.getQueueName(), p_s_o.getCpuType(), p_s_o.getWallTime());
#else
    jobscript::JOBSCRIPT job_script(ms_tmp, p_s_o.getTotalNumProcs(), p_s_o.getMaxNumProcsPerNode(), p_s_o.getMpiCmdName(), p_s_o.getMpiCmdArgs(), f_e_n, "", "f_script_" + std::to_string(getTestObjectCount()) + "_" +  std::to_string(ic) + ".pbs", "f_script_" + std::to_string(getTestObjectCount()) + "_" + std::to_string(ic), p_s_o.getQueueName(), p_s_o.getCpuType(), p_s_o.getWallTime(), p_s_o.getPbsArrangement(), p_s_o.getPbsSharing());
#endif
     p_s_o_tmp.push_back(job_script);
     ++ic;
  }                                                                          
//  std::cout << "Exit CompilerTest::calcFJobScripts" << std::endl;            
  return p_s_o_tmp;
}


SrcTest::SrcTest(const std::string &s, const jobscript::JOBSCRIPT &p_s, const std::string &c_n, const std::string &cpp_n, const std::string &f_n, int n_c_srcs, int n_cpp_srcs, int n_f_srcs, const std::string &c_f, const std::string &cpp_f, const std::string &f_f, const std::string &c_l_l, const std::string &cpp_l_l, const std::string &f_l_l): 
                                                                                                   HpcSwTest(s),
                                                                                                   c_name_(c_n),
                                                                                                   cpp_name_(cpp_n),
                                                                                                   f_name_(f_n),
                                                                                                   c_job_scripts_(calcCJobScripts(p_s)),
                                                                                                   cpp_job_scripts_(calcCppJobScripts(p_s)),
                                                                                                   f_job_scripts_(calcFJobScripts(p_s)),
                                                                                                   c_src_names_(calcCSrcNames(n_c_srcs)),
                                                                                                   cpp_src_names_(calcCppSrcNames(n_cpp_srcs)),
                                                                                                   f_src_names_(calcFSrcNames(n_f_srcs)),
                                                                                                   c_exe_names_(calcCExeNames(n_c_srcs)),
                                                                                                   cpp_exe_names_(calcCppExeNames(n_cpp_srcs)),
                                                                                                   f_exe_names_(calcFExeNames(n_f_srcs)),
                                                                                                   c_flags_(c_f),
                                                                                                   cpp_flags_(cpp_f),
                                                                                                   f_flags_(f_f),
                                                                                                   c_link_libs_(c_l_l),
                                                                                                   cpp_link_libs_(cpp_l_l),
                                                                                                   f_link_libs_(f_l_l) {}


std::vector<std::string> SrcTest::calcCSrcNames(int n_c_srcs) const {
  std::vector<std::string> c_src_names_tmp;
  for (auto i=0; i<n_c_srcs; ++i) {
    c_src_names_tmp.push_back("c_src_" + std::to_string(getTestObjectCount()) + "_" + std::to_string(i) + ".c");
  }
//  std::cout << "CompilerTest::calcCSrcNames c_src_names_tmp.size() = " << c_src_names_tmp.size() << std::endl;
  return c_src_names_tmp;
}


std::vector<std::string> SrcTest::calcCppSrcNames(int n_cpp_srcs) const {
  std::vector<std::string> cpp_src_names_tmp;
  for (auto i=0; i<n_cpp_srcs; ++i) {
    cpp_src_names_tmp.push_back("cpp_src_" + std::to_string(getTestObjectCount()) + "_" + std::to_string(i) + ".cpp");
  }
  return cpp_src_names_tmp;
}


std::vector<std::string> SrcTest::calcFSrcNames(int n_f_srcs) const {
  std::vector<std::string> f_src_names_tmp;
  for (auto i=0; i<n_f_srcs; ++i) {
    f_src_names_tmp.push_back("f_src_" + std::to_string(getTestObjectCount()) + "_" + std::to_string(i) + ".f90");
  }
  return f_src_names_tmp;
}


std::vector<std::string> SrcTest::calcCExeNames(int n_c_srcs) const {
  std::vector<std::string> c_exe_names_tmp;
  for (auto i=0; i<n_c_srcs; ++i) {
    c_exe_names_tmp.push_back("c_exe_" + std::to_string(getTestObjectCount()) + "_" + std::to_string(i));
  }
  return c_exe_names_tmp;
}


std::vector<std::string> SrcTest::calcCppExeNames(int n_cpp_srcs) const {
//  std::cout << "enter CompilerTest::calcCppExeNames" << std::endl;
  std::vector<std::string> cpp_exe_names_tmp;
  for (auto i=0; i<n_cpp_srcs; ++i) {
    cpp_exe_names_tmp.push_back("cpp_exe_" + std::to_string(getTestObjectCount()) + "_" + std::to_string(i));
  }
  return cpp_exe_names_tmp;
}


std::vector<std::string> SrcTest::calcFExeNames(int n_f_srcs) const {
  std::vector<std::string> f_exe_names_tmp;
  for (auto i=0; i<n_f_srcs; ++i) {
    f_exe_names_tmp.push_back("f_exe_"+  std::to_string(getTestObjectCount()) + "_" + std::to_string(i));
  }
  return f_exe_names_tmp;
}


void SrcTest::runTest(void) {
  std::cout << "Execute runTest member function from SrcTest object" << std::endl;
}


void SrcTest::setCName(const std::string &c_n) {
  c_name_ = c_n;
}


void SrcTest::setCppName(const std::string &cpp_n) {
  cpp_name_ = cpp_n;
}


void SrcTest::setFName(const std::string &f_n) {
  f_name_ = f_n;
}


void SrcTest::setCFlags(const std::string &c_f) {
  c_flags_ = c_f;
}


void SrcTest::setCppFlags(const std::string &cpp_f) {
  cpp_flags_ = cpp_f;
}


void SrcTest::setFFlags(const std::string &f_f) {
  f_flags_ = f_f;
}


void SrcTest::setCLinkLibs(const std::string &c_ll) {
  c_link_libs_ = c_ll;
}


void SrcTest::setCppLinkLibs(const std::string &cpp_ll) {
  cpp_link_libs_ = cpp_ll;
}


void SrcTest::setFLinkLibs(const std::string &f_ll) {
  f_link_libs_ = f_ll;
}


std::string SrcTest::getCName(void) const {
  return c_name_;
}


std::string SrcTest::getCppName(void) const {
  return cpp_name_;
}


std::string SrcTest::getFName(void) const {
  return f_name_;
}


int SrcTest::numCSrcName(void) const {
  return c_src_names_.size();
}


int SrcTest::numCppSrcName(void) const {
  return cpp_src_names_.size();
}


int SrcTest::numFSrcName(void) const {
  return f_src_names_.size();
}


std::string SrcTest::getCSrcName(int i) const {
  if (i >= 0 and i <= numCSrcName()) {
    return c_src_names_[i];
  } else {
    std::cerr << "Error: Illegal index(" << i << ") in SrcTest member function getCSrcName\n" << std::endl;
    exit(EXIT_FAILURE);
  }
}


std::string SrcTest::getCppSrcName(int i) const {
  if (i >= 0 and i <= numCppSrcName()) {
    return cpp_src_names_[i];
  } else {
    std::cerr << "Error: Illegal index(" << i << ") in SrcTest member function getCppSrcName\n" << std::endl;
    exit(EXIT_FAILURE);
  }
}


std::string SrcTest::getFSrcName(int i) const {
  if (i >= 0 and i <= numFSrcName()) {
    return f_src_names_[i];
  } else {
    std::cerr << "Error: Illegal index(" << i << ") in SrcTest member function getFSrcName\n" << std::endl;
    exit(EXIT_FAILURE);
  }
}


std::string SrcTest::getCExeName(int i) const {
  std::cout << numCSrcName();
  if (i >= 0 and i <= numCSrcName()) {
    return c_exe_names_[i];
  } else {
    std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << " Illegal index(" << i << ")\n" << std::endl;
    exit(EXIT_FAILURE);
  }
}


std::string SrcTest::getCppExeName(int i) const {
  if (i >= 0 and i <= numCppSrcName()) {
    return cpp_exe_names_[i];
  } else {
    std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << " Illegal index(" << i << ")\n" << std::endl;
    exit(EXIT_FAILURE);
  }
}


std::string SrcTest::getFExeName(int i) const {
  if (i >= 0 and i <= numFSrcName()) {
    return f_exe_names_[i];
  } else {
    std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << " Illegal index(" << i << ")\n" << std::endl;
    exit(EXIT_FAILURE);
  }
}


std::string SrcTest::getCFlags(void) const {
  return c_flags_;
}


std::string SrcTest::getCppFlags(void) const {
  return cpp_flags_;
}


std::string SrcTest::getFFlags(void) const {
  return f_flags_;
}


std::string SrcTest::getCLinkLibs(void) const {
  return c_link_libs_;
}


std::string SrcTest::getCppLinkLibs(void) const {
  return cpp_link_libs_;
}


std::string SrcTest::getFLinkLibs(void) const {
  return f_link_libs_;
}


std::vector<jobscript::JOBSCRIPT> SrcTest::getCJobScripts(void) const {
  return c_job_scripts_;
}


std::vector<jobscript::JOBSCRIPT> SrcTest::getCppJobScripts(void) const {
  return cpp_job_scripts_;
}


std::vector<jobscript::JOBSCRIPT> SrcTest::getFJobScripts(void) const {
  return f_job_scripts_;
}


std::string SrcTest::compileCmd(const modules::modules_type &modules, const std::string &c_name, const std::string &c_flags, const std::string &c_src_name, const std::string &c_exe_name, const std::string &c_link_libs) const {
  std::string modules_str_tmp;
//  std::cout << "(SrcTest::compileCmd) enter" << std::endl;
  modules_str_tmp = modules_string(modules);
  if (!modules_str_tmp.empty()) {
    return "module purge;" + modules_str_tmp + ";" + c_name + " " + c_flags + " " + c_src_name + " -o" + " " + c_exe_name + " " + c_link_libs + " 2>&1";
  } else {
    return "module purge;" + c_name + " " + c_flags + " " + c_src_name + " -o" + " " + c_exe_name + " " + c_link_libs + " 2>&1";
  }
}


std::string SrcTest::compileTest(std::ofstream &flog, const jobscript::JOBSCRIPT &job_script, const std::string &src, const std::string &compiler_name, const std::string &compiler_flags, const std::string &src_name, const std::string &exe_name, const std::string &link_libs) const {
  std::string module_load_result;
  std::string compile_cmd;
  std::string cmd_result;
  int c_i = 0;
//  std::cout << "(SrcTest::compileTest) enter" << std::endl;

  std::ofstream fout_c(src_name, std::ios_base::out);
  fout_c << src << std::endl;
	flog << "Running Compiler Test: " << findPrimaryModule(job_script.getModules()).first << "\t" << findPrimaryModule(job_script.getModules()).second << "\t" << compiler_name << "\t" << src_name << std::endl;
  if (modules_load(flog, job_script.getModules(), module_load_result)) {
    compile_cmd = compileCmd(job_script.getModules(), compiler_name, compiler_flags, src_name, exe_name, link_libs);
    flog << "Compile command: " << compile_cmd << std::endl;
    cmd_result = exec(compile_cmd.c_str());
  } else {
    cmd_result = "fatal";
  }
  return cmd_result;
}


std::string SrcTest::srcExeTest(std::ofstream &flog, jobscript::JOBSCRIPT &job_script) const {
  std::string script_cmd_result;
  std::string script_cmd;

  job_script.generate();
//  std::cout << job_script.getJobScriptName() << std::endl;
  script_cmd = "qsub -P hpc " + job_script.getJobScriptName() + " 2>&1";
  flog << "Submit Command: " << script_cmd << std::endl;
  script_cmd_result = exec(script_cmd.c_str());
  return script_cmd_result;
}


void SrcTest::checkCompileResult(const std::string &result, const std::string &compiler_name, const std::string &module_name, const std::string &module_version, const std::string &job_name, std::ofstream &flog, std::ofstream &fresult) const {
  std::regex compile_regex("error|fatal|found|undefined|No such file|cannot find", std::regex_constants::icase);
  if (result.size() == 0) {
    flog << "Compile : " << module_name << "\t" << module_version << "(" << compiler_name << ")" << "\t" << "passed" << std::endl;
    std::cout << "Compile : " << module_name << "\t" << module_version << " (" << compiler_name << ")" << "\t" << "passed" << std::endl;
    fresult << module_name_version({module_name, module_version}) << "\t" << compiler_name << "\t" << job_name << "\t" << "passed" << std::endl; 
  } else if (std::regex_search(result, compile_regex)){
    flog << "Compile test : " << module_name << "\t" << module_version << " (" << compiler_name << ")" << "\t" << "failed" << std::endl;
    flog << result << std::endl;
    std::cout << "Compile : " << module_name << "\t" << module_version << " (" << compiler_name << ")" << "\t" << "failed" << std::endl;
    fresult << module_name_version({module_name, module_version}) << "\t" << compiler_name << "\t" << job_name << "\t" << "failed" << std::endl;
  } else {
    flog << "Compile test : " << module_name << "\t" << module_version << " (" << compiler_name << ")" << "\t" << "check" << std::endl;
    flog << result << std::endl;
    std::cout << "Compile : " << module_name << "\t" << module_version << " (" << compiler_name << ")" << "\t" << "check" << std::endl;
    fresult << module_name_version({module_name, module_version}) << "\t" << compiler_name << "\t" << job_name << "\t" << "check" << std::endl;
  }

}


} // namespace hpcswtest

