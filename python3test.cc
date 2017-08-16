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
Python3Test subclass source code.

Date Created: Wed Dec 23 11:52:20 MST 2015

Author: Cormac Garvey

*/

#include "python3test.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> Python3Test::python3_inputs_ = {
R"(
print ("Hello Python")
)"
}; // vector python3_inputs_


Python3Test::Python3Test(const jobscript::JOBSCRIPT &p_s, const std::vector<std::string> &p_ms, const std::string &p_t): Python2Test(p_s, p_ms, p_t),
                                                                                                                         log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                                                                                         result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                                                                                         flog_(log_file_name_,std::ios_base::app),
                                                                                                                         fresult_(result_file_name_,std::ios_base::app) {}


void Python3Test::runTest() {
  std::string cmd_result;
  std::string script_cmd_result;
  std::string modules_load_result;
  std::time_t date_result = std::time(NULL);
//  std::cout << "Execute runTest member function from Python3Test object " << __FILE__ << "\t" <<__LINE__ << std::endl;
  if (!flog_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << log_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  if (!fresult_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << result_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  fresult_ << std::ctime(&date_result) << std::endl;
  fresult_ << getTestName() << " tests run on " << getHostName() << std::endl;
  std::cout << "Testing: " << module_name_version(getJobScripts()[0].getModules()[getJobScripts()[0].getModules().size()-1]) << std::endl;
  modules_load(flog_, getJobScripts()[0].getModules(), modules_load_result);
  int c_i = 0;
  for (auto python3_input: python3_inputs_) {
    createFileFromStr(getInputFileNames()[c_i], python3_input);
    runPythonTest(flog_, fresult_, getJobScripts()[c_i].getModules(), getInputFileNames()[c_i]); 
    ++c_i;
  }
  runPythonModulesTest(flog_, fresult_, getJobScripts()[0].getModules(), getPythonModules());
}


} // namespace hpcswtest

