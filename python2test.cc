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
Python2Test subclass source code.

Date Created: Tue Dec 22 15:46:19 MST 2015

Author: Cormac Garvey

*/

#include "python2test.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> Python2Test::python2_inputs_ = {
R"(
print "Hello Python"
)"
}; // vector python2_inputs_


std::vector<std::string> Python2Test::getPythonModules(void) {
  return python_modules_;
}


Python2Test::Python2Test(const jobscript::JOBSCRIPT &p_s, const std::vector<std::string> &p_ms, const std::string &p_t): AppTest(p_t, ".py", p_s, python2_inputs_.size()),
                                                                                                                         log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                                                                                         result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                                                                                         flog_(log_file_name_,std::ios_base::app),
                                                                                                                         fresult_(result_file_name_,std::ios_base::app),
                                                                                                                         python_modules_(p_ms) {}


void Python2Test::runPythonModulesTest(std::ofstream &flog, std::ofstream &fresult, const modules::modules_type &modules, const std::vector<std::string> &python_modules) const {
  std::string result;
  std::string python_cmd;
  std::string modules_str = modules_string(modules);
  for (auto python_module: python_modules) {
#ifdef SLURM
    python_cmd = " { module purge;" + modules_str + ";" + "python -c \"import " + python_module + "\"; }" + " 2>&1";
#else
    python_cmd = " { module purge;module load pbs;" + modules_str + ";" + "python -c \"import " + python_module + "\"; }" + " 2>&1";
#endif
    flog << "Execute : " << python_cmd << std::endl;
//    std::cout << "python_cmd = " << python_cmd << std::endl;
    result = exec(python_cmd.c_str());
    if (strSizeZero(result)) {
      fresult << module_name_version(modules[modules.size()-1]) << " " << python_module << " passed" << std::endl;
      flog << module_name_version(modules[modules.size()-1]) << " " << python_module << " passed" << std::endl;
      std::cout << module_name_version(modules[modules.size()-1]) << " " << python_module << " passed" << std::endl;
    } else {
      fresult << module_name_version(modules[modules.size()-1]) << " " << python_module << " failed" << std::endl;
      flog << module_name_version(modules[modules.size()-1]) << " " << python_module << " failed" << std::endl;
      std::cout << module_name_version(modules[modules.size()-1]) << " " << python_module << " failed" << std::endl;
      flog << result << std::endl;
    }
//    std::cout << "result = " << result << std::endl;
  }
}


void Python2Test::runPythonTest(std::ofstream &flog, std::ofstream &fresult, const modules::modules_type &modules, const std::string &input_file) const {
  std::string result;
  std::string python_cmd;
  std::string modules_str = modules_string(modules);
#ifdef SLURM
  python_cmd = " { module purge;" + modules_str + ";" + "python " + input_file + "; }" + " 2>&1";
#else
  python_cmd = " { module purge;module load pbs;" + modules_str + ";" + "python " + input_file + "; }" + " 2>&1";
#endif
  flog << "Execute : " << python_cmd << std::endl;
//  std::cout << "python_cmd = " << python_cmd << std::endl;
  result = exec(python_cmd.c_str());
  if (result == "Hello Python") {
    fresult << module_name_version(modules[modules.size()-1]) << " base passed" << std::endl;
    flog << module_name_version(modules[modules.size()-1]) << " base passed" << std::endl;
    std::cout << module_name_version(modules[modules.size()-1]) << " base passed" << std::endl;
  } else {
    fresult << module_name_version(modules[modules.size()-1]) << " base failed" << std::endl;
    flog << module_name_version(modules[modules.size()-1]) << " base failed" << std::endl;
    std::cout << module_name_version(modules[modules.size()-1]) << " base failed" << std::endl;
    flog << result << std::endl;
  }
}


void Python2Test::runTest() {
  std::string cmd_result;
  std::string script_cmd_result;
  std::string modules_load_result;
  std::time_t date_result = std::time(NULL);
//  std::cout << "Execute runTest member function from Python2Test object " << __FILE__ << "\t" <<__LINE__ << std::endl;
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
  for (auto python2_input: python2_inputs_) {
    createFileFromStr(getInputFileNames()[c_i], python2_input);
    runPythonTest(flog_, fresult_, getJobScripts()[c_i].getModules(), getInputFileNames()[c_i]); 
    ++c_i;
  }
  runPythonModulesTest(flog_, fresult_, getJobScripts()[0].getModules(), getPythonModules());
}


} // namespace hpcswtest

