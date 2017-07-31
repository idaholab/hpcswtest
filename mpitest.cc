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
mpitest is a subclass of class srctest.
Part of the HPC Software test suite.

Date Created: Sat Nov 14 17:52:12 MST 2015

Author: Cormac Garvey

*/

#include "mpitest.h"
#include <iostream> // for debugging only
#include <cstdlib> // for exit()


namespace hpcswtest {


const std::vector<std::string> MpiTest::c_mpi_srcs_ = {
R"(
#include "mpi.h"
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int rank, size;
    char name[20];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    gethostname(name,20);
    printf("Hello, world, I am %d of %d running on %s\n", rank, size, name);
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();

    return 0;
}
)"
}; // vector c_mpi_srcs_


const std::vector<std::string> MpiTest::cpp_mpi_srcs_ = {
R"(
#include "mpi.h"
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int size, rank;
    char name[20];

    MPI::Init(argc, argv);
    rank = MPI::COMM_WORLD.Get_rank();
    size = MPI::COMM_WORLD.Get_size();
    gethostname(name,20);
    cout << "Hello, world, I am " <<rank <<" of " << size << " running on " << name << endl;
    MPI::COMM_WORLD.Barrier();
    MPI::Finalize();

    return 0;
}
)"
}; //vector cpp_mpi_srcs_


const std::vector<std::string> MpiTest::f_mpi_srcs_ = {
R"(
      program main
      implicit none
      include 'mpif.h'
      integer ierr, rank, size
      integer len_name
      character(len=15):: name 
      call MPI_INIT(ierr)
      call MPI_COMM_RANK(MPI_COMM_WORLD, rank, ierr)
      call MPI_COMM_SIZE(MPI_COMM_WORLD, size, ierr)
      CALL MPI_GET_PROCESSOR_NAME(NAME, LEN_NAME, ierr)
      write(6,*)'Hello, world, I am ',rank,' of ',size,' running on ',NAME
      call MPI_FINALIZE(ierr)
      end
)"
}; //vector f_mpi_srcs_


MpiTest::MpiTest(const jobscript::PbsScript &p_s, const std::string &c_n, const std::string &cpp_n, const std::string &f_n, const std::string &c_f, const std::string &cpp_f, const std::string &f_f, const std::string &c_l_l, const std::string &cpp_l_l, const std::string &f_l_l): SrcTest("mpi", p_s, c_n, cpp_n, f_n, c_mpi_srcs_.size(), cpp_mpi_srcs_.size(), f_mpi_srcs_.size(), c_f, cpp_f, f_f, c_l_l, cpp_l_l, f_l_l),
                    log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
					          result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
	                  flog_(log_file_name_,std::ios_base::app),
	                  fresult_(result_file_name_,std::ios_base::app) {}


void MpiTest::runTest() {
  std::string cmd_result;
  std::string script_cmd_result;
//  std::cout << "Execute runTest member function from MpiTest object " << __FILE__ << "\t" <<__LINE__ << std::endl;
  if (!flog_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << log_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  if (!fresult_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << result_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  int c_i = 0;
  for (auto c_mpi_src: c_mpi_srcs_) {
    cmd_result = compileTest(flog_, getCPbsScripts()[c_i], c_mpi_srcs_[c_i], getCName(), getCFlags(), getCSrcName(c_i), getCExeName(c_i), getCLinkLibs());
    checkCompileResult(cmd_result, getCName(), getCPbsScripts()[c_i].getModules()[getCPbsScripts()[c_i].getModules().size()-1].first, getCPbsScripts()[c_i].getModules()[getCPbsScripts()[c_i].getModules().size()-1].second, getCPbsScripts()[c_i].getJobName(), flog_, fresult_);
    script_cmd_result = srcExeTest(flog_, getCPbsScripts()[c_i]);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
  c_i = 0;
  for (auto cpp_mpi_src: cpp_mpi_srcs_) {
    cmd_result = compileTest(flog_, getCppPbsScripts()[c_i], cpp_mpi_srcs_[c_i], getCppName(), getCppFlags(), getCppSrcName(c_i), getCppExeName(c_i), getCppLinkLibs());
    checkCompileResult(cmd_result, getCppName(), getCppPbsScripts()[c_i].getModules()[getCppPbsScripts()[c_i].getModules().size()-1].first, getCppPbsScripts()[c_i].getModules()[getCppPbsScripts()[c_i].getModules().size()-1].second, getCppPbsScripts()[c_i].getJobName(), flog_, fresult_);
    script_cmd_result = srcExeTest(flog_, getCppPbsScripts()[c_i]);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
  c_i = 0;
  for (auto f_mpi_src: f_mpi_srcs_) {
    cmd_result = compileTest(flog_, getFPbsScripts()[c_i], f_mpi_srcs_[c_i], getFName(), getFFlags(), getFSrcName(c_i), getFExeName(c_i), getFLinkLibs());
    checkCompileResult(cmd_result, getFName(), getFPbsScripts()[c_i].getModules()[getFPbsScripts()[c_i].getModules().size()-1].first, getFPbsScripts()[c_i].getModules()[getFPbsScripts()[c_i].getModules().size()-1].second, getFPbsScripts()[c_i].getJobName(), flog_, fresult_);
    script_cmd_result = srcExeTest(flog_, getFPbsScripts()[c_i]);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }

}


void MpiTest::setMpiCmd(std::string s) {
	mpi_cmd_ = s;
}


void MpiTest::setMpiCmdArgs(std::string s) {
	mpi_cmd_args_ = s;
}


} // namespace hpcswtest
