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
VaspTest is a subclass of pure virtual abstract base class AppTest.

Date Created: Thu Dec 17 16:51:27 MST 2015

Author: Cormac Garvey

*/

#ifndef HPCSWTEST_VASPTEST_H_
#define HPCSWTEST_VASPTEST_H_

#include "apptest.h"
#include "helper.h"

#include <fstream>


namespace hpcswtest {


class VaspTest: public AppTest {

  public:
    VaspTest(const jobscript::JOBSCRIPT &);
    VaspTest(const jobscript::JOBSCRIPT &, const std::string &);
    virtual ~VaspTest(void) {};
    virtual void runTest(void) override;
//    void setTestNumber(int);
//    int getTestNumber(void);

  protected:
    std::string exeAppTest(std::ofstream &, std::ofstream &, const jobscript::JOBSCRIPT &, const std::string &) const override;

  private:
    std::string log_file_name_;
    std::string result_file_name_;
    std::ofstream flog_;
    std::ofstream fresult_;
//    int test_number_;

    const static std::vector<std::string> vasp_incar_inputs_;
    const static std::vector<std::string> vasp_kpoints_inputs_;
    const static std::vector<std::string> vasp_poscar_inputs_;
    const static std::vector<std::string> vasp_potcar_inputs_;

}; // class VaspTest


} // namespace hpcswtest

#endif  // HPCSWTEST_VASPTEST_H
