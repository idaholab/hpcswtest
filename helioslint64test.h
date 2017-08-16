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
HelioslinT64Test is a subclass of HeliosTest.

Date Created: Mon Jan 11 16:25:30 MST 2016

Author: Cormac Garvey

*/

#ifndef HPCSWTEST_HELIOSLINT64TEST_H_
#define HPCSWTEST_HELIOSLINT64TEST_H_

#include "heliostest.h"
#include "helper.h"

#include <fstream>


namespace hpcswtest {


class HeliosLinT64Test: public HeliosTest {

  public:
    HeliosLinT64Test(const jobscript::JOBSCRIPT &, const std::string &, const std::string &, const std::string &, const std::string &);
    virtual ~HeliosLinT64Test(void) {};
    virtual void runTest(void) override;

  private:
    std::string log_file_name_;
    std::string result_file_name_;
    std::ofstream flog_;
    std::ofstream fresult_;

    const static std::vector<std::string> helios_aurora_03_inputs_;
    const static std::vector<std::string> helios_aurora_31_inputs_;
    const static std::vector<std::string> helios_zenith_31_inputs_;

}; // class HeliosLinT64Test


} // namespace hpcswtest

#endif  // HPCSWTEST_HELIOSLINT64TEST_H
