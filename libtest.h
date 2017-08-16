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
LibTest is a subclass of SrcTest base class.

Date Created: Fri Nov 20 14:26:33 MST 2015

Author: Cormac Garvey

*/

#ifndef HPCSWTEST_LIBTEST_H_
#define HPCSWTEST_LIBTEST_H_

#include "srctest.h"

namespace hpcswtest {

class LibTest: public SrcTest {

	public:
		LibTest(const std::string &, const jobscript::JOBSCRIPT &, const std::string &, const std::string &, const std::string &, int, int, int, const std::string &, const std::string &, const std::string &, const std::string &, const std::string &, const std::string &);
		virtual ~LibTest(void) {};
    virtual void runTest(void) override;
		void setLinkLibs(const std::string &);
		std::string getLinkLibs(void);

	private:
		std::string link_libs_;

}; // class LibTest

} // namespace hpcswtest

#endif  // HPCSWTEST_LIBTEST_H
