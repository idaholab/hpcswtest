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
MatlabTest is a subclass of pure virtual abstract base class AppTest.

Date Created: Tue Dec 22 13:52:56 MST 2015

Author: Cormac Garvey

*/

#ifndef HPCSWTEST_MATLABTEST_H_
#define HPCSWTEST_MATLABTEST_H_

#include "apptest.h"
#include "helper.h"

#include <fstream>


namespace hpcswtest {


class MatlabTest: public AppTest {

  public:
    MatlabTest(const jobscript::JOBSCRIPT &, const std::string &);
    MatlabTest(const jobscript::JOBSCRIPT &);
    virtual ~MatlabTest(void) {};
    virtual void runTest(void) override;

  private:
    std::string log_file_name_;
    std::string result_file_name_;
    std::ofstream flog_;
    std::ofstream fresult_;

    const static std::vector<std::string> matlab_inputs_;

}; // class MatlabTest


} // namespace hpcswtest

#endif  // HPCSWTEST_MATLABTEST_H
