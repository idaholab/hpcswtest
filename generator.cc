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
HPCSoftware testing suite.

Date Created: Tue Dec  8 09:20:23 MST 2015

Author: Cormac Garvey

*/

#include "generator.h"


namespace hpcswtest {


Generator::Generator(std::string j_f_n): json_file_name_(j_f_n) {
  createTestObjects();
}


Generator::~Generator(void) {
  for (auto p: tests_) {
    delete p;
  }
}


void Generator::getCompilerJsonData(boost::property_tree::ptree::value_type pt, std::string &module_name, std::string &module_version, std::string &c_name, std::string &cpp_name, std::string &f_name, std::string &c_flags, std::string &cpp_flags, std::string &f_flags, std::string &c_link_libs, std::string &cpp_link_libs, std::string &f_link_libs) {
  module_name =  pt.second.get<std::string>("module_name");
  module_version =  pt.second.get<std::string>("module_version");
//  std::cout << "(Generator::Generator)" << pt.second.get<std::string>("module_name") << std::endl;
//  std::cout << "(Generator::Generator)" << pt.second.get<std::string>("module_version") << std::endl;
  c_name =  pt.second.get<std::string>("c_name");
  cpp_name =  pt.second.get<std::string>("cpp_name");
  f_name =  pt.second.get<std::string>("f_name");
  c_flags =  pt.second.get<std::string>("c_flags");
  cpp_flags =  pt.second.get<std::string>("cpp_flags");
  f_flags =  pt.second.get<std::string>("f_flags");
  c_link_libs =  pt.second.get<std::string>("c_link_libs");
  cpp_link_libs =  pt.second.get<std::string>("cpp_link_libs");
  f_link_libs =  pt.second.get<std::string>("f_link_libs");
}


void Generator::getModuleNameVersionJsonData(boost::property_tree::ptree::value_type pt, std::string &module_name, std::string &module_version) {
  module_name =  pt.second.get<std::string>("module_name");
  module_version =  pt.second.get<std::string>("module_version");
}


void Generator::getRunScriptJsonData(boost::property_tree::ptree::value_type pt, std::string &run_script) {
  run_script =  pt.second.get<std::string>("run_script");
}

void Generator::getLibraryNameJsonData(boost::property_tree::ptree::value_type pt, std::string &library_name) {
  library_name =  pt.second.get<std::string>("library_name");
}


void Generator::getExtraModJsonData(boost::property_tree::ptree::value_type pt, int extra_module_num, std::string &extra_module_name, std::string &extra_module_version) {
  extra_module_name =  pt.second.get<std::string>("extra_module_name" + std::to_string(extra_module_num));
  extra_module_version =  pt.second.get<std::string>("extra_module_version" + std::to_string(extra_module_num));
//  if (extra_module_name == "none") {
//    extra_module_name = "";
//  }
  if (extra_module_name != "none" && extra_module_version == "none") {
    extra_module_version = "";
  }
}


void Generator::getExeExeArgsJsonData(boost::property_tree::ptree::value_type pt, std::string &exe_name, std::string &exe_args) {
  exe_name =  pt.second.get<std::string>("exe_name");
  exe_args =  pt.second.get<std::string>("exe_args");
  if (exe_args == "none") {
    exe_args = "";
  }
}


void Generator::getMpiCmdNameArgsJsonData(boost::property_tree::ptree::value_type pt, std::string &mpi_cmd_name, std::string &mpi_cmd_args) {
  mpi_cmd_name =  pt.second.get<std::string>("mpi_cmd_name");
  mpi_cmd_args =  pt.second.get<std::string>("mpi_cmd_args");
  if (mpi_cmd_name == "none") {
    mpi_cmd_name = "";
  }
  if (mpi_cmd_args == "none") {
    mpi_cmd_args = "";
  }
}


void Generator::getHeliosExesJsonData(boost::property_tree::ptree::value_type pt, std::string &aurora_exe_name, std::string &helios_exe_name, std::string &zenith_exe_name) {
  aurora_exe_name =  pt.second.get<std::string>("aurora_exe_name");
  helios_exe_name =  pt.second.get<std::string>("helios_exe_name");
  zenith_exe_name =  pt.second.get<std::string>("zenith_exe_name");
}


void Generator::getPythonModulesJsonData(boost::property_tree::ptree::value_type pt, std::vector<std::string> &python_modules) {
  std::string python_modules_str;
  std::string python_module;
  python_modules_str =  pt.second.get<std::string>("python_modules");
  if (python_modules_str != "none") {
    std::stringstream python_modules_ss(python_modules_str);
    while (python_modules_ss >> python_module) {
     python_modules.push_back(python_module);
    }
  }
}


std::string Generator::getClusterNameJsonData(boost::property_tree::ptree sc) {
  std::string clustername;
  boost::property_tree::ptree cluster_node;
  bool found = false;
  char hostname[1024];
  std::string hostname_str;
  gethostname(hostname, 1023);
  hostname_str = hostname;
  for (const auto  &clusters: sc) {
      clustername = std::string(clusters.first.data());
      cluster_node = sc.get_child(std::string(clusters.first.data())+".login_nodes");
      for (const auto  &c: cluster_node) {
//          std::cout << "(Generator::getClusterNameJsonData)" << "compare " << hostname_str << " with " << std::string(c.second.data()) << std::endl;
          if (hostname_str == std::string(c.second.data())) {
//             std::cout << "(Generator::getClusterNameJsonData)" << "found host" << std::endl;
             found = true;
             break;
          }
      }
      if (found) break;
  }
  if (!found) {
     std::cout << "Warning: Could not determine what cluster you are testing on, check your json file." << std::endl;
  }
  return clustername;
}


int Generator::getPbsMaxChunkSizeJsonData(std::string clustername, boost::property_tree::ptree sc) {
    int pbs_max_chunk_size;
    pbs_max_chunk_size = sc.get<int>(clustername+".pbs_max_chunk_size");
    return  pbs_max_chunk_size;
}


void Generator::createTestObjects(void) {
  std::string module_name;
  std::string module_version;
  std::string c_name;
  std::string cpp_name;
  std::string f_name;
  std::string c_flags;
  std::string cpp_flags;
  std::string f_flags;
  std::string c_link_libs;
  std::string cpp_link_libs;
  std::string f_link_libs;
  std::string run_script;
  std::string extra_module_name1;
  std::string extra_module_version1;
  std::string extra_module_name2;
  std::string extra_module_version2;
  std::string exe_name;
  std::string exe_args;
  char * hpcswtest_queue_env;
  char * cpu_type_env;
  std::string hpcswtest_queue = "hpc_support";
  std::string cpu_type = "dummy";
//  std::cout << "(Enter Generator::Generator)" << std::endl;
  std::string cluster_name;
  boost::property_tree::ptree pt;
  boost::property_tree::ptree sc;
  int pbs_max_chunk_size;
  if (hpcswtest_queue_env = std::getenv("HPCSWTEST_QUEUE")) {
     hpcswtest_queue = hpcswtest_queue_env;
  }
  if (cpu_type_env = std::getenv("HPCSWTEST_CPUTYPE")) {
     cpu_type = cpu_type_env;
  }
//  std::cout << "(Generator::Generator) json_file_name_ = " << json_file_name_ << std::endl;
  boost::property_tree::read_json(json_file_name_, pt);
  sc = pt.get_child("system_configuration");
  cluster_name = Generator::getClusterNameJsonData(sc);
//  std::cout << "(Generator::Generator) cluster_name = " << cluster_name << std::endl;
#ifndef SLURM
  pbs_max_chunk_size = Generator::getPbsMaxChunkSizeJsonData(cluster_name, sc);
//  std::cout << "(Generator::Generator) pbs_max_chunk_size = " << pbs_max_chunk_size << std::endl;
#endif

  for (auto v: pt.get_child(cluster_name)) {
//    std::cout << "(Generator::Generator) Test key= " << v.first << std::endl;
    for (auto v2: pt.get_child(cluster_name + "." + v.first)) {
      if (v.first == "compiler") {
        getCompilerJsonData(v2, module_name, module_version, c_name, cpp_name, f_name, c_flags, cpp_flags, f_flags, c_link_libs, cpp_link_libs, f_link_libs);
        modules::modules_type modules;
        if (module_name != "none") {
          modules = {{module_name, module_version}};
        }
#ifdef SLURM
        jobscript::SlurmScript job_script(modules,1, 1, "", "", "", "", "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules,1, 1, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
//        std::cout << "(generator) after job_script object generated" << std::endl;
        tests_.push_back(new hpcswtest::CompilerTest(job_script, c_name, cpp_name, f_name, c_flags, cpp_flags, f_flags, c_link_libs, cpp_link_libs, f_link_libs));
//        std::cout << "(generator) after CompilerTest object generated" << std::endl;
//        tests_.push_back(std::unique_ptr<hpcswtest::HpcSwTest> (new hpcswtest::CompilerTest(job_script, c_name, cpp_name, f_name, c_flags, cpp_flags, f_flags, c_link_libs, cpp_link_libs, f_link_libs)));
      } else if (v.first == "mcnp") {
        getModuleNameVersionJsonData(v2, module_name, module_version);
        getExtraModJsonData(v2, 1, extra_module_name1, extra_module_version1);
        getExtraModJsonData(v2, 2, extra_module_name2, extra_module_version2);
        modules::modules_type modules({{extra_module_name1,extra_module_version1},{extra_module_name2,extra_module_version2},{module_name, module_version}});
        removeNoneModules(modules);
        getRunScriptJsonData(v2, run_script);
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::McnpTest(job_script, run_script));
      } else if (v.first == "mcnpx") {
        getModuleNameVersionJsonData(v2, module_name, module_version);
        getExtraModJsonData(v2, 1, extra_module_name1, extra_module_version1);
        getExtraModJsonData(v2, 2, extra_module_name2, extra_module_version2);
        modules::modules_type modules({{extra_module_name1,extra_module_version1},{extra_module_name2,extra_module_version2},{module_name, module_version}});
        removeNoneModules(modules);
        getRunScriptJsonData(v2, run_script);
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::McnpxTest(job_script, run_script));
      } else if (v.first == "mpi") {
        std::string mpi_cmd_name;
        std::string mpi_cmd_args;
        getCompilerJsonData(v2, module_name, module_version, c_name, cpp_name, f_name, c_flags, cpp_flags, f_flags, c_link_libs, cpp_link_libs, f_link_libs);
        getMpiCmdNameArgsJsonData(v2, mpi_cmd_name, mpi_cmd_args);
        modules::modules_type modules({{module_name, module_version}});
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 2, 1, mpi_cmd_name, mpi_cmd_args, "", "", "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 2, 1, mpi_cmd_name, mpi_cmd_args, "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::MpiTest(job_script, c_name, cpp_name, f_name, c_flags, cpp_flags, f_flags, c_link_libs, cpp_link_libs, f_link_libs));
      } else if (v.first == "blas") {
        getCompilerJsonData(v2, module_name, module_version, c_name, cpp_name, f_name, c_flags, cpp_flags, f_flags, c_link_libs, cpp_link_libs, f_link_libs);
        modules::modules_type modules({{module_name, module_version}});
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 1, 1, "", "", "", "", "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 1, 1, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::BlasTest(job_script, c_name, cpp_name, f_name, c_flags, cpp_flags, f_flags, c_link_libs, cpp_link_libs, f_link_libs));
      } else if (v.first == "boost") {
        getCompilerJsonData(v2, module_name, module_version, c_name, cpp_name, f_name, c_flags, cpp_flags, f_flags, c_link_libs, cpp_link_libs, f_link_libs);
        modules::modules_type modules({{module_name, module_version}});
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 1, 1, "", "", "", "", "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 1, 1, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::BoostTest(job_script, c_name, cpp_name, f_name, c_flags, cpp_flags, f_flags, c_link_libs, cpp_link_libs, f_link_libs));
      } else if (v.first == "scale") {
        getModuleNameVersionJsonData(v2, module_name, module_version);
        getExtraModJsonData(v2, 1, extra_module_name1, extra_module_version1);
        modules::modules_type modules({{extra_module_name1,extra_module_version1},{module_name, module_version}});
        getExeExeArgsJsonData(v2, exe_name, exe_args);
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 1, 1, "", "", exe_name, exe_args, "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 1, 1, "", "", exe_name, exe_args, "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::ScaleTest(job_script, v.first));
      } else if (v.first == "scale62") {
        getModuleNameVersionJsonData(v2, module_name, module_version);
        getExtraModJsonData(v2, 1, extra_module_name1, extra_module_version1);
        modules::modules_type modules({{extra_module_name1,extra_module_version1},{module_name, module_version}});
        getExeExeArgsJsonData(v2, exe_name, exe_args);
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 1, 1, "", "", exe_name, exe_args, "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 1, 1, "", "", exe_name, exe_args, "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::Scale62Test(job_script, v.first));
      } else if (v.first == "serpent") {
        getModuleNameVersionJsonData(v2, module_name, module_version);
        getExtraModJsonData(v2, 1, extra_module_name1, extra_module_version1);
        modules::modules_type modules({{extra_module_name1,extra_module_version1},{module_name, module_version}});
        getRunScriptJsonData(v2, run_script);
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 4, 2, "", "", "", "", "", "", hpcswtest_queue, "0:10:00");
#else
        jobscript::PbsScript job_script(modules, 4, 2, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size, "0:10:00");
#endif
        tests_.push_back(new hpcswtest::SerpentTest(job_script, run_script));
      } else if (v.first == "cth") {
        getModuleNameVersionJsonData(v2, module_name, module_version);
        getExtraModJsonData(v2, 1, extra_module_name1, extra_module_version1);
        modules::modules_type modules({{extra_module_name1,extra_module_version1},{module_name, module_version}});
        getRunScriptJsonData(v2, run_script);
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::CthTest(job_script, run_script));
      } else if (v.first == "helios") {
        std::string aurora_exe_name;
        std::string helios_exe_name;
        std::string zenith_exe_name;
        std::string library_name;
        getModuleNameVersionJsonData(v2, module_name, module_version);
        getExtraModJsonData(v2, 1, extra_module_name1, extra_module_version1);
        modules::modules_type modules({{extra_module_name1,extra_module_version1},{module_name, module_version}});
//        getExeExeArgsJsonData(v2, exe_name, exe_args);
        getHeliosExesJsonData(v2, aurora_exe_name, helios_exe_name, zenith_exe_name);
        getLibraryNameJsonData(v2, library_name);
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue, "0:5:0");
#else
        jobscript::PbsScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size, "0:5:0");
#endif
        tests_.push_back(new hpcswtest::HeliosTest(job_script, aurora_exe_name, helios_exe_name, zenith_exe_name, library_name, v.first));
      } else if (v.first == "mc21") {
        getModuleNameVersionJsonData(v2, module_name, module_version);
        getExtraModJsonData(v2, 1, extra_module_name1, extra_module_version1);
        modules::modules_type modules({{extra_module_name1,extra_module_version1},{module_name, module_version}});
        removeNoneModules(modules);
//        getExeExeArgsJsonData(v2, exe_name, exe_args);
        getRunScriptJsonData(v2, run_script);
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 12, 12, "", "", "", "", "", "", hpcswtest_queue, "0:10:00");
#else
        jobscript::PbsScript job_script(modules, 12, 12, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size, "0:10:00");
#endif
        tests_.push_back(new hpcswtest::Mc21Test(job_script, run_script));
      } else if (v.first == "vasp") {
        getModuleNameVersionJsonData(v2, module_name, module_version);
        getExtraModJsonData(v2, 1, extra_module_name1, extra_module_version1);
        modules::modules_type modules({{extra_module_name1,extra_module_version1},{module_name, module_version}});
        removeNoneModules(modules);
        getRunScriptJsonData(v2, run_script);
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::VaspTest(job_script, run_script));
      } else if (v.first == "lammps") {
        getModuleNameVersionJsonData(v2, module_name, module_version);
        modules::modules_type modules({{module_name, module_version}});
        getRunScriptJsonData(v2, run_script);
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::LammpsTest(job_script, run_script));
      } else if (v.first == "nwchem") {
        getModuleNameVersionJsonData(v2, module_name, module_version);
        modules::modules_type modules({{module_name, module_version}});
        getRunScriptJsonData(v2, run_script);
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::NwchemTest(job_script, run_script));
      } else if (v.first == "gaussian") {
        getModuleNameVersionJsonData(v2, module_name, module_version);
        getExtraModJsonData(v2, 1, extra_module_name1, extra_module_version1);
        getRunScriptJsonData(v2, run_script);
        modules::modules_type modules({{extra_module_name1,extra_module_version1},{module_name, module_version}});
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 1, 1, "", "", "", "", "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 1, 1, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::GaussianTest(job_script, run_script));
      } else if (v.first == "abaqus") {
        getModuleNameVersionJsonData(v2, module_name, module_version);
        modules::modules_type modules({{module_name, module_version}});
        getRunScriptJsonData(v2, run_script);
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::AbaqusTest(job_script, run_script));
      } else if (v.first == "starccm") {
        getModuleNameVersionJsonData(v2, module_name, module_version);
        modules::modules_type modules({{module_name, module_version}});
        getRunScriptJsonData(v2, run_script);
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 2, 1, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::StarccmTest(job_script, run_script));
      } else if (v.first == "matlab") {
        getModuleNameVersionJsonData(v2, module_name, module_version);
        modules::modules_type modules({{module_name, module_version}});
        getExeExeArgsJsonData(v2, exe_name, exe_args);
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 1, 1, "", "", exe_name, exe_args, "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 1, 1, "", "", exe_name, exe_args, "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::MatlabTest(job_script));
      } else if (v.first == "python2") {
        std::vector<std::string> python_modules;
        getModuleNameVersionJsonData(v2, module_name, module_version);
        modules::modules_type modules({{module_name, module_version}});
        getPythonModulesJsonData(v2, python_modules);
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 1, 1, "", "", "", "", "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 1, 1, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::Python2Test(job_script, python_modules, v.first));
      } else if (v.first == "python3") {
        std::vector<std::string> python_modules;
        getModuleNameVersionJsonData(v2, module_name, module_version);
        modules::modules_type modules({{module_name, module_version}});
        getPythonModulesJsonData(v2, python_modules);
#ifdef SLURM
        jobscript::SlurmScript job_script(modules, 1, 1, "", "", "", "", "", "", hpcswtest_queue);
#else
        jobscript::PbsScript job_script(modules, 1, 1, "", "", "", "", "", "", hpcswtest_queue, cpu_type, pbs_max_chunk_size);
#endif
        tests_.push_back(new hpcswtest::Python3Test(job_script, python_modules, v.first));
      } else {
          std::cerr << "Error: Do not recognize this test " << v.first << " (" << __FILE__ << "," << __LINE__ << ")" << std::endl;
          exit(EXIT_FAILURE);
      }
    }
  }
}


void Generator::runTests(void) {
  for (auto t: tests_) {
    t->runTest();
  }
}


} // namespace hpcswtest

