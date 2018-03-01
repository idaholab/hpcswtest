/*

Description
-----------
SlurmScript sub class source code.

Date Created: Thu Jul 27 17:20:29 MDT 2017

Author: Cormac Garvey

*/

#include "slurmscript.h"


namespace jobscript {


SlurmScript::SlurmScript(modules::modules_type ms, int t_n_p, int m_n_p_p_n, std::string m_c_n, std::string m_c_a, std::string e_n, std::string e_a, std::string j_s_n, std::string j_n, std::string q_n, std::string w_t): JobScript(t_n_p, m_n_p_p_n, m_c_n, m_c_a, e_n, e_a, j_s_n, j_n, q_n, w_t, ms) {}


SlurmScript::SlurmScript(const SlurmScript & p_s): JobScript(p_s) {}


void SlurmScript::generate(void) {
  auto m = getModules();
  std::ofstream f_slurm_script(getJobScriptName(),std::ios_base::out);
  
  f_slurm_script << "#!/bin/bash " << std::endl;
  f_slurm_script << "#SBATCH --output=" << getJobName() << ".o%A" << std::endl;
  f_slurm_script << "#SBATCH --error=" << getJobName() << ".e%A" << std::endl;
  f_slurm_script << "#SBATCH --job-name=" << getJobName() << std::endl;
  f_slurm_script << "#SBATCH --partition=" << getQueueName() << std::endl;
  f_slurm_script << "#SBATCH --ntasks=" << getTotalNumProcs() << std::endl;
  f_slurm_script << "#SBATCH --ntasks-per-node=" << getMaxNumProcsPerNode() << std::endl;
  f_slurm_script << "#SBATCH --time=" << getWallTime() << std::endl;
  for (auto m_p: m) {
    f_slurm_script << "module load " << m_p.first << "/" << m_p.second << std::endl;
  }
  if (getMpiCmdName().empty()) {
    f_slurm_script << getExeName() << " " << getExeArgs() << std::endl;
  } else {
    f_slurm_script << getMpiCmdName() << " " << getMpiCmdArgs() << " " << getExeName() << " " << getExeArgs() << std::endl;
  }
}
 

} // namespace jobscript

