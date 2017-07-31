#!/usr/bin/env python
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
#

"""Read HPC Software test suite output results files, determine
   if results are correct or not and print QA report.

   Initial Version Created on Dec 24, 2015 (by C.Garvey). """


import sys
import os
import re
import socket
import shutil

c_results = []
c_run_results = []
c_modules = []
c_compilers = []
c_pbs_job_name = []
c_pbs_job_id = []
mpi_results = []
mpi_run_results = []
mpi_modules = []
mpi_compilers = []
mpi_pbs_job_id = []
mpi_pbs_job_name = []
pbs_results = []
pbs_string = []
pbs_pbs_job_id = []
pbs_run_results = []
pbs_run_string = []
blas_modules = []
blas_c_modules = []
blas_compilers = []
#library = []
blas_results = []
blas_pbs_job_id = []
blas_pbs_job_name = []
blas_run_results = []
mcnp_pbs_job_id = []
mcnp_modules = []
mcnp_run_results = []
mcnp_pbs_job_name = []
mcnpx_pbs_job_id = []
mcnpx_modules = []
mcnpx_run_results = []
mcnpx_pbs_job_name = []
vasp_pbs_job_id = []
vasp_pbs_job_name = []
vasp_modules = []
vasp_run_results = []
vasp_run_dir = []
gaussian_pbs_job_id = []
gaussian_pbs_job_name = []
gaussian_modules = []
gaussian_run_results = []
starccm_modules = []
starccm_run_results = []
starccm_pbs_job_id = []
starccm_pbs_job_name = []
abaqus_modules = []
abaqus_run_results = []
abaqus_pbs_job_id = []
abaqus_pbs_job_name = []
matlab_modules = []
matlab_run_results = []
matlab_pbs_job_id = []
matlab_pbs_job_name = []
misc_results = []
misc_run_results = []
misc_string = []
misc_run_string = []
misc_job_id = []
python2_modules = []
python2_tests = []
python2_results = []
python3_modules = []
python3_tests = []
python3_results = []
boost_modules = []
boost_cxx_compilers = []
#boost_library = []
boost_run_results = []
boost_compile_results = []
boost_pbs_job_id = []
boost_pbs_job_name = []
helios_pbs_job_id = []
helios_pbs_job_name = []
helios_modules = []
helios_run_results = []
helios_run_dir = []
helioslint64_pbs_job_id = []
helioslint64_pbs_job_name = []
helioslint64_modules = []
helioslint64_run_results = []
helioslint64_run_dir = []
scale_pbs_job_id = []
scale_pbs_job_name = []
scale_modules = []
scale_run_results = []
scale62_pbs_job_id = []
scale62_pbs_job_name = []
scale62_modules = []
scale62_run_results = []
lsdyna_modules = []
lsdyna_pbs_job_id = []
lsdyna_run_results = []
ansys_modules = []
ansys_pbs_job_id = []
ansys_run_results = []
serpent_pbs_job_id = []
serpent_pbs_job_name = []
serpent_modules = []
serpent_run_results = []
cth_pbs_job_id = []
cth_pbs_job_name = []
cth_modules = []
cth_run_results = []
cth_run_dir = []
mc21_pbs_job_id = []
mc21_pbs_job_name = []
mc21_modules = []
mc21_run_results = []
mc21_run_dir = []

shmmax_job_id = 0
global_hostname = ""
run_date = ""

hostname = socket.gethostname()

if hostname == "falcon1" or hostname == "falcon2" or hostname == "falconpbs":
   clustername = "falcon"
elif  hostname == "flogin1" or hostname == "flogin2" or hostname == "fpbs":
   clustername = "fission"
else:
   clustername = hostname


def collect_misc_results(f,misc_string,results):
    global shmmax_job_id
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("passed$|failed$|check$|^none$",line.strip())
        if s is not None:
#           if (s.group() != "none"):
           results.append(s.group())
#           misc_string.append(re.sub(s.group(),'',line.strip()))
           misc_string.append("ibv_devinfo")
           line2 = f.next().strip()
#           print "line2=",line2
#           if (line2 != "none"):
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              misc_job_id.append(s2.group())
              shmmax_job_id = s2.group()
           else:
              misc_job_id.append("not_run")
              shmmax_job_id = "not_run"
#    print "shmmax_job_id =",shmmax_job_id
#    print results
#    print misc_string
#    print misc_job_id


def collect_pbs_qa_results(f,pbs_string,results):
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("passed$|failed$|check$",line.strip())
        if s is not None:
           results.append(s.group())
           pbs_string.append(data[0] + " " + data[1] + " " + data[2] + " " + data[3] + \
                                       " " + data[4] + " " + data[5] + " " + data[6])
#        print results
#        print pbs_string
           line2 = f.next()
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              pbs_pbs_job_id.append(s2.group())
           else:
              pbs_pbs_job_id.append("not_run")


def collect_compiler_qa_results(f, modules, compilers, pbs_job_name, results):
    global run_date
    global global_hostname
    run_date = f.readline()
#    print "run_date = ",run_date
    f.readline()
    host_line = re.split("\s*",f.readline())
    global_hostname = host_line[4]
#    print "global_hostname = ",global_hostname
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("passed$|failed$|check$",line.strip())
        if s is not None:
           results.append(s.group())
           modules.append(data[0])
           compilers.append(data[1])
           pbs_job_name.append(data[2])
#           print "next line1=",f.next()
           line2 = f.next()
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              c_pbs_job_id.append(s2.group())
           else:
              c_pbs_job_id.append("not_run")


def collect_blas_qa_results(f,blas_modules,compilers,pbs_job_name,results):
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
#        data = re.split(":",line.strip())
        s = re.search("passed$|failed$|check$",line.strip())
        if s is not None:
           results.append(s.group())
           blas_modules.append(data[0])
           compilers.append(data[1])
           pbs_job_name.append(data[2])
#           print "next line1=",f.next()
           line2 = f.next()
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              blas_pbs_job_id.append(s2.group())
           else:
              blas_pbs_job_id.append("not_run")


def collect_boost_qa_results(f,modules,compiler,pbs_job_name,results):
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
#        data = re.split(":",line.strip())
        s = re.search("passed$|failed$|check$",line.strip())
        if s is not None:
           results.append(s.group())
           modules.append(data[0])
           compiler.append(data[1])
           pbs_job_name.append(data[2])
#           print "next line1=",f.next()
           line2 = f.next()
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              boost_pbs_job_id.append(s2.group())
           else:
              boost_pbs_job_id.append("not_run")


def collect_python2_qa_results(f, modules,tests,results):
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("passed$|failed$|check$",line.strip())
        if s is not None:
           results.append(s.group())
           modules.append(data[0])
           tests.append(data[1])
#
#        print results
#        print modules
#        print tests


def collect_python3_qa_results(f, modules,tests,results):
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("passed$|failed$|check$",line.strip())
        if s is not None:
           results.append(s.group())
           modules.append(data[0])
           tests.append(data[1])
#
#        print results
#        print modules
#        print tests


def collect_mpi_qa_results(f,modules,compilers,pbs_job_name,results):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("passed$|failed$|check$",line.strip())
        if s is not None:
           results.append(s.group())
           modules.append(data[0])
           compilers.append(data[1])
           pbs_job_name.append(data[2])
#           print "next line1=",f.next()
           line2 = f.next()
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              mpi_pbs_job_id.append(s2.group())
           else:
              mpi_pbs_job_id.append("not_run")


def collect_helios_qa_results(f,modules,run_dir,pbs_job_name):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("job.$",line.strip())
        if s is not None:
           modules.append(data[0])
           run_dir.append(data[1])
           pbs_job_name.append(data[2])
#           print "next line1=",f.next()
           line2 = f.next()
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              helios_pbs_job_id.append(s2.group())
           else:
              helios_pbs_job_id.append("not_run")


def collect_helioslint64_qa_results(f,modules,run_dir,pbs_job_name):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("job.$",line.strip())
        if s is not None:
           modules.append(data[0])
           run_dir.append(data[1])
           pbs_job_name.append(data[2])
#           print "next line1=",f.next()
           line2 = f.next()
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              helioslint64_pbs_job_id.append(s2.group())
           else:
              helioslint64_pbs_job_id.append("not_run")


def collect_scale_qa_results(f,modules,run_dir):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("job.$",line.strip())
        if s is not None:
           modules.append(data[0])
           run_dir.append(data[1])
#           print "next line1=",f.next()
           line2 = f.next()
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              scale_pbs_job_id.append(s2.group())
           else:
              scale_pbs_job_id.append("not_run")


def collect_scale62_qa_results(f,modules,run_dir):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("job.$",line.strip())
        if s is not None:
           modules.append(data[0])
           run_dir.append(data[1])
#           print "next line1=",f.next()
           line2 = f.next()
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              scale62_pbs_job_id.append(s2.group())
           else:
              scale62_pbs_job_id.append("not_run")


def collect_serpent_qa_results(f,modules,run_dir):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("job.$",line.strip())
        if s is not None:
           modules.append(data[0])
           run_dir.append(data[1])
#           print "next line1=",f.next()
           line2 = f.next()
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              serpent_pbs_job_id.append(s2.group())
           else:
              serpent_pbs_job_id.append("not_run")


def collect_cth_qa_results(f, modules, run_dir, pbs_job_name):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("job.$",line.strip())
        if s is not None:
           modules.append(data[0])
           run_dir.append(data[1])
           pbs_job_name.append(data[2])
#           print "next line1=",f.next()
           line2 = f.next()
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              cth_pbs_job_id.append(s2.group())
           else:
              cth_pbs_job_id.append("not_run")


def collect_mc21_qa_results(f, modules, run_dir, pbs_job_name):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("job.$",line.strip())
        if s is not None:
           modules.append(data[0])
           run_dir.append(data[1])
           pbs_job_name.append(data[2])
#           print "next line1=",f.next()
           line2 = f.next()
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              mc21_pbs_job_id.append(s2.group())
           else:
              mc21_pbs_job_id.append("not_run")


def collect_mcnp_qa_results(f,modules,jobs):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("job.$",line.strip())
        if s is not None:
           modules.append(data[0])
           jobs.append(data[1])
#           print "next line1=",f.next()
           line2 = f.next()
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              mcnp_pbs_job_id.append(s2.group())
           else:
              mcnp_pbs_job_id.append("not_run")


def collect_mcnpx_qa_results(f,modules,jobs):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("job.$",line.strip())
        if s is not None:
           modules.append(data[0])
           jobs.append(data[1])
#           print "next line1=",f.next()
           line2 = f.next()
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              mcnpx_pbs_job_id.append(s2.group())
           else:
              mcnpx_pbs_job_id.append("not_run")


def collect_vasp_qa_results(f,modules,run_dir,pbs_job_name):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("job.$",line.strip())
        if s is not None:
           modules.append(data[0])
           run_dir.append(data[1])
           pbs_job_name.append(data[2])
#           print "next line1=",f.next()
           line2 = f.next()
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              vasp_pbs_job_id.append(s2.group())
           else:
              vasp_pbs_job_id.append("not_run")


def collect_lsdyna_qa_results(f,modules,run_dir):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("job.$",line.strip())
        if s is not None:
           modules.append(data[0])
           run_dir.append(data[1])
#           print "next line1=",f.next()
           line2 = f.next()
#           print line2
           s2 = re.search('\d+',line2.strip())
           if s2 is not None:
              lsdyna_pbs_job_id.append(s2.group())
           else:
              lsdyna_pbs_job_id.append("not_run")


def collect_starccm_qa_results(f,modules,pbs_job_name):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("job.$",line.strip())
        if s is not None:
           modules.append(data[0])
           pbs_job_name.append(data[1])
#           print "next line1=",f.next()
           line = f.next()
           s2 = re.search('\d+',line.strip())
           if s2 is not None:
              starccm_pbs_job_id.append(s2.group())
           else:
              starccm_pbs_job_id.append("not_run")


def collect_matlab_qa_results(f,modules,pbs_job_name):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("job.$",line.strip())
        if s is not None:
           modules.append(data[0])
           pbs_job_name.append(data[1])
#           print "next line1=",f.next()
           line = f.next()
           s2 = re.search('\d+',line.strip())
           if s2 is not None:
              matlab_pbs_job_id.append(s2.group())
           else:
              matlab_pbs_job_id.append("not_run")


def collect_abaqus_qa_results(f,modules,pbs_job_name):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("job.$",line.strip())
        if s is not None:
           modules.append(data[0])
           pbs_job_name.append(data[1])
#           print "next line1=",f.next()
           line = f.next()
           s2 = re.search('\d+',line.strip())
           if s2 is not None:
              abaqus_pbs_job_id.append(s2.group())
           else:
              abaqus_pbs_job_id.append("not_run")


def collect_gaussian_qa_results(f,modules,pbs_job_name):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("job.$",line.strip())
        if s is not None:
           modules.append(data[0])
           pbs_job_name.append(data[1])
#           print "next line1=",f.next()
           line = f.next()
           s2 = re.search('\d+',line.strip())
           if s2 is not None:
              gaussian_pbs_job_id.append(s2.group())
           else:
              gaussian_pbs_job_id.append("not_run")


def collect_ansys_qa_results(f,modules):
   
    for line in f:
#        print line,
        data = re.split("\s*",line.strip())
        s = re.search("job.$",line.strip())
        if s is not None:
           modules.append(data[0])
#           print "next line1=",f.next()
           line = f.next()
           s2 = re.search('\d+',line.strip())
           if s2 is not None:
              ansys_pbs_job_id.append(s2.group())
           else:
              ansys_pbs_job_id.append("not_run")


def check_misc_results():
#    print "shmmax_job_id=",shmmax_job_id
     s = re.search('\d+',shmmax_job_id.strip())
     if s is not None:
        shmmax_file = "shmmax.o" + shmmax_job_id
#    print "shmmax_file =",shmmax_file
        if os.path.isfile(shmmax_file):
#       print "files are :",shmmax_file
           hostname = "failed"
           ref_shmmax = 999999
           shmmax = 99
           f = open(shmmax_file,"r")
           for line in f:
               s = re.search('shmmax',line.strip())
               if s is not None:
                  data = re.split("\s*",line.strip())
                  hostname = data[0]
                  shmmax = data[3]
                  break
#              print data
           if re.search('fission',hostname): 
              ref_shmmax = 62000000
           elif re.search('quark',hostname):
              ref_shmmax = 20000000
           elif re.search('rocky',hostname):
              ref_shmmax = 300000000
           elif re.search('fbuild',hostname):
              ref_shmmax = 62000000
           elif re.search('qbuild',hostname):
              ref_shmmax = 126000000
           elif re.search('r[0-9]i[0-9]n[0-9]',hostname):
              ref_shmmax = 14000000
#       print "ref_shmmax=",ref_shmmax," shmmax=",shmmax
           misc_run_string.append("shmmax")
           if (int(shmmax) > ref_shmmax):
#          print "passed"
              misc_run_results.append("passed")
           else:
#              print "failed"
              misc_run_results.append("failed")
        else:
            misc_run_results.append("running")
     else: 
         misc_run_results.append("failed")
#       print misc_run_string
#       print misc_run_results
  

def check_blas_run_results():
    for line,line2 in zip(blas_pbs_job_id,blas_pbs_job_name):
#        print line
        s = re.search('\d+',line.strip())
        if s is not None:
           blas_file = line2 + ".o" + s.group()
#           print blas_file
           if os.path.isfile(blas_file):
#              print "files are :",blas_file
              f = open(blas_file,"r")
              c_value = ""
              for line in f:
                  s = re.search('SUM C',line.strip())
                  if s is not None:
#                     print line,
                     data = re.split("\s*",line.strip())
                     c_value = data[3]
#                     print "c_value = ",c_value
              if c_value == "45":
                 c_value_result = "passed"
              else:
                 c_value_result = "failed" 
              blas_error_file = ""
              blas_file_e = re.sub('.o','.e',blas_file)
              if os.path.isfile(blas_file_e):
                 if os.path.getsize(blas_file_e) > 0:
                    blas_error_file = "check"
              else:
                  blas_error_file = "failed"
#              print "c_value_result =",c_value_result
              if c_value_result == "passed":
                 if blas_error_file == "check": 
                    blas_run_results.append("check")
                 else:
                    blas_run_results.append("passed")
              else:
                 blas_run_results.append("failed")
           else:
#              print "Error: File %s does not exist\n" % lib_file
              blas_run_results.append("running")

        else: 
           blas_run_results.append("failed")


def check_boost_run_results():
    for line,line2 in zip(boost_pbs_job_id,boost_pbs_job_name):
#        print line
        s = re.search('\d+',line.strip())
        if s is not None:
           boost_file = line2 + ".o" + s.group()
#           print lib_file
           if os.path.isfile(boost_file):
#              print "files are :",boost_file
              f = open(boost_file,"r")
              out_file_result = ""
              for line in f:
                  s = re.search('Working',line.strip())
                  if s is not None:
#                     print line,
                     out_file_result = "passed"
              boost_error_file = ""
              boost_file_e = re.sub('.o','.e',boost_file)
#             print "boost_file_e=",boost_file_e
              if os.path.isfile(boost_file_e):
                 if os.path.getsize(boost_file_e) > 0:
                    boost_error_file = "check"
              else:
                  boost_error_file = "failed"
#              print "c_value_result =",c_value_result
              if out_file_result == "passed":
                 if boost_error_file == "check": 
                    boost_run_results.append("check")
                 else:
                    boost_run_results.append("passed")
              else:
                 boost_run_results.append("failed")
           else:
#              print "Error: File %s does not exist\n" % lib_file
              boost_run_results.append("running")

        else: 
           boost_run_results.append("failed")


def check_compiler_run_results():
    for line,line2,line3 in zip(c_pbs_job_id,c_compilers,c_pbs_job_name):
        cnt = 0
#        print line,line2,line3
        s = re.search('\d+',line.strip())
        if s is not None:
           compiler_file = line3 + ".o" + s.group()
#           print compiler_file
           if os.path.isfile(compiler_file):
#              print "files are :",compiler_file
              f = open(compiler_file,"r")
              c_run_result = "failed"
              for line in f:
                  s = re.search('code is working',line.strip())
                  if s is not None:
                     c_run_result = "passed"
                     compiler_error_file = ""
                     compiler_file_e = re.sub('\.o','.e',compiler_file)
                     if os.path.isfile(compiler_file_e):
                        if os.path.getsize(compiler_file_e) > 0:
                           c_run_result = "check"
                     else:
                       c_run_result = "check"
                     break
              c_run_results.append(c_run_result) 
           else:
#              print "Error: File %s does not exist\n" % mpi_file
              c_run_results.append("running")
        else: 
           c_run_results.append("failed")


def check_mpi_run_results():
    cnt2 = []
    num_mpi_procs = 2
    for line,line2,line3 in zip(mpi_pbs_job_id,mpi_compilers,mpi_pbs_job_name):
        cnt = 0
#        print line,line2
        s = re.search('\d+',line.strip())
        if s is not None:
           if (line2 == "mpicc") or (line2 == "mpiicc"):
              mpi_file = line3 + ".o" + s.group()
           elif (line2 == "mpif90") or (line2 == "mpif77") or (line2 == "mpiifort"):
              mpi_file = line3 + ".o" + s.group()
           elif (line2 == "mpicxx") or (line2 == "mpiicpc"):
              mpi_file = line3 + ".o" + s.group()
           else:
              print "Error: Do not recognize mpi wrapper",line2
#           print mpi_file
           if os.path.isfile(mpi_file):
#              print "files are :",mpi_file
              f = open(mpi_file,"r")
              for line in f:
#                  s = re.search('Hello',line.strip())
                  s = re.findall('Hello',line.strip())
#                  print "s=%s len=%d" % (s,len(s))
                  if s is not None:
#                     cnt = cnt + 1
                      cnt = cnt + len(s)
#                     print line,
#              print "2 cnt =",cnt,mpi_file
              if cnt == num_mpi_procs:
                 mpi_error_file = ""
                 mpi_file_e = re.sub('.o','.e',mpi_file)
#                 print "mpi_file_e=",mpi_file_e
                 if os.path.isfile(mpi_file_e):
                    if os.path.getsize(mpi_file_e) > 0:
                       mpi_error_file = "check"
#                    f2 = open(mpi_file_e,"r")
#                    for line in f2:
#                       s = re.search('WARNING|warning|Warning',line.strip())
#                       if s is not None:
#                          print "pbs error file check",mpi_file_e
#                          mpi_error_file = "check"
                 else:
                    mpi_error_file = "check"
                 if mpi_error_file == "check": 
                    mpi_run_results.append("check")
                 else:
                    mpi_run_results.append("passed")
              elif cnt == 0:
                 mpi_run_results.append("failed")
              elif cnt < num_mpi_procs:
                 mpi_run_results.append("check")
#                 print "cnt=",cnt 
           else:
#              print "Error: File %s does not exist\n" % mpi_file
              mpi_run_results.append("running")

        else: 
           mpi_run_results.append("failed")


def check_mcnp_run_results():
#    print mcnp_pbs_job_id,mcnp_jobs
    for line,line2 in zip(mcnp_pbs_job_id,mcnp_pbs_job_name):
#        print line,line2
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = line2 + ".o" + s.group() 
           o_file = line2 + ".o"
           r_file = line2 + ".r"
           s_file = line2 + ".s"
#           print pbs_file
           if os.path.isfile(pbs_file):
              mcnp_result_file = ""
              o_file_exists = ""
              r_file_exists = ""
              s_file_exists = ""
#              print "files exists :",pbs_file
              f = open(pbs_file,"r")
              for line in f:
                  data = re.split("\s*",line.strip())
                  s2 = re.search("^mcrun  is done$",line.strip())
                  if s2 is not None:
                     mcnp_result_file = "passed"
#                     print "MCNP5 job  passed"
              if os.path.isfile(o_file):
                 o_file_exists = "passed"
              if os.path.isfile(r_file):
                 r_file_exists = "passed"
              if os.path.isfile(s_file):
                 s_file_exists = "passed"
#              print "o_file_exists=",o_file_exists," r_file_exists=",r_file_exists," s_file_exists=",s_file_exists
              if (mcnp_result_file == "passed") and (o_file_exists == "passed") and \
                 (r_file_exists == "passed") and (s_file_exists == "passed"):
                 mcnp_run_results.append("passed")
              else:
                 mcnp_run_results.append("failed")

           else:
#              print "Error: File %s does not exist\n" % pbs_file
              mcnp_run_results.append("running")
        else:
            mcnp_run_results.append("failed")


def check_mcnpx_run_results():
#    print mcnpx_pbs_job_id,mcnpx_jobs
    for line,line2 in zip(mcnpx_pbs_job_id,mcnpx_pbs_job_name):
#        print line,line2
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = line2 + ".o" + s.group() 
           o_file = line2 + ".o"
           r_file = line2 + ".r"
           m_file = line2 + ".m"
#           print pbs_file
           if os.path.isfile(pbs_file):
              mcnpx_result_file = ""
              o_file_exists = ""
              r_file_exists = ""
              m_file_exists = ""
#              print "files exists :",pbs_file
              f = open(pbs_file,"r")
              for line in f:
                  data = re.split("\s*",line.strip())
                  s2 = re.search("^mcrun  is done$",line.strip())
                  if s2 is not None:
                     mcnpx_result_file = "passed"
#                     print "MCNP5 job  passed"
              if os.path.isfile(o_file):
                 o_file_exists = "passed"
              if os.path.isfile(r_file):
                 r_file_exists = "passed"
              if os.path.isfile(m_file):
                 m_file_exists = "passed"
#              print "o_file_exists=",o_file_exists," r_file_exists=",r_file_exists," m_file_exists=",m_file_exists
              if (mcnpx_result_file == "passed") and (o_file_exists == "passed") and \
                 (r_file_exists == "passed") and (m_file_exists == "passed"):
                 mcnpx_run_results.append("passed")
              else:
                 mcnpx_run_results.append("failed")

           else:
#              print "Error: File %s does not exist\n" % pbs_file
              mcnpx_run_results.append("running")
        else:
            mcnpx_run_results.append("failed")


def check_starccm_run_results():
#    print starccm_pbs_job_id
    for line,line2 in zip(starccm_pbs_job_id,starccm_pbs_job_name):
#        print line
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = line2 + ".o" + s.group() 
#           print pbs_file
           if os.path.isfile(pbs_file):
              starccm_string1 = ""
              starccm_string2 = ""
              starccm_string3 = ""
#              print "files exists :",pbs_file
              f = open(pbs_file,"r")
              for line in f:
                  data = re.split("\s*",line.strip())
                  s2 = re.search("^Configuring finished$",line.strip())
                  if s2 is not None:
                     starccm_string1 = "passed"
                  s3 = re.search("^Saving:",line.strip())
                  if s3 is not None:
                     starccm_string2 = "passed"
                  s2 = re.search("^Partitioning finished$",line.strip())
                  if s2 is not None:
                     starccm_string3 = "passed"
              if (starccm_string1 == "passed" or starccm_string3 == "passed") and (starccm_string2 == "passed"):
                  starccm_run_results.append("passed")
              else:
                  starccm_run_results.append("failed")

           else:
#              print "Error: File %s does not exist, job runnings\n" % pbs_file
              starccm_run_results.append("running")
        else:
            starccm_run_results.append("failed")


def check_matlab_run_results():
#    print matlab_pbs_job_id
    for line,line2 in zip(matlab_pbs_job_id,matlab_pbs_job_name):
#        print line
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = line2 + ".o" + s.group() 
#           print pbs_file
           if os.path.isfile(pbs_file):
              matlab_string1 = ""
              matlab_string2 = ""
#              print "files exists :",pbs_file
              f = open(pbs_file,"r")
              for line in f:
                  data = re.split("\s*",line.strip())
                  s2 = re.search("^e =$",line.strip())
                  if s2 is not None:
                     matlab_string1 = "passed"
                  s3 = re.search("^991$",line.strip())
                  if s3 is not None:
                     matlab_string2 = "passed"
              if (matlab_string1 == "passed") and (matlab_string2 == "passed"):
                  matlab_run_results.append("passed")
              else:
                  matlab_run_results.append("failed")

           else:
#              print "Error: File %s does not exist, job runnings\n" % pbs_file
              matlab_run_results.append("running")
        else:
            matlab_run_results.append("failed")


def check_abaqus_run_results():
    for line,line2 in zip(abaqus_pbs_job_id,abaqus_pbs_job_name):
#        print line
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = line2 + ".o" + s.group() 
#           print pbs_file
           if os.path.isfile(pbs_file):
              abaqus_string1 = ""
              abaqus_string2 = ""
              abaqus_string3 = ""
#              print "files exists :",pbs_file
              f = open(pbs_file,"r")
              for line in f:
                  data = re.split("\s*",line.strip())
                  s2 = re.search("^Begin Abaqus/Standard Analysis$",line.strip())
                  if s2 is not None:
                     abaqus_string1 = "passed"
                  s3 = re.search("^End Abaqus/Standard Analysis$",line.strip())
                  if s3 is not None:
                     abaqus_string2 = "passed"
                  s2 = re.search("COMPLETED",line.strip())
                  if s2 is not None:
                     abaqus_string3 = "passed"
              if (abaqus_string1 == "passed") and (abaqus_string3 == "passed") and (abaqus_string2 == "passed"):
                  abaqus_run_results.append("passed")
              else:
                  abaqus_run_results.append("failed")

           else:
#              print "Error: File %s does not exist, job runnings\n" % pbs_file
              abaqus_run_results.append("running")
        else:
            abaqus_run_results.append("failed")


def check_gaussian_run_results():
    for line,line2 in zip(gaussian_pbs_job_id,gaussian_pbs_job_name):
#        print line
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = line2
#           print pbs_file
           if os.path.isfile(pbs_file):
              gaussian_string1 = ""
#              print "files exists :",pbs_file
              f = open(pbs_file,"r")
              for line in f:
                  data = re.split("\s*",line.strip())
                  s2 = re.search("^Normal termination of Gaussian",line.strip())
                  if s2 is not None:
                     gaussian_string1 = "passed"
              if (gaussian_string1 == "passed"):
                  gaussian_run_results.append("passed")
              else:
                  gaussian_run_results.append("failed")

           else:
#              print "Error: File %s does not exist, job runnings\n" % pbs_file
              gaussian_run_results.append("running")
        else:
            gaussian_run_results.append("failed")


def check_ansys_run_results():
#    print ansys_pbs_job_id
    for line in ansys_pbs_job_id:
#        print line
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = "ansys_qa" + ".o" + s.group() 
#           print pbs_file
           if os.path.isfile(pbs_file):
              ansys_string1 = ""
#              print "files exists :",pbs_file
              f = open(pbs_file,"r")
              for line in f:
                  data = re.split("\s*",line.strip())
                  s2 = re.search("solution is converged$",line.strip())
                  if s2 is not None:
                     ansys_string1 = "passed"
              if (ansys_string1 == "passed"):
                  ansys_run_results.append("passed")
              else:
                  ansys_run_results.append("failed")
           else:
#              print "Error: File %s does not exist, job runnings\n" % pbs_file
              ansys_run_results.append("running")
        else:
            ansys_run_results.append("failed")


def check_helios_run_results():
#    print helios_pbs_job_id
    for line,line2,line3 in zip(helios_pbs_job_id,helios_run_dir,helios_pbs_job_name):
#        print line,line2,line3
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = line2 + "/" + line3 + ".o" + s.group()
#           print "pbs_file=",pbs_file 
           if os.path.isfile(pbs_file):
              helios_string1 = ""
              f = open(pbs_file,"r")
              for line in f:
                  data = re.split("\s*",line.strip())
                  s2 = re.search("ZENITH Successful Completion",line.strip())
                  if s2 is not None:
                     helios_string1 = "passed"
              if helios_string1 == "passed":
                 helios_run_results.append("passed")
              else:
                 helios_run_results.append("failed")
           else:
#              print "Error: File %s does not exist\n" % pbs_file
              helios_run_results.append("running")
        else:
           helios_run_results.append("failed")


def check_helioslint64_run_results():
#    print helios_pbs_job_id
    for line,line2,line3 in zip(helioslint64_pbs_job_id,helioslint64_run_dir,helioslint64_pbs_job_name):
#        print line,line2,line3
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = line2 + "/" + line3 + ".o" + s.group()
#           print "pbs_file=",pbs_file 
           if os.path.isfile(pbs_file):
              helios_string1 = ""
              f = open(pbs_file,"r")
              for line in f:
                  data = re.split("\s*",line.strip())
                  s2 = re.search("ZENITH Successful Completion",line.strip())
                  if s2 is not None:
                     helios_string1 = "passed"
              if helios_string1 == "passed":
                 helioslint64_run_results.append("passed")
              else:
                 helioslint64_run_results.append("failed")
           else:
#              print "Error: File %s does not exist\n" % pbs_file
              helioslint64_run_results.append("running")
        else:
           helioslint64_run_results.append("failed")


def check_scale_run_results():
#    print scale_pbs_job_id
    for line,line2 in zip(scale_pbs_job_id,scale_pbs_job_name):
#        print line,line2
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = line2 + ".o" + s.group()
           out_file = line2 + ".out"
#           print "pbs_file=",pbs_file," out_file=",out_file 
           if os.path.isfile(out_file):
              scale_string1 = "failed"
              scale_string2 = "passed"
              f = open(out_file,"r")
              for line in f:
                  data = re.split("\s*",line.strip())
                  s2 = re.search("normal termination",line.strip())
                  if s2 is not None:
                     scale_string1 = "passed"
                  if re.search("error",line.strip(), re.IGNORECASE) is not None:
                     scale_string2 = "failed"
              if scale_string1 == "passed" and scale_string2 == "passed":
                 scale_run_results.append("passed")
              else:
                 scale_run_results.append("failed")
           else:
#              print "Error: File %s does not exist\n" % pbs_file
              scale_run_results.append("running")
        else:
           scale_run_results.append("failed")


def check_scale62_run_results():
#    print scale62_pbs_job_id
    for line,line2 in zip(scale62_pbs_job_id,scale62_pbs_job_name):
#        print line,line2
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = line2 + ".o" + s.group()
           out_file = line2 + ".out"
#           print "pbs_file=",pbs_file," out_file=",out_file 
           if os.path.isfile(out_file):
              scale62_string1 = "failed"
              scale62_string2 = "passed"
              f = open(out_file,"r")
              for line in f:
                  data = re.split("\s*",line.strip())
                  s2 = re.search("SCALE is finished",line.strip())
                  if s2 is not None:
                     scale62_string1 = "passed"
                  if re.search("error",line.strip(), re.IGNORECASE) is not None:
                     scale62_string2 = "failed"
              if scale62_string1 == "passed" and scale62_string2 == "passed":
                 scale62_run_results.append("passed")
              else:
                 scale62_run_results.append("failed")
           else:
#              print "Error: File %s does not exist\n" % pbs_file
              scale62_run_results.append("running")
        else:
           scale62_run_results.append("failed")


def check_serpent_run_results():
#    print serpent_pbs_job_id
    for line,line2 in zip(serpent_pbs_job_id, serpent_pbs_job_name):
#        print line,line2
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = line2 + ".o" + s.group()
           out_file = line2 + ".out"
#           print "pbs_file=",pbs_file," out_file=",out_file 
           if os.path.isfile(pbs_file) and os.path.isfile(out_file):
              serpent_string1 = "failed"
              serpent_string2 = "passed"
              f = open(pbs_file,"r")
              for line in f:
                  data = re.split("\s*",line.strip())
                  s2 = re.search("Transport cycle completed",line.strip())
                  if s2 is not None:
                     serpent_string1 = "passed"
                  if re.search("error",line.strip(), re.IGNORECASE) is not None:
                     serpent_string2 = "failed"
#              print "serpent_string1=",serpent_string1, "serpent_string2=",serpent_string2    
              if serpent_string1 == "passed" and serpent_string2 == "passed":
                 serpent_run_results.append("passed")
              else:
                 serpent_run_results.append("failed")
           else:
#              print "Error: File %s does not exist\n" % pbs_file
              serpent_run_results.append("running")
        else:
           serpent_run_results.append("failed")


def check_cth_run_results():
#    print cth_pbs_job_id
    for line, line2, line3 in zip(cth_pbs_job_id, cth_run_dir, cth_pbs_job_name):
#        print line,line2,line3
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = line2 + "/" + line3 + ".o" + s.group()
           out_file = line2 + "/" + "octh"
#           print "pbs_file=",pbs_file," out_file=",out_file
           if os.path.isfile(pbs_file) and os.path.isfile(out_file):
              cth_string1 = "failed"
              cth_string2 = "passed"
              f = open(pbs_file,"r")
              for line in f:
                  data = re.split("\s*",line.strip())
                  s2 = re.search("CALCULATION TERMINATED BECAUSE STOP TIME ACHIEVED",line.strip())
                  if s2 is not None:
                     cth_string1 = "passed"
                  if re.search("error",line.strip(), re.IGNORECASE) is not None:
#                     print line
                     cth_string2 = "failed"
#              print "cth_string1=",cth_string1, "cth_string2=",cth_string2    
              if cth_string1 == "passed" and cth_string2 == "passed":
                 cth_run_results.append("passed")
              else:
                 cth_run_results.append("failed")
           else:
#              print "Error: File %s does not exist\n" % pbs_file
              cth_run_results.append("running")
        else:
           cth_run_results.append("failed")


def check_mc21_run_results():
#    print mc21_pbs_job_id
    for line, line2, line3 in zip(mc21_pbs_job_id, mc21_run_dir, mc21_pbs_job_name):
#        print line,line2,line3
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = line2 + "/" + line3 + ".o" + s.group()
#           out_file = line2 + "/" + ""
#           print "pbs_file=",pbs_file," out_file=",out_file
           if os.path.isfile(pbs_file):
              mc21_string1 = "failed"
              mc21_string2 = "failed"
              f = open(pbs_file,"r")
              for line in f:
                  data = re.split("\s*",line.strip())
                  s2 = re.search("Simulation Completed",line.strip())
                  if s2 is not None:
                     mc21_string1 = "passed"
                  if re.search("Number of errors:\s*0",line.strip()) is not None:
#                     print line
                     mc21_string2 = "passed"
#              print "cth_string1=",cth_string1, "cth_string2=",cth_string2    
              if mc21_string1 == "passed" and mc21_string2 == "passed":
                 mc21_run_results.append("passed")
              else:
                 mc21_run_results.append("failed")
           else:
#              print "Error: File %s does not exist\n" % pbs_file
              mc21_run_results.append("running")
        else:
           mc21_run_results.append("failed")


def check_vasp_run_results():
#    print vasp_pbs_job_id
    for line,line2,line3 in zip(vasp_pbs_job_id,vasp_run_dir,vasp_pbs_job_name):
#        print line,line2,line3
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = line2 + "/" + line3 + ".o" + s.group()
#           print "pbs_file=",pbs_file 
           if os.path.isfile(pbs_file):
              outcar_file = line2 + "/OUTCAR"
#              print "outcar_file=",outcar_file
              if os.path.isfile(outcar_file):
                 vasp_string1 = ""
                 vasp_string2 = ""
#                 print "files exists :",outcar_file
                 f = open(outcar_file,"r")
                 for line in f:
#                   print line
                     data = re.split("\s*",line.strip())
                     s2 = re.search("aborting loop because EDIFF is reached",line.strip())
                     if s2 is not None:
                        vasp_string1 = "passed"
                     s3 = re.search("General timing and accounting informations for this job",line.strip())
                     if s3 is not None:
                        vasp_string2 = "passed"
                 if (vasp_string1 == "passed") and (vasp_string2 == "passed"):
                     vasp_run_results.append("passed")
                 else:
                     vasp_run_results.append("failed")
              else:
                  vasp_run_results.append("failed")
           else:
#              print "Error: File %s does not exist\n" % pbs_file
              vasp_run_results.append("running")
        else:
           vasp_run_results.append("failed")


def check_lsdyna_run_results():
#    print lsdyna_pbs_job_id
    for line,line2 in zip(lsdyna_pbs_job_id,lsdyna_run_dir):
        cnt = 0
#        print line,line2
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = line2 + "/lsdyna_qa" + ".o" + s.group()
#           print "pbs_file=",pbs_file 
           if os.path.isfile(pbs_file):
              d3hsp_file = line2 + "/d3hsp"
#              print "d3hsp_file=",d3hsp_file
              if os.path.isfile(d3hsp_file):
#                 print "files exists :",d3hsp_file
                 f = open(d3hsp_file,"r")
                 for line in f:
#                   print line
                     data = re.split("\s*",line.strip())
                     s2 = re.findall("N o r m a l    t e r m i n a t i o n",line.strip())
                     cnt = cnt + len(s2)
#                 print "cnt = %d" % (cnt)
                 if (cnt == 2):
                     lsdyna_run_results.append("passed")
                 else:
                     lsdyna_run_results.append("failed")
              else:
                  lsdyna_run_results.append("failed")
           else:
#              print "Error: File %s does not exist\n" % pbs_file
              lsdyna_run_results.append("running")
        else:
           lsdyna_run_results.append("failed")


def check_pbs_run_results():
    cnt = 0
    pbs_limits = ""
    data_seg_size = ""
    file_size = ""
    max_locked_memory = ""
    stack_size = ""
    cpu_time = ""
    virtual_memory = ""
    file_locks = ""
    max_memory_size = "" 
    hostname = ""
    ref_mem = ""

    for line in pbs_pbs_job_id:
#        print line
        s = re.search('\d+',line.strip())
        if s is not None:
           pbs_file = "pbs.o" + s.group() 
#           print pbs_file
           if os.path.isfile(pbs_file):
#              print "files exists :",pbs_file
              f = open(pbs_file,"r")
              for line in f:
                  data = re.split("\s*",line.strip())
                  s = re.search("passed$|failed$|check$",line.strip())
                  if s is not None:
                     pbs_limits = "passed" 
                     hostname = data[6]
#                     print "hostname=",hostname
                  s = re.search('data seg size',line.strip())
                  if s is not None:
                     s2 = re.search('unlimited$',line.strip())
                     if s2 is not None:
                        data_seg_size = "passed"
                  s = re.search('file size',line.strip())
                  if s is not None:
                     s2 = re.search('unlimited$',line.strip())
                     if s2 is not None:
                        file_size = "passed"
                  s = re.search('max locked memory',line.strip())
                  if s is not None:
                     s2 = re.search('unlimited$',line.strip())
                     if s2 is not None:
                        max_locked_memory = "passed"
                  s = re.search('stack size',line.strip())
                  if s is not None:
                     s2 = re.search('unlimited$',line.strip())
                     if s2 is not None:
                        stack_size = "passed"
                  s = re.search('cpu time',line.strip())
                  if s is not None:
                     s2 = re.search('unlimited$',line.strip())
                     if s2 is not None:
                        cpu_time = "passed"
#                  s = re.search('virtual memory',line.strip())
#                  if s is not None:
#                     s2 = re.search('unlimited$',line.strip())
#                     if s2 is not None:
#                        virtual_memory = "passed"
                  s = re.search('file locks',line.strip())
                  if s is not None:
                     s2 = re.search('unlimited$',line.strip())
                     if s2 is not None:
                        file_locks = "passed"
                  s = re.search('max memory size',line.strip())
                  if s is not None:
#                     print "hostname=",hostname
                     if re.search('fission',hostname): 
                        ref_mem = 62000000
                     elif re.search('quark',hostname):
                        ref_mem = 19000000
                     elif re.search('rocky',hostname):
                        ref_mem = 300000000
                     elif re.search('fbuild',hostname):
                        ref_mem = 62000000
                     elif re.search('qbuild',hostname):
                        ref_mem = 126000000
                     elif re.search('r[0-9]i[0-9]n[0-9]',hostname):
                        ref_mem = 14000000
#                     print "ref_mem=",ref_mem
                     if data[5] == "unlimited":
                        max_memory_size = "passed"
                     elif int(data[5]) > ref_mem:
                        max_memory_size = "passed"
#              print "1=",data_seg_size,"2=",file_size,"3=",max_locked_memory,"4=",stack_size,"5=",cpu_time,"6=",file_locks,"7=",max_memory_size,"8=",pbs_limits
              if (data_seg_size == "passed") and (file_size == "passed") and (max_locked_memory == "passed") and \
                 (stack_size == "passed") and (cpu_time == "passed") and \
                 (file_locks == "passed") and (max_memory_size == "passed") and (pbs_limits == "passed"):
                 pbs_run_results.append("passed")
              else:
                 pbs_run_results.append("failed")
              pbs_run_string.append("pbs.conf permission and limits on " + hostname) 
           else:
#              print "Error: File %s does not exist\n" % pbs_file
              pbs_run_results.append("running")
              pbs_run_string.append("pbs.conf permission and limits on compute node") 
        else:
           pbs_run_results.append("failed")
           pbs_run_string.append("pbs.conf permission and limits on compute node") 

#           print "pbs_run_results",pbs_run_results


def concat_files(f1_name, f2_name, f_name):

#    print f1_name, f2_name, f_name
    f1 = open(f1_name, 'r')
    if os.path.exists(f2_name):
       f2 = open(f2_name, 'r')
    f  = open(f_name, 'w')

    f.write(f1.read())
    if os.path.exists(f2_name):
       f.write(f2.read())


def gaussian_html_link_str(str1,jobid,result):

    file_o = str1 + ".o" + jobid
    file_e = str1 + ".e" + jobid
    file_out2 = str1 + ".oe" + jobid

    file_out = re.split("/",file_out2)[-1]

    concat_files(file_o,file_e,file_out)

    result = "<a href=\"" + str1 + "\"" + "target=\"_blank\">" + result + "</a>"
    
    return result


def html_link_str(str1,jobid,result):

    file_o = str1 + ".o" + jobid
    file_e = str1 + ".e" + jobid
    file_out2 = str1 + ".oe" + jobid

    file_out = re.split("/",file_out2)[-1]

    concat_files(file_o,file_e,file_out)

    result = "<a href=\"" + clustername + "/" + file_out + "\"" + "target=\"_blank\">" + result + "</a>"
    
    return result


def log_link_str(file_str,result):
    shutil.copy(global_hostname + "_" + file_str + ".log", global_hostname + "_" + file_str + ".txt")
    link_str = "<a href=\"" + clustername + "/" + global_hostname + "_" + file_str + ".txt" + "\" target=\"_blank\">" + result + "</a>"
    return link_str


def qa_report():
    if len(sys.argv) > 1 and re.match('h',sys.argv[1]):
       print "<html>"
       print "<body>"
       print "<pre>"
    print
    print "Software Quality Assurance Tests run on ",global_hostname," at",run_date
    print
    print "".ljust(143,"#")
    print "Compiler Tests".center(130)
    print 
    for module,compiler,result,pbs_jobid,pbs_jobname,run_result in zip(c_modules,c_compilers,c_results,c_pbs_job_id,c_pbs_job_name,c_run_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result):
              result = log_link_str("compiler_test",result)
              print module.ljust(20),compiler.ljust(10),'Compile',result.rjust(155,"-")
           else:
              print module.ljust(20),compiler.ljust(10),'Compile',result.rjust(100,"-")
           if re.search("failed$|check$",run_result) and re.search("\d+",pbs_jobid):
              if re.match("gcc|pgcc|icc|clang",compiler):
                 run_result = html_link_str(pbs_jobname, pbs_jobid, run_result)
                 print module.ljust(32),compiler.ljust(10),'Job'.ljust(5),pbs_jobid.ljust(7),run_result.rjust(131,"-")
              elif re.match("gfortran|pgf77|pgf90|ifort",compiler):
                 run_result = html_link_str(pbs_jobname, pbs_jobid, run_result)
                 print module.ljust(32),compiler.ljust(10),'Job'.ljust(5),pbs_jobid.ljust(7),run_result.rjust(131,"-")
              elif re.match("g\+\+|c\+\+|pgCC|icpc|clang\+\+",compiler):
                 run_result = html_link_str(pbs_jobname, pbs_jobid, run_result)
                 print module.ljust(32),compiler.ljust(10),'Job'.ljust(5),pbs_jobid.ljust(7),run_result.rjust(131,"-")
              else:
                 print module.ljust(32),compiler.ljust(10),'Job'.ljust(5),pbs_jobid.ljust(7),run_result.rjust(85,"-")
           else:
              print module.ljust(32),compiler.ljust(10),'Job'.ljust(5),pbs_jobid.ljust(7),run_result.rjust(85,"-")
        else:
           print module.ljust(32),compiler.ljust(10),'Compile'.ljust(12),result.rjust(80,"-")
           print module.ljust(32),compiler.ljust(10),'Job'.ljust(4),pbs_jobid.ljust(7),run_result.rjust(80,"-")
    c_no_passed = c_results.count("passed") + c_run_results.count("passed")
    c_no_failed = c_results.count("failed") + c_run_results.count("failed")
    c_no_check = c_results.count("check") + c_run_results.count("check")
    c_no_running = c_run_results.count("running")
    print
    print "Total No of Compiler QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (c_no_passed+c_no_failed+c_no_check+c_no_running,c_no_passed,c_no_failed,c_no_check,c_no_running)
    print
    print "".ljust(143,"#")
    print "MPI Tests".center(130)
    print
    for module,compiler,result,pbs_jobid,pbs_jobname,run_result in zip(mpi_modules,mpi_compilers,mpi_results,mpi_pbs_job_id,mpi_pbs_job_name, mpi_run_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result):
              result = log_link_str("mpi_test",result)
              print module.ljust(32),compiler.ljust(10),'Compile'.ljust(13),result.rjust(133,"-")
           else:
              print module.ljust(32),compiler.ljust(10),'Compile'.ljust(13),result.rjust(85,"-")
           if re.search("failed$|check$",run_result) and re.search("\d+",pbs_jobid):
              if re.match("mpicc|mpiicc",compiler):
                 run_result = html_link_str(pbs_jobname, pbs_jobid, run_result)
                 print module.ljust(32),compiler.ljust(10),'Job'.ljust(5),pbs_jobid.ljust(7),run_result.rjust(131,"-")
              elif re.match("mpif90|mpif77|mpiifort",compiler):
                 run_result = html_link_str(pbs_jobname, pbs_jobid, run_result)
                 print module.ljust(32),compiler.ljust(10),'Job'.ljust(5),pbs_jobid.ljust(7),run_result.rjust(131,"-")
              elif re.match("mpicxx|mpiicpc",compiler):
                 run_result = html_link_str(pbs_jobname, pbs_jobid, run_result)
                 print module.ljust(32),compiler.ljust(10),'Job'.ljust(5),pbs_jobid.ljust(7),run_result.rjust(131,"-")
              else:
                 print module.ljust(32),compiler.ljust(10),'Job'.ljust(5),pbs_jobid.ljust(7),run_result.rjust(85,"-")
           else:
              print module.ljust(32),compiler.ljust(10),'Job'.ljust(5),pbs_jobid.ljust(7),run_result.rjust(85,"-")
        else:
           print module.ljust(25),compiler.ljust(10),'Compile'.ljust(13),result.rjust(85,"-")
           print module.ljust(25),compiler.ljust(10),'Job'.ljust(5),pbs_jobid.ljust(7),run_result.rjust(85,"-")
    mpi_no_passed = mpi_results.count("passed") + mpi_run_results.count("passed")
    mpi_no_failed =mpi_results.count("failed") + mpi_run_results.count("failed")
    mpi_no_check = mpi_results.count("check") + mpi_run_results.count("check")
    mpi_no_running = mpi_run_results.count("running")
    print
    print "Total No of MPI QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (mpi_no_passed+mpi_no_failed+mpi_no_check+mpi_no_running,mpi_no_passed,mpi_no_failed,mpi_no_check,mpi_no_running)
    print
    print "".ljust(143,"#")
    print "PBS Tests".center(130)
    print
    for pbsstring,result,pbsrun_string,pbs_jobid,run_result in zip(pbs_string,pbs_results,pbs_run_string,pbs_pbs_job_id,pbs_run_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              result = log_link_str("pbs_qa",result)
              print pbsstring.ljust(58),result.rjust(84,'-')
           else:
              print pbsstring.ljust(58),result.rjust(84,'-')
           if re.search("failed$|check$",run_result):
              run_result = html_link_str("pbs", pbs_jobid, run_result)
              print pbsrun_string.ljust(50),pbs_jobid.ljust(7),run_result.rjust(126,'-')
           else:
              print pbsrun_string.ljust(50),pbs_jobid.ljust(7),run_result.rjust(84,'-')
        else:
           print pbsstring.ljust(58),result.rjust(84,'-')
           print pbsrun_string.ljust(50),pbs_jobid.ljust(7),run_result.rjust(84,'-')
    pbs_no_passed = pbs_results.count("passed") + pbs_run_results.count("passed")
    pbs_no_failed = pbs_results.count("failed") + pbs_run_results.count("failed")
    pbs_no_check  = pbs_results.count("check")  + pbs_run_results.count("check")
    pbs_no_running  = pbs_run_results.count("running")
    print
    print "Total No of PBS QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (pbs_no_passed+pbs_no_failed+pbs_no_check,pbs_no_passed,pbs_no_failed,pbs_no_check,pbs_no_running)
    print
    print "".ljust(143,"#")
    print "BLAS Library Tests".center(130)
    print
    for mod1,compiler,result,pbs_jobid,pbs_jobname,run_result in zip(blas_modules,blas_compilers,blas_results,blas_pbs_job_id,blas_pbs_job_name, blas_run_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result):
              result = log_link_str("blas_test",result)
              print mod1.ljust(40),compiler.ljust(8),'Compile/link'.ljust(12),result.rjust(8,'-')
           else:
              print mod1.ljust(40),compiler.ljust(8),'Compile/link'.ljust(12),result.rjust(8,'-')
           if re.search("failed$|check$",run_result) and re.search("\d+",pbs_jobid):
              run_result = html_link_str(pbs_jobname, pbs_jobid, run_result)
              print mod1.ljust(40),compiler.ljust(8),'Job'.ljust(5),pbs_jobid.ljust(6),run_result.rjust(8,'-')
           else:
              print mod1.ljust(40),compiler.ljust(8),'Job'.ljust(5),pbs_jobid.ljust(6),run_result.rjust(8,'-')
        else:
           print mod1.ljust(40),compiler.ljust(8),'Compile/link'.ljust(12),result.rjust(8,'-')
           print mod1.ljust(40),compiler.ljust(8),'Job'.ljust(5),pbs_jobid.ljust(6),run_result.rjust(8,'-')
    blas_no_passed = blas_results.count("passed") + blas_run_results.count("passed")
    blas_no_failed = blas_results.count("failed") + blas_run_results.count("failed")
    blas_no_check  = blas_results.count("check")  + blas_run_results.count("check")
    blas_no_running = blas_run_results.count("running")
    print
    print "Total No of BLAS Library QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (blas_no_passed+blas_no_failed+blas_no_check,blas_no_passed,blas_no_failed,blas_no_check,blas_no_running)
    print
    print "".ljust(143,"#")
    print "Boost Tests".center(130)
    print
    for mod1,compiler,result,pbs_jobid,pbs_jobname,run_result in zip(boost_modules,boost_cxx_compilers,boost_compile_results,boost_pbs_job_id,boost_pbs_job_name,boost_run_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result):
              result = log_link_str("boost_test",result)
              print mod1.ljust(40),compiler.ljust(8),'Compile/link'.ljust(12),result.rjust(8,'-')
           else:
              print mod1.ljust(40),compiler.ljust(8),'Compile/link'.ljust(12),result.rjust(8,'-')
           if re.search("failed$|check$",run_result) and re.search("\d+",pbs_jobid):
              run_result = html_link_str(pbs_jobname, pbs_jobid, run_result)
              print mod1.ljust(40),compiler.ljust(8),'Job'.ljust(5),pbs_jobid.ljust(6),run_result.rjust(8,'-')
           else:
              print mod1.ljust(40),compiler.ljust(8),'Job'.ljust(5),pbs_jobid.ljust(6),run_result.rjust(8,'-')
        else:
           print mod1.ljust(40),compiler.ljust(8),'Compile/link'.ljust(12),result.rjust(8,'-')
           print mod1.ljust(40),compiler.ljust(8),'Job'.ljust(5),pbs_jobid.ljust(6),run_result.rjust(8,'-')
    boost_no_passed = boost_compile_results.count("passed") + boost_run_results.count("passed")
    boost_no_failed = boost_compile_results.count("failed") + boost_run_results.count("failed")
    boost_no_check  = boost_compile_results.count("check")  + boost_run_results.count("check")
    boost_no_running = boost_run_results.count("running")
    print
    print "Total No of Boost Library QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (boost_no_passed+boost_no_failed+boost_no_check,boost_no_passed,boost_no_failed,boost_no_check,boost_no_running)
    print
    print "".ljust(143,"#")
    print "HELIOS Tests".center(130)
    print
    for mod1,jobs,pbs_jobid,pbs_jobname,result in zip(helios_modules,helios_run_dir,helios_pbs_job_id,helios_pbs_job_name,helios_run_results):
#        print mod1,jobs,pbs_jobid,result
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              if re.search('[0-9]+',pbs_jobid):
                 result = html_link_str(jobs+"/"+pbs_jobname, pbs_jobid, result)
#                 os.rename(jobs+"/"+"helios.oe" + pbs_jobid,"helios.oe" + pbs_jobid)
                 print mod1.ljust(17),jobs.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
              else:
                 result = log_link_str("helios_test",result)
                 print mod1.ljust(17),jobs.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
           else:
              print mod1.ljust(17),jobs.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
        else:
           print mod1.ljust(17),jobs.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
    helios_no_passed = helios_run_results.count("passed")
    helios_no_failed = helios_run_results.count("failed")
    helios_no_check  = helios_run_results.count("check")
    helios_no_running  = helios_run_results.count("running")
    print
    print "Total No of HELIOS QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (helios_no_passed+helios_no_failed+helios_no_check+helios_no_running,helios_no_passed,helios_no_failed,helios_no_check,helios_no_running)
    print
    print "".ljust(143,"#")
    print "HELIOS_linT64 Tests".center(130)
    print
    for mod1,jobs,pbs_jobid,pbs_jobname,result in zip(helioslint64_modules,helioslint64_run_dir,helioslint64_pbs_job_id,helioslint64_pbs_job_name,helioslint64_run_results):
#        print mod1,jobs,pbs_jobid,result
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              if re.search('[0-9]+',pbs_jobid):
                 result = html_link_str(jobs+"/"+pbs_jobname, pbs_jobid, result)
#                 os.rename(jobs+"/"+"helios.oe" + pbs_jobid,"helios.oe" + pbs_jobid)
                 print mod1.ljust(17),jobs.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
              else:
                 result = log_link_str("helioslint64_test",result)
                 print mod1.ljust(17),jobs.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
           else:
              print mod1.ljust(17),jobs.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
        else:
           print mod1.ljust(17),jobs.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
    helioslint64_no_passed = helioslint64_run_results.count("passed")
    helioslint64_no_failed = helioslint64_run_results.count("failed")
    helioslint64_no_check  = helioslint64_run_results.count("check")
    helioslint64_no_running  = helios_run_results.count("running")
    print
    print "Total No of HELIOS_linT64 QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (helioslint64_no_passed+helioslint64_no_failed+helioslint64_no_check+helioslint64_no_running,helioslint64_no_passed,helioslint64_no_failed,helioslint64_no_check,helioslint64_no_running)
    print
    print "".ljust(143,"#")
    print "SCALE Tests".center(130)
    print
    for mod1,pbs_jobid,pbs_jobname,result in zip(scale_modules,scale_pbs_job_id,scale_pbs_job_name,scale_run_results):
#        print mod1,jobs,pbs_jobid,result
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              if re.search('[0-9]+',pbs_jobid):
                 result = html_link_str(pbs_jobname, pbs_jobid, result)
#                 os.rename(jobs+"/"+"scale.oe" + pbs_jobid,"scale.oe" + pbs_jobid)
                 print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
              else:
                 result = log_link_str("scale_test",result)
                 print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
           else:
              print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
        else:
           print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
    scale_no_passed = scale_run_results.count("passed")
    scale_no_failed = scale_run_results.count("failed")
    scale_no_check  = scale_run_results.count("check")
    scale_no_running  = scale_run_results.count("running")
    print
    print "Total No of SCALE QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (scale_no_passed+scale_no_failed+scale_no_check+scale_no_running,scale_no_passed,scale_no_failed,scale_no_check,scale_no_running)
    print
    print "".ljust(143,"#")
    print "SCALE62 Tests".center(130)
    print
    for mod1,pbs_jobid,pbs_jobname,result in zip(scale62_modules,scale62_pbs_job_id,scale62_pbs_job_name,scale62_run_results):
#        print mod1,jobs,pbs_jobid,result
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              if re.search('[0-9]+',pbs_jobid):
                 result = html_link_str(pbs_jobname, pbs_jobid, result)
#                 os.rename(jobs+"/"+"scale.oe" + pbs_jobid,"scale.oe" + pbs_jobid)
                 print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
              else:
                 result = log_link_str("scale62_test",result)
                 print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
           else:
              print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
        else:
           print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
    scale62_no_passed = scale62_run_results.count("passed")
    scale62_no_failed = scale62_run_results.count("failed")
    scale62_no_check  = scale62_run_results.count("check")
    scale62_no_running  = scale62_run_results.count("running")
    print
    print "Total No of SCALE62 QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (scale62_no_passed+scale62_no_failed+scale62_no_check+scale62_no_running,scale62_no_passed,scale62_no_failed,scale62_no_check,scale62_no_running)
    print
    print "".ljust(143,"#")
    print "SERPENT Tests".center(130)
    print
    for mod1,pbs_jobid,pbs_jobname,result in zip(serpent_modules, serpent_pbs_job_id, serpent_pbs_job_name, serpent_run_results):
#        print mod1,jobs,pbs_jobid,result
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              if re.search('[0-9]+',pbs_jobid):
                 result = html_link_str(pbs_jobname, pbs_jobid, result)
#                 os.rename(jobs+"/"+"scale.oe" + pbs_jobid,"scale.oe" + pbs_jobid)
                 print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
              else:
                 result = log_link_str("serpent_test",result)
                 print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
           else:
              print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
        else:
           print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
    serpent_no_passed = serpent_run_results.count("passed")
    serpent_no_failed = serpent_run_results.count("failed")
    serpent_no_check  = serpent_run_results.count("check")
    serpent_no_running  = serpent_run_results.count("running")
    print
    print "Total No of SERPENT QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (serpent_no_passed+serpent_no_failed+serpent_no_check+serpent_no_running,serpent_no_passed,serpent_no_failed,serpent_no_check,serpent_no_running)
    print
    print "".ljust(143,"#")
    print "CTH Tests".center(130)
    print
    for mod1, pbs_jobid, pbs_jobname, result in zip(cth_modules, cth_pbs_job_id, cth_pbs_job_name, cth_run_results):
#        print mod1,jobs,pbs_jobid,result
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              if re.search('[0-9]+',pbs_jobid):
                 result = html_link_str(pbs_jobname, pbs_jobid, result)
#                 os.rename(jobs+"/"+"scale.oe" + pbs_jobid,"scale.oe" + pbs_jobid)
                 print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
              else:
                 result = log_link_str("cth_test",result)
                 print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
           else:
              print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
        else:
           print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
    cth_no_passed = cth_run_results.count("passed")
    cth_no_failed = cth_run_results.count("failed")
    cth_no_check  = cth_run_results.count("check")
    cth_no_running  = cth_run_results.count("running")
    print
    print "Total No of CTH QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (cth_no_passed+cth_no_failed+cth_no_check+cth_no_running,cth_no_passed,cth_no_failed,cth_no_check,cth_no_running)
    print
    print "".ljust(143,"#")
    print "MC21 Tests".center(130)
    print
    for mod1, pbs_jobid, pbs_jobname, result in zip(mc21_modules, mc21_pbs_job_id, mc21_pbs_job_name, mc21_run_results):
#        print mod1,jobs,pbs_jobid,result
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              if re.search('[0-9]+',pbs_jobid):
                 result = html_link_str(pbs_jobname, pbs_jobid, result)
#                 os.rename(jobs+"/"+"scale.oe" + pbs_jobid,"scale.oe" + pbs_jobid)
                 print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
              else:
                 result = log_link_str("mc21_test",result)
                 print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
           else:
              print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
        else:
           print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
    mc21_no_passed = mc21_run_results.count("passed")
    mc21_no_failed = mc21_run_results.count("failed")
    mc21_no_check  = mc21_run_results.count("check")
    mc21_no_running  = mc21_run_results.count("running")
    print
    print "Total No of MC21 QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (mc21_no_passed+mc21_no_failed+mc21_no_check+mc21_no_running,mc21_no_passed,mc21_no_failed,mc21_no_check,mc21_no_running)
    print "".ljust(143,"#")
    print "MCNP Tests".center(130)
    print
    for mod1,pbs_jobid,pbs_jobname,result in zip(mcnp_modules,mcnp_pbs_job_id,mcnp_pbs_job_name,mcnp_run_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              if re.search('[0-9]+',pbs_jobid):
                 result = html_link_str(pbs_jobname, pbs_jobid, result)
                 print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
              else:
                 result = log_link_str("m_test",result)
                 print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
           else:
              print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
        else:
           print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
    mcnp_no_passed = mcnp_run_results.count("passed")
    mcnp_no_failed = mcnp_run_results.count("failed")
    mcnp_no_check  = mcnp_run_results.count("check")
    mcnp_no_running  = mcnp_run_results.count("running")
    print
    print "Total No of MCNP QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (mcnp_no_passed+mcnp_no_failed+mcnp_no_check+mcnp_no_running,mcnp_no_passed,mcnp_no_failed,mcnp_no_check,mcnp_no_running)
    print
    print "".ljust(143,"#")
    print "MCNPX Tests".center(130)
    print
    for mod1,pbs_jobid,pbs_jobname,result in zip(mcnpx_modules,mcnpx_pbs_job_id,mcnpx_pbs_job_name,mcnpx_run_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              if re.search('[0-9]+',pbs_jobid):
                 result = html_link_str(pbs_jobname, pbs_jobid, result)
                 print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
              else:
                 result = log_link_str("x_test",result)
                 print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
           else:
              print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
        else:
           print mod1.ljust(17),pbs_jobname.ljust(8),pbs_jobid.ljust(10),result.rjust(105,'-')
    mcnpx_no_passed = mcnpx_run_results.count("passed")
    mcnpx_no_failed = mcnpx_run_results.count("failed")
    mcnpx_no_check  = mcnpx_run_results.count("check")
    mcnpx_no_running  = mcnpx_run_results.count("running")
    print
    print "Total No of MCNPX QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (mcnpx_no_passed+mcnpx_no_failed+mcnpx_no_check+mcnpx_no_running,mcnpx_no_passed,mcnpx_no_failed,mcnpx_no_check,mcnpx_no_running)
    print
    print "".ljust(143,"#")
    print "Vasp Tests".center(130)
    print
    for mod1,jobs,pbs_jobid,pbs_jobname,result in zip(vasp_modules,vasp_run_dir,vasp_pbs_job_id,vasp_pbs_job_name,vasp_run_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              result = html_link_str(jobs+"/"+pbs_jobname, pbs_jobid, result)
#              os.rename(jobs+"/"+"vasp_qa.oe" + pbs_jobid,"vasp_qa.oe" + pbs_jobid)
              print mod1.ljust(15),jobs.ljust(8),pbs_jobid.ljust(8),result.rjust(109,'-')
           else:
              print mod1.ljust(15),jobs.ljust(8),pbs_jobid.ljust(8),result.rjust(109,'-')
        else:
           print mod1.ljust(15),jobs.ljust(8),pbs_jobid.ljust(8),result.rjust(109,'-')
    vasp_no_passed = vasp_run_results.count("passed")
    vasp_no_failed = vasp_run_results.count("failed")
    vasp_no_check  = vasp_run_results.count("check")
    vasp_no_running  = vasp_run_results.count("running")
    print
    print "Total No of VASP QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (vasp_no_passed+vasp_no_failed+vasp_no_check+vasp_no_running,vasp_no_passed,vasp_no_failed,vasp_no_check,vasp_no_running)
    print
    print "".ljust(143,"#")
    print "Gaussian Tests".center(130)
    print
    for mod1,pbs_jobid,pbs_jobname,result in zip(gaussian_modules,gaussian_pbs_job_id,gaussian_pbs_job_name,gaussian_run_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              result = gaussian_html_link_str(pbs_jobname, pbs_jobid, result)
              print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
           else:
              print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
        else:
           print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
    gaussian_no_passed   = gaussian_run_results.count("passed")
    gaussian_no_failed   = gaussian_run_results.count("failed")
    gaussian_no_check    = gaussian_run_results.count("check")
    gaussian_no_running  = gaussian_run_results.count("running")
    print
    print "Total No of GAUSSIAN QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (gaussian_no_passed+gaussian_no_failed+gaussian_no_check+gaussian_no_running,gaussian_no_passed,gaussian_no_failed,gaussian_no_check,gaussian_no_running)
    print
    print "".ljust(143,"#")
    print "STARCCM Tests".center(130)
    print
    for mod1,pbs_jobid,pbs_jobname,result in zip(starccm_modules,starccm_pbs_job_id,starccm_pbs_job_name,starccm_run_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              result = html_link_str(pbs_jobname, pbs_jobid, result)
              print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(162,'-')
           else:
              print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(114,'-')
        else:
           print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(114,'-')
    star_no_passed = starccm_run_results.count("passed")
    star_no_failed = starccm_run_results.count("failed")
    star_no_check  = starccm_run_results.count("check")
    star_no_running  = starccm_run_results.count("running")
    print
    print "Total No of STARCCM+ QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (star_no_passed+star_no_failed+star_no_check+star_no_running,star_no_passed,star_no_failed,star_no_check,star_no_running)
    print
    print "".ljust(143,"#")
    print "ABAQUS Tests".center(130)
    print
    for mod1,pbs_jobid,pbs_jobname,result in zip(abaqus_modules,abaqus_pbs_job_id,abaqus_pbs_job_name,abaqus_run_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              result = html_link_str(pbs_jobname, pbs_jobid, result)
              print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
           else:
              print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
        else:
           print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
    abaqus_no_passed   = abaqus_run_results.count("passed")
    abaqus_no_failed   = abaqus_run_results.count("failed")
    abaqus_no_check    = abaqus_run_results.count("check")
    abaqus_no_running  = abaqus_run_results.count("running")
    print
    print "Total No of ABAQUS QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (abaqus_no_passed+abaqus_no_failed+abaqus_no_check+abaqus_no_running,abaqus_no_passed,abaqus_no_failed,abaqus_no_check,abaqus_no_running)
    print
    print "".ljust(143,"#")
    print "LSDYNA Tests".center(130)
    print
    for mod1,pbs_jobid,result in zip(lsdyna_modules,lsdyna_pbs_job_id,lsdyna_run_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              if re.search('[0-9]+',pbs_jobid):
                 result = html_link_str("lsdyna_qa", pbs_jobid, result)
                 print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
              else:
                 result = log_link_str("lsdyna_qa",result)
                 print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
           else:
              print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
        else:
           print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
    lsdyna_no_passed   = lsdyna_run_results.count("passed")
    lsdyna_no_failed   = lsdyna_run_results.count("failed")
    lsdyna_no_check    = lsdyna_run_results.count("check")
    lsdyna_no_running  = lsdyna_run_results.count("running")
    print
    print "Total No of LSDYNA QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (lsdyna_no_passed+lsdyna_no_failed+lsdyna_no_check+lsdyna_no_running,lsdyna_no_passed,lsdyna_no_failed,lsdyna_no_check,lsdyna_no_running)
    print
    print "".ljust(143,"#")
    print "ANSYS Tests".center(130)
    print
    for mod1,pbs_jobid,result in zip(ansys_modules,ansys_pbs_job_id,ansys_run_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              if re.search('[0-9]+',pbs_jobid):
                 result = html_link_str("ansys_qa", pbs_jobid, result)
                 print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
              else:
                 result = log_link_str("ansys_qa",result)
                 print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
           else:
              print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
        else:
           print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
    ansys_no_passed   = ansys_run_results.count("passed")
    ansys_no_failed   = ansys_run_results.count("failed")
    ansys_no_check    = ansys_run_results.count("check")
    ansys_no_running  = ansys_run_results.count("running")
    print
    print "Total No of ANSYS QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (ansys_no_passed+ansys_no_failed+ansys_no_check+ansys_no_running,ansys_no_passed,ansys_no_failed,ansys_no_check,ansys_no_running)
    print
    print "".ljust(143,"#")
    print "MATLAB Tests".center(130)
    print
    for mod1,pbs_jobid,pbs_jobname,result in zip(matlab_modules,matlab_pbs_job_id,matlab_pbs_job_name,matlab_run_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result) and re.search("\d+",pbs_jobid):
              result = html_link_str(pbs_jobname, pbs_jobid, result)
              print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
           else:
              print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
        else:
           print mod1.ljust(20),pbs_jobid.ljust(8),result.rjust(104,'-')
    matlab_no_passed   = matlab_run_results.count("passed")
    matlab_no_failed   = matlab_run_results.count("failed")
    matlab_no_check    = matlab_run_results.count("check")
    matlab_no_running  = matlab_run_results.count("running")
    print
    print "Total No of MATLAB QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (matlab_no_passed+matlab_no_failed+matlab_no_check+matlab_no_running,matlab_no_passed,matlab_no_failed,matlab_no_check,matlab_no_running)
    print
    print
    print "".ljust(143,"#")
    print "PYTHON2 Tests".center(130)
    print
    for module,test,result in zip(python2_modules,python2_tests,python2_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result):
              result = log_link_str("python2_test",result)
              print module.ljust(15),test.ljust(12),result.rjust(166,'-')
           else:
              print module.ljust(15),test.ljust(12),result.rjust(114,'-')
        else:
           print module.ljust(15),test.ljust(12),result.rjust(114,'-')
    python2_no_passed = python2_results.count("passed")
    python2_no_failed = python2_results.count("failed")
    python2_no_check  = python2_results.count("check")
    print
    print "Total No of Python2 QA Tests = %d ( Passed = %d Failed = %d Check = %d )" % (python2_no_passed+python2_no_failed+python2_no_check,python2_no_passed,python2_no_failed,python2_no_check)
    print
    print "".ljust(143,"#")
    print "PYTHON3 Tests".center(130)
    print
    for module,test,result in zip(python3_modules,python3_tests,python3_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result):
              result = log_link_str("python3_test",result)
              print module.ljust(15),test.ljust(12),result.rjust(166,'-')
           else:
              print module.ljust(15),test.ljust(12),result.rjust(114,'-')
        else:
           print module.ljust(15),test.ljust(12),result.rjust(114,'-')
    python3_no_passed = python3_results.count("passed")
    python3_no_failed = python3_results.count("failed")
    python3_no_check  = python3_results.count("check")
    print
    print "Total No of Python3 QA Tests = %d ( Passed = %d Failed = %d Check = %d )" % (python3_no_passed+python3_no_failed+python3_no_check,python3_no_passed,python3_no_failed,python3_no_check)
    print
    print
    print "".ljust(143,"#")
    print "MISC Tests".center(130)
    print
    for string,result in zip(misc_string,misc_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result):
              result = log_link_str("misc_qa",result)
              print string.ljust(21),result.rjust(121,'-')
           else:
              print string.ljust(21),result.rjust(121,'-')
        else:
           print string.ljust(21),result.rjust(121,'-')
    for string,pbs_jobid,result in zip(misc_run_string,misc_job_id,misc_run_results):
        if len(sys.argv) > 1 and re.match("h",sys.argv[1]):
           if re.search("failed$|check$",result):
              result = html_link_str("shmmax", pbs_jobid, result)
              print string.ljust(12),pbs_jobid.ljust(8),result.rjust(121,'-')
           else:
              print string.ljust(12),pbs_jobid.ljust(8),result.rjust(121,'-')
        else:
           print string.ljust(12),pbs_jobid.ljust(8),result.rjust(121,'-')
    misc_no_passed   = misc_run_results.count("passed") + misc_results.count("passed")
    misc_no_failed   = misc_run_results.count("failed") + misc_results.count("failed")
    misc_no_check    = misc_run_results.count("check") + misc_results.count("check")
    misc_no_running  = misc_run_results.count("running") + misc_results.count("running")
    print
    print "Total No of MISCELLANEOUS QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (misc_no_passed+misc_no_failed+misc_no_check+misc_no_running,misc_no_passed,misc_no_failed,misc_no_check,misc_no_running)
    print
    print "".ljust(143,"#")
    print
    total_no_passed = c_no_passed+mpi_no_passed+blas_no_passed+pbs_no_passed+mcnp_no_passed+vasp_no_passed+gaussian_no_passed+star_no_passed+abaqus_no_passed+matlab_no_passed+python2_no_passed+python3_no_passed+misc_no_passed+lsdyna_no_passed+mcnpx_no_passed+ansys_no_passed+boost_no_passed+helios_no_passed+helioslint64_no_passed+scale_no_passed+scale62_no_passed+serpent_no_passed+cth_no_passed+mc21_no_passed
    total_no_failed = c_no_failed+mpi_no_failed+blas_no_failed+pbs_no_failed+mcnp_no_failed+vasp_no_failed+gaussian_no_failed+star_no_failed+abaqus_no_failed+matlab_no_failed+python2_no_failed+python3_no_failed+misc_no_failed+lsdyna_no_failed+mcnpx_no_failed+ansys_no_failed+boost_no_failed+helios_no_failed+helioslint64_no_failed+scale_no_failed+scale62_no_failed+serpent_no_failed+cth_no_failed+mc21_no_failed
    total_no_check = c_no_check+mpi_no_check+blas_no_check+pbs_no_check+mcnp_no_check+vasp_no_check+gaussian_no_check+star_no_check+abaqus_no_check+matlab_no_check+python2_no_check+python3_no_check+misc_no_check+lsdyna_no_check+mcnpx_no_check+ansys_no_check+boost_no_check+helios_no_check+helioslint64_no_check+scale_no_check+scale62_no_check+serpent_no_check+cth_no_check+mc21_no_check
    total_no_running = c_no_running+mpi_no_running+pbs_no_running+mcnp_no_running+vasp_no_running+gaussian_no_running+star_no_running+abaqus_no_running+matlab_no_running+misc_no_running+lsdyna_no_running+blas_no_running+mcnpx_no_running+ansys_no_running+boost_no_running+helios_no_running+helioslint64_no_running+scale_no_running+scale62_no_running+serpent_no_running+cth_no_running+mc21_no_running
    print 
    print "Total No of QA Tests = %d ( Passed = %d Failed = %d Check = %d Running = %d )" % (total_no_passed+total_no_failed+total_no_check+total_no_running,total_no_passed,total_no_failed,total_no_check,total_no_running)
    print
    print "".ljust(143,"#")
    if len(sys.argv) > 1 and re.match('h',sys.argv[1]):
       print "</pre>"
       print "</body>"
       print "</html>"


def main():
#    if len(sys.argv) != 2:
#       sys.exit('Usage: qa_report.py <file no>\n')
#    print "argv=",sys.argv[0],sys.argv[1]
    try:
       f1 = open(hostname + "_compiler_results.out","r")
       collect_compiler_qa_results(f1,c_modules,c_compilers,c_pbs_job_name,c_results)
       check_compiler_run_results()
    except IOError, e:
       print 'Could not open compiler_results file: skipping'
    try:
       f2 = open(hostname + "_mpi_results.out","r")
       collect_mpi_qa_results(f2,mpi_modules,mpi_compilers,mpi_pbs_job_name,mpi_results)
       check_mpi_run_results()
    except IOError, e:
       print 'Could not open mpi_results file: skipping'
    try:
       f3 = open(hostname + "_blas_results.out","r")
       collect_blas_qa_results(f3,blas_modules,blas_compilers,blas_pbs_job_name,blas_results)
       check_blas_run_results()
    except IOError, e:
       print 'Could not open blas_results file: skipping'
    try:
       f4 = open(hostname + "_boost_results.out","r")
       collect_boost_qa_results(f4,boost_modules,boost_cxx_compilers,boost_pbs_job_name,boost_compile_results)
       check_boost_run_results()
    except IOError, e:
       print 'Could not open boost_qa_results file: skipping'
    try:
       f5 = open(hostname + "_m_results.out","r")
       collect_mcnp_qa_results(f5,mcnp_modules,mcnp_pbs_job_name)
       check_mcnp_run_results()
    except IOError, e:
       print 'Could not open m_results file: skipping'
    try:
       f6 = open(hostname + "_x_results.out","r")
       collect_mcnpx_qa_results(f6,mcnpx_modules,mcnpx_pbs_job_name)
       check_mcnpx_run_results()
    except IOError, e:
       print 'Could not open x_results file: skipping'
    try:
       f7 = open(hostname + "_scale_results.out","r")
       collect_scale_qa_results(f7,scale_modules,scale_pbs_job_name)
       check_scale_run_results()
    except IOError, e:
       print 'Could not open scale_results file: skipping'
    try:
       f8 = open(hostname + "_helios_results.out","r")
       collect_helios_qa_results(f8,helios_modules,helios_run_dir,helios_pbs_job_name)
       check_helios_run_results()
    except IOError, e:
       print 'Could not open helios_results file: skipping'
    try:
       f9 = open(hostname + "_helioslint64_results.out","r")
       collect_helioslint64_qa_results(f9,helioslint64_modules,helioslint64_run_dir,helioslint64_pbs_job_name)
       check_helioslint64_run_results()
    except IOError, e:
       print 'Could not open helioslint64_results file: skipping'
    try:
       f10 = open(hostname + "_vasp_results.out","r")
       collect_vasp_qa_results(f10,vasp_modules,vasp_run_dir,vasp_pbs_job_name)
       check_vasp_run_results()
    except IOError, e:
       print 'Could not open vasp_results file: skipping'
    try:
       f11 = open(hostname + "_gaussian_results.out","r")
       collect_gaussian_qa_results(f11,gaussian_modules,gaussian_pbs_job_name)
       check_gaussian_run_results()
    except IOError, e:
       print 'Could not open gaussian_results file: skipping'
    try:
       f12 = open(hostname + "_starccm_results.out","r")
       collect_starccm_qa_results(f12,starccm_modules, starccm_pbs_job_name)
       check_starccm_run_results()
    except IOError, e:
       print 'Could not open starccm_results file: skipping'
    try:
       f13 = open(hostname + "_abaqus_results.out","r")
       collect_abaqus_qa_results(f13,abaqus_modules,abaqus_pbs_job_name)
       check_abaqus_run_results()
    except IOError, e:
       print 'Could not open abaqus_results file: skipping'
    try:
       f14 = open(hostname + "_matlab_results.out","r")
       collect_matlab_qa_results(f14,matlab_modules,matlab_pbs_job_name)
       check_matlab_run_results()
    except IOError, e:
       print 'Could not open matlab_results file: skipping'
    try:
       f15 = open(hostname + "_python2_results.out","r")
       collect_python2_qa_results(f15,python2_modules,python2_tests,python2_results)
    except IOError, e:
       print 'Could not open python2_results file: skipping'
    try:
       f16 = open(hostname + "_python3_results.out","r")
       collect_python3_qa_results(f16,python3_modules,python3_tests,python3_results)
    except IOError, e:
       print 'Could not open python3_results file: skipping'
    try:
       f17 = open(hostname + "_scale62_results.out","r")
       collect_scale62_qa_results(f17, scale62_modules, scale62_pbs_job_name)
       check_scale62_run_results()
    except IOError, e:
       print 'Could not open scale62_results file: skipping'
    try:
       f18 = open(hostname + "_serpent_results.out","r")
       collect_serpent_qa_results(f18, serpent_modules, serpent_pbs_job_name)
       check_serpent_run_results()
    except IOError, e:
       print 'Could not open serpent_results file: skipping'
    try:
       f19 = open(hostname + "_cth_results.out","r")
       collect_cth_qa_results(f19, cth_modules, cth_run_dir, cth_pbs_job_name)
       check_cth_run_results()
    except IOError, e:
       print 'Could not open cth_results file: skipping'
    try:
       f20 = open(hostname + "_mc21_results.out","r")
       collect_mc21_qa_results(f20, mc21_modules, mc21_run_dir, mc21_pbs_job_name)
       check_mc21_run_results()
    except IOError, e:
       print 'Could not open mc21_results file: skipping'

    qa_report()


if __name__ == '__main__':
    main()
