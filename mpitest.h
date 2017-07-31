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

#ifndef HPCSWTEST_MPITEST_H_
#define HPCSWTEST_MPITEST_H_

#include "srctest.h"
#include <fstream>


namespace hpcswtest {


class MpiTest: public SrcTest {

public:
	MpiTest(const jobscript::PbsScript &, const std::string &, const std::string &, const std::string &, const std::string &c_f="-O2", const std::string &cpp_f="-O2", const std::string &f_f="-O2", const std::string &c_l_l="-lm", const std::string &cpp_l_l="-lm", const std::string &f_l_l="-lm");
	virtual ~MpiTest(void) {};
	virtual void runTest(void) override;
//	virtual TestResult checkResult(void) const override;
	void setMpiCmd(std::string);
	void setMpiCmdArgs(std::string);
	std::string getMpiCmd(void);
	std::string getMpiCmdArgs(void);

private:
	std::string log_file_name_;
	std::string result_file_name_;
  std::ofstream flog_;
	std::ofstream fresult_;
	std::string mpi_cmd_;
	std::string mpi_cmd_args_;

  const static std::vector<std::string> c_mpi_srcs_;
  const static std::vector<std::string> cpp_mpi_srcs_;
  const static std::vector<std::string> f_mpi_srcs_;

}; // class MpiTest


} // namespace hpcswtest

#endif  // HPCSWTEST_MPITEST_H

