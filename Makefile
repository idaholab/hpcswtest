#
#Copyright 2017 Battelle Energy Alliance, LLC
#
#Licensed under the Apache License, Version 2.0 (the "License");
#you may not use this file except in compliance with the License.
#You may obtain a copy of the License at
#
#http://www.apache.org/licenses/LICENSE-2.0
#
#Unless required by applicable law or agreed to in writing, software
#distributed under the License is distributed on an "AS IS" BASIS,
#WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#See the License for the specific language governing permissions and
#limitations under the License.

CPP = g++
# PBS is enabled by default, to enable SLURM instead of PBS, add -DSLURM to CPPFLAGS.
CPPFLAGS = -O2 -std=c++11 -static
JOBSCRIPT_OBJS = jobscript.o pbsscript.o slurmscript.o
OBJECTS = main.o hpcswtest.o srctest.o compilertest.o mpitest.o libtest.o blastest.o boosttest.o apptest.o mcnptest.o mcnpxtest.o scaletest.o scale62test.o heliostest.o mc21test.o vasptest.o lammpstest.o nwchemtest.o abaqustest.o starccmtest.o gaussiantest.o matlabtest.o serpenttest.o cthtest.o python2test.o python3test.o helper.o generator.o $(MODULES_OBJS) $(JOBSCRIPT_OBJS)
BOOST_LIBS = -lboost_filesystem -lboost_system
EXECUTABLE = hpcswtest

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJECTS) $(BOOST_LIBS)

clean:
	rm *.o $(EXECUTABLE)

%.o: %.cc
	$(CPP) $(CPPFLAGS) -c -o $@ $<
