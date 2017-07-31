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
HPC Software testing suite.
Generator concrete class.
Reads json file and creates test objects.

Date Created: Tue Dec  8 08:51:17 MST 2015

Author: Cormac Garvey

*/

#ifndef HPCSWTEST_GENERATOR_H_
#define HPCSWTEST_GENERATOR_H_

#include "compilertest.h"
#include "mpitest.h"
#include "blastest.h"
#include "boosttest.h"
#include "mcnptest.h"
#include "mcnpxtest.h"
#include "scaletest.h"
#include "scale62test.h"
#include "heliostest.h"
#include "helioslint64test.h"
#include "vasptest.h"
#include "mc21test.h"
#include "abaqustest.h"
#include "serpenttest.h"
#include "cthtest.h"
#include "starccmtest.h"
#include "gaussiantest.h"
#include "matlabtest.h"
#include "python2test.h"
#include "python3test.h"

#include <memory>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


namespace hpcswtest {


class Generator {

  public:
    Generator(std::string);
    ~Generator(void);
    void runTests(void);

  private:
    void createTestObjects(void);
    void getCompilerJsonData(boost::property_tree::ptree::value_type, std::string &, std::string &, std::string &, std::string &, std::string &, std::string &, std::string &, std::string &, std::string &, std::string &, std::string &);
    void getModuleNameVersionJsonData(boost::property_tree::ptree::value_type, std::string &, std::string &);
    void getRunScriptJsonData(boost::property_tree::ptree::value_type, std::string &);
    void getExtraModJsonData(boost::property_tree::ptree::value_type, int, std::string &, std::string &);
    void getExeExeArgsJsonData(boost::property_tree::ptree::value_type, std::string &, std::string &);
    void getMpiCmdNameArgsJsonData(boost::property_tree::ptree::value_type, std::string &, std::string &);
    void getHeliosExesJsonData(boost::property_tree::ptree::value_type, std::string &, std::string &, std::string &);
    void getPythonModulesJsonData(boost::property_tree::ptree::value_type, std::vector<std::string> &);
    std::string json_file_name_;
    std::vector<HpcSwTest *> tests_;

};


} // namespace hpcswtest

#endif  // HPCSWTEST_GENERATOR_H
