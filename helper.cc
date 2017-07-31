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
HPC Software Testing Suite.
Helper functions

Date Created: Wed Nov 25 11:20:36 MST 2015

Author: Cormac Garvey

*/

#include "helper.h"

#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>


namespace hpcswtest {


std::string exec(const char* cmd) {
  std::string result = "";
  const int BUFSIZE = 1000;
  char buf[BUFSIZE];
  FILE * f = popen( cmd, "r" );
//  std::cout << "(exec) cmd= " << cmd << std::endl;
  if ( f == NULL) {
    std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Could not execute" << std::endl;
    exit(EXIT_FAILURE);
  }
  while( fgets( buf, BUFSIZE,  f ) ) {
    result += buf;
  }
  if (result[result.size()-1] == '\n') {
      result.pop_back();
  }
  return result;
}


modules::module_type findPrimaryModule(const modules::modules_type &my_modules) {
  modules::module_type my_module_local = {"default","default"};
//  std::cout << "(helper findPrimaryModule enter)" << std::endl;
  if (!my_modules.empty()) {
    my_module_local.first = my_modules[my_modules.size()-1].first;
    my_module_local.second = my_modules[my_modules.size()-1].second;
  }
//  std::cout << "(helper findPrimaryModule enter) name=" << my_module_local.first << " version=" << my_module_local.second << std::endl;
  return my_module_local;
}

//Why does lambda not work??
void removeNoneModules(modules::modules_type &my_modules) {
  modules::module_type m_t = {"none","none"};
//  modules.erase(std::remove(modules.begin(), modules.end(),[](modules::module_type x){return true;}),modules.end());
//  modules.erase(std::remove(modules.begin(), modules.end(), ""),modules.end());
    auto e = std::remove(my_modules.begin(), my_modules.end(), m_t);
    my_modules.erase(e,my_modules.end());
//    auto e2 = std::remove(my_modules.begin(), my_modules.end(), [](modules::module_type x){return true;});
//    auto e2 = std::remove(my_modules.begin(), my_modules.end(), [](std::pair<std::string,std::string> x){return x.first == "none";});
//    auto e2 = std::remove(my_modules.begin(), my_modules.end(), [](auto x){return true;});
}


std::string modules_string(modules::modules_type modules) {

  std::string cmd_str;
  
  if (!modules.empty()) {
    cmd_str = "module purge;module load pbs;module load " + module_name_version(modules[0]); 
    for (auto pr=modules.begin()+1; pr != modules.end();pr++) {
     cmd_str = cmd_str + " " + module_name_version(*pr);
    } 
  } 
//  cmd_str = cmd_str + " 2>&1";
  return cmd_str;
}


bool modules_load(std::ofstream &flog, modules::modules_type modules, std::string &result) {
//  std::cout << "(modules_load) modules.size() = " << modules.size() << std::endl;
//  removeNoneModules(modules);
  if (modules.size() > 0) {
    std::string cmd_str = modules_string(modules) + " 2>&1";
 // std::cout << "(modules_load) " << cmd_str << std::endl;
    result = exec(cmd_str.c_str());
    std::regex error_regex("error", std::regex_constants::icase);
    if (std::regex_search(result, error_regex)) {
      flog <<  cmd_str << " : failed" << std::endl;
      flog <<  result << std::endl;
      return false;
  } else {
      flog <<  cmd_str << " : passed" << std::endl;
      flog <<  result << std::endl;
      return true;
    }
  } else {
//    std::cout << "(modules_load) exit modules.size() = " << modules.size() << std::endl;
      return true;
  }
}


bool module_load(std::ofstream &flog, modules::module_type module, std::string &result ) {
  std::string cmd;
  cmd = "module load " + module.first + "/" + module.second + " 2>&1";
  result = exec(cmd.c_str());
//  std::cerr << "module_load result=" << result << std::endl;
  std::regex error_regex("error", std::regex_constants::icase);
  if (std::regex_search(result, error_regex)) {
//     std::cerr << "Module load failed" << std::endl;
    return false;
  } else {
//     std::cerr << "Module load was successful" << std::endl;
    return true;
  }
}


std::string module_name_version(modules::module_type m_t) {
  return m_t.first + "/" + m_t.second;
}


std::string getClusterName(void) {
  char hostname[1024];
  std::string cluster_name_tmp;
  gethostname(hostname, 1023);
  cluster_name_tmp = hostname;
  if (cluster_name_tmp == "service0" || cluster_name_tmp == "service1" || cluster_name_tmp == "service2" ||
      cluster_name_tmp == "falcon1" || cluster_name_tmp == "falcon2" || cluster_name_tmp == "falconpbs") {
    cluster_name_tmp = "falcon";
  } else if (cluster_name_tmp == "flogin1" || cluster_name_tmp == "flogin2" || cluster_name_tmp == "fpbs") {
    cluster_name_tmp = "fission";
  } else if (cluster_name_tmp == "bechler") {
    cluster_name_tmp = "bechler";
  } else if (cluster_name_tmp == "falconviz") {
    cluster_name_tmp = "falconviz";
  } else {
    std::cout << "Error:(" << __FILE__ <<"," << __LINE__ << ") Do Not recognize hostname " << cluster_name_tmp << std::endl;
    exit(EXIT_FAILURE);
  }
  return cluster_name_tmp;
}


void checkSubmitResult(const std::string &result, std::ofstream &flog, std::ofstream &fresult) {
//  std::cout << result << std::endl;
  std::regex script_regex(R"(^\d+)", std::regex_constants::ECMAScript | std::regex_constants::icase);
  if (std::regex_search(result, script_regex) && result.size() > 0){
    flog << "Job " << result << " submitted correctly," << std::endl;
    std::cout << "job " << result << " submitted correctly" << std::endl;
    fresult << removeSuffixExt(result) << std::endl;
  } else {
    flog << "Error: job submitted incorrectly" << std::endl;
    fresult << "Error: job submitted incorrectly" << std::endl;
    std::cout << "Error: job submitted incorrectly" << std::endl;
    flog << result << std::endl;
  }
}


std::string removeSuffixExt(std::string str) {
  auto period_loc = str.find("."); 
//  std::cout << "(removeSuffixExt) " << pbs_str << " " << period_loc << std::endl; 
  str.erase(str.begin()+period_loc, str.end());
  return str; 
}


void createFileFromStr(std::string file_name, std::string content) {
  std::ofstream f_file(file_name, std::ios_base::out);
  f_file << content << std::endl;
  f_file.close();
}


std::string subPbsScript(std::ofstream &flog, jobscript::PbsScript &pbs_script) {
  std::string script_cmd_result;
  std::string script_cmd;

  pbs_script.generate();
//  std::cout << pbs_script.getJobScriptName() << std::endl;
  script_cmd = "qsub -P hpc " + pbs_script.getJobScriptName() + " 2>&1";
  flog << "Submit Command: " << script_cmd << std::endl;
  script_cmd_result = exec(script_cmd.c_str());
  return script_cmd_result;
}


std::string replaceStr(std::string str_orig, const std::string str_out, const std::string str_in) {
//  std::cout << "(replaceStr) str_orig = " << str_orig << " str_out = " << str_out << " str_in = " << str_in << std::endl;
  auto pos_out = str_orig.find(str_out);
  if (str_orig == "none") {
    str_orig = "";
  } else if (pos_out != std::string::npos) {
//    std::cout << "(replaceStr) found string to replace" << std::endl;
    str_orig.replace(pos_out, str_out.size(), str_in);
  }
  return str_orig;
}


void makeDir(std::string dir_path) {
  boost::filesystem::create_directories(dir_path);
//  std::cout << "(makeDir) " << boost::filesystem::current_path() << std::endl;
}


void changeDir(std::string dir_path) {
  boost::filesystem::current_path(dir_path);
//  std::cout << "(changeDir) " << boost::filesystem::current_path() << std::endl;
}


void copyFile(std::string source_path, std::string dest_path) {
//  boost::filesystem::copy_file(source_path, dest_path, boost::filesystem::copy_option::overwrite_if_exists);
//  boost::filesystem::copy_file(source_path, dest_path);
  if (!boost::filesystem::exists(dest_path)) {
    boost::filesystem::copy(source_path, dest_path);
  }
}


void modifyFile(std::string file_name, std::vector<std::string> out_strs, std::vector<std::string> in_strs) {
//  std::cout << "(modifyFile) file_name = " << file_name << std::endl;
  std::string line_local;
  std::string new_line_local;
  std::ifstream f_in(file_name);
  std::ofstream f_out(file_name + "_tmp");
  boost::filesystem::path p_file_name(file_name);
  int i;
  while (getline(f_in, line_local)) {
//    std::cout << line_local << std::endl;
    i = 0;
    for (auto out_str: out_strs) {
      auto in_str = in_strs[i];
      new_line_local = replaceStr(line_local,out_str, in_str);
      ++i;
    }
    f_out << new_line_local << std::endl; 
  }
  f_in.close();
//  std::cout << boost::filesystem::current_path() << std::endl;
//  std::cout << boost::filesystem::remove(p_file_name) << std::endl;
  boost::filesystem::rename(file_name + "_tmp", file_name);
}


bool strSizeZero(std::string str) {
  if (str.size() == 0) {
    return true;
  } else {
    return false;
  }
}


} // namespace hpcswtest

