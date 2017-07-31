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
ScaleTest62 is a subclass of pure virtual abstract base class AppTest.

Date Created: Wed Nov 23 12:20:56 MST 2016

Author: Cormac Garvey

*/

#ifndef HPCSWTEST_SCALE62TEST_H_
#define HPCSWTEST_SCALE62TEST_H_

#include "scaletest.h"
#include "helper.h"

#include <fstream>


namespace hpcswtest {


class Scale62Test: public ScaleTest {

  public:
    Scale62Test(const jobscript::PbsScript &, const std::string &);
    virtual ~Scale62Test(void) {};
    virtual void runTest(void) override;

  private:
    std::string log_file_name_;
    std::string result_file_name_;
    std::ofstream flog_;
    std::ofstream fresult_;

    const static std::vector<std::string> scale_inputs_;

}; // class Scale62Test


} // namespace hpcswtest

#endif  // HPCSWTEST_SCALE62TEST_H
