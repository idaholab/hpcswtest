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
HPC Software Test Suite.
class BoostTest source code.

Date Created: Mon Dec 14 16:34:24 MST 2015

Author: Cormac Garvey

*/

#include "boosttest.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> BoostTest::c_boost_srcs_ = {};


const std::vector<std::string> BoostTest::cpp_boost_srcs_ = {
R"(
#include <iostream>
#include <sstream> 
#include <iterator>
#include <algorithm>
#include <boost/filesystem.hpp>

#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    std::ostringstream ss;
    ss << getpid();
    std::string tmp_dir = "tmp_dir_" + ss.str();
    boost::filesystem::create_directory(tmp_dir);
    boost::filesystem::path p (tmp_dir);   // p reads clearer than argv[1] in the following code

    try
    {
      if (exists(p))    // does p actually exist?
      {
       if (is_regular_file(p))        // is p a regular file?
          std::cout << p << " size is " << file_size(p) << '\n';

       else if (is_directory(p))      // is p a directory?
       {
          std::cout << "Working" << std::endl;
       }
       else
          std::cout << p << " exists, but is neither a regular file nor a directory\n";
      }
      else
        std::cout << p << " does not exist\n";
    }

    catch (const boost::filesystem::filesystem_error& ex)
    {
     std::cout << ex.what() << '\n';
    }
    boost::filesystem::remove_all(tmp_dir);

   return 0;
}
)"
}; // vector cpp_boost_srcs


const std::vector<std::string> BoostTest::f_boost_srcs_ = {}; 




BoostTest::BoostTest(const jobscript::JOBSCRIPT &p_s, const std::string &c_n, const std::string &cpp_n, const std::string &f_n, const std::string &c_f, const std::string &cpp_f, const std::string &f_f, const std::string &c_l_l, const std::string &cpp_l_l, const std::string &f_l_l): LibTest("boost", p_s, c_n, cpp_n, f_n, c_boost_srcs_.size(), cpp_boost_srcs_.size(), f_boost_srcs_.size(), c_f, cpp_f, f_f, c_l_l, cpp_l_l, f_l_l),
												log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
												result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
												flog_(log_file_name_,std::ios_base::app),
												fresult_(result_file_name_,std::ios_base::app) {}


void BoostTest::runTest() {

  std::string cmd_result;
  std::string script_cmd_result;
//  std::cout << "Execute runTest member function from BoostTest object " << __FILE__ << "\t" <<__LINE__ << std::endl;
  if (!flog_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << log_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  if (!fresult_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << result_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  int c_i = 0;
  for (auto c_boost_src: c_boost_srcs_) {
    cmd_result = compileTest(flog_, getCJobScripts()[c_i], c_boost_srcs_[c_i], getCName(), getCFlags(), getCSrcName(c_i), getCExeName(c_i), getCLinkLibs());
    checkCompileResult(cmd_result, getCName(), getCJobScripts()[c_i].getModules()[getCJobScripts()[c_i].getModules().size()-1].first, getCJobScripts()[c_i].getModules()[getCJobScripts()[c_i].getModules().size()-1].second, getCJobScripts()[c_i].getJobName(), flog_, fresult_);
    script_cmd_result = srcExeTest(flog_, getCJobScripts()[c_i]);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
  c_i = 0;
  for (auto cpp_boost_src: cpp_boost_srcs_) {
    cmd_result = compileTest(flog_, getCppJobScripts()[c_i], cpp_boost_srcs_[c_i], getCppName(), getCppFlags(), getCppSrcName(c_i), getCppExeName(c_i), getCppLinkLibs());
    checkCompileResult(cmd_result, getCppName(), getCppJobScripts()[c_i].getModules()[getCppJobScripts()[c_i].getModules().size()-1].first, getCppJobScripts()[c_i].getModules()[getCppJobScripts()[c_i].getModules().size()-1].second, getCppJobScripts()[c_i].getJobName(), flog_, fresult_);
    script_cmd_result = srcExeTest(flog_, getCppJobScripts()[c_i]);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
  c_i = 0;
  for (auto f_boost_src: f_boost_srcs_) {
    cmd_result = compileTest(flog_, getFJobScripts()[c_i], f_boost_srcs_[c_i], getFName(), getFFlags(), getFSrcName(c_i), getFExeName(c_i), getFLinkLibs());
    checkCompileResult(cmd_result, getFName(), getFJobScripts()[c_i].getModules()[getFJobScripts()[c_i].getModules().size()-1].first, getFJobScripts()[c_i].getModules()[getFJobScripts()[c_i].getModules().size()-1].second, getFJobScripts()[c_i].getJobName(), flog_, fresult_);
    script_cmd_result = srcExeTest(flog_, getFJobScripts()[c_i]);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    ++c_i;
  }
}


} // namespace hpcswtest

