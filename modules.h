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
Defines module_type

Date Created: Wed Dec  9 09:42:38 MST 2015

Author: Cormac Garvey

*/

#ifndef MODULES_MODULES_H_
#define MODULES_MODULES_H_

#include <string>
#include <vector>

namespace modules {


typedef std::pair<std::string, std::string> module_type;
typedef std::vector<module_type> modules_type;


} // namespace modules

#endif  // MODULES_MODULES_H

