/*

Description
-----------
SlurmScript sub class source code.

Date Created: Thu Jul 27 17:20:29 MDT 2017

Author: Cormac Garvey

*/

#include "slurmscript.h"


namespace jobscript {


SlurmScript::SlurmScript(modules::modules_type ms, int t_n_p, int m_n_p_p_n, std::string m_c_n, std::string m_c_a, std::string e_n, std::string e_a, std::string j_s_n, std::string j_n, std::string q_n, std::string w_t): JobScript(t_n_p, m_n_p_p_n, m_c_n, m_c_a, e_n, e_a, j_s_n, j_n, q_n, w_t, ms),
                                                                                                                                                                                                                      f_slurm_script_(j_s_n,std::ios_base::out) {
}


SlurmScript::SlurmScript(const SlurmScript & p_s): JobScript(p_s), f_slurm_script_(p_s.getJobScriptName(),std::ios_base::app) {
}


void SlurmScript::generate(void) {
  auto m = getModules();
  
  f_slurm_script_ << "#!/bin/bash " << std::endl;
  f_slurm_script_ << "#SBATCH --output=" << getJobName() << ".o%A" << std::endl;
  f_slurm_script_ << "#SBATCH --error=" << getJobName() << ".e%A" << std::endl;
  f_slurm_script_ << "#SBATCH --job-name=" << getJobName() << std::endl;
  f_slurm_script_ << "#SBATCH --partition=" << getQueueName() << std::endl;
  f_slurm_script_ << "#SBATCH --ntasks=" << getTotalNumProcs() << std::endl;
  f_slurm_script_ << "#SBATCH --ntasks-per-node=" << getMaxNumProcsPerNode() << std::endl;
  f_slurm_script_ << "#SBATCH --time=" << getWallTime() << std::endl;
  for (auto m_p: m) {
    f_slurm_script_ << "module load " << m_p.first << "/" << m_p.second << std::endl;
  }
  if (getMpiCmdName() == "") {
    f_slurm_script_ << getExeName() << " " << getExeArgs() << std::endl;
  } else {
    f_slurm_script_ << getMpiCmdName() << " " << getMpiCmdArgs() << " " << getExeName() << " " << getExeArgs() << std::endl;
  }
}
 

} // namespace jobscript

