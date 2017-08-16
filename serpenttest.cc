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
SerpentTest subclass source code.

Date Created: Mon Nov 28 08:40:11 MST 2016

Author: Cormac Garvey

*/

#include "serpenttest.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> SerpentTest::serpent_inputs_ = {
R"(% title Initial M-H Core
% Michael Pope
% 
% *****************************************
% ************   Cell Cards  **************
% *****************************************
% *** Fuel Plates *** Universe 1 ****
cell   1  1  zirc4   -1        -60  61   % 
cell   2  1  h2o      1   -2   -60  61   % Water internal to plate 1
cell   3  1  zirc4    2   -3   -60  61   % Fuel Clad inner Plate  1
cell   4  1  fuel1    3   -4   -60  61   % Fuel Meat Plate  1
cell   5  1  zirc4    4   -5   -60  61   % Fuel Clad outer Plate  1
cell   6  1  h2o      5   -6   -60  61   % Water between Plates 1 and 2
cell   7  1  zirc4    6   -7   -60  61   % Fuel Clad inner Plate  2
cell   8  1  fuel2    7   -8   -60  61   % Fuel Meat Plate  2
cell   9  1  zirc4    8   -9   -60  61   % Fuel Clad outer Plate  2
cell  10  1  h2o      9  -10   -60  61   % Water between Plates 2 and 3
cell  11  1  zirc4   10  -11   -60  61   % Fuel Clad inner Plate  3
cell  12  1  fuel3   11  -12   -60  61   % Fuel Meat Plate  3
cell  13  1  zirc4   12  -13   -60  61   % Fuel Clad outer Plate  3
cell  14  1  h2o     13  -14   -60  61   % Water between Plates 3 and 4
cell  15  1  zirc4   14  -15   -60  61   % Fuel Clad inner Plate  4
cell  16  1  fuel4   15  -16   -60  61   % Fuel Meat Plate  4
cell  17  1  zirc4   16  -17   -60  61   % Fuel Clad outer Plate  4
cell  18  1  h2o     17  -18   -60  61   % Water between Plates 4 and 5
cell  19  1  zirc4   18  -19   -60  61   % Fuel Clad inner Plate  5
cell  20  1  fuel5   19  -20   -60  61   % Fuel Meat Plate  5
cell  21  1  zirc4   20  -21   -60  61   % Fuel Clad outer Plate  5
cell  22  1  h2o     21  -22   -60  61   % Water between Plates 5 and 6
cell  23  1  zirc4   22  -23   -60  61   % Fuel Clad inner Plate  6
cell  24  1  fuel6   23  -24   -60  61   % Fuel Meat Plate  6
cell  25  1  zirc4   24  -25   -60  61   % Fuel Clad outer Plate  6
cell  26  1  h2o     25  -26   -60  61   % Water between Plates 6 and 7
cell  27  1  zirc4   26  -27   -60  61   % Fuel Clad inner Plate  7
cell  28  1  fuel7   27  -28   -60  61   % Fuel Meat Plate  7
cell  29  1  zirc4   28  -29   -60  61   % Fuel Clad outer Plate  7
cell  30  1  h2o     29  -30   -60  61   % Water between Plates 7 and 8
cell  31  1  zirc4   30  -31   -60  61   % Fuel Clad inner Plate  8
cell  32  1  fuel8   31  -32   -60  61   % Fuel Meat Plate  8
cell  33  1  zirc4   32  -33   -60  61   % Fuel Clad outer Plate  8
cell  34  1  h2o     33  -34   -60  61   % Water between Plates 8 and 9
cell  35  1  zirc4   34  -35   -60  61   % Fuel Clad inner Plate  9
cell  36  1  fuel9   35  -36   -60  61   % Fuel Meat Plate  9
cell  37  1  zirc4   36  -37   -60  61   % Fuel Clad outer Plate  9
cell  38  1  h2o     37  -38   -60  61   % Water between Plates 9 and 10
cell  39  1  zirc4   38  -39   -60  61   % Fuel Clad inner Plate  10
cell  40  1  fuel10  39  -40   -60  61   % Fuel Meat Plate  10
cell  41  1  zirc4   40  -41   -60  61   % Fuel Clad outer Plate  10
cell  42  1  h2o     41  -42   -60  61   % Water between Plate 10 rack
cell  43  1  AlRack  42        -60  61   % al6061 rack
 

%  Upper and lower end plates 
cell  55  1  zirc4   -42       60 -62    % upper end plate
cell  56  1  zirc4   -42      -61  63    % lower end plate

%  h2o above and below fuel assembly
cell  57  1  h2o      -42      62    % water above fuel assembly above fuel
cell  58  1  h2o      -42     -63    % water below fuel assembly above fuel
cell  59  1  h2o       42      60    % water above fuel assembly outside fuel
cell  60  1  h2o       42     -61    % water below fuel assembly outside fuel

% *** Small Test Location *** Universe 2 ****
cell 120 2  al6061   -110 61 -60    % test space
cell 121 2  al6061   -110 60        % above test space
cell 122 2  al6061   -110 -61       % below test space
cell 123 2  ss304    110  -111      % flow tube
cell 124 2  h2o      111  -112      % return flow
cell 125 2  ss304    112  -113      % pressure tube
cell 126 2  helium   113  -114      % helium annulus
cell 127 2  ss304    114  -115      % insulation jacket
cell 128 2  h2o      115  -116      % water gap
cell 129 2  AlRack   116  -117  -60  61  % baffle
cell 230 2  AlRack   117    -60  61  %  al6061 rack adjacent to test location 
cell 228 2  h2o      116     60      %  water above core next to test loc.
cell 328 2  h2o      116    -61      %  water below core next to test loc.



cell 200 4 AlRack  -201   -60  61 %  large area of al6061.  used for filling lat.
cell 201 4 h2o  -201    60     %  large area of coolant above core
cell 202 4 h2o  -201   -61     %  large area of coolant above core

% ---------------------------------
%  ----------- core map -----------
% ---------------------------------
lat 150  2 0.0 0.0 9 9 13.80
    4 4 4 4 4 4 4 4 4 
    4 4 4 4 1 1 1 1 4 
    4 4 4 1 1 2 1 1 4 
    4 4 1 2 1 1 2 1 4 
    4 1 1 1 2 1 1 1 4 
    4 1 2 1 1 2 1 4 4 
    4 1 1 2 1 1 4 4 4 
    4 1 1 1 1 4 4 4 4 
    4 4 4 4 4 4 4 4 4 
cell 151 0 fill 150 -170  202 -203  % inside pressure vessel
cell 152 0 al6061       170 -171  202 -203  % inside pressure vessel
cell 153 0 d2o  171 -201  202 -203  % d2o tank
%
% ------ Void Outside Core ------
cell 1001 0 outside 201 203 % rest of universe
cell 1002 0 outside 201 -202 % rest of universe
cell 1003 0 outside -201 203 % rest of universe
cell 1004 0 outside -201 -202 % rest of universe
cell 1005 0 outside 201 -203 202 % rest of universe

% *****************************************
% ******** End Of Cell Cards **************
% *****************************************



% *****************************************
% ************ Surface Cards **************
% *****************************************

% *** Fuel Plate Surfaces ****  kept same numbering as before even though
% I don't use first three plates.  This was done in order to make larger
% hole in middle of fuel assembly for irradiation space or control rod.

surf  1 cyl  0.0  0.0   1.97500           % Outside of filler
surf  2 cyl  0.0  0.0   2.17500            % Fuel Cld inner Plate  1
surf  3 cyl  0.0  0.0   2.21250             % Fuel Mt inner Plate  1
surf  4 cyl  0.0  0.0   2.26250            % Fuel Mt outer  Plate  1
surf  5 cyl  0.0  0.0   2.30000           % Fuel Cld outer  Plate  1
surf  6 cyl  0.0  0.0   2.50000            % Fuel Cld inner Plate  2
surf  7 cyl  0.0  0.0   2.53750             % Fuel Mt inner Plate  2
surf  8 cyl  0.0  0.0   2.58750            % Fuel Mt outer  Plate  2
surf  9 cyl  0.0  0.0   2.62500           % Fuel Cld outer  Plate  2
surf 10 cyl  0.0  0.0   2.82500            % Fuel Cld inner Plate  3
surf 11 cyl  0.0  0.0   2.86250             % Fuel Mt inner Plate  3
surf 12 cyl  0.0  0.0   2.91250            % Fuel Mt outer  Plate  3
surf 13 cyl  0.0  0.0   2.95000           % Fuel Cld outer  Plate  3
surf 14 cyl  0.0  0.0   3.15000            % Fuel Cld inner Plate  4
surf 15 cyl  0.0  0.0   3.18750             % Fuel Mt inner Plate  4
surf 16 cyl  0.0  0.0   3.23750            % Fuel Mt outer  Plate  4
surf 17 cyl  0.0  0.0   3.27500           % Fuel Cld outer  Plate  4
surf 18 cyl  0.0  0.0   3.47500            % Fuel Cld inner Plate  5
surf 19 cyl  0.0  0.0   3.51250             % Fuel Mt inner Plate  5
surf 20 cyl  0.0  0.0   3.56250            % Fuel Mt outer  Plate  5
surf 21 cyl  0.0  0.0   3.60000           % Fuel Cld outer  Plate  5
surf 22 cyl  0.0  0.0   3.80000            % Fuel Cld inner Plate  6
surf 23 cyl  0.0  0.0   3.83750             % Fuel Mt inner Plate  6
surf 24 cyl  0.0  0.0   3.88750             % Fuel Mt outer  Plate 6
surf 25 cyl  0.0  0.0   3.92500           % Fuel Cld outer  Plate  6
surf 26 cyl  0.0  0.0   4.12500            % Fuel Cld inner Plate  7
surf 27 cyl  0.0  0.0   4.16250             % Fuel Mt inner Plate  7
surf 28 cyl  0.0  0.0   4.21250            % Fuel Mt outer  Plate  7
surf 29 cyl  0.0  0.0   4.25000           % Fuel Cld outer  Plate  7
surf 30 cyl  0.0  0.0   4.45000            % Fuel Cld inner Plate  8
surf 31 cyl  0.0  0.0   4.48750             % Fuel Mt inner Plate  8
surf 32 cyl  0.0  0.0   4.53750            % Fuel Mt outer  Plate  8
surf 33 cyl  0.0  0.0   4.57500           % Fuel Cld outer  Plate  8
surf 34 cyl  0.0  0.0   4.77500            % Fuel Cld inner Plate  9
surf 35 cyl  0.0  0.0   4.81250             % Fuel Mt inner Plate  9
surf 36 cyl  0.0  0.0   4.86250            % Fuel Mt outer  Plate  9
surf 37 cyl  0.0  0.0   4.90000           % Fuel Cld outer  Plate  9
surf 38 cyl  0.0  0.0   5.10000            % Fuel Cld inner Plate 10
surf 39 cyl  0.0  0.0   5.13750             % Fuel Mt inner Plate 10
surf 40 cyl  0.0  0.0   5.18750            % Fuel Mt outer  Plate 10
surf 41 cyl  0.0  0.0   5.22500           % Fuel Cld outer  Plate 10
surf 42 cyl  0.0  0.0  5.4250  % outer boundary of outermost channel
%
% *** Top and Bottom End Plates ***
surf 60  pz  50      % Top plate
surf 61  pz -50      % Bottom plate
surf 62  pz  50.2    % Top plate
surf 63  pz -50.2    % Bottom plate
 
% *** hexagonal surface defining lattice ***
surf 65 hexxc 0.0 0.0 12.355

%  *** Small Test Space Surfaces ***
surf 110 cyl  0.0  0.0  4.645  % Outer boundary of test space
surf 111 cyl  0.0  0.0  4.810  % Outer surface of flow tube
surf 112 cyl  0.0  0.0  5.130  % Inner surface of pressure tube
surf 113 cyl  0.0  0.0  5.800  % Outer surface of pressure tube
surf 114 cyl  0.0  0.0  5.950  % Inner surface of insulation jacket
surf 115 cyl  0.0  0.0  6.250  % Outer surface of insulation jacket
surf 116 cyl  0.0  0.0  6.900  % Inner surface of Al baffle
surf 117 cyl  0.0  0.0  7.500  % Outer surface of Al baffle

 
% *** Al rack boundary reflector boundary ***
surf 170  cyl 0.0 0.0 49.    %
surf 171  cyl 0.0 0.0 53.    %

% *** D2O tank outer boundary ***
surf 201  cyl 0.0 0.0 150.0   %

surf 202 pz -150. 
surf 203 pz  150.


% *****************************************
% ********  End Of Surface Cards **********
% *****************************************

% vacuum boundary
set bc 1
% unresolved resonance 
% set ures 1 1
% use track-length flux estimate
% instead of collision estimator
% set tle 1

% source points
% src 1 sp 1.24 0.0 0.0 

% source entropy mesh
set entr [4 4 4 -150. 150. -150. 150. -50. 50. ]

% cross section library path
set acelib "/hpc-common/software/hpcswtest/data/xsdata_combined"
set declib "/hpc-common/software/hpcswtest/data/sss_endfb7.dec"
set nfylib "/hpc-common/software/hpcswtest/data/sss_endfb7.nfy"


set power 250.E06

set pop 2000 400 5 1.2
% set nbuf 10000000
% ------- Material Cards --------------------------------------------
mat fuel1 4.9186E-02 tmp 433. vol  2109    
     92235.03c  7.6963E-03
     92238.03c  3.0882E-02
     42000.03c  1.0608E-02   
mat fuel2 4.9186E-02 tmp 433. vol  2415.    
     92235.03c  7.6963E-03
     92238.03c  3.0882E-02
     42000.03c  1.0608E-02   
mat fuel3 4.9186E-02 tmp 433. vol  2721.    
     92235.03c  7.6963E-03
     92238.03c  3.0882E-02
     42000.03c  1.0608E-02   
mat fuel4 4.9186E-02 tmp 433. vol  3028.    
     92235.03c  7.6963E-03
     92238.03c  3.0882E-02
     42000.03c  1.0608E-02   
mat fuel5 4.9186E-02 tmp 433. vol  3334.    
     92235.03c  7.6963E-03
     92238.03c  3.0882E-02
     42000.03c  1.0608E-02   
mat fuel6 4.9186E-02 tmp 433. vol  3640.  
     92235.03c  7.6963E-03
     92238.03c  3.0882E-02
     42000.03c  1.0608E-02   
mat fuel7  4.9186E-02 tmp 433. vol  3947.    
     92235.03c  7.6963E-03
     92238.03c  3.0882E-02
     42000.03c  1.0608E-02   
mat fuel8  4.9186E-02 tmp 433. vol  4253.    
     92235.03c  7.6963E-03
     92238.03c  3.0882E-02
     42000.03c  1.0608E-02   
mat fuel9  4.9186E-02 tmp 433. vol  4559.    
     92235.03c  7.6963E-03
     92238.03c  3.0882E-02
     42000.03c  1.0608E-02   
mat fuel10 4.9186E-02 tmp 433. vol  4866.    
     92235.03c  7.6963E-03
     92238.03c  3.0882E-02
     42000.03c  1.0608E-02   
% ------ H2O Coolant ------
% T=70C, P=2.3 MPa, rho=0.979 g/cc
mat h2o  9.818E-02       moder h2o 1001
      1001.03c  6.545E-02
      8016.03c  3.273E-02
% ------ D2O ------
mat d2o 9.986E-02     moder d2o 1002      
      1002.03c  6.657E-02
      8016.03c  3.329E-02
% ------ Al-6061 ------
mat al6061 -2.715       % Al-6061 density 2.715 g/cc       
    14000.03c  -0.7   %      0.7   % Si
    26000.03c  -0.6   %      0.60  % Fe
    29000.03c  -0.22  %      0.22  % Cu
    25055.03c  -0.08  %      0.08  % Mn
    12000.03c  -1.0   %      1.0   % Mg
    24000.03c  -0.2   %      0.1   % Cr
    30000.03c  -0.08  %      0.08  % Zn
    22000.03c  -0.03  %      0.03  % Ti 
    13027.03c  -97.09 %      97.09 % Al
% ------ Al-6061 Rack / part water ------
mat AlRack    6.22E-02       % 5% water       
    14000.03c  3.87E-04 %    
    26000.03c  1.67E-04 %    
    29000.03c  5.38E-05 %    
    25055.03c  2.26E-05 %    
    12000.03c  6.39E-04 %    
    24000.03c  5.97E-05 %    
    30000.03c  1.90E-05 %    
    22000.03c  9.73E-06 %     
    13027.03c  5.59E-02 %    
     1001.03c  3.27E-03
     8016.03c  1.64E-03
% ------ Beryllium ------
% assumed 6.3% by volume H2O
mat be9  1.2188E-01  moder be 4009 moder h2o 1001  % moder be 
    4009.03c  1.157E-01
    1001.03c  4.120E-03
    8016.03c  2.060E-03
mat AlBe10  7.09E-02  moder be 4009 moder h2o 1001  % moder be 
	4009.03c  1.616E-02
   13027.03c  4.859E-02
    1001.03c  4.120E-03
    8016.03c  2.060E-03
mat AlBe20  7.85E-02  moder be 4009 moder h2o 1001  % moder be 
	4009.03c  3.097E-02
   13027.03c  4.137E-02
    1001.03c  4.120E-03
    8016.03c  2.060E-03
mat AlBe30  8.55E-02  moder be 4009 moder h2o 1001  % moder be 
	4009.03c  4.457E-02
   13027.03c  3.474E-02
    1001.03c  4.120E-03
    8016.03c  2.060E-03
mat AlBe40  9.19E-02  moder be 4009 moder h2o 1001  % moder be 
	4009.03c  5.712E-02
   13027.03c  2.862E-02
    1001.03c  4.120E-03
    8016.03c  2.060E-03
mat AlBe60  1.03E-01  moder be 4009 moder h2o 1001  % moder be 
	4009.03c  7.951E-02
   13027.03c  1.771E-02
    1001.03c  4.120E-03
    8016.03c  2.060E-03
mat AlBe80  1.13E-01  moder be 4009 moder h2o 1001  % moder be 
	4009.03c  9.889E-02
   13027.03c  8.258E-03
    1001.03c  4.120E-03
    8016.03c  2.060E-03
% ------  SS 304   ------
% Fe-0.08C-2.0Mn-0.045P-0.03S-1.0Si-19Cr-9Ni 
mat ss304   -8.0       % ss 304 8g/cc
     6000.03c  -0.08   %     0.08   % C
    25055.03c  -2.0    %     2.0    % Mn
    15031.03c  -0.045  %     0.045  % P
    16000.03c  -0.03   %     0.03   % S
    14000.03c  -0.75   %     0.75   % Si 
    24000.03c  -19.    %     19.    % Cr
    28000.03c  -9.25   %     9.25   % Ni
     7014.03c  -0.05   %     0.05   % N
    26000.03c  -68.795 %    68.795  % Fe
% ------ Helium Coolant ------
mat helium 0.0007     
      2004.03c  7.0000E-04
% ---- Al/H2O 50/50 mix in test spaces -----
mat AlH2Omix  7.929E-02  moder h2o 1001
      1001.03c  3.270E-02
      8016.03c  1.635E-02
     13027.03c  3.024E-02  
% ----- Zircalloy4 -------
mat zirc4  -6.56     tmp 398.
     40000.03c  -98.23   %     98.23 % Zr
     50000.03c  -1.45    %     1.45  % Sn
     26000.03c  -0.21    %     0.21  % Fe      
     24000.03c  -0.10    %     0.10  % Cr
     72000.03c  -0.01    %     0.01  % Hf
therm h2o lwtr.01t
therm d2o hwtr.01t
therm be  be.01t 
% therm Al ???


% TALLIES



% Flux 1MeV cutoff in  test zones
det CTrap dc 120 du 2 dv 360. de 1MeV dx -3.   3.   1  dy  -3.  3.  1  dz -50. 50. 10
det PTrap dc 120 du 2 dv 360. de 1MeV dx -3.   3.   1  dy 20.9 26.9 1  dz -50. 50. 10

% Flux broken down into 3.
det FTref1 dc 153  du 0  dv 160. de 1MeV dx  55.4  59.4 1 dy 21.7 25.7 1  dz -50. 50. 10 
det FTref2 dc 153  du 0  dv 160. de 1MeV dx  73.8  77.8 1 dy 29.4 33.4 1  dz -50. 50. 10 
det FTref3 dc 153  du 0  dv 160. de 1MeV dx  92.3  96.3 1 dy 37.0 41.0 1  dz -50. 50. 10 
det FTref4 dc 153  du 0  dv 160. de 1MeV dx 110.8 114.8 1 dy 44.7 48.7 1  dz -50. 50. 10 

ene 1MeV   1 1.0E-15 0.625E-06 1.0  20.  
)"
}; // vector serpent_inputs_


SerpentTest::SerpentTest(const jobscript::JOBSCRIPT &p_s, const std::string &e_n): AppTest("serpent", "", p_s, serpent_inputs_.size(), e_n),
                                                                                 log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                                                 result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                                                 flog_(log_file_name_,std::ios_base::app),
                                                                                 fresult_(result_file_name_,std::ios_base::app) {}


void SerpentTest::runTest() {
  std::string cmd_result;
  std::string script_cmd_result;
//  std::cout << "Execute runTest member function from SerpentTest object " << __FILE__ << "\t" <<__LINE__ << std::endl;
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
  for (auto serpent_input: serpent_inputs_) {
    createFileFromStr(getInputFileNames()[c_i], serpent_input);
    script_cmd_result = exeAppTest(flog_, fresult_, getJobScripts()[c_i], getJobScripts()[c_i].getJobName());
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
}


} // namespace hpcswtest

