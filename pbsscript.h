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
PbsScript sub class of pure abstract base base JobScript.

Date Created: Mon Nov 30 12:54:22 MST 2015

Author: Cormac Garvey

*/

#ifndef JOBSCRIPT_PBSSCRIPT_H_
#define JOBSCRIPT_PBSSCRIPT_H_


#include "jobscript.h"

#include <iostream>
#include <fstream>

#include <cstdlib> // for exit()

namespace jobscript {

class PbsScript: public JobScript {

  public:
    enum PbsArrangement {kFree, kPack, kScatter};
    enum PbsSharing {kExcl, kShared};
    PbsScript(modules::modules_type ms = {{}}, int t_n_p=1, int m_n_p_p_n=1, std::string m_c_n="", std::string m_c_a="", std::string e_n="exe_dummy", std::string e_a="exe_dummy_args", std::string j_s_n="job.pbs", std::string j_n="job", std::string q_n="hpc_support", std::string c_t="broadwell", std::string w_t="0:02:00", PbsArrangement p_a=kFree, PbsSharing p_s=kExcl);
//    PbsScript(std::string, std::string, std::string, modules::Modules m_o);
    PbsScript(const PbsScript &);
//    PbsScript(void) = default;
    virtual ~PbsScript(void) {};
    int getChunkSize(void) const;
    std::string getCpuType(void) const;
    PbsArrangement getPbsArrangement(void) const;
    PbsSharing getPbsSharing(void) const;
    std::string getPbsArrangementStr(void) const;
    std::string getPbsSharingStr(void) const;
    void generate(void) override;

  private:
    void setDefaultChunkSize(void);
    std::ofstream f_pbs_script_;
    int chunk_size_;
    std::string cpu_type_;
    PbsArrangement pbs_arrangement_;
    PbsSharing pbs_sharing_;

}; // class PbsScript


} // namespace jobscript

#endif  // JOBSCRIPT_PBSSCRIPT_H
