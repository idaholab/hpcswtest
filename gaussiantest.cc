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
GaussianTest subclass source code.

Date Created: Fri Jan 15 12:16:18 MST 2016

Author: Cormac Garvey

*/

#include "gaussiantest.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> GaussianTest::gaussian_inputs_ = {
R"(#p rhf/6-31g* opt=tight test
 
Gaussian Test Job 83: 
Water dimer optimization
 
0,1
O
O,1,ROO
X,1,1.,2,X3O
H,1,RO1H,3,HOX3,2,90.,0
H,1,RO1H,3,HOX3,2,-90.,0
X,2,1.,1,52.5,3,180.,0
H,2,RO2H1,6,H7OX,1,180.,0
H,2,RO2H2,6,H8OX,1,0.,0
 
ROO=2.98308
RO1H=0.94839
X3O=120.2827
HOX3=52.90868
RO2H1=0.94686
RO2H2=0.95173
H7OX=52.98178
H8OX=51.9632
)"
}; // vector gaussian_inputs_


GaussianTest::GaussianTest(const jobscript::PbsScript &p_s, const std::string &e_n): AppTest("gaussian", "", p_s ,gaussian_inputs_.size(), e_n),
                                                     log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                     result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                     flog_(log_file_name_,std::ios_base::app),
                                                     fresult_(result_file_name_,std::ios_base::app) {}


void GaussianTest::runTest() {
  std::string cmd_result;
  std::string script_cmd_result;
//  std::cout << "Execute runTest member function from GaussianTest object " << __FILE__ << "\t" <<__LINE__ << "\t" << getTestObjectCount() << "\t" << getTestNumber() << std::endl;
  if (!flog_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << log_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  if (!fresult_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << result_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  std::cout << "Testing: " << module_name_version(getPbsScripts()[0].getModules()[getPbsScripts()[0].getModules().size()-1]) << std::endl;
  int c_i = 0;
  for (auto gaussian_input: gaussian_inputs_) {
    createFileFromStr(getInputFileNames()[c_i], gaussian_input);
//    script_cmd_result = subPbsScript(flog_, getPbsScripts()[c_i]);
    script_cmd_result = exeAppTest(flog_, fresult_, getPbsScripts()[c_i], getInputFileNames()[c_i] + ".out");
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
}


} // namespace hpcswtest

