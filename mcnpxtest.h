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
McnpxTest is subclass of pure virtual abstract base class AppTest.

Date Created: Wed Dec 16 13:12:07 MST 2015

Author: Cormac Garvey

*/

#ifndef HPCSWTEST_MCNPXTEST_H_
#define HPCSWTEST_MCNPXTEST_H_

#include "apptest.h"

#include <fstream>


namespace hpcswtest {


class McnpxTest: public AppTest {

  public:
    McnpxTest(const jobscript::JOBSCRIPT &, const std::string &);
    virtual ~McnpxTest(void) {};
    virtual void runTest(void) override;

  private:
    std::string log_file_name_;
    std::string result_file_name_;
    std::ofstream flog_;
    std::ofstream fresult_;

    const static std::vector<std::string> mcnpx_inputs_;

}; // class McnpxTest


} // namespace hpcswtest

#endif  // HPCSWTEST_MCNPXTEST_H

