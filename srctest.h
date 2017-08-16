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
----------
SrcTest is subclass of the abstract base class HpcSwTest.
Part of the HPC Software Test Suite.

Date Created: Wed Nov 11 11:44:34 MST 2015

Author: Cormac Garvey

*/

#ifndef HPCSWTEST_SRCTEST_H_
#define HPCSWTEST_SRCTEST_H_

#include "hpcswtest.h"
#include "helper.h"

#include <regex>


namespace hpcswtest {


class SrcTest : public HpcSwTest {

  public:
    SrcTest(const std::string &, const jobscript::JOBSCRIPT &, const std::string &, const std::string &, const std::string &, int, int, int, const std::string &, const std::string &, const std::string &, const std::string &, const std::string &, const std::string &);
    virtual ~SrcTest() {};
    virtual void runTest(void) override;
    void setCName(const std::string &);
    void setCppName(const std::string &);
    void setFName(const std::string &);
    void setCFlags(const std::string &);
    void setCppFlags(const std::string &);
    void setFFlags(const std::string &);
    void setCLinkLibs(const std::string &);
    void setCppLinkLibs(const std::string &);
    void setFLinkLibs(const std::string &);
    int numCSrcName(void) const;
    int numCppSrcName(void) const;
    int numFSrcName(void) const;
    std::string getCName(void) const;
    std::string getCppName(void) const;
    std::string getFName(void) const;
    std::string getCSrcName(int) const;
    std::string getCppSrcName(int) const;
    std::string getFSrcName(int) const;
    std::string getCExeName(int) const;
    std::string getCppExeName(int) const;
    std::string getFExeName(int) const;
    std::string getCFlags(void) const;
    std::string getCppFlags(void) const;
    std::string getFFlags(void) const;
    std::string getCLinkLibs(void) const;
    std::string getCppLinkLibs(void) const;
    std::string getFLinkLibs(void) const;
    std::vector<jobscript::JOBSCRIPT> getCJobScripts(void) const;
    std::vector<jobscript::JOBSCRIPT> getCppJobScripts(void) const;
    std::vector<jobscript::JOBSCRIPT> getFJobScripts(void) const;

  protected:
    virtual std::vector<std::string> calcCSrcNames(int) const;
    virtual std::vector<std::string> calcCppSrcNames(int) const;
    virtual std::vector<std::string> calcFSrcNames(int) const;
    virtual std::vector<std::string> calcCExeNames(int) const;
    virtual std::vector<std::string> calcCppExeNames(int) const;
    virtual std::vector<std::string> calcFExeNames(int) const;
    std::string compileCmd(const modules::modules_type &, const std::string &, const std::string &, const std::string &, const std::string &, const std::string &) const;
    std::string compileTest(std::ofstream &, const jobscript::JOBSCRIPT &, const std::string &, const std::string &, const std::string &, const std::string &, const std::string &, const std::string &) const;
    void checkCompileResult(const std::string &, const std::string &, const std::string &, const std::string &, const std::string &, std::ofstream &, std::ofstream &) const;
    virtual std::string srcExeTest(std::ofstream &flog, jobscript::JOBSCRIPT &job_script) const;

  private:
    std::vector<jobscript::JOBSCRIPT> calcCJobScripts(const jobscript::JOBSCRIPT &p_s) const;
    std::vector<jobscript::JOBSCRIPT> calcCppJobScripts(const jobscript::JOBSCRIPT &p_s) const;
    std::vector<jobscript::JOBSCRIPT> calcFJobScripts(const jobscript::JOBSCRIPT &p_s) const;
    std::string c_name_;
    std::string cpp_name_;
    std::string f_name_;
    std::string c_flags_;
    std::string cpp_flags_;
    std::string f_flags_;
    std::string c_link_libs_;
    std::string cpp_link_libs_;
    std::string f_link_libs_;
    std::vector<std::string> c_src_names_;
    std::vector<std::string> cpp_src_names_;
    std::vector<std::string> f_src_names_;
    std::vector<std::string> c_exe_names_;
    std::vector<std::string> cpp_exe_names_;
    std::vector<std::string> f_exe_names_;
    std::vector<std::string> c_exe_args_;
    std::vector<std::string> cpp_exe_args_;
    std::vector<std::string> f_exe_args_;
    std::vector<jobscript::JOBSCRIPT> c_job_scripts_;
    std::vector<jobscript::JOBSCRIPT> cpp_job_scripts_;
    std::vector<jobscript::JOBSCRIPT> f_job_scripts_;

}; // class SrcTest


} // namespace hpcswtest

#endif  // HPCSWTEST_SRCTEST_H
