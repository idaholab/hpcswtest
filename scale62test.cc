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
Scale62Test subclass source code.

Date Created: Wed Nov 23 13:00:57 MST 2016

Author: Cormac Garvey

*/

#include "scale62test.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> Scale62Test::scale_inputs_ = {
R"(=arp
w17x17
3
3
350
375
455
38.285714
33.986667
15.43956
1
1
1
0.7295
w17x17_burnlib
end
=origens
case {
    lib {file="w17x17_burnlib"}
    title="w17x17, 1 MTU: Cycle 1 / 5"
    time=[50 100 175 250 275 300 325 350]
    power=[38 38 40 40 35 35 37 37]
    print {rel_cutoff=yes cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
    mat {units="grams" iso {u234=254 u235=30000 u236=138 u238=969608 8000=134400}}
}
case {
    title="w17x17, 1 MTU: Cycle 2 / 5"
    time {t=[0.01 0.03 0.1 0.3 1 3 10 30 49] start=0}
    print {rel_cutoff=yes cutoffs=[all=1e-05]}
}
case {
    lib {pos=2}
    title="w17x17, 1 MTU: Cycle 3 / 5"
    time {t=[50 100 130 180 240 300 350 405] start=0}
    power=[35 35 0 34 34 34 33 33]
    print {rel_cutoff=yes cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    title="w17x17, 1 MTU: Cycle 4 / 5"
    time {t=[0.01 0.03 0.1 0.3 1 3 10 30 70] start=0}
    print {rel_cutoff=yes cutoffs=[all=1e-05]}
}
case {
    lib {pos=3}
    title="w17x17, 1 MTU: Cycle 5 / 5"
    time {t=[50 100 150 200 250 300 350 400 455] start=0}
    power=[16 16 16 16 15 15 15 15 15]
    print {rel_cutoff=yes cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
    save {steps=[9] file="arp_dumpfile.f71"}
}
end
=arp
w15x15
2.5610
4
243.5
243.5
156
156
44.685198
40.249576
36.608056
33.783325
1
1
1
1
0.7135
w15x15_burnlib
end
=origens
case {
    lib {file="w15x15_burnlib"}
    title="cycle 1, part1 hb robinson n-9 226 cm (31.66 gwd/t), 0.8815 mtu"
    time=[24.35 48.7 73.05 97.4 121.75 146.1 170.45 194.8 219.15 243.5]
    power=[39.39 39.39 39.39 39.39 39.39 39.39 39.39 39.39 39.39 39.39]
    mat {units="grams" iso {u234=202.745 u235=22575.22 u236=114.595 u238=858607.4 8000=118500}}
    print {rel_cutoff=yes cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    title="cycle 1, part2 hb robinson n-9 226 cm (31.66 gwd/t), 0.8815 mtu"
    time {t=[0.01 0.03 0.1 0.3 1 3 10 30 40] start=0}
    print {rel_cutoff=yes cutoffs=[all=1e-05]}
}
case {
    lib {pos=2}
    title="cycle 2, part1 hb robinson n-9 226 cm (31.66 gwd/t), 0.8815 mtu"
    time {t=[24.35 48.7 73.05 97.4 121.75 146.1 170.45 194.8 219.15 243.5] start=0}
    power=[35.48 35.48 35.48 35.48 35.48 35.48 35.48 35.48 35.48 35.48]
    print {rel_cutoff=yes cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    title="cycle 2, part2 hb robinson n-9 226 cm (31.66 gwd/t), 0.8815 mtu"
    time {t=[0.01 0.03 0.1 0.3 1 3 10 30 64] start=0}
    print {rel_cutoff=yes cutoffs=[all=1e-05]}
}
case {
    lib {pos=3}
    title="case 5, 0.8815 mtu"
    time {t=[15.6 31.2 46.8 62.4 78 93.6 109.2 124.8 140.4 156] start=0}
    power=[32.27 32.27 32.27 32.27 32.27 32.27 32.27 32.27 32.27 32.27]
    print {rel_cutoff=yes cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    title="case 6, 0.8815 mtu"
    time {t=[0.01 0.03 0.1 0.3 1 3 10 30 39] start=0}
    print {rel_cutoff=yes cutoffs=[all=1e-05]}
}
case {
    lib {pos=4}
    title="case 7, 0.8815 mtu"
    time {t=[15.6 31.2 46.8 62.4 78 93.6 109.2 124.8 140.4 156] start=0}
    power=[29.78 29.78 29.78 29.78 29.78 29.78 29.78 29.78 29.78 29.78]
    print {rel_cutoff=yes cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    title="case 8, 0.8815 mtu"
    time {t=[1 3 10 30 100 300 1000 3000 3936] start=0}
    print {rel_cutoff=yes cutoffs=[all=1e-05]}
    save {file="arp_dumpfile.f71" steps=[4 5 6 7 8 9]}
}
end
=arp
ge7x7-0
2.5
5
807
306
164
317
348
12.760252
24.227129
18.212408
5.8780231
7.9915878
1
1
1
1
1
0.4323
cooper_cz205
end
=origens
'------------ Cooper cz205, ge7x7-0: begin -----------
bounds {neutron="xn27g19v7.0" gamma="xn27g19v7.0"}
case {
    lib {file="cooper_cz205"}
    title="cycle 1 - cooper assembly cz205, 0.1902 mtu"
    time=[80.7 161.4 242.1 322.8 403.5 484.2 564.9 645.6 726.3 807]
    power=[2.427 2.427 2.427 2.427 2.427 2.427 2.427 2.427 2.427 2.427]
    mat {iso { u234(2)=41.844  u235(2)=4755  u236(2)=22.824  u238(2)=185380.3
               1000(1)=3100    5000(1)=13    8000(1)=50500  24000(1)=450
              25000(1)=29     26000(1)=1200 27000(1)=4.6    28000(1)=450
              40000(1)=98200  50000(1)=1600 64000(1)=544}}
    print {rel_cutoff=yes cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    title="downtime after cycle 1, 0.1902 mtu"
    time {t=[0.01 0.03 0.1 0.3 1 3 10 30 59] start=0}
    print {rel_cutoff=yes cutoffs=[all=1e-05]}
}
case {
    lib {pos=2}
    title="cycle 2 - cooper assembly cz205, 0.1902 mtu"
    time {t=[30.6 61.2 91.8 122.4 153 183.6 214.2 244.8 275.4 306] start=0}
    power=[4.608 4.608 4.608 4.608 4.608 4.608 4.608 4.608 4.608 4.608]
    print {rel_cutoff=yes cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    title="decay after cycle 2 - cooper assembly cz205, 0.1902 mtu"
    time {t=[0.01 0.03 0.1 0.3 1 3 10 30 31] start=0}
    print {rel_cutoff=yes cutoffs=[all=1e-05]}
}
case {
    lib {pos=3}
    title="cycle 3, 0.1902 mtu"
    time {t=[16.4 32.8 49.2 65.6 82 98.4 114.8 131.2 147.6 164] start=0}
    power=[3.464 3.464 3.464 3.464 3.464 3.464 3.464 3.464 3.464 3.464]
    print {rel_cutoff=yes cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    title="downtime after cycle 3 - cooper assembly cz205, 0.1902 mtu"
    time {t=[0.1 0.3 1 3 10 30 100 300 799] start=0}
    print {rel_cutoff=yes cutoffs=[all=1e-05]}
}
case {
    lib {pos=4}
    title="cycle 6 - cooper assembly cz205, 0.1902 mtu"
    time {t=[31.7 63.4 95.1 126.8 158.5 190.2 221.9 253.6 285.3 317] start=0}
    power=[1.118 1.118 1.118 1.118 1.118 1.118 1.118 1.118 1.118 1.118]
    print {rel_cutoff=yes cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    title="decay after cycle 6, 0.1902 mtu"
    time {t=[0.01 0.03 0.1 0.3 1 3 10 30 48] start=0}
    print {rel_cutoff=yes cutoffs=[all=1e-05]}
}
case {
    lib {pos=5}
    title="cycle 7 - cooper assembly cz205, 0.1902 mtu"
    time {t=[34.8 69.6 104.4 139.2 174 208.8 243.6 278.4 313.2 348] start=0}
    power=[1.52 1.52 1.52 1.52 1.52 1.52 1.52 1.52 1.52 1.52]
    print {rel_cutoff=yes cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    title="final cooldown after cycle 7, 0.1902 mtu"
    time {t=[10 30 100 300 857 871 886 892 899 946] start=0}
    print {rel_cutoff=yes cutoffs=[all=1e-05]}
    save {file="arp_dumpfile.f71" steps=[1 2 3 4 5 6 7 8 9 10]}
}
end
=arp
w15x15
2.5570
3
314
327
312
30.192939
29.824599
28.590221
1
1
1
0.7135
w15x15_tp
end
=origens
'------------ Turkey Point w15x15: begin -----------
case {
    lib {file="w15x15_tp"}
    title="case 1 - turkey point assembly d-15, 0.4561 mtu"
    time=[31.4 62.8 94.2 125.6 157 188.4 219.8 251.2 282.6 314]
    power=[13.771 13.771 13.771 13.771 13.771 13.771 13.771 13.771 13.771 13.771]
    mat {units="grams" iso { u234(ac)=104.903 u235(ac)=11662.48 u236(ac)=54.732  u238(ac)=444277.9
                             8000(lt)=62000  24000(lt)=2700    25000(lt)=150    26000(lt)=5900
                            27000(lt)=34     28000(lt)=4500    40000(lt)=101000 50000(lt)=1600}}
    print {cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    title="case 2 - turkey point assembly d-15, 0.4561 mtu"
    time {t=[0.01 0.03 0.1 0.3 1 3 10 30 58] start=0}
    print {rel_cutoff=yes cutoffs=[all=0.05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    lib {pos=2}
    title="case 3 turkey point assembly d-15, 0.4561 mtu"
    time {t=[346.7 379.4 412.1 444.8 477.5 510.2 542.9 575.6 608.3 641] start=314}
    power=[13.603 13.603 13.603 13.603 13.603 13.603 13.603 13.603 13.603 13.603]
    print {rel_cutoff=yes cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    title="case 4 - turkey point assembly d-15, 0.4561 mtu"
    time {t=[0.01 0.03 0.1 0.3 1 3 10 30 62] start=0}
    print {rel_cutoff=yes cutoffs=[all=0.05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    lib {pos=3}
    title="case 5, turkey point assembly d-15, 0.4561 mtu"
    time {t=[672.2 703.4 734.6 765.8 797 828.2 859.4 890.6 921.8 953] start=641}
    power=[13.04 13.04 13.04 13.04 13.04 13.04 13.04 13.04 13.04 13.04]
    print {rel_cutoff=yes cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    title="case 6, turkey point assembly d-15, 0.4561 mtu"
    time {t=[10 30 100 300 962 1144 2077] start=0}
    print {rel_cutoff=yes cutoffs=[all=0.05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
    save {file="arp_dumpfile.f71" steps=[5 6 7]}
}
end
=arp
candu37
 0.711
 5
 5r 45.30423
 5r 35
 5r 1
 1
candu37e_burnlib
end
=origens
'------------ CANDU 37e: begin -----------
bounds {neutron="xn27g19v7.0" gamma="xn27g19v7.0"}
case {
    lib {file="candu37e_burnlib"}
    title="cycle 1 -candu 685 gj/kgu, 1 mtu"
    time=[4.530423 9.060846 13.59127 18.12169 22.65211 27.18254 31.71296 36.24338 40.77381 45.30423]
    power=[35 35 35 35 35 35 35 35 35 35]
    mat {iso {u235=7110 u238=992890 8000=134000}}
    print {cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    lib {pos=2}
    title="cycle 2 -candu 685 gj/kgu, 1 mtu"
    time {t=[49.83465 54.36507 58.8955 63.42592 67.95634 72.48677 77.01719 81.54761 86.07803 90.60846] start=45.30423}
    power=[35 35 35 35 35 35 35 35 35 35]
    print {cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    lib {pos=3}
    title="cycle 3 -candu 685 gj/kgu, 1 mtu"
    time {t=[95.13888 99.6693 104.1997 108.7301 113.2606 117.791 122.3214 126.8518 131.3823 135.9127] start=90.60846}
    power=[35 35 35 35 35 35 35 35 35 35]
    print {cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    lib {pos=4}
    title="cycle 4 -candu 685 gj/kgu, 1 mtu"
    time {t=[140.4431 144.9735 149.504 154.0344 158.5648 163.0952 167.6256 172.1561 176.6865 181.2169] start=135.9127}
    power=[35 35 35 35 35 35 35 35 35 35]
    print {cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    lib {pos=5}
    title="cycle 5 -candu 685 gj/kgu, 1 mtu"
    time {t=[185.7473 190.2778 194.8082 199.3386 203.869 208.3995 212.9299 217.4603 221.9907 226.5211] start=181.2169}
    power=[35 35 35 35 35 35 35 35 35 35]
    print {cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    lib {pos=5}
    title="cycle 5 down - candu 685 gj/kgu, 1 mtu"
    time {t=[0.001 0.003 0.01 0.03 0.1 0.3 1] start=0 units=years}
    print {cutoffs=[all=0.05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
end
=arp
mox_w17x17
 8
 54.7
 1.0
 3
 419.9475
 419.9475
 419.9475
 38.1
 38.1
 38.1
 1
 1
 1
 0.723
mox17x17_burnlib
end
=origens
'------------ MOX 17x17: begin -----------
case {
    lib {file="mox17x17_burnlib"}
    title="cycle 1 -oecd/neasc phase iv-b mox (3a), 1 mthm"
    time=[41.99475 83.9895 125.9843 167.979 209.9738 251.9685 293.9633 335.958 377.9528 419.9475]
    power=[38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1]
    mat {units="grams" iso {u234=10.948 u235=2300 u238=917689.1 pu238=2000 pu239=43760 pu240=20880 pu241=7600 pu242=5760 8000=134272}}
    print {cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    title="decay - oecd/neasc phase iv-b mox (3a), 1 mthm"
    time {t=[0.01 0.03 0.1 0.3 1 3 10 30 46.66083] start=0}
    print {cutoffs=[all=0.05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    lib {pos=2}
    title="cycle 2 -oecd/neasc phase iv-b mox (3a), 1 mthm"
    time {t=[461.9423 503.937 545.9318 587.9265 629.9213 671.916 713.9108 755.9055 797.9003 839.895] start=419.9475}
    power=[38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1]
    print {cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    title="decay - oecd/neasc phase iv-b mox (3a), 1 mthm"
    time {t=[0.01 0.03 0.1 0.3 1 3 10 30 46.66083] start=0}
    print {cutoffs=[all=0.05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    lib {pos=3}
    title="cycle 3 -oecd/neasc phase iv-b mox (3a), 1 mthm"
    time {t=[881.8898 923.8845 965.8793 1007.874 1049.869 1091.864 1133.858 1175.853 1217.848 1259.843] start=839.895}
    power=[38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1]
    print {cutoffs=[all=1e-05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
case {
    title="cycle 3 down - oecd/neasc phase iv-b mox (3a), 1 mthm"
    time {t=[0.001 0.003 0.01 0.03 0.1 0.3 1 3 5] start=0 units=years}
    print {cutoffs=[all=0.05] nuc {sublibs=["lt" "ac" "fp"] units=["grams"] total=no}}
}
end)"
}; // vector scale_inputs_


Scale62Test::Scale62Test(const jobscript::PbsScript &p_s, const std::string &s_t): ScaleTest(p_s, s_t),
                                                       log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                       result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                       flog_(log_file_name_,std::ios_base::app),
                                                       fresult_(result_file_name_,std::ios_base::app) {}


void Scale62Test::runTest() {
  std::string cmd_result;
  std::string script_cmd_result;
//  std::cout << "Execute runTest member function from ScaleTest object " << __FILE__ << "\t" <<__LINE__ << std::endl;
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
  for (auto scale_input: scale_inputs_) {
    createFileFromStr(getInputFileNames()[c_i], scale_input);
    fresult_ << module_name_version(getPbsScripts()[c_i].getModules()[getPbsScripts()[c_i].getModules().size()-1]) << "\t" << getPbsScripts()[c_i].getJobName() << "\t" << "job." << std::endl;
    script_cmd_result = subPbsScript(flog_, getPbsScripts()[c_i]);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
}


} // namespace hpcswtest

