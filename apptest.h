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
HPC Software test suite.
AppTest is a subclass of base class HpcSwTest.

Date Created: Fri Nov 20 16:07:13 MST 2015

Author: Cormac Garvey

*/

#ifndef HPCSWTEST_APPTEST_H_
#define HPCSWTEST_APPTEST_H_

#include "hpcswtest.h"
#include "helper.h"
#include "pbsscript.h"


namespace  hpcswtest {


class AppTest: public HpcSwTest {

	public:
		AppTest(const std::string &, const std::string &, const jobscript::PbsScript &, int, const std::string &);
		AppTest(const std::string &, const std::string &, const jobscript::PbsScript &, int);
		virtual ~AppTest(void) {};
		virtual void runTest(void) override;
		void setRunCmd(const std::string &);
		std::string getRunCmd(void) const;
    std::vector<std::string> getInputFileNames(void) const;
    std::vector<jobscript::PbsScript> getPbsScripts(void) const;

  protected:
    virtual std::vector<std::string> calcInputNames(const std::string &, int, const std::string &) const;
    virtual std::string exeAppTest(std::ofstream &, std::ofstream &, const jobscript::PbsScript &, const std::string &) const;

	private:
    std::vector<jobscript::PbsScript> calcPbsScripts(const std::string &, const jobscript::PbsScript &, const std::string &) const;
    std::vector<jobscript::PbsScript> calcPbsScripts(const std::string &, const jobscript::PbsScript &) const;
    std::string calcStarccmSubArgs(const jobscript::PbsScript &, const std::string &, const std::string &) const;
    std::string calcSubArgs(const jobscript::PbsScript &, const std::string &, const std::string &) const;
    std::string calcAbaqusSubArgs(const jobscript::PbsScript &, const std::string &, const std::string &) const;
    std::string calcGaussianSubArgs(const jobscript::PbsScript &, const std::string &, const std::string &) const;
    std::string calcVaspSubArgs(const jobscript::PbsScript &, const std::string &) const;
    std::string calcExeArgs(const jobscript::PbsScript &, const std::string &) const;
		std::string run_cmd_;
    std::vector<std::string> input_file_names_;
    std::vector<jobscript::PbsScript> pbs_scripts_;

}; // class AppTest


} // namespace hpcswtest

#endif  // HPCSWTEST_APPTEST_H
