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
HPC Software stack test suite, pure abstract base class.

Date Created: Tue Nov 10 11:34:09 MST 2015

Author: Cormac Garvey

*/

#ifndef HPCSWTEST_HPCSWTEST_H_
#define HPCSWTEST_HPCSWTEST_H_

#ifdef SLURM
#include "slurmscript.h"
#else
#include "pbsscript.h"
#endif

#include <string>
#include <vector>

#include <unistd.h>

namespace hpcswtest {

//typedef std::pair<std::string, std::string> module_type;

class HpcSwTest {

	public:
    enum TestResult {kPass, kFail, kCheck, kRunning};
    HpcSwTest(const std::string &s);
    virtual ~HpcSwTest() {};
    virtual void runTest(void) = 0;
    void setTestName(const std::string &);
    void setHostName(const std::string &);
    std::string getHostName(void) const;
    std::string getTestName(void) const;
    int getTestObjectCount(void) const;
    void setTestNumber(int);
    int getTestNumber(void);

  private:
    static int test_object_count_;
    int test_number_;
    std::string test_name_;
    std::string host_name_;

}; // class HpcSwTest

} // namespace hpcswtest

#endif  // HPCSWTEST_HPCSWTEST_H

