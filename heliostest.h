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
HeliosTest is a subclass of pure virtual abstract base class AppTest.

Date Created: Wed Dec 23 13:17:55 MST 2015

Author: Cormac Garvey

*/

#ifndef HPCSWTEST_HELIOSTEST_H_
#define HPCSWTEST_HELIOSTEST_H_

#include "apptest.h"
#include "helper.h"

#include <fstream>


namespace hpcswtest {


class HeliosTest: public AppTest {

  public:
    HeliosTest(const jobscript::JOBSCRIPT &, const std::string &, const std::string &, const std::string &, const std::string &);
    virtual ~HeliosTest(void) {};
    virtual void runTest(void) override;
    std::string getHeliosExeName(void);
    std::string getAuroraExeName(void);
    std::string getZenithExeName(void);

  protected:
    void createHeliosJob(jobscript::JOBSCRIPT &) const;

  private:
    std::string log_file_name_;
    std::string result_file_name_;
    std::ofstream flog_;
    std::ofstream fresult_;
    std::string helios_exe_name_;
    std::string aurora_exe_name_;
    std::string zenith_exe_name_;

    const static std::vector<std::string> helios_aurora_03_inputs_;
    const static std::vector<std::string> helios_aurora_31_inputs_;
    const static std::vector<std::string> helios_zenith_31_inputs_;

}; // class HeliosTest


} // namespace hpcswtest

#endif  // HPCSWTEST_HELIOSTEST_H
