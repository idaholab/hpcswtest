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
HPC software test suite.
LibTest class source code.

Date Created: Fri Nov 20 14:36:59 MST 2015

Author: Cormac Garvey

*/

#include "libtest.h"

#include <iostream>  // debugging only

namespace hpcswtest {


LibTest::LibTest(const std::string &s, const jobscript::PbsScript &p_s, const std::string &c_n, const std::string &cpp_n, const std::string &f_n, int n_c_lib_srcs, int n_cpp_lib_srcs, int n_f_lib_srcs, const std::string &c_f, const std::string &cpp_f, const std::string &f_f, const std::string &c_l_l, const std::string &cpp_l_l, const std::string &f_l_l): SrcTest(s, p_s, c_n, cpp_n, f_n, n_c_lib_srcs, n_cpp_lib_srcs, n_f_lib_srcs, c_f, cpp_f, f_f, c_l_l, cpp_l_l, f_l_l) {}


void LibTest::setLinkLibs(const std::string &s) {
	link_libs_ = s;
}


std::string LibTest::getLinkLibs(void) {
	return link_libs_;
}


void LibTest::runTest(void) {
	std::cout << "Execute runTest member function from LibTest object" << std::endl;
}


} // namespace hpcswtest

