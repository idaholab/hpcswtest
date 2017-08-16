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
McnpxTest subclass source code.

Date Created: Wed Dec 16 13:14:28 MST 2015

Author: Cormac Garvey

*/

#include "mcnpxtest.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> McnpxTest::mcnpx_inputs_ = {
R"(testprob03 -- many features of the general source
3     1 -7  -10              $ source on surface of this cell
4     2 -.9  -90 #3 #8 #30   $ carbon between sources and tally
8     3 -3.7  -14 15 -16     $ tally here
30    4 -1.2  (-21 22 -23 24:-27) -25 26   $ volume source here
40    0  90                  $ zero-importance outside world
 
10    sx -50 12
14    p 0 31 0 16 31 21 18 31 27
15    py 0
16    cy 15
21    py 30 
22    py -16
23    px 30
24    px 25
25    pz 9
26    pz -9
27    c/z 25 30 4
90    sq 1 4 4 0 0 0 -6400 0 0 0
      
sc6   a surface source on sphere 10 and a cell source in cell 30.
sdef  sur d6  axs fsur d61  cel fsur d62  x fsur d63  y fsur d64
      z fsur d65  vec fsur d66  dir fsur d67  erg fsur d68
      ext fsur d69
c     biased sampling between the surface and cell sources
si6   l 10 0
sp6   .8 .2
sb6   .3 .7 
c     axs for position bias on the surface
ds61  t 10 4 2 0
c     the name of the cell
ds62  l 0 30
c     sample x for the cell cover
ds63  s 0 73
si73  20 30
sp73  0 1
c     sample y for the cell cover
ds64  s 0 74
si74  -17 36
sp74  0 1
c     sample z for the cell cover
ds65  s 0 75
si75  -10 10
sp75  0 1
c     reference vector for directional biasing in the cell
ds66  t 0 -3 1 0
c     exponential biasing in the cell
ds67  s 0 77
sb77  -31 1.5
c     the surface and cell sources have different energy spectra
ds68  s 78 88
si78  a 7 10 13
sp78  0 1 0
sp88  -3
c     position biasing on the surface
ds69  s 79 0
si79  -1 .5 .9 1
sp79  c 0 1.5 1.9 2
sb79  c 0 .5 1.2 2
c     materials
m1    92238 1 nlib=.50m
m2    6012 1  nlib=50m
m3    8016 1
m4    1001 2  8016 1  92235 3 nlib .50m
c     tally
nonu 0 0 0 1 0
f4:n  8
e4    1 2 4 6 8 12 14
c     miscellaneous
imp:n   1 3r 0
cut:n   j .0001 .18 .09
nps     5000
prdmp 2j -1 j -1
print 200
f14:n 8
f24:n 8
fq14 u e
fq24 u e
ft14 scx 79
ft24 scd
fu24 73 74 75 79 78 77
mgopt f 30
)"
}; // vector mcnpx_inputs_


McnpxTest::McnpxTest(const jobscript::JOBSCRIPT &p_s, const std::string &e_n): AppTest("x", "", p_s, mcnpx_inputs_.size(), e_n),
                                                                               log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                                               result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                                               flog_(log_file_name_,std::ios_base::app),
                                                                               fresult_(result_file_name_,std::ios_base::app) {}


void McnpxTest::runTest() {
  std::string cmd_result;
  std::string script_cmd_result;
//  std::cout << "Execute runTest member function from McnpxTest object " << __FILE__ << "\t" <<__LINE__ << std::endl;
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
  for (auto mcnpx_input: mcnpx_inputs_) {
    createFileFromStr(getInputFileNames()[c_i], mcnpx_input);
    script_cmd_result = exeAppTest(flog_, fresult_, getJobScripts()[c_i], getJobScripts()[c_i].getJobName());
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
  c_i = 0;
}


} // namespace hpcswtest

