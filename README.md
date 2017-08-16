# HPC Software Stack Testing Framework

The HPC Software stack testing framework (hpcswtest) is used in the INL Scientific Computing Department to test the basic sanity and integrity of the HPC Software stack (Compilers, MPI, Numerical libraries and Applications) and to quickly discover hard failures. As a by-product it will indirectly check the HPC infrastructure (network, PBS and licensing servers). Hpcswtest is primarily written in c++11, with some supporting scripts written in python2. A json file defines all the tests to be run (i.e typically each line contains the module name and version), PBS scripts for the tests are generated and submitted to the PBS pro scheduling system. When the tests have complete a python script (i.e hpcswtest_report.py) is provided to check the results and generate a report.
An example json file is provided (hpcswtest.json_def).


Tests Supported
---------------
MPI libraries, Compilers, BLAS libraries, Boost, VASP, gaussian, abaqus, starccm+, matlab, ansys, lsdyna, cth, helios, mcnp, mcnpx, serpent, scale, mc21, python2, python3


Building Dependencies
---------------------
Software was built with GCC 4.9.3 compilers and Boost c++ libraries version 1.60.


Building Procedure
------------------
Modify Makefile as appropriate, and type

make


Testing Procedure
----------------
Create a directory, execute hpcswtest executable inside created directory. Set the environmental variable, HPCSWTEST_QUEUE to the queue you want to use.
If file "hpcswtest.json" is not contained in your current working directory then the default json file (i.e hpcswtest.json_def) will 
be used to execute tests.

When all tests have completed, run hpcswtest_report.py inside your current working directory to create a report showing what tests passed/failed.



This project is supported by [Idaho National Laboratory](https://www.inl.gov/).



### Other Software


[Idaho National Laboratory](https://www.inl.gov/) is a cutting edge research facility which is a constantly producing high quality research and software. Feel free to take a look at our other software and scientific offerings at:



[Primary Technology Offerings Page](https://www.inl.gov/inl-initiatives/technology-deployment)



[Supported Open Source Software](https://github.com/idaholab)



[Raw Experiment Open Source Software](https://github.com/IdahoLabResearch)



[Unsupported Open Source Software](https://github.com/IdahoLabCuttingBoard)



### License



Copyright 2016 Battelle Energy Alliance, LLC



Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.

You may obtain a copy of the License at



  http://www.apache.org/licenses/LICENSE-2.0



Unless required by applicable law or agreed to in writing, software

distributed under the License is distributed on an "AS IS" BASIS,

WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.

See the License for the specific language governing permissions and

limitations under the License.
