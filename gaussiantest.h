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
GaussianTest is a subclass of pure virtual abstract base class AppTest.

Date Created: Fri Jan 15 12:11:43 MST 2016

Author: Cormac Garvey

*/

#ifndef HPCSWTEST_GAUSSIANTEST_H_
#define HPCSWTEST_GAUSSIANTEST_H_

#include "apptest.h"
#include "helper.h"

#include <fstream>


namespace hpcswtest {


class GaussianTest: public AppTest {

  public:
    GaussianTest(const jobscript::JOBSCRIPT &);
    GaussianTest(const jobscript::JOBSCRIPT &, const std::string &);
    virtual ~GaussianTest(void) {};
    virtual void runTest(void) override;

  private:
    std::string log_file_name_;
    std::string result_file_name_;
    std::ofstream flog_;
    std::ofstream fresult_;

    const static std::vector<std::string> gaussian_inputs_;

}; // class GaussianTest


} // namespace hpcswtest

#endif  // HPCSWTEST_GAUSSIANTEST_H
