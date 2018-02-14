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
HPC Software test suite main program.

Date Created: Wed Nov 11 13:54:15 MST 2015

Author: Cormac Garvey

*/

#include <boost/filesystem.hpp>

#include "generator.h"


int main() {
  boost::filesystem::path cur_dir=boost::filesystem::current_path();
  boost::filesystem::path json_def_file_path("/hpc-common/software/hpcswtest/bin/hpcswtest.json_def");
  std::string json_file_str("hpcswtest.json");
  std::string json_file_path_str;
  std::ofstream dateHost("datehost.out",std::ios::out);
  std::time_t date_result = std::time(NULL);
  char hostname[1024];

  json_file_path_str = cur_dir.string() + "/" + json_file_str;
  boost::filesystem::path json_file_path(json_file_path_str);
  
  if (boost::filesystem::exists(json_file_path)) {
//    std::cout << json_file_path_str << " exists, lets use it" << std::endl;
  } else {
    json_file_path_str = json_def_file_path.string();
//    std::cout << json_file_path << " does not exist, so lets use " << json_file_path_str << std::endl;
  }
  gethostname(hostname, 1023);
  dateHost << std::ctime(&date_result);
  dateHost << hostname << std::endl;

  hpcswtest::Generator gen(json_file_path_str);
  gen.runTests();

}
