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
PbsScript sub class source code.

Date Created: Mon Nov 30 13:06:42 MST 2015

Author: Cormac Garvey

*/

#include "pbsscript.h"


namespace jobscript {


PbsScript::PbsScript(modules::modules_type ms, int t_n_p, int m_n_p_p_n, std::string m_c_n, std::string m_c_a, std::string e_n, std::string e_a, std::string j_s_n, std::string j_n, std::string q_n, std::string c_t, std::string w_t, PbsArrangement p_a, PbsSharing p_s): JobScript(t_n_p, m_n_p_p_n, m_c_n, m_c_a, e_n, e_a, j_s_n, j_n, q_n, w_t, ms),
                                                                                                                                                                                                                      f_pbs_script_(j_s_n,std::ios_base::out),
                                                                                                                                                                                                                      cpu_type_(c_t),
                                                                                                                                                                                                                      pbs_arrangement_(p_a), 
                                                                                                                                                                                                                      pbs_sharing_(p_s) {
  setDefaultChunkSize();        
//  generate();
}

PbsScript::PbsScript(const PbsScript & p_s): JobScript(p_s), f_pbs_script_(p_s.getJobScriptName(),std::ios_base::app) {
//  f_pbs_script_ = p_s.f_pbs_script_;
  chunk_size_ = p_s.chunk_size_;
  cpu_type_ = p_s.cpu_type_;
  pbs_arrangement_ = p_s.pbs_arrangement_;
  pbs_sharing_ = p_s.pbs_sharing_;
}


//PbsScript::PbsScript(std::string j_s_n, std::string e_n, std::string e_a, modules::Modules m_o): PbsScript(j_s_n,e_n,e_a,m_o,1,1,"0:01:00",kFree,kExcl) {}


int PbsScript::getChunkSize(void) const {
  return chunk_size_;
}


PbsScript::PbsArrangement PbsScript::getPbsArrangement(void) const {
  return pbs_arrangement_;
}


PbsScript::PbsSharing PbsScript::getPbsSharing(void) const {
  return pbs_sharing_;
}


std::string PbsScript::getPbsArrangementStr(void) const {
  switch (pbs_arrangement_) {
    case kFree: {
      return "free";
      break;
    }
    case kPack: {
      return "pack";
      break; 
    }
    case kScatter: {
      return "scatter";
      break;
    }
    default: {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Do not recognize : " << pbs_arrangement_ << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}


std::string PbsScript::getPbsSharingStr(void) const {
  switch (pbs_sharing_) {
    case kExcl: {
      return "excl";
      break;
    }
    case kShared: {
      return "shared";
      break; 
    }
    default: {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Do not recognize : " << pbs_sharing_ << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}


void PbsScript::setDefaultChunkSize(void) {
  std::string hostname = getHostName();
  if (hostname == "service0" || hostname == "service1" || hostname == "service2" ||
      hostname == "falcon1" || hostname == "falcon2" || hostname == "falconpbs" ||
      hostname == "falconviz") {
    chunk_size_ = 24;
  } else if (hostname == "fpbs" || hostname == "flogin1" || hostname == "flogin2") {
    chunk_size_ = 32;
  } else if (hostname == "bechler") {
    chunk_size_ = 32;
  } else {
    std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Do not recognize hostname = " << hostname << std::endl;
    exit(EXIT_FAILURE);
  }
}


std::string PbsScript::getCpuType(void) const {
  return cpu_type_;
}


void PbsScript::generate(void) {
  int select_size;
//  std::vector<module_type> m = modules_.getModules();
  auto m = getModules();
  select_size = getTotalNumProcs() / getMaxNumProcsPerNode();
  f_pbs_script_ << "#PBS -N " << getJobName() << std::endl;
  f_pbs_script_ << "#PBS -q " << getQueueName() << std::endl;
//  if (getTotalNumCores() <= getChunkSize()) {
  f_pbs_script_ << "#PBS -l select=" << select_size << ":ncpus=" << getChunkSize() << ":mpiprocs=" << getMaxNumProcsPerNode() << ":cputype=" << getCpuType()<< std::endl;
//  }
  f_pbs_script_ << "#PBS -l walltime=" << getWallTime() << std::endl;
  f_pbs_script_ << "#PBS -l place=" << getPbsArrangementStr() << ":" << getPbsSharingStr() << std::endl;
  f_pbs_script_ << "source /etc/profile.d/modules.sh" << std::endl;
  for (auto m_p: m) {
    f_pbs_script_ << "module load " << m_p.first << "/" << m_p.second << std::endl;
  }
  f_pbs_script_ << "cd $PBS_O_WORKDIR" << std::endl;
  if (getMpiCmdName() == "") {
    f_pbs_script_ << getExeName() << " " << getExeArgs() << std::endl;
  } else {
    f_pbs_script_ << getMpiCmdName() << " " << getMpiCmdArgs() << " " << getExeName() << " " << getExeArgs() << std::endl;
  }
}
 

} // namespace jobscript

