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
JobScript abstract base class.

Date Created: Fri Nov 27 18:57:46 MST 2015

Author: Cormac Garvey

*/


#ifndef JOBSCRIPT_JOBSCRIPT_H_
#define JOBSCRIPT_JOBSCRIPT_H_

#include "modules.h"

#include <string>

#include <unistd.h>

#ifdef SLURM
#define JOBSCRIPT SlurmScript
#else
#define JOBSCRIPT PbsScript
#endif

namespace jobscript {


class JobScript {

  public:
    JobScript(int t_n_p, int m_n_p_p_n, std::string m_c_n, std::string m_c_a, std::string e_n, std::string e_a, std::string j_s_n, std::string j_n, std::string q_n, std::string w_t, modules::modules_type ms): total_num_procs_(t_n_p),
                                                                                                                                                                           max_num_procs_per_node_(m_n_p_p_n), 
                                                                                                                                                                           mpi_cmd_name_(m_c_n),
                                                                                                                                                                           mpi_cmd_args_(m_c_a),
                                                                                                                                                                           exe_name_(e_n),
                                                                                                                                                                           exe_args_(e_a),
                                                                                                                                                                           job_script_name_(j_s_n),
                                                                                                                                                                           job_name_(j_n),
                                                                                                                                                                           queue_name_(q_n),
                                                                                                                                                                           host_name_(setHostName()),
                                                                                                                                                                           wall_time_(w_t),
                                                                                                                                                                           modules_(ms) {};

    JobScript(const JobScript &);
    virtual ~JobScript() {};
//    virtual void generate(void) = 0;
    int getTotalNumProcs(void) const;
    int getMaxNumProcsPerNode(void) const;
    void setExeName(std::string);
    void setExeArgs(std::string);
    std::string getWallTime(void) const;
    std::string getHostName(void) const;
    std::string getMpiCmdName(void) const;
    std::string getMpiCmdArgs(void) const;
    std::string getExeName(void) const;
    std::string getExeArgs(void) const;
    std::string getJobScriptName(void) const;
    std::string getJobName(void) const;
    std::string getQueueName(void) const;
    modules::modules_type getModules(void) const;
    virtual void generate(void) = 0;

  private:
    std::string setHostName(void);
    std::string job_script_name_;
    std::string job_name_;
    int total_num_procs_;
    int max_num_procs_per_node_;
    std::string host_name_;
    std::string queue_name_;
    std::string wall_time_;
    std::string mpi_cmd_name_;
    std::string mpi_cmd_args_;
    std::string exe_name_;
    std::string exe_args_;
    modules::modules_type modules_;

};


} // namespace jobscript

#endif  // JOBSCRIPT_JOBSCRIPT_H
