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
HPC Software Test Suite.
class BlasTest source code.

Date Created: Fri Nov 20 15:32:24 MST 2015

Author: Cormac Garvey

*/

#include "blastest.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> BlasTest::c_blas_srcs_ = {};


const std::vector<std::string> BlasTest::cpp_blas_srcs_ = {};


const std::vector<std::string> BlasTest::f_blas_srcs_ = {
R"(
      program lll
      real(kind=8), dimension(2,2) :: A,B,C
      do j = 1, 2
         do i = 1, 2
            A(i,j) = dble(i*j)
            B(i,j) = dble(i*j)
         enddo
      enddo
      call DGEMM('N','N',2,2,2,1.0d0,A,2,B,2,0.0d0,C,2)
!   do j = 1, 2
!   do i = 1, 2
!      write(6,*)'C(',i,j,')=',C(i,j)
!   enddo
!   enddo
!   write(6,*)'SUM A =',SUM(A),' SUM B = ',SUM(B)
      write(6,*)'SUM C =',INT(SUM(C))
      end
)"
}; // vector f_blas_srcs_



BlasTest::BlasTest(const jobscript::PbsScript &p_s, const std::string &c_n, const std::string &cpp_n, const std::string &f_n, const std::string &c_f, const std::string &cpp_f, const std::string &f_f, const std::string &c_l_l, const std::string &cpp_l_l, const std::string &f_l_l): LibTest("blas", p_s, c_n, cpp_n, f_n, c_blas_srcs_.size(), cpp_blas_srcs_.size(), f_blas_srcs_.size(), c_f, cpp_f, f_f, c_l_l, cpp_l_l, f_l_l),
												log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
												result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
												flog_(log_file_name_,std::ios_base::app),
												fresult_(result_file_name_,std::ios_base::app) {}


void BlasTest::runTest() {

  std::string cmd_result;
  std::string script_cmd_result;
//  std::cout << "Execute runTest member function from BlasTest object " << __FILE__ << "\t" <<__LINE__ << std::endl;
  if (!flog_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << log_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  if (!fresult_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << result_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  int c_i = 0;
  for (auto c_blas_src: c_blas_srcs_) {
    cmd_result = compileTest(flog_, getCPbsScripts()[c_i], c_blas_srcs_[c_i], getCName(), getCFlags(), getCSrcName(c_i), getCExeName(c_i), getCLinkLibs());
    checkCompileResult(cmd_result, getCName(), getCPbsScripts()[c_i].getModules()[getCPbsScripts()[c_i].getModules().size()-1].first, getCPbsScripts()[c_i].getModules()[getCPbsScripts()[c_i].getModules().size()-1].second, getCPbsScripts()[c_i].getJobName(), flog_, fresult_);
    script_cmd_result = srcExeTest(flog_, getCPbsScripts()[c_i]);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
  c_i = 0;
  for (auto cpp_blas_src: cpp_blas_srcs_) {
    cmd_result = compileTest(flog_, getCppPbsScripts()[c_i], cpp_blas_srcs_[c_i], getCppName(), getCppFlags(), getCppSrcName(c_i), getCppExeName(c_i), getCppLinkLibs());
    checkCompileResult(cmd_result, getCppName(), getCppPbsScripts()[c_i].getModules()[getCppPbsScripts()[c_i].getModules().size()-1].first, getCppPbsScripts()[c_i].getModules()[getCppPbsScripts()[c_i].getModules().size()-1].second, getCppPbsScripts()[c_i].getJobName(), flog_, fresult_);
    script_cmd_result = srcExeTest(flog_, getCppPbsScripts()[c_i]);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
  c_i = 0;
  for (auto f_blas_src: f_blas_srcs_) {
    cmd_result = compileTest(flog_, getFPbsScripts()[c_i], f_blas_srcs_[c_i], getFName(), getFFlags(), getFSrcName(c_i), getFExeName(c_i), getFLinkLibs());
    checkCompileResult(cmd_result, getFName(), getFPbsScripts()[c_i].getModules()[getFPbsScripts()[c_i].getModules().size()-1].first, getFPbsScripts()[c_i].getModules()[getFPbsScripts()[c_i].getModules().size()-1].second, getFPbsScripts()[c_i].getJobName(), flog_, fresult_);
    script_cmd_result = srcExeTest(flog_, getFPbsScripts()[c_i]);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
}


} // namespace hpcswtest

