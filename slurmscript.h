/*

Description
-----------
SlurmScript sub class of pure abstract base base JobScript.

Date Created: Thu Jul 27 17:26:50 MDT 2017

Author: Cormac Garvey

*/

#ifndef JOBSCRIPT_SLURMSCRIPT_H_
#define JOBSCRIPT_SLURMSCRIPT_H_


#include "jobscript.h"

#include <iostream>
#include <fstream>

#include <cstdlib> // for exit()

namespace jobscript {

class SlurmScript: public JobScript {

  public:
    SlurmScript(modules::modules_type ms = {{}}, int t_n_p=1, int m_n_p_p_n=1, std::string m_c_n="", std::string m_c_a="", std::string e_n="exe_dummy", std::string e_a="exe_dummy_args", std::string j_s_n="job.sbatch", std::string j_n="job", std::string q_n="hpc_support", std::string w_t="0:02:00");
    SlurmScript(const SlurmScript &);
    virtual ~SlurmScript(void) {};
    void generate(void) override;

  private:
//    std::ofstream f_slurm_script_;

}; // class SlurmScript


} // namespace jobscript

#endif  // JOBSCRIPT_SLURMSCRIPT_H
