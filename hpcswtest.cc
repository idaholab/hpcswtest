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
HPC Software stack test suite, source code.

Date Created: Tue Nov 10 13:07:55 MST 2015

Author: Cormac Garvey

*/

#include "hpcswtest.h"
#include <iostream>


namespace hpcswtest {


int HpcSwTest::test_object_count_ = 0;


HpcSwTest::HpcSwTest(const std::string &s): test_name_(s) {
  char hostname[1024];
  gethostname(hostname, 1023);
//  std::cout << hostname << std::endl;
  host_name_ = hostname;
//  std::cout << "(HpcSwTest::HpcSwTest) test_object_count_= " << test_object_count_ << std::endl;
  test_number_ = test_object_count_++;
}


int HpcSwTest::getTestObjectCount(void) const {
  return test_object_count_;
}


void HpcSwTest::setTestNumber(int t_n) {
  test_number_ = t_n;
}


int HpcSwTest::getTestNumber(void) {
  return test_number_;
}


void HpcSwTest::setHostName(const std::string &h_n) {
  host_name_ = h_n;
}


void HpcSwTest::setTestName(const std::string &t_n) {
  test_name_ = t_n;
}


std::string HpcSwTest::getHostName() const {
  return host_name_;
}


std::string HpcSwTest::getTestName() const {
  return test_name_;
}


} // namespace hpcswtest
