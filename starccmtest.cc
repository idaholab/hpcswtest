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
StarccmTest subclass source code.

Date Created: Mon Dec 21 12:25:41 MST 2015

Author: Cormac Garvey

*/

#include "starccmtest.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> StarccmTest::starccm_inputs_ = {
R"(
// STAR-CCM+ macro: run_heated_fin_step.java
package macro;

import java.util.*;

import star.common.*;
import star.base.neo.*;

public class XXXX_X_X extends StarMacro {

  public void execute() {
    execute0();
  }

  private void execute0() {

    Simulation simulation_0 =
      getActiveSimulation();

    ResidualPlot residualPlot_0 =
      ((ResidualPlot) simulation_0.getPlotManager().getObject("Residuals"));

    residualPlot_0.setTitleFont(new java.awt.Font("Sans Serif", 0, 12));

    simulation_0.getSimulationIterator().step(1);

    simulation_0.getSimulationIterator().step(1);

    simulation_0.saveState(resolvePath("./XXXX_X_X.sim"));
  }
}
)"
}; // vector starccm_inputs_


StarccmTest::StarccmTest(const jobscript::PbsScript &p_s, const std::string &e_n): AppTest("starccm", ".java", p_s, starccm_inputs_.size(), e_n),
                                                                                   log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                                                   result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                                                   flog_(log_file_name_,std::ios_base::app),
                                                                                   fresult_(result_file_name_,std::ios_base::app) {}


void StarccmTest::runTest() {
  std::string cmd_result;
  std::string script_cmd_result;
  std::vector<std::string> out_strs = {"XXXX_X_X"};
//  std::cout << "Execute runTest member function from StarccmTest object " << __FILE__ << "\t" <<__LINE__ << std::endl;
  if (!flog_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << log_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  if (!fresult_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << result_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  std::cout << "Testing: " << module_name_version(getPbsScripts()[0].getModules()[getPbsScripts()[0].getModules().size()-1]) << std::endl;
  copyFile("/hpc-common/software/sw_qa/scripts/Heated_Fin.sim","Heated_Fin.sim");
  int c_i = 0;
  for (auto starccm_input: starccm_inputs_) {
    std::vector<std::string> in_strs = {getPbsScripts()[c_i].getJobName()};
    createFileFromStr(getInputFileNames()[c_i], starccm_input);
    modifyFile(getInputFileNames()[c_i], out_strs, in_strs);
    script_cmd_result = exeAppTest(flog_, fresult_, getPbsScripts()[c_i], getPbsScripts()[c_i].getJobName());
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
}


} // namespace hpcswtest

