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
HPC Software test suite.
BlasTest is a subclass of base class LibTest.

Date Created: Fri Nov 20 15:25:32 MST 2015

Author: Cormac Garvey

*/

#ifndef HPCSWTEST_BLASTEST_H_
#define HPCSWTEST_BLASTEST_H_

#include "libtest.h"

#include <fstream>


namespace hpcswtest {

class BlasTest: public LibTest {

	public:
		BlasTest(const jobscript::PbsScript &, const std::string &, const std::string &, const std::string &, const std::string &c_f="-O2", const std::string &cpp_f="-O2", const std::string &f_f="-O2", const std::string &c_l_l="-lm", const std::string &cpp_l_l="-lm", const std::string &f_l_l="-lm");
		virtual ~BlasTest(void) {};
		virtual void runTest(void) override;

	private:
		std::string log_file_name_;
		std::string result_file_name_;
		std::ofstream flog_;
		std::ofstream fresult_;

    const static std::vector<std::string> c_blas_srcs_;
    const static std::vector<std::string> cpp_blas_srcs_;
    const static std::vector<std::string> f_blas_srcs_;

}; // class BlasTest


} // namespace hpcswtest

#endif  // HPCSWTEST_BLASTEST_H

