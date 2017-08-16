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
Mc21Test is a subclass of pure virtual abstract base class AppTest.

Date Created: Mon Dec 19 10:13:26 MST 2016

Author: Cormac Garvey

*/

#ifndef HPCSWTEST_MC21TEST_H_
#define HPCSWTEST_MC21TEST_H_

#include "apptest.h"
#include "helper.h"

#include <fstream>


namespace hpcswtest {


class Mc21Test: public AppTest {

  public:
    Mc21Test(const jobscript::JOBSCRIPT &);
    Mc21Test(const jobscript::JOBSCRIPT &, const std::string &);
    virtual ~Mc21Test(void) {};
    virtual void runTest(void) override;

  protected:
    std::string exeAppTest(std::ofstream &, std::ofstream &, const jobscript::JOBSCRIPT &, const std::string &) const override;

  private:
    std::string log_file_name_;
    std::string result_file_name_;
    std::ofstream flog_;
    std::ofstream fresult_;
//    int test_number_;

    const static std::vector<std::string> mc21_inputs_;
    const static std::vector<std::string> mc21_geometry_inputs_;
    const static std::vector<std::string> mc21_material_inputs_;

}; // class Mc21Test


} // namespace hpcswtest

#endif  // HPCSWTEST_MC21TEST_H
