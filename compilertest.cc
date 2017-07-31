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
subclass of base class SrcTest.
Part of HPC Software Test Suite.

Date Created: Wed Nov 11 13:31:39 MST 2015

Author: Cormac Garvey

*/

#include "compilertest.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> CompilerTest::c_srcs_ = {
R"(
#include <stdio.h>
#include <math.h>
int main(){
  double d, r;
  d = 0.0;
  r = cos(d);
  printf("cos(%4.2f)=%4.2f\n",d,r);
  printf("C code is working\n");
}
)"
}; // vector c_srcs_


const std::vector<std::string> CompilerTest::cpp_srcs_ = { 
R"( 
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
  double d, r;
  d = 0.0;
  r=cos(d);
  cout << setprecision(2) << "cos(" << d << ")=" << setw(2) << r << endl;
  cout << "C code is working\n";
}
)"  
}; // vector cpp_srcs_


const std::vector<std::string> CompilerTest::f_srcs_ = {
R"( 
      program fff 
      double precision d,r 
      d = 0.0 
      r = cos(d)
      write(6,10)d,r
 10   format(1x,'cos(',F6.2,')=',F6.2)
      write(6,*)'F90 code is working'
      end 
)"  
}; // vector f_srcs_



CompilerTest::CompilerTest(const jobscript::PbsScript &p_s, const std::string &c_n, const std::string &cpp_n, const std::string &f_n, const std::string &c_f, const std::string &cpp_f, const std::string &f_f, const std::string &c_l_l, const std::string &cpp_l_l, const std::string &f_l_l): SrcTest("compiler",  p_s, c_n, cpp_n, f_n, c_srcs_.size(), cpp_srcs_.size(), f_srcs_.size(), c_f, cpp_f, f_f, c_l_l, cpp_l_l, f_l_l),
                                                                             log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                                             result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                                             flog_(log_file_name_,std::ios_base::app),
                                                                             fresult_(result_file_name_,std::ios_base::app) {}


void CompilerTest::runTest(void) {
  std::string cmd_result;
  std::string script_cmd_result;
  std::time_t date_result = std::time(NULL);
//  std::cout << "Execute runTest member function from CompilerTest object " << __FILE__ << "\t" <<__LINE__ << std::endl;
  if (!flog_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << log_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  if (!fresult_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << result_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  fresult_ << std::ctime(&date_result) << std::endl;
  fresult_ << getTestName() << " tests run on " << getHostName() << std::endl;
  int c_i = 0;
  if (getCName() != "none") {
  for (auto c_src: c_srcs_) {
//    std::cout << "(CompilerTest::runTest, before compileTest)" << std::endl;
    cmd_result = compileTest(flog_, getCPbsScripts()[c_i], getCSrc(c_i), getCName(), getCFlags(), getCSrcName(c_i), getCExeName(c_i), getCLinkLibs());
//    std::cout << "(CompilerTest::runTest, after compileTest)" << std::endl;
//    checkCompileResult(cmd_result, getCName(), getCPbsScripts()[c_i].getModules()[getCPbsScripts()[c_i].getModules().size()-1].first, getCPbsScripts()[c_i].getModules()[getCPbsScripts()[c_i].getModules().size()-1].second, getCPbsScripts()[c_i].getJobName(), flog_, fresult_);
    checkCompileResult(cmd_result, getCName(), findPrimaryModule(getCPbsScripts()[c_i].getModules()).first, findPrimaryModule(getCPbsScripts()[c_i].getModules()).second, getCPbsScripts()[c_i].getJobName(), flog_, fresult_);
    script_cmd_result = srcExeTest(flog_, getCPbsScripts()[c_i]);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
  }
  c_i = 0;
  if (getCppName() != "none") {
  for (auto cpp_src: cpp_srcs_) {
    cmd_result = compileTest(flog_, getCppPbsScripts()[c_i], getCppSrc(c_i), getCppName(), getCppFlags(), getCppSrcName(c_i), getCppExeName(c_i), getCppLinkLibs());
    checkCompileResult(cmd_result, getCppName(), findPrimaryModule(getCppPbsScripts()[c_i].getModules()).first, findPrimaryModule(getCppPbsScripts()[c_i].getModules()).second, getCppPbsScripts()[c_i].getJobName(), flog_, fresult_);
    script_cmd_result = srcExeTest(flog_, getCppPbsScripts()[c_i]);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
  }
  c_i = 0;
  if (getFName() != "none") {
  for (auto f_src: f_srcs_) {
    cmd_result = compileTest(flog_, getFPbsScripts()[c_i], getFSrc(c_i), getFName(), getFFlags(), getFSrcName(c_i), getFExeName(c_i), getFLinkLibs());
    checkCompileResult(cmd_result, getFName(), findPrimaryModule(getFPbsScripts()[c_i].getModules()).first, findPrimaryModule(getFPbsScripts()[c_i].getModules()).second, getFPbsScripts()[c_i].getJobName(), flog_, fresult_);
    script_cmd_result = srcExeTest(flog_, getFPbsScripts()[c_i]);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
  }
}


int CompilerTest::NumCSrc(void) const {
  return c_srcs_.size();
}


std::string CompilerTest::getCSrc(int i) const {
  if (i >= 0 and i <= NumCSrc()) { 
    return c_srcs_[i];
  } else {
    std::cerr << "Error: Illegal index(" << i << ") in CompilerTest member function getCSrc\n" << std::endl;
    exit(EXIT_FAILURE);
  }
}


int CompilerTest::NumCppSrc(void) const {
  return cpp_srcs_.size();
}


std::string CompilerTest::getCppSrc(int i) const {
  if (i >= 0 and i <= NumCppSrc()) { 
  return cpp_srcs_[i];
  } else {
    std::cerr << "Error: Illegal index(" << i << ") in CompilerTest member function getCppSrc\n" << std::endl;
    exit(EXIT_FAILURE);
  }
}


int CompilerTest::NumFSrc(void) const {
  return f_srcs_.size();
}


std::string CompilerTest::getFSrc(int i) const {
  if (i >= 0 and i <= NumFSrc()) { 
  return f_srcs_[i];
  } else {
    std::cerr << "Error: Illegal index(" << i << ") in CompilerTest member function getFSrc\n" << std::endl;
    exit(EXIT_FAILURE);
  }
}


} // namespace hpcswtest
