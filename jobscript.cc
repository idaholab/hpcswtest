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
JobScript abstract base class source code

Date Created: Fri Nov 27 19:25:57 MST 2015

Author: Cormac Garvey

*/

#include "jobscript.h"


namespace jobscript {


JobScript::JobScript(const JobScript & j_s) {
  job_script_name_ = j_s.job_script_name_;
  job_name_ = j_s.job_name_;
  queue_name_ = j_s.queue_name_;
  total_num_procs_ = j_s.total_num_procs_;
  max_num_procs_per_node_ = j_s.max_num_procs_per_node_;
  host_name_ = j_s.host_name_;
  wall_time_ = j_s.wall_time_;
  mpi_cmd_name_ = j_s.mpi_cmd_name_;
  mpi_cmd_args_ = j_s.mpi_cmd_args_;
  exe_name_ = j_s.exe_name_;
  exe_args_ = j_s.exe_args_;
  modules_ = j_s.modules_;
}


void JobScript::setExeName(std::string e_n) {
 exe_name_ = e_n; 
}


void JobScript::setExeArgs(std::string e_a) {
 exe_args_ = e_a; 
}


std::string JobScript::setHostName(void) {
char hostname[1024];
gethostname(hostname, 1023);
return hostname;
}

/*
int JobScript::getTotalNumCores(void) const {
  return total_num_cores_;
}
*/


int JobScript::getMaxNumProcsPerNode(void) const {
  return max_num_procs_per_node_;
}


int JobScript::getTotalNumProcs(void) const {
  return total_num_procs_;
}


std::string JobScript::getHostName(void) const {
  return host_name_;
}


std::string JobScript::getWallTime(void) const {
  return wall_time_;
}


std::string JobScript::getMpiCmdName(void) const {
  return mpi_cmd_name_;
}


std::string JobScript::getMpiCmdArgs(void) const {
  return mpi_cmd_args_;
}


std::string JobScript::getExeName(void) const {
  return exe_name_;
}


std::string JobScript::getExeArgs(void) const {
  return exe_args_;
}


std::string JobScript::getJobScriptName(void) const {
  return job_script_name_;
}


std::string JobScript::getJobName(void) const {
  return job_name_;
}


std::string JobScript::getQueueName(void) const {
  return queue_name_;
}


modules::modules_type JobScript::getModules(void) const {
  return modules_;
}


} // namespace jobscript

