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
HPC Software testing suite.
McnpTest subclass source code.

Date Created: Mon Nov 23 16:45:56 MST 2015

Author: Cormac Garvey

*/

#include "mcnptest.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> McnpTest::mcnp_inputs_ = {
R"( Godiva  Solid Bare HEU sphere  HEU-MET-FAST-001
1         1        4.7984e-02         -1        imp:n=1
2         0                            1        imp:n=0

1         so       8.7407

kcode     5000     1.0  50   250
sdef   cel=1     erg=d1    rad=d2    pos=0.0 0.0 0.0
sp1    -3
si2    0.0    8.7407
sp2    -21    2
totnu
c ---------------------------------------------------- ENDF/B-VII -------
m1        92234.70c   4.9184e-04     92235.70c   4.4994e-02
          92238.70c   2.4984e-03
c -----------------------------------------------------------------------
prdmp    j    999999
print

end of input
)"
}; // vector mcnp_inputs_


McnpTest::McnpTest(const jobscript::JOBSCRIPT &p_s, const std::string &s_a_n): AppTest("m", "", p_s, mcnp_inputs_.size(), s_a_n),
                                                                               log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                                               result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                                               flog_(log_file_name_,std::ios_base::app),
                                                                               fresult_(result_file_name_,std::ios_base::app) {}


McnpTest::McnpTest(const jobscript::JOBSCRIPT &p_s): AppTest("m", "", p_s, mcnp_inputs_.size()),
                                                     log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                     result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                     flog_(log_file_name_,std::ios_base::app),
                                                     fresult_(result_file_name_,std::ios_base::app) {}

/*
McnpTest::McnpTest(const std::string s_a_n): AppTest("m", "", s_a_n, calcSubAppArgs(), mcnp_inputs_.size()),
                                                     log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                     result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                     flog_(log_file_name_,std::ios_base::app),
                                                     fresult_(result_file_name_,std::ios_base::app) {}
*/

void McnpTest::runTest() {
  std::string cmd_result;
  std::string script_cmd_result;
//  std::cout << "Execute runTest member function from McnpTest object " << __FILE__ << "\t" <<__LINE__ << std::endl;
  if (!flog_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << log_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  if (!fresult_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << result_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  std::cout << "Testing: " << module_name_version(getJobScripts()[0].getModules()[getJobScripts()[0].getModules().size()-1]) << std::endl;
  int c_i = 0;
  for (auto mcnp_input: mcnp_inputs_) {
    createFileFromStr(getInputFileNames()[c_i], mcnp_input);
    script_cmd_result = exeAppTest(flog_, fresult_, c_i);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
  c_i = 0;
}


} // namespace hpcswtest

