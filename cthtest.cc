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
CthTest subclass source code.

Date Created: Mon Nov 28 09:37:04 MST 2016

Author: Cormac Garvey

*/

#include "cthtest.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> CthTest::cth_inputs_ = {
R"ttt(**************************************************************************
*
*eor* cthin
*
*  cth input for penetrator calculation
*
*  title record
*
Long-Rod Penetration Calculation
*
**************************************************************************
*
*  control records
*
control
  tstop 100e-6
endc
*
**************************************************************************
*
*  mesh records
*
mesh
*
  geom=2dc
*
    x0 0.
      x1    w=2.0     n=20     r=1.
      x2  dxf=0.1   dxl=.4     w=10.
    endx
    y0 -8.
      y1  dyf=0.4   dyl=0.1  w=8.
      y2  dyf=0.1   dyl=0.1  w=5.
      y3  dyf=-1.   dyl=0.4  w=6.
    endy
*
    xact  0. 0.5
    yact -9. 0.0
*
endm
*
**************************************************************************
*
*  material insertion records
*
diatom
*
    package 'U-Ti penetrator'
      material 1
      yvelocity 1.2e5
      insert circle
        center 0. -0.4
        radius 0.4
      endi
      insert box
        p1 0.      -0.4
        p2 0.4     -7.5
      endi
    endp
*
    package 'armor plate'
      material 2
      insert box
        p1 0.   0.
        p2 1.e3 5.
      endi
    endp
*
*
enddiatom
*
**************************************************************************
*
*  tracer records
*
tracer
   add 0.025 -7.25 to 0.025 4.75 n=13
endt
*
**************************************************************************
*
*  eos records 
*
eos
*
  mat1 mgrun uranium
*
* No MGRUN for Iron; only PTRAN containing Alpha & Epsilon Phases
*
  mat2 ptran iron
*
ende
*
***************************************************************************
*
*  material strength records
*
epdata
  mix=3
  matep 1  eppvm user yield=17.9e9  poisson=.245
  matep 2  eppvm user yield=10.0e9  poisson=.279
ende
*
**************************************************************************
*
*  convection records
*
convct
  interface=smyra
endc
*
*************************************************************************
*
*  time step control
*
mindt
 time=1e-6 dtmin=3e-8
endm
*
**************************************************************************
*
*  fracture records
*
fracts
  stress
  pfrac1 -24.0e9
  pfrac2 -25.0e9
endf
*
**************************************************************************
*
*  edit records
*
edit
*
  shortt
    time=0.0  dt=5.0e-6
  ends
*
  longt
    time=0.0  dt=25.e-6
  endl
*
  restt
    time=0.0  dt=50.0e-6
  endr
*
ende
*
**************************************************************************
*
*  boundary condition records
*
boundary
  bhydro
      bxbot=0
      bxtop=2
      bybot=0
      bytop=0
  endh
endb
*
***************************************************************************
*
* Spymaster script (see Spymaster User's Guide):
*
spy

 PlotTime(0, 10e-6);

 SaveTime(0, 10e-6);
 Save("VOLM,M,P,VX,VY");

 ImageFormat(800,600);

 define main()
 {
   pprintf(" PLOT: Cycle=%d, Time=%e\n",CYCLE,TIME);
   XBMirror(ON);
   XLimits(-12,12);
   YLimits(-12,12);

   Image("mats",WHITE,BLACK);
    Window(0,0,0.75,1);
    MatColors(MAGENTA,STEEL_BLUE);
    MatNames("URANIUM","STEEL");
    Label(sprintf("Materials at %6.2e seconds",TIME));
    Plot2DMats;
    DrawMatLegend("",0.75,0.4,1.0,0.9);
   EndImage;

 }

 define spyplt_main()
 {
   pprintf(" PLOT: Cycle=%d, Time=%e\n",CYCLE,TIME);
   XBMirror(ON);
   XLimits(-12,12);
   YLimits(-12,12);

   Image("vmag");
    Window(0,0,0.75,1);
    MatColors(DARK_GRAY,GRAY);
    Plot2DMats;
    ColorMapRange(100,1.4e5);
    ColorMapClipping(ON,OFF);
    Label(sprintf("Velocity Magnitude at %6.2e seconds",TIME));
    Plot2D("VMAG");
    Draw2DMatContour;
    DrawColorMap("(cm/s)",0.75,0.4,0.9,0.9);
   EndImage;

   Image("vy_1d");
    Fix1D(0,-8,0,11);
    Label(sprintf("Y-Velocity at %6.2e seconds",TIME));
    Plot1D("VY",ON,AUTOSCALE);
   EndImage;
 }

 HisTime(0,1e-7);
 SaveTracer(ALL);
 SaveHis("GLOBAL,POSITION,P,DENS,VY");

 define spyhis_main()
 {
  HisLoad(1,"hscth");
  HisImageName("pene_history");
  Label("U Penetrator into Steel at 1.2 km/s (Tracer 3)");
  TPlot("DENS.3",1,AUTOSCALE);
 }

endspy)ttt"
}; // vector cth_inputs_


/*std::string CthTest::exeAppTest(std::ofstream &flog, std::ofstream &fresult, jobscript::JOBSCRIPT &job_script, const std::string &dir_path) const {
  std::string script_cmd_result;
  std::string module_load_result;
  std::string script_cmd;
  std::string modules_str;

  fresult << module_name_version(job_script.getModules()[job_script.getModules().size()-1]) << "\t" << dir_path << "\t" << job_script.getJobName() << std::endl;
//  std::cout << job_script.getExeName() << " " << job_script.getExeArgs() << std::endl;
  if (modules_load(flog, job_script.getModules(), module_load_result)) {
    modules_str = modules_string(job_script.getModules());
#ifdef SLURM
    script_cmd = "module purge;" + modules_str + ";" + job_script.getExeName() + " " + job_script.getExeArgs() + " 2>&1";
#else
    script_cmd = "module purge;module load pbs;" + modules_str + ";" + job_script.getExeName() + " " + job_script.getExeArgs() + " 2>&1";
#endif
    flog << "Submit Command: " << script_cmd << std::endl;
    script_cmd_result = exec(script_cmd.c_str());
  } else {
    script_cmd_result = "fatal";
  }
  return script_cmd_result;
}
*/

CthTest::CthTest(const jobscript::JOBSCRIPT &p_s, const std::string &s_a_n): AppTest("cth", "", p_s, cth_inputs_.size(), s_a_n),
                                                                             log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                                             result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                                             flog_(log_file_name_,std::ios_base::app),
                                                                             fresult_(result_file_name_,std::ios_base::app) {}


CthTest::CthTest(const jobscript::JOBSCRIPT &p_s): AppTest("cth", "", p_s, cth_inputs_.size()),
                                                   log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                   result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                   flog_(log_file_name_,std::ios_base::app),
                                                   fresult_(result_file_name_,std::ios_base::app) {}


void CthTest::runTest() {
  std::string cmd_result;
  std::string script_cmd_result;
  std::string cth_dir;
//  std::cout << "Execute runTest member function from CthTest object " << __FILE__ << "\t" <<__LINE__ << std::endl;
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
  for (auto cth_input: cth_inputs_) {
    cth_dir = "cth_" + std::to_string(getTestNumber()) + "_" + std::to_string(c_i);
    flog_ << "Run test in directory " << cth_dir << std::endl;
    makeDir(cth_dir);
    changeDir(cth_dir);
    createFileFromStr(getInputFileNames()[c_i], cth_input);
    script_cmd_result = exeAppTest(flog_, fresult_, c_i, cth_dir);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    changeDir("..");
    ++c_i;
  }
}


} // namespace hpcswtest
