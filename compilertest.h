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
subclss of SrcTest.
Part of HPC Software Test Suite.

Date Created: Wed Nov 11 13:23:21 MST 2015

Author: Cormac Garvey

*/

#ifndef HPCSWTEST_COMPILERTEST_H_
#define HPCSWTEST_COMPILERTEST_H_

#include "srctest.h"
#include "helper.h"

#include <fstream>
#include <regex>


namespace hpcswtest {


class CompilerTest : public SrcTest {

  public:
    CompilerTest(const jobscript::PbsScript &, const std::string &, const std::string &, const std::string &, const std::string &c_f="-O2", const std::string &cpp_f="-O2", const std::string &f_f="-O2", const std::string &c_l_l="-lm", const std::string &cpp_l_l="-lm", const std::string &f_l_l="-lm");
    virtual ~CompilerTest(void) {};
    virtual void runTest(void) override; 
    int NumCSrc(void) const;
    int NumCppSrc(void) const;
    int NumFSrc(void) const;
    std::string getCSrc(int) const;
    std::string getCppSrc(int) const;
    std::string getFSrc(int) const;

  private:
    std::string log_file_name_; 
    std::string result_file_name_; 
    std::ofstream flog_;
    std::ofstream fresult_;

    const static std::vector<std::string> c_srcs_;
    const static std::vector<std::string> cpp_srcs_;
    const static std::vector<std::string> f_srcs_;

}; // class CompilerTest


} // namespace hpcswtest

#endif  // HPCSWTEST_COMPILERTEST_H

