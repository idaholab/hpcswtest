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
ScaleTest subclass source code.

Date Created: Wed Dec 16 14:32:52 MST 2015

Author: Cormac Garvey

*/

#include "scaletest.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> ScaleTest::scale_inputs_ = {
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
ft33f001
end
#origens
0$$ a4 33 a11 71 e t
westinghouse 17x17
3$$ 33 a3 1 0 a16 2 a33 0 e t
35$$ 0 t
56$$ 8 8 a10 0 a13 5 a15 3 a18 1 e
57** 0 a3 1e-05 0.2966102 e t
cycle 1
1 mtu
58** 38 38 40 40 35 35 37 37  
60** 50 100 175 250 275 300 325 350  
66$$ a1 2 a5 2 a9 2 e 
73$$ 922340 922350 922360 922380 80000 
74** 254 30000 138 969608 134400 
75$$ 2 2 2 2 4 
t
54$$ a8 1 a11 0  e
56$$ a2 9 a6 3 a10 8 a15 3 a17 4 e
57** 0 a3 1e-05 e 
95$$ 0 t
cycle 2
1 mtu
60** 0.01 0.03 0.1 0.3 1 3 10 30 49  
t
westinghouse 17x17
3$$ 33 a3 2 0 a33 0 e t
35$$ 0 t
56$$ 8 8 a10 9 a15 3 a18 1 e
57** 0 a3 1e-05 0.3177966 e t
cycle 3
1 mtu
58** 35 35 0 34 34 34 33 33  
60** 50 100 130 180 240 300 350 405  
66$$ a1 2 a5 2 a9 2 e t
54$$ a8 1 a11 0  e
56$$ a2 9 a6 3 a10 8 a15 3 a17 4 e
57** 0 a3 1e-05 e 
95$$ 0 t
cycle 4
1 mtu
60** 0.01 0.03 0.1 0.3 1 3 10 30 70  
t
westinghouse 17x17
3$$ 33 a3 3 0 a33 0 e t
35$$ 0 t
56$$ 9 9 a6 1 a10 9 a15 3 a18 1 e
57** 0 a3 1e-05 0.3855932 e t
case 5
1 mtu
58** 16 16 16 16 15 15 15 15 15  
60** 50 100 150 200 250 300 350 400 455  
66$$ a1 2 a5 2 a9 2 e t
56$$ 0 0 a10  9 e t 
56$$ f0 t
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
ft33f001
end
=origens
0$$ a4 33 a11 71 e t
15x15
3$$ 33 a3 1 0 a16 2 a33 0 e t
35$$ 0 t
56$$ 10 10 a10 0 a13 5 a15 3 a18 1 e
57** 0 a3 1e-05 0.3047559 e t
cycle 1, part1 hb robinson n-9 226 cm (31.66 gwd/t)
0.8815 mtu
58** 39.39 39.39 39.39 39.39 39.39 39.39 39.39 39.39 39.39 39.39  
60** 24.35 48.7 73.05 97.4 121.75 146.1 170.45 194.8 219.15 243.5  
66$$ a1 2 a5 2 a9 2 e 
73$$ 922340 922350 922360 922380 80000 
74** 202.745 22575.22 114.595 858607.4 118500 
75$$ 2 2 2 2 4 
t
54$$ a8 1 a11 0  e
56$$ a2 9 a6 3 a10 10 a15 3 a17 4 e
57** 0 a3 1e-05 e 
95$$ 0 t
cycle 1, part2 hb robinson n-9 226 cm (31.66 gwd/t)
0.8815 mtu
60** 0.01 0.03 0.1 0.3 1 3 10 30 40  
t
15x15
3$$ 33 a3 2 0 a33 0 e t
35$$ 0 t
56$$ 10 10 a10 9 a15 3 a18 1 e
57** 0 a3 1e-05 0.3047559 e t
cycle 2, part1 hb robinson n-9 226 cm (31.66 gwd/t)
0.8815 mtu
58** 35.48 35.48 35.48 35.48 35.48 35.48 35.48 35.48 35.48 35.48  
60** 24.35 48.7 73.05 97.4 121.75 146.1 170.45 194.8 219.15 243.5  
66$$ a1 2 a5 2 a9 2 e t
54$$ a8 1 a11 0  e
56$$ a2 9 a6 3 a10 10 a15 3 a17 4 e
57** 0 a3 1e-05 e 
95$$ 0 t
cycle 2, part2 hb robinson n-9 226 cm (31.66 gwd/t)
0.8815 mtu
60** 0.01 0.03 0.1 0.3 1 3 10 30 64  
t
15x15
3$$ 33 a3 3 0 a33 0 e t
35$$ 0 t
56$$ 10 10 a10 9 a15 3 a18 1 e
57** 0 a3 1e-05 0.1952441 e t
case 5
0.8815 mtu
58** 32.27 32.27 32.27 32.27 32.27 32.27 32.27 32.27 32.27 32.27  
60** 15.6 31.2 46.8 62.4 78 93.6 109.2 124.8 140.4 156  
66$$ a1 2 a5 2 a9 2 e t
54$$ a8 1 a11 0  e
56$$ a2 9 a6 3 a10 10 a15 3 a17 4 e
57** 0 a3 1e-05 e 
95$$ 0 t
case 6
0.8815 mtu
60** 0.01 0.03 0.1 0.3 1 3 10 30 39  
t
15x15
3$$ 33 a3 4 0 a33 0 e t
35$$ 0 t
56$$ 10 10 a10 9 a15 3 a18 1 e
57** 0 a3 1e-05 0.1952441 e t
case 7
0.8815 mtu
58** 29.78 29.78 29.78 29.78 29.78 29.78 29.78 29.78 29.78 29.78  
60** 15.6 31.2 46.8 62.4 78 93.6 109.2 124.8 140.4 156  
66$$ a1 2 a5 2 a9 2 e t
54$$ a8 1 a11 0  e
56$$ a2 9 a6 1 a10 10 a15 3 a17 4 e
57** 0 a3 1e-05 e 
95$$ 0 t
case 8
0.8815 mtu
60** 1 3 10 30 100 300 1000 3000 3936  
t
56$$ 0 0 a10  4 e t 
56$$ 0 0 a10  5 e t 
56$$ 0 0 a10  6 e t 
56$$ 0 0 a10  7 e t 
56$$ 0 0 a10  8 e t 
56$$ 0 0 a10  9 e t 
56$$ f0 t
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
ft33f001
end
=origens
0$$ a4 33 a11 71 e t
cooper assembly cz205
3$$ 33 a3 1 27 a16 2 a33 18 e t
35$$ 0 t
56$$ 10 10 a10 0 a13 15 a15 3 a18 1 e
57** 0 a3 1e-05 0.415551 e t
cycle 1
0.1902 mtu
58** 2.427 2.427 2.427 2.427 2.427 2.427 2.427 2.427 2.427 2.427  
60** 80.7 161.4 242.1 322.8 403.5 484.2 564.9 645.6 726.3 807  
66$$ a1 2 a5 2 a9 2 e 
73$$ 922340 922350 922360 922380 10000 50000 80000 240000 250000 260000
 270000 280000 400000 500000 640000 
74** 41.844 4755 22.824 185380.3 3100 13 50500 450 29 1200 4.6 450 98200
 1600 544 
75$$ 2 2 2 2 4 4 4 4 4 4 4 4 4 4 4 
t
54$$ a8 1 a11 0 e
56$$ a2 9 a6 3 a10 10 a15 3 a17 4 e
57** 0 a3 1e-05 e 
95$$ 0 t
downtime after cycle 1
0.1902 mtu
60** 0.01 0.03 0.1 0.3 1 3 10 30 59  
t
cooper assembly cz205
3$$ 33 a3 2 27 a33 18 e t
35$$ 0 t
56$$ 10 10 a10 9 a15 3 a18 1 e
57** 0 a3 1e-05 0.1575695 e t
cycle 2
0.1902 mtu
58** 4.608 4.608 4.608 4.608 4.608 4.608 4.608 4.608 4.608 4.608  
60** 30.6 61.2 91.8 122.4 153 183.6 214.2 244.8 275.4 306  
66$$ a1 2 a5 2 a9 2 e t
54$$ a8 1 a11 0 e
56$$ a2 9 a6 3 a10 10 a15 3 a17 4 e
57** 0 a3 1e-05 e 
95$$ 0 t
decay after cycle 2
0.1902 mtu
60** 0.01 0.03 0.1 0.3 1 3 10 30 31  
t
cooper assembly cz205
3$$ 33 a3 3 27 a33 18 e t
35$$ 0 t
56$$ 10 10 a10 9 a15 3 a18 1 e
57** 0 a3 1e-05 0.08444902 e t
cycle 3
0.1902 mtu
58** 3.464 3.464 3.464 3.464 3.464 3.464 3.464 3.464 3.464 3.464  
60** 16.4 32.8 49.2 65.6 82 98.4 114.8 131.2 147.6 164  
66$$ a1 2 a5 2 a9 2 e t
54$$ a8 1 a11 0 e
56$$ a2 9 a6 3 a10 10 a15 3 a17 4 e
57** 0 a3 1e-05 e 
95$$ 0 t
downtime after cycle 3
0.1902 mtu
60** 0.1 0.3 1 3 10 30 100 300 799  
t
cooper assembly cz205
3$$ 33 a3 4 27 a33 18 e t
35$$ 0 t
56$$ 10 10 a10 9 a15 3 a18 1 e
57** 0 a3 1e-05 0.1632338 e t
cycle 6
0.1902 mtu
58** 1.118 1.118 1.118 1.118 1.118 1.118 1.118 1.118 1.118 1.118  
60** 31.7 63.4 95.1 126.8 158.5 190.2 221.9 253.6 285.3 317  
66$$ a1 2 a5 2 a9 2 e t
54$$ a8 1 a11 0 e
56$$ a2 9 a6 3 a10 10 a15 3 a17 4 e
57** 0 a3 1e-05 e 
95$$ 0 t
decay after cycle 6
0.1902 mtu
60** 0.01 0.03 0.1 0.3 1 3 10 30 48  
t
cooper assembly cz205
3$$ 33 a3 5 27 a33 18 e t
35$$ 0 t
56$$ 10 10 a10 9 a15 3 a18 1 e
57** 0 a3 1e-05 0.1791967 e t
cycle 7
0.1902 mtu
58** 1.52 1.52 1.52 1.52 1.52 1.52 1.52 1.52 1.52 1.52  
60** 34.8 69.6 104.4 139.2 174 208.8 243.6 278.4 313.2 348  
66$$ a1 2 a5 2 a9 2 e t
54$$ a8 1 a11 0 e
56$$ a2 10 a6 1 a10 10 a15 3 a17 4 e
57** 0 a3 1e-05 e 
95$$ 0 t
final cooldown after cycle 7
0.1902 mtu
60** 10 30 100 300 857 871 886 892 899 946  
t
56$$ 0 0 a10  1 e t 
56$$ 0 0 a10  2 e t 
56$$ 0 0 a10  3 e t 
56$$ 0 0 a10  4 e t 
56$$ 0 0 a10  5 e t 
56$$ 0 0 a10  6 e t 
56$$ 0 0 a10  7 e t 
56$$ 0 0 a10  8 e t 
56$$ 0 0 a10  9 e t 
56$$ 0 0 a10  10 e t 
56$$ f0 t
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
ft33f001
end
=origens
0$$ a4 33 a11 71 e t
turkey point assembly d-15
3$$ 33 a3 1 0 a16 2 a33 0 e t
35$$ 0 t
56$$ 10 10 a10 0 a13 12 a15 3 a18 1 e
57** 0 a3 1e-05 0.3294858 e t
case 1
0.4561 mtu
58** 13.771 13.771 13.771 13.771 13.771 13.771 13.771 13.771 13.771
 13.771  
60** 31.4 62.8 94.2 125.6 157 188.4 219.8 251.2 282.6 314  
66$$ a1 2 a5 2 a9 2 e 
73$$ 922340 922350 922360 922380 80000 240000 250000 260000 270000
 280000 400000 500000 
74** 104.903 11662.48 54.732 444277.9 62000 2700 150 5900 34 4500 101000
 1600 
75$$ 2 2 2 2 4 4 4 4 4 4 4 4 
t
54$$ a8 1 a11 0  e
56$$ a2 9 a6 3 a10 10 a15 3 a17 4 e
57** 0 a3 1e-05 e 
95$$ 0 t
case 2
0.4561 mtu
60** 0.01 0.03 0.1 0.3 1 3 10 30 58  
61** f0.05 
65$$ 
'gram-atoms   grams   curies   watts-all   watts-gamma
 3z   1   0   0   3z   3z   3z   6z 
 3z   1   0   0   3z   3z   3z   6z 
 3z   1   0   0   3z   3z   3z   6z 
t
turkey point assembly d-15
3$$ 33 a3 2 0 a33 0 e t
35$$ 0 t
56$$ 10 10 a10 9 a15 3 a18 1 e
57** 314 a3 1e-05 0.343127 e t
case 3
0.4561 mtu
58** 13.603 13.603 13.603 13.603 13.603 13.603 13.603 13.603 13.603
 13.603  
60** 346.7 379.4 412.1 444.8 477.5 510.2 542.9 575.6 608.3 641  
66$$ a1 2 a5 2 a9 2 e t
54$$ a8 1 a11 0  e
56$$ a2 9 a6 3 a10 10 a15 3 a17 4 e
57** 0 a3 1e-05 e 
95$$ 0 t
case 4
0.4561 mtu
60** 0.01 0.03 0.1 0.3 1 3 10 30 62  
61** f0.05 
65$$ 
'gram-atoms   grams   curies   watts-all   watts-gamma
 3z   1   0   0   3z   3z   3z   6z 
 3z   1   0   0   3z   3z   3z   6z 
 3z   1   0   0   3z   3z   3z   6z 
t
turkey point assembly d-15
3$$ 33 a3 3 0 a33 0 e t
35$$ 0 t
56$$ 10 10 a10 9 a15 3 a18 1 e
57** 641 a3 1e-05 0.3273872 e t
case 5
0.4561 mtu
58** 13.04 13.04 13.04 13.04 13.04 13.04 13.04 13.04 13.04 13.04  
60** 672.2 703.4 734.6 765.8 797 828.2 859.4 890.6 921.8 953  
66$$ a1 2 a5 2 a9 2 e t
54$$ a8 1 a11 0  e
56$$ a2 7 a6 1 a10 10 a15 3 a17 4 e
57** 0 a3 1e-05 e 
95$$ 0 t
case 6
0.4561 mtu
60** 10 30 100 300 962 1144 2077  
61** f0.05 
65$$ 
'gram-atoms   grams   curies   watts-all   watts-gamma
 3z   1   0   0   3z   3z   3z   6z 
 3z   1   0   0   3z   3z   3z   6z 
 3z   1   0   0   3z   3z   3z   6z 
t
56$$ 0 0 a10  5 e t 
56$$ 0 0 a10  6 e t 
56$$ 0 0 a10  7 e t 
56$$ f0 t
end
=arp
candu37
 0.711
 5
 5r 45.30423
 5r 35
 5r 1
 1
ft33f001
end
=origens
0$$ a4 33 a11 71 e t
candu(37e) library
3$$ 33 a3 1 27 a16 2 a33 18 e t
35$$ 0 t
56$$ 10 10 a6 3 a10 0 a13 3 a15 3 a18 1 e
57** 0 a3 1e-05 0.2 e t
cycle 1 -candu 685 gj/kgu
1 mtu
58** 35 35 35 35 35 35 35 35 35 35  
60** 4.530423 9.060846 13.59127 18.12169 22.65211 27.18254 31.71296
 36.24338 40.77381 45.30423  
66$$ a1 2 a5 2 a9 2 e 
73$$ 922350 922380 80000 
74**  7110  992890 134000
75$$ 2 2 4
t
candu(37e) library
3$$ 33 a3 2 27 a33 18 e t
35$$ 0 t
56$$ 10 10 a6 3 a10 10 a15 3 a18 1 e
57** 45.30423 a3 1e-05 0.2 e t
cycle 2 -candu 685 gj/kgu
1 mtu
58** 35 35 35 35 35 35 35 35 35 35  
60** 49.83465 54.36507 58.8955 63.42592 67.95634 72.48677 77.01719
 81.54761 86.07803 90.60846  
66$$ a1 2 a5 2 a9 2 e t
candu(37e) library
3$$ 33 a3 3 27 a33 18 e t
35$$ 0 t
56$$ 10 10 a6 3 a10 10 a15 3 a18 1 e
57** 90.60846 a3 1e-05 0.2 e t
cycle 3 -candu 685 gj/kgu
1 mtu
58** 35 35 35 35 35 35 35 35 35 35  
60** 95.13888 99.6693 104.1997 108.7301 113.2606 117.791 122.3214
 126.8518 131.3823 135.9127  
66$$ a1 2 a5 2 a9 2 e t
candu(37e) library
3$$ 33 a3 4 27 a33 18 e t
35$$ 0 t
56$$ 10 10 a6 3 a10 10 a15 3 a18 1 e
57** 135.9127 a3 1e-05 0.2 e t
cycle 4 -candu 685 gj/kgu
1 mtu
58** 35 35 35 35 35 35 35 35 35 35  
60** 140.4431 144.9735 149.504 154.0344 158.5648 163.0952 167.6256
 172.1561 176.6865 181.2169  
66$$ a1 2 a5 2 a9 2 e t
candu(37e) library
3$$ 33 a3 5 e t
35$$ 0 t
56$$ 10 10 a10 10 a15 3 a18 1 e
57** 181.2169 a3 1e-05 0.2 e t
cycle 5 -candu 685 gj/kgu
1 mtu
58** 35 35 35 35 35 35 35 35 35 35  
60** 185.7473 190.2778 194.8082 199.3386 203.869 208.3995 212.9299
 217.4603 221.9907 226.5211  
66$$ a1 2 a5 2 a9 2 e t
54$$ a8 1 a11 0 e
56$$ a2 7 a6 1 a10 10 a14 5 a15 3 a17 2 e
57** 0 a3 1e-05 e 
95$$ 0 t
cycle 5 down - candu 685 gj/kgu
1 mtu
60** 0.001 0.003 0.01 0.03 0.1 0.3 1  
61** f0.05 
65$$ 
'gram-atoms   grams   curies   watts-all   watts-gamma
 3z   1   0   0   3z   3z   3z   6z 
 3z   1   0   0   3z   3z   3z   6z 
 3z   1   0   0   3z   3z   3z   6z 
 t
56$$ f0 t
end
=arp
mox17x17
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
 0.72
ft33f001
end
=origens
0$$ a4 33 a11 71 e t
mox17x17 library
3$$ 33 a3 1 0 a16 2 a33 0 e t
35$$ 0 t
56$$ 10 10 a10 0 a13 9 a15 3 a18 1 e
57** 0 a3 1e-05 0.3333333 e t
cycle 1 -oecd/neasc phase iv-b mox (3a)
1 mthm
58** 38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1  
60** 41.99475 83.9895 125.9843 167.979 209.9738 251.9685 293.9633
 335.958 377.9528 419.9475  
66$$ a1 2 a5 2 a9 2 e 
73$$ 922340 922350 922380 942380 942390 942400 942410 942420 80000 
74** 10.948 2300 917689.1 2000 43760 20880 7600 5760 134272 
75$$ 2 2 2 2 2 2 2 2 4 
t
54$$ a8 1 a11 0 e
56$$ a2 9 a6 3 a10 10 a15 3 a17 4 e
57** 0 a3 1e-05 e 
95$$ 0 t
decay - oecd/neasc phase iv-b mox (3a)
1 mthm
60** 0.01 0.03 0.1 0.3 1 3 10 30 46.66083  
61** f0.05 
65$$ 
'gram-atoms   grams   curies   watts-all   watts-gamma
 3z   1   0   0   3z   3z   3z   6z 
 3z   1   0   0   3z   3z   3z   6z 
 3z   1   0   0   3z   3z   3z   6z 
t
mox17x17 library
3$$ 33 a3 2 0 a33 0 e t
35$$ 0 t
56$$ 10 10 a10 9 a15 3 a18 1 e
57** 419.9475 a3 1e-05 0.3333333 e t
cycle 2 -oecd/neasc phase iv-b mox (3a)
1 mthm
58** 38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1  
60** 461.9423 503.937 545.9318 587.9265 629.9213 671.916 713.9108
 755.9055 797.9003 839.895  
66$$ a1 2 a5 2 a9 2 e t
54$$ a8 1 a11 0 e
56$$ a2 9 a6 3 a10 10 a15 3 a17 4 e
57** 0 a3 1e-05 e 
95$$ 0 t
decay - oecd/neasc phase iv-b mox (3a)
1 mthm
60** 0.01 0.03 0.1 0.3 1 3 10 30 46.66083  
61** f0.05 
65$$ 
'gram-atoms   grams   curies   watts-all   watts-gamma
 3z   1   0   0   3z   3z   3z   6z 
 3z   1   0   0   3z   3z   3z   6z 
 3z   1   0   0   3z   3z   3z   6z 
t
mox17x17 library
3$$ 33 a3 3 0 a33 0 e t
35$$ 0 t
56$$ 10 10 a10 9 a15 3 a18 1 e
57** 839.895 a3 1e-05 0.3333333 e t
cycle 3 -oecd/neasc phase iv-b mox (3a)
1 mthm
58** 38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1 38.1  
60** 881.8898 923.8845 965.8793 1007.874 1049.869 1091.864 1133.858
 1175.853 1217.848 1259.843  
66$$ a1 2 a5 2 a9 2 e t
54$$ a8 1 a11 0 e
56$$ a2 9 a6 1 a10 10 a14 5 a15 3 a17 2 e
57** 0 a3 1e-05 e 
95$$ 0 t
cycle 3 down - oecd/neasc phase iv-b mox (3a)
1 mthm
60** 0.001 0.003 0.01 0.03 0.1 0.3 1 3 5  
61** f0.05 
65$$ 
'gram-atoms   grams   curies   watts-all   watts-gamma
 3z   1   0   0   3z   3z   3z   6z 
 3z   1   0   0   3z   3z   3z   6z 
 3z   1   0   0   3z   3z   3z   6z 
 t
56$$ f0 t
end)"
}; // vector scale_inputs_


ScaleTest::ScaleTest(const jobscript::JOBSCRIPT &p_s, const std::string &s_t): AppTest(s_t, "", p_s, scale_inputs_.size()),
                                                       log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                       result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                       flog_(log_file_name_,std::ios_base::app),
                                                       fresult_(result_file_name_,std::ios_base::app) {}


void ScaleTest::runTest() {
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
  std::cout << "Testing: " << module_name_version(getJobScripts()[0].getModules()[getJobScripts()[0].getModules().size()-1]) << std::endl;
  int c_i = 0;
  for (auto scale_input: scale_inputs_) {
    createFileFromStr(getInputFileNames()[c_i], scale_input);
    fresult_ << module_name_version(getJobScripts()[c_i].getModules()[getJobScripts()[c_i].getModules().size()-1]) << "\t" << getJobScripts()[c_i].getJobName() << std::endl;
    script_cmd_result = subJobScript(flog_, getJobScripts()[c_i]);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
}


} // namespace hpcswtest

