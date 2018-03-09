# HPC Software Stack Testing Framework

The HPC Software stack testing framework (hpcswtest) is used in the INL Scientific Computing Department to test the basic sanity and integrity of the HPC Software stack (Compilers, MPI, Numerical libraries and Applications) and to quickly discover hard failures. As a by-product it will indirectly check the HPC infrastructure (network, PBS and licensing servers). Hpcswtest is primarily written in c++11, with some supporting scripts written in python2. A json file defines all the tests to be run (i.e typically each line contains the module name and version), Job scheduler scripts for the tests are generated and submitted to the scheduling system (PBS pro and SLURM are supported). When the tests have complete a python script (i.e hpcswtest_report.py) is provided to check the results and generate a report.
An example json file is provided (hpcswtest.json_def).


Tests Supported
---------------
MPI libraries, Compilers, BLAS libraries, Boost, VASP, gaussian, abaqus, starccm+, matlab, ansys, lsdyna, cth, helios, mcnp, mcnpx, serpent, scale, mc21, lammps, nwchem, python2, python3


Building Dependencies
---------------------
Software was built with GCC 4.9.3 compilers and boost c++ libraries version 1.60. Python 2.7.12+ required.


Building Procedure
------------------
Modify Makefile as appropriate, and type

make

To build SLURM version, modify Makefile, add -DSLURM to CPPFLAGS, then make.


Environmental variables
-----------------------
HPCSWTEST_QUEUE - Define job scheduling queue to use.

HPCSWTEST_BASE_DIR - Directory location of default json file defining the tests to run (hpcswtest.json_def) (If hpcswtest.json is
contained in your current working directory then this environmental variable will be ignored and hpcswtest.json will be used to define what tests to run.)


Testing Procedure
----------------
Create a directory, execute hpcswtest executable inside created directory. Modify the "system_configuration" section in the default json file. Set the environmental variable, HPCSWTEST_BASE_DIR to location of hpcswtest.json_def file and HPCSWTEST_QUEUE to the queue you want to use.
If file "hpcswtest.json" is not contained in your current working directory then the default json file (i.e hpcswtest.json_def) will be used to execute tests.

When all tests have completed, run hpcswtest_report.py inside your current working directory to create a report showing what tests passed/failed.


Template variables
------------------
There are a couple of template variables defined in the input json file (hpcswtest.json_def) and report script (hpcswtest_report.py) for your convenience.

INPUT_NAME - Will substitute the appropriate input file name generated internally for the testing framework (json file).
JOB_NAME - Will subsitute the appropriate scheduler job name generated internally by the testing framework (json file).
pbs_stdout - Will substitute the appropriate scheduler stdout file name generated internally by the testing framework (hpcswtest_report.py).
pbs_stderr - Will substitute the appropriate scheduler stderr file name generated internally by the testing framework (hpcswtest_report.py).


Json Input file (hpcswtest.json_def) file format
------------------------------------------------
At the top of the json file contains a section called "system configuration", modify it for your environment, identifying 
what clusters to test, the names of login-nodes for each cluster and if using PBS pro as your scheduler, the chunk-size for
your processors. The other sections of the json file correspond to the clusters you will testing.
Most application tests can use the provided automated submission scripts to generate the scheduler job syntax or have the testing framework generate the scheduler syntax directly for you. If "run_script" is defined then the defined run_script will be used to generate the job scheduler script syntax, otherwise the framework will generate the job run scripts directly, using the "mpi_cmd_name", "mpi_cmd_args", "exe_name" and "exe_args" definitions.


Testing verification and checks
-------------------------------
The script hpcswtest_report.py is used to check the test results and generate a report. The following types of checks can be defined in hpcswtest_report.py (Check for regular expression pattern(s) in file(s), check if file exists and check the file size of file(s)). These checks can be defined in the check_file_patterns python dictionary defined at the top of the hpcswtst_report.py file. (See the section Template variables for information on template variables such as pbs_stdout).


Troubleshooting
---------------
If you get test failures you can check the *.log files to see what went wrong. There is a single log file for each application.
To re-run a failued test, create a json file (hpcswtest.json) in your current working directory containing the tests you want to run. (Note if hpcswtest.json exists in your testing directory the default hpcswtest json file (hpcswtest.json_def) is not used.)


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
