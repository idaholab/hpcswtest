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
HPC Software stack testing suite
helper functions source code

Date Created: Wed Nov 25 11:31:01 MST 2015

Author: Cormac Garvey

*/

#ifndef HPCSWTEST_HELPER_H_
#define HPCSWTEST_HELPER_H_

#include "hpcswtest.h"

#include <string>
#include <regex>
//#include <utility>
//#include <algorithm>

#include <boost/filesystem.hpp>

#include <cstdlib>  // for exit()
//#include <cstdio>


namespace hpcswtest {


std::string exec(const char *);
bool module_load(std::ofstream &, modules::module_type, std::string &);
std::string module_name_version(modules::module_type);
std::string modules_string(modules::modules_type);
bool modules_load(std::ofstream &, modules::modules_type, std::string &);
//std::string getClusterName(void);
void checkSubmitResult(const std::string &, std::ofstream &, std::ofstream &);
std::string removeSuffixExt(std::string);
void createFileFromStr(std::string, std::string);
std::string subJobScript(std::ofstream &, jobscript::JOBSCRIPT &);
std::string replaceStr(std::string, const std::string, std::string);
void makeDir(std::string);
void changeDir(std::string);
void copyFile(std::string, std::string);
void modifyFile(std::string, std::vector<std::string>, std::vector<std::string>);
boost::filesystem::path getCwd(void);
bool strSizeZero(std::string);
void removeNoneModules(modules::modules_type &);
modules::module_type findPrimaryModule(const modules::modules_type &); 

} // namespace hpcswtest

#endif  // HPCSWTEST_HELPER_H

