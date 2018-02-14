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
MatlabTest subclass source code.

Date Created: Tue Dec 22 13:54:31 MST 2015

Author: Cormac Garvey

*/

#include "matlabtest.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> MatlabTest::matlab_inputs_ = {
R"(
a=91;
b=400;
c=500;
d=a+b;
e=d+c;
e
)"
}; // vector matlab_inputs_


MatlabTest::MatlabTest(const jobscript::JOBSCRIPT &p_s): AppTest("matlab", ".m", p_s, matlab_inputs_.size()),
                                                         log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                         result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                         flog_(log_file_name_,std::ios_base::app),
                                                         fresult_(result_file_name_,std::ios_base::app) {}


void MatlabTest::runTest() {
  std::string cmd_result;
  std::string script_cmd_result;
//  std::cout << "Execute runTest member function from MatlabTest object " << __FILE__ << "\t" <<__LINE__ << std::endl;
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
  for (auto matlab_input: matlab_inputs_) {
    createFileFromStr(getInputFileNames()[c_i], matlab_input);
    fresult_ << module_name_version(getJobScripts()[c_i].getModules()[getJobScripts()[c_i].getModules().size()-1]) << "\t" << getJobScripts()[c_i].getJobName() << std::endl;
    script_cmd_result = subJobScript(flog_, getJobScripts()[c_i]);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
}


} // namespace hpcswtest

