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
Mc21Test subclass source code.

Date Created: Mon Dec 19 10:17:56 MST 2016

Author: Cormac Garvey

*/

#include "mc21test.h"

#include <iostream>     // for debugging only
#include <cstdlib>  // for exit()


namespace hpcswtest {


const std::vector<std::string> Mc21Test::mc21_inputs_ = {
R"(neutron_xs_input                '/apps/exp_ctl/mc21/5.00.01/ND_LIBRARY_ENDF70_300K'
xs_temperature_lookup           300. nearest
job_type                        k-eff
source_coordinates              sphere 0.0 0.0 0.0 1.0
histories                       10000
batches                         550
discard                         50
<TIMESTEP>                      1
{EXECUTE}                       spatial)"
}; // vector mc21_inputs_


const std::vector<std::string> Mc21Test::mc21_geometry_inputs_ = {
R"(title 'mc21_model'
surface_list 2582
<surface> 1 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 1.000000E+00
<surface> 2 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -7.720000E+01
<surface> 3 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -7.720000E+01
<surface> 4 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 1.000000E+00
<surface> 5 
type general_plane 0.000000E+00 0.000000E+00 1.000000E+00 1.000000E+00
<surface> 6 
type general_plane 0.000000E+00 0.000000E+00 1.000000E+00 -1.643240E+02
<surface> 7 
type general_plane 3.493852E-01 9.369792E-01 0.000000E+00 -7.139781E+01
<surface> 8 
type right_cylinder 1.000000E+00 0.000000E+00 0.000000E+00 -5.806440E+03
bc escape
<surface> 9 
type general_plane 0.000000E+00 0.000000E+00 1.000000E+00 0.000000E+00
<surface> 10 
type general_plane 0.000000E+00 0.000000E+00 1.000000E+00 -1.633240E+02
<surface> 11 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -6.624828E+01
<surface> 12 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -1.717548E+01
<surface> 13 
type general_plane 7.071068E-01 7.071068E-01 0.000000E+00 -5.388154E+01
<surface> 14 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -5.806948E+01
<surface> 15 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -3.353308E+01
<surface> 16 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -4.989068E+01
<surface> 17 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -4.989068E+01
<surface> 18 
type general_plane 9.095970E-01 4.154917E-01 0.000000E+00 -6.931129E+01
<surface> 19 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -5.806948E+01
<surface> 20 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -3.353308E+01
<surface> 21 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -1.717548E+01
<surface> 22 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -6.624828E+01
<surface> 23 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 0.000000E+00
bc reflecting
<surface> 24 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 0.000000E+00
bc reflecting
<surface> 25 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -8.178800E-01
<surface> 26 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -8.178800E-01
<surface> 27 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -2.453640E+00
<surface> 28 
type right_cylinder 1.000000E+00 -1.635760E+00 0.000000E+00 -3.636042E-01
<surface> 29 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 6.029960E-01
<surface> 30 
type right_cylinder 1.000000E+00 -1.635760E+00 0.000000E+00 -2.650788E-01
<surface> 31 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 5.148580E-01
<surface> 32 
type right_cylinder 1.000000E+00 -3.271520E+00 0.000000E+00 -3.636042E-01
<surface> 33 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -4.089400E+00
<surface> 34 
type right_cylinder 1.000000E+00 -3.271520E+00 0.000000E+00 -2.650788E-01
<surface> 35 
type right_cylinder 1.000000E+00 -4.907280E+00 0.000000E+00 -3.636042E-01
<surface> 36 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -5.725160E+00
<surface> 37 
type right_cylinder 1.000000E+00 -4.907280E+00 0.000000E+00 -2.650788E-01
<surface> 38 
type right_cylinder 1.000000E+00 -6.543040E+00 0.000000E+00 -3.636042E-01
<surface> 39 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -7.360920E+00
<surface> 40 
type right_cylinder 1.000000E+00 -6.543040E+00 0.000000E+00 -2.650788E-01
<surface> 41 
type right_cylinder 1.000000E+00 -8.178800E+00 0.000000E+00 -3.636042E-01
<surface> 42 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -8.996680E+00
<surface> 43 
type right_cylinder 1.000000E+00 -8.178800E+00 0.000000E+00 -2.650788E-01
<surface> 44 
type right_cylinder 1.000000E+00 -9.814560E+00 0.000000E+00 -3.636042E-01
<surface> 45 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -1.063244E+01
<surface> 46 
type right_cylinder 1.000000E+00 -9.814560E+00 0.000000E+00 -2.650788E-01
<surface> 47 
type right_cylinder 1.000000E+00 -1.145032E+01 0.000000E+00 -3.636042E-01
<surface> 48 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -1.226820E+01
<surface> 49 
type right_cylinder 1.000000E+00 -1.145032E+01 0.000000E+00 -2.650788E-01
<surface> 50 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -2.453640E+00
<surface> 51 
type right_cylinder 1.000000E+00 0.000000E+00 -1.635760E+00 -3.636042E-01
<surface> 52 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 6.029960E-01
<surface> 53 
type right_cylinder 1.000000E+00 0.000000E+00 -1.635760E+00 -2.650788E-01
<surface> 54 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 5.148580E-01
<surface> 55 
type right_cylinder 1.000000E+00 -1.635760E+00 -1.635760E+00 -3.636042E-01
<surface> 56 
type right_cylinder 1.000000E+00 -1.635760E+00 -1.635760E+00 -2.650788E-01
<surface> 57 
type right_cylinder 1.000000E+00 -3.271520E+00 -1.635760E+00 -3.636042E-01
<surface> 58 
type right_cylinder 1.000000E+00 -3.271520E+00 -1.635760E+00 -2.650788E-01
<surface> 59 
type right_cylinder 1.000000E+00 -4.907280E+00 -1.635760E+00 -3.636042E-01
<surface> 60 
type right_cylinder 1.000000E+00 -4.907280E+00 -1.635760E+00 -2.650788E-01
<surface> 61 
type right_cylinder 1.000000E+00 -6.543040E+00 -1.635760E+00 -3.636042E-01
<surface> 62 
type right_cylinder 1.000000E+00 -6.543040E+00 -1.635760E+00 -2.650788E-01
<surface> 63 
type right_cylinder 1.000000E+00 -8.178800E+00 -1.635760E+00 -3.636042E-01
<surface> 64 
type right_cylinder 1.000000E+00 -8.178800E+00 -1.635760E+00 -2.650788E-01
<surface> 65 
type right_cylinder 1.000000E+00 -9.814560E+00 -1.635760E+00 -3.636042E-01
<surface> 66 
type right_cylinder 1.000000E+00 -9.814560E+00 -1.635760E+00 -2.650788E-01
<surface> 67 
type right_cylinder 1.000000E+00 -1.145032E+01 -1.635760E+00 -3.636042E-01
<surface> 68 
type right_cylinder 1.000000E+00 -1.145032E+01 -1.635760E+00 -2.650788E-01
<surface> 69 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -4.089400E+00
<surface> 70 
type right_cylinder 1.000000E+00 0.000000E+00 -3.271520E+00 -3.636042E-01
<surface> 71 
type right_cylinder 1.000000E+00 0.000000E+00 -3.271520E+00 -2.650788E-01
<surface> 72 
type right_cylinder 1.000000E+00 -1.635760E+00 -3.271520E+00 -3.636042E-01
<surface> 73 
type right_cylinder 1.000000E+00 -1.635760E+00 -3.271520E+00 -2.650788E-01
<surface> 74 
type right_cylinder 1.000000E+00 -4.907280E+00 -3.271520E+00 -3.636042E-01
<surface> 75 
type right_cylinder 1.000000E+00 -4.907280E+00 -3.271520E+00 -2.650788E-01
<surface> 76 
type right_cylinder 1.000000E+00 -6.543040E+00 -3.271520E+00 -3.636042E-01
<surface> 77 
type right_cylinder 1.000000E+00 -6.543040E+00 -3.271520E+00 -2.650788E-01
<surface> 78 
type right_cylinder 1.000000E+00 -9.814560E+00 -3.271520E+00 -3.636042E-01
<surface> 79 
type right_cylinder 1.000000E+00 -9.814560E+00 -3.271520E+00 -2.650788E-01
<surface> 80 
type right_cylinder 1.000000E+00 -1.145032E+01 -3.271520E+00 -3.636042E-01
<surface> 81 
type right_cylinder 1.000000E+00 -1.145032E+01 -3.271520E+00 -2.650788E-01
<surface> 82 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -5.725160E+00
<surface> 83 
type right_cylinder 1.000000E+00 0.000000E+00 -4.907280E+00 -3.636042E-01
<surface> 84 
type right_cylinder 1.000000E+00 0.000000E+00 -4.907280E+00 -2.650788E-01
<surface> 85 
type right_cylinder 1.000000E+00 -1.635760E+00 -4.907280E+00 -3.636042E-01
<surface> 86 
type right_cylinder 1.000000E+00 -1.635760E+00 -4.907280E+00 -2.650788E-01
<surface> 87 
type right_cylinder 1.000000E+00 -3.271520E+00 -4.907280E+00 -3.636042E-01
<surface> 88 
type right_cylinder 1.000000E+00 -3.271520E+00 -4.907280E+00 -2.650788E-01
<surface> 89 
type right_cylinder 1.000000E+00 -4.907280E+00 -4.907280E+00 -3.636042E-01
<surface> 90 
type right_cylinder 1.000000E+00 -4.907280E+00 -4.907280E+00 -2.650788E-01
<surface> 91 
type right_cylinder 1.000000E+00 -6.543040E+00 -4.907280E+00 -3.636042E-01
<surface> 92 
type right_cylinder 1.000000E+00 -6.543040E+00 -4.907280E+00 -2.650788E-01
<surface> 93 
type right_cylinder 1.000000E+00 -8.178800E+00 -4.907280E+00 -3.636042E-01
<surface> 94 
type right_cylinder 1.000000E+00 -8.178800E+00 -4.907280E+00 -2.650788E-01
<surface> 95 
type right_cylinder 1.000000E+00 -9.814560E+00 -4.907280E+00 -3.636042E-01
<surface> 96 
type right_cylinder 1.000000E+00 -9.814560E+00 -4.907280E+00 -2.650788E-01
<surface> 97 
type right_cylinder 1.000000E+00 -1.145032E+01 -4.907280E+00 -3.636042E-01
<surface> 98 
type right_cylinder 1.000000E+00 -1.145032E+01 -4.907280E+00 -2.650788E-01
<surface> 99 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -7.360920E+00
<surface> 100 
type right_cylinder 1.000000E+00 0.000000E+00 -6.543040E+00 -3.636042E-01
<surface> 101 
type right_cylinder 1.000000E+00 0.000000E+00 -6.543040E+00 -2.650788E-01
<surface> 102 
type right_cylinder 1.000000E+00 -1.635760E+00 -6.543040E+00 -3.636042E-01
<surface> 103 
type right_cylinder 1.000000E+00 -1.635760E+00 -6.543040E+00 -2.650788E-01
<surface> 104 
type right_cylinder 1.000000E+00 -3.271520E+00 -6.543040E+00 -3.636042E-01
<surface> 105 
type right_cylinder 1.000000E+00 -3.271520E+00 -6.543040E+00 -2.650788E-01
<surface> 106 
type right_cylinder 1.000000E+00 -4.907280E+00 -6.543040E+00 -3.636042E-01
<surface> 107 
type right_cylinder 1.000000E+00 -4.907280E+00 -6.543040E+00 -2.650788E-01
<surface> 108 
type right_cylinder 1.000000E+00 -8.178800E+00 -6.543040E+00 -3.636042E-01
<surface> 109 
type right_cylinder 1.000000E+00 -8.178800E+00 -6.543040E+00 -2.650788E-01
<surface> 110 
type right_cylinder 1.000000E+00 -9.814560E+00 -6.543040E+00 -3.636042E-01
<surface> 111 
type right_cylinder 1.000000E+00 -9.814560E+00 -6.543040E+00 -2.650788E-01
<surface> 112 
type right_cylinder 1.000000E+00 -1.145032E+01 -6.543040E+00 -3.636042E-01
<surface> 113 
type right_cylinder 1.000000E+00 -1.145032E+01 -6.543040E+00 -2.650788E-01
<surface> 114 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -8.996680E+00
<surface> 115 
type right_cylinder 1.000000E+00 0.000000E+00 -8.178800E+00 -3.636042E-01
<surface> 116 
type right_cylinder 1.000000E+00 0.000000E+00 -8.178800E+00 -2.650788E-01
<surface> 117 
type right_cylinder 1.000000E+00 -1.635760E+00 -8.178800E+00 -3.636042E-01
<surface> 118 
type right_cylinder 1.000000E+00 -1.635760E+00 -8.178800E+00 -2.650788E-01
<surface> 119 
type right_cylinder 1.000000E+00 -4.907280E+00 -8.178800E+00 -3.636042E-01
<surface> 120 
type right_cylinder 1.000000E+00 -4.907280E+00 -8.178800E+00 -2.650788E-01
<surface> 121 
type right_cylinder 1.000000E+00 -6.543040E+00 -8.178800E+00 -3.636042E-01
<surface> 122 
type right_cylinder 1.000000E+00 -6.543040E+00 -8.178800E+00 -2.650788E-01
<surface> 123 
type right_cylinder 1.000000E+00 -8.178800E+00 -8.178800E+00 -3.636042E-01
<surface> 124 
type right_cylinder 1.000000E+00 -8.178800E+00 -8.178800E+00 -2.650788E-01
<surface> 125 
type right_cylinder 1.000000E+00 -9.814560E+00 -8.178800E+00 -3.636042E-01
<surface> 126 
type right_cylinder 1.000000E+00 -9.814560E+00 -8.178800E+00 -2.650788E-01
<surface> 127 
type right_cylinder 1.000000E+00 -1.145032E+01 -8.178800E+00 -3.636042E-01
<surface> 128 
type right_cylinder 1.000000E+00 -1.145032E+01 -8.178800E+00 -2.650788E-01
<surface> 129 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -1.063244E+01
<surface> 130 
type right_cylinder 1.000000E+00 0.000000E+00 -9.814560E+00 -3.636042E-01
<surface> 131 
type right_cylinder 1.000000E+00 0.000000E+00 -9.814560E+00 -2.650788E-01
<surface> 132 
type right_cylinder 1.000000E+00 -1.635760E+00 -9.814560E+00 -3.636042E-01
<surface> 133 
type right_cylinder 1.000000E+00 -1.635760E+00 -9.814560E+00 -2.650788E-01
<surface> 134 
type right_cylinder 1.000000E+00 -3.271520E+00 -9.814560E+00 -3.636042E-01
<surface> 135 
type right_cylinder 1.000000E+00 -3.271520E+00 -9.814560E+00 -2.650788E-01
<surface> 136 
type right_cylinder 1.000000E+00 -4.907280E+00 -9.814560E+00 -3.636042E-01
<surface> 137 
type right_cylinder 1.000000E+00 -4.907280E+00 -9.814560E+00 -2.650788E-01
<surface> 138 
type right_cylinder 1.000000E+00 -6.543040E+00 -9.814560E+00 -3.636042E-01
<surface> 139 
type right_cylinder 1.000000E+00 -6.543040E+00 -9.814560E+00 -2.650788E-01
<surface> 140 
type right_cylinder 1.000000E+00 -8.178800E+00 -9.814560E+00 -3.636042E-01
<surface> 141 
type right_cylinder 1.000000E+00 -8.178800E+00 -9.814560E+00 -2.650788E-01
<surface> 142 
type right_cylinder 1.000000E+00 -9.814560E+00 -9.814560E+00 -3.636042E-01
<surface> 143 
type right_cylinder 1.000000E+00 -9.814560E+00 -9.814560E+00 -2.650788E-01
<surface> 144 
type right_cylinder 1.000000E+00 -1.145032E+01 -9.814560E+00 -3.636042E-01
<surface> 145 
type right_cylinder 1.000000E+00 -1.145032E+01 -9.814560E+00 -2.650788E-01
<surface> 146 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -1.226820E+01
<surface> 147 
type right_cylinder 1.000000E+00 0.000000E+00 -1.145032E+01 -3.636042E-01
<surface> 148 
type right_cylinder 1.000000E+00 0.000000E+00 -1.145032E+01 -2.650788E-01
<surface> 149 
type right_cylinder 1.000000E+00 -1.635760E+00 -1.145032E+01 -3.636042E-01
<surface> 150 
type right_cylinder 1.000000E+00 -1.635760E+00 -1.145032E+01 -2.650788E-01
<surface> 151 
type right_cylinder 1.000000E+00 -3.271520E+00 -1.145032E+01 -3.636042E-01
<surface> 152 
type right_cylinder 1.000000E+00 -3.271520E+00 -1.145032E+01 -2.650788E-01
<surface> 153 
type right_cylinder 1.000000E+00 -4.907280E+00 -1.145032E+01 -3.636042E-01
<surface> 154 
type right_cylinder 1.000000E+00 -4.907280E+00 -1.145032E+01 -2.650788E-01
<surface> 155 
type right_cylinder 1.000000E+00 -6.543040E+00 -1.145032E+01 -3.636042E-01
<surface> 156 
type right_cylinder 1.000000E+00 -6.543040E+00 -1.145032E+01 -2.650788E-01
<surface> 157 
type right_cylinder 1.000000E+00 -8.178800E+00 -1.145032E+01 -3.636042E-01
<surface> 158 
type right_cylinder 1.000000E+00 -8.178800E+00 -1.145032E+01 -2.650788E-01
<surface> 159 
type right_cylinder 1.000000E+00 -9.814560E+00 -1.145032E+01 -3.636042E-01
<surface> 160 
type right_cylinder 1.000000E+00 -9.814560E+00 -1.145032E+01 -2.650788E-01
<surface> 161 
type right_cylinder 1.000000E+00 -1.145032E+01 -1.145032E+01 -3.636042E-01
<surface> 162 
type right_cylinder 1.000000E+00 -1.145032E+01 -1.145032E+01 -2.650788E-01
<surface> 163 
type right_cylinder 1.000000E+00 -1.308608E+01 0.000000E+00 -3.636042E-01
<surface> 164 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -1.390396E+01
<surface> 165 
type right_cylinder 1.000000E+00 -1.308608E+01 0.000000E+00 -2.650788E-01
<surface> 166 
type right_cylinder 1.000000E+00 -1.472184E+01 0.000000E+00 -3.636042E-01
<surface> 167 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -1.553972E+01
<surface> 168 
type right_cylinder 1.000000E+00 -1.472184E+01 0.000000E+00 -2.650788E-01
<surface> 169 
type right_cylinder 1.000000E+00 -1.635760E+01 0.000000E+00 -3.636042E-01
<surface> 170 
type right_cylinder 1.000000E+00 -1.635760E+01 0.000000E+00 -2.650788E-01
<surface> 171 
type right_cylinder 1.000000E+00 -1.799336E+01 0.000000E+00 -3.636042E-01
<surface> 172 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -1.881124E+01
<surface> 173 
type right_cylinder 1.000000E+00 -1.799336E+01 0.000000E+00 -2.650788E-01
<surface> 174 
type right_cylinder 1.000000E+00 -1.962912E+01 0.000000E+00 -3.636042E-01
<surface> 175 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -2.044700E+01
<surface> 176 
type right_cylinder 1.000000E+00 -1.962912E+01 0.000000E+00 -2.650788E-01
<surface> 177 
type right_cylinder 1.000000E+00 -2.126488E+01 0.000000E+00 -3.636042E-01
<surface> 178 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -2.208276E+01
<surface> 179 
type right_cylinder 1.000000E+00 -2.126488E+01 0.000000E+00 -2.650788E-01
<surface> 180 
type right_cylinder 1.000000E+00 -2.290064E+01 0.000000E+00 -3.636042E-01
<surface> 181 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -2.371852E+01
<surface> 182 
type right_cylinder 1.000000E+00 -2.290064E+01 0.000000E+00 -2.650788E-01
<surface> 183 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -2.535428E+01
<surface> 184 
type right_cylinder 1.000000E+00 -2.617216E+01 0.000000E+00 -3.636042E-01
<surface> 185 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -2.699004E+01
<surface> 186 
type right_cylinder 1.000000E+00 -2.617216E+01 0.000000E+00 -2.650788E-01
<surface> 187 
type right_cylinder 1.000000E+00 -2.780792E+01 0.000000E+00 -3.636042E-01
<surface> 188 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -2.862580E+01
<surface> 189 
type right_cylinder 1.000000E+00 -2.780792E+01 0.000000E+00 -2.650788E-01
<surface> 190 
type right_cylinder 1.000000E+00 -2.944368E+01 0.000000E+00 -3.636042E-01
<surface> 191 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -3.026156E+01
<surface> 192 
type right_cylinder 1.000000E+00 -2.944368E+01 0.000000E+00 -2.650788E-01
<surface> 193 
type right_cylinder 1.000000E+00 -3.107944E+01 0.000000E+00 -3.636042E-01
<surface> 194 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -3.189732E+01
<surface> 195 
type right_cylinder 1.000000E+00 -3.107944E+01 0.000000E+00 -2.650788E-01
<surface> 196 
type right_cylinder 1.000000E+00 -3.271520E+01 0.000000E+00 -3.636042E-01
<surface> 197 
type right_cylinder 1.000000E+00 -3.271520E+01 0.000000E+00 -2.650788E-01
<surface> 198 
type right_cylinder 1.000000E+00 -3.435096E+01 0.000000E+00 -3.636042E-01
<surface> 199 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -3.516884E+01
<surface> 200 
type right_cylinder 1.000000E+00 -3.435096E+01 0.000000E+00 -2.650788E-01
<surface> 201 
type right_cylinder 1.000000E+00 -3.598672E+01 0.000000E+00 -3.636042E-01
<surface> 202 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -3.680460E+01
<surface> 203 
type right_cylinder 1.000000E+00 -3.598672E+01 0.000000E+00 -2.650788E-01
<surface> 204 
type right_cylinder 1.000000E+00 -1.308608E+01 -1.635760E+00 -3.636042E-01
<surface> 205 
type right_cylinder 1.000000E+00 -1.308608E+01 -1.635760E+00 -2.650788E-01
<surface> 206 
type right_cylinder 1.000000E+00 -1.472184E+01 -1.635760E+00 -3.636042E-01
<surface> 207 
type right_cylinder 1.000000E+00 -1.472184E+01 -1.635760E+00 -2.650788E-01
<surface> 208 
type right_cylinder 1.000000E+00 -1.635760E+01 -1.635760E+00 -3.636042E-01
<surface> 209 
type right_cylinder 1.000000E+00 -1.635760E+01 -1.635760E+00 -2.650788E-01
<surface> 210 
type right_cylinder 1.000000E+00 -1.799336E+01 -1.635760E+00 -3.636042E-01
<surface> 211 
type right_cylinder 1.000000E+00 -1.799336E+01 -1.635760E+00 -2.650788E-01
<surface> 212 
type right_cylinder 1.000000E+00 -1.962912E+01 -1.635760E+00 -3.636042E-01
<surface> 213 
type right_cylinder 1.000000E+00 -1.962912E+01 -1.635760E+00 -2.650788E-01
<surface> 214 
type right_cylinder 1.000000E+00 -2.126488E+01 -1.635760E+00 -3.636042E-01
<surface> 215 
type right_cylinder 1.000000E+00 -2.126488E+01 -1.635760E+00 -2.650788E-01
<surface> 216 
type right_cylinder 1.000000E+00 -2.290064E+01 -1.635760E+00 -3.636042E-01
<surface> 217 
type right_cylinder 1.000000E+00 -2.290064E+01 -1.635760E+00 -2.650788E-01
<surface> 218 
type right_cylinder 1.000000E+00 -2.453640E+01 -1.635760E+00 -3.636042E-01
<surface> 219 
type right_cylinder 1.000000E+00 -2.453640E+01 -1.635760E+00 -2.650788E-01
<surface> 220 
type right_cylinder 1.000000E+00 -2.617216E+01 -1.635760E+00 -3.636042E-01
<surface> 221 
type right_cylinder 1.000000E+00 -2.617216E+01 -1.635760E+00 -2.650788E-01
<surface> 222 
type right_cylinder 1.000000E+00 -2.780792E+01 -1.635760E+00 -3.636042E-01
<surface> 223 
type right_cylinder 1.000000E+00 -2.780792E+01 -1.635760E+00 -2.650788E-01
<surface> 224 
type right_cylinder 1.000000E+00 -2.944368E+01 -1.635760E+00 -3.636042E-01
<surface> 225 
type right_cylinder 1.000000E+00 -2.944368E+01 -1.635760E+00 -2.650788E-01
<surface> 226 
type right_cylinder 1.000000E+00 -3.107944E+01 -1.635760E+00 -3.636042E-01
<surface> 227 
type right_cylinder 1.000000E+00 -3.107944E+01 -1.635760E+00 -2.650788E-01
<surface> 228 
type right_cylinder 1.000000E+00 -3.271520E+01 -1.635760E+00 -3.636042E-01
<surface> 229 
type right_cylinder 1.000000E+00 -3.271520E+01 -1.635760E+00 -2.650788E-01
<surface> 230 
type right_cylinder 1.000000E+00 -3.435096E+01 -1.635760E+00 -3.636042E-01
<surface> 231 
type right_cylinder 1.000000E+00 -3.435096E+01 -1.635760E+00 -2.650788E-01
<surface> 232 
type right_cylinder 1.000000E+00 -3.598672E+01 -1.635760E+00 -3.636042E-01
<surface> 233 
type right_cylinder 1.000000E+00 -3.598672E+01 -1.635760E+00 -2.650788E-01
<surface> 234 
type right_cylinder 1.000000E+00 -1.308608E+01 -3.271520E+00 -3.636042E-01
<surface> 235 
type right_cylinder 1.000000E+00 -1.308608E+01 -3.271520E+00 -2.650788E-01
<surface> 236 
type right_cylinder 1.000000E+00 -1.472184E+01 -3.271520E+00 -3.636042E-01
<surface> 237 
type right_cylinder 1.000000E+00 -1.472184E+01 -3.271520E+00 -2.650788E-01
<surface> 238 
type right_cylinder 1.000000E+00 -1.799336E+01 -3.271520E+00 -3.636042E-01
<surface> 239 
type right_cylinder 1.000000E+00 -1.799336E+01 -3.271520E+00 -2.650788E-01
<surface> 240 
type right_cylinder 1.000000E+00 -1.962912E+01 -3.271520E+00 -3.636042E-01
<surface> 241 
type right_cylinder 1.000000E+00 -1.962912E+01 -3.271520E+00 -2.650788E-01
<surface> 242 
type right_cylinder 1.000000E+00 -2.290064E+01 -3.271520E+00 -3.636042E-01
<surface> 243 
type right_cylinder 1.000000E+00 -2.290064E+01 -3.271520E+00 -2.650788E-01
<surface> 244 
type right_cylinder 1.000000E+00 -2.453640E+01 -3.271520E+00 -3.636042E-01
<surface> 245 
type right_cylinder 1.000000E+00 -2.453640E+01 -3.271520E+00 -2.650788E-01
<surface> 246 
type right_cylinder 1.000000E+00 -2.617216E+01 -3.271520E+00 -3.636042E-01
<surface> 247 
type right_cylinder 1.000000E+00 -2.617216E+01 -3.271520E+00 -2.650788E-01
<surface> 248 
type right_cylinder 1.000000E+00 -2.944368E+01 -3.271520E+00 -3.636042E-01
<surface> 249 
type right_cylinder 1.000000E+00 -2.944368E+01 -3.271520E+00 -2.650788E-01
<surface> 250 
type right_cylinder 1.000000E+00 -3.107944E+01 -3.271520E+00 -3.636042E-01
<surface> 251 
type right_cylinder 1.000000E+00 -3.107944E+01 -3.271520E+00 -2.650788E-01
<surface> 252 
type right_cylinder 1.000000E+00 -3.435096E+01 -3.271520E+00 -3.636042E-01
<surface> 253 
type right_cylinder 1.000000E+00 -3.435096E+01 -3.271520E+00 -2.650788E-01
<surface> 254 
type right_cylinder 1.000000E+00 -3.598672E+01 -3.271520E+00 -3.636042E-01
<surface> 255 
type right_cylinder 1.000000E+00 -3.598672E+01 -3.271520E+00 -2.650788E-01
<surface> 256 
type right_cylinder 1.000000E+00 -1.308608E+01 -4.907280E+00 -3.636042E-01
<surface> 257 
type right_cylinder 1.000000E+00 -1.308608E+01 -4.907280E+00 -2.650788E-01
<surface> 258 
type right_cylinder 1.000000E+00 -1.472184E+01 -4.907280E+00 -3.636042E-01
<surface> 259 
type right_cylinder 1.000000E+00 -1.472184E+01 -4.907280E+00 -2.650788E-01
<surface> 260 
type right_cylinder 1.000000E+00 -1.635760E+01 -4.907280E+00 -3.636042E-01
<surface> 261 
type right_cylinder 1.000000E+00 -1.635760E+01 -4.907280E+00 -2.650788E-01
<surface> 262 
type right_cylinder 1.000000E+00 -1.799336E+01 -4.907280E+00 -3.636042E-01
<surface> 263 
type right_cylinder 1.000000E+00 -1.799336E+01 -4.907280E+00 -2.650788E-01
<surface> 264 
type right_cylinder 1.000000E+00 -1.962912E+01 -4.907280E+00 -3.636042E-01
<surface> 265 
type right_cylinder 1.000000E+00 -1.962912E+01 -4.907280E+00 -2.650788E-01
<surface> 266 
type right_cylinder 1.000000E+00 -2.126488E+01 -4.907280E+00 -3.636042E-01
<surface> 267 
type right_cylinder 1.000000E+00 -2.126488E+01 -4.907280E+00 -2.650788E-01
<surface> 268 
type right_cylinder 1.000000E+00 -2.290064E+01 -4.907280E+00 -3.636042E-01
<surface> 269 
type right_cylinder 1.000000E+00 -2.290064E+01 -4.907280E+00 -2.650788E-01
<surface> 270 
type right_cylinder 1.000000E+00 -2.453640E+01 -4.907280E+00 -3.636042E-01
<surface> 271 
type right_cylinder 1.000000E+00 -2.453640E+01 -4.907280E+00 -2.650788E-01
<surface> 272 
type right_cylinder 1.000000E+00 -2.617216E+01 -4.907280E+00 -3.636042E-01
<surface> 273 
type right_cylinder 1.000000E+00 -2.617216E+01 -4.907280E+00 -2.650788E-01
<surface> 274 
type right_cylinder 1.000000E+00 -2.780792E+01 -4.907280E+00 -3.636042E-01
<surface> 275 
type right_cylinder 1.000000E+00 -2.780792E+01 -4.907280E+00 -2.650788E-01
<surface> 276 
type right_cylinder 1.000000E+00 -2.944368E+01 -4.907280E+00 -3.636042E-01
<surface> 277 
type right_cylinder 1.000000E+00 -2.944368E+01 -4.907280E+00 -2.650788E-01
<surface> 278 
type right_cylinder 1.000000E+00 -3.107944E+01 -4.907280E+00 -3.636042E-01
<surface> 279 
type right_cylinder 1.000000E+00 -3.107944E+01 -4.907280E+00 -2.650788E-01
<surface> 280 
type right_cylinder 1.000000E+00 -3.271520E+01 -4.907280E+00 -3.636042E-01
<surface> 281 
type right_cylinder 1.000000E+00 -3.271520E+01 -4.907280E+00 -2.650788E-01
<surface> 282 
type right_cylinder 1.000000E+00 -3.435096E+01 -4.907280E+00 -3.636042E-01
<surface> 283 
type right_cylinder 1.000000E+00 -3.435096E+01 -4.907280E+00 -2.650788E-01
<surface> 284 
type right_cylinder 1.000000E+00 -3.598672E+01 -4.907280E+00 -3.636042E-01
<surface> 285 
type right_cylinder 1.000000E+00 -3.598672E+01 -4.907280E+00 -2.650788E-01
<surface> 286 
type right_cylinder 1.000000E+00 -1.308608E+01 -6.543040E+00 -3.636042E-01
<surface> 287 
type right_cylinder 1.000000E+00 -1.308608E+01 -6.543040E+00 -2.650788E-01
<surface> 288 
type right_cylinder 1.000000E+00 -1.472184E+01 -6.543040E+00 -3.636042E-01
<surface> 289 
type right_cylinder 1.000000E+00 -1.472184E+01 -6.543040E+00 -2.650788E-01
<surface> 290 
type right_cylinder 1.000000E+00 -1.635760E+01 -6.543040E+00 -3.636042E-01
<surface> 291 
type right_cylinder 1.000000E+00 -1.635760E+01 -6.543040E+00 -2.650788E-01
<surface> 292 
type right_cylinder 1.000000E+00 -1.962912E+01 -6.543040E+00 -3.636042E-01
<surface> 293 
type right_cylinder 1.000000E+00 -1.962912E+01 -6.543040E+00 -2.650788E-01
<surface> 294 
type right_cylinder 1.000000E+00 -2.126488E+01 -6.543040E+00 -3.636042E-01
<surface> 295 
type right_cylinder 1.000000E+00 -2.126488E+01 -6.543040E+00 -2.650788E-01
<surface> 296 
type right_cylinder 1.000000E+00 -2.290064E+01 -6.543040E+00 -3.636042E-01
<surface> 297 
type right_cylinder 1.000000E+00 -2.290064E+01 -6.543040E+00 -2.650788E-01
<surface> 298 
type right_cylinder 1.000000E+00 -2.453640E+01 -6.543040E+00 -3.636042E-01
<surface> 299 
type right_cylinder 1.000000E+00 -2.453640E+01 -6.543040E+00 -2.650788E-01
<surface> 300 
type right_cylinder 1.000000E+00 -2.617216E+01 -6.543040E+00 -3.636042E-01
<surface> 301 
type right_cylinder 1.000000E+00 -2.617216E+01 -6.543040E+00 -2.650788E-01
<surface> 302 
type right_cylinder 1.000000E+00 -2.780792E+01 -6.543040E+00 -3.636042E-01
<surface> 303 
type right_cylinder 1.000000E+00 -2.780792E+01 -6.543040E+00 -2.650788E-01
<surface> 304 
type right_cylinder 1.000000E+00 -2.944368E+01 -6.543040E+00 -3.636042E-01
<surface> 305 
type right_cylinder 1.000000E+00 -2.944368E+01 -6.543040E+00 -2.650788E-01
<surface> 306 
type right_cylinder 1.000000E+00 -3.271520E+01 -6.543040E+00 -3.636042E-01
<surface> 307 
type right_cylinder 1.000000E+00 -3.271520E+01 -6.543040E+00 -2.650788E-01
<surface> 308 
type right_cylinder 1.000000E+00 -3.435096E+01 -6.543040E+00 -3.636042E-01
<surface> 309 
type right_cylinder 1.000000E+00 -3.435096E+01 -6.543040E+00 -2.650788E-01
<surface> 310 
type right_cylinder 1.000000E+00 -3.598672E+01 -6.543040E+00 -3.636042E-01
<surface> 311 
type right_cylinder 1.000000E+00 -3.598672E+01 -6.543040E+00 -2.650788E-01
<surface> 312 
type right_cylinder 1.000000E+00 -1.308608E+01 -8.178800E+00 -3.636042E-01
<surface> 313 
type right_cylinder 1.000000E+00 -1.308608E+01 -8.178800E+00 -2.650788E-01
<surface> 314 
type right_cylinder 1.000000E+00 -1.472184E+01 -8.178800E+00 -3.636042E-01
<surface> 315 
type right_cylinder 1.000000E+00 -1.472184E+01 -8.178800E+00 -2.650788E-01
<surface> 316 
type right_cylinder 1.000000E+00 -1.635760E+01 -8.178800E+00 -3.636042E-01
<surface> 317 
type right_cylinder 1.000000E+00 -1.635760E+01 -8.178800E+00 -2.650788E-01
<surface> 318 
type right_cylinder 1.000000E+00 -1.799336E+01 -8.178800E+00 -3.636042E-01
<surface> 319 
type right_cylinder 1.000000E+00 -1.799336E+01 -8.178800E+00 -2.650788E-01
<surface> 320 
type right_cylinder 1.000000E+00 -1.962912E+01 -8.178800E+00 -3.636042E-01
<surface> 321 
type right_cylinder 1.000000E+00 -1.962912E+01 -8.178800E+00 -2.650788E-01
<surface> 322 
type right_cylinder 1.000000E+00 -2.290064E+01 -8.178800E+00 -3.636042E-01
<surface> 323 
type right_cylinder 1.000000E+00 -2.290064E+01 -8.178800E+00 -2.650788E-01
<surface> 324 
type right_cylinder 1.000000E+00 -2.453640E+01 -8.178800E+00 -3.636042E-01
<surface> 325 
type right_cylinder 1.000000E+00 -2.453640E+01 -8.178800E+00 -2.650788E-01
<surface> 326 
type right_cylinder 1.000000E+00 -2.617216E+01 -8.178800E+00 -3.636042E-01
<surface> 327 
type right_cylinder 1.000000E+00 -2.617216E+01 -8.178800E+00 -2.650788E-01
<surface> 328 
type right_cylinder 1.000000E+00 -2.944368E+01 -8.178800E+00 -3.636042E-01
<surface> 329 
type right_cylinder 1.000000E+00 -2.944368E+01 -8.178800E+00 -2.650788E-01
<surface> 330 
type right_cylinder 1.000000E+00 -3.107944E+01 -8.178800E+00 -3.636042E-01
<surface> 331 
type right_cylinder 1.000000E+00 -3.107944E+01 -8.178800E+00 -2.650788E-01
<surface> 332 
type right_cylinder 1.000000E+00 -3.271520E+01 -8.178800E+00 -3.636042E-01
<surface> 333 
type right_cylinder 1.000000E+00 -3.271520E+01 -8.178800E+00 -2.650788E-01
<surface> 334 
type right_cylinder 1.000000E+00 -3.435096E+01 -8.178800E+00 -3.636042E-01
<surface> 335 
type right_cylinder 1.000000E+00 -3.435096E+01 -8.178800E+00 -2.650788E-01
<surface> 336 
type right_cylinder 1.000000E+00 -3.598672E+01 -8.178800E+00 -3.636042E-01
<surface> 337 
type right_cylinder 1.000000E+00 -3.598672E+01 -8.178800E+00 -2.650788E-01
<surface> 338 
type right_cylinder 1.000000E+00 -1.308608E+01 -9.814560E+00 -3.636042E-01
<surface> 339 
type right_cylinder 1.000000E+00 -1.308608E+01 -9.814560E+00 -2.650788E-01
<surface> 340 
type right_cylinder 1.000000E+00 -1.472184E+01 -9.814560E+00 -3.636042E-01
<surface> 341 
type right_cylinder 1.000000E+00 -1.472184E+01 -9.814560E+00 -2.650788E-01
<surface> 342 
type right_cylinder 1.000000E+00 -1.635760E+01 -9.814560E+00 -3.636042E-01
<surface> 343 
type right_cylinder 1.000000E+00 -1.635760E+01 -9.814560E+00 -2.650788E-01
<surface> 344 
type right_cylinder 1.000000E+00 -1.799336E+01 -9.814560E+00 -3.636042E-01
<surface> 345 
type right_cylinder 1.000000E+00 -1.799336E+01 -9.814560E+00 -2.650788E-01
<surface> 346 
type right_cylinder 1.000000E+00 -1.962912E+01 -9.814560E+00 -3.636042E-01
<surface> 347 
type right_cylinder 1.000000E+00 -1.962912E+01 -9.814560E+00 -2.650788E-01
<surface> 348 
type right_cylinder 1.000000E+00 -2.126488E+01 -9.814560E+00 -3.636042E-01
<surface> 349 
type right_cylinder 1.000000E+00 -2.126488E+01 -9.814560E+00 -2.650788E-01
<surface> 350 
type right_cylinder 1.000000E+00 -2.290064E+01 -9.814560E+00 -3.636042E-01
<surface> 351 
type right_cylinder 1.000000E+00 -2.290064E+01 -9.814560E+00 -2.650788E-01
<surface> 352 
type right_cylinder 1.000000E+00 -2.453640E+01 -9.814560E+00 -3.636042E-01
<surface> 353 
type right_cylinder 1.000000E+00 -2.453640E+01 -9.814560E+00 -2.650788E-01
<surface> 354 
type right_cylinder 1.000000E+00 -2.617216E+01 -9.814560E+00 -3.636042E-01
<surface> 355 
type right_cylinder 1.000000E+00 -2.617216E+01 -9.814560E+00 -2.650788E-01
<surface> 356 
type right_cylinder 1.000000E+00 -2.780792E+01 -9.814560E+00 -3.636042E-01
<surface> 357 
type right_cylinder 1.000000E+00 -2.780792E+01 -9.814560E+00 -2.650788E-01
<surface> 358 
type right_cylinder 1.000000E+00 -2.944368E+01 -9.814560E+00 -3.636042E-01
<surface> 359 
type right_cylinder 1.000000E+00 -2.944368E+01 -9.814560E+00 -2.650788E-01
<surface> 360 
type right_cylinder 1.000000E+00 -3.107944E+01 -9.814560E+00 -3.636042E-01
<surface> 361 
type right_cylinder 1.000000E+00 -3.107944E+01 -9.814560E+00 -2.650788E-01
<surface> 362 
type right_cylinder 1.000000E+00 -3.271520E+01 -9.814560E+00 -3.636042E-01
<surface> 363 
type right_cylinder 1.000000E+00 -3.271520E+01 -9.814560E+00 -2.650788E-01
<surface> 364 
type right_cylinder 1.000000E+00 -3.435096E+01 -9.814560E+00 -3.636042E-01
<surface> 365 
type right_cylinder 1.000000E+00 -3.435096E+01 -9.814560E+00 -2.650788E-01
<surface> 366 
type right_cylinder 1.000000E+00 -3.598672E+01 -9.814560E+00 -3.636042E-01
<surface> 367 
type right_cylinder 1.000000E+00 -3.598672E+01 -9.814560E+00 -2.650788E-01
<surface> 368 
type right_cylinder 1.000000E+00 -1.308608E+01 -1.145032E+01 -3.636042E-01
<surface> 369 
type right_cylinder 1.000000E+00 -1.308608E+01 -1.145032E+01 -2.650788E-01
<surface> 370 
type right_cylinder 1.000000E+00 -1.472184E+01 -1.145032E+01 -3.636042E-01
<surface> 371 
type right_cylinder 1.000000E+00 -1.472184E+01 -1.145032E+01 -2.650788E-01
<surface> 372 
type right_cylinder 1.000000E+00 -1.635760E+01 -1.145032E+01 -3.636042E-01
<surface> 373 
type right_cylinder 1.000000E+00 -1.635760E+01 -1.145032E+01 -2.650788E-01
<surface> 374 
type right_cylinder 1.000000E+00 -1.799336E+01 -1.145032E+01 -3.636042E-01
<surface> 375 
type right_cylinder 1.000000E+00 -1.799336E+01 -1.145032E+01 -2.650788E-01
<surface> 376 
type right_cylinder 1.000000E+00 -1.962912E+01 -1.145032E+01 -3.636042E-01
<surface> 377 
type right_cylinder 1.000000E+00 -1.962912E+01 -1.145032E+01 -2.650788E-01
<surface> 378 
type right_cylinder 1.000000E+00 -2.126488E+01 -1.145032E+01 -3.636042E-01
<surface> 379 
type right_cylinder 1.000000E+00 -2.126488E+01 -1.145032E+01 -2.650788E-01
<surface> 380 
type right_cylinder 1.000000E+00 -2.290064E+01 -1.145032E+01 -3.636042E-01
<surface> 381 
type right_cylinder 1.000000E+00 -2.290064E+01 -1.145032E+01 -2.650788E-01
<surface> 382 
type right_cylinder 1.000000E+00 -2.453640E+01 -1.145032E+01 -3.636042E-01
<surface> 383 
type right_cylinder 1.000000E+00 -2.453640E+01 -1.145032E+01 -2.650788E-01
<surface> 384 
type right_cylinder 1.000000E+00 -2.617216E+01 -1.145032E+01 -3.636042E-01
<surface> 385 
type right_cylinder 1.000000E+00 -2.617216E+01 -1.145032E+01 -2.650788E-01
<surface> 386 
type right_cylinder 1.000000E+00 -2.780792E+01 -1.145032E+01 -3.636042E-01
<surface> 387 
type right_cylinder 1.000000E+00 -2.780792E+01 -1.145032E+01 -2.650788E-01
<surface> 388 
type right_cylinder 1.000000E+00 -2.944368E+01 -1.145032E+01 -3.636042E-01
<surface> 389 
type right_cylinder 1.000000E+00 -2.944368E+01 -1.145032E+01 -2.650788E-01
<surface> 390 
type right_cylinder 1.000000E+00 -3.107944E+01 -1.145032E+01 -3.636042E-01
<surface> 391 
type right_cylinder 1.000000E+00 -3.107944E+01 -1.145032E+01 -2.650788E-01
<surface> 392 
type right_cylinder 1.000000E+00 -3.271520E+01 -1.145032E+01 -3.636042E-01
<surface> 393 
type right_cylinder 1.000000E+00 -3.271520E+01 -1.145032E+01 -2.650788E-01
<surface> 394 
type right_cylinder 1.000000E+00 -3.435096E+01 -1.145032E+01 -3.636042E-01
<surface> 395 
type right_cylinder 1.000000E+00 -3.435096E+01 -1.145032E+01 -2.650788E-01
<surface> 396 
type right_cylinder 1.000000E+00 -3.598672E+01 -1.145032E+01 -3.636042E-01
<surface> 397 
type right_cylinder 1.000000E+00 -3.598672E+01 -1.145032E+01 -2.650788E-01
<surface> 398 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -1.390396E+01
<surface> 399 
type right_cylinder 1.000000E+00 0.000000E+00 -1.308608E+01 -3.636042E-01
<surface> 400 
type right_cylinder 1.000000E+00 0.000000E+00 -1.308608E+01 -2.650788E-01
<surface> 401 
type right_cylinder 1.000000E+00 -1.635760E+00 -1.308608E+01 -3.636042E-01
<surface> 402 
type right_cylinder 1.000000E+00 -1.635760E+00 -1.308608E+01 -2.650788E-01
<surface> 403 
type right_cylinder 1.000000E+00 -3.271520E+00 -1.308608E+01 -3.636042E-01
<surface> 404 
type right_cylinder 1.000000E+00 -3.271520E+00 -1.308608E+01 -2.650788E-01
<surface> 405 
type right_cylinder 1.000000E+00 -4.907280E+00 -1.308608E+01 -3.636042E-01
<surface> 406 
type right_cylinder 1.000000E+00 -4.907280E+00 -1.308608E+01 -2.650788E-01
<surface> 407 
type right_cylinder 1.000000E+00 -6.543040E+00 -1.308608E+01 -3.636042E-01
<surface> 408 
type right_cylinder 1.000000E+00 -6.543040E+00 -1.308608E+01 -2.650788E-01
<surface> 409 
type right_cylinder 1.000000E+00 -8.178800E+00 -1.308608E+01 -3.636042E-01
<surface> 410 
type right_cylinder 1.000000E+00 -8.178800E+00 -1.308608E+01 -2.650788E-01
<surface> 411 
type right_cylinder 1.000000E+00 -9.814560E+00 -1.308608E+01 -3.636042E-01
<surface> 412 
type right_cylinder 1.000000E+00 -9.814560E+00 -1.308608E+01 -2.650788E-01
<surface> 413 
type right_cylinder 1.000000E+00 -1.145032E+01 -1.308608E+01 -3.636042E-01
<surface> 414 
type right_cylinder 1.000000E+00 -1.145032E+01 -1.308608E+01 -2.650788E-01
<surface> 415 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -1.553972E+01
<surface> 416 
type right_cylinder 1.000000E+00 0.000000E+00 -1.472184E+01 -3.636042E-01
<surface> 417 
type right_cylinder 1.000000E+00 0.000000E+00 -1.472184E+01 -2.650788E-01
<surface> 418 
type right_cylinder 1.000000E+00 -1.635760E+00 -1.472184E+01 -3.636042E-01
<surface> 419 
type right_cylinder 1.000000E+00 -1.635760E+00 -1.472184E+01 -2.650788E-01
<surface> 420 
type right_cylinder 1.000000E+00 -3.271520E+00 -1.472184E+01 -3.636042E-01
<surface> 421 
type right_cylinder 1.000000E+00 -3.271520E+00 -1.472184E+01 -2.650788E-01
<surface> 422 
type right_cylinder 1.000000E+00 -4.907280E+00 -1.472184E+01 -3.636042E-01
<surface> 423 
type right_cylinder 1.000000E+00 -4.907280E+00 -1.472184E+01 -2.650788E-01
<surface> 424 
type right_cylinder 1.000000E+00 -6.543040E+00 -1.472184E+01 -3.636042E-01
<surface> 425 
type right_cylinder 1.000000E+00 -6.543040E+00 -1.472184E+01 -2.650788E-01
<surface> 426 
type right_cylinder 1.000000E+00 -8.178800E+00 -1.472184E+01 -3.636042E-01
<surface> 427 
type right_cylinder 1.000000E+00 -8.178800E+00 -1.472184E+01 -2.650788E-01
<surface> 428 
type right_cylinder 1.000000E+00 -9.814560E+00 -1.472184E+01 -3.636042E-01
<surface> 429 
type right_cylinder 1.000000E+00 -9.814560E+00 -1.472184E+01 -2.650788E-01
<surface> 430 
type right_cylinder 1.000000E+00 -1.145032E+01 -1.472184E+01 -3.636042E-01
<surface> 431 
type right_cylinder 1.000000E+00 -1.145032E+01 -1.472184E+01 -2.650788E-01
<surface> 432 
type right_cylinder 1.000000E+00 0.000000E+00 -1.635760E+01 -3.636042E-01
<surface> 433 
type right_cylinder 1.000000E+00 0.000000E+00 -1.635760E+01 -2.650788E-01
<surface> 434 
type right_cylinder 1.000000E+00 -1.635760E+00 -1.635760E+01 -3.636042E-01
<surface> 435 
type right_cylinder 1.000000E+00 -1.635760E+00 -1.635760E+01 -2.650788E-01
<surface> 436 
type right_cylinder 1.000000E+00 -4.907280E+00 -1.635760E+01 -3.636042E-01
<surface> 437 
type right_cylinder 1.000000E+00 -4.907280E+00 -1.635760E+01 -2.650788E-01
<surface> 438 
type right_cylinder 1.000000E+00 -6.543040E+00 -1.635760E+01 -3.636042E-01
<surface> 439 
type right_cylinder 1.000000E+00 -6.543040E+00 -1.635760E+01 -2.650788E-01
<surface> 440 
type right_cylinder 1.000000E+00 -8.178800E+00 -1.635760E+01 -3.636042E-01
<surface> 441 
type right_cylinder 1.000000E+00 -8.178800E+00 -1.635760E+01 -2.650788E-01
<surface> 442 
type right_cylinder 1.000000E+00 -9.814560E+00 -1.635760E+01 -3.636042E-01
<surface> 443 
type right_cylinder 1.000000E+00 -9.814560E+00 -1.635760E+01 -2.650788E-01
<surface> 444 
type right_cylinder 1.000000E+00 -1.145032E+01 -1.635760E+01 -3.636042E-01
<surface> 445 
type right_cylinder 1.000000E+00 -1.145032E+01 -1.635760E+01 -2.650788E-01
<surface> 446 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -1.881124E+01
<surface> 447 
type right_cylinder 1.000000E+00 0.000000E+00 -1.799336E+01 -3.636042E-01
<surface> 448 
type right_cylinder 1.000000E+00 0.000000E+00 -1.799336E+01 -2.650788E-01
<surface> 449 
type right_cylinder 1.000000E+00 -1.635760E+00 -1.799336E+01 -3.636042E-01
<surface> 450 
type right_cylinder 1.000000E+00 -1.635760E+00 -1.799336E+01 -2.650788E-01
<surface> 451 
type right_cylinder 1.000000E+00 -3.271520E+00 -1.799336E+01 -3.636042E-01
<surface> 452 
type right_cylinder 1.000000E+00 -3.271520E+00 -1.799336E+01 -2.650788E-01
<surface> 453 
type right_cylinder 1.000000E+00 -4.907280E+00 -1.799336E+01 -3.636042E-01
<surface> 454 
type right_cylinder 1.000000E+00 -4.907280E+00 -1.799336E+01 -2.650788E-01
<surface> 455 
type right_cylinder 1.000000E+00 -8.178800E+00 -1.799336E+01 -3.636042E-01
<surface> 456 
type right_cylinder 1.000000E+00 -8.178800E+00 -1.799336E+01 -2.650788E-01
<surface> 457 
type right_cylinder 1.000000E+00 -9.814560E+00 -1.799336E+01 -3.636042E-01
<surface> 458 
type right_cylinder 1.000000E+00 -9.814560E+00 -1.799336E+01 -2.650788E-01
<surface> 459 
type right_cylinder 1.000000E+00 -1.145032E+01 -1.799336E+01 -3.636042E-01
<surface> 460 
type right_cylinder 1.000000E+00 -1.145032E+01 -1.799336E+01 -2.650788E-01
<surface> 461 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -2.044700E+01
<surface> 462 
type right_cylinder 1.000000E+00 0.000000E+00 -1.962912E+01 -3.636042E-01
<surface> 463 
type right_cylinder 1.000000E+00 0.000000E+00 -1.962912E+01 -2.650788E-01
<surface> 464 
type right_cylinder 1.000000E+00 -1.635760E+00 -1.962912E+01 -3.636042E-01
<surface> 465 
type right_cylinder 1.000000E+00 -1.635760E+00 -1.962912E+01 -2.650788E-01
<surface> 466 
type right_cylinder 1.000000E+00 -3.271520E+00 -1.962912E+01 -3.636042E-01
<surface> 467 
type right_cylinder 1.000000E+00 -3.271520E+00 -1.962912E+01 -2.650788E-01
<surface> 468 
type right_cylinder 1.000000E+00 -4.907280E+00 -1.962912E+01 -3.636042E-01
<surface> 469 
type right_cylinder 1.000000E+00 -4.907280E+00 -1.962912E+01 -2.650788E-01
<surface> 470 
type right_cylinder 1.000000E+00 -6.543040E+00 -1.962912E+01 -3.636042E-01
<surface> 471 
type right_cylinder 1.000000E+00 -6.543040E+00 -1.962912E+01 -2.650788E-01
<surface> 472 
type right_cylinder 1.000000E+00 -8.178800E+00 -1.962912E+01 -3.636042E-01
<surface> 473 
type right_cylinder 1.000000E+00 -8.178800E+00 -1.962912E+01 -2.650788E-01
<surface> 474 
type right_cylinder 1.000000E+00 -9.814560E+00 -1.962912E+01 -3.636042E-01
<surface> 475 
type right_cylinder 1.000000E+00 -9.814560E+00 -1.962912E+01 -2.650788E-01
<surface> 476 
type right_cylinder 1.000000E+00 -1.145032E+01 -1.962912E+01 -3.636042E-01
<surface> 477 
type right_cylinder 1.000000E+00 -1.145032E+01 -1.962912E+01 -2.650788E-01
<surface> 478 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -2.208276E+01
<surface> 479 
type right_cylinder 1.000000E+00 0.000000E+00 -2.126488E+01 -3.636042E-01
<surface> 480 
type right_cylinder 1.000000E+00 0.000000E+00 -2.126488E+01 -2.650788E-01
<surface> 481 
type right_cylinder 1.000000E+00 -1.635760E+00 -2.126488E+01 -3.636042E-01
<surface> 482 
type right_cylinder 1.000000E+00 -1.635760E+00 -2.126488E+01 -2.650788E-01
<surface> 483 
type right_cylinder 1.000000E+00 -4.907280E+00 -2.126488E+01 -3.636042E-01
<surface> 484 
type right_cylinder 1.000000E+00 -4.907280E+00 -2.126488E+01 -2.650788E-01
<surface> 485 
type right_cylinder 1.000000E+00 -6.543040E+00 -2.126488E+01 -3.636042E-01
<surface> 486 
type right_cylinder 1.000000E+00 -6.543040E+00 -2.126488E+01 -2.650788E-01
<surface> 487 
type right_cylinder 1.000000E+00 -9.814560E+00 -2.126488E+01 -3.636042E-01
<surface> 488 
type right_cylinder 1.000000E+00 -9.814560E+00 -2.126488E+01 -2.650788E-01
<surface> 489 
type right_cylinder 1.000000E+00 -1.145032E+01 -2.126488E+01 -3.636042E-01
<surface> 490 
type right_cylinder 1.000000E+00 -1.145032E+01 -2.126488E+01 -2.650788E-01
<surface> 491 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -2.371852E+01
<surface> 492 
type right_cylinder 1.000000E+00 0.000000E+00 -2.290064E+01 -3.636042E-01
<surface> 493 
type right_cylinder 1.000000E+00 0.000000E+00 -2.290064E+01 -2.650788E-01
<surface> 494 
type right_cylinder 1.000000E+00 -1.635760E+00 -2.290064E+01 -3.636042E-01
<surface> 495 
type right_cylinder 1.000000E+00 -1.635760E+00 -2.290064E+01 -2.650788E-01
<surface> 496 
type right_cylinder 1.000000E+00 -3.271520E+00 -2.290064E+01 -3.636042E-01
<surface> 497 
type right_cylinder 1.000000E+00 -3.271520E+00 -2.290064E+01 -2.650788E-01
<surface> 498 
type right_cylinder 1.000000E+00 -4.907280E+00 -2.290064E+01 -3.636042E-01
<surface> 499 
type right_cylinder 1.000000E+00 -4.907280E+00 -2.290064E+01 -2.650788E-01
<surface> 500 
type right_cylinder 1.000000E+00 -6.543040E+00 -2.290064E+01 -3.636042E-01
<surface> 501 
type right_cylinder 1.000000E+00 -6.543040E+00 -2.290064E+01 -2.650788E-01
<surface> 502 
type right_cylinder 1.000000E+00 -8.178800E+00 -2.290064E+01 -3.636042E-01
<surface> 503 
type right_cylinder 1.000000E+00 -8.178800E+00 -2.290064E+01 -2.650788E-01
<surface> 504 
type right_cylinder 1.000000E+00 -9.814560E+00 -2.290064E+01 -3.636042E-01
<surface> 505 
type right_cylinder 1.000000E+00 -9.814560E+00 -2.290064E+01 -2.650788E-01
<surface> 506 
type right_cylinder 1.000000E+00 -1.145032E+01 -2.290064E+01 -3.636042E-01
<surface> 507 
type right_cylinder 1.000000E+00 -1.145032E+01 -2.290064E+01 -2.650788E-01
<surface> 508 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -2.535428E+01
<surface> 509 
type right_cylinder 1.000000E+00 -1.635760E+00 -2.453640E+01 -3.636042E-01
<surface> 510 
type right_cylinder 1.000000E+00 -1.635760E+00 -2.453640E+01 -2.650788E-01
<surface> 511 
type right_cylinder 1.000000E+00 -3.271520E+00 -2.453640E+01 -3.636042E-01
<surface> 512 
type right_cylinder 1.000000E+00 -3.271520E+00 -2.453640E+01 -2.650788E-01
<surface> 513 
type right_cylinder 1.000000E+00 -4.907280E+00 -2.453640E+01 -3.636042E-01
<surface> 514 
type right_cylinder 1.000000E+00 -4.907280E+00 -2.453640E+01 -2.650788E-01
<surface> 515 
type right_cylinder 1.000000E+00 -6.543040E+00 -2.453640E+01 -3.636042E-01
<surface> 516 
type right_cylinder 1.000000E+00 -6.543040E+00 -2.453640E+01 -2.650788E-01
<surface> 517 
type right_cylinder 1.000000E+00 -8.178800E+00 -2.453640E+01 -3.636042E-01
<surface> 518 
type right_cylinder 1.000000E+00 -8.178800E+00 -2.453640E+01 -2.650788E-01
<surface> 519 
type right_cylinder 1.000000E+00 -9.814560E+00 -2.453640E+01 -3.636042E-01
<surface> 520 
type right_cylinder 1.000000E+00 -9.814560E+00 -2.453640E+01 -2.650788E-01
<surface> 521 
type right_cylinder 1.000000E+00 -1.145032E+01 -2.453640E+01 -3.636042E-01
<surface> 522 
type right_cylinder 1.000000E+00 -1.145032E+01 -2.453640E+01 -2.650788E-01
<surface> 523 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -2.699004E+01
<surface> 524 
type right_cylinder 1.000000E+00 0.000000E+00 -2.617216E+01 -3.636042E-01
<surface> 525 
type right_cylinder 1.000000E+00 0.000000E+00 -2.617216E+01 -2.650788E-01
<surface> 526 
type right_cylinder 1.000000E+00 -1.635760E+00 -2.617216E+01 -3.636042E-01
<surface> 527 
type right_cylinder 1.000000E+00 -1.635760E+00 -2.617216E+01 -2.650788E-01
<surface> 528 
type right_cylinder 1.000000E+00 -3.271520E+00 -2.617216E+01 -3.636042E-01
<surface> 529 
type right_cylinder 1.000000E+00 -3.271520E+00 -2.617216E+01 -2.650788E-01
<surface> 530 
type right_cylinder 1.000000E+00 -4.907280E+00 -2.617216E+01 -3.636042E-01
<surface> 531 
type right_cylinder 1.000000E+00 -4.907280E+00 -2.617216E+01 -2.650788E-01
<surface> 532 
type right_cylinder 1.000000E+00 -6.543040E+00 -2.617216E+01 -3.636042E-01
<surface> 533 
type right_cylinder 1.000000E+00 -6.543040E+00 -2.617216E+01 -2.650788E-01
<surface> 534 
type right_cylinder 1.000000E+00 -8.178800E+00 -2.617216E+01 -3.636042E-01
<surface> 535 
type right_cylinder 1.000000E+00 -8.178800E+00 -2.617216E+01 -2.650788E-01
<surface> 536 
type right_cylinder 1.000000E+00 -9.814560E+00 -2.617216E+01 -3.636042E-01
<surface> 537 
type right_cylinder 1.000000E+00 -9.814560E+00 -2.617216E+01 -2.650788E-01
<surface> 538 
type right_cylinder 1.000000E+00 -1.145032E+01 -2.617216E+01 -3.636042E-01
<surface> 539 
type right_cylinder 1.000000E+00 -1.145032E+01 -2.617216E+01 -2.650788E-01
<surface> 540 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -2.862580E+01
<surface> 541 
type right_cylinder 1.000000E+00 0.000000E+00 -2.780792E+01 -3.636042E-01
<surface> 542 
type right_cylinder 1.000000E+00 0.000000E+00 -2.780792E+01 -2.650788E-01
<surface> 543 
type right_cylinder 1.000000E+00 -1.635760E+00 -2.780792E+01 -3.636042E-01
<surface> 544 
type right_cylinder 1.000000E+00 -1.635760E+00 -2.780792E+01 -2.650788E-01
<surface> 545 
type right_cylinder 1.000000E+00 -4.907280E+00 -2.780792E+01 -3.636042E-01
<surface> 546 
type right_cylinder 1.000000E+00 -4.907280E+00 -2.780792E+01 -2.650788E-01
<surface> 547 
type right_cylinder 1.000000E+00 -6.543040E+00 -2.780792E+01 -3.636042E-01
<surface> 548 
type right_cylinder 1.000000E+00 -6.543040E+00 -2.780792E+01 -2.650788E-01
<surface> 549 
type right_cylinder 1.000000E+00 -9.814560E+00 -2.780792E+01 -3.636042E-01
<surface> 550 
type right_cylinder 1.000000E+00 -9.814560E+00 -2.780792E+01 -2.650788E-01
<surface> 551 
type right_cylinder 1.000000E+00 -1.145032E+01 -2.780792E+01 -3.636042E-01
<surface> 552 
type right_cylinder 1.000000E+00 -1.145032E+01 -2.780792E+01 -2.650788E-01
<surface> 553 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -3.026156E+01
<surface> 554 
type right_cylinder 1.000000E+00 0.000000E+00 -2.944368E+01 -3.636042E-01
<surface> 555 
type right_cylinder 1.000000E+00 0.000000E+00 -2.944368E+01 -2.650788E-01
<surface> 556 
type right_cylinder 1.000000E+00 -1.635760E+00 -2.944368E+01 -3.636042E-01
<surface> 557 
type right_cylinder 1.000000E+00 -1.635760E+00 -2.944368E+01 -2.650788E-01
<surface> 558 
type right_cylinder 1.000000E+00 -3.271520E+00 -2.944368E+01 -3.636042E-01
<surface> 559 
type right_cylinder 1.000000E+00 -3.271520E+00 -2.944368E+01 -2.650788E-01
<surface> 560 
type right_cylinder 1.000000E+00 -4.907280E+00 -2.944368E+01 -3.636042E-01
<surface> 561 
type right_cylinder 1.000000E+00 -4.907280E+00 -2.944368E+01 -2.650788E-01
<surface> 562 
type right_cylinder 1.000000E+00 -6.543040E+00 -2.944368E+01 -3.636042E-01
<surface> 563 
type right_cylinder 1.000000E+00 -6.543040E+00 -2.944368E+01 -2.650788E-01
<surface> 564 
type right_cylinder 1.000000E+00 -8.178800E+00 -2.944368E+01 -3.636042E-01
<surface> 565 
type right_cylinder 1.000000E+00 -8.178800E+00 -2.944368E+01 -2.650788E-01
<surface> 566 
type right_cylinder 1.000000E+00 -9.814560E+00 -2.944368E+01 -3.636042E-01
<surface> 567 
type right_cylinder 1.000000E+00 -9.814560E+00 -2.944368E+01 -2.650788E-01
<surface> 568 
type right_cylinder 1.000000E+00 -1.145032E+01 -2.944368E+01 -3.636042E-01
<surface> 569 
type right_cylinder 1.000000E+00 -1.145032E+01 -2.944368E+01 -2.650788E-01
<surface> 570 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -3.189732E+01
<surface> 571 
type right_cylinder 1.000000E+00 0.000000E+00 -3.107944E+01 -3.636042E-01
<surface> 572 
type right_cylinder 1.000000E+00 0.000000E+00 -3.107944E+01 -2.650788E-01
<surface> 573 
type right_cylinder 1.000000E+00 -1.635760E+00 -3.107944E+01 -3.636042E-01
<surface> 574 
type right_cylinder 1.000000E+00 -1.635760E+00 -3.107944E+01 -2.650788E-01
<surface> 575 
type right_cylinder 1.000000E+00 -3.271520E+00 -3.107944E+01 -3.636042E-01
<surface> 576 
type right_cylinder 1.000000E+00 -3.271520E+00 -3.107944E+01 -2.650788E-01
<surface> 577 
type right_cylinder 1.000000E+00 -4.907280E+00 -3.107944E+01 -3.636042E-01
<surface> 578 
type right_cylinder 1.000000E+00 -4.907280E+00 -3.107944E+01 -2.650788E-01
<surface> 579 
type right_cylinder 1.000000E+00 -8.178800E+00 -3.107944E+01 -3.636042E-01
<surface> 580 
type right_cylinder 1.000000E+00 -8.178800E+00 -3.107944E+01 -2.650788E-01
<surface> 581 
type right_cylinder 1.000000E+00 -9.814560E+00 -3.107944E+01 -3.636042E-01
<surface> 582 
type right_cylinder 1.000000E+00 -9.814560E+00 -3.107944E+01 -2.650788E-01
<surface> 583 
type right_cylinder 1.000000E+00 -1.145032E+01 -3.107944E+01 -3.636042E-01
<surface> 584 
type right_cylinder 1.000000E+00 -1.145032E+01 -3.107944E+01 -2.650788E-01
<surface> 585 
type right_cylinder 1.000000E+00 0.000000E+00 -3.271520E+01 -3.636042E-01
<surface> 586 
type right_cylinder 1.000000E+00 0.000000E+00 -3.271520E+01 -2.650788E-01
<surface> 587 
type right_cylinder 1.000000E+00 -1.635760E+00 -3.271520E+01 -3.636042E-01
<surface> 588 
type right_cylinder 1.000000E+00 -1.635760E+00 -3.271520E+01 -2.650788E-01
<surface> 589 
type right_cylinder 1.000000E+00 -4.907280E+00 -3.271520E+01 -3.636042E-01
<surface> 590 
type right_cylinder 1.000000E+00 -4.907280E+00 -3.271520E+01 -2.650788E-01
<surface> 591 
type right_cylinder 1.000000E+00 -6.543040E+00 -3.271520E+01 -3.636042E-01
<surface> 592 
type right_cylinder 1.000000E+00 -6.543040E+00 -3.271520E+01 -2.650788E-01
<surface> 593 
type right_cylinder 1.000000E+00 -8.178800E+00 -3.271520E+01 -3.636042E-01
<surface> 594 
type right_cylinder 1.000000E+00 -8.178800E+00 -3.271520E+01 -2.650788E-01
<surface> 595 
type right_cylinder 1.000000E+00 -9.814560E+00 -3.271520E+01 -3.636042E-01
<surface> 596 
type right_cylinder 1.000000E+00 -9.814560E+00 -3.271520E+01 -2.650788E-01
<surface> 597 
type right_cylinder 1.000000E+00 -1.145032E+01 -3.271520E+01 -3.636042E-01
<surface> 598 
type right_cylinder 1.000000E+00 -1.145032E+01 -3.271520E+01 -2.650788E-01
<surface> 599 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -3.516884E+01
<surface> 600 
type right_cylinder 1.000000E+00 0.000000E+00 -3.435096E+01 -3.636042E-01
<surface> 601 
type right_cylinder 1.000000E+00 0.000000E+00 -3.435096E+01 -2.650788E-01
<surface> 602 
type right_cylinder 1.000000E+00 -1.635760E+00 -3.435096E+01 -3.636042E-01
<surface> 603 
type right_cylinder 1.000000E+00 -1.635760E+00 -3.435096E+01 -2.650788E-01
<surface> 604 
type right_cylinder 1.000000E+00 -3.271520E+00 -3.435096E+01 -3.636042E-01
<surface> 605 
type right_cylinder 1.000000E+00 -3.271520E+00 -3.435096E+01 -2.650788E-01
<surface> 606 
type right_cylinder 1.000000E+00 -4.907280E+00 -3.435096E+01 -3.636042E-01
<surface> 607 
type right_cylinder 1.000000E+00 -4.907280E+00 -3.435096E+01 -2.650788E-01
<surface> 608 
type right_cylinder 1.000000E+00 -6.543040E+00 -3.435096E+01 -3.636042E-01
<surface> 609 
type right_cylinder 1.000000E+00 -6.543040E+00 -3.435096E+01 -2.650788E-01
<surface> 610 
type right_cylinder 1.000000E+00 -8.178800E+00 -3.435096E+01 -3.636042E-01
<surface> 611 
type right_cylinder 1.000000E+00 -8.178800E+00 -3.435096E+01 -2.650788E-01
<surface> 612 
type right_cylinder 1.000000E+00 -9.814560E+00 -3.435096E+01 -3.636042E-01
<surface> 613 
type right_cylinder 1.000000E+00 -9.814560E+00 -3.435096E+01 -2.650788E-01
<surface> 614 
type right_cylinder 1.000000E+00 -1.145032E+01 -3.435096E+01 -3.636042E-01
<surface> 615 
type right_cylinder 1.000000E+00 -1.145032E+01 -3.435096E+01 -2.650788E-01
<surface> 616 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -3.680460E+01
<surface> 617 
type right_cylinder 1.000000E+00 0.000000E+00 -3.598672E+01 -3.636042E-01
<surface> 618 
type right_cylinder 1.000000E+00 0.000000E+00 -3.598672E+01 -2.650788E-01
<surface> 619 
type right_cylinder 1.000000E+00 -1.635760E+00 -3.598672E+01 -3.636042E-01
<surface> 620 
type right_cylinder 1.000000E+00 -1.635760E+00 -3.598672E+01 -2.650788E-01
<surface> 621 
type right_cylinder 1.000000E+00 -3.271520E+00 -3.598672E+01 -3.636042E-01
<surface> 622 
type right_cylinder 1.000000E+00 -3.271520E+00 -3.598672E+01 -2.650788E-01
<surface> 623 
type right_cylinder 1.000000E+00 -4.907280E+00 -3.598672E+01 -3.636042E-01
<surface> 624 
type right_cylinder 1.000000E+00 -4.907280E+00 -3.598672E+01 -2.650788E-01
<surface> 625 
type right_cylinder 1.000000E+00 -6.543040E+00 -3.598672E+01 -3.636042E-01
<surface> 626 
type right_cylinder 1.000000E+00 -6.543040E+00 -3.598672E+01 -2.650788E-01
<surface> 627 
type right_cylinder 1.000000E+00 -8.178800E+00 -3.598672E+01 -3.636042E-01
<surface> 628 
type right_cylinder 1.000000E+00 -8.178800E+00 -3.598672E+01 -2.650788E-01
<surface> 629 
type right_cylinder 1.000000E+00 -9.814560E+00 -3.598672E+01 -3.636042E-01
<surface> 630 
type right_cylinder 1.000000E+00 -9.814560E+00 -3.598672E+01 -2.650788E-01
<surface> 631 
type right_cylinder 1.000000E+00 -1.145032E+01 -3.598672E+01 -3.636042E-01
<surface> 632 
type right_cylinder 1.000000E+00 -1.145032E+01 -3.598672E+01 -2.650788E-01
<surface> 633 
type right_cylinder 1.000000E+00 -1.308608E+01 -1.308608E+01 -3.636042E-01
<surface> 634 
type right_cylinder 1.000000E+00 -1.308608E+01 -1.308608E+01 -2.650788E-01
<surface> 635 
type right_cylinder 1.000000E+00 -1.472184E+01 -1.308608E+01 -3.636042E-01
<surface> 636 
type right_cylinder 1.000000E+00 -1.472184E+01 -1.308608E+01 -2.650788E-01
<surface> 637 
type right_cylinder 1.000000E+00 -1.635760E+01 -1.308608E+01 -3.636042E-01
<surface> 638 
type right_cylinder 1.000000E+00 -1.635760E+01 -1.308608E+01 -2.650788E-01
<surface> 639 
type right_cylinder 1.000000E+00 -1.799336E+01 -1.308608E+01 -3.636042E-01
<surface> 640 
type right_cylinder 1.000000E+00 -1.799336E+01 -1.308608E+01 -2.650788E-01
<surface> 641 
type right_cylinder 1.000000E+00 -1.962912E+01 -1.308608E+01 -3.636042E-01
<surface> 642 
type right_cylinder 1.000000E+00 -1.962912E+01 -1.308608E+01 -2.650788E-01
<surface> 643 
type right_cylinder 1.000000E+00 -2.126488E+01 -1.308608E+01 -3.636042E-01
<surface> 644 
type right_cylinder 1.000000E+00 -2.126488E+01 -1.308608E+01 -2.650788E-01
<surface> 645 
type right_cylinder 1.000000E+00 -2.290064E+01 -1.308608E+01 -3.636042E-01
<surface> 646 
type right_cylinder 1.000000E+00 -2.290064E+01 -1.308608E+01 -2.650788E-01
<surface> 647 
type right_cylinder 1.000000E+00 -2.453640E+01 -1.308608E+01 -3.636042E-01
<surface> 648 
type right_cylinder 1.000000E+00 -2.453640E+01 -1.308608E+01 -2.650788E-01
<surface> 649 
type right_cylinder 1.000000E+00 -2.617216E+01 -1.308608E+01 -3.636042E-01
<surface> 650 
type right_cylinder 1.000000E+00 -2.617216E+01 -1.308608E+01 -2.650788E-01
<surface> 651 
type right_cylinder 1.000000E+00 -2.780792E+01 -1.308608E+01 -3.636042E-01
<surface> 652 
type right_cylinder 1.000000E+00 -2.780792E+01 -1.308608E+01 -2.650788E-01
<surface> 653 
type right_cylinder 1.000000E+00 -2.944368E+01 -1.308608E+01 -3.636042E-01
<surface> 654 
type right_cylinder 1.000000E+00 -2.944368E+01 -1.308608E+01 -2.650788E-01
<surface> 655 
type right_cylinder 1.000000E+00 -3.107944E+01 -1.308608E+01 -3.636042E-01
<surface> 656 
type right_cylinder 1.000000E+00 -3.107944E+01 -1.308608E+01 -2.650788E-01
<surface> 657 
type right_cylinder 1.000000E+00 -3.271520E+01 -1.308608E+01 -3.636042E-01
<surface> 658 
type right_cylinder 1.000000E+00 -3.271520E+01 -1.308608E+01 -2.650788E-01
<surface> 659 
type right_cylinder 1.000000E+00 -3.435096E+01 -1.308608E+01 -3.636042E-01
<surface> 660 
type right_cylinder 1.000000E+00 -3.435096E+01 -1.308608E+01 -2.650788E-01
<surface> 661 
type right_cylinder 1.000000E+00 -3.598672E+01 -1.308608E+01 -3.636042E-01
<surface> 662 
type right_cylinder 1.000000E+00 -3.598672E+01 -1.308608E+01 -2.650788E-01
<surface> 663 
type right_cylinder 1.000000E+00 -1.308608E+01 -1.472184E+01 -3.636042E-01
<surface> 664 
type right_cylinder 1.000000E+00 -1.308608E+01 -1.472184E+01 -2.650788E-01
<surface> 665 
type right_cylinder 1.000000E+00 -1.472184E+01 -1.472184E+01 -3.636042E-01
<surface> 666 
type right_cylinder 1.000000E+00 -1.472184E+01 -1.472184E+01 -2.650788E-01
<surface> 667 
type right_cylinder 1.000000E+00 -1.635760E+01 -1.472184E+01 -3.636042E-01
<surface> 668 
type right_cylinder 1.000000E+00 -1.635760E+01 -1.472184E+01 -2.650788E-01
<surface> 669 
type right_cylinder 1.000000E+00 -1.799336E+01 -1.472184E+01 -3.636042E-01
<surface> 670 
type right_cylinder 1.000000E+00 -1.799336E+01 -1.472184E+01 -2.650788E-01
<surface> 671 
type right_cylinder 1.000000E+00 -1.962912E+01 -1.472184E+01 -3.636042E-01
<surface> 672 
type right_cylinder 1.000000E+00 -1.962912E+01 -1.472184E+01 -2.650788E-01
<surface> 673 
type right_cylinder 1.000000E+00 -2.126488E+01 -1.472184E+01 -3.636042E-01
<surface> 674 
type right_cylinder 1.000000E+00 -2.126488E+01 -1.472184E+01 -2.650788E-01
<surface> 675 
type right_cylinder 1.000000E+00 -2.290064E+01 -1.472184E+01 -3.636042E-01
<surface> 676 
type right_cylinder 1.000000E+00 -2.290064E+01 -1.472184E+01 -2.650788E-01
<surface> 677 
type right_cylinder 1.000000E+00 -2.453640E+01 -1.472184E+01 -3.636042E-01
<surface> 678 
type right_cylinder 1.000000E+00 -2.453640E+01 -1.472184E+01 -2.650788E-01
<surface> 679 
type right_cylinder 1.000000E+00 -2.617216E+01 -1.472184E+01 -3.636042E-01
<surface> 680 
type right_cylinder 1.000000E+00 -2.617216E+01 -1.472184E+01 -2.650788E-01
<surface> 681 
type right_cylinder 1.000000E+00 -2.780792E+01 -1.472184E+01 -3.636042E-01
<surface> 682 
type right_cylinder 1.000000E+00 -2.780792E+01 -1.472184E+01 -2.650788E-01
<surface> 683 
type right_cylinder 1.000000E+00 -2.944368E+01 -1.472184E+01 -3.636042E-01
<surface> 684 
type right_cylinder 1.000000E+00 -2.944368E+01 -1.472184E+01 -2.650788E-01
<surface> 685 
type right_cylinder 1.000000E+00 -3.107944E+01 -1.472184E+01 -3.636042E-01
<surface> 686 
type right_cylinder 1.000000E+00 -3.107944E+01 -1.472184E+01 -2.650788E-01
<surface> 687 
type right_cylinder 1.000000E+00 -3.271520E+01 -1.472184E+01 -3.636042E-01
<surface> 688 
type right_cylinder 1.000000E+00 -3.271520E+01 -1.472184E+01 -2.650788E-01
<surface> 689 
type right_cylinder 1.000000E+00 -3.435096E+01 -1.472184E+01 -3.636042E-01
<surface> 690 
type right_cylinder 1.000000E+00 -3.435096E+01 -1.472184E+01 -2.650788E-01
<surface> 691 
type right_cylinder 1.000000E+00 -3.598672E+01 -1.472184E+01 -3.636042E-01
<surface> 692 
type right_cylinder 1.000000E+00 -3.598672E+01 -1.472184E+01 -2.650788E-01
<surface> 693 
type right_cylinder 1.000000E+00 -1.308608E+01 -1.635760E+01 -3.636042E-01
<surface> 694 
type right_cylinder 1.000000E+00 -1.308608E+01 -1.635760E+01 -2.650788E-01
<surface> 695 
type right_cylinder 1.000000E+00 -1.472184E+01 -1.635760E+01 -3.636042E-01
<surface> 696 
type right_cylinder 1.000000E+00 -1.472184E+01 -1.635760E+01 -2.650788E-01
<surface> 697 
type right_cylinder 1.000000E+00 -1.635760E+01 -1.635760E+01 -3.636042E-01
<surface> 698 
type right_cylinder 1.000000E+00 -1.635760E+01 -1.635760E+01 -2.650788E-01
<surface> 699 
type right_cylinder 1.000000E+00 -1.799336E+01 -1.635760E+01 -3.636042E-01
<surface> 700 
type right_cylinder 1.000000E+00 -1.799336E+01 -1.635760E+01 -2.650788E-01
<surface> 701 
type right_cylinder 1.000000E+00 -1.962912E+01 -1.635760E+01 -3.636042E-01
<surface> 702 
type right_cylinder 1.000000E+00 -1.962912E+01 -1.635760E+01 -2.650788E-01
<surface> 703 
type right_cylinder 1.000000E+00 -2.290064E+01 -1.635760E+01 -3.636042E-01
<surface> 704 
type right_cylinder 1.000000E+00 -2.290064E+01 -1.635760E+01 -2.650788E-01
<surface> 705 
type right_cylinder 1.000000E+00 -2.453640E+01 -1.635760E+01 -3.636042E-01
<surface> 706 
type right_cylinder 1.000000E+00 -2.453640E+01 -1.635760E+01 -2.650788E-01
<surface> 707 
type right_cylinder 1.000000E+00 -2.617216E+01 -1.635760E+01 -3.636042E-01
<surface> 708 
type right_cylinder 1.000000E+00 -2.617216E+01 -1.635760E+01 -2.650788E-01
<surface> 709 
type right_cylinder 1.000000E+00 -2.944368E+01 -1.635760E+01 -3.636042E-01
<surface> 710 
type right_cylinder 1.000000E+00 -2.944368E+01 -1.635760E+01 -2.650788E-01
<surface> 711 
type right_cylinder 1.000000E+00 -3.107944E+01 -1.635760E+01 -3.636042E-01
<surface> 712 
type right_cylinder 1.000000E+00 -3.107944E+01 -1.635760E+01 -2.650788E-01
<surface> 713 
type right_cylinder 1.000000E+00 -3.271520E+01 -1.635760E+01 -3.636042E-01
<surface> 714 
type right_cylinder 1.000000E+00 -3.271520E+01 -1.635760E+01 -2.650788E-01
<surface> 715 
type right_cylinder 1.000000E+00 -3.435096E+01 -1.635760E+01 -3.636042E-01
<surface> 716 
type right_cylinder 1.000000E+00 -3.435096E+01 -1.635760E+01 -2.650788E-01
<surface> 717 
type right_cylinder 1.000000E+00 -3.598672E+01 -1.635760E+01 -3.636042E-01
<surface> 718 
type right_cylinder 1.000000E+00 -3.598672E+01 -1.635760E+01 -2.650788E-01
<surface> 719 
type right_cylinder 1.000000E+00 -1.308608E+01 -1.799336E+01 -3.636042E-01
<surface> 720 
type right_cylinder 1.000000E+00 -1.308608E+01 -1.799336E+01 -2.650788E-01
<surface> 721 
type right_cylinder 1.000000E+00 -1.472184E+01 -1.799336E+01 -3.636042E-01
<surface> 722 
type right_cylinder 1.000000E+00 -1.472184E+01 -1.799336E+01 -2.650788E-01
<surface> 723 
type right_cylinder 1.000000E+00 -1.635760E+01 -1.799336E+01 -3.636042E-01
<surface> 724 
type right_cylinder 1.000000E+00 -1.635760E+01 -1.799336E+01 -2.650788E-01
<surface> 725 
type right_cylinder 1.000000E+00 -1.962912E+01 -1.799336E+01 -3.636042E-01
<surface> 726 
type right_cylinder 1.000000E+00 -1.962912E+01 -1.799336E+01 -2.650788E-01
<surface> 727 
type right_cylinder 1.000000E+00 -2.126488E+01 -1.799336E+01 -3.636042E-01
<surface> 728 
type right_cylinder 1.000000E+00 -2.126488E+01 -1.799336E+01 -2.650788E-01
<surface> 729 
type right_cylinder 1.000000E+00 -2.290064E+01 -1.799336E+01 -3.636042E-01
<surface> 730 
type right_cylinder 1.000000E+00 -2.290064E+01 -1.799336E+01 -2.650788E-01
<surface> 731 
type right_cylinder 1.000000E+00 -2.453640E+01 -1.799336E+01 -3.636042E-01
<surface> 732 
type right_cylinder 1.000000E+00 -2.453640E+01 -1.799336E+01 -2.650788E-01
<surface> 733 
type right_cylinder 1.000000E+00 -2.617216E+01 -1.799336E+01 -3.636042E-01
<surface> 734 
type right_cylinder 1.000000E+00 -2.617216E+01 -1.799336E+01 -2.650788E-01
<surface> 735 
type right_cylinder 1.000000E+00 -2.780792E+01 -1.799336E+01 -3.636042E-01
<surface> 736 
type right_cylinder 1.000000E+00 -2.780792E+01 -1.799336E+01 -2.650788E-01
<surface> 737 
type right_cylinder 1.000000E+00 -2.944368E+01 -1.799336E+01 -3.636042E-01
<surface> 738 
type right_cylinder 1.000000E+00 -2.944368E+01 -1.799336E+01 -2.650788E-01
<surface> 739 
type right_cylinder 1.000000E+00 -3.271520E+01 -1.799336E+01 -3.636042E-01
<surface> 740 
type right_cylinder 1.000000E+00 -3.271520E+01 -1.799336E+01 -2.650788E-01
<surface> 741 
type right_cylinder 1.000000E+00 -3.435096E+01 -1.799336E+01 -3.636042E-01
<surface> 742 
type right_cylinder 1.000000E+00 -3.435096E+01 -1.799336E+01 -2.650788E-01
<surface> 743 
type right_cylinder 1.000000E+00 -3.598672E+01 -1.799336E+01 -3.636042E-01
<surface> 744 
type right_cylinder 1.000000E+00 -3.598672E+01 -1.799336E+01 -2.650788E-01
<surface> 745 
type right_cylinder 1.000000E+00 -1.308608E+01 -1.962912E+01 -3.636042E-01
<surface> 746 
type right_cylinder 1.000000E+00 -1.308608E+01 -1.962912E+01 -2.650788E-01
<surface> 747 
type right_cylinder 1.000000E+00 -1.472184E+01 -1.962912E+01 -3.636042E-01
<surface> 748 
type right_cylinder 1.000000E+00 -1.472184E+01 -1.962912E+01 -2.650788E-01
<surface> 749 
type right_cylinder 1.000000E+00 -1.635760E+01 -1.962912E+01 -3.636042E-01
<surface> 750 
type right_cylinder 1.000000E+00 -1.635760E+01 -1.962912E+01 -2.650788E-01
<surface> 751 
type right_cylinder 1.000000E+00 -1.799336E+01 -1.962912E+01 -3.636042E-01
<surface> 752 
type right_cylinder 1.000000E+00 -1.799336E+01 -1.962912E+01 -2.650788E-01
<surface> 753 
type right_cylinder 1.000000E+00 -1.962912E+01 -1.962912E+01 -3.636042E-01
<surface> 754 
type right_cylinder 1.000000E+00 -1.962912E+01 -1.962912E+01 -2.650788E-01
<surface> 755 
type right_cylinder 1.000000E+00 -2.126488E+01 -1.962912E+01 -3.636042E-01
<surface> 756 
type right_cylinder 1.000000E+00 -2.126488E+01 -1.962912E+01 -2.650788E-01
<surface> 757 
type right_cylinder 1.000000E+00 -2.290064E+01 -1.962912E+01 -3.636042E-01
<surface> 758 
type right_cylinder 1.000000E+00 -2.290064E+01 -1.962912E+01 -2.650788E-01
<surface> 759 
type right_cylinder 1.000000E+00 -2.453640E+01 -1.962912E+01 -3.636042E-01
<surface> 760 
type right_cylinder 1.000000E+00 -2.453640E+01 -1.962912E+01 -2.650788E-01
<surface> 761 
type right_cylinder 1.000000E+00 -2.617216E+01 -1.962912E+01 -3.636042E-01
<surface> 762 
type right_cylinder 1.000000E+00 -2.617216E+01 -1.962912E+01 -2.650788E-01
<surface> 763 
type right_cylinder 1.000000E+00 -2.780792E+01 -1.962912E+01 -3.636042E-01
<surface> 764 
type right_cylinder 1.000000E+00 -2.780792E+01 -1.962912E+01 -2.650788E-01
<surface> 765 
type right_cylinder 1.000000E+00 -2.944368E+01 -1.962912E+01 -3.636042E-01
<surface> 766 
type right_cylinder 1.000000E+00 -2.944368E+01 -1.962912E+01 -2.650788E-01
<surface> 767 
type right_cylinder 1.000000E+00 -3.107944E+01 -1.962912E+01 -3.636042E-01
<surface> 768 
type right_cylinder 1.000000E+00 -3.107944E+01 -1.962912E+01 -2.650788E-01
<surface> 769 
type right_cylinder 1.000000E+00 -3.271520E+01 -1.962912E+01 -3.636042E-01
<surface> 770 
type right_cylinder 1.000000E+00 -3.271520E+01 -1.962912E+01 -2.650788E-01
<surface> 771 
type right_cylinder 1.000000E+00 -3.435096E+01 -1.962912E+01 -3.636042E-01
<surface> 772 
type right_cylinder 1.000000E+00 -3.435096E+01 -1.962912E+01 -2.650788E-01
<surface> 773 
type right_cylinder 1.000000E+00 -3.598672E+01 -1.962912E+01 -3.636042E-01
<surface> 774 
type right_cylinder 1.000000E+00 -3.598672E+01 -1.962912E+01 -2.650788E-01
<surface> 775 
type right_cylinder 1.000000E+00 -1.308608E+01 -2.126488E+01 -3.636042E-01
<surface> 776 
type right_cylinder 1.000000E+00 -1.308608E+01 -2.126488E+01 -2.650788E-01
<surface> 777 
type right_cylinder 1.000000E+00 -1.472184E+01 -2.126488E+01 -3.636042E-01
<surface> 778 
type right_cylinder 1.000000E+00 -1.472184E+01 -2.126488E+01 -2.650788E-01
<surface> 779 
type right_cylinder 1.000000E+00 -1.799336E+01 -2.126488E+01 -3.636042E-01
<surface> 780 
type right_cylinder 1.000000E+00 -1.799336E+01 -2.126488E+01 -2.650788E-01
<surface> 781 
type right_cylinder 1.000000E+00 -1.962912E+01 -2.126488E+01 -3.636042E-01
<surface> 782 
type right_cylinder 1.000000E+00 -1.962912E+01 -2.126488E+01 -2.650788E-01
<surface> 783 
type right_cylinder 1.000000E+00 -2.290064E+01 -2.126488E+01 -3.636042E-01
<surface> 784 
type right_cylinder 1.000000E+00 -2.290064E+01 -2.126488E+01 -2.650788E-01
<surface> 785 
type right_cylinder 1.000000E+00 -2.453640E+01 -2.126488E+01 -3.636042E-01
<surface> 786 
type right_cylinder 1.000000E+00 -2.453640E+01 -2.126488E+01 -2.650788E-01
<surface> 787 
type right_cylinder 1.000000E+00 -2.617216E+01 -2.126488E+01 -3.636042E-01
<surface> 788 
type right_cylinder 1.000000E+00 -2.617216E+01 -2.126488E+01 -2.650788E-01
<surface> 789 
type right_cylinder 1.000000E+00 -2.944368E+01 -2.126488E+01 -3.636042E-01
<surface> 790 
type right_cylinder 1.000000E+00 -2.944368E+01 -2.126488E+01 -2.650788E-01
<surface> 791 
type right_cylinder 1.000000E+00 -3.107944E+01 -2.126488E+01 -3.636042E-01
<surface> 792 
type right_cylinder 1.000000E+00 -3.107944E+01 -2.126488E+01 -2.650788E-01
<surface> 793 
type right_cylinder 1.000000E+00 -3.435096E+01 -2.126488E+01 -3.636042E-01
<surface> 794 
type right_cylinder 1.000000E+00 -3.435096E+01 -2.126488E+01 -2.650788E-01
<surface> 795 
type right_cylinder 1.000000E+00 -3.598672E+01 -2.126488E+01 -3.636042E-01
<surface> 796 
type right_cylinder 1.000000E+00 -3.598672E+01 -2.126488E+01 -2.650788E-01
<surface> 797 
type right_cylinder 1.000000E+00 -1.308608E+01 -2.290064E+01 -3.636042E-01
<surface> 798 
type right_cylinder 1.000000E+00 -1.308608E+01 -2.290064E+01 -2.650788E-01
<surface> 799 
type right_cylinder 1.000000E+00 -1.472184E+01 -2.290064E+01 -3.636042E-01
<surface> 800 
type right_cylinder 1.000000E+00 -1.472184E+01 -2.290064E+01 -2.650788E-01
<surface> 801 
type right_cylinder 1.000000E+00 -1.635760E+01 -2.290064E+01 -3.636042E-01
<surface> 802 
type right_cylinder 1.000000E+00 -1.635760E+01 -2.290064E+01 -2.650788E-01
<surface> 803 
type right_cylinder 1.000000E+00 -1.799336E+01 -2.290064E+01 -3.636042E-01
<surface> 804 
type right_cylinder 1.000000E+00 -1.799336E+01 -2.290064E+01 -2.650788E-01
<surface> 805 
type right_cylinder 1.000000E+00 -1.962912E+01 -2.290064E+01 -3.636042E-01
<surface> 806 
type right_cylinder 1.000000E+00 -1.962912E+01 -2.290064E+01 -2.650788E-01
<surface> 807 
type right_cylinder 1.000000E+00 -2.126488E+01 -2.290064E+01 -3.636042E-01
<surface> 808 
type right_cylinder 1.000000E+00 -2.126488E+01 -2.290064E+01 -2.650788E-01
<surface> 809 
type right_cylinder 1.000000E+00 -2.290064E+01 -2.290064E+01 -3.636042E-01
<surface> 810 
type right_cylinder 1.000000E+00 -2.290064E+01 -2.290064E+01 -2.650788E-01
<surface> 811 
type right_cylinder 1.000000E+00 -2.453640E+01 -2.290064E+01 -3.636042E-01
<surface> 812 
type right_cylinder 1.000000E+00 -2.453640E+01 -2.290064E+01 -2.650788E-01
<surface> 813 
type right_cylinder 1.000000E+00 -2.617216E+01 -2.290064E+01 -3.636042E-01
<surface> 814 
type right_cylinder 1.000000E+00 -2.617216E+01 -2.290064E+01 -2.650788E-01
<surface> 815 
type right_cylinder 1.000000E+00 -2.780792E+01 -2.290064E+01 -3.636042E-01
<surface> 816 
type right_cylinder 1.000000E+00 -2.780792E+01 -2.290064E+01 -2.650788E-01
<surface> 817 
type right_cylinder 1.000000E+00 -2.944368E+01 -2.290064E+01 -3.636042E-01
<surface> 818 
type right_cylinder 1.000000E+00 -2.944368E+01 -2.290064E+01 -2.650788E-01
<surface> 819 
type right_cylinder 1.000000E+00 -3.107944E+01 -2.290064E+01 -3.636042E-01
<surface> 820 
type right_cylinder 1.000000E+00 -3.107944E+01 -2.290064E+01 -2.650788E-01
<surface> 821 
type right_cylinder 1.000000E+00 -3.271520E+01 -2.290064E+01 -3.636042E-01
<surface> 822 
type right_cylinder 1.000000E+00 -3.271520E+01 -2.290064E+01 -2.650788E-01
<surface> 823 
type right_cylinder 1.000000E+00 -3.435096E+01 -2.290064E+01 -3.636042E-01
<surface> 824 
type right_cylinder 1.000000E+00 -3.435096E+01 -2.290064E+01 -2.650788E-01
<surface> 825 
type right_cylinder 1.000000E+00 -3.598672E+01 -2.290064E+01 -3.636042E-01
<surface> 826 
type right_cylinder 1.000000E+00 -3.598672E+01 -2.290064E+01 -2.650788E-01
<surface> 827 
type right_cylinder 1.000000E+00 -1.308608E+01 -2.453640E+01 -3.636042E-01
<surface> 828 
type right_cylinder 1.000000E+00 -1.308608E+01 -2.453640E+01 -2.650788E-01
<surface> 829 
type right_cylinder 1.000000E+00 -1.472184E+01 -2.453640E+01 -3.636042E-01
<surface> 830 
type right_cylinder 1.000000E+00 -1.472184E+01 -2.453640E+01 -2.650788E-01
<surface> 831 
type right_cylinder 1.000000E+00 -1.635760E+01 -2.453640E+01 -3.636042E-01
<surface> 832 
type right_cylinder 1.000000E+00 -1.635760E+01 -2.453640E+01 -2.650788E-01
<surface> 833 
type right_cylinder 1.000000E+00 -1.799336E+01 -2.453640E+01 -3.636042E-01
<surface> 834 
type right_cylinder 1.000000E+00 -1.799336E+01 -2.453640E+01 -2.650788E-01
<surface> 835 
type right_cylinder 1.000000E+00 -1.962912E+01 -2.453640E+01 -3.636042E-01
<surface> 836 
type right_cylinder 1.000000E+00 -1.962912E+01 -2.453640E+01 -2.650788E-01
<surface> 837 
type right_cylinder 1.000000E+00 -2.126488E+01 -2.453640E+01 -3.636042E-01
<surface> 838 
type right_cylinder 1.000000E+00 -2.126488E+01 -2.453640E+01 -2.650788E-01
<surface> 839 
type right_cylinder 1.000000E+00 -2.290064E+01 -2.453640E+01 -3.636042E-01
<surface> 840 
type right_cylinder 1.000000E+00 -2.290064E+01 -2.453640E+01 -2.650788E-01
<surface> 841 
type right_cylinder 1.000000E+00 -2.617216E+01 -2.453640E+01 -3.636042E-01
<surface> 842 
type right_cylinder 1.000000E+00 -2.617216E+01 -2.453640E+01 -2.650788E-01
<surface> 843 
type right_cylinder 1.000000E+00 -2.780792E+01 -2.453640E+01 -3.636042E-01
<surface> 844 
type right_cylinder 1.000000E+00 -2.780792E+01 -2.453640E+01 -2.650788E-01
<surface> 845 
type right_cylinder 1.000000E+00 -2.944368E+01 -2.453640E+01 -3.636042E-01
<surface> 846 
type right_cylinder 1.000000E+00 -2.944368E+01 -2.453640E+01 -2.650788E-01
<surface> 847 
type right_cylinder 1.000000E+00 -3.107944E+01 -2.453640E+01 -3.636042E-01
<surface> 848 
type right_cylinder 1.000000E+00 -3.107944E+01 -2.453640E+01 -2.650788E-01
<surface> 849 
type right_cylinder 1.000000E+00 -3.271520E+01 -2.453640E+01 -3.636042E-01
<surface> 850 
type right_cylinder 1.000000E+00 -3.271520E+01 -2.453640E+01 -2.650788E-01
<surface> 851 
type right_cylinder 1.000000E+00 -3.435096E+01 -2.453640E+01 -3.636042E-01
<surface> 852 
type right_cylinder 1.000000E+00 -3.435096E+01 -2.453640E+01 -2.650788E-01
<surface> 853 
type right_cylinder 1.000000E+00 -3.598672E+01 -2.453640E+01 -3.636042E-01
<surface> 854 
type right_cylinder 1.000000E+00 -3.598672E+01 -2.453640E+01 -2.650788E-01
<surface> 855 
type right_cylinder 1.000000E+00 -1.308608E+01 -2.617216E+01 -3.636042E-01
<surface> 856 
type right_cylinder 1.000000E+00 -1.308608E+01 -2.617216E+01 -2.650788E-01
<surface> 857 
type right_cylinder 1.000000E+00 -1.472184E+01 -2.617216E+01 -3.636042E-01
<surface> 858 
type right_cylinder 1.000000E+00 -1.472184E+01 -2.617216E+01 -2.650788E-01
<surface> 859 
type right_cylinder 1.000000E+00 -1.635760E+01 -2.617216E+01 -3.636042E-01
<surface> 860 
type right_cylinder 1.000000E+00 -1.635760E+01 -2.617216E+01 -2.650788E-01
<surface> 861 
type right_cylinder 1.000000E+00 -1.799336E+01 -2.617216E+01 -3.636042E-01
<surface> 862 
type right_cylinder 1.000000E+00 -1.799336E+01 -2.617216E+01 -2.650788E-01
<surface> 863 
type right_cylinder 1.000000E+00 -1.962912E+01 -2.617216E+01 -3.636042E-01
<surface> 864 
type right_cylinder 1.000000E+00 -1.962912E+01 -2.617216E+01 -2.650788E-01
<surface> 865 
type right_cylinder 1.000000E+00 -2.126488E+01 -2.617216E+01 -3.636042E-01
<surface> 866 
type right_cylinder 1.000000E+00 -2.126488E+01 -2.617216E+01 -2.650788E-01
<surface> 867 
type right_cylinder 1.000000E+00 -2.290064E+01 -2.617216E+01 -3.636042E-01
<surface> 868 
type right_cylinder 1.000000E+00 -2.290064E+01 -2.617216E+01 -2.650788E-01
<surface> 869 
type right_cylinder 1.000000E+00 -2.453640E+01 -2.617216E+01 -3.636042E-01
<surface> 870 
type right_cylinder 1.000000E+00 -2.453640E+01 -2.617216E+01 -2.650788E-01
<surface> 871 
type right_cylinder 1.000000E+00 -2.617216E+01 -2.617216E+01 -3.636042E-01
<surface> 872 
type right_cylinder 1.000000E+00 -2.617216E+01 -2.617216E+01 -2.650788E-01
<surface> 873 
type right_cylinder 1.000000E+00 -2.780792E+01 -2.617216E+01 -3.636042E-01
<surface> 874 
type right_cylinder 1.000000E+00 -2.780792E+01 -2.617216E+01 -2.650788E-01
<surface> 875 
type right_cylinder 1.000000E+00 -2.944368E+01 -2.617216E+01 -3.636042E-01
<surface> 876 
type right_cylinder 1.000000E+00 -2.944368E+01 -2.617216E+01 -2.650788E-01
<surface> 877 
type right_cylinder 1.000000E+00 -3.107944E+01 -2.617216E+01 -3.636042E-01
<surface> 878 
type right_cylinder 1.000000E+00 -3.107944E+01 -2.617216E+01 -2.650788E-01
<surface> 879 
type right_cylinder 1.000000E+00 -3.271520E+01 -2.617216E+01 -3.636042E-01
<surface> 880 
type right_cylinder 1.000000E+00 -3.271520E+01 -2.617216E+01 -2.650788E-01
<surface> 881 
type right_cylinder 1.000000E+00 -3.435096E+01 -2.617216E+01 -3.636042E-01
<surface> 882 
type right_cylinder 1.000000E+00 -3.435096E+01 -2.617216E+01 -2.650788E-01
<surface> 883 
type right_cylinder 1.000000E+00 -3.598672E+01 -2.617216E+01 -3.636042E-01
<surface> 884 
type right_cylinder 1.000000E+00 -3.598672E+01 -2.617216E+01 -2.650788E-01
<surface> 885 
type right_cylinder 1.000000E+00 -1.308608E+01 -2.780792E+01 -3.636042E-01
<surface> 886 
type right_cylinder 1.000000E+00 -1.308608E+01 -2.780792E+01 -2.650788E-01
<surface> 887 
type right_cylinder 1.000000E+00 -1.472184E+01 -2.780792E+01 -3.636042E-01
<surface> 888 
type right_cylinder 1.000000E+00 -1.472184E+01 -2.780792E+01 -2.650788E-01
<surface> 889 
type right_cylinder 1.000000E+00 -1.799336E+01 -2.780792E+01 -3.636042E-01
<surface> 890 
type right_cylinder 1.000000E+00 -1.799336E+01 -2.780792E+01 -2.650788E-01
<surface> 891 
type right_cylinder 1.000000E+00 -1.962912E+01 -2.780792E+01 -3.636042E-01
<surface> 892 
type right_cylinder 1.000000E+00 -1.962912E+01 -2.780792E+01 -2.650788E-01
<surface> 893 
type right_cylinder 1.000000E+00 -2.290064E+01 -2.780792E+01 -3.636042E-01
<surface> 894 
type right_cylinder 1.000000E+00 -2.290064E+01 -2.780792E+01 -2.650788E-01
<surface> 895 
type right_cylinder 1.000000E+00 -2.453640E+01 -2.780792E+01 -3.636042E-01
<surface> 896 
type right_cylinder 1.000000E+00 -2.453640E+01 -2.780792E+01 -2.650788E-01
<surface> 897 
type right_cylinder 1.000000E+00 -2.617216E+01 -2.780792E+01 -3.636042E-01
<surface> 898 
type right_cylinder 1.000000E+00 -2.617216E+01 -2.780792E+01 -2.650788E-01
<surface> 899 
type right_cylinder 1.000000E+00 -2.944368E+01 -2.780792E+01 -3.636042E-01
<surface> 900 
type right_cylinder 1.000000E+00 -2.944368E+01 -2.780792E+01 -2.650788E-01
<surface> 901 
type right_cylinder 1.000000E+00 -3.107944E+01 -2.780792E+01 -3.636042E-01
<surface> 902 
type right_cylinder 1.000000E+00 -3.107944E+01 -2.780792E+01 -2.650788E-01
<surface> 903 
type right_cylinder 1.000000E+00 -3.435096E+01 -2.780792E+01 -3.636042E-01
<surface> 904 
type right_cylinder 1.000000E+00 -3.435096E+01 -2.780792E+01 -2.650788E-01
<surface> 905 
type right_cylinder 1.000000E+00 -3.598672E+01 -2.780792E+01 -3.636042E-01
<surface> 906 
type right_cylinder 1.000000E+00 -3.598672E+01 -2.780792E+01 -2.650788E-01
<surface> 907 
type right_cylinder 1.000000E+00 -1.308608E+01 -2.944368E+01 -3.636042E-01
<surface> 908 
type right_cylinder 1.000000E+00 -1.308608E+01 -2.944368E+01 -2.650788E-01
<surface> 909 
type right_cylinder 1.000000E+00 -1.472184E+01 -2.944368E+01 -3.636042E-01
<surface> 910 
type right_cylinder 1.000000E+00 -1.472184E+01 -2.944368E+01 -2.650788E-01
<surface> 911 
type right_cylinder 1.000000E+00 -1.635760E+01 -2.944368E+01 -3.636042E-01
<surface> 912 
type right_cylinder 1.000000E+00 -1.635760E+01 -2.944368E+01 -2.650788E-01
<surface> 913 
type right_cylinder 1.000000E+00 -1.799336E+01 -2.944368E+01 -3.636042E-01
<surface> 914 
type right_cylinder 1.000000E+00 -1.799336E+01 -2.944368E+01 -2.650788E-01
<surface> 915 
type right_cylinder 1.000000E+00 -1.962912E+01 -2.944368E+01 -3.636042E-01
<surface> 916 
type right_cylinder 1.000000E+00 -1.962912E+01 -2.944368E+01 -2.650788E-01
<surface> 917 
type right_cylinder 1.000000E+00 -2.126488E+01 -2.944368E+01 -3.636042E-01
<surface> 918 
type right_cylinder 1.000000E+00 -2.126488E+01 -2.944368E+01 -2.650788E-01
<surface> 919 
type right_cylinder 1.000000E+00 -2.290064E+01 -2.944368E+01 -3.636042E-01
<surface> 920 
type right_cylinder 1.000000E+00 -2.290064E+01 -2.944368E+01 -2.650788E-01
<surface> 921 
type right_cylinder 1.000000E+00 -2.453640E+01 -2.944368E+01 -3.636042E-01
<surface> 922 
type right_cylinder 1.000000E+00 -2.453640E+01 -2.944368E+01 -2.650788E-01
<surface> 923 
type right_cylinder 1.000000E+00 -2.617216E+01 -2.944368E+01 -3.636042E-01
<surface> 924 
type right_cylinder 1.000000E+00 -2.617216E+01 -2.944368E+01 -2.650788E-01
<surface> 925 
type right_cylinder 1.000000E+00 -2.780792E+01 -2.944368E+01 -3.636042E-01
<surface> 926 
type right_cylinder 1.000000E+00 -2.780792E+01 -2.944368E+01 -2.650788E-01
<surface> 927 
type right_cylinder 1.000000E+00 -2.944368E+01 -2.944368E+01 -3.636042E-01
<surface> 928 
type right_cylinder 1.000000E+00 -2.944368E+01 -2.944368E+01 -2.650788E-01
<surface> 929 
type right_cylinder 1.000000E+00 -3.107944E+01 -2.944368E+01 -3.636042E-01
<surface> 930 
type right_cylinder 1.000000E+00 -3.107944E+01 -2.944368E+01 -2.650788E-01
<surface> 931 
type right_cylinder 1.000000E+00 -3.271520E+01 -2.944368E+01 -3.636042E-01
<surface> 932 
type right_cylinder 1.000000E+00 -3.271520E+01 -2.944368E+01 -2.650788E-01
<surface> 933 
type right_cylinder 1.000000E+00 -3.435096E+01 -2.944368E+01 -3.636042E-01
<surface> 934 
type right_cylinder 1.000000E+00 -3.435096E+01 -2.944368E+01 -2.650788E-01
<surface> 935 
type right_cylinder 1.000000E+00 -3.598672E+01 -2.944368E+01 -3.636042E-01
<surface> 936 
type right_cylinder 1.000000E+00 -3.598672E+01 -2.944368E+01 -2.650788E-01
<surface> 937 
type right_cylinder 1.000000E+00 -1.308608E+01 -3.107944E+01 -3.636042E-01
<surface> 938 
type right_cylinder 1.000000E+00 -1.308608E+01 -3.107944E+01 -2.650788E-01
<surface> 939 
type right_cylinder 1.000000E+00 -1.472184E+01 -3.107944E+01 -3.636042E-01
<surface> 940 
type right_cylinder 1.000000E+00 -1.472184E+01 -3.107944E+01 -2.650788E-01
<surface> 941 
type right_cylinder 1.000000E+00 -1.635760E+01 -3.107944E+01 -3.636042E-01
<surface> 942 
type right_cylinder 1.000000E+00 -1.635760E+01 -3.107944E+01 -2.650788E-01
<surface> 943 
type right_cylinder 1.000000E+00 -1.962912E+01 -3.107944E+01 -3.636042E-01
<surface> 944 
type right_cylinder 1.000000E+00 -1.962912E+01 -3.107944E+01 -2.650788E-01
<surface> 945 
type right_cylinder 1.000000E+00 -2.126488E+01 -3.107944E+01 -3.636042E-01
<surface> 946 
type right_cylinder 1.000000E+00 -2.126488E+01 -3.107944E+01 -2.650788E-01
<surface> 947 
type right_cylinder 1.000000E+00 -2.290064E+01 -3.107944E+01 -3.636042E-01
<surface> 948 
type right_cylinder 1.000000E+00 -2.290064E+01 -3.107944E+01 -2.650788E-01
<surface> 949 
type right_cylinder 1.000000E+00 -2.453640E+01 -3.107944E+01 -3.636042E-01
<surface> 950 
type right_cylinder 1.000000E+00 -2.453640E+01 -3.107944E+01 -2.650788E-01
<surface> 951 
type right_cylinder 1.000000E+00 -2.617216E+01 -3.107944E+01 -3.636042E-01
<surface> 952 
type right_cylinder 1.000000E+00 -2.617216E+01 -3.107944E+01 -2.650788E-01
<surface> 953 
type right_cylinder 1.000000E+00 -2.780792E+01 -3.107944E+01 -3.636042E-01
<surface> 954 
type right_cylinder 1.000000E+00 -2.780792E+01 -3.107944E+01 -2.650788E-01
<surface> 955 
type right_cylinder 1.000000E+00 -2.944368E+01 -3.107944E+01 -3.636042E-01
<surface> 956 
type right_cylinder 1.000000E+00 -2.944368E+01 -3.107944E+01 -2.650788E-01
<surface> 957 
type right_cylinder 1.000000E+00 -3.271520E+01 -3.107944E+01 -3.636042E-01
<surface> 958 
type right_cylinder 1.000000E+00 -3.271520E+01 -3.107944E+01 -2.650788E-01
<surface> 959 
type right_cylinder 1.000000E+00 -3.435096E+01 -3.107944E+01 -3.636042E-01
<surface> 960 
type right_cylinder 1.000000E+00 -3.435096E+01 -3.107944E+01 -2.650788E-01
<surface> 961 
type right_cylinder 1.000000E+00 -3.598672E+01 -3.107944E+01 -3.636042E-01
<surface> 962 
type right_cylinder 1.000000E+00 -3.598672E+01 -3.107944E+01 -2.650788E-01
<surface> 963 
type right_cylinder 1.000000E+00 -1.308608E+01 -3.271520E+01 -3.636042E-01
<surface> 964 
type right_cylinder 1.000000E+00 -1.308608E+01 -3.271520E+01 -2.650788E-01
<surface> 965 
type right_cylinder 1.000000E+00 -1.472184E+01 -3.271520E+01 -3.636042E-01
<surface> 966 
type right_cylinder 1.000000E+00 -1.472184E+01 -3.271520E+01 -2.650788E-01
<surface> 967 
type right_cylinder 1.000000E+00 -1.635760E+01 -3.271520E+01 -3.636042E-01
<surface> 968 
type right_cylinder 1.000000E+00 -1.635760E+01 -3.271520E+01 -2.650788E-01
<surface> 969 
type right_cylinder 1.000000E+00 -1.799336E+01 -3.271520E+01 -3.636042E-01
<surface> 970 
type right_cylinder 1.000000E+00 -1.799336E+01 -3.271520E+01 -2.650788E-01
<surface> 971 
type right_cylinder 1.000000E+00 -1.962912E+01 -3.271520E+01 -3.636042E-01
<surface> 972 
type right_cylinder 1.000000E+00 -1.962912E+01 -3.271520E+01 -2.650788E-01
<surface> 973 
type right_cylinder 1.000000E+00 -2.290064E+01 -3.271520E+01 -3.636042E-01
<surface> 974 
type right_cylinder 1.000000E+00 -2.290064E+01 -3.271520E+01 -2.650788E-01
<surface> 975 
type right_cylinder 1.000000E+00 -2.453640E+01 -3.271520E+01 -3.636042E-01
<surface> 976 
type right_cylinder 1.000000E+00 -2.453640E+01 -3.271520E+01 -2.650788E-01
<surface> 977 
type right_cylinder 1.000000E+00 -2.617216E+01 -3.271520E+01 -3.636042E-01
<surface> 978 
type right_cylinder 1.000000E+00 -2.617216E+01 -3.271520E+01 -2.650788E-01
<surface> 979 
type right_cylinder 1.000000E+00 -2.944368E+01 -3.271520E+01 -3.636042E-01
<surface> 980 
type right_cylinder 1.000000E+00 -2.944368E+01 -3.271520E+01 -2.650788E-01
<surface> 981 
type right_cylinder 1.000000E+00 -3.107944E+01 -3.271520E+01 -3.636042E-01
<surface> 982 
type right_cylinder 1.000000E+00 -3.107944E+01 -3.271520E+01 -2.650788E-01
<surface> 983 
type right_cylinder 1.000000E+00 -3.271520E+01 -3.271520E+01 -3.636042E-01
<surface> 984 
type right_cylinder 1.000000E+00 -3.271520E+01 -3.271520E+01 -2.650788E-01
<surface> 985 
type right_cylinder 1.000000E+00 -3.435096E+01 -3.271520E+01 -3.636042E-01
<surface> 986 
type right_cylinder 1.000000E+00 -3.435096E+01 -3.271520E+01 -2.650788E-01
<surface> 987 
type right_cylinder 1.000000E+00 -3.598672E+01 -3.271520E+01 -3.636042E-01
<surface> 988 
type right_cylinder 1.000000E+00 -3.598672E+01 -3.271520E+01 -2.650788E-01
<surface> 989 
type right_cylinder 1.000000E+00 -1.308608E+01 -3.435096E+01 -3.636042E-01
<surface> 990 
type right_cylinder 1.000000E+00 -1.308608E+01 -3.435096E+01 -2.650788E-01
<surface> 991 
type right_cylinder 1.000000E+00 -1.472184E+01 -3.435096E+01 -3.636042E-01
<surface> 992 
type right_cylinder 1.000000E+00 -1.472184E+01 -3.435096E+01 -2.650788E-01
<surface> 993 
type right_cylinder 1.000000E+00 -1.635760E+01 -3.435096E+01 -3.636042E-01
<surface> 994 
type right_cylinder 1.000000E+00 -1.635760E+01 -3.435096E+01 -2.650788E-01
<surface> 995 
type right_cylinder 1.000000E+00 -1.799336E+01 -3.435096E+01 -3.636042E-01
<surface> 996 
type right_cylinder 1.000000E+00 -1.799336E+01 -3.435096E+01 -2.650788E-01
<surface> 997 
type right_cylinder 1.000000E+00 -1.962912E+01 -3.435096E+01 -3.636042E-01
<surface> 998 
type right_cylinder 1.000000E+00 -1.962912E+01 -3.435096E+01 -2.650788E-01
<surface> 999 
type right_cylinder 1.000000E+00 -2.126488E+01 -3.435096E+01 -3.636042E-01
<surface> 1000 
type right_cylinder 1.000000E+00 -2.126488E+01 -3.435096E+01 -2.650788E-01
<surface> 1001 
type right_cylinder 1.000000E+00 -2.290064E+01 -3.435096E+01 -3.636042E-01
<surface> 1002 
type right_cylinder 1.000000E+00 -2.290064E+01 -3.435096E+01 -2.650788E-01
<surface> 1003 
type right_cylinder 1.000000E+00 -2.453640E+01 -3.435096E+01 -3.636042E-01
<surface> 1004 
type right_cylinder 1.000000E+00 -2.453640E+01 -3.435096E+01 -2.650788E-01
<surface> 1005 
type right_cylinder 1.000000E+00 -2.617216E+01 -3.435096E+01 -3.636042E-01
<surface> 1006 
type right_cylinder 1.000000E+00 -2.617216E+01 -3.435096E+01 -2.650788E-01
<surface> 1007 
type right_cylinder 1.000000E+00 -2.780792E+01 -3.435096E+01 -3.636042E-01
<surface> 1008 
type right_cylinder 1.000000E+00 -2.780792E+01 -3.435096E+01 -2.650788E-01
<surface> 1009 
type right_cylinder 1.000000E+00 -2.944368E+01 -3.435096E+01 -3.636042E-01
<surface> 1010 
type right_cylinder 1.000000E+00 -2.944368E+01 -3.435096E+01 -2.650788E-01
<surface> 1011 
type right_cylinder 1.000000E+00 -3.107944E+01 -3.435096E+01 -3.636042E-01
<surface> 1012 
type right_cylinder 1.000000E+00 -3.107944E+01 -3.435096E+01 -2.650788E-01
<surface> 1013 
type right_cylinder 1.000000E+00 -3.271520E+01 -3.435096E+01 -3.636042E-01
<surface> 1014 
type right_cylinder 1.000000E+00 -3.271520E+01 -3.435096E+01 -2.650788E-01
<surface> 1015 
type right_cylinder 1.000000E+00 -3.435096E+01 -3.435096E+01 -3.636042E-01
<surface> 1016 
type right_cylinder 1.000000E+00 -3.435096E+01 -3.435096E+01 -2.650788E-01
<surface> 1017 
type right_cylinder 1.000000E+00 -3.598672E+01 -3.435096E+01 -3.636042E-01
<surface> 1018 
type right_cylinder 1.000000E+00 -3.598672E+01 -3.435096E+01 -2.650788E-01
<surface> 1019 
type right_cylinder 1.000000E+00 -1.308608E+01 -3.598672E+01 -3.636042E-01
<surface> 1020 
type right_cylinder 1.000000E+00 -1.308608E+01 -3.598672E+01 -2.650788E-01
<surface> 1021 
type right_cylinder 1.000000E+00 -1.472184E+01 -3.598672E+01 -3.636042E-01
<surface> 1022 
type right_cylinder 1.000000E+00 -1.472184E+01 -3.598672E+01 -2.650788E-01
<surface> 1023 
type right_cylinder 1.000000E+00 -1.635760E+01 -3.598672E+01 -3.636042E-01
<surface> 1024 
type right_cylinder 1.000000E+00 -1.635760E+01 -3.598672E+01 -2.650788E-01
<surface> 1025 
type right_cylinder 1.000000E+00 -1.799336E+01 -3.598672E+01 -3.636042E-01
<surface> 1026 
type right_cylinder 1.000000E+00 -1.799336E+01 -3.598672E+01 -2.650788E-01
<surface> 1027 
type right_cylinder 1.000000E+00 -1.962912E+01 -3.598672E+01 -3.636042E-01
<surface> 1028 
type right_cylinder 1.000000E+00 -1.962912E+01 -3.598672E+01 -2.650788E-01
<surface> 1029 
type right_cylinder 1.000000E+00 -2.126488E+01 -3.598672E+01 -3.636042E-01
<surface> 1030 
type right_cylinder 1.000000E+00 -2.126488E+01 -3.598672E+01 -2.650788E-01
<surface> 1031 
type right_cylinder 1.000000E+00 -2.290064E+01 -3.598672E+01 -3.636042E-01
<surface> 1032 
type right_cylinder 1.000000E+00 -2.290064E+01 -3.598672E+01 -2.650788E-01
<surface> 1033 
type right_cylinder 1.000000E+00 -2.453640E+01 -3.598672E+01 -3.636042E-01
<surface> 1034 
type right_cylinder 1.000000E+00 -2.453640E+01 -3.598672E+01 -2.650788E-01
<surface> 1035 
type right_cylinder 1.000000E+00 -2.617216E+01 -3.598672E+01 -3.636042E-01
<surface> 1036 
type right_cylinder 1.000000E+00 -2.617216E+01 -3.598672E+01 -2.650788E-01
<surface> 1037 
type right_cylinder 1.000000E+00 -2.780792E+01 -3.598672E+01 -3.636042E-01
<surface> 1038 
type right_cylinder 1.000000E+00 -2.780792E+01 -3.598672E+01 -2.650788E-01
<surface> 1039 
type right_cylinder 1.000000E+00 -2.944368E+01 -3.598672E+01 -3.636042E-01
<surface> 1040 
type right_cylinder 1.000000E+00 -2.944368E+01 -3.598672E+01 -2.650788E-01
<surface> 1041 
type right_cylinder 1.000000E+00 -3.107944E+01 -3.598672E+01 -3.636042E-01
<surface> 1042 
type right_cylinder 1.000000E+00 -3.107944E+01 -3.598672E+01 -2.650788E-01
<surface> 1043 
type right_cylinder 1.000000E+00 -3.271520E+01 -3.598672E+01 -3.636042E-01
<surface> 1044 
type right_cylinder 1.000000E+00 -3.271520E+01 -3.598672E+01 -2.650788E-01
<surface> 1045 
type right_cylinder 1.000000E+00 -3.435096E+01 -3.598672E+01 -3.636042E-01
<surface> 1046 
type right_cylinder 1.000000E+00 -3.435096E+01 -3.598672E+01 -2.650788E-01
<surface> 1047 
type right_cylinder 1.000000E+00 -3.598672E+01 -3.598672E+01 -3.636042E-01
<surface> 1048 
type right_cylinder 1.000000E+00 -3.598672E+01 -3.598672E+01 -2.650788E-01
<surface> 1049 
type right_cylinder 1.000000E+00 -3.762248E+01 0.000000E+00 -3.636042E-01
<surface> 1050 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -3.844036E+01
<surface> 1051 
type right_cylinder 1.000000E+00 -3.762248E+01 0.000000E+00 -2.650788E-01
<surface> 1052 
type right_cylinder 1.000000E+00 -3.925824E+01 0.000000E+00 -3.636042E-01
<surface> 1053 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -4.007612E+01
<surface> 1054 
type right_cylinder 1.000000E+00 -3.925824E+01 0.000000E+00 -2.650788E-01
<surface> 1055 
type right_cylinder 1.000000E+00 -4.089400E+01 0.000000E+00 -3.636042E-01
<surface> 1056 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -4.171188E+01
<surface> 1057 
type right_cylinder 1.000000E+00 -4.089400E+01 0.000000E+00 -2.650788E-01
<surface> 1058 
type right_cylinder 1.000000E+00 -4.252976E+01 0.000000E+00 -3.636042E-01
<surface> 1059 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -4.334764E+01
<surface> 1060 
type right_cylinder 1.000000E+00 -4.252976E+01 0.000000E+00 -2.650788E-01
<surface> 1061 
type right_cylinder 1.000000E+00 -4.416552E+01 0.000000E+00 -3.636042E-01
<surface> 1062 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -4.498340E+01
<surface> 1063 
type right_cylinder 1.000000E+00 -4.416552E+01 0.000000E+00 -2.650788E-01
<surface> 1064 
type right_cylinder 1.000000E+00 -4.580128E+01 0.000000E+00 -3.636042E-01
<surface> 1065 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -4.661916E+01
<surface> 1066 
type right_cylinder 1.000000E+00 -4.580128E+01 0.000000E+00 -2.650788E-01
<surface> 1067 
type right_cylinder 1.000000E+00 -4.743704E+01 0.000000E+00 -3.636042E-01
<surface> 1068 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -4.825492E+01
<surface> 1069 
type right_cylinder 1.000000E+00 -4.743704E+01 0.000000E+00 -2.650788E-01
<surface> 1070 
type right_cylinder 1.000000E+00 -4.907280E+01 0.000000E+00 -3.636042E-01
<surface> 1071 
type right_cylinder 1.000000E+00 -4.907280E+01 0.000000E+00 -2.650788E-01
<surface> 1072 
type right_cylinder 1.000000E+00 -5.070856E+01 0.000000E+00 -3.636042E-01
<surface> 1073 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -5.152644E+01
<surface> 1074 
type right_cylinder 1.000000E+00 -5.070856E+01 0.000000E+00 -2.650788E-01
<surface> 1075 
type right_cylinder 1.000000E+00 -5.234432E+01 0.000000E+00 -3.636042E-01
<surface> 1076 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -5.316220E+01
<surface> 1077 
type right_cylinder 1.000000E+00 -5.234432E+01 0.000000E+00 -2.650788E-01
<surface> 1078 
type right_cylinder 1.000000E+00 -5.398008E+01 0.000000E+00 -3.636042E-01
<surface> 1079 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -5.479796E+01
<surface> 1080 
type right_cylinder 1.000000E+00 -5.398008E+01 0.000000E+00 -2.650788E-01
<surface> 1081 
type right_cylinder 1.000000E+00 -5.561584E+01 0.000000E+00 -3.636042E-01
<surface> 1082 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -5.643372E+01
<surface> 1083 
type right_cylinder 1.000000E+00 -5.561584E+01 0.000000E+00 -2.650788E-01
<surface> 1084 
type right_cylinder 1.000000E+00 -5.725160E+01 0.000000E+00 -3.636042E-01
<surface> 1085 
type right_cylinder 1.000000E+00 -5.725160E+01 0.000000E+00 -2.650788E-01
<surface> 1086 
type right_cylinder 1.000000E+00 -5.888736E+01 0.000000E+00 -3.636042E-01
<surface> 1087 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -5.970524E+01
<surface> 1088 
type right_cylinder 1.000000E+00 -5.888736E+01 0.000000E+00 -2.650788E-01
<surface> 1089 
type right_cylinder 1.000000E+00 -6.052312E+01 0.000000E+00 -3.636042E-01
<surface> 1090 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -6.134100E+01
<surface> 1091 
type right_cylinder 1.000000E+00 -6.052312E+01 0.000000E+00 -2.650788E-01
<surface> 1092 
type right_cylinder 1.000000E+00 -6.215888E+01 0.000000E+00 -3.636042E-01
<surface> 1093 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -6.297676E+01
<surface> 1094 
type right_cylinder 1.000000E+00 -6.215888E+01 0.000000E+00 -2.650788E-01
<surface> 1095 
type right_cylinder 1.000000E+00 -6.379464E+01 0.000000E+00 -3.636042E-01
<surface> 1096 
type general_plane 1.000000E+00 0.000000E+00 0.000000E+00 -6.461252E+01
<surface> 1097 
type right_cylinder 1.000000E+00 -6.379464E+01 0.000000E+00 -2.650788E-01
<surface> 1098 
type right_cylinder 1.000000E+00 -6.543040E+01 0.000000E+00 -3.636042E-01
<surface> 1099 
type right_cylinder 1.000000E+00 -6.543040E+01 0.000000E+00 -2.650788E-01
<surface> 1100 
type right_cylinder 1.000000E+00 -3.762248E+01 -1.635760E+00 -3.636042E-01
<surface> 1101 
type right_cylinder 1.000000E+00 -3.762248E+01 -1.635760E+00 -2.650788E-01
<surface> 1102 
type right_cylinder 1.000000E+00 -3.925824E+01 -1.635760E+00 -3.636042E-01
<surface> 1103 
type right_cylinder 1.000000E+00 -3.925824E+01 -1.635760E+00 -2.650788E-01
<surface> 1104 
type right_cylinder 1.000000E+00 -4.089400E+01 -1.635760E+00 -3.636042E-01
<surface> 1105 
type right_cylinder 1.000000E+00 -4.089400E+01 -1.635760E+00 -2.650788E-01
<surface> 1106 
type right_cylinder 1.000000E+00 -4.252976E+01 -1.635760E+00 -3.636042E-01
<surface> 1107 
type right_cylinder 1.000000E+00 -4.252976E+01 -1.635760E+00 -2.650788E-01
<surface> 1108 
type right_cylinder 1.000000E+00 -4.416552E+01 -1.635760E+00 -3.636042E-01
<surface> 1109 
type right_cylinder 1.000000E+00 -4.416552E+01 -1.635760E+00 -2.650788E-01
<surface> 1110 
type right_cylinder 1.000000E+00 -4.580128E+01 -1.635760E+00 -3.636042E-01
<surface> 1111 
type right_cylinder 1.000000E+00 -4.580128E+01 -1.635760E+00 -2.650788E-01
<surface> 1112 
type right_cylinder 1.000000E+00 -4.743704E+01 -1.635760E+00 -3.636042E-01
<surface> 1113 
type right_cylinder 1.000000E+00 -4.743704E+01 -1.635760E+00 -2.650788E-01
<surface> 1114 
type right_cylinder 1.000000E+00 -4.907280E+01 -1.635760E+00 -3.636042E-01
<surface> 1115 
type right_cylinder 1.000000E+00 -4.907280E+01 -1.635760E+00 -2.650788E-01
<surface> 1116 
type right_cylinder 1.000000E+00 -5.070856E+01 -1.635760E+00 -3.636042E-01
<surface> 1117 
type right_cylinder 1.000000E+00 -5.070856E+01 -1.635760E+00 -2.650788E-01
<surface> 1118 
type right_cylinder 1.000000E+00 -5.234432E+01 -1.635760E+00 -3.636042E-01
<surface> 1119 
type right_cylinder 1.000000E+00 -5.234432E+01 -1.635760E+00 -2.650788E-01
<surface> 1120 
type right_cylinder 1.000000E+00 -5.398008E+01 -1.635760E+00 -3.636042E-01
<surface> 1121 
type right_cylinder 1.000000E+00 -5.398008E+01 -1.635760E+00 -2.650788E-01
<surface> 1122 
type right_cylinder 1.000000E+00 -5.561584E+01 -1.635760E+00 -3.636042E-01
<surface> 1123 
type right_cylinder 1.000000E+00 -5.561584E+01 -1.635760E+00 -2.650788E-01
<surface> 1124 
type right_cylinder 1.000000E+00 -5.725160E+01 -1.635760E+00 -3.636042E-01
<surface> 1125 
type right_cylinder 1.000000E+00 -5.725160E+01 -1.635760E+00 -2.650788E-01
<surface> 1126 
type right_cylinder 1.000000E+00 -5.888736E+01 -1.635760E+00 -3.636042E-01
<surface> 1127 
type right_cylinder 1.000000E+00 -5.888736E+01 -1.635760E+00 -2.650788E-01
<surface> 1128 
type right_cylinder 1.000000E+00 -6.052312E+01 -1.635760E+00 -3.636042E-01
<surface> 1129 
type right_cylinder 1.000000E+00 -6.052312E+01 -1.635760E+00 -2.650788E-01
<surface> 1130 
type right_cylinder 1.000000E+00 -6.215888E+01 -1.635760E+00 -3.636042E-01
<surface> 1131 
type right_cylinder 1.000000E+00 -6.215888E+01 -1.635760E+00 -2.650788E-01
<surface> 1132 
type right_cylinder 1.000000E+00 -6.379464E+01 -1.635760E+00 -3.636042E-01
<surface> 1133 
type right_cylinder 1.000000E+00 -6.379464E+01 -1.635760E+00 -2.650788E-01
<surface> 1134 
type right_cylinder 1.000000E+00 -6.543040E+01 -1.635760E+00 -3.636042E-01
<surface> 1135 
type right_cylinder 1.000000E+00 -6.543040E+01 -1.635760E+00 -2.650788E-01
<surface> 1136 
type right_cylinder 1.000000E+00 -3.762248E+01 -3.271520E+00 -3.636042E-01
<surface> 1137 
type right_cylinder 1.000000E+00 -3.762248E+01 -3.271520E+00 -2.650788E-01
<surface> 1138 
type right_cylinder 1.000000E+00 -3.925824E+01 -3.271520E+00 -3.636042E-01
<surface> 1139 
type right_cylinder 1.000000E+00 -3.925824E+01 -3.271520E+00 -2.650788E-01
<surface> 1140 
type right_cylinder 1.000000E+00 -4.089400E+01 -3.271520E+00 -3.636042E-01
<surface> 1141 
type right_cylinder 1.000000E+00 -4.089400E+01 -3.271520E+00 -2.650788E-01
<surface> 1142 
type right_cylinder 1.000000E+00 -4.252976E+01 -3.271520E+00 -3.636042E-01
<surface> 1143 
type right_cylinder 1.000000E+00 -4.252976E+01 -3.271520E+00 -2.650788E-01
<surface> 1144 
type right_cylinder 1.000000E+00 -4.416552E+01 -3.271520E+00 -3.636042E-01
<surface> 1145 
type right_cylinder 1.000000E+00 -4.416552E+01 -3.271520E+00 -2.650788E-01
<surface> 1146 
type right_cylinder 1.000000E+00 -4.580128E+01 -3.271520E+00 -3.636042E-01
<surface> 1147 
type right_cylinder 1.000000E+00 -4.580128E+01 -3.271520E+00 -2.650788E-01
<surface> 1148 
type right_cylinder 1.000000E+00 -4.743704E+01 -3.271520E+00 -3.636042E-01
<surface> 1149 
type right_cylinder 1.000000E+00 -4.743704E+01 -3.271520E+00 -2.650788E-01
<surface> 1150 
type right_cylinder 1.000000E+00 -4.907280E+01 -3.271520E+00 -3.636042E-01
<surface> 1151 
type right_cylinder 1.000000E+00 -4.907280E+01 -3.271520E+00 -2.650788E-01
<surface> 1152 
type right_cylinder 1.000000E+00 -5.070856E+01 -3.271520E+00 -3.636042E-01
<surface> 1153 
type right_cylinder 1.000000E+00 -5.070856E+01 -3.271520E+00 -2.650788E-01
<surface> 1154 
type right_cylinder 1.000000E+00 -5.234432E+01 -3.271520E+00 -3.636042E-01
<surface> 1155 
type right_cylinder 1.000000E+00 -5.234432E+01 -3.271520E+00 -2.650788E-01
<surface> 1156 
type right_cylinder 1.000000E+00 -5.398008E+01 -3.271520E+00 -3.636042E-01
<surface> 1157 
type right_cylinder 1.000000E+00 -5.398008E+01 -3.271520E+00 -2.650788E-01
<surface> 1158 
type right_cylinder 1.000000E+00 -5.561584E+01 -3.271520E+00 -3.636042E-01
<surface> 1159 
type right_cylinder 1.000000E+00 -5.561584E+01 -3.271520E+00 -2.650788E-01
<surface> 1160 
type right_cylinder 1.000000E+00 -5.725160E+01 -3.271520E+00 -3.636042E-01
<surface> 1161 
type right_cylinder 1.000000E+00 -5.725160E+01 -3.271520E+00 -2.650788E-01
<surface> 1162 
type right_cylinder 1.000000E+00 -5.888736E+01 -3.271520E+00 -3.636042E-01
<surface> 1163 
type right_cylinder 1.000000E+00 -5.888736E+01 -3.271520E+00 -2.650788E-01
<surface> 1164 
type right_cylinder 1.000000E+00 -6.052312E+01 -3.271520E+00 -3.636042E-01
<surface> 1165 
type right_cylinder 1.000000E+00 -6.052312E+01 -3.271520E+00 -2.650788E-01
<surface> 1166 
type right_cylinder 1.000000E+00 -6.215888E+01 -3.271520E+00 -3.636042E-01
<surface> 1167 
type right_cylinder 1.000000E+00 -6.215888E+01 -3.271520E+00 -2.650788E-01
<surface> 1168 
type right_cylinder 1.000000E+00 -6.379464E+01 -3.271520E+00 -3.636042E-01
<surface> 1169 
type right_cylinder 1.000000E+00 -6.379464E+01 -3.271520E+00 -2.650788E-01
<surface> 1170 
type right_cylinder 1.000000E+00 -6.543040E+01 -3.271520E+00 -3.636042E-01
<surface> 1171 
type right_cylinder 1.000000E+00 -6.543040E+01 -3.271520E+00 -2.650788E-01
<surface> 1172 
type right_cylinder 1.000000E+00 -3.762248E+01 -4.907280E+00 -3.636042E-01
<surface> 1173 
type right_cylinder 1.000000E+00 -3.762248E+01 -4.907280E+00 -2.650788E-01
<surface> 1174 
type right_cylinder 1.000000E+00 -3.925824E+01 -4.907280E+00 -3.636042E-01
<surface> 1175 
type right_cylinder 1.000000E+00 -3.925824E+01 -4.907280E+00 -2.650788E-01
<surface> 1176 
type right_cylinder 1.000000E+00 -4.089400E+01 -4.907280E+00 -3.636042E-01
<surface> 1177 
type right_cylinder 1.000000E+00 -4.089400E+01 -4.907280E+00 -2.650788E-01
<surface> 1178 
type right_cylinder 1.000000E+00 -4.252976E+01 -4.907280E+00 -3.636042E-01
<surface> 1179 
type right_cylinder 1.000000E+00 -4.252976E+01 -4.907280E+00 -2.650788E-01
<surface> 1180 
type right_cylinder 1.000000E+00 -4.416552E+01 -4.907280E+00 -3.636042E-01
<surface> 1181 
type right_cylinder 1.000000E+00 -4.416552E+01 -4.907280E+00 -2.650788E-01
<surface> 1182 
type right_cylinder 1.000000E+00 -4.580128E+01 -4.907280E+00 -3.636042E-01
<surface> 1183 
type right_cylinder 1.000000E+00 -4.580128E+01 -4.907280E+00 -2.650788E-01
<surface> 1184 
type right_cylinder 1.000000E+00 -4.743704E+01 -4.907280E+00 -3.636042E-01
<surface> 1185 
type right_cylinder 1.000000E+00 -4.743704E+01 -4.907280E+00 -2.650788E-01
<surface> 1186 
type right_cylinder 1.000000E+00 -4.907280E+01 -4.907280E+00 -3.636042E-01
<surface> 1187 
type right_cylinder 1.000000E+00 -4.907280E+01 -4.907280E+00 -2.650788E-01
<surface> 1188 
type right_cylinder 1.000000E+00 -5.070856E+01 -4.907280E+00 -3.636042E-01
<surface> 1189 
type right_cylinder 1.000000E+00 -5.070856E+01 -4.907280E+00 -2.650788E-01
<surface> 1190 
type right_cylinder 1.000000E+00 -5.234432E+01 -4.907280E+00 -3.636042E-01
<surface> 1191 
type right_cylinder 1.000000E+00 -5.234432E+01 -4.907280E+00 -2.650788E-01
<surface> 1192 
type right_cylinder 1.000000E+00 -5.398008E+01 -4.907280E+00 -3.636042E-01
<surface> 1193 
type right_cylinder 1.000000E+00 -5.398008E+01 -4.907280E+00 -2.650788E-01
<surface> 1194 
type right_cylinder 1.000000E+00 -5.561584E+01 -4.907280E+00 -3.636042E-01
<surface> 1195 
type right_cylinder 1.000000E+00 -5.561584E+01 -4.907280E+00 -2.650788E-01
<surface> 1196 
type right_cylinder 1.000000E+00 -5.725160E+01 -4.907280E+00 -3.636042E-01
<surface> 1197 
type right_cylinder 1.000000E+00 -5.725160E+01 -4.907280E+00 -2.650788E-01
<surface> 1198 
type right_cylinder 1.000000E+00 -5.888736E+01 -4.907280E+00 -3.636042E-01
<surface> 1199 
type right_cylinder 1.000000E+00 -5.888736E+01 -4.907280E+00 -2.650788E-01
<surface> 1200 
type right_cylinder 1.000000E+00 -6.052312E+01 -4.907280E+00 -3.636042E-01
<surface> 1201 
type right_cylinder 1.000000E+00 -6.052312E+01 -4.907280E+00 -2.650788E-01
<surface> 1202 
type right_cylinder 1.000000E+00 -6.215888E+01 -4.907280E+00 -3.636042E-01
<surface> 1203 
type right_cylinder 1.000000E+00 -6.215888E+01 -4.907280E+00 -2.650788E-01
<surface> 1204 
type right_cylinder 1.000000E+00 -6.379464E+01 -4.907280E+00 -3.636042E-01
<surface> 1205 
type right_cylinder 1.000000E+00 -6.379464E+01 -4.907280E+00 -2.650788E-01
<surface> 1206 
type right_cylinder 1.000000E+00 -6.543040E+01 -4.907280E+00 -3.636042E-01
<surface> 1207 
type right_cylinder 1.000000E+00 -6.543040E+01 -4.907280E+00 -2.650788E-01
<surface> 1208 
type right_cylinder 1.000000E+00 -3.762248E+01 -6.543040E+00 -3.636042E-01
<surface> 1209 
type right_cylinder 1.000000E+00 -3.762248E+01 -6.543040E+00 -2.650788E-01
<surface> 1210 
type right_cylinder 1.000000E+00 -3.925824E+01 -6.543040E+00 -3.636042E-01
<surface> 1211 
type right_cylinder 1.000000E+00 -3.925824E+01 -6.543040E+00 -2.650788E-01
<surface> 1212 
type right_cylinder 1.000000E+00 -4.089400E+01 -6.543040E+00 -3.636042E-01
<surface> 1213 
type right_cylinder 1.000000E+00 -4.089400E+01 -6.543040E+00 -2.650788E-01
<surface> 1214 
type right_cylinder 1.000000E+00 -4.252976E+01 -6.543040E+00 -3.636042E-01
<surface> 1215 
type right_cylinder 1.000000E+00 -4.252976E+01 -6.543040E+00 -2.650788E-01
<surface> 1216 
type right_cylinder 1.000000E+00 -4.416552E+01 -6.543040E+00 -3.636042E-01
<surface> 1217 
type right_cylinder 1.000000E+00 -4.416552E+01 -6.543040E+00 -2.650788E-01
<surface> 1218 
type right_cylinder 1.000000E+00 -4.580128E+01 -6.543040E+00 -3.636042E-01
<surface> 1219 
type right_cylinder 1.000000E+00 -4.580128E+01 -6.543040E+00 -2.650788E-01
<surface> 1220 
type right_cylinder 1.000000E+00 -4.743704E+01 -6.543040E+00 -3.636042E-01
<surface> 1221 
type right_cylinder 1.000000E+00 -4.743704E+01 -6.543040E+00 -2.650788E-01
<surface> 1222 
type right_cylinder 1.000000E+00 -4.907280E+01 -6.543040E+00 -3.636042E-01
<surface> 1223 
type right_cylinder 1.000000E+00 -4.907280E+01 -6.543040E+00 -2.650788E-01
<surface> 1224 
type right_cylinder 1.000000E+00 -5.070856E+01 -6.543040E+00 -3.636042E-01
<surface> 1225 
type right_cylinder 1.000000E+00 -5.070856E+01 -6.543040E+00 -2.650788E-01
<surface> 1226 
type right_cylinder 1.000000E+00 -5.234432E+01 -6.543040E+00 -3.636042E-01
<surface> 1227 
type right_cylinder 1.000000E+00 -5.234432E+01 -6.543040E+00 -2.650788E-01
<surface> 1228 
type right_cylinder 1.000000E+00 -5.398008E+01 -6.543040E+00 -3.636042E-01
<surface> 1229 
type right_cylinder 1.000000E+00 -5.398008E+01 -6.543040E+00 -2.650788E-01
<surface> 1230 
type right_cylinder 1.000000E+00 -5.561584E+01 -6.543040E+00 -3.636042E-01
<surface> 1231 
type right_cylinder 1.000000E+00 -5.561584E+01 -6.543040E+00 -2.650788E-01
<surface> 1232 
type right_cylinder 1.000000E+00 -5.725160E+01 -6.543040E+00 -3.636042E-01
<surface> 1233 
type right_cylinder 1.000000E+00 -5.725160E+01 -6.543040E+00 -2.650788E-01
<surface> 1234 
type right_cylinder 1.000000E+00 -5.888736E+01 -6.543040E+00 -3.636042E-01
<surface> 1235 
type right_cylinder 1.000000E+00 -5.888736E+01 -6.543040E+00 -2.650788E-01
<surface> 1236 
type right_cylinder 1.000000E+00 -6.052312E+01 -6.543040E+00 -3.636042E-01
<surface> 1237 
type right_cylinder 1.000000E+00 -6.052312E+01 -6.543040E+00 -2.650788E-01
<surface> 1238 
type right_cylinder 1.000000E+00 -6.215888E+01 -6.543040E+00 -3.636042E-01
<surface> 1239 
type right_cylinder 1.000000E+00 -6.215888E+01 -6.543040E+00 -2.650788E-01
<surface> 1240 
type right_cylinder 1.000000E+00 -6.379464E+01 -6.543040E+00 -3.636042E-01
<surface> 1241 
type right_cylinder 1.000000E+00 -6.379464E+01 -6.543040E+00 -2.650788E-01
<surface> 1242 
type right_cylinder 1.000000E+00 -6.543040E+01 -6.543040E+00 -3.636042E-01
<surface> 1243 
type right_cylinder 1.000000E+00 -6.543040E+01 -6.543040E+00 -2.650788E-01
<surface> 1244 
type right_cylinder 1.000000E+00 -3.762248E+01 -8.178800E+00 -3.636042E-01
<surface> 1245 
type right_cylinder 1.000000E+00 -3.762248E+01 -8.178800E+00 -2.650788E-01
<surface> 1246 
type right_cylinder 1.000000E+00 -3.925824E+01 -8.178800E+00 -3.636042E-01
<surface> 1247 
type right_cylinder 1.000000E+00 -3.925824E+01 -8.178800E+00 -2.650788E-01
<surface> 1248 
type right_cylinder 1.000000E+00 -4.089400E+01 -8.178800E+00 -3.636042E-01
<surface> 1249 
type right_cylinder 1.000000E+00 -4.089400E+01 -8.178800E+00 -2.650788E-01
<surface> 1250 
type right_cylinder 1.000000E+00 -4.252976E+01 -8.178800E+00 -3.636042E-01
<surface> 1251 
type right_cylinder 1.000000E+00 -4.252976E+01 -8.178800E+00 -2.650788E-01
<surface> 1252 
type right_cylinder 1.000000E+00 -4.416552E+01 -8.178800E+00 -3.636042E-01
<surface> 1253 
type right_cylinder 1.000000E+00 -4.416552E+01 -8.178800E+00 -2.650788E-01
<surface> 1254 
type right_cylinder 1.000000E+00 -4.580128E+01 -8.178800E+00 -3.636042E-01
<surface> 1255 
type right_cylinder 1.000000E+00 -4.580128E+01 -8.178800E+00 -2.650788E-01
<surface> 1256 
type right_cylinder 1.000000E+00 -4.743704E+01 -8.178800E+00 -3.636042E-01
<surface> 1257 
type right_cylinder 1.000000E+00 -4.743704E+01 -8.178800E+00 -2.650788E-01
<surface> 1258 
type right_cylinder 1.000000E+00 -4.907280E+01 -8.178800E+00 -3.636042E-01
<surface> 1259 
type right_cylinder 1.000000E+00 -4.907280E+01 -8.178800E+00 -2.650788E-01
<surface> 1260 
type right_cylinder 1.000000E+00 -5.070856E+01 -8.178800E+00 -3.636042E-01
<surface> 1261 
type right_cylinder 1.000000E+00 -5.070856E+01 -8.178800E+00 -2.650788E-01
<surface> 1262 
type right_cylinder 1.000000E+00 -5.234432E+01 -8.178800E+00 -3.636042E-01
<surface> 1263 
type right_cylinder 1.000000E+00 -5.234432E+01 -8.178800E+00 -2.650788E-01
<surface> 1264 
type right_cylinder 1.000000E+00 -5.398008E+01 -8.178800E+00 -3.636042E-01
<surface> 1265 
type right_cylinder 1.000000E+00 -5.398008E+01 -8.178800E+00 -2.650788E-01
<surface> 1266 
type right_cylinder 1.000000E+00 -5.561584E+01 -8.178800E+00 -3.636042E-01
<surface> 1267 
type right_cylinder 1.000000E+00 -5.561584E+01 -8.178800E+00 -2.650788E-01
<surface> 1268 
type right_cylinder 1.000000E+00 -5.725160E+01 -8.178800E+00 -3.636042E-01
<surface> 1269 
type right_cylinder 1.000000E+00 -5.725160E+01 -8.178800E+00 -2.650788E-01
<surface> 1270 
type right_cylinder 1.000000E+00 -5.888736E+01 -8.178800E+00 -3.636042E-01
<surface> 1271 
type right_cylinder 1.000000E+00 -5.888736E+01 -8.178800E+00 -2.650788E-01
<surface> 1272 
type right_cylinder 1.000000E+00 -6.052312E+01 -8.178800E+00 -3.636042E-01
<surface> 1273 
type right_cylinder 1.000000E+00 -6.052312E+01 -8.178800E+00 -2.650788E-01
<surface> 1274 
type right_cylinder 1.000000E+00 -6.215888E+01 -8.178800E+00 -3.636042E-01
<surface> 1275 
type right_cylinder 1.000000E+00 -6.215888E+01 -8.178800E+00 -2.650788E-01
<surface> 1276 
type right_cylinder 1.000000E+00 -6.379464E+01 -8.178800E+00 -3.636042E-01
<surface> 1277 
type right_cylinder 1.000000E+00 -6.379464E+01 -8.178800E+00 -2.650788E-01
<surface> 1278 
type right_cylinder 1.000000E+00 -6.543040E+01 -8.178800E+00 -3.636042E-01
<surface> 1279 
type right_cylinder 1.000000E+00 -6.543040E+01 -8.178800E+00 -2.650788E-01
<surface> 1280 
type right_cylinder 1.000000E+00 -3.762248E+01 -9.814560E+00 -3.636042E-01
<surface> 1281 
type right_cylinder 1.000000E+00 -3.762248E+01 -9.814560E+00 -2.650788E-01
<surface> 1282 
type right_cylinder 1.000000E+00 -3.925824E+01 -9.814560E+00 -3.636042E-01
<surface> 1283 
type right_cylinder 1.000000E+00 -3.925824E+01 -9.814560E+00 -2.650788E-01
<surface> 1284 
type right_cylinder 1.000000E+00 -4.089400E+01 -9.814560E+00 -3.636042E-01
<surface> 1285 
type right_cylinder 1.000000E+00 -4.089400E+01 -9.814560E+00 -2.650788E-01
<surface> 1286 
type right_cylinder 1.000000E+00 -4.252976E+01 -9.814560E+00 -3.636042E-01
<surface> 1287 
type right_cylinder 1.000000E+00 -4.252976E+01 -9.814560E+00 -2.650788E-01
<surface> 1288 
type right_cylinder 1.000000E+00 -4.416552E+01 -9.814560E+00 -3.636042E-01
<surface> 1289 
type right_cylinder 1.000000E+00 -4.416552E+01 -9.814560E+00 -2.650788E-01
<surface> 1290 
type right_cylinder 1.000000E+00 -4.580128E+01 -9.814560E+00 -3.636042E-01
<surface> 1291 
type right_cylinder 1.000000E+00 -4.580128E+01 -9.814560E+00 -2.650788E-01
<surface> 1292 
type right_cylinder 1.000000E+00 -4.743704E+01 -9.814560E+00 -3.636042E-01
<surface> 1293 
type right_cylinder 1.000000E+00 -4.743704E+01 -9.814560E+00 -2.650788E-01
<surface> 1294 
type right_cylinder 1.000000E+00 -4.907280E+01 -9.814560E+00 -3.636042E-01
<surface> 1295 
type right_cylinder 1.000000E+00 -4.907280E+01 -9.814560E+00 -2.650788E-01
<surface> 1296 
type right_cylinder 1.000000E+00 -5.070856E+01 -9.814560E+00 -3.636042E-01
<surface> 1297 
type right_cylinder 1.000000E+00 -5.070856E+01 -9.814560E+00 -2.650788E-01
<surface> 1298 
type right_cylinder 1.000000E+00 -5.234432E+01 -9.814560E+00 -3.636042E-01
<surface> 1299 
type right_cylinder 1.000000E+00 -5.234432E+01 -9.814560E+00 -2.650788E-01
<surface> 1300 
type right_cylinder 1.000000E+00 -5.398008E+01 -9.814560E+00 -3.636042E-01
<surface> 1301 
type right_cylinder 1.000000E+00 -5.398008E+01 -9.814560E+00 -2.650788E-01
<surface> 1302 
type right_cylinder 1.000000E+00 -5.561584E+01 -9.814560E+00 -3.636042E-01
<surface> 1303 
type right_cylinder 1.000000E+00 -5.561584E+01 -9.814560E+00 -2.650788E-01
<surface> 1304 
type right_cylinder 1.000000E+00 -5.725160E+01 -9.814560E+00 -3.636042E-01
<surface> 1305 
type right_cylinder 1.000000E+00 -5.725160E+01 -9.814560E+00 -2.650788E-01
<surface> 1306 
type right_cylinder 1.000000E+00 -5.888736E+01 -9.814560E+00 -3.636042E-01
<surface> 1307 
type right_cylinder 1.000000E+00 -5.888736E+01 -9.814560E+00 -2.650788E-01
<surface> 1308 
type right_cylinder 1.000000E+00 -6.052312E+01 -9.814560E+00 -3.636042E-01
<surface> 1309 
type right_cylinder 1.000000E+00 -6.052312E+01 -9.814560E+00 -2.650788E-01
<surface> 1310 
type right_cylinder 1.000000E+00 -6.215888E+01 -9.814560E+00 -3.636042E-01
<surface> 1311 
type right_cylinder 1.000000E+00 -6.215888E+01 -9.814560E+00 -2.650788E-01
<surface> 1312 
type right_cylinder 1.000000E+00 -6.379464E+01 -9.814560E+00 -3.636042E-01
<surface> 1313 
type right_cylinder 1.000000E+00 -6.379464E+01 -9.814560E+00 -2.650788E-01
<surface> 1314 
type right_cylinder 1.000000E+00 -6.543040E+01 -9.814560E+00 -3.636042E-01
<surface> 1315 
type right_cylinder 1.000000E+00 -6.543040E+01 -9.814560E+00 -2.650788E-01
<surface> 1316 
type right_cylinder 1.000000E+00 -3.762248E+01 -1.145032E+01 -3.636042E-01
<surface> 1317 
type right_cylinder 1.000000E+00 -3.762248E+01 -1.145032E+01 -2.650788E-01
<surface> 1318 
type right_cylinder 1.000000E+00 -3.925824E+01 -1.145032E+01 -3.636042E-01
<surface> 1319 
type right_cylinder 1.000000E+00 -3.925824E+01 -1.145032E+01 -2.650788E-01
<surface> 1320 
type right_cylinder 1.000000E+00 -4.089400E+01 -1.145032E+01 -3.636042E-01
<surface> 1321 
type right_cylinder 1.000000E+00 -4.089400E+01 -1.145032E+01 -2.650788E-01
<surface> 1322 
type right_cylinder 1.000000E+00 -4.252976E+01 -1.145032E+01 -3.636042E-01
<surface> 1323 
type right_cylinder 1.000000E+00 -4.252976E+01 -1.145032E+01 -2.650788E-01
<surface> 1324 
type right_cylinder 1.000000E+00 -4.416552E+01 -1.145032E+01 -3.636042E-01
<surface> 1325 
type right_cylinder 1.000000E+00 -4.416552E+01 -1.145032E+01 -2.650788E-01
<surface> 1326 
type right_cylinder 1.000000E+00 -4.580128E+01 -1.145032E+01 -3.636042E-01
<surface> 1327 
type right_cylinder 1.000000E+00 -4.580128E+01 -1.145032E+01 -2.650788E-01
<surface> 1328 
type right_cylinder 1.000000E+00 -4.743704E+01 -1.145032E+01 -3.636042E-01
<surface> 1329 
type right_cylinder 1.000000E+00 -4.743704E+01 -1.145032E+01 -2.650788E-01
<surface> 1330 
type right_cylinder 1.000000E+00 -4.907280E+01 -1.145032E+01 -3.636042E-01
<surface> 1331 
type right_cylinder 1.000000E+00 -4.907280E+01 -1.145032E+01 -2.650788E-01
<surface> 1332 
type right_cylinder 1.000000E+00 -5.070856E+01 -1.145032E+01 -3.636042E-01
<surface> 1333 
type right_cylinder 1.000000E+00 -5.070856E+01 -1.145032E+01 -2.650788E-01
<surface> 1334 
type right_cylinder 1.000000E+00 -5.234432E+01 -1.145032E+01 -3.636042E-01
<surface> 1335 
type right_cylinder 1.000000E+00 -5.234432E+01 -1.145032E+01 -2.650788E-01
<surface> 1336 
type right_cylinder 1.000000E+00 -5.398008E+01 -1.145032E+01 -3.636042E-01
<surface> 1337 
type right_cylinder 1.000000E+00 -5.398008E+01 -1.145032E+01 -2.650788E-01
<surface> 1338 
type right_cylinder 1.000000E+00 -5.561584E+01 -1.145032E+01 -3.636042E-01
<surface> 1339 
type right_cylinder 1.000000E+00 -5.561584E+01 -1.145032E+01 -2.650788E-01
<surface> 1340 
type right_cylinder 1.000000E+00 -5.725160E+01 -1.145032E+01 -3.636042E-01
<surface> 1341 
type right_cylinder 1.000000E+00 -5.725160E+01 -1.145032E+01 -2.650788E-01
<surface> 1342 
type right_cylinder 1.000000E+00 -5.888736E+01 -1.145032E+01 -3.636042E-01
<surface> 1343 
type right_cylinder 1.000000E+00 -5.888736E+01 -1.145032E+01 -2.650788E-01
<surface> 1344 
type right_cylinder 1.000000E+00 -6.052312E+01 -1.145032E+01 -3.636042E-01
<surface> 1345 
type right_cylinder 1.000000E+00 -6.052312E+01 -1.145032E+01 -2.650788E-01
<surface> 1346 
type right_cylinder 1.000000E+00 -6.215888E+01 -1.145032E+01 -3.636042E-01
<surface> 1347 
type right_cylinder 1.000000E+00 -6.215888E+01 -1.145032E+01 -2.650788E-01
<surface> 1348 
type right_cylinder 1.000000E+00 -6.379464E+01 -1.145032E+01 -3.636042E-01
<surface> 1349 
type right_cylinder 1.000000E+00 -6.379464E+01 -1.145032E+01 -2.650788E-01
<surface> 1350 
type right_cylinder 1.000000E+00 -6.543040E+01 -1.145032E+01 -3.636042E-01
<surface> 1351 
type right_cylinder 1.000000E+00 -6.543040E+01 -1.145032E+01 -2.650788E-01
<surface> 1352 
type right_cylinder 1.000000E+00 -3.762248E+01 -1.308608E+01 -3.636042E-01
<surface> 1353 
type right_cylinder 1.000000E+00 -3.762248E+01 -1.308608E+01 -2.650788E-01
<surface> 1354 
type right_cylinder 1.000000E+00 -3.925824E+01 -1.308608E+01 -3.636042E-01
<surface> 1355 
type right_cylinder 1.000000E+00 -3.925824E+01 -1.308608E+01 -2.650788E-01
<surface> 1356 
type right_cylinder 1.000000E+00 -4.089400E+01 -1.308608E+01 -3.636042E-01
<surface> 1357 
type right_cylinder 1.000000E+00 -4.089400E+01 -1.308608E+01 -2.650788E-01
<surface> 1358 
type right_cylinder 1.000000E+00 -4.252976E+01 -1.308608E+01 -3.636042E-01
<surface> 1359 
type right_cylinder 1.000000E+00 -4.252976E+01 -1.308608E+01 -2.650788E-01
<surface> 1360 
type right_cylinder 1.000000E+00 -4.416552E+01 -1.308608E+01 -3.636042E-01
<surface> 1361 
type right_cylinder 1.000000E+00 -4.416552E+01 -1.308608E+01 -2.650788E-01
<surface> 1362 
type right_cylinder 1.000000E+00 -4.580128E+01 -1.308608E+01 -3.636042E-01
<surface> 1363 
type right_cylinder 1.000000E+00 -4.580128E+01 -1.308608E+01 -2.650788E-01
<surface> 1364 
type right_cylinder 1.000000E+00 -4.743704E+01 -1.308608E+01 -3.636042E-01
<surface> 1365 
type right_cylinder 1.000000E+00 -4.743704E+01 -1.308608E+01 -2.650788E-01
<surface> 1366 
type right_cylinder 1.000000E+00 -4.907280E+01 -1.308608E+01 -3.636042E-01
<surface> 1367 
type right_cylinder 1.000000E+00 -4.907280E+01 -1.308608E+01 -2.650788E-01
<surface> 1368 
type right_cylinder 1.000000E+00 -5.070856E+01 -1.308608E+01 -3.636042E-01
<surface> 1369 
type right_cylinder 1.000000E+00 -5.070856E+01 -1.308608E+01 -2.650788E-01
<surface> 1370 
type right_cylinder 1.000000E+00 -5.234432E+01 -1.308608E+01 -3.636042E-01
<surface> 1371 
type right_cylinder 1.000000E+00 -5.234432E+01 -1.308608E+01 -2.650788E-01
<surface> 1372 
type right_cylinder 1.000000E+00 -5.398008E+01 -1.308608E+01 -3.636042E-01
<surface> 1373 
type right_cylinder 1.000000E+00 -5.398008E+01 -1.308608E+01 -2.650788E-01
<surface> 1374 
type right_cylinder 1.000000E+00 -5.561584E+01 -1.308608E+01 -3.636042E-01
<surface> 1375 
type right_cylinder 1.000000E+00 -5.561584E+01 -1.308608E+01 -2.650788E-01
<surface> 1376 
type right_cylinder 1.000000E+00 -5.725160E+01 -1.308608E+01 -3.636042E-01
<surface> 1377 
type right_cylinder 1.000000E+00 -5.725160E+01 -1.308608E+01 -2.650788E-01
<surface> 1378 
type right_cylinder 1.000000E+00 -5.888736E+01 -1.308608E+01 -3.636042E-01
<surface> 1379 
type right_cylinder 1.000000E+00 -5.888736E+01 -1.308608E+01 -2.650788E-01
<surface> 1380 
type right_cylinder 1.000000E+00 -6.052312E+01 -1.308608E+01 -3.636042E-01
<surface> 1381 
type right_cylinder 1.000000E+00 -6.052312E+01 -1.308608E+01 -2.650788E-01
<surface> 1382 
type right_cylinder 1.000000E+00 -6.215888E+01 -1.308608E+01 -3.636042E-01
<surface> 1383 
type right_cylinder 1.000000E+00 -6.215888E+01 -1.308608E+01 -2.650788E-01
<surface> 1384 
type right_cylinder 1.000000E+00 -6.379464E+01 -1.308608E+01 -3.636042E-01
<surface> 1385 
type right_cylinder 1.000000E+00 -6.379464E+01 -1.308608E+01 -2.650788E-01
<surface> 1386 
type right_cylinder 1.000000E+00 -6.543040E+01 -1.308608E+01 -3.636042E-01
<surface> 1387 
type right_cylinder 1.000000E+00 -6.543040E+01 -1.308608E+01 -2.650788E-01
<surface> 1388 
type right_cylinder 1.000000E+00 -3.762248E+01 -1.472184E+01 -3.636042E-01
<surface> 1389 
type right_cylinder 1.000000E+00 -3.762248E+01 -1.472184E+01 -2.650788E-01
<surface> 1390 
type right_cylinder 1.000000E+00 -3.925824E+01 -1.472184E+01 -3.636042E-01
<surface> 1391 
type right_cylinder 1.000000E+00 -3.925824E+01 -1.472184E+01 -2.650788E-01
<surface> 1392 
type right_cylinder 1.000000E+00 -4.089400E+01 -1.472184E+01 -3.636042E-01
<surface> 1393 
type right_cylinder 1.000000E+00 -4.089400E+01 -1.472184E+01 -2.650788E-01
<surface> 1394 
type right_cylinder 1.000000E+00 -4.252976E+01 -1.472184E+01 -3.636042E-01
<surface> 1395 
type right_cylinder 1.000000E+00 -4.252976E+01 -1.472184E+01 -2.650788E-01
<surface> 1396 
type right_cylinder 1.000000E+00 -4.416552E+01 -1.472184E+01 -3.636042E-01
<surface> 1397 
type right_cylinder 1.000000E+00 -4.416552E+01 -1.472184E+01 -2.650788E-01
<surface> 1398 
type right_cylinder 1.000000E+00 -4.580128E+01 -1.472184E+01 -3.636042E-01
<surface> 1399 
type right_cylinder 1.000000E+00 -4.580128E+01 -1.472184E+01 -2.650788E-01
<surface> 1400 
type right_cylinder 1.000000E+00 -4.743704E+01 -1.472184E+01 -3.636042E-01
<surface> 1401 
type right_cylinder 1.000000E+00 -4.743704E+01 -1.472184E+01 -2.650788E-01
<surface> 1402 
type right_cylinder 1.000000E+00 -4.907280E+01 -1.472184E+01 -3.636042E-01
<surface> 1403 
type right_cylinder 1.000000E+00 -4.907280E+01 -1.472184E+01 -2.650788E-01
<surface> 1404 
type right_cylinder 1.000000E+00 -5.070856E+01 -1.472184E+01 -3.636042E-01
<surface> 1405 
type right_cylinder 1.000000E+00 -5.070856E+01 -1.472184E+01 -2.650788E-01
<surface> 1406 
type right_cylinder 1.000000E+00 -5.234432E+01 -1.472184E+01 -3.636042E-01
<surface> 1407 
type right_cylinder 1.000000E+00 -5.234432E+01 -1.472184E+01 -2.650788E-01
<surface> 1408 
type right_cylinder 1.000000E+00 -5.398008E+01 -1.472184E+01 -3.636042E-01
<surface> 1409 
type right_cylinder 1.000000E+00 -5.398008E+01 -1.472184E+01 -2.650788E-01
<surface> 1410 
type right_cylinder 1.000000E+00 -5.561584E+01 -1.472184E+01 -3.636042E-01
<surface> 1411 
type right_cylinder 1.000000E+00 -5.561584E+01 -1.472184E+01 -2.650788E-01
<surface> 1412 
type right_cylinder 1.000000E+00 -5.725160E+01 -1.472184E+01 -3.636042E-01
<surface> 1413 
type right_cylinder 1.000000E+00 -5.725160E+01 -1.472184E+01 -2.650788E-01
<surface> 1414 
type right_cylinder 1.000000E+00 -5.888736E+01 -1.472184E+01 -3.636042E-01
<surface> 1415 
type right_cylinder 1.000000E+00 -5.888736E+01 -1.472184E+01 -2.650788E-01
<surface> 1416 
type right_cylinder 1.000000E+00 -6.052312E+01 -1.472184E+01 -3.636042E-01
<surface> 1417 
type right_cylinder 1.000000E+00 -6.052312E+01 -1.472184E+01 -2.650788E-01
<surface> 1418 
type right_cylinder 1.000000E+00 -6.215888E+01 -1.472184E+01 -3.636042E-01
<surface> 1419 
type right_cylinder 1.000000E+00 -6.215888E+01 -1.472184E+01 -2.650788E-01
<surface> 1420 
type right_cylinder 1.000000E+00 -6.379464E+01 -1.472184E+01 -3.636042E-01
<surface> 1421 
type right_cylinder 1.000000E+00 -6.379464E+01 -1.472184E+01 -2.650788E-01
<surface> 1422 
type right_cylinder 1.000000E+00 -6.543040E+01 -1.472184E+01 -3.636042E-01
<surface> 1423 
type right_cylinder 1.000000E+00 -6.543040E+01 -1.472184E+01 -2.650788E-01
<surface> 1424 
type right_cylinder 1.000000E+00 -3.762248E+01 -1.635760E+01 -3.636042E-01
<surface> 1425 
type right_cylinder 1.000000E+00 -3.762248E+01 -1.635760E+01 -2.650788E-01
<surface> 1426 
type right_cylinder 1.000000E+00 -3.925824E+01 -1.635760E+01 -3.636042E-01
<surface> 1427 
type right_cylinder 1.000000E+00 -3.925824E+01 -1.635760E+01 -2.650788E-01
<surface> 1428 
type right_cylinder 1.000000E+00 -4.089400E+01 -1.635760E+01 -3.636042E-01
<surface> 1429 
type right_cylinder 1.000000E+00 -4.089400E+01 -1.635760E+01 -2.650788E-01
<surface> 1430 
type right_cylinder 1.000000E+00 -4.252976E+01 -1.635760E+01 -3.636042E-01
<surface> 1431 
type right_cylinder 1.000000E+00 -4.252976E+01 -1.635760E+01 -2.650788E-01
<surface> 1432 
type right_cylinder 1.000000E+00 -4.416552E+01 -1.635760E+01 -3.636042E-01
<surface> 1433 
type right_cylinder 1.000000E+00 -4.416552E+01 -1.635760E+01 -2.650788E-01
<surface> 1434 
type right_cylinder 1.000000E+00 -4.580128E+01 -1.635760E+01 -3.636042E-01
<surface> 1435 
type right_cylinder 1.000000E+00 -4.580128E+01 -1.635760E+01 -2.650788E-01
<surface> 1436 
type right_cylinder 1.000000E+00 -4.743704E+01 -1.635760E+01 -3.636042E-01
<surface> 1437 
type right_cylinder 1.000000E+00 -4.743704E+01 -1.635760E+01 -2.650788E-01
<surface> 1438 
type right_cylinder 1.000000E+00 -4.907280E+01 -1.635760E+01 -3.636042E-01
<surface> 1439 
type right_cylinder 1.000000E+00 -4.907280E+01 -1.635760E+01 -2.650788E-01
<surface> 1440 
type right_cylinder 1.000000E+00 -5.070856E+01 -1.635760E+01 -3.636042E-01
<surface> 1441 
type right_cylinder 1.000000E+00 -5.070856E+01 -1.635760E+01 -2.650788E-01
<surface> 1442 
type right_cylinder 1.000000E+00 -5.234432E+01 -1.635760E+01 -3.636042E-01
<surface> 1443 
type right_cylinder 1.000000E+00 -5.234432E+01 -1.635760E+01 -2.650788E-01
<surface> 1444 
type right_cylinder 1.000000E+00 -5.398008E+01 -1.635760E+01 -3.636042E-01
<surface> 1445 
type right_cylinder 1.000000E+00 -5.398008E+01 -1.635760E+01 -2.650788E-01
<surface> 1446 
type right_cylinder 1.000000E+00 -5.561584E+01 -1.635760E+01 -3.636042E-01
<surface> 1447 
type right_cylinder 1.000000E+00 -5.561584E+01 -1.635760E+01 -2.650788E-01
<surface> 1448 
type right_cylinder 1.000000E+00 -5.725160E+01 -1.635760E+01 -3.636042E-01
<surface> 1449 
type right_cylinder 1.000000E+00 -5.725160E+01 -1.635760E+01 -2.650788E-01
<surface> 1450 
type right_cylinder 1.000000E+00 -5.888736E+01 -1.635760E+01 -3.636042E-01
<surface> 1451 
type right_cylinder 1.000000E+00 -5.888736E+01 -1.635760E+01 -2.650788E-01
<surface> 1452 
type right_cylinder 1.000000E+00 -6.052312E+01 -1.635760E+01 -3.636042E-01
<surface> 1453 
type right_cylinder 1.000000E+00 -6.052312E+01 -1.635760E+01 -2.650788E-01
<surface> 1454 
type right_cylinder 1.000000E+00 -6.215888E+01 -1.635760E+01 -3.636042E-01
<surface> 1455 
type right_cylinder 1.000000E+00 -6.215888E+01 -1.635760E+01 -2.650788E-01
<surface> 1456 
type right_cylinder 1.000000E+00 -6.379464E+01 -1.635760E+01 -3.636042E-01
<surface> 1457 
type right_cylinder 1.000000E+00 -6.379464E+01 -1.635760E+01 -2.650788E-01
<surface> 1458 
type right_cylinder 1.000000E+00 -6.543040E+01 -1.635760E+01 -3.636042E-01
<surface> 1459 
type right_cylinder 1.000000E+00 -6.543040E+01 -1.635760E+01 -2.650788E-01
<surface> 1460 
type right_cylinder 1.000000E+00 -3.762248E+01 -1.799336E+01 -3.636042E-01
<surface> 1461 
type right_cylinder 1.000000E+00 -3.762248E+01 -1.799336E+01 -2.650788E-01
<surface> 1462 
type right_cylinder 1.000000E+00 -3.925824E+01 -1.799336E+01 -3.636042E-01
<surface> 1463 
type right_cylinder 1.000000E+00 -3.925824E+01 -1.799336E+01 -2.650788E-01
<surface> 1464 
type right_cylinder 1.000000E+00 -4.089400E+01 -1.799336E+01 -3.636042E-01
<surface> 1465 
type right_cylinder 1.000000E+00 -4.089400E+01 -1.799336E+01 -2.650788E-01
<surface> 1466 
type right_cylinder 1.000000E+00 -4.252976E+01 -1.799336E+01 -3.636042E-01
<surface> 1467 
type right_cylinder 1.000000E+00 -4.252976E+01 -1.799336E+01 -2.650788E-01
<surface> 1468 
type right_cylinder 1.000000E+00 -4.416552E+01 -1.799336E+01 -3.636042E-01
<surface> 1469 
type right_cylinder 1.000000E+00 -4.416552E+01 -1.799336E+01 -2.650788E-01
<surface> 1470 
type right_cylinder 1.000000E+00 -4.580128E+01 -1.799336E+01 -3.636042E-01
<surface> 1471 
type right_cylinder 1.000000E+00 -4.580128E+01 -1.799336E+01 -2.650788E-01
<surface> 1472 
type right_cylinder 1.000000E+00 -4.743704E+01 -1.799336E+01 -3.636042E-01
<surface> 1473 
type right_cylinder 1.000000E+00 -4.743704E+01 -1.799336E+01 -2.650788E-01
<surface> 1474 
type right_cylinder 1.000000E+00 -4.907280E+01 -1.799336E+01 -3.636042E-01
<surface> 1475 
type right_cylinder 1.000000E+00 -4.907280E+01 -1.799336E+01 -2.650788E-01
<surface> 1476 
type right_cylinder 1.000000E+00 -5.070856E+01 -1.799336E+01 -3.636042E-01
<surface> 1477 
type right_cylinder 1.000000E+00 -5.070856E+01 -1.799336E+01 -2.650788E-01
<surface> 1478 
type right_cylinder 1.000000E+00 -5.234432E+01 -1.799336E+01 -3.636042E-01
<surface> 1479 
type right_cylinder 1.000000E+00 -5.234432E+01 -1.799336E+01 -2.650788E-01
<surface> 1480 
type right_cylinder 1.000000E+00 -5.398008E+01 -1.799336E+01 -3.636042E-01
<surface> 1481 
type right_cylinder 1.000000E+00 -5.398008E+01 -1.799336E+01 -2.650788E-01
<surface> 1482 
type right_cylinder 1.000000E+00 -5.561584E+01 -1.799336E+01 -3.636042E-01
<surface> 1483 
type right_cylinder 1.000000E+00 -5.561584E+01 -1.799336E+01 -2.650788E-01
<surface> 1484 
type right_cylinder 1.000000E+00 -5.725160E+01 -1.799336E+01 -3.636042E-01
<surface> 1485 
type right_cylinder 1.000000E+00 -5.725160E+01 -1.799336E+01 -2.650788E-01
<surface> 1486 
type right_cylinder 1.000000E+00 -3.762248E+01 -1.962912E+01 -3.636042E-01
<surface> 1487 
type right_cylinder 1.000000E+00 -3.762248E+01 -1.962912E+01 -2.650788E-01
<surface> 1488 
type right_cylinder 1.000000E+00 -3.925824E+01 -1.962912E+01 -3.636042E-01
<surface> 1489 
type right_cylinder 1.000000E+00 -3.925824E+01 -1.962912E+01 -2.650788E-01
<surface> 1490 
type right_cylinder 1.000000E+00 -4.089400E+01 -1.962912E+01 -3.636042E-01
<surface> 1491 
type right_cylinder 1.000000E+00 -4.089400E+01 -1.962912E+01 -2.650788E-01
<surface> 1492 
type right_cylinder 1.000000E+00 -4.252976E+01 -1.962912E+01 -3.636042E-01
<surface> 1493 
type right_cylinder 1.000000E+00 -4.252976E+01 -1.962912E+01 -2.650788E-01
<surface> 1494 
type right_cylinder 1.000000E+00 -4.416552E+01 -1.962912E+01 -3.636042E-01
<surface> 1495 
type right_cylinder 1.000000E+00 -4.416552E+01 -1.962912E+01 -2.650788E-01
<surface> 1496 
type right_cylinder 1.000000E+00 -4.580128E+01 -1.962912E+01 -3.636042E-01
<surface> 1497 
type right_cylinder 1.000000E+00 -4.580128E+01 -1.962912E+01 -2.650788E-01
<surface> 1498 
type right_cylinder 1.000000E+00 -4.743704E+01 -1.962912E+01 -3.636042E-01
<surface> 1499 
type right_cylinder 1.000000E+00 -4.743704E+01 -1.962912E+01 -2.650788E-01
<surface> 1500 
type right_cylinder 1.000000E+00 -4.907280E+01 -1.962912E+01 -3.636042E-01
<surface> 1501 
type right_cylinder 1.000000E+00 -4.907280E+01 -1.962912E+01 -2.650788E-01
<surface> 1502 
type right_cylinder 1.000000E+00 -5.070856E+01 -1.962912E+01 -3.636042E-01
<surface> 1503 
type right_cylinder 1.000000E+00 -5.070856E+01 -1.962912E+01 -2.650788E-01
<surface> 1504 
type right_cylinder 1.000000E+00 -5.234432E+01 -1.962912E+01 -3.636042E-01
<surface> 1505 
type right_cylinder 1.000000E+00 -5.234432E+01 -1.962912E+01 -2.650788E-01
<surface> 1506 
type right_cylinder 1.000000E+00 -5.398008E+01 -1.962912E+01 -3.636042E-01
<surface> 1507 
type right_cylinder 1.000000E+00 -5.398008E+01 -1.962912E+01 -2.650788E-01
<surface> 1508 
type right_cylinder 1.000000E+00 -5.561584E+01 -1.962912E+01 -3.636042E-01
<surface> 1509 
type right_cylinder 1.000000E+00 -5.561584E+01 -1.962912E+01 -2.650788E-01
<surface> 1510 
type right_cylinder 1.000000E+00 -5.725160E+01 -1.962912E+01 -3.636042E-01
<surface> 1511 
type right_cylinder 1.000000E+00 -5.725160E+01 -1.962912E+01 -2.650788E-01
<surface> 1512 
type right_cylinder 1.000000E+00 -3.762248E+01 -2.126488E+01 -3.636042E-01
<surface> 1513 
type right_cylinder 1.000000E+00 -3.762248E+01 -2.126488E+01 -2.650788E-01
<surface> 1514 
type right_cylinder 1.000000E+00 -3.925824E+01 -2.126488E+01 -3.636042E-01
<surface> 1515 
type right_cylinder 1.000000E+00 -3.925824E+01 -2.126488E+01 -2.650788E-01
<surface> 1516 
type right_cylinder 1.000000E+00 -4.089400E+01 -2.126488E+01 -3.636042E-01
<surface> 1517 
type right_cylinder 1.000000E+00 -4.089400E+01 -2.126488E+01 -2.650788E-01
<surface> 1518 
type right_cylinder 1.000000E+00 -4.252976E+01 -2.126488E+01 -3.636042E-01
<surface> 1519 
type right_cylinder 1.000000E+00 -4.252976E+01 -2.126488E+01 -2.650788E-01
<surface> 1520 
type right_cylinder 1.000000E+00 -4.416552E+01 -2.126488E+01 -3.636042E-01
<surface> 1521 
type right_cylinder 1.000000E+00 -4.416552E+01 -2.126488E+01 -2.650788E-01
<surface> 1522 
type right_cylinder 1.000000E+00 -4.580128E+01 -2.126488E+01 -3.636042E-01
<surface> 1523 
type right_cylinder 1.000000E+00 -4.580128E+01 -2.126488E+01 -2.650788E-01
<surface> 1524 
type right_cylinder 1.000000E+00 -4.743704E+01 -2.126488E+01 -3.636042E-01
<surface> 1525 
type right_cylinder 1.000000E+00 -4.743704E+01 -2.126488E+01 -2.650788E-01
<surface> 1526 
type right_cylinder 1.000000E+00 -4.907280E+01 -2.126488E+01 -3.636042E-01
<surface> 1527 
type right_cylinder 1.000000E+00 -4.907280E+01 -2.126488E+01 -2.650788E-01
<surface> 1528 
type right_cylinder 1.000000E+00 -5.070856E+01 -2.126488E+01 -3.636042E-01
<surface> 1529 
type right_cylinder 1.000000E+00 -5.070856E+01 -2.126488E+01 -2.650788E-01
<surface> 1530 
type right_cylinder 1.000000E+00 -5.234432E+01 -2.126488E+01 -3.636042E-01
<surface> 1531 
type right_cylinder 1.000000E+00 -5.234432E+01 -2.126488E+01 -2.650788E-01
<surface> 1532 
type right_cylinder 1.000000E+00 -5.398008E+01 -2.126488E+01 -3.636042E-01
<surface> 1533 
type right_cylinder 1.000000E+00 -5.398008E+01 -2.126488E+01 -2.650788E-01
<surface> 1534 
type right_cylinder 1.000000E+00 -5.561584E+01 -2.126488E+01 -3.636042E-01
<surface> 1535 
type right_cylinder 1.000000E+00 -5.561584E+01 -2.126488E+01 -2.650788E-01
<surface> 1536 
type right_cylinder 1.000000E+00 -5.725160E+01 -2.126488E+01 -3.636042E-01
<surface> 1537 
type right_cylinder 1.000000E+00 -5.725160E+01 -2.126488E+01 -2.650788E-01
<surface> 1538 
type right_cylinder 1.000000E+00 -3.762248E+01 -2.290064E+01 -3.636042E-01
<surface> 1539 
type right_cylinder 1.000000E+00 -3.762248E+01 -2.290064E+01 -2.650788E-01
<surface> 1540 
type right_cylinder 1.000000E+00 -3.925824E+01 -2.290064E+01 -3.636042E-01
<surface> 1541 
type right_cylinder 1.000000E+00 -3.925824E+01 -2.290064E+01 -2.650788E-01
<surface> 1542 
type right_cylinder 1.000000E+00 -4.089400E+01 -2.290064E+01 -3.636042E-01
<surface> 1543 
type right_cylinder 1.000000E+00 -4.089400E+01 -2.290064E+01 -2.650788E-01
<surface> 1544 
type right_cylinder 1.000000E+00 -4.252976E+01 -2.290064E+01 -3.636042E-01
<surface> 1545 
type right_cylinder 1.000000E+00 -4.252976E+01 -2.290064E+01 -2.650788E-01
<surface> 1546 
type right_cylinder 1.000000E+00 -4.416552E+01 -2.290064E+01 -3.636042E-01
<surface> 1547 
type right_cylinder 1.000000E+00 -4.416552E+01 -2.290064E+01 -2.650788E-01
<surface> 1548 
type right_cylinder 1.000000E+00 -4.580128E+01 -2.290064E+01 -3.636042E-01
<surface> 1549 
type right_cylinder 1.000000E+00 -4.580128E+01 -2.290064E+01 -2.650788E-01
<surface> 1550 
type right_cylinder 1.000000E+00 -4.743704E+01 -2.290064E+01 -3.636042E-01
<surface> 1551 
type right_cylinder 1.000000E+00 -4.743704E+01 -2.290064E+01 -2.650788E-01
<surface> 1552 
type right_cylinder 1.000000E+00 -4.907280E+01 -2.290064E+01 -3.636042E-01
<surface> 1553 
type right_cylinder 1.000000E+00 -4.907280E+01 -2.290064E+01 -2.650788E-01
<surface> 1554 
type right_cylinder 1.000000E+00 -5.070856E+01 -2.290064E+01 -3.636042E-01
<surface> 1555 
type right_cylinder 1.000000E+00 -5.070856E+01 -2.290064E+01 -2.650788E-01
<surface> 1556 
type right_cylinder 1.000000E+00 -5.234432E+01 -2.290064E+01 -3.636042E-01
<surface> 1557 
type right_cylinder 1.000000E+00 -5.234432E+01 -2.290064E+01 -2.650788E-01
<surface> 1558 
type right_cylinder 1.000000E+00 -5.398008E+01 -2.290064E+01 -3.636042E-01
<surface> 1559 
type right_cylinder 1.000000E+00 -5.398008E+01 -2.290064E+01 -2.650788E-01
<surface> 1560 
type right_cylinder 1.000000E+00 -5.561584E+01 -2.290064E+01 -3.636042E-01
<surface> 1561 
type right_cylinder 1.000000E+00 -5.561584E+01 -2.290064E+01 -2.650788E-01
<surface> 1562 
type right_cylinder 1.000000E+00 -5.725160E+01 -2.290064E+01 -3.636042E-01
<surface> 1563 
type right_cylinder 1.000000E+00 -5.725160E+01 -2.290064E+01 -2.650788E-01
<surface> 1564 
type right_cylinder 1.000000E+00 -3.762248E+01 -2.453640E+01 -3.636042E-01
<surface> 1565 
type right_cylinder 1.000000E+00 -3.762248E+01 -2.453640E+01 -2.650788E-01
<surface> 1566 
type right_cylinder 1.000000E+00 -3.925824E+01 -2.453640E+01 -3.636042E-01
<surface> 1567 
type right_cylinder 1.000000E+00 -3.925824E+01 -2.453640E+01 -2.650788E-01
<surface> 1568 
type right_cylinder 1.000000E+00 -4.089400E+01 -2.453640E+01 -3.636042E-01
<surface> 1569 
type right_cylinder 1.000000E+00 -4.089400E+01 -2.453640E+01 -2.650788E-01
<surface> 1570 
type right_cylinder 1.000000E+00 -4.252976E+01 -2.453640E+01 -3.636042E-01
<surface> 1571 
type right_cylinder 1.000000E+00 -4.252976E+01 -2.453640E+01 -2.650788E-01
<surface> 1572 
type right_cylinder 1.000000E+00 -4.416552E+01 -2.453640E+01 -3.636042E-01
<surface> 1573 
type right_cylinder 1.000000E+00 -4.416552E+01 -2.453640E+01 -2.650788E-01
<surface> 1574 
type right_cylinder 1.000000E+00 -4.580128E+01 -2.453640E+01 -3.636042E-01
<surface> 1575 
type right_cylinder 1.000000E+00 -4.580128E+01 -2.453640E+01 -2.650788E-01
<surface> 1576 
type right_cylinder 1.000000E+00 -4.743704E+01 -2.453640E+01 -3.636042E-01
<surface> 1577 
type right_cylinder 1.000000E+00 -4.743704E+01 -2.453640E+01 -2.650788E-01
<surface> 1578 
type right_cylinder 1.000000E+00 -4.907280E+01 -2.453640E+01 -3.636042E-01
<surface> 1579 
type right_cylinder 1.000000E+00 -4.907280E+01 -2.453640E+01 -2.650788E-01
<surface> 1580 
type right_cylinder 1.000000E+00 -5.070856E+01 -2.453640E+01 -3.636042E-01
<surface> 1581 
type right_cylinder 1.000000E+00 -5.070856E+01 -2.453640E+01 -2.650788E-01
<surface> 1582 
type right_cylinder 1.000000E+00 -5.234432E+01 -2.453640E+01 -3.636042E-01
<surface> 1583 
type right_cylinder 1.000000E+00 -5.234432E+01 -2.453640E+01 -2.650788E-01
<surface> 1584 
type right_cylinder 1.000000E+00 -5.398008E+01 -2.453640E+01 -3.636042E-01
<surface> 1585 
type right_cylinder 1.000000E+00 -5.398008E+01 -2.453640E+01 -2.650788E-01
<surface> 1586 
type right_cylinder 1.000000E+00 -5.561584E+01 -2.453640E+01 -3.636042E-01
<surface> 1587 
type right_cylinder 1.000000E+00 -5.561584E+01 -2.453640E+01 -2.650788E-01
<surface> 1588 
type right_cylinder 1.000000E+00 -5.725160E+01 -2.453640E+01 -3.636042E-01
<surface> 1589 
type right_cylinder 1.000000E+00 -5.725160E+01 -2.453640E+01 -2.650788E-01
<surface> 1590 
type right_cylinder 1.000000E+00 -3.762248E+01 -2.617216E+01 -3.636042E-01
<surface> 1591 
type right_cylinder 1.000000E+00 -3.762248E+01 -2.617216E+01 -2.650788E-01
<surface> 1592 
type right_cylinder 1.000000E+00 -3.925824E+01 -2.617216E+01 -3.636042E-01
<surface> 1593 
type right_cylinder 1.000000E+00 -3.925824E+01 -2.617216E+01 -2.650788E-01
<surface> 1594 
type right_cylinder 1.000000E+00 -4.089400E+01 -2.617216E+01 -3.636042E-01
<surface> 1595 
type right_cylinder 1.000000E+00 -4.089400E+01 -2.617216E+01 -2.650788E-01
<surface> 1596 
type right_cylinder 1.000000E+00 -4.252976E+01 -2.617216E+01 -3.636042E-01
<surface> 1597 
type right_cylinder 1.000000E+00 -4.252976E+01 -2.617216E+01 -2.650788E-01
<surface> 1598 
type right_cylinder 1.000000E+00 -4.416552E+01 -2.617216E+01 -3.636042E-01
<surface> 1599 
type right_cylinder 1.000000E+00 -4.416552E+01 -2.617216E+01 -2.650788E-01
<surface> 1600 
type right_cylinder 1.000000E+00 -4.580128E+01 -2.617216E+01 -3.636042E-01
<surface> 1601 
type right_cylinder 1.000000E+00 -4.580128E+01 -2.617216E+01 -2.650788E-01
<surface> 1602 
type right_cylinder 1.000000E+00 -4.743704E+01 -2.617216E+01 -3.636042E-01
<surface> 1603 
type right_cylinder 1.000000E+00 -4.743704E+01 -2.617216E+01 -2.650788E-01
<surface> 1604 
type right_cylinder 1.000000E+00 -4.907280E+01 -2.617216E+01 -3.636042E-01
<surface> 1605 
type right_cylinder 1.000000E+00 -4.907280E+01 -2.617216E+01 -2.650788E-01
<surface> 1606 
type right_cylinder 1.000000E+00 -5.070856E+01 -2.617216E+01 -3.636042E-01
<surface> 1607 
type right_cylinder 1.000000E+00 -5.070856E+01 -2.617216E+01 -2.650788E-01
<surface> 1608 
type right_cylinder 1.000000E+00 -5.234432E+01 -2.617216E+01 -3.636042E-01
<surface> 1609 
type right_cylinder 1.000000E+00 -5.234432E+01 -2.617216E+01 -2.650788E-01
<surface> 1610 
type right_cylinder 1.000000E+00 -5.398008E+01 -2.617216E+01 -3.636042E-01
<surface> 1611 
type right_cylinder 1.000000E+00 -5.398008E+01 -2.617216E+01 -2.650788E-01
<surface> 1612 
type right_cylinder 1.000000E+00 -5.561584E+01 -2.617216E+01 -3.636042E-01
<surface> 1613 
type right_cylinder 1.000000E+00 -5.561584E+01 -2.617216E+01 -2.650788E-01
<surface> 1614 
type right_cylinder 1.000000E+00 -5.725160E+01 -2.617216E+01 -3.636042E-01
<surface> 1615 
type right_cylinder 1.000000E+00 -5.725160E+01 -2.617216E+01 -2.650788E-01
<surface> 1616 
type right_cylinder 1.000000E+00 -3.762248E+01 -2.780792E+01 -3.636042E-01
<surface> 1617 
type right_cylinder 1.000000E+00 -3.762248E+01 -2.780792E+01 -2.650788E-01
<surface> 1618 
type right_cylinder 1.000000E+00 -3.925824E+01 -2.780792E+01 -3.636042E-01
<surface> 1619 
type right_cylinder 1.000000E+00 -3.925824E+01 -2.780792E+01 -2.650788E-01
<surface> 1620 
type right_cylinder 1.000000E+00 -4.089400E+01 -2.780792E+01 -3.636042E-01
<surface> 1621 
type right_cylinder 1.000000E+00 -4.089400E+01 -2.780792E+01 -2.650788E-01
<surface> 1622 
type right_cylinder 1.000000E+00 -4.252976E+01 -2.780792E+01 -3.636042E-01
<surface> 1623 
type right_cylinder 1.000000E+00 -4.252976E+01 -2.780792E+01 -2.650788E-01
<surface> 1624 
type right_cylinder 1.000000E+00 -4.416552E+01 -2.780792E+01 -3.636042E-01
<surface> 1625 
type right_cylinder 1.000000E+00 -4.416552E+01 -2.780792E+01 -2.650788E-01
<surface> 1626 
type right_cylinder 1.000000E+00 -4.580128E+01 -2.780792E+01 -3.636042E-01
<surface> 1627 
type right_cylinder 1.000000E+00 -4.580128E+01 -2.780792E+01 -2.650788E-01
<surface> 1628 
type right_cylinder 1.000000E+00 -4.743704E+01 -2.780792E+01 -3.636042E-01
<surface> 1629 
type right_cylinder 1.000000E+00 -4.743704E+01 -2.780792E+01 -2.650788E-01
<surface> 1630 
type right_cylinder 1.000000E+00 -4.907280E+01 -2.780792E+01 -3.636042E-01
<surface> 1631 
type right_cylinder 1.000000E+00 -4.907280E+01 -2.780792E+01 -2.650788E-01
<surface> 1632 
type right_cylinder 1.000000E+00 -5.070856E+01 -2.780792E+01 -3.636042E-01
<surface> 1633 
type right_cylinder 1.000000E+00 -5.070856E+01 -2.780792E+01 -2.650788E-01
<surface> 1634 
type right_cylinder 1.000000E+00 -5.234432E+01 -2.780792E+01 -3.636042E-01
<surface> 1635 
type right_cylinder 1.000000E+00 -5.234432E+01 -2.780792E+01 -2.650788E-01
<surface> 1636 
type right_cylinder 1.000000E+00 -5.398008E+01 -2.780792E+01 -3.636042E-01
<surface> 1637 
type right_cylinder 1.000000E+00 -5.398008E+01 -2.780792E+01 -2.650788E-01
<surface> 1638 
type right_cylinder 1.000000E+00 -5.561584E+01 -2.780792E+01 -3.636042E-01
<surface> 1639 
type right_cylinder 1.000000E+00 -5.561584E+01 -2.780792E+01 -2.650788E-01
<surface> 1640 
type right_cylinder 1.000000E+00 -5.725160E+01 -2.780792E+01 -3.636042E-01
<surface> 1641 
type right_cylinder 1.000000E+00 -5.725160E+01 -2.780792E+01 -2.650788E-01
<surface> 1642 
type right_cylinder 1.000000E+00 -3.762248E+01 -2.944368E+01 -3.636042E-01
<surface> 1643 
type right_cylinder 1.000000E+00 -3.762248E+01 -2.944368E+01 -2.650788E-01
<surface> 1644 
type right_cylinder 1.000000E+00 -3.925824E+01 -2.944368E+01 -3.636042E-01
<surface> 1645 
type right_cylinder 1.000000E+00 -3.925824E+01 -2.944368E+01 -2.650788E-01
<surface> 1646 
type right_cylinder 1.000000E+00 -4.089400E+01 -2.944368E+01 -3.636042E-01
<surface> 1647 
type right_cylinder 1.000000E+00 -4.089400E+01 -2.944368E+01 -2.650788E-01
<surface> 1648 
type right_cylinder 1.000000E+00 -4.252976E+01 -2.944368E+01 -3.636042E-01
<surface> 1649 
type right_cylinder 1.000000E+00 -4.252976E+01 -2.944368E+01 -2.650788E-01
<surface> 1650 
type right_cylinder 1.000000E+00 -4.416552E+01 -2.944368E+01 -3.636042E-01
<surface> 1651 
type right_cylinder 1.000000E+00 -4.416552E+01 -2.944368E+01 -2.650788E-01
<surface> 1652 
type right_cylinder 1.000000E+00 -4.580128E+01 -2.944368E+01 -3.636042E-01
<surface> 1653 
type right_cylinder 1.000000E+00 -4.580128E+01 -2.944368E+01 -2.650788E-01
<surface> 1654 
type right_cylinder 1.000000E+00 -4.743704E+01 -2.944368E+01 -3.636042E-01
<surface> 1655 
type right_cylinder 1.000000E+00 -4.743704E+01 -2.944368E+01 -2.650788E-01
<surface> 1656 
type right_cylinder 1.000000E+00 -4.907280E+01 -2.944368E+01 -3.636042E-01
<surface> 1657 
type right_cylinder 1.000000E+00 -4.907280E+01 -2.944368E+01 -2.650788E-01
<surface> 1658 
type right_cylinder 1.000000E+00 -5.070856E+01 -2.944368E+01 -3.636042E-01
<surface> 1659 
type right_cylinder 1.000000E+00 -5.070856E+01 -2.944368E+01 -2.650788E-01
<surface> 1660 
type right_cylinder 1.000000E+00 -5.234432E+01 -2.944368E+01 -3.636042E-01
<surface> 1661 
type right_cylinder 1.000000E+00 -5.234432E+01 -2.944368E+01 -2.650788E-01
<surface> 1662 
type right_cylinder 1.000000E+00 -5.398008E+01 -2.944368E+01 -3.636042E-01
<surface> 1663 
type right_cylinder 1.000000E+00 -5.398008E+01 -2.944368E+01 -2.650788E-01
<surface> 1664 
type right_cylinder 1.000000E+00 -5.561584E+01 -2.944368E+01 -3.636042E-01
<surface> 1665 
type right_cylinder 1.000000E+00 -5.561584E+01 -2.944368E+01 -2.650788E-01
<surface> 1666 
type right_cylinder 1.000000E+00 -5.725160E+01 -2.944368E+01 -3.636042E-01
<surface> 1667 
type right_cylinder 1.000000E+00 -5.725160E+01 -2.944368E+01 -2.650788E-01
<surface> 1668 
type right_cylinder 1.000000E+00 -3.762248E+01 -3.107944E+01 -3.636042E-01
<surface> 1669 
type right_cylinder 1.000000E+00 -3.762248E+01 -3.107944E+01 -2.650788E-01
<surface> 1670 
type right_cylinder 1.000000E+00 -3.925824E+01 -3.107944E+01 -3.636042E-01
<surface> 1671 
type right_cylinder 1.000000E+00 -3.925824E+01 -3.107944E+01 -2.650788E-01
<surface> 1672 
type right_cylinder 1.000000E+00 -4.089400E+01 -3.107944E+01 -3.636042E-01
<surface> 1673 
type right_cylinder 1.000000E+00 -4.089400E+01 -3.107944E+01 -2.650788E-01
<surface> 1674 
type right_cylinder 1.000000E+00 -4.252976E+01 -3.107944E+01 -3.636042E-01
<surface> 1675 
type right_cylinder 1.000000E+00 -4.252976E+01 -3.107944E+01 -2.650788E-01
<surface> 1676 
type right_cylinder 1.000000E+00 -4.416552E+01 -3.107944E+01 -3.636042E-01
<surface> 1677 
type right_cylinder 1.000000E+00 -4.416552E+01 -3.107944E+01 -2.650788E-01
<surface> 1678 
type right_cylinder 1.000000E+00 -4.580128E+01 -3.107944E+01 -3.636042E-01
<surface> 1679 
type right_cylinder 1.000000E+00 -4.580128E+01 -3.107944E+01 -2.650788E-01
<surface> 1680 
type right_cylinder 1.000000E+00 -4.743704E+01 -3.107944E+01 -3.636042E-01
<surface> 1681 
type right_cylinder 1.000000E+00 -4.743704E+01 -3.107944E+01 -2.650788E-01
<surface> 1682 
type right_cylinder 1.000000E+00 -4.907280E+01 -3.107944E+01 -3.636042E-01
<surface> 1683 
type right_cylinder 1.000000E+00 -4.907280E+01 -3.107944E+01 -2.650788E-01
<surface> 1684 
type right_cylinder 1.000000E+00 -5.070856E+01 -3.107944E+01 -3.636042E-01
<surface> 1685 
type right_cylinder 1.000000E+00 -5.070856E+01 -3.107944E+01 -2.650788E-01
<surface> 1686 
type right_cylinder 1.000000E+00 -5.234432E+01 -3.107944E+01 -3.636042E-01
<surface> 1687 
type right_cylinder 1.000000E+00 -5.234432E+01 -3.107944E+01 -2.650788E-01
<surface> 1688 
type right_cylinder 1.000000E+00 -5.398008E+01 -3.107944E+01 -3.636042E-01
<surface> 1689 
type right_cylinder 1.000000E+00 -5.398008E+01 -3.107944E+01 -2.650788E-01
<surface> 1690 
type right_cylinder 1.000000E+00 -5.561584E+01 -3.107944E+01 -3.636042E-01
<surface> 1691 
type right_cylinder 1.000000E+00 -5.561584E+01 -3.107944E+01 -2.650788E-01
<surface> 1692 
type right_cylinder 1.000000E+00 -5.725160E+01 -3.107944E+01 -3.636042E-01
<surface> 1693 
type right_cylinder 1.000000E+00 -5.725160E+01 -3.107944E+01 -2.650788E-01
<surface> 1694 
type right_cylinder 1.000000E+00 -3.762248E+01 -3.271520E+01 -3.636042E-01
<surface> 1695 
type right_cylinder 1.000000E+00 -3.762248E+01 -3.271520E+01 -2.650788E-01
<surface> 1696 
type right_cylinder 1.000000E+00 -3.925824E+01 -3.271520E+01 -3.636042E-01
<surface> 1697 
type right_cylinder 1.000000E+00 -3.925824E+01 -3.271520E+01 -2.650788E-01
<surface> 1698 
type right_cylinder 1.000000E+00 -4.089400E+01 -3.271520E+01 -3.636042E-01
<surface> 1699 
type right_cylinder 1.000000E+00 -4.089400E+01 -3.271520E+01 -2.650788E-01
<surface> 1700 
type right_cylinder 1.000000E+00 -4.252976E+01 -3.271520E+01 -3.636042E-01
<surface> 1701 
type right_cylinder 1.000000E+00 -4.252976E+01 -3.271520E+01 -2.650788E-01
<surface> 1702 
type right_cylinder 1.000000E+00 -4.416552E+01 -3.271520E+01 -3.636042E-01
<surface> 1703 
type right_cylinder 1.000000E+00 -4.416552E+01 -3.271520E+01 -2.650788E-01
<surface> 1704 
type right_cylinder 1.000000E+00 -4.580128E+01 -3.271520E+01 -3.636042E-01
<surface> 1705 
type right_cylinder 1.000000E+00 -4.580128E+01 -3.271520E+01 -2.650788E-01
<surface> 1706 
type right_cylinder 1.000000E+00 -4.743704E+01 -3.271520E+01 -3.636042E-01
<surface> 1707 
type right_cylinder 1.000000E+00 -4.743704E+01 -3.271520E+01 -2.650788E-01
<surface> 1708 
type right_cylinder 1.000000E+00 -4.907280E+01 -3.271520E+01 -3.636042E-01
<surface> 1709 
type right_cylinder 1.000000E+00 -4.907280E+01 -3.271520E+01 -2.650788E-01
<surface> 1710 
type right_cylinder 1.000000E+00 -5.070856E+01 -3.271520E+01 -3.636042E-01
<surface> 1711 
type right_cylinder 1.000000E+00 -5.070856E+01 -3.271520E+01 -2.650788E-01
<surface> 1712 
type right_cylinder 1.000000E+00 -5.234432E+01 -3.271520E+01 -3.636042E-01
<surface> 1713 
type right_cylinder 1.000000E+00 -5.234432E+01 -3.271520E+01 -2.650788E-01
<surface> 1714 
type right_cylinder 1.000000E+00 -5.398008E+01 -3.271520E+01 -3.636042E-01
<surface> 1715 
type right_cylinder 1.000000E+00 -5.398008E+01 -3.271520E+01 -2.650788E-01
<surface> 1716 
type right_cylinder 1.000000E+00 -5.561584E+01 -3.271520E+01 -3.636042E-01
<surface> 1717 
type right_cylinder 1.000000E+00 -5.561584E+01 -3.271520E+01 -2.650788E-01
<surface> 1718 
type right_cylinder 1.000000E+00 -5.725160E+01 -3.271520E+01 -3.636042E-01
<surface> 1719 
type right_cylinder 1.000000E+00 -5.725160E+01 -3.271520E+01 -2.650788E-01
<surface> 1720 
type right_cylinder 1.000000E+00 -3.762248E+01 -3.435096E+01 -3.636042E-01
<surface> 1721 
type right_cylinder 1.000000E+00 -3.762248E+01 -3.435096E+01 -2.650788E-01
<surface> 1722 
type right_cylinder 1.000000E+00 -3.925824E+01 -3.435096E+01 -3.636042E-01
<surface> 1723 
type right_cylinder 1.000000E+00 -3.925824E+01 -3.435096E+01 -2.650788E-01
<surface> 1724 
type right_cylinder 1.000000E+00 -4.089400E+01 -3.435096E+01 -3.636042E-01
<surface> 1725 
type right_cylinder 1.000000E+00 -4.089400E+01 -3.435096E+01 -2.650788E-01
<surface> 1726 
type right_cylinder 1.000000E+00 -4.252976E+01 -3.435096E+01 -3.636042E-01
<surface> 1727 
type right_cylinder 1.000000E+00 -4.252976E+01 -3.435096E+01 -2.650788E-01
<surface> 1728 
type right_cylinder 1.000000E+00 -4.416552E+01 -3.435096E+01 -3.636042E-01
<surface> 1729 
type right_cylinder 1.000000E+00 -4.416552E+01 -3.435096E+01 -2.650788E-01
<surface> 1730 
type right_cylinder 1.000000E+00 -4.580128E+01 -3.435096E+01 -3.636042E-01
<surface> 1731 
type right_cylinder 1.000000E+00 -4.580128E+01 -3.435096E+01 -2.650788E-01
<surface> 1732 
type right_cylinder 1.000000E+00 -4.743704E+01 -3.435096E+01 -3.636042E-01
<surface> 1733 
type right_cylinder 1.000000E+00 -4.743704E+01 -3.435096E+01 -2.650788E-01
<surface> 1734 
type right_cylinder 1.000000E+00 -4.907280E+01 -3.435096E+01 -3.636042E-01
<surface> 1735 
type right_cylinder 1.000000E+00 -4.907280E+01 -3.435096E+01 -2.650788E-01
<surface> 1736 
type right_cylinder 1.000000E+00 -3.762248E+01 -3.598672E+01 -3.636042E-01
<surface> 1737 
type right_cylinder 1.000000E+00 -3.762248E+01 -3.598672E+01 -2.650788E-01
<surface> 1738 
type right_cylinder 1.000000E+00 -3.925824E+01 -3.598672E+01 -3.636042E-01
<surface> 1739 
type right_cylinder 1.000000E+00 -3.925824E+01 -3.598672E+01 -2.650788E-01
<surface> 1740 
type right_cylinder 1.000000E+00 -4.089400E+01 -3.598672E+01 -3.636042E-01
<surface> 1741 
type right_cylinder 1.000000E+00 -4.089400E+01 -3.598672E+01 -2.650788E-01
<surface> 1742 
type right_cylinder 1.000000E+00 -4.252976E+01 -3.598672E+01 -3.636042E-01
<surface> 1743 
type right_cylinder 1.000000E+00 -4.252976E+01 -3.598672E+01 -2.650788E-01
<surface> 1744 
type right_cylinder 1.000000E+00 -4.416552E+01 -3.598672E+01 -3.636042E-01
<surface> 1745 
type right_cylinder 1.000000E+00 -4.416552E+01 -3.598672E+01 -2.650788E-01
<surface> 1746 
type right_cylinder 1.000000E+00 -4.580128E+01 -3.598672E+01 -3.636042E-01
<surface> 1747 
type right_cylinder 1.000000E+00 -4.580128E+01 -3.598672E+01 -2.650788E-01
<surface> 1748 
type right_cylinder 1.000000E+00 -4.743704E+01 -3.598672E+01 -3.636042E-01
<surface> 1749 
type right_cylinder 1.000000E+00 -4.743704E+01 -3.598672E+01 -2.650788E-01
<surface> 1750 
type right_cylinder 1.000000E+00 -4.907280E+01 -3.598672E+01 -3.636042E-01
<surface> 1751 
type right_cylinder 1.000000E+00 -4.907280E+01 -3.598672E+01 -2.650788E-01
<surface> 1752 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -3.844036E+01
<surface> 1753 
type right_cylinder 1.000000E+00 0.000000E+00 -3.762248E+01 -3.636042E-01
<surface> 1754 
type right_cylinder 1.000000E+00 0.000000E+00 -3.762248E+01 -2.650788E-01
<surface> 1755 
type right_cylinder 1.000000E+00 -1.635760E+00 -3.762248E+01 -3.636042E-01
<surface> 1756 
type right_cylinder 1.000000E+00 -1.635760E+00 -3.762248E+01 -2.650788E-01
<surface> 1757 
type right_cylinder 1.000000E+00 -3.271520E+00 -3.762248E+01 -3.636042E-01
<surface> 1758 
type right_cylinder 1.000000E+00 -3.271520E+00 -3.762248E+01 -2.650788E-01
<surface> 1759 
type right_cylinder 1.000000E+00 -4.907280E+00 -3.762248E+01 -3.636042E-01
<surface> 1760 
type right_cylinder 1.000000E+00 -4.907280E+00 -3.762248E+01 -2.650788E-01
<surface> 1761 
type right_cylinder 1.000000E+00 -6.543040E+00 -3.762248E+01 -3.636042E-01
<surface> 1762 
type right_cylinder 1.000000E+00 -6.543040E+00 -3.762248E+01 -2.650788E-01
<surface> 1763 
type right_cylinder 1.000000E+00 -8.178800E+00 -3.762248E+01 -3.636042E-01
<surface> 1764 
type right_cylinder 1.000000E+00 -8.178800E+00 -3.762248E+01 -2.650788E-01
<surface> 1765 
type right_cylinder 1.000000E+00 -9.814560E+00 -3.762248E+01 -3.636042E-01
<surface> 1766 
type right_cylinder 1.000000E+00 -9.814560E+00 -3.762248E+01 -2.650788E-01
<surface> 1767 
type right_cylinder 1.000000E+00 -1.145032E+01 -3.762248E+01 -3.636042E-01
<surface> 1768 
type right_cylinder 1.000000E+00 -1.145032E+01 -3.762248E+01 -2.650788E-01
<surface> 1769 
type right_cylinder 1.000000E+00 -1.308608E+01 -3.762248E+01 -3.636042E-01
<surface> 1770 
type right_cylinder 1.000000E+00 -1.308608E+01 -3.762248E+01 -2.650788E-01
<surface> 1771 
type right_cylinder 1.000000E+00 -1.472184E+01 -3.762248E+01 -3.636042E-01
<surface> 1772 
type right_cylinder 1.000000E+00 -1.472184E+01 -3.762248E+01 -2.650788E-01
<surface> 1773 
type right_cylinder 1.000000E+00 -1.635760E+01 -3.762248E+01 -3.636042E-01
<surface> 1774 
type right_cylinder 1.000000E+00 -1.635760E+01 -3.762248E+01 -2.650788E-01
<surface> 1775 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -4.007612E+01
<surface> 1776 
type right_cylinder 1.000000E+00 0.000000E+00 -3.925824E+01 -3.636042E-01
<surface> 1777 
type right_cylinder 1.000000E+00 0.000000E+00 -3.925824E+01 -2.650788E-01
<surface> 1778 
type right_cylinder 1.000000E+00 -1.635760E+00 -3.925824E+01 -3.636042E-01
<surface> 1779 
type right_cylinder 1.000000E+00 -1.635760E+00 -3.925824E+01 -2.650788E-01
<surface> 1780 
type right_cylinder 1.000000E+00 -3.271520E+00 -3.925824E+01 -3.636042E-01
<surface> 1781 
type right_cylinder 1.000000E+00 -3.271520E+00 -3.925824E+01 -2.650788E-01
<surface> 1782 
type right_cylinder 1.000000E+00 -4.907280E+00 -3.925824E+01 -3.636042E-01
<surface> 1783 
type right_cylinder 1.000000E+00 -4.907280E+00 -3.925824E+01 -2.650788E-01
<surface> 1784 
type right_cylinder 1.000000E+00 -6.543040E+00 -3.925824E+01 -3.636042E-01
<surface> 1785 
type right_cylinder 1.000000E+00 -6.543040E+00 -3.925824E+01 -2.650788E-01
<surface> 1786 
type right_cylinder 1.000000E+00 -8.178800E+00 -3.925824E+01 -3.636042E-01
<surface> 1787 
type right_cylinder 1.000000E+00 -8.178800E+00 -3.925824E+01 -2.650788E-01
<surface> 1788 
type right_cylinder 1.000000E+00 -9.814560E+00 -3.925824E+01 -3.636042E-01
<surface> 1789 
type right_cylinder 1.000000E+00 -9.814560E+00 -3.925824E+01 -2.650788E-01
<surface> 1790 
type right_cylinder 1.000000E+00 -1.145032E+01 -3.925824E+01 -3.636042E-01
<surface> 1791 
type right_cylinder 1.000000E+00 -1.145032E+01 -3.925824E+01 -2.650788E-01
<surface> 1792 
type right_cylinder 1.000000E+00 -1.308608E+01 -3.925824E+01 -3.636042E-01
<surface> 1793 
type right_cylinder 1.000000E+00 -1.308608E+01 -3.925824E+01 -2.650788E-01
<surface> 1794 
type right_cylinder 1.000000E+00 -1.472184E+01 -3.925824E+01 -3.636042E-01
<surface> 1795 
type right_cylinder 1.000000E+00 -1.472184E+01 -3.925824E+01 -2.650788E-01
<surface> 1796 
type right_cylinder 1.000000E+00 -1.635760E+01 -3.925824E+01 -3.636042E-01
<surface> 1797 
type right_cylinder 1.000000E+00 -1.635760E+01 -3.925824E+01 -2.650788E-01
<surface> 1798 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -4.171188E+01
<surface> 1799 
type right_cylinder 1.000000E+00 0.000000E+00 -4.089400E+01 -3.636042E-01
<surface> 1800 
type right_cylinder 1.000000E+00 0.000000E+00 -4.089400E+01 -2.650788E-01
<surface> 1801 
type right_cylinder 1.000000E+00 -1.635760E+00 -4.089400E+01 -3.636042E-01
<surface> 1802 
type right_cylinder 1.000000E+00 -1.635760E+00 -4.089400E+01 -2.650788E-01
<surface> 1803 
type right_cylinder 1.000000E+00 -3.271520E+00 -4.089400E+01 -3.636042E-01
<surface> 1804 
type right_cylinder 1.000000E+00 -3.271520E+00 -4.089400E+01 -2.650788E-01
<surface> 1805 
type right_cylinder 1.000000E+00 -4.907280E+00 -4.089400E+01 -3.636042E-01
<surface> 1806 
type right_cylinder 1.000000E+00 -4.907280E+00 -4.089400E+01 -2.650788E-01
<surface> 1807 
type right_cylinder 1.000000E+00 -6.543040E+00 -4.089400E+01 -3.636042E-01
<surface> 1808 
type right_cylinder 1.000000E+00 -6.543040E+00 -4.089400E+01 -2.650788E-01
<surface> 1809 
type right_cylinder 1.000000E+00 -8.178800E+00 -4.089400E+01 -3.636042E-01
<surface> 1810 
type right_cylinder 1.000000E+00 -8.178800E+00 -4.089400E+01 -2.650788E-01
<surface> 1811 
type right_cylinder 1.000000E+00 -9.814560E+00 -4.089400E+01 -3.636042E-01
<surface> 1812 
type right_cylinder 1.000000E+00 -9.814560E+00 -4.089400E+01 -2.650788E-01
<surface> 1813 
type right_cylinder 1.000000E+00 -1.145032E+01 -4.089400E+01 -3.636042E-01
<surface> 1814 
type right_cylinder 1.000000E+00 -1.145032E+01 -4.089400E+01 -2.650788E-01
<surface> 1815 
type right_cylinder 1.000000E+00 -1.308608E+01 -4.089400E+01 -3.636042E-01
<surface> 1816 
type right_cylinder 1.000000E+00 -1.308608E+01 -4.089400E+01 -2.650788E-01
<surface> 1817 
type right_cylinder 1.000000E+00 -1.472184E+01 -4.089400E+01 -3.636042E-01
<surface> 1818 
type right_cylinder 1.000000E+00 -1.472184E+01 -4.089400E+01 -2.650788E-01
<surface> 1819 
type right_cylinder 1.000000E+00 -1.635760E+01 -4.089400E+01 -3.636042E-01
<surface> 1820 
type right_cylinder 1.000000E+00 -1.635760E+01 -4.089400E+01 -2.650788E-01
<surface> 1821 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -4.334764E+01
<surface> 1822 
type right_cylinder 1.000000E+00 0.000000E+00 -4.252976E+01 -3.636042E-01
<surface> 1823 
type right_cylinder 1.000000E+00 0.000000E+00 -4.252976E+01 -2.650788E-01
<surface> 1824 
type right_cylinder 1.000000E+00 -1.635760E+00 -4.252976E+01 -3.636042E-01
<surface> 1825 
type right_cylinder 1.000000E+00 -1.635760E+00 -4.252976E+01 -2.650788E-01
<surface> 1826 
type right_cylinder 1.000000E+00 -3.271520E+00 -4.252976E+01 -3.636042E-01
<surface> 1827 
type right_cylinder 1.000000E+00 -3.271520E+00 -4.252976E+01 -2.650788E-01
<surface> 1828 
type right_cylinder 1.000000E+00 -4.907280E+00 -4.252976E+01 -3.636042E-01
<surface> 1829 
type right_cylinder 1.000000E+00 -4.907280E+00 -4.252976E+01 -2.650788E-01
<surface> 1830 
type right_cylinder 1.000000E+00 -6.543040E+00 -4.252976E+01 -3.636042E-01
<surface> 1831 
type right_cylinder 1.000000E+00 -6.543040E+00 -4.252976E+01 -2.650788E-01
<surface> 1832 
type right_cylinder 1.000000E+00 -8.178800E+00 -4.252976E+01 -3.636042E-01
<surface> 1833 
type right_cylinder 1.000000E+00 -8.178800E+00 -4.252976E+01 -2.650788E-01
<surface> 1834 
type right_cylinder 1.000000E+00 -9.814560E+00 -4.252976E+01 -3.636042E-01
<surface> 1835 
type right_cylinder 1.000000E+00 -9.814560E+00 -4.252976E+01 -2.650788E-01
<surface> 1836 
type right_cylinder 1.000000E+00 -1.145032E+01 -4.252976E+01 -3.636042E-01
<surface> 1837 
type right_cylinder 1.000000E+00 -1.145032E+01 -4.252976E+01 -2.650788E-01
<surface> 1838 
type right_cylinder 1.000000E+00 -1.308608E+01 -4.252976E+01 -3.636042E-01
<surface> 1839 
type right_cylinder 1.000000E+00 -1.308608E+01 -4.252976E+01 -2.650788E-01
<surface> 1840 
type right_cylinder 1.000000E+00 -1.472184E+01 -4.252976E+01 -3.636042E-01
<surface> 1841 
type right_cylinder 1.000000E+00 -1.472184E+01 -4.252976E+01 -2.650788E-01
<surface> 1842 
type right_cylinder 1.000000E+00 -1.635760E+01 -4.252976E+01 -3.636042E-01
<surface> 1843 
type right_cylinder 1.000000E+00 -1.635760E+01 -4.252976E+01 -2.650788E-01
<surface> 1844 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -4.498340E+01
<surface> 1845 
type right_cylinder 1.000000E+00 0.000000E+00 -4.416552E+01 -3.636042E-01
<surface> 1846 
type right_cylinder 1.000000E+00 0.000000E+00 -4.416552E+01 -2.650788E-01
<surface> 1847 
type right_cylinder 1.000000E+00 -1.635760E+00 -4.416552E+01 -3.636042E-01
<surface> 1848 
type right_cylinder 1.000000E+00 -1.635760E+00 -4.416552E+01 -2.650788E-01
<surface> 1849 
type right_cylinder 1.000000E+00 -3.271520E+00 -4.416552E+01 -3.636042E-01
<surface> 1850 
type right_cylinder 1.000000E+00 -3.271520E+00 -4.416552E+01 -2.650788E-01
<surface> 1851 
type right_cylinder 1.000000E+00 -4.907280E+00 -4.416552E+01 -3.636042E-01
<surface> 1852 
type right_cylinder 1.000000E+00 -4.907280E+00 -4.416552E+01 -2.650788E-01
<surface> 1853 
type right_cylinder 1.000000E+00 -6.543040E+00 -4.416552E+01 -3.636042E-01
<surface> 1854 
type right_cylinder 1.000000E+00 -6.543040E+00 -4.416552E+01 -2.650788E-01
<surface> 1855 
type right_cylinder 1.000000E+00 -8.178800E+00 -4.416552E+01 -3.636042E-01
<surface> 1856 
type right_cylinder 1.000000E+00 -8.178800E+00 -4.416552E+01 -2.650788E-01
<surface> 1857 
type right_cylinder 1.000000E+00 -9.814560E+00 -4.416552E+01 -3.636042E-01
<surface> 1858 
type right_cylinder 1.000000E+00 -9.814560E+00 -4.416552E+01 -2.650788E-01
<surface> 1859 
type right_cylinder 1.000000E+00 -1.145032E+01 -4.416552E+01 -3.636042E-01
<surface> 1860 
type right_cylinder 1.000000E+00 -1.145032E+01 -4.416552E+01 -2.650788E-01
<surface> 1861 
type right_cylinder 1.000000E+00 -1.308608E+01 -4.416552E+01 -3.636042E-01
<surface> 1862 
type right_cylinder 1.000000E+00 -1.308608E+01 -4.416552E+01 -2.650788E-01
<surface> 1863 
type right_cylinder 1.000000E+00 -1.472184E+01 -4.416552E+01 -3.636042E-01
<surface> 1864 
type right_cylinder 1.000000E+00 -1.472184E+01 -4.416552E+01 -2.650788E-01
<surface> 1865 
type right_cylinder 1.000000E+00 -1.635760E+01 -4.416552E+01 -3.636042E-01
<surface> 1866 
type right_cylinder 1.000000E+00 -1.635760E+01 -4.416552E+01 -2.650788E-01
<surface> 1867 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -4.661916E+01
<surface> 1868 
type right_cylinder 1.000000E+00 0.000000E+00 -4.580128E+01 -3.636042E-01
<surface> 1869 
type right_cylinder 1.000000E+00 0.000000E+00 -4.580128E+01 -2.650788E-01
<surface> 1870 
type right_cylinder 1.000000E+00 -1.635760E+00 -4.580128E+01 -3.636042E-01
<surface> 1871 
type right_cylinder 1.000000E+00 -1.635760E+00 -4.580128E+01 -2.650788E-01
<surface> 1872 
type right_cylinder 1.000000E+00 -3.271520E+00 -4.580128E+01 -3.636042E-01
<surface> 1873 
type right_cylinder 1.000000E+00 -3.271520E+00 -4.580128E+01 -2.650788E-01
<surface> 1874 
type right_cylinder 1.000000E+00 -4.907280E+00 -4.580128E+01 -3.636042E-01
<surface> 1875 
type right_cylinder 1.000000E+00 -4.907280E+00 -4.580128E+01 -2.650788E-01
<surface> 1876 
type right_cylinder 1.000000E+00 -6.543040E+00 -4.580128E+01 -3.636042E-01
<surface> 1877 
type right_cylinder 1.000000E+00 -6.543040E+00 -4.580128E+01 -2.650788E-01
<surface> 1878 
type right_cylinder 1.000000E+00 -8.178800E+00 -4.580128E+01 -3.636042E-01
<surface> 1879 
type right_cylinder 1.000000E+00 -8.178800E+00 -4.580128E+01 -2.650788E-01
<surface> 1880 
type right_cylinder 1.000000E+00 -9.814560E+00 -4.580128E+01 -3.636042E-01
<surface> 1881 
type right_cylinder 1.000000E+00 -9.814560E+00 -4.580128E+01 -2.650788E-01
<surface> 1882 
type right_cylinder 1.000000E+00 -1.145032E+01 -4.580128E+01 -3.636042E-01
<surface> 1883 
type right_cylinder 1.000000E+00 -1.145032E+01 -4.580128E+01 -2.650788E-01
<surface> 1884 
type right_cylinder 1.000000E+00 -1.308608E+01 -4.580128E+01 -3.636042E-01
<surface> 1885 
type right_cylinder 1.000000E+00 -1.308608E+01 -4.580128E+01 -2.650788E-01
<surface> 1886 
type right_cylinder 1.000000E+00 -1.472184E+01 -4.580128E+01 -3.636042E-01
<surface> 1887 
type right_cylinder 1.000000E+00 -1.472184E+01 -4.580128E+01 -2.650788E-01
<surface> 1888 
type right_cylinder 1.000000E+00 -1.635760E+01 -4.580128E+01 -3.636042E-01
<surface> 1889 
type right_cylinder 1.000000E+00 -1.635760E+01 -4.580128E+01 -2.650788E-01
<surface> 1890 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -4.825492E+01
<surface> 1891 
type right_cylinder 1.000000E+00 0.000000E+00 -4.743704E+01 -3.636042E-01
<surface> 1892 
type right_cylinder 1.000000E+00 0.000000E+00 -4.743704E+01 -2.650788E-01
<surface> 1893 
type right_cylinder 1.000000E+00 -1.635760E+00 -4.743704E+01 -3.636042E-01
<surface> 1894 
type right_cylinder 1.000000E+00 -1.635760E+00 -4.743704E+01 -2.650788E-01
<surface> 1895 
type right_cylinder 1.000000E+00 -3.271520E+00 -4.743704E+01 -3.636042E-01
<surface> 1896 
type right_cylinder 1.000000E+00 -3.271520E+00 -4.743704E+01 -2.650788E-01
<surface> 1897 
type right_cylinder 1.000000E+00 -4.907280E+00 -4.743704E+01 -3.636042E-01
<surface> 1898 
type right_cylinder 1.000000E+00 -4.907280E+00 -4.743704E+01 -2.650788E-01
<surface> 1899 
type right_cylinder 1.000000E+00 -6.543040E+00 -4.743704E+01 -3.636042E-01
<surface> 1900 
type right_cylinder 1.000000E+00 -6.543040E+00 -4.743704E+01 -2.650788E-01
<surface> 1901 
type right_cylinder 1.000000E+00 -8.178800E+00 -4.743704E+01 -3.636042E-01
<surface> 1902 
type right_cylinder 1.000000E+00 -8.178800E+00 -4.743704E+01 -2.650788E-01
<surface> 1903 
type right_cylinder 1.000000E+00 -9.814560E+00 -4.743704E+01 -3.636042E-01
<surface> 1904 
type right_cylinder 1.000000E+00 -9.814560E+00 -4.743704E+01 -2.650788E-01
<surface> 1905 
type right_cylinder 1.000000E+00 -1.145032E+01 -4.743704E+01 -3.636042E-01
<surface> 1906 
type right_cylinder 1.000000E+00 -1.145032E+01 -4.743704E+01 -2.650788E-01
<surface> 1907 
type right_cylinder 1.000000E+00 -1.308608E+01 -4.743704E+01 -3.636042E-01
<surface> 1908 
type right_cylinder 1.000000E+00 -1.308608E+01 -4.743704E+01 -2.650788E-01
<surface> 1909 
type right_cylinder 1.000000E+00 -1.472184E+01 -4.743704E+01 -3.636042E-01
<surface> 1910 
type right_cylinder 1.000000E+00 -1.472184E+01 -4.743704E+01 -2.650788E-01
<surface> 1911 
type right_cylinder 1.000000E+00 -1.635760E+01 -4.743704E+01 -3.636042E-01
<surface> 1912 
type right_cylinder 1.000000E+00 -1.635760E+01 -4.743704E+01 -2.650788E-01
<surface> 1913 
type right_cylinder 1.000000E+00 0.000000E+00 -4.907280E+01 -3.636042E-01
<surface> 1914 
type right_cylinder 1.000000E+00 0.000000E+00 -4.907280E+01 -2.650788E-01
<surface> 1915 
type right_cylinder 1.000000E+00 -1.635760E+00 -4.907280E+01 -3.636042E-01
<surface> 1916 
type right_cylinder 1.000000E+00 -1.635760E+00 -4.907280E+01 -2.650788E-01
<surface> 1917 
type right_cylinder 1.000000E+00 -3.271520E+00 -4.907280E+01 -3.636042E-01
<surface> 1918 
type right_cylinder 1.000000E+00 -3.271520E+00 -4.907280E+01 -2.650788E-01
<surface> 1919 
type right_cylinder 1.000000E+00 -4.907280E+00 -4.907280E+01 -3.636042E-01
<surface> 1920 
type right_cylinder 1.000000E+00 -4.907280E+00 -4.907280E+01 -2.650788E-01
<surface> 1921 
type right_cylinder 1.000000E+00 -6.543040E+00 -4.907280E+01 -3.636042E-01
<surface> 1922 
type right_cylinder 1.000000E+00 -6.543040E+00 -4.907280E+01 -2.650788E-01
<surface> 1923 
type right_cylinder 1.000000E+00 -8.178800E+00 -4.907280E+01 -3.636042E-01
<surface> 1924 
type right_cylinder 1.000000E+00 -8.178800E+00 -4.907280E+01 -2.650788E-01
<surface> 1925 
type right_cylinder 1.000000E+00 -9.814560E+00 -4.907280E+01 -3.636042E-01
<surface> 1926 
type right_cylinder 1.000000E+00 -9.814560E+00 -4.907280E+01 -2.650788E-01
<surface> 1927 
type right_cylinder 1.000000E+00 -1.145032E+01 -4.907280E+01 -3.636042E-01
<surface> 1928 
type right_cylinder 1.000000E+00 -1.145032E+01 -4.907280E+01 -2.650788E-01
<surface> 1929 
type right_cylinder 1.000000E+00 -1.308608E+01 -4.907280E+01 -3.636042E-01
<surface> 1930 
type right_cylinder 1.000000E+00 -1.308608E+01 -4.907280E+01 -2.650788E-01
<surface> 1931 
type right_cylinder 1.000000E+00 -1.472184E+01 -4.907280E+01 -3.636042E-01
<surface> 1932 
type right_cylinder 1.000000E+00 -1.472184E+01 -4.907280E+01 -2.650788E-01
<surface> 1933 
type right_cylinder 1.000000E+00 -1.635760E+01 -4.907280E+01 -3.636042E-01
<surface> 1934 
type right_cylinder 1.000000E+00 -1.635760E+01 -4.907280E+01 -2.650788E-01
<surface> 1935 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -5.152644E+01
<surface> 1936 
type right_cylinder 1.000000E+00 0.000000E+00 -5.070856E+01 -3.636042E-01
<surface> 1937 
type right_cylinder 1.000000E+00 0.000000E+00 -5.070856E+01 -2.650788E-01
<surface> 1938 
type right_cylinder 1.000000E+00 -1.635760E+00 -5.070856E+01 -3.636042E-01
<surface> 1939 
type right_cylinder 1.000000E+00 -1.635760E+00 -5.070856E+01 -2.650788E-01
<surface> 1940 
type right_cylinder 1.000000E+00 -3.271520E+00 -5.070856E+01 -3.636042E-01
<surface> 1941 
type right_cylinder 1.000000E+00 -3.271520E+00 -5.070856E+01 -2.650788E-01
<surface> 1942 
type right_cylinder 1.000000E+00 -4.907280E+00 -5.070856E+01 -3.636042E-01
<surface> 1943 
type right_cylinder 1.000000E+00 -4.907280E+00 -5.070856E+01 -2.650788E-01
<surface> 1944 
type right_cylinder 1.000000E+00 -6.543040E+00 -5.070856E+01 -3.636042E-01
<surface> 1945 
type right_cylinder 1.000000E+00 -6.543040E+00 -5.070856E+01 -2.650788E-01
<surface> 1946 
type right_cylinder 1.000000E+00 -8.178800E+00 -5.070856E+01 -3.636042E-01
<surface> 1947 
type right_cylinder 1.000000E+00 -8.178800E+00 -5.070856E+01 -2.650788E-01
<surface> 1948 
type right_cylinder 1.000000E+00 -9.814560E+00 -5.070856E+01 -3.636042E-01
<surface> 1949 
type right_cylinder 1.000000E+00 -9.814560E+00 -5.070856E+01 -2.650788E-01
<surface> 1950 
type right_cylinder 1.000000E+00 -1.145032E+01 -5.070856E+01 -3.636042E-01
<surface> 1951 
type right_cylinder 1.000000E+00 -1.145032E+01 -5.070856E+01 -2.650788E-01
<surface> 1952 
type right_cylinder 1.000000E+00 -1.308608E+01 -5.070856E+01 -3.636042E-01
<surface> 1953 
type right_cylinder 1.000000E+00 -1.308608E+01 -5.070856E+01 -2.650788E-01
<surface> 1954 
type right_cylinder 1.000000E+00 -1.472184E+01 -5.070856E+01 -3.636042E-01
<surface> 1955 
type right_cylinder 1.000000E+00 -1.472184E+01 -5.070856E+01 -2.650788E-01
<surface> 1956 
type right_cylinder 1.000000E+00 -1.635760E+01 -5.070856E+01 -3.636042E-01
<surface> 1957 
type right_cylinder 1.000000E+00 -1.635760E+01 -5.070856E+01 -2.650788E-01
<surface> 1958 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -5.316220E+01
<surface> 1959 
type right_cylinder 1.000000E+00 0.000000E+00 -5.234432E+01 -3.636042E-01
<surface> 1960 
type right_cylinder 1.000000E+00 0.000000E+00 -5.234432E+01 -2.650788E-01
<surface> 1961 
type right_cylinder 1.000000E+00 -1.635760E+00 -5.234432E+01 -3.636042E-01
<surface> 1962 
type right_cylinder 1.000000E+00 -1.635760E+00 -5.234432E+01 -2.650788E-01
<surface> 1963 
type right_cylinder 1.000000E+00 -3.271520E+00 -5.234432E+01 -3.636042E-01
<surface> 1964 
type right_cylinder 1.000000E+00 -3.271520E+00 -5.234432E+01 -2.650788E-01
<surface> 1965 
type right_cylinder 1.000000E+00 -4.907280E+00 -5.234432E+01 -3.636042E-01
<surface> 1966 
type right_cylinder 1.000000E+00 -4.907280E+00 -5.234432E+01 -2.650788E-01
<surface> 1967 
type right_cylinder 1.000000E+00 -6.543040E+00 -5.234432E+01 -3.636042E-01
<surface> 1968 
type right_cylinder 1.000000E+00 -6.543040E+00 -5.234432E+01 -2.650788E-01
<surface> 1969 
type right_cylinder 1.000000E+00 -8.178800E+00 -5.234432E+01 -3.636042E-01
<surface> 1970 
type right_cylinder 1.000000E+00 -8.178800E+00 -5.234432E+01 -2.650788E-01
<surface> 1971 
type right_cylinder 1.000000E+00 -9.814560E+00 -5.234432E+01 -3.636042E-01
<surface> 1972 
type right_cylinder 1.000000E+00 -9.814560E+00 -5.234432E+01 -2.650788E-01
<surface> 1973 
type right_cylinder 1.000000E+00 -1.145032E+01 -5.234432E+01 -3.636042E-01
<surface> 1974 
type right_cylinder 1.000000E+00 -1.145032E+01 -5.234432E+01 -2.650788E-01
<surface> 1975 
type right_cylinder 1.000000E+00 -1.308608E+01 -5.234432E+01 -3.636042E-01
<surface> 1976 
type right_cylinder 1.000000E+00 -1.308608E+01 -5.234432E+01 -2.650788E-01
<surface> 1977 
type right_cylinder 1.000000E+00 -1.472184E+01 -5.234432E+01 -3.636042E-01
<surface> 1978 
type right_cylinder 1.000000E+00 -1.472184E+01 -5.234432E+01 -2.650788E-01
<surface> 1979 
type right_cylinder 1.000000E+00 -1.635760E+01 -5.234432E+01 -3.636042E-01
<surface> 1980 
type right_cylinder 1.000000E+00 -1.635760E+01 -5.234432E+01 -2.650788E-01
<surface> 1981 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -5.479796E+01
<surface> 1982 
type right_cylinder 1.000000E+00 0.000000E+00 -5.398008E+01 -3.636042E-01
<surface> 1983 
type right_cylinder 1.000000E+00 0.000000E+00 -5.398008E+01 -2.650788E-01
<surface> 1984 
type right_cylinder 1.000000E+00 -1.635760E+00 -5.398008E+01 -3.636042E-01
<surface> 1985 
type right_cylinder 1.000000E+00 -1.635760E+00 -5.398008E+01 -2.650788E-01
<surface> 1986 
type right_cylinder 1.000000E+00 -3.271520E+00 -5.398008E+01 -3.636042E-01
<surface> 1987 
type right_cylinder 1.000000E+00 -3.271520E+00 -5.398008E+01 -2.650788E-01
<surface> 1988 
type right_cylinder 1.000000E+00 -4.907280E+00 -5.398008E+01 -3.636042E-01
<surface> 1989 
type right_cylinder 1.000000E+00 -4.907280E+00 -5.398008E+01 -2.650788E-01
<surface> 1990 
type right_cylinder 1.000000E+00 -6.543040E+00 -5.398008E+01 -3.636042E-01
<surface> 1991 
type right_cylinder 1.000000E+00 -6.543040E+00 -5.398008E+01 -2.650788E-01
<surface> 1992 
type right_cylinder 1.000000E+00 -8.178800E+00 -5.398008E+01 -3.636042E-01
<surface> 1993 
type right_cylinder 1.000000E+00 -8.178800E+00 -5.398008E+01 -2.650788E-01
<surface> 1994 
type right_cylinder 1.000000E+00 -9.814560E+00 -5.398008E+01 -3.636042E-01
<surface> 1995 
type right_cylinder 1.000000E+00 -9.814560E+00 -5.398008E+01 -2.650788E-01
<surface> 1996 
type right_cylinder 1.000000E+00 -1.145032E+01 -5.398008E+01 -3.636042E-01
<surface> 1997 
type right_cylinder 1.000000E+00 -1.145032E+01 -5.398008E+01 -2.650788E-01
<surface> 1998 
type right_cylinder 1.000000E+00 -1.308608E+01 -5.398008E+01 -3.636042E-01
<surface> 1999 
type right_cylinder 1.000000E+00 -1.308608E+01 -5.398008E+01 -2.650788E-01
<surface> 2000 
type right_cylinder 1.000000E+00 -1.472184E+01 -5.398008E+01 -3.636042E-01
<surface> 2001 
type right_cylinder 1.000000E+00 -1.472184E+01 -5.398008E+01 -2.650788E-01
<surface> 2002 
type right_cylinder 1.000000E+00 -1.635760E+01 -5.398008E+01 -3.636042E-01
<surface> 2003 
type right_cylinder 1.000000E+00 -1.635760E+01 -5.398008E+01 -2.650788E-01
<surface> 2004 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -5.643372E+01
<surface> 2005 
type right_cylinder 1.000000E+00 0.000000E+00 -5.561584E+01 -3.636042E-01
<surface> 2006 
type right_cylinder 1.000000E+00 0.000000E+00 -5.561584E+01 -2.650788E-01
<surface> 2007 
type right_cylinder 1.000000E+00 -1.635760E+00 -5.561584E+01 -3.636042E-01
<surface> 2008 
type right_cylinder 1.000000E+00 -1.635760E+00 -5.561584E+01 -2.650788E-01
<surface> 2009 
type right_cylinder 1.000000E+00 -3.271520E+00 -5.561584E+01 -3.636042E-01
<surface> 2010 
type right_cylinder 1.000000E+00 -3.271520E+00 -5.561584E+01 -2.650788E-01
<surface> 2011 
type right_cylinder 1.000000E+00 -4.907280E+00 -5.561584E+01 -3.636042E-01
<surface> 2012 
type right_cylinder 1.000000E+00 -4.907280E+00 -5.561584E+01 -2.650788E-01
<surface> 2013 
type right_cylinder 1.000000E+00 -6.543040E+00 -5.561584E+01 -3.636042E-01
<surface> 2014 
type right_cylinder 1.000000E+00 -6.543040E+00 -5.561584E+01 -2.650788E-01
<surface> 2015 
type right_cylinder 1.000000E+00 -8.178800E+00 -5.561584E+01 -3.636042E-01
<surface> 2016 
type right_cylinder 1.000000E+00 -8.178800E+00 -5.561584E+01 -2.650788E-01
<surface> 2017 
type right_cylinder 1.000000E+00 -9.814560E+00 -5.561584E+01 -3.636042E-01
<surface> 2018 
type right_cylinder 1.000000E+00 -9.814560E+00 -5.561584E+01 -2.650788E-01
<surface> 2019 
type right_cylinder 1.000000E+00 -1.145032E+01 -5.561584E+01 -3.636042E-01
<surface> 2020 
type right_cylinder 1.000000E+00 -1.145032E+01 -5.561584E+01 -2.650788E-01
<surface> 2021 
type right_cylinder 1.000000E+00 -1.308608E+01 -5.561584E+01 -3.636042E-01
<surface> 2022 
type right_cylinder 1.000000E+00 -1.308608E+01 -5.561584E+01 -2.650788E-01
<surface> 2023 
type right_cylinder 1.000000E+00 -1.472184E+01 -5.561584E+01 -3.636042E-01
<surface> 2024 
type right_cylinder 1.000000E+00 -1.472184E+01 -5.561584E+01 -2.650788E-01
<surface> 2025 
type right_cylinder 1.000000E+00 -1.635760E+01 -5.561584E+01 -3.636042E-01
<surface> 2026 
type right_cylinder 1.000000E+00 -1.635760E+01 -5.561584E+01 -2.650788E-01
<surface> 2027 
type right_cylinder 1.000000E+00 0.000000E+00 -5.725160E+01 -3.636042E-01
<surface> 2028 
type right_cylinder 1.000000E+00 0.000000E+00 -5.725160E+01 -2.650788E-01
<surface> 2029 
type right_cylinder 1.000000E+00 -1.635760E+00 -5.725160E+01 -3.636042E-01
<surface> 2030 
type right_cylinder 1.000000E+00 -1.635760E+00 -5.725160E+01 -2.650788E-01
<surface> 2031 
type right_cylinder 1.000000E+00 -3.271520E+00 -5.725160E+01 -3.636042E-01
<surface> 2032 
type right_cylinder 1.000000E+00 -3.271520E+00 -5.725160E+01 -2.650788E-01
<surface> 2033 
type right_cylinder 1.000000E+00 -4.907280E+00 -5.725160E+01 -3.636042E-01
<surface> 2034 
type right_cylinder 1.000000E+00 -4.907280E+00 -5.725160E+01 -2.650788E-01
<surface> 2035 
type right_cylinder 1.000000E+00 -6.543040E+00 -5.725160E+01 -3.636042E-01
<surface> 2036 
type right_cylinder 1.000000E+00 -6.543040E+00 -5.725160E+01 -2.650788E-01
<surface> 2037 
type right_cylinder 1.000000E+00 -8.178800E+00 -5.725160E+01 -3.636042E-01
<surface> 2038 
type right_cylinder 1.000000E+00 -8.178800E+00 -5.725160E+01 -2.650788E-01
<surface> 2039 
type right_cylinder 1.000000E+00 -9.814560E+00 -5.725160E+01 -3.636042E-01
<surface> 2040 
type right_cylinder 1.000000E+00 -9.814560E+00 -5.725160E+01 -2.650788E-01
<surface> 2041 
type right_cylinder 1.000000E+00 -1.145032E+01 -5.725160E+01 -3.636042E-01
<surface> 2042 
type right_cylinder 1.000000E+00 -1.145032E+01 -5.725160E+01 -2.650788E-01
<surface> 2043 
type right_cylinder 1.000000E+00 -1.308608E+01 -5.725160E+01 -3.636042E-01
<surface> 2044 
type right_cylinder 1.000000E+00 -1.308608E+01 -5.725160E+01 -2.650788E-01
<surface> 2045 
type right_cylinder 1.000000E+00 -1.472184E+01 -5.725160E+01 -3.636042E-01
<surface> 2046 
type right_cylinder 1.000000E+00 -1.472184E+01 -5.725160E+01 -2.650788E-01
<surface> 2047 
type right_cylinder 1.000000E+00 -1.635760E+01 -5.725160E+01 -3.636042E-01
<surface> 2048 
type right_cylinder 1.000000E+00 -1.635760E+01 -5.725160E+01 -2.650788E-01
<surface> 2049 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -5.970524E+01
<surface> 2050 
type right_cylinder 1.000000E+00 0.000000E+00 -5.888736E+01 -3.636042E-01
<surface> 2051 
type right_cylinder 1.000000E+00 0.000000E+00 -5.888736E+01 -2.650788E-01
<surface> 2052 
type right_cylinder 1.000000E+00 -1.635760E+00 -5.888736E+01 -3.636042E-01
<surface> 2053 
type right_cylinder 1.000000E+00 -1.635760E+00 -5.888736E+01 -2.650788E-01
<surface> 2054 
type right_cylinder 1.000000E+00 -3.271520E+00 -5.888736E+01 -3.636042E-01
<surface> 2055 
type right_cylinder 1.000000E+00 -3.271520E+00 -5.888736E+01 -2.650788E-01
<surface> 2056 
type right_cylinder 1.000000E+00 -4.907280E+00 -5.888736E+01 -3.636042E-01
<surface> 2057 
type right_cylinder 1.000000E+00 -4.907280E+00 -5.888736E+01 -2.650788E-01
<surface> 2058 
type right_cylinder 1.000000E+00 -6.543040E+00 -5.888736E+01 -3.636042E-01
<surface> 2059 
type right_cylinder 1.000000E+00 -6.543040E+00 -5.888736E+01 -2.650788E-01
<surface> 2060 
type right_cylinder 1.000000E+00 -8.178800E+00 -5.888736E+01 -3.636042E-01
<surface> 2061 
type right_cylinder 1.000000E+00 -8.178800E+00 -5.888736E+01 -2.650788E-01
<surface> 2062 
type right_cylinder 1.000000E+00 -9.814560E+00 -5.888736E+01 -3.636042E-01
<surface> 2063 
type right_cylinder 1.000000E+00 -9.814560E+00 -5.888736E+01 -2.650788E-01
<surface> 2064 
type right_cylinder 1.000000E+00 -1.145032E+01 -5.888736E+01 -3.636042E-01
<surface> 2065 
type right_cylinder 1.000000E+00 -1.145032E+01 -5.888736E+01 -2.650788E-01
<surface> 2066 
type right_cylinder 1.000000E+00 -1.308608E+01 -5.888736E+01 -3.636042E-01
<surface> 2067 
type right_cylinder 1.000000E+00 -1.308608E+01 -5.888736E+01 -2.650788E-01
<surface> 2068 
type right_cylinder 1.000000E+00 -1.472184E+01 -5.888736E+01 -3.636042E-01
<surface> 2069 
type right_cylinder 1.000000E+00 -1.472184E+01 -5.888736E+01 -2.650788E-01
<surface> 2070 
type right_cylinder 1.000000E+00 -1.635760E+01 -5.888736E+01 -3.636042E-01
<surface> 2071 
type right_cylinder 1.000000E+00 -1.635760E+01 -5.888736E+01 -2.650788E-01
<surface> 2072 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -6.134100E+01
<surface> 2073 
type right_cylinder 1.000000E+00 0.000000E+00 -6.052312E+01 -3.636042E-01
<surface> 2074 
type right_cylinder 1.000000E+00 0.000000E+00 -6.052312E+01 -2.650788E-01
<surface> 2075 
type right_cylinder 1.000000E+00 -1.635760E+00 -6.052312E+01 -3.636042E-01
<surface> 2076 
type right_cylinder 1.000000E+00 -1.635760E+00 -6.052312E+01 -2.650788E-01
<surface> 2077 
type right_cylinder 1.000000E+00 -3.271520E+00 -6.052312E+01 -3.636042E-01
<surface> 2078 
type right_cylinder 1.000000E+00 -3.271520E+00 -6.052312E+01 -2.650788E-01
<surface> 2079 
type right_cylinder 1.000000E+00 -4.907280E+00 -6.052312E+01 -3.636042E-01
<surface> 2080 
type right_cylinder 1.000000E+00 -4.907280E+00 -6.052312E+01 -2.650788E-01
<surface> 2081 
type right_cylinder 1.000000E+00 -6.543040E+00 -6.052312E+01 -3.636042E-01
<surface> 2082 
type right_cylinder 1.000000E+00 -6.543040E+00 -6.052312E+01 -2.650788E-01
<surface> 2083 
type right_cylinder 1.000000E+00 -8.178800E+00 -6.052312E+01 -3.636042E-01
<surface> 2084 
type right_cylinder 1.000000E+00 -8.178800E+00 -6.052312E+01 -2.650788E-01
<surface> 2085 
type right_cylinder 1.000000E+00 -9.814560E+00 -6.052312E+01 -3.636042E-01
<surface> 2086 
type right_cylinder 1.000000E+00 -9.814560E+00 -6.052312E+01 -2.650788E-01
<surface> 2087 
type right_cylinder 1.000000E+00 -1.145032E+01 -6.052312E+01 -3.636042E-01
<surface> 2088 
type right_cylinder 1.000000E+00 -1.145032E+01 -6.052312E+01 -2.650788E-01
<surface> 2089 
type right_cylinder 1.000000E+00 -1.308608E+01 -6.052312E+01 -3.636042E-01
<surface> 2090 
type right_cylinder 1.000000E+00 -1.308608E+01 -6.052312E+01 -2.650788E-01
<surface> 2091 
type right_cylinder 1.000000E+00 -1.472184E+01 -6.052312E+01 -3.636042E-01
<surface> 2092 
type right_cylinder 1.000000E+00 -1.472184E+01 -6.052312E+01 -2.650788E-01
<surface> 2093 
type right_cylinder 1.000000E+00 -1.635760E+01 -6.052312E+01 -3.636042E-01
<surface> 2094 
type right_cylinder 1.000000E+00 -1.635760E+01 -6.052312E+01 -2.650788E-01
<surface> 2095 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -6.297676E+01
<surface> 2096 
type right_cylinder 1.000000E+00 0.000000E+00 -6.215888E+01 -3.636042E-01
<surface> 2097 
type right_cylinder 1.000000E+00 0.000000E+00 -6.215888E+01 -2.650788E-01
<surface> 2098 
type right_cylinder 1.000000E+00 -1.635760E+00 -6.215888E+01 -3.636042E-01
<surface> 2099 
type right_cylinder 1.000000E+00 -1.635760E+00 -6.215888E+01 -2.650788E-01
<surface> 2100 
type right_cylinder 1.000000E+00 -3.271520E+00 -6.215888E+01 -3.636042E-01
<surface> 2101 
type right_cylinder 1.000000E+00 -3.271520E+00 -6.215888E+01 -2.650788E-01
<surface> 2102 
type right_cylinder 1.000000E+00 -4.907280E+00 -6.215888E+01 -3.636042E-01
<surface> 2103 
type right_cylinder 1.000000E+00 -4.907280E+00 -6.215888E+01 -2.650788E-01
<surface> 2104 
type right_cylinder 1.000000E+00 -6.543040E+00 -6.215888E+01 -3.636042E-01
<surface> 2105 
type right_cylinder 1.000000E+00 -6.543040E+00 -6.215888E+01 -2.650788E-01
<surface> 2106 
type right_cylinder 1.000000E+00 -8.178800E+00 -6.215888E+01 -3.636042E-01
<surface> 2107 
type right_cylinder 1.000000E+00 -8.178800E+00 -6.215888E+01 -2.650788E-01
<surface> 2108 
type right_cylinder 1.000000E+00 -9.814560E+00 -6.215888E+01 -3.636042E-01
<surface> 2109 
type right_cylinder 1.000000E+00 -9.814560E+00 -6.215888E+01 -2.650788E-01
<surface> 2110 
type right_cylinder 1.000000E+00 -1.145032E+01 -6.215888E+01 -3.636042E-01
<surface> 2111 
type right_cylinder 1.000000E+00 -1.145032E+01 -6.215888E+01 -2.650788E-01
<surface> 2112 
type right_cylinder 1.000000E+00 -1.308608E+01 -6.215888E+01 -3.636042E-01
<surface> 2113 
type right_cylinder 1.000000E+00 -1.308608E+01 -6.215888E+01 -2.650788E-01
<surface> 2114 
type right_cylinder 1.000000E+00 -1.472184E+01 -6.215888E+01 -3.636042E-01
<surface> 2115 
type right_cylinder 1.000000E+00 -1.472184E+01 -6.215888E+01 -2.650788E-01
<surface> 2116 
type right_cylinder 1.000000E+00 -1.635760E+01 -6.215888E+01 -3.636042E-01
<surface> 2117 
type right_cylinder 1.000000E+00 -1.635760E+01 -6.215888E+01 -2.650788E-01
<surface> 2118 
type general_plane 0.000000E+00 1.000000E+00 0.000000E+00 -6.461252E+01
<surface> 2119 
type right_cylinder 1.000000E+00 0.000000E+00 -6.379464E+01 -3.636042E-01
<surface> 2120 
type right_cylinder 1.000000E+00 0.000000E+00 -6.379464E+01 -2.650788E-01
<surface> 2121 
type right_cylinder 1.000000E+00 -1.635760E+00 -6.379464E+01 -3.636042E-01
<surface> 2122 
type right_cylinder 1.000000E+00 -1.635760E+00 -6.379464E+01 -2.650788E-01
<surface> 2123 
type right_cylinder 1.000000E+00 -3.271520E+00 -6.379464E+01 -3.636042E-01
<surface> 2124 
type right_cylinder 1.000000E+00 -3.271520E+00 -6.379464E+01 -2.650788E-01
<surface> 2125 
type right_cylinder 1.000000E+00 -4.907280E+00 -6.379464E+01 -3.636042E-01
<surface> 2126 
type right_cylinder 1.000000E+00 -4.907280E+00 -6.379464E+01 -2.650788E-01
<surface> 2127 
type right_cylinder 1.000000E+00 -6.543040E+00 -6.379464E+01 -3.636042E-01
<surface> 2128 
type right_cylinder 1.000000E+00 -6.543040E+00 -6.379464E+01 -2.650788E-01
<surface> 2129 
type right_cylinder 1.000000E+00 -8.178800E+00 -6.379464E+01 -3.636042E-01
<surface> 2130 
type right_cylinder 1.000000E+00 -8.178800E+00 -6.379464E+01 -2.650788E-01
<surface> 2131 
type right_cylinder 1.000000E+00 -9.814560E+00 -6.379464E+01 -3.636042E-01
<surface> 2132 
type right_cylinder 1.000000E+00 -9.814560E+00 -6.379464E+01 -2.650788E-01
<surface> 2133 
type right_cylinder 1.000000E+00 -1.145032E+01 -6.379464E+01 -3.636042E-01
<surface> 2134 
type right_cylinder 1.000000E+00 -1.145032E+01 -6.379464E+01 -2.650788E-01
<surface> 2135 
type right_cylinder 1.000000E+00 -1.308608E+01 -6.379464E+01 -3.636042E-01
<surface> 2136 
type right_cylinder 1.000000E+00 -1.308608E+01 -6.379464E+01 -2.650788E-01
<surface> 2137 
type right_cylinder 1.000000E+00 -1.472184E+01 -6.379464E+01 -3.636042E-01
<surface> 2138 
type right_cylinder 1.000000E+00 -1.472184E+01 -6.379464E+01 -2.650788E-01
<surface> 2139 
type right_cylinder 1.000000E+00 -1.635760E+01 -6.379464E+01 -3.636042E-01
<surface> 2140 
type right_cylinder 1.000000E+00 -1.635760E+01 -6.379464E+01 -2.650788E-01
<surface> 2141 
type right_cylinder 1.000000E+00 0.000000E+00 -6.543040E+01 -3.636042E-01
<surface> 2142 
type right_cylinder 1.000000E+00 0.000000E+00 -6.543040E+01 -2.650788E-01
<surface> 2143 
type right_cylinder 1.000000E+00 -1.635760E+00 -6.543040E+01 -3.636042E-01
<surface> 2144 
type right_cylinder 1.000000E+00 -1.635760E+00 -6.543040E+01 -2.650788E-01
<surface> 2145 
type right_cylinder 1.000000E+00 -3.271520E+00 -6.543040E+01 -3.636042E-01
<surface> 2146 
type right_cylinder 1.000000E+00 -3.271520E+00 -6.543040E+01 -2.650788E-01
<surface> 2147 
type right_cylinder 1.000000E+00 -4.907280E+00 -6.543040E+01 -3.636042E-01
<surface> 2148 
type right_cylinder 1.000000E+00 -4.907280E+00 -6.543040E+01 -2.650788E-01
<surface> 2149 
type right_cylinder 1.000000E+00 -6.543040E+00 -6.543040E+01 -3.636042E-01
<surface> 2150 
type right_cylinder 1.000000E+00 -6.543040E+00 -6.543040E+01 -2.650788E-01
<surface> 2151 
type right_cylinder 1.000000E+00 -8.178800E+00 -6.543040E+01 -3.636042E-01
<surface> 2152 
type right_cylinder 1.000000E+00 -8.178800E+00 -6.543040E+01 -2.650788E-01
<surface> 2153 
type right_cylinder 1.000000E+00 -9.814560E+00 -6.543040E+01 -3.636042E-01
<surface> 2154 
type right_cylinder 1.000000E+00 -9.814560E+00 -6.543040E+01 -2.650788E-01
<surface> 2155 
type right_cylinder 1.000000E+00 -1.145032E+01 -6.543040E+01 -3.636042E-01
<surface> 2156 
type right_cylinder 1.000000E+00 -1.145032E+01 -6.543040E+01 -2.650788E-01
<surface> 2157 
type right_cylinder 1.000000E+00 -1.308608E+01 -6.543040E+01 -3.636042E-01
<surface> 2158 
type right_cylinder 1.000000E+00 -1.308608E+01 -6.543040E+01 -2.650788E-01
<surface> 2159 
type right_cylinder 1.000000E+00 -1.472184E+01 -6.543040E+01 -3.636042E-01
<surface> 2160 
type right_cylinder 1.000000E+00 -1.472184E+01 -6.543040E+01 -2.650788E-01
<surface> 2161 
type right_cylinder 1.000000E+00 -1.635760E+01 -6.543040E+01 -3.636042E-01
<surface> 2162 
type right_cylinder 1.000000E+00 -1.635760E+01 -6.543040E+01 -2.650788E-01
<surface> 2163 
type right_cylinder 1.000000E+00 -1.799336E+01 -3.762248E+01 -3.636042E-01
<surface> 2164 
type right_cylinder 1.000000E+00 -1.799336E+01 -3.762248E+01 -2.650788E-01
<surface> 2165 
type right_cylinder 1.000000E+00 -1.962912E+01 -3.762248E+01 -3.636042E-01
<surface> 2166 
type right_cylinder 1.000000E+00 -1.962912E+01 -3.762248E+01 -2.650788E-01
<surface> 2167 
type right_cylinder 1.000000E+00 -2.126488E+01 -3.762248E+01 -3.636042E-01
<surface> 2168 
type right_cylinder 1.000000E+00 -2.126488E+01 -3.762248E+01 -2.650788E-01
<surface> 2169 
type right_cylinder 1.000000E+00 -2.290064E+01 -3.762248E+01 -3.636042E-01
<surface> 2170 
type right_cylinder 1.000000E+00 -2.290064E+01 -3.762248E+01 -2.650788E-01
<surface> 2171 
type right_cylinder 1.000000E+00 -2.453640E+01 -3.762248E+01 -3.636042E-01
<surface> 2172 
type right_cylinder 1.000000E+00 -2.453640E+01 -3.762248E+01 -2.650788E-01
<surface> 2173 
type right_cylinder 1.000000E+00 -2.617216E+01 -3.762248E+01 -3.636042E-01
<surface> 2174 
type right_cylinder 1.000000E+00 -2.617216E+01 -3.762248E+01 -2.650788E-01
<surface> 2175 
type right_cylinder 1.000000E+00 -2.780792E+01 -3.762248E+01 -3.636042E-01
<surface> 2176 
type right_cylinder 1.000000E+00 -2.780792E+01 -3.762248E+01 -2.650788E-01
<surface> 2177 
type right_cylinder 1.000000E+00 -2.944368E+01 -3.762248E+01 -3.636042E-01
<surface> 2178 
type right_cylinder 1.000000E+00 -2.944368E+01 -3.762248E+01 -2.650788E-01
<surface> 2179 
type right_cylinder 1.000000E+00 -3.107944E+01 -3.762248E+01 -3.636042E-01
<surface> 2180 
type right_cylinder 1.000000E+00 -3.107944E+01 -3.762248E+01 -2.650788E-01
<surface> 2181 
type right_cylinder 1.000000E+00 -3.271520E+01 -3.762248E+01 -3.636042E-01
<surface> 2182 
type right_cylinder 1.000000E+00 -3.271520E+01 -3.762248E+01 -2.650788E-01
<surface> 2183 
type right_cylinder 1.000000E+00 -1.799336E+01 -3.925824E+01 -3.636042E-01
<surface> 2184 
type right_cylinder 1.000000E+00 -1.799336E+01 -3.925824E+01 -2.650788E-01
<surface> 2185 
type right_cylinder 1.000000E+00 -1.962912E+01 -3.925824E+01 -3.636042E-01
<surface> 2186 
type right_cylinder 1.000000E+00 -1.962912E+01 -3.925824E+01 -2.650788E-01
<surface> 2187 
type right_cylinder 1.000000E+00 -2.126488E+01 -3.925824E+01 -3.636042E-01
<surface> 2188 
type right_cylinder 1.000000E+00 -2.126488E+01 -3.925824E+01 -2.650788E-01
<surface> 2189 
type right_cylinder 1.000000E+00 -2.290064E+01 -3.925824E+01 -3.636042E-01
<surface> 2190 
type right_cylinder 1.000000E+00 -2.290064E+01 -3.925824E+01 -2.650788E-01
<surface> 2191 
type right_cylinder 1.000000E+00 -2.453640E+01 -3.925824E+01 -3.636042E-01
<surface> 2192 
type right_cylinder 1.000000E+00 -2.453640E+01 -3.925824E+01 -2.650788E-01
<surface> 2193 
type right_cylinder 1.000000E+00 -2.617216E+01 -3.925824E+01 -3.636042E-01
<surface> 2194 
type right_cylinder 1.000000E+00 -2.617216E+01 -3.925824E+01 -2.650788E-01
<surface> 2195 
type right_cylinder 1.000000E+00 -2.780792E+01 -3.925824E+01 -3.636042E-01
<surface> 2196 
type right_cylinder 1.000000E+00 -2.780792E+01 -3.925824E+01 -2.650788E-01
<surface> 2197 
type right_cylinder 1.000000E+00 -2.944368E+01 -3.925824E+01 -3.636042E-01
<surface> 2198 
type right_cylinder 1.000000E+00 -2.944368E+01 -3.925824E+01 -2.650788E-01
<surface> 2199 
type right_cylinder 1.000000E+00 -3.107944E+01 -3.925824E+01 -3.636042E-01
<surface> 2200 
type right_cylinder 1.000000E+00 -3.107944E+01 -3.925824E+01 -2.650788E-01
<surface> 2201 
type right_cylinder 1.000000E+00 -3.271520E+01 -3.925824E+01 -3.636042E-01
<surface> 2202 
type right_cylinder 1.000000E+00 -3.271520E+01 -3.925824E+01 -2.650788E-01
<surface> 2203 
type right_cylinder 1.000000E+00 -1.799336E+01 -4.089400E+01 -3.636042E-01
<surface> 2204 
type right_cylinder 1.000000E+00 -1.799336E+01 -4.089400E+01 -2.650788E-01
<surface> 2205 
type right_cylinder 1.000000E+00 -1.962912E+01 -4.089400E+01 -3.636042E-01
<surface> 2206 
type right_cylinder 1.000000E+00 -1.962912E+01 -4.089400E+01 -2.650788E-01
<surface> 2207 
type right_cylinder 1.000000E+00 -2.126488E+01 -4.089400E+01 -3.636042E-01
<surface> 2208 
type right_cylinder 1.000000E+00 -2.126488E+01 -4.089400E+01 -2.650788E-01
<surface> 2209 
type right_cylinder 1.000000E+00 -2.290064E+01 -4.089400E+01 -3.636042E-01
<surface> 2210 
type right_cylinder 1.000000E+00 -2.290064E+01 -4.089400E+01 -2.650788E-01
<surface> 2211 
type right_cylinder 1.000000E+00 -2.453640E+01 -4.089400E+01 -3.636042E-01
<surface> 2212 
type right_cylinder 1.000000E+00 -2.453640E+01 -4.089400E+01 -2.650788E-01
<surface> 2213 
type right_cylinder 1.000000E+00 -2.617216E+01 -4.089400E+01 -3.636042E-01
<surface> 2214 
type right_cylinder 1.000000E+00 -2.617216E+01 -4.089400E+01 -2.650788E-01
<surface> 2215 
type right_cylinder 1.000000E+00 -2.780792E+01 -4.089400E+01 -3.636042E-01
<surface> 2216 
type right_cylinder 1.000000E+00 -2.780792E+01 -4.089400E+01 -2.650788E-01
<surface> 2217 
type right_cylinder 1.000000E+00 -2.944368E+01 -4.089400E+01 -3.636042E-01
<surface> 2218 
type right_cylinder 1.000000E+00 -2.944368E+01 -4.089400E+01 -2.650788E-01
<surface> 2219 
type right_cylinder 1.000000E+00 -3.107944E+01 -4.089400E+01 -3.636042E-01
<surface> 2220 
type right_cylinder 1.000000E+00 -3.107944E+01 -4.089400E+01 -2.650788E-01
<surface> 2221 
type right_cylinder 1.000000E+00 -3.271520E+01 -4.089400E+01 -3.636042E-01
<surface> 2222 
type right_cylinder 1.000000E+00 -3.271520E+01 -4.089400E+01 -2.650788E-01
<surface> 2223 
type right_cylinder 1.000000E+00 -1.799336E+01 -4.252976E+01 -3.636042E-01
<surface> 2224 
type right_cylinder 1.000000E+00 -1.799336E+01 -4.252976E+01 -2.650788E-01
<surface> 2225 
type right_cylinder 1.000000E+00 -1.962912E+01 -4.252976E+01 -3.636042E-01
<surface> 2226 
type right_cylinder 1.000000E+00 -1.962912E+01 -4.252976E+01 -2.650788E-01
<surface> 2227 
type right_cylinder 1.000000E+00 -2.126488E+01 -4.252976E+01 -3.636042E-01
<surface> 2228 
type right_cylinder 1.000000E+00 -2.126488E+01 -4.252976E+01 -2.650788E-01
<surface> 2229 
type right_cylinder 1.000000E+00 -2.290064E+01 -4.252976E+01 -3.636042E-01
<surface> 2230 
type right_cylinder 1.000000E+00 -2.290064E+01 -4.252976E+01 -2.650788E-01
<surface> 2231 
type right_cylinder 1.000000E+00 -2.453640E+01 -4.252976E+01 -3.636042E-01
<surface> 2232 
type right_cylinder 1.000000E+00 -2.453640E+01 -4.252976E+01 -2.650788E-01
<surface> 2233 
type right_cylinder 1.000000E+00 -2.617216E+01 -4.252976E+01 -3.636042E-01
<surface> 2234 
type right_cylinder 1.000000E+00 -2.617216E+01 -4.252976E+01 -2.650788E-01
<surface> 2235 
type right_cylinder 1.000000E+00 -2.780792E+01 -4.252976E+01 -3.636042E-01
<surface> 2236 
type right_cylinder 1.000000E+00 -2.780792E+01 -4.252976E+01 -2.650788E-01
<surface> 2237 
type right_cylinder 1.000000E+00 -2.944368E+01 -4.252976E+01 -3.636042E-01
<surface> 2238 
type right_cylinder 1.000000E+00 -2.944368E+01 -4.252976E+01 -2.650788E-01
<surface> 2239 
type right_cylinder 1.000000E+00 -3.107944E+01 -4.252976E+01 -3.636042E-01
<surface> 2240 
type right_cylinder 1.000000E+00 -3.107944E+01 -4.252976E+01 -2.650788E-01
<surface> 2241 
type right_cylinder 1.000000E+00 -3.271520E+01 -4.252976E+01 -3.636042E-01
<surface> 2242 
type right_cylinder 1.000000E+00 -3.271520E+01 -4.252976E+01 -2.650788E-01
<surface> 2243 
type right_cylinder 1.000000E+00 -1.799336E+01 -4.416552E+01 -3.636042E-01
<surface> 2244 
type right_cylinder 1.000000E+00 -1.799336E+01 -4.416552E+01 -2.650788E-01
<surface> 2245 
type right_cylinder 1.000000E+00 -1.962912E+01 -4.416552E+01 -3.636042E-01
<surface> 2246 
type right_cylinder 1.000000E+00 -1.962912E+01 -4.416552E+01 -2.650788E-01
<surface> 2247 
type right_cylinder 1.000000E+00 -2.126488E+01 -4.416552E+01 -3.636042E-01
<surface> 2248 
type right_cylinder 1.000000E+00 -2.126488E+01 -4.416552E+01 -2.650788E-01
<surface> 2249 
type right_cylinder 1.000000E+00 -2.290064E+01 -4.416552E+01 -3.636042E-01
<surface> 2250 
type right_cylinder 1.000000E+00 -2.290064E+01 -4.416552E+01 -2.650788E-01
<surface> 2251 
type right_cylinder 1.000000E+00 -2.453640E+01 -4.416552E+01 -3.636042E-01
<surface> 2252 
type right_cylinder 1.000000E+00 -2.453640E+01 -4.416552E+01 -2.650788E-01
<surface> 2253 
type right_cylinder 1.000000E+00 -2.617216E+01 -4.416552E+01 -3.636042E-01
<surface> 2254 
type right_cylinder 1.000000E+00 -2.617216E+01 -4.416552E+01 -2.650788E-01
<surface> 2255 
type right_cylinder 1.000000E+00 -2.780792E+01 -4.416552E+01 -3.636042E-01
<surface> 2256 
type right_cylinder 1.000000E+00 -2.780792E+01 -4.416552E+01 -2.650788E-01
<surface> 2257 
type right_cylinder 1.000000E+00 -2.944368E+01 -4.416552E+01 -3.636042E-01
<surface> 2258 
type right_cylinder 1.000000E+00 -2.944368E+01 -4.416552E+01 -2.650788E-01
<surface> 2259 
type right_cylinder 1.000000E+00 -3.107944E+01 -4.416552E+01 -3.636042E-01
<surface> 2260 
type right_cylinder 1.000000E+00 -3.107944E+01 -4.416552E+01 -2.650788E-01
<surface> 2261 
type right_cylinder 1.000000E+00 -3.271520E+01 -4.416552E+01 -3.636042E-01
<surface> 2262 
type right_cylinder 1.000000E+00 -3.271520E+01 -4.416552E+01 -2.650788E-01
<surface> 2263 
type right_cylinder 1.000000E+00 -1.799336E+01 -4.580128E+01 -3.636042E-01
<surface> 2264 
type right_cylinder 1.000000E+00 -1.799336E+01 -4.580128E+01 -2.650788E-01
<surface> 2265 
type right_cylinder 1.000000E+00 -1.962912E+01 -4.580128E+01 -3.636042E-01
<surface> 2266 
type right_cylinder 1.000000E+00 -1.962912E+01 -4.580128E+01 -2.650788E-01
<surface> 2267 
type right_cylinder 1.000000E+00 -2.126488E+01 -4.580128E+01 -3.636042E-01
<surface> 2268 
type right_cylinder 1.000000E+00 -2.126488E+01 -4.580128E+01 -2.650788E-01
<surface> 2269 
type right_cylinder 1.000000E+00 -2.290064E+01 -4.580128E+01 -3.636042E-01
<surface> 2270 
type right_cylinder 1.000000E+00 -2.290064E+01 -4.580128E+01 -2.650788E-01
<surface> 2271 
type right_cylinder 1.000000E+00 -2.453640E+01 -4.580128E+01 -3.636042E-01
<surface> 2272 
type right_cylinder 1.000000E+00 -2.453640E+01 -4.580128E+01 -2.650788E-01
<surface> 2273 
type right_cylinder 1.000000E+00 -2.617216E+01 -4.580128E+01 -3.636042E-01
<surface> 2274 
type right_cylinder 1.000000E+00 -2.617216E+01 -4.580128E+01 -2.650788E-01
<surface> 2275 
type right_cylinder 1.000000E+00 -2.780792E+01 -4.580128E+01 -3.636042E-01
<surface> 2276 
type right_cylinder 1.000000E+00 -2.780792E+01 -4.580128E+01 -2.650788E-01
<surface> 2277 
type right_cylinder 1.000000E+00 -2.944368E+01 -4.580128E+01 -3.636042E-01
<surface> 2278 
type right_cylinder 1.000000E+00 -2.944368E+01 -4.580128E+01 -2.650788E-01
<surface> 2279 
type right_cylinder 1.000000E+00 -3.107944E+01 -4.580128E+01 -3.636042E-01
<surface> 2280 
type right_cylinder 1.000000E+00 -3.107944E+01 -4.580128E+01 -2.650788E-01
<surface> 2281 
type right_cylinder 1.000000E+00 -3.271520E+01 -4.580128E+01 -3.636042E-01
<surface> 2282 
type right_cylinder 1.000000E+00 -3.271520E+01 -4.580128E+01 -2.650788E-01
<surface> 2283 
type right_cylinder 1.000000E+00 -1.799336E+01 -4.743704E+01 -3.636042E-01
<surface> 2284 
type right_cylinder 1.000000E+00 -1.799336E+01 -4.743704E+01 -2.650788E-01
<surface> 2285 
type right_cylinder 1.000000E+00 -1.962912E+01 -4.743704E+01 -3.636042E-01
<surface> 2286 
type right_cylinder 1.000000E+00 -1.962912E+01 -4.743704E+01 -2.650788E-01
<surface> 2287 
type right_cylinder 1.000000E+00 -2.126488E+01 -4.743704E+01 -3.636042E-01
<surface> 2288 
type right_cylinder 1.000000E+00 -2.126488E+01 -4.743704E+01 -2.650788E-01
<surface> 2289 
type right_cylinder 1.000000E+00 -2.290064E+01 -4.743704E+01 -3.636042E-01
<surface> 2290 
type right_cylinder 1.000000E+00 -2.290064E+01 -4.743704E+01 -2.650788E-01
<surface> 2291 
type right_cylinder 1.000000E+00 -2.453640E+01 -4.743704E+01 -3.636042E-01
<surface> 2292 
type right_cylinder 1.000000E+00 -2.453640E+01 -4.743704E+01 -2.650788E-01
<surface> 2293 
type right_cylinder 1.000000E+00 -2.617216E+01 -4.743704E+01 -3.636042E-01
<surface> 2294 
type right_cylinder 1.000000E+00 -2.617216E+01 -4.743704E+01 -2.650788E-01
<surface> 2295 
type right_cylinder 1.000000E+00 -2.780792E+01 -4.743704E+01 -3.636042E-01
<surface> 2296 
type right_cylinder 1.000000E+00 -2.780792E+01 -4.743704E+01 -2.650788E-01
<surface> 2297 
type right_cylinder 1.000000E+00 -2.944368E+01 -4.743704E+01 -3.636042E-01
<surface> 2298 
type right_cylinder 1.000000E+00 -2.944368E+01 -4.743704E+01 -2.650788E-01
<surface> 2299 
type right_cylinder 1.000000E+00 -3.107944E+01 -4.743704E+01 -3.636042E-01
<surface> 2300 
type right_cylinder 1.000000E+00 -3.107944E+01 -4.743704E+01 -2.650788E-01
<surface> 2301 
type right_cylinder 1.000000E+00 -3.271520E+01 -4.743704E+01 -3.636042E-01
<surface> 2302 
type right_cylinder 1.000000E+00 -3.271520E+01 -4.743704E+01 -2.650788E-01
<surface> 2303 
type right_cylinder 1.000000E+00 -1.799336E+01 -4.907280E+01 -3.636042E-01
<surface> 2304 
type right_cylinder 1.000000E+00 -1.799336E+01 -4.907280E+01 -2.650788E-01
<surface> 2305 
type right_cylinder 1.000000E+00 -1.962912E+01 -4.907280E+01 -3.636042E-01
<surface> 2306 
type right_cylinder 1.000000E+00 -1.962912E+01 -4.907280E+01 -2.650788E-01
<surface> 2307 
type right_cylinder 1.000000E+00 -2.126488E+01 -4.907280E+01 -3.636042E-01
<surface> 2308 
type right_cylinder 1.000000E+00 -2.126488E+01 -4.907280E+01 -2.650788E-01
<surface> 2309 
type right_cylinder 1.000000E+00 -2.290064E+01 -4.907280E+01 -3.636042E-01
<surface> 2310 
type right_cylinder 1.000000E+00 -2.290064E+01 -4.907280E+01 -2.650788E-01
<surface> 2311 
type right_cylinder 1.000000E+00 -2.453640E+01 -4.907280E+01 -3.636042E-01
<surface> 2312 
type right_cylinder 1.000000E+00 -2.453640E+01 -4.907280E+01 -2.650788E-01
<surface> 2313 
type right_cylinder 1.000000E+00 -2.617216E+01 -4.907280E+01 -3.636042E-01
<surface> 2314 
type right_cylinder 1.000000E+00 -2.617216E+01 -4.907280E+01 -2.650788E-01
<surface> 2315 
type right_cylinder 1.000000E+00 -2.780792E+01 -4.907280E+01 -3.636042E-01
<surface> 2316 
type right_cylinder 1.000000E+00 -2.780792E+01 -4.907280E+01 -2.650788E-01
<surface> 2317 
type right_cylinder 1.000000E+00 -2.944368E+01 -4.907280E+01 -3.636042E-01
<surface> 2318 
type right_cylinder 1.000000E+00 -2.944368E+01 -4.907280E+01 -2.650788E-01
<surface> 2319 
type right_cylinder 1.000000E+00 -3.107944E+01 -4.907280E+01 -3.636042E-01
<surface> 2320 
type right_cylinder 1.000000E+00 -3.107944E+01 -4.907280E+01 -2.650788E-01
<surface> 2321 
type right_cylinder 1.000000E+00 -3.271520E+01 -4.907280E+01 -3.636042E-01
<surface> 2322 
type right_cylinder 1.000000E+00 -3.271520E+01 -4.907280E+01 -2.650788E-01
<surface> 2323 
type right_cylinder 1.000000E+00 -1.799336E+01 -5.070856E+01 -3.636042E-01
<surface> 2324 
type right_cylinder 1.000000E+00 -1.799336E+01 -5.070856E+01 -2.650788E-01
<surface> 2325 
type right_cylinder 1.000000E+00 -1.962912E+01 -5.070856E+01 -3.636042E-01
<surface> 2326 
type right_cylinder 1.000000E+00 -1.962912E+01 -5.070856E+01 -2.650788E-01
<surface> 2327 
type right_cylinder 1.000000E+00 -2.126488E+01 -5.070856E+01 -3.636042E-01
<surface> 2328 
type right_cylinder 1.000000E+00 -2.126488E+01 -5.070856E+01 -2.650788E-01
<surface> 2329 
type right_cylinder 1.000000E+00 -2.290064E+01 -5.070856E+01 -3.636042E-01
<surface> 2330 
type right_cylinder 1.000000E+00 -2.290064E+01 -5.070856E+01 -2.650788E-01
<surface> 2331 
type right_cylinder 1.000000E+00 -2.453640E+01 -5.070856E+01 -3.636042E-01
<surface> 2332 
type right_cylinder 1.000000E+00 -2.453640E+01 -5.070856E+01 -2.650788E-01
<surface> 2333 
type right_cylinder 1.000000E+00 -2.617216E+01 -5.070856E+01 -3.636042E-01
<surface> 2334 
type right_cylinder 1.000000E+00 -2.617216E+01 -5.070856E+01 -2.650788E-01
<surface> 2335 
type right_cylinder 1.000000E+00 -2.780792E+01 -5.070856E+01 -3.636042E-01
<surface> 2336 
type right_cylinder 1.000000E+00 -2.780792E+01 -5.070856E+01 -2.650788E-01
<surface> 2337 
type right_cylinder 1.000000E+00 -2.944368E+01 -5.070856E+01 -3.636042E-01
<surface> 2338 
type right_cylinder 1.000000E+00 -2.944368E+01 -5.070856E+01 -2.650788E-01
<surface> 2339 
type right_cylinder 1.000000E+00 -3.107944E+01 -5.070856E+01 -3.636042E-01
<surface> 2340 
type right_cylinder 1.000000E+00 -3.107944E+01 -5.070856E+01 -2.650788E-01
<surface> 2341 
type right_cylinder 1.000000E+00 -3.271520E+01 -5.070856E+01 -3.636042E-01
<surface> 2342 
type right_cylinder 1.000000E+00 -3.271520E+01 -5.070856E+01 -2.650788E-01
<surface> 2343 
type right_cylinder 1.000000E+00 -1.799336E+01 -5.234432E+01 -3.636042E-01
<surface> 2344 
type right_cylinder 1.000000E+00 -1.799336E+01 -5.234432E+01 -2.650788E-01
<surface> 2345 
type right_cylinder 1.000000E+00 -1.962912E+01 -5.234432E+01 -3.636042E-01
<surface> 2346 
type right_cylinder 1.000000E+00 -1.962912E+01 -5.234432E+01 -2.650788E-01
<surface> 2347 
type right_cylinder 1.000000E+00 -2.126488E+01 -5.234432E+01 -3.636042E-01
<surface> 2348 
type right_cylinder 1.000000E+00 -2.126488E+01 -5.234432E+01 -2.650788E-01
<surface> 2349 
type right_cylinder 1.000000E+00 -2.290064E+01 -5.234432E+01 -3.636042E-01
<surface> 2350 
type right_cylinder 1.000000E+00 -2.290064E+01 -5.234432E+01 -2.650788E-01
<surface> 2351 
type right_cylinder 1.000000E+00 -2.453640E+01 -5.234432E+01 -3.636042E-01
<surface> 2352 
type right_cylinder 1.000000E+00 -2.453640E+01 -5.234432E+01 -2.650788E-01
<surface> 2353 
type right_cylinder 1.000000E+00 -2.617216E+01 -5.234432E+01 -3.636042E-01
<surface> 2354 
type right_cylinder 1.000000E+00 -2.617216E+01 -5.234432E+01 -2.650788E-01
<surface> 2355 
type right_cylinder 1.000000E+00 -2.780792E+01 -5.234432E+01 -3.636042E-01
<surface> 2356 
type right_cylinder 1.000000E+00 -2.780792E+01 -5.234432E+01 -2.650788E-01
<surface> 2357 
type right_cylinder 1.000000E+00 -2.944368E+01 -5.234432E+01 -3.636042E-01
<surface> 2358 
type right_cylinder 1.000000E+00 -2.944368E+01 -5.234432E+01 -2.650788E-01
<surface> 2359 
type right_cylinder 1.000000E+00 -3.107944E+01 -5.234432E+01 -3.636042E-01
<surface> 2360 
type right_cylinder 1.000000E+00 -3.107944E+01 -5.234432E+01 -2.650788E-01
<surface> 2361 
type right_cylinder 1.000000E+00 -3.271520E+01 -5.234432E+01 -3.636042E-01
<surface> 2362 
type right_cylinder 1.000000E+00 -3.271520E+01 -5.234432E+01 -2.650788E-01
<surface> 2363 
type right_cylinder 1.000000E+00 -1.799336E+01 -5.398008E+01 -3.636042E-01
<surface> 2364 
type right_cylinder 1.000000E+00 -1.799336E+01 -5.398008E+01 -2.650788E-01
<surface> 2365 
type right_cylinder 1.000000E+00 -1.962912E+01 -5.398008E+01 -3.636042E-01
<surface> 2366 
type right_cylinder 1.000000E+00 -1.962912E+01 -5.398008E+01 -2.650788E-01
<surface> 2367 
type right_cylinder 1.000000E+00 -2.126488E+01 -5.398008E+01 -3.636042E-01
<surface> 2368 
type right_cylinder 1.000000E+00 -2.126488E+01 -5.398008E+01 -2.650788E-01
<surface> 2369 
type right_cylinder 1.000000E+00 -2.290064E+01 -5.398008E+01 -3.636042E-01
<surface> 2370 
type right_cylinder 1.000000E+00 -2.290064E+01 -5.398008E+01 -2.650788E-01
<surface> 2371 
type right_cylinder 1.000000E+00 -2.453640E+01 -5.398008E+01 -3.636042E-01
<surface> 2372 
type right_cylinder 1.000000E+00 -2.453640E+01 -5.398008E+01 -2.650788E-01
<surface> 2373 
type right_cylinder 1.000000E+00 -2.617216E+01 -5.398008E+01 -3.636042E-01
<surface> 2374 
type right_cylinder 1.000000E+00 -2.617216E+01 -5.398008E+01 -2.650788E-01
<surface> 2375 
type right_cylinder 1.000000E+00 -2.780792E+01 -5.398008E+01 -3.636042E-01
<surface> 2376 
type right_cylinder 1.000000E+00 -2.780792E+01 -5.398008E+01 -2.650788E-01
<surface> 2377 
type right_cylinder 1.000000E+00 -2.944368E+01 -5.398008E+01 -3.636042E-01
<surface> 2378 
type right_cylinder 1.000000E+00 -2.944368E+01 -5.398008E+01 -2.650788E-01
<surface> 2379 
type right_cylinder 1.000000E+00 -3.107944E+01 -5.398008E+01 -3.636042E-01
<surface> 2380 
type right_cylinder 1.000000E+00 -3.107944E+01 -5.398008E+01 -2.650788E-01
<surface> 2381 
type right_cylinder 1.000000E+00 -3.271520E+01 -5.398008E+01 -3.636042E-01
<surface> 2382 
type right_cylinder 1.000000E+00 -3.271520E+01 -5.398008E+01 -2.650788E-01
<surface> 2383 
type right_cylinder 1.000000E+00 -1.799336E+01 -5.561584E+01 -3.636042E-01
<surface> 2384 
type right_cylinder 1.000000E+00 -1.799336E+01 -5.561584E+01 -2.650788E-01
<surface> 2385 
type right_cylinder 1.000000E+00 -1.962912E+01 -5.561584E+01 -3.636042E-01
<surface> 2386 
type right_cylinder 1.000000E+00 -1.962912E+01 -5.561584E+01 -2.650788E-01
<surface> 2387 
type right_cylinder 1.000000E+00 -2.126488E+01 -5.561584E+01 -3.636042E-01
<surface> 2388 
type right_cylinder 1.000000E+00 -2.126488E+01 -5.561584E+01 -2.650788E-01
<surface> 2389 
type right_cylinder 1.000000E+00 -2.290064E+01 -5.561584E+01 -3.636042E-01
<surface> 2390 
type right_cylinder 1.000000E+00 -2.290064E+01 -5.561584E+01 -2.650788E-01
<surface> 2391 
type right_cylinder 1.000000E+00 -2.453640E+01 -5.561584E+01 -3.636042E-01
<surface> 2392 
type right_cylinder 1.000000E+00 -2.453640E+01 -5.561584E+01 -2.650788E-01
<surface> 2393 
type right_cylinder 1.000000E+00 -2.617216E+01 -5.561584E+01 -3.636042E-01
<surface> 2394 
type right_cylinder 1.000000E+00 -2.617216E+01 -5.561584E+01 -2.650788E-01
<surface> 2395 
type right_cylinder 1.000000E+00 -2.780792E+01 -5.561584E+01 -3.636042E-01
<surface> 2396 
type right_cylinder 1.000000E+00 -2.780792E+01 -5.561584E+01 -2.650788E-01
<surface> 2397 
type right_cylinder 1.000000E+00 -2.944368E+01 -5.561584E+01 -3.636042E-01
<surface> 2398 
type right_cylinder 1.000000E+00 -2.944368E+01 -5.561584E+01 -2.650788E-01
<surface> 2399 
type right_cylinder 1.000000E+00 -3.107944E+01 -5.561584E+01 -3.636042E-01
<surface> 2400 
type right_cylinder 1.000000E+00 -3.107944E+01 -5.561584E+01 -2.650788E-01
<surface> 2401 
type right_cylinder 1.000000E+00 -3.271520E+01 -5.561584E+01 -3.636042E-01
<surface> 2402 
type right_cylinder 1.000000E+00 -3.271520E+01 -5.561584E+01 -2.650788E-01
<surface> 2403 
type right_cylinder 1.000000E+00 -1.799336E+01 -5.725160E+01 -3.636042E-01
<surface> 2404 
type right_cylinder 1.000000E+00 -1.799336E+01 -5.725160E+01 -2.650788E-01
<surface> 2405 
type right_cylinder 1.000000E+00 -1.962912E+01 -5.725160E+01 -3.636042E-01
<surface> 2406 
type right_cylinder 1.000000E+00 -1.962912E+01 -5.725160E+01 -2.650788E-01
<surface> 2407 
type right_cylinder 1.000000E+00 -2.126488E+01 -5.725160E+01 -3.636042E-01
<surface> 2408 
type right_cylinder 1.000000E+00 -2.126488E+01 -5.725160E+01 -2.650788E-01
<surface> 2409 
type right_cylinder 1.000000E+00 -2.290064E+01 -5.725160E+01 -3.636042E-01
<surface> 2410 
type right_cylinder 1.000000E+00 -2.290064E+01 -5.725160E+01 -2.650788E-01
<surface> 2411 
type right_cylinder 1.000000E+00 -2.453640E+01 -5.725160E+01 -3.636042E-01
<surface> 2412 
type right_cylinder 1.000000E+00 -2.453640E+01 -5.725160E+01 -2.650788E-01
<surface> 2413 
type right_cylinder 1.000000E+00 -2.617216E+01 -5.725160E+01 -3.636042E-01
<surface> 2414 
type right_cylinder 1.000000E+00 -2.617216E+01 -5.725160E+01 -2.650788E-01
<surface> 2415 
type right_cylinder 1.000000E+00 -2.780792E+01 -5.725160E+01 -3.636042E-01
<surface> 2416 
type right_cylinder 1.000000E+00 -2.780792E+01 -5.725160E+01 -2.650788E-01
<surface> 2417 
type right_cylinder 1.000000E+00 -2.944368E+01 -5.725160E+01 -3.636042E-01
<surface> 2418 
type right_cylinder 1.000000E+00 -2.944368E+01 -5.725160E+01 -2.650788E-01
<surface> 2419 
type right_cylinder 1.000000E+00 -3.107944E+01 -5.725160E+01 -3.636042E-01
<surface> 2420 
type right_cylinder 1.000000E+00 -3.107944E+01 -5.725160E+01 -2.650788E-01
<surface> 2421 
type right_cylinder 1.000000E+00 -3.271520E+01 -5.725160E+01 -3.636042E-01
<surface> 2422 
type right_cylinder 1.000000E+00 -3.271520E+01 -5.725160E+01 -2.650788E-01
<surface> 2423 
type right_cylinder 1.000000E+00 -3.435096E+01 -3.762248E+01 -3.636042E-01
<surface> 2424 
type right_cylinder 1.000000E+00 -3.435096E+01 -3.762248E+01 -2.650788E-01
<surface> 2425 
type right_cylinder 1.000000E+00 -3.598672E+01 -3.762248E+01 -3.636042E-01
<surface> 2426 
type right_cylinder 1.000000E+00 -3.598672E+01 -3.762248E+01 -2.650788E-01
<surface> 2427 
type right_cylinder 1.000000E+00 -3.762248E+01 -3.762248E+01 -3.636042E-01
<surface> 2428 
type right_cylinder 1.000000E+00 -3.762248E+01 -3.762248E+01 -2.650788E-01
<surface> 2429 
type right_cylinder 1.000000E+00 -3.925824E+01 -3.762248E+01 -3.636042E-01
<surface> 2430 
type right_cylinder 1.000000E+00 -3.925824E+01 -3.762248E+01 -2.650788E-01
<surface> 2431 
type right_cylinder 1.000000E+00 -4.089400E+01 -3.762248E+01 -3.636042E-01
<surface> 2432 
type right_cylinder 1.000000E+00 -4.089400E+01 -3.762248E+01 -2.650788E-01
<surface> 2433 
type right_cylinder 1.000000E+00 -4.252976E+01 -3.762248E+01 -3.636042E-01
<surface> 2434 
type right_cylinder 1.000000E+00 -4.252976E+01 -3.762248E+01 -2.650788E-01
<surface> 2435 
type right_cylinder 1.000000E+00 -4.416552E+01 -3.762248E+01 -3.636042E-01
<surface> 2436 
type right_cylinder 1.000000E+00 -4.416552E+01 -3.762248E+01 -2.650788E-01
<surface> 2437 
type right_cylinder 1.000000E+00 -4.580128E+01 -3.762248E+01 -3.636042E-01
<surface> 2438 
type right_cylinder 1.000000E+00 -4.580128E+01 -3.762248E+01 -2.650788E-01
<surface> 2439 
type right_cylinder 1.000000E+00 -4.743704E+01 -3.762248E+01 -3.636042E-01
<surface> 2440 
type right_cylinder 1.000000E+00 -4.743704E+01 -3.762248E+01 -2.650788E-01
<surface> 2441 
type right_cylinder 1.000000E+00 -4.907280E+01 -3.762248E+01 -3.636042E-01
<surface> 2442 
type right_cylinder 1.000000E+00 -4.907280E+01 -3.762248E+01 -2.650788E-01
<surface> 2443 
type right_cylinder 1.000000E+00 -3.435096E+01 -3.925824E+01 -3.636042E-01
<surface> 2444 
type right_cylinder 1.000000E+00 -3.435096E+01 -3.925824E+01 -2.650788E-01
<surface> 2445 
type right_cylinder 1.000000E+00 -3.598672E+01 -3.925824E+01 -3.636042E-01
<surface> 2446 
type right_cylinder 1.000000E+00 -3.598672E+01 -3.925824E+01 -2.650788E-01
<surface> 2447 
type right_cylinder 1.000000E+00 -3.762248E+01 -3.925824E+01 -3.636042E-01
<surface> 2448 
type right_cylinder 1.000000E+00 -3.762248E+01 -3.925824E+01 -2.650788E-01
<surface> 2449 
type right_cylinder 1.000000E+00 -3.925824E+01 -3.925824E+01 -3.636042E-01
<surface> 2450 
type right_cylinder 1.000000E+00 -3.925824E+01 -3.925824E+01 -2.650788E-01
<surface> 2451 
type right_cylinder 1.000000E+00 -4.089400E+01 -3.925824E+01 -3.636042E-01
<surface> 2452 
type right_cylinder 1.000000E+00 -4.089400E+01 -3.925824E+01 -2.650788E-01
<surface> 2453 
type right_cylinder 1.000000E+00 -4.252976E+01 -3.925824E+01 -3.636042E-01
<surface> 2454 
type right_cylinder 1.000000E+00 -4.252976E+01 -3.925824E+01 -2.650788E-01
<surface> 2455 
type right_cylinder 1.000000E+00 -4.416552E+01 -3.925824E+01 -3.636042E-01
<surface> 2456 
type right_cylinder 1.000000E+00 -4.416552E+01 -3.925824E+01 -2.650788E-01
<surface> 2457 
type right_cylinder 1.000000E+00 -4.580128E+01 -3.925824E+01 -3.636042E-01
<surface> 2458 
type right_cylinder 1.000000E+00 -4.580128E+01 -3.925824E+01 -2.650788E-01
<surface> 2459 
type right_cylinder 1.000000E+00 -4.743704E+01 -3.925824E+01 -3.636042E-01
<surface> 2460 
type right_cylinder 1.000000E+00 -4.743704E+01 -3.925824E+01 -2.650788E-01
<surface> 2461 
type right_cylinder 1.000000E+00 -4.907280E+01 -3.925824E+01 -3.636042E-01
<surface> 2462 
type right_cylinder 1.000000E+00 -4.907280E+01 -3.925824E+01 -2.650788E-01
<surface> 2463 
type right_cylinder 1.000000E+00 -3.435096E+01 -4.089400E+01 -3.636042E-01
<surface> 2464 
type right_cylinder 1.000000E+00 -3.435096E+01 -4.089400E+01 -2.650788E-01
<surface> 2465 
type right_cylinder 1.000000E+00 -3.598672E+01 -4.089400E+01 -3.636042E-01
<surface> 2466 
type right_cylinder 1.000000E+00 -3.598672E+01 -4.089400E+01 -2.650788E-01
<surface> 2467 
type right_cylinder 1.000000E+00 -3.762248E+01 -4.089400E+01 -3.636042E-01
<surface> 2468 
type right_cylinder 1.000000E+00 -3.762248E+01 -4.089400E+01 -2.650788E-01
<surface> 2469 
type right_cylinder 1.000000E+00 -3.925824E+01 -4.089400E+01 -3.636042E-01
<surface> 2470 
type right_cylinder 1.000000E+00 -3.925824E+01 -4.089400E+01 -2.650788E-01
<surface> 2471 
type right_cylinder 1.000000E+00 -4.089400E+01 -4.089400E+01 -3.636042E-01
<surface> 2472 
type right_cylinder 1.000000E+00 -4.089400E+01 -4.089400E+01 -2.650788E-01
<surface> 2473 
type right_cylinder 1.000000E+00 -4.252976E+01 -4.089400E+01 -3.636042E-01
<surface> 2474 
type right_cylinder 1.000000E+00 -4.252976E+01 -4.089400E+01 -2.650788E-01
<surface> 2475 
type right_cylinder 1.000000E+00 -4.416552E+01 -4.089400E+01 -3.636042E-01
<surface> 2476 
type right_cylinder 1.000000E+00 -4.416552E+01 -4.089400E+01 -2.650788E-01
<surface> 2477 
type right_cylinder 1.000000E+00 -4.580128E+01 -4.089400E+01 -3.636042E-01
<surface> 2478 
type right_cylinder 1.000000E+00 -4.580128E+01 -4.089400E+01 -2.650788E-01
<surface> 2479 
type right_cylinder 1.000000E+00 -4.743704E+01 -4.089400E+01 -3.636042E-01
<surface> 2480 
type right_cylinder 1.000000E+00 -4.743704E+01 -4.089400E+01 -2.650788E-01
<surface> 2481 
type right_cylinder 1.000000E+00 -4.907280E+01 -4.089400E+01 -3.636042E-01
<surface> 2482 
type right_cylinder 1.000000E+00 -4.907280E+01 -4.089400E+01 -2.650788E-01
<surface> 2483 
type right_cylinder 1.000000E+00 -3.435096E+01 -4.252976E+01 -3.636042E-01
<surface> 2484 
type right_cylinder 1.000000E+00 -3.435096E+01 -4.252976E+01 -2.650788E-01
<surface> 2485 
type right_cylinder 1.000000E+00 -3.598672E+01 -4.252976E+01 -3.636042E-01
<surface> 2486 
type right_cylinder 1.000000E+00 -3.598672E+01 -4.252976E+01 -2.650788E-01
<surface> 2487 
type right_cylinder 1.000000E+00 -3.762248E+01 -4.252976E+01 -3.636042E-01
<surface> 2488 
type right_cylinder 1.000000E+00 -3.762248E+01 -4.252976E+01 -2.650788E-01
<surface> 2489 
type right_cylinder 1.000000E+00 -3.925824E+01 -4.252976E+01 -3.636042E-01
<surface> 2490 
type right_cylinder 1.000000E+00 -3.925824E+01 -4.252976E+01 -2.650788E-01
<surface> 2491 
type right_cylinder 1.000000E+00 -4.089400E+01 -4.252976E+01 -3.636042E-01
<surface> 2492 
type right_cylinder 1.000000E+00 -4.089400E+01 -4.252976E+01 -2.650788E-01
<surface> 2493 
type right_cylinder 1.000000E+00 -4.252976E+01 -4.252976E+01 -3.636042E-01
<surface> 2494 
type right_cylinder 1.000000E+00 -4.252976E+01 -4.252976E+01 -2.650788E-01
<surface> 2495 
type right_cylinder 1.000000E+00 -4.416552E+01 -4.252976E+01 -3.636042E-01
<surface> 2496 
type right_cylinder 1.000000E+00 -4.416552E+01 -4.252976E+01 -2.650788E-01
<surface> 2497 
type right_cylinder 1.000000E+00 -4.580128E+01 -4.252976E+01 -3.636042E-01
<surface> 2498 
type right_cylinder 1.000000E+00 -4.580128E+01 -4.252976E+01 -2.650788E-01
<surface> 2499 
type right_cylinder 1.000000E+00 -4.743704E+01 -4.252976E+01 -3.636042E-01
<surface> 2500 
type right_cylinder 1.000000E+00 -4.743704E+01 -4.252976E+01 -2.650788E-01
<surface> 2501 
type right_cylinder 1.000000E+00 -4.907280E+01 -4.252976E+01 -3.636042E-01
<surface> 2502 
type right_cylinder 1.000000E+00 -4.907280E+01 -4.252976E+01 -2.650788E-01
<surface> 2503 
type right_cylinder 1.000000E+00 -3.435096E+01 -4.416552E+01 -3.636042E-01
<surface> 2504 
type right_cylinder 1.000000E+00 -3.435096E+01 -4.416552E+01 -2.650788E-01
<surface> 2505 
type right_cylinder 1.000000E+00 -3.598672E+01 -4.416552E+01 -3.636042E-01
<surface> 2506 
type right_cylinder 1.000000E+00 -3.598672E+01 -4.416552E+01 -2.650788E-01
<surface> 2507 
type right_cylinder 1.000000E+00 -3.762248E+01 -4.416552E+01 -3.636042E-01
<surface> 2508 
type right_cylinder 1.000000E+00 -3.762248E+01 -4.416552E+01 -2.650788E-01
<surface> 2509 
type right_cylinder 1.000000E+00 -3.925824E+01 -4.416552E+01 -3.636042E-01
<surface> 2510 
type right_cylinder 1.000000E+00 -3.925824E+01 -4.416552E+01 -2.650788E-01
<surface> 2511 
type right_cylinder 1.000000E+00 -4.089400E+01 -4.416552E+01 -3.636042E-01
<surface> 2512 
type right_cylinder 1.000000E+00 -4.089400E+01 -4.416552E+01 -2.650788E-01
<surface> 2513 
type right_cylinder 1.000000E+00 -4.252976E+01 -4.416552E+01 -3.636042E-01
<surface> 2514 
type right_cylinder 1.000000E+00 -4.252976E+01 -4.416552E+01 -2.650788E-01
<surface> 2515 
type right_cylinder 1.000000E+00 -4.416552E+01 -4.416552E+01 -3.636042E-01
<surface> 2516 
type right_cylinder 1.000000E+00 -4.416552E+01 -4.416552E+01 -2.650788E-01
<surface> 2517 
type right_cylinder 1.000000E+00 -4.580128E+01 -4.416552E+01 -3.636042E-01
<surface> 2518 
type right_cylinder 1.000000E+00 -4.580128E+01 -4.416552E+01 -2.650788E-01
<surface> 2519 
type right_cylinder 1.000000E+00 -4.743704E+01 -4.416552E+01 -3.636042E-01
<surface> 2520 
type right_cylinder 1.000000E+00 -4.743704E+01 -4.416552E+01 -2.650788E-01
<surface> 2521 
type right_cylinder 1.000000E+00 -4.907280E+01 -4.416552E+01 -3.636042E-01
<surface> 2522 
type right_cylinder 1.000000E+00 -4.907280E+01 -4.416552E+01 -2.650788E-01
<surface> 2523 
type right_cylinder 1.000000E+00 -3.435096E+01 -4.580128E+01 -3.636042E-01
<surface> 2524 
type right_cylinder 1.000000E+00 -3.435096E+01 -4.580128E+01 -2.650788E-01
<surface> 2525 
type right_cylinder 1.000000E+00 -3.598672E+01 -4.580128E+01 -3.636042E-01
<surface> 2526 
type right_cylinder 1.000000E+00 -3.598672E+01 -4.580128E+01 -2.650788E-01
<surface> 2527 
type right_cylinder 1.000000E+00 -3.762248E+01 -4.580128E+01 -3.636042E-01
<surface> 2528 
type right_cylinder 1.000000E+00 -3.762248E+01 -4.580128E+01 -2.650788E-01
<surface> 2529 
type right_cylinder 1.000000E+00 -3.925824E+01 -4.580128E+01 -3.636042E-01
<surface> 2530 
type right_cylinder 1.000000E+00 -3.925824E+01 -4.580128E+01 -2.650788E-01
<surface> 2531 
type right_cylinder 1.000000E+00 -4.089400E+01 -4.580128E+01 -3.636042E-01
<surface> 2532 
type right_cylinder 1.000000E+00 -4.089400E+01 -4.580128E+01 -2.650788E-01
<surface> 2533 
type right_cylinder 1.000000E+00 -4.252976E+01 -4.580128E+01 -3.636042E-01
<surface> 2534 
type right_cylinder 1.000000E+00 -4.252976E+01 -4.580128E+01 -2.650788E-01
<surface> 2535 
type right_cylinder 1.000000E+00 -4.416552E+01 -4.580128E+01 -3.636042E-01
<surface> 2536 
type right_cylinder 1.000000E+00 -4.416552E+01 -4.580128E+01 -2.650788E-01
<surface> 2537 
type right_cylinder 1.000000E+00 -4.580128E+01 -4.580128E+01 -3.636042E-01
<surface> 2538 
type right_cylinder 1.000000E+00 -4.580128E+01 -4.580128E+01 -2.650788E-01
<surface> 2539 
type right_cylinder 1.000000E+00 -4.743704E+01 -4.580128E+01 -3.636042E-01
<surface> 2540 
type right_cylinder 1.000000E+00 -4.743704E+01 -4.580128E+01 -2.650788E-01
<surface> 2541 
type right_cylinder 1.000000E+00 -4.907280E+01 -4.580128E+01 -3.636042E-01
<surface> 2542 
type right_cylinder 1.000000E+00 -4.907280E+01 -4.580128E+01 -2.650788E-01
<surface> 2543 
type right_cylinder 1.000000E+00 -3.435096E+01 -4.743704E+01 -3.636042E-01
<surface> 2544 
type right_cylinder 1.000000E+00 -3.435096E+01 -4.743704E+01 -2.650788E-01
<surface> 2545 
type right_cylinder 1.000000E+00 -3.598672E+01 -4.743704E+01 -3.636042E-01
<surface> 2546 
type right_cylinder 1.000000E+00 -3.598672E+01 -4.743704E+01 -2.650788E-01
<surface> 2547 
type right_cylinder 1.000000E+00 -3.762248E+01 -4.743704E+01 -3.636042E-01
<surface> 2548 
type right_cylinder 1.000000E+00 -3.762248E+01 -4.743704E+01 -2.650788E-01
<surface> 2549 
type right_cylinder 1.000000E+00 -3.925824E+01 -4.743704E+01 -3.636042E-01
<surface> 2550 
type right_cylinder 1.000000E+00 -3.925824E+01 -4.743704E+01 -2.650788E-01
<surface> 2551 
type right_cylinder 1.000000E+00 -4.089400E+01 -4.743704E+01 -3.636042E-01
<surface> 2552 
type right_cylinder 1.000000E+00 -4.089400E+01 -4.743704E+01 -2.650788E-01
<surface> 2553 
type right_cylinder 1.000000E+00 -4.252976E+01 -4.743704E+01 -3.636042E-01
<surface> 2554 
type right_cylinder 1.000000E+00 -4.252976E+01 -4.743704E+01 -2.650788E-01
<surface> 2555 
type right_cylinder 1.000000E+00 -4.416552E+01 -4.743704E+01 -3.636042E-01
<surface> 2556 
type right_cylinder 1.000000E+00 -4.416552E+01 -4.743704E+01 -2.650788E-01
<surface> 2557 
type right_cylinder 1.000000E+00 -4.580128E+01 -4.743704E+01 -3.636042E-01
<surface> 2558 
type right_cylinder 1.000000E+00 -4.580128E+01 -4.743704E+01 -2.650788E-01
<surface> 2559 
type right_cylinder 1.000000E+00 -4.743704E+01 -4.743704E+01 -3.636042E-01
<surface> 2560 
type right_cylinder 1.000000E+00 -4.743704E+01 -4.743704E+01 -2.650788E-01
<surface> 2561 
type right_cylinder 1.000000E+00 -4.907280E+01 -4.743704E+01 -3.636042E-01
<surface> 2562 
type right_cylinder 1.000000E+00 -4.907280E+01 -4.743704E+01 -2.650788E-01
<surface> 2563 
type right_cylinder 1.000000E+00 -3.435096E+01 -4.907280E+01 -3.636042E-01
<surface> 2564 
type right_cylinder 1.000000E+00 -3.435096E+01 -4.907280E+01 -2.650788E-01
<surface> 2565 
type right_cylinder 1.000000E+00 -3.598672E+01 -4.907280E+01 -3.636042E-01
<surface> 2566 
type right_cylinder 1.000000E+00 -3.598672E+01 -4.907280E+01 -2.650788E-01
<surface> 2567 
type right_cylinder 1.000000E+00 -3.762248E+01 -4.907280E+01 -3.636042E-01
<surface> 2568 
type right_cylinder 1.000000E+00 -3.762248E+01 -4.907280E+01 -2.650788E-01
<surface> 2569 
type right_cylinder 1.000000E+00 -3.925824E+01 -4.907280E+01 -3.636042E-01
<surface> 2570 
type right_cylinder 1.000000E+00 -3.925824E+01 -4.907280E+01 -2.650788E-01
<surface> 2571 
type right_cylinder 1.000000E+00 -4.089400E+01 -4.907280E+01 -3.636042E-01
<surface> 2572 
type right_cylinder 1.000000E+00 -4.089400E+01 -4.907280E+01 -2.650788E-01
<surface> 2573 
type right_cylinder 1.000000E+00 -4.252976E+01 -4.907280E+01 -3.636042E-01
<surface> 2574 
type right_cylinder 1.000000E+00 -4.252976E+01 -4.907280E+01 -2.650788E-01
<surface> 2575 
type right_cylinder 1.000000E+00 -4.416552E+01 -4.907280E+01 -3.636042E-01
<surface> 2576 
type right_cylinder 1.000000E+00 -4.416552E+01 -4.907280E+01 -2.650788E-01
<surface> 2577 
type right_cylinder 1.000000E+00 -4.580128E+01 -4.907280E+01 -3.636042E-01
<surface> 2578 
type right_cylinder 1.000000E+00 -4.580128E+01 -4.907280E+01 -2.650788E-01
<surface> 2579 
type right_cylinder 1.000000E+00 -4.743704E+01 -4.907280E+01 -3.636042E-01
<surface> 2580 
type right_cylinder 1.000000E+00 -4.743704E+01 -4.907280E+01 -2.650788E-01
<surface> 2581 
type right_cylinder 1.000000E+00 -4.907280E+01 -4.907280E+01 -3.636042E-01
<surface> 2582 
type right_cylinder 1.000000E+00 -4.907280E+01 -4.907280E+01 -2.650788E-01
end_surface_list

component_list 3776
<component> 0 
n_bounds 6
bounds 1 4 5 -2 -3 -6 
n_inners 3775 
inners 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 
21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 
41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 
61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 
81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 
101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 
121 122 123 124 125 126 127 128 129 130 131 132 133 134 135 136 137 138 139 140 
141 142 143 144 145 146 147 148 149 150 151 152 153 154 155 156 157 158 159 160 
161 162 163 164 165 166 167 168 169 170 171 172 173 174 175 176 177 178 179 180 
181 182 183 184 185 186 187 188 189 190 191 192 193 194 195 196 197 198 199 200 
201 202 203 204 205 206 207 208 209 210 211 212 213 214 215 216 217 218 219 220 
221 222 223 224 225 226 227 228 229 230 231 232 233 234 235 236 237 238 239 240 
241 242 243 244 245 246 247 248 249 250 251 252 253 254 255 256 257 258 259 260 
261 262 263 264 265 266 267 268 269 270 271 272 273 274 275 276 277 278 279 280 
281 282 283 284 285 286 287 288 289 290 291 292 293 294 295 296 297 298 299 300 
301 302 303 304 305 306 307 308 309 310 311 312 313 314 315 316 317 318 319 320 
321 322 323 324 325 326 327 328 329 330 331 332 333 334 335 336 337 338 339 340 
341 342 343 344 345 346 347 348 349 350 351 352 353 354 355 356 357 358 359 360 
361 362 363 364 365 366 367 368 369 370 371 372 373 374 375 376 377 378 379 380 
381 382 383 384 385 386 387 388 389 390 391 392 393 394 395 396 397 398 399 400 
401 402 403 404 405 406 407 408 409 410 411 412 413 414 415 416 417 418 419 420 
421 422 423 424 425 426 427 428 429 430 431 432 433 434 435 436 437 438 439 440 
441 442 443 444 445 446 447 448 449 450 451 452 453 454 455 456 457 458 459 460 
461 462 463 464 465 466 467 468 469 470 471 472 473 474 475 476 477 478 479 480 
481 482 483 484 485 486 487 488 489 490 491 492 493 494 495 496 497 498 499 500 
501 502 503 504 505 506 507 508 509 510 511 512 513 514 515 516 517 518 519 520 
521 522 523 524 525 526 527 528 529 530 531 532 533 534 535 536 537 538 539 540 
541 542 543 544 545 546 547 548 549 550 551 552 553 554 555 556 557 558 559 560 
561 562 563 564 565 566 567 568 569 570 571 572 573 574 575 576 577 578 579 580 
581 582 583 584 585 586 587 588 589 590 591 592 593 594 595 596 597 598 599 600 
601 602 603 604 605 606 607 608 609 610 611 612 613 614 615 616 617 618 619 620 
621 622 623 624 625 626 627 628 629 630 631 632 633 634 635 636 637 638 639 640 
641 642 643 644 645 646 647 648 649 650 651 652 653 654 655 656 657 658 659 660 
661 662 663 664 665 666 667 668 669 670 671 672 673 674 675 676 677 678 679 680 
681 682 683 684 685 686 687 688 689 690 691 692 693 694 695 696 697 698 699 700 
701 702 703 704 705 706 707 708 709 710 711 712 713 714 715 716 717 718 719 720 
721 722 723 724 725 726 727 728 729 730 731 732 733 734 735 736 737 738 739 740 
741 742 743 744 745 746 747 748 749 750 751 752 753 754 755 756 757 758 759 760 
761 762 763 764 765 766 767 768 769 770 771 772 773 774 775 776 777 778 779 780 
781 782 783 784 785 786 787 788 789 790 791 792 793 794 795 796 797 798 799 800 
801 802 803 804 805 806 807 808 809 810 811 812 813 814 815 816 817 818 819 820 
821 822 823 824 825 826 827 828 829 830 831 832 833 834 835 836 837 838 839 840 
841 842 843 844 845 846 847 848 849 850 851 852 853 854 855 856 857 858 859 860 
861 862 863 864 865 866 867 868 869 870 871 872 873 874 875 876 877 878 879 880 
881 882 883 884 885 886 887 888 889 890 891 892 893 894 895 896 897 898 899 900 
901 902 903 904 905 906 907 908 909 910 911 912 913 914 915 916 917 918 919 920 
921 922 923 924 925 926 927 928 929 930 931 932 933 934 935 936 937 938 939 940 
941 942 943 944 945 946 947 948 949 950 951 952 953 954 955 956 957 958 959 960 
961 962 963 964 965 966 967 968 969 970 971 972 973 974 975 976 977 978 979 980 
981 982 983 984 985 986 987 988 989 990 991 992 993 994 995 996 997 998 999 1000 
1001 1002 1003 1004 1005 1006 1007 1008 1009 1010 1011 1012 1013 1014 1015 1016 1017 1018 1019 1020 
1021 1022 1023 1024 1025 1026 1027 1028 1029 1030 1031 1032 1033 1034 1035 1036 1037 1038 1039 1040 
1041 1042 1043 1044 1045 1046 1047 1048 1049 1050 1051 1052 1053 1054 1055 1056 1057 1058 1059 1060 
1061 1062 1063 1064 1065 1066 1067 1068 1069 1070 1071 1072 1073 1074 1075 1076 1077 1078 1079 1080 
1081 1082 1083 1084 1085 1086 1087 1088 1089 1090 1091 1092 1093 1094 1095 1096 1097 1098 1099 1100 
1101 1102 1103 1104 1105 1106 1107 1108 1109 1110 1111 1112 1113 1114 1115 1116 1117 1118 1119 1120 
1121 1122 1123 1124 1125 1126 1127 1128 1129 1130 1131 1132 1133 1134 1135 1136 1137 1138 1139 1140 
1141 1142 1143 1144 1145 1146 1147 1148 1149 1150 1151 1152 1153 1154 1155 1156 1157 1158 1159 1160 
1161 1162 1163 1164 1165 1166 1167 1168 1169 1170 1171 1172 1173 1174 1175 1176 1177 1178 1179 1180 
1181 1182 1183 1184 1185 1186 1187 1188 1189 1190 1191 1192 1193 1194 1195 1196 1197 1198 1199 1200 
1201 1202 1203 1204 1205 1206 1207 1208 1209 1210 1211 1212 1213 1214 1215 1216 1217 1218 1219 1220 
1221 1222 1223 1224 1225 1226 1227 1228 1229 1230 1231 1232 1233 1234 1235 1236 1237 1238 1239 1240 
1241 1242 1243 1244 1245 1246 1247 1248 1249 1250 1251 1252 1253 1254 1255 1256 1257 1258 1259 1260 
1261 1262 1263 1264 1265 1266 1267 1268 1269 1270 1271 1272 1273 1274 1275 1276 1277 1278 1279 1280 
1281 1282 1283 1284 1285 1286 1287 1288 1289 1290 1291 1292 1293 1294 1295 1296 1297 1298 1299 1300 
1301 1302 1303 1304 1305 1306 1307 1308 1309 1310 1311 1312 1313 1314 1315 1316 1317 1318 1319 1320 
1321 1322 1323 1324 1325 1326 1327 1328 1329 1330 1331 1332 1333 1334 1335 1336 1337 1338 1339 1340 
1341 1342 1343 1344 1345 1346 1347 1348 1349 1350 1351 1352 1353 1354 1355 1356 1357 1358 1359 1360 
1361 1362 1363 1364 1365 1366 1367 1368 1369 1370 1371 1372 1373 1374 1375 1376 1377 1378 1379 1380 
1381 1382 1383 1384 1385 1386 1387 1388 1389 1390 1391 1392 1393 1394 1395 1396 1397 1398 1399 1400 
1401 1402 1403 1404 1405 1406 1407 1408 1409 1410 1411 1412 1413 1414 1415 1416 1417 1418 1419 1420 
1421 1422 1423 1424 1425 1426 1427 1428 1429 1430 1431 1432 1433 1434 1435 1436 1437 1438 1439 1440 
1441 1442 1443 1444 1445 1446 1447 1448 1449 1450 1451 1452 1453 1454 1455 1456 1457 1458 1459 1460 
1461 1462 1463 1464 1465 1466 1467 1468 1469 1470 1471 1472 1473 1474 1475 1476 1477 1478 1479 1480 
1481 1482 1483 1484 1485 1486 1487 1488 1489 1490 1491 1492 1493 1494 1495 1496 1497 1498 1499 1500 
1501 1502 1503 1504 1505 1506 1507 1508 1509 1510 1511 1512 1513 1514 1515 1516 1517 1518 1519 1520 
1521 1522 1523 1524 1525 1526 1527 1528 1529 1530 1531 1532 1533 1534 1535 1536 1537 1538 1539 1540 
1541 1542 1543 1544 1545 1546 1547 1548 1549 1550 1551 1552 1553 1554 1555 1556 1557 1558 1559 1560 
1561 1562 1563 1564 1565 1566 1567 1568 1569 1570 1571 1572 1573 1574 1575 1576 1577 1578 1579 1580 
1581 1582 1583 1584 1585 1586 1587 1588 1589 1590 1591 1592 1593 1594 1595 1596 1597 1598 1599 1600 
1601 1602 1603 1604 1605 1606 1607 1608 1609 1610 1611 1612 1613 1614 1615 1616 1617 1618 1619 1620 
1621 1622 1623 1624 1625 1626 1627 1628 1629 1630 1631 1632 1633 1634 1635 1636 1637 1638 1639 1640 
1641 1642 1643 1644 1645 1646 1647 1648 1649 1650 1651 1652 1653 1654 1655 1656 1657 1658 1659 1660 
1661 1662 1663 1664 1665 1666 1667 1668 1669 1670 1671 1672 1673 1674 1675 1676 1677 1678 1679 1680 
1681 1682 1683 1684 1685 1686 1687 1688 1689 1690 1691 1692 1693 1694 1695 1696 1697 1698 1699 1700 
1701 1702 1703 1704 1705 1706 1707 1708 1709 1710 1711 1712 1713 1714 1715 1716 1717 1718 1719 1720 
1721 1722 1723 1724 1725 1726 1727 1728 1729 1730 1731 1732 1733 1734 1735 1736 1737 1738 1739 1740 
1741 1742 1743 1744 1745 1746 1747 1748 1749 1750 1751 1752 1753 1754 1755 1756 1757 1758 1759 1760 
1761 1762 1763 1764 1765 1766 1767 1768 1769 1770 1771 1772 1773 1774 1775 1776 1777 1778 1779 1780 
1781 1782 1783 1784 1785 1786 1787 1788 1789 1790 1791 1792 1793 1794 1795 1796 1797 1798 1799 1800 
1801 1802 1803 1804 1805 1806 1807 1808 1809 1810 1811 1812 1813 1814 1815 1816 1817 1818 1819 1820 
1821 1822 1823 1824 1825 1826 1827 1828 1829 1830 1831 1832 1833 1834 1835 1836 1837 1838 1839 1840 
1841 1842 1843 1844 1845 1846 1847 1848 1849 1850 1851 1852 1853 1854 1855 1856 1857 1858 1859 1860 
1861 1862 1863 1864 1865 1866 1867 1868 1869 1870 1871 1872 1873 1874 1875 1876 1877 1878 1879 1880 
1881 1882 1883 1884 1885 1886 1887 1888 1889 1890 1891 1892 1893 1894 1895 1896 1897 1898 1899 1900 
1901 1902 1903 1904 1905 1906 1907 1908 1909 1910 1911 1912 1913 1914 1915 1916 1917 1918 1919 1920 
1921 1922 1923 1924 1925 1926 1927 1928 1929 1930 1931 1932 1933 1934 1935 1936 1937 1938 1939 1940 
1941 1942 1943 1944 1945 1946 1947 1948 1949 1950 1951 1952 1953 1954 1955 1956 1957 1958 1959 1960 
1961 1962 1963 1964 1965 1966 1967 1968 1969 1970 1971 1972 1973 1974 1975 1976 1977 1978 1979 1980 
1981 1982 1983 1984 1985 1986 1987 1988 1989 1990 1991 1992 1993 1994 1995 1996 1997 1998 1999 2000 
2001 2002 2003 2004 2005 2006 2007 2008 2009 2010 2011 2012 2013 2014 2015 2016 2017 2018 2019 2020 
2021 2022 2023 2024 2025 2026 2027 2028 2029 2030 2031 2032 2033 2034 2035 2036 2037 2038 2039 2040 
2041 2042 2043 2044 2045 2046 2047 2048 2049 2050 2051 2052 2053 2054 2055 2056 2057 2058 2059 2060 
2061 2062 2063 2064 2065 2066 2067 2068 2069 2070 2071 2072 2073 2074 2075 2076 2077 2078 2079 2080 
2081 2082 2083 2084 2085 2086 2087 2088 2089 2090 2091 2092 2093 2094 2095 2096 2097 2098 2099 2100 
2101 2102 2103 2104 2105 2106 2107 2108 2109 2110 2111 2112 2113 2114 2115 2116 2117 2118 2119 2120 
2121 2122 2123 2124 2125 2126 2127 2128 2129 2130 2131 2132 2133 2134 2135 2136 2137 2138 2139 2140 
2141 2142 2143 2144 2145 2146 2147 2148 2149 2150 2151 2152 2153 2154 2155 2156 2157 2158 2159 2160 
2161 2162 2163 2164 2165 2166 2167 2168 2169 2170 2171 2172 2173 2174 2175 2176 2177 2178 2179 2180 
2181 2182 2183 2184 2185 2186 2187 2188 2189 2190 2191 2192 2193 2194 2195 2196 2197 2198 2199 2200 
2201 2202 2203 2204 2205 2206 2207 2208 2209 2210 2211 2212 2213 2214 2215 2216 2217 2218 2219 2220 
2221 2222 2223 2224 2225 2226 2227 2228 2229 2230 2231 2232 2233 2234 2235 2236 2237 2238 2239 2240 
2241 2242 2243 2244 2245 2246 2247 2248 2249 2250 2251 2252 2253 2254 2255 2256 2257 2258 2259 2260 
2261 2262 2263 2264 2265 2266 2267 2268 2269 2270 2271 2272 2273 2274 2275 2276 2277 2278 2279 2280 
2281 2282 2283 2284 2285 2286 2287 2288 2289 2290 2291 2292 2293 2294 2295 2296 2297 2298 2299 2300 
2301 2302 2303 2304 2305 2306 2307 2308 2309 2310 2311 2312 2313 2314 2315 2316 2317 2318 2319 2320 
2321 2322 2323 2324 2325 2326 2327 2328 2329 2330 2331 2332 2333 2334 2335 2336 2337 2338 2339 2340 
2341 2342 2343 2344 2345 2346 2347 2348 2349 2350 2351 2352 2353 2354 2355 2356 2357 2358 2359 2360 
2361 2362 2363 2364 2365 2366 2367 2368 2369 2370 2371 2372 2373 2374 2375 2376 2377 2378 2379 2380 
2381 2382 2383 2384 2385 2386 2387 2388 2389 2390 2391 2392 2393 2394 2395 2396 2397 2398 2399 2400 
2401 2402 2403 2404 2405 2406 2407 2408 2409 2410 2411 2412 2413 2414 2415 2416 2417 2418 2419 2420 
2421 2422 2423 2424 2425 2426 2427 2428 2429 2430 2431 2432 2433 2434 2435 2436 2437 2438 2439 2440 
2441 2442 2443 2444 2445 2446 2447 2448 2449 2450 2451 2452 2453 2454 2455 2456 2457 2458 2459 2460 
2461 2462 2463 2464 2465 2466 2467 2468 2469 2470 2471 2472 2473 2474 2475 2476 2477 2478 2479 2480 
2481 2482 2483 2484 2485 2486 2487 2488 2489 2490 2491 2492 2493 2494 2495 2496 2497 2498 2499 2500 
2501 2502 2503 2504 2505 2506 2507 2508 2509 2510 2511 2512 2513 2514 2515 2516 2517 2518 2519 2520 
2521 2522 2523 2524 2525 2526 2527 2528 2529 2530 2531 2532 2533 2534 2535 2536 2537 2538 2539 2540 
2541 2542 2543 2544 2545 2546 2547 2548 2549 2550 2551 2552 2553 2554 2555 2556 2557 2558 2559 2560 
2561 2562 2563 2564 2565 2566 2567 2568 2569 2570 2571 2572 2573 2574 2575 2576 2577 2578 2579 2580 
2581 2582 2583 2584 2585 2586 2587 2588 2589 2590 2591 2592 2593 2594 2595 2596 2597 2598 2599 2600 
2601 2602 2603 2604 2605 2606 2607 2608 2609 2610 2611 2612 2613 2614 2615 2616 2617 2618 2619 2620 
2621 2622 2623 2624 2625 2626 2627 2628 2629 2630 2631 2632 2633 2634 2635 2636 2637 2638 2639 2640 
2641 2642 2643 2644 2645 2646 2647 2648 2649 2650 2651 2652 2653 2654 2655 2656 2657 2658 2659 2660 
2661 2662 2663 2664 2665 2666 2667 2668 2669 2670 2671 2672 2673 2674 2675 2676 2677 2678 2679 2680 
2681 2682 2683 2684 2685 2686 2687 2688 2689 2690 2691 2692 2693 2694 2695 2696 2697 2698 2699 2700 
2701 2702 2703 2704 2705 2706 2707 2708 2709 2710 2711 2712 2713 2714 2715 2716 2717 2718 2719 2720 
2721 2722 2723 2724 2725 2726 2727 2728 2729 2730 2731 2732 2733 2734 2735 2736 2737 2738 2739 2740 
2741 2742 2743 2744 2745 2746 2747 2748 2749 2750 2751 2752 2753 2754 2755 2756 2757 2758 2759 2760 
2761 2762 2763 2764 2765 2766 2767 2768 2769 2770 2771 2772 2773 2774 2775 2776 2777 2778 2779 2780 
2781 2782 2783 2784 2785 2786 2787 2788 2789 2790 2791 2792 2793 2794 2795 2796 2797 2798 2799 2800 
2801 2802 2803 2804 2805 2806 2807 2808 2809 2810 2811 2812 2813 2814 2815 2816 2817 2818 2819 2820 
2821 2822 2823 2824 2825 2826 2827 2828 2829 2830 2831 2832 2833 2834 2835 2836 2837 2838 2839 2840 
2841 2842 2843 2844 2845 2846 2847 2848 2849 2850 2851 2852 2853 2854 2855 2856 2857 2858 2859 2860 
2861 2862 2863 2864 2865 2866 2867 2868 2869 2870 2871 2872 2873 2874 2875 2876 2877 2878 2879 2880 
2881 2882 2883 2884 2885 2886 2887 2888 2889 2890 2891 2892 2893 2894 2895 2896 2897 2898 2899 2900 
2901 2902 2903 2904 2905 2906 2907 2908 2909 2910 2911 2912 2913 2914 2915 2916 2917 2918 2919 2920 
2921 2922 2923 2924 2925 2926 2927 2928 2929 2930 2931 2932 2933 2934 2935 2936 2937 2938 2939 2940 
2941 2942 2943 2944 2945 2946 2947 2948 2949 2950 2951 2952 2953 2954 2955 2956 2957 2958 2959 2960 
2961 2962 2963 2964 2965 2966 2967 2968 2969 2970 2971 2972 2973 2974 2975 2976 2977 2978 2979 2980 
2981 2982 2983 2984 2985 2986 2987 2988 2989 2990 2991 2992 2993 2994 2995 2996 2997 2998 2999 3000 
3001 3002 3003 3004 3005 3006 3007 3008 3009 3010 3011 3012 3013 3014 3015 3016 3017 3018 3019 3020 
3021 3022 3023 3024 3025 3026 3027 3028 3029 3030 3031 3032 3033 3034 3035 3036 3037 3038 3039 3040 
3041 3042 3043 3044 3045 3046 3047 3048 3049 3050 3051 3052 3053 3054 3055 3056 3057 3058 3059 3060 
3061 3062 3063 3064 3065 3066 3067 3068 3069 3070 3071 3072 3073 3074 3075 3076 3077 3078 3079 3080 
3081 3082 3083 3084 3085 3086 3087 3088 3089 3090 3091 3092 3093 3094 3095 3096 3097 3098 3099 3100 
3101 3102 3103 3104 3105 3106 3107 3108 3109 3110 3111 3112 3113 3114 3115 3116 3117 3118 3119 3120 
3121 3122 3123 3124 3125 3126 3127 3128 3129 3130 3131 3132 3133 3134 3135 3136 3137 3138 3139 3140 
3141 3142 3143 3144 3145 3146 3147 3148 3149 3150 3151 3152 3153 3154 3155 3156 3157 3158 3159 3160 
3161 3162 3163 3164 3165 3166 3167 3168 3169 3170 3171 3172 3173 3174 3175 3176 3177 3178 3179 3180 
3181 3182 3183 3184 3185 3186 3187 3188 3189 3190 3191 3192 3193 3194 3195 3196 3197 3198 3199 3200 
3201 3202 3203 3204 3205 3206 3207 3208 3209 3210 3211 3212 3213 3214 3215 3216 3217 3218 3219 3220 
3221 3222 3223 3224 3225 3226 3227 3228 3229 3230 3231 3232 3233 3234 3235 3236 3237 3238 3239 3240 
3241 3242 3243 3244 3245 3246 3247 3248 3249 3250 3251 3252 3253 3254 3255 3256 3257 3258 3259 3260 
3261 3262 3263 3264 3265 3266 3267 3268 3269 3270 3271 3272 3273 3274 3275 3276 3277 3278 3279 3280 
3281 3282 3283 3284 3285 3286 3287 3288 3289 3290 3291 3292 3293 3294 3295 3296 3297 3298 3299 3300 
3301 3302 3303 3304 3305 3306 3307 3308 3309 3310 3311 3312 3313 3314 3315 3316 3317 3318 3319 3320 
3321 3322 3323 3324 3325 3326 3327 3328 3329 3330 3331 3332 3333 3334 3335 3336 3337 3338 3339 3340 
3341 3342 3343 3344 3345 3346 3347 3348 3349 3350 3351 3352 3353 3354 3355 3356 3357 3358 3359 3360 
3361 3362 3363 3364 3365 3366 3367 3368 3369 3370 3371 3372 3373 3374 3375 3376 3377 3378 3379 3380 
3381 3382 3383 3384 3385 3386 3387 3388 3389 3390 3391 3392 3393 3394 3395 3396 3397 3398 3399 3400 
3401 3402 3403 3404 3405 3406 3407 3408 3409 3410 3411 3412 3413 3414 3415 3416 3417 3418 3419 3420 
3421 3422 3423 3424 3425 3426 3427 3428 3429 3430 3431 3432 3433 3434 3435 3436 3437 3438 3439 3440 
3441 3442 3443 3444 3445 3446 3447 3448 3449 3450 3451 3452 3453 3454 3455 3456 3457 3458 3459 3460 
3461 3462 3463 3464 3465 3466 3467 3468 3469 3470 3471 3472 3473 3474 3475 3476 3477 3478 3479 3480 
3481 3482 3483 3484 3485 3486 3487 3488 3489 3490 3491 3492 3493 3494 3495 3496 3497 3498 3499 3500 
3501 3502 3503 3504 3505 3506 3507 3508 3509 3510 3511 3512 3513 3514 3515 3516 3517 3518 3519 3520 
3521 3522 3523 3524 3525 3526 3527 3528 3529 3530 3531 3532 3533 3534 3535 3536 3537 3538 3539 3540 
3541 3542 3543 3544 3545 3546 3547 3548 3549 3550 3551 3552 3553 3554 3555 3556 3557 3558 3559 3560 
3561 3562 3563 3564 3565 3566 3567 3568 3569 3570 3571 3572 3573 3574 3575 3576 3577 3578 3579 3580 
3581 3582 3583 3584 3585 3586 3587 3588 3589 3590 3591 3592 3593 3594 3595 3596 3597 3598 3599 3600 
3601 3602 3603 3604 3605 3606 3607 3608 3609 3610 3611 3612 3613 3614 3615 3616 3617 3618 3619 3620 
3621 3622 3623 3624 3625 3626 3627 3628 3629 3630 3631 3632 3633 3634 3635 3636 3637 3638 3639 3640 
3641 3642 3643 3644 3645 3646 3647 3648 3649 3650 3651 3652 3653 3654 3655 3656 3657 3658 3659 3660 
3661 3662 3663 3664 3665 3666 3667 3668 3669 3670 3671 3672 3673 3674 3675 3676 3677 3678 3679 3680 
3681 3682 3683 3684 3685 3686 3687 3688 3689 3690 3691 3692 3693 3694 3695 3696 3697 3698 3699 3700 
3701 3702 3703 3704 3705 3706 3707 3708 3709 3710 3711 3712 3713 3714 3715 3716 3717 3718 3719 3720 
3721 3722 3723 3724 3725 3726 3727 3728 3729 3730 3731 3732 3733 3734 3735 3736 3737 3738 3739 3740 
3741 3742 3743 3744 3745 3746 3747 3748 3749 3750 3751 3752 3753 3754 3755 3756 3757 3758 3759 3760 
3761 3762 3763 3764 3765 3766 3767 3768 3769 3770 3771 3772 3773 3774 3775
property_list 
material 1
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/TANK_0-2
end_property_list 
<component> 1 
n_bounds 4
bounds 7 9 -8 -10 
property_list 
material 2
region 3
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/TANK_0-2
end_property_list 
<component> 2 
n_bounds 8
bounds -11 -15 -7 -10 12 13 14 9 
property_list 
material 2
region 3
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/TANK_0-2
end_property_list 
<component> 3 
n_bounds 5
bounds 11 13 9 -7 -10 
property_list 
material 2
region 3
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/TANK_0-2
end_property_list 
<component> 4 
n_bounds 6
bounds 15 16 9 -17 -7 -10 
property_list 
material 2
region 3
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/TANK_0-2
end_property_list 
<component> 5 
n_bounds 4
bounds 18 9 -8 -10 
property_list 
material 2
region 3
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/TANK_0-2
end_property_list 
<component> 6 
n_bounds 6
bounds -19 -18 -10 17 20 9 
property_list 
material 2
region 3
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/TANK_0-2
end_property_list 
<component> 7 
n_bounds 6
bounds -21 -18 -10 22 13 9 
property_list 
material 2
region 3
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/TANK_0-2
end_property_list 
<component> 8 
n_bounds 6
bounds 21 19 13 9 -18 -10 
property_list 
material 2
region 3
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/TANK_0-2
end_property_list 
<component> 9 
n_bounds 5
bounds -13 -10 23 11 9 
property_list 
material 2
region 3
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/TANK_0-2
end_property_list 
<component> 10 
n_bounds 5
bounds -13 -10 12 14 9 
property_list 
material 2
region 3
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/TANK_0-2
end_property_list 
<component> 11 
n_bounds 5
bounds -13 -10 19 21 9 
property_list 
material 2
region 3
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/TANK_0-2
end_property_list 
<component> 12 
n_bounds 5
bounds -13 -10 22 24 9 
property_list 
material 2
region 3
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3
end_property_list 
<component> 13 
n_bounds 6
bounds 24 23 9 -25 -26 -10 
property_list 
material 2
region 4
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-4
end_property_list 
<component> 14 
n_bounds 8
bounds 24 25 29 28 9 -27 -26 -10 
property_list 
material 2
region 5
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-5
end_property_list 
<component> 15 
n_bounds 6
bounds 24 31 30 9 -28 -10 
property_list 
material 3
region 6
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-6
end_property_list 
<component> 16 
n_bounds 4
bounds 24 9 -30 -10 
property_list 
material 4
region 7
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-7
end_property_list 
<component> 17 
n_bounds 8
bounds 24 29 32 27 9 -33 -26 -10 
property_list 
material 2
region 8
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-8
end_property_list 
<component> 18 
n_bounds 6
bounds 24 31 34 9 -32 -10 
property_list 
material 3
region 9
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-9
end_property_list 
<component> 19 
n_bounds 4
bounds 24 9 -34 -10 
property_list 
material 4
region 10
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-10
end_property_list 
<component> 20 
n_bounds 8
bounds 24 29 35 33 9 -36 -26 -10 
property_list 
material 2
region 11
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-11
end_property_list 
<component> 21 
n_bounds 6
bounds 24 31 37 9 -35 -10 
property_list 
material 3
region 12
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-12
end_property_list 
<component> 22 
n_bounds 4
bounds 24 9 -37 -10 
property_list 
material 4
region 13
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-13
end_property_list 
<component> 23 
n_bounds 8
bounds 24 29 38 36 9 -39 -26 -10 
property_list 
material 2
region 14
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-14
end_property_list 
<component> 24 
n_bounds 6
bounds 24 31 40 9 -38 -10 
property_list 
material 3
region 15
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-15
end_property_list 
<component> 25 
n_bounds 4
bounds 24 9 -40 -10 
property_list 
material 4
region 16
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-16
end_property_list 
<component> 26 
n_bounds 8
bounds 24 29 41 39 9 -42 -26 -10 
property_list 
material 2
region 17
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-17
end_property_list 
<component> 27 
n_bounds 6
bounds 24 31 43 9 -41 -10 
property_list 
material 3
region 18
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-18
end_property_list 
<component> 28 
n_bounds 4
bounds 24 9 -43 -10 
property_list 
material 4
region 19
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-19
end_property_list 
<component> 29 
n_bounds 8
bounds 24 29 44 42 9 -45 -26 -10 
property_list 
material 2
region 20
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-20
end_property_list 
<component> 30 
n_bounds 6
bounds 24 31 46 9 -44 -10 
property_list 
material 3
region 21
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-21
end_property_list 
<component> 31 
n_bounds 4
bounds 24 9 -46 -10 
property_list 
material 4
region 22
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-22
end_property_list 
<component> 32 
n_bounds 8
bounds 24 29 47 45 9 -48 -26 -10 
property_list 
material 2
region 23
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-23
end_property_list 
<component> 33 
n_bounds 6
bounds 24 31 49 9 -47 -10 
property_list 
material 3
region 24
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-24
end_property_list 
<component> 34 
n_bounds 4
bounds 24 9 -49 -10 
property_list 
material 4
region 25
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-25
end_property_list 
<component> 35 
n_bounds 8
bounds 26 23 52 51 9 -25 -50 -10 
property_list 
material 2
region 26
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-26
end_property_list 
<component> 36 
n_bounds 6
bounds 23 54 53 9 -51 -10 
property_list 
material 3
region 27
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-27
end_property_list 
<component> 37 
n_bounds 4
bounds 23 9 -53 -10 
property_list 
material 4
region 28
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-28
end_property_list 
<component> 38 
n_bounds 7
bounds 26 25 9 55 -27 -50 -10 
property_list 
material 2
region 29
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-29
end_property_list 
<component> 39 
n_bounds 4
bounds -55 -10 9 56 
property_list 
material 3
region 30
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-30
end_property_list 
<component> 40 
n_bounds 3
bounds -56 -10 9 
property_list 
material 4
region 31
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-31
end_property_list 
<component> 41 
n_bounds 7
bounds 26 27 9 57 -33 -50 -10 
property_list 
material 2
region 32
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-32
end_property_list 
<component> 42 
n_bounds 4
bounds -57 -10 9 58 
property_list 
material 3
region 33
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-33
end_property_list 
<component> 43 
n_bounds 3
bounds -58 -10 9 
property_list 
material 4
region 34
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-34
end_property_list 
<component> 44 
n_bounds 7
bounds 26 33 9 59 -36 -50 -10 
property_list 
material 2
region 35
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-35
end_property_list 
<component> 45 
n_bounds 4
bounds -59 -10 9 60 
property_list 
material 3
region 36
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-36
end_property_list 
<component> 46 
n_bounds 3
bounds -60 -10 9 
property_list 
material 4
region 37
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-37
end_property_list 
<component> 47 
n_bounds 7
bounds 26 36 9 61 -39 -50 -10 
property_list 
material 2
region 38
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-38
end_property_list 
<component> 48 
n_bounds 4
bounds -61 -10 9 62 
property_list 
material 3
region 39
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-39
end_property_list 
<component> 49 
n_bounds 3
bounds -62 -10 9 
property_list 
material 4
region 40
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-40
end_property_list 
<component> 50 
n_bounds 7
bounds 26 39 9 63 -42 -50 -10 
property_list 
material 2
region 41
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-41
end_property_list 
<component> 51 
n_bounds 4
bounds -63 -10 9 64 
property_list 
material 3
region 42
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-42
end_property_list 
<component> 52 
n_bounds 3
bounds -64 -10 9 
property_list 
material 4
region 43
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-43
end_property_list 
<component> 53 
n_bounds 7
bounds 26 42 9 65 -45 -50 -10 
property_list 
material 2
region 44
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-44
end_property_list 
<component> 54 
n_bounds 4
bounds -65 -10 9 66 
property_list 
material 3
region 45
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-45
end_property_list 
<component> 55 
n_bounds 3
bounds -66 -10 9 
property_list 
material 4
region 46
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-46
end_property_list 
<component> 56 
n_bounds 7
bounds 26 45 9 67 -48 -50 -10 
property_list 
material 2
region 47
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-47
end_property_list 
<component> 57 
n_bounds 4
bounds -67 -10 9 68 
property_list 
material 3
region 48
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-48
end_property_list 
<component> 58 
n_bounds 3
bounds -68 -10 9 
property_list 
material 4
region 49
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-49
end_property_list 
<component> 59 
n_bounds 8
bounds 50 23 52 70 9 -25 -69 -10 
property_list 
material 2
region 50
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-50
end_property_list 
<component> 60 
n_bounds 6
bounds 23 54 71 9 -70 -10 
property_list 
material 3
region 51
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-51
end_property_list 
<component> 61 
n_bounds 4
bounds 23 9 -71 -10 
property_list 
material 4
region 52
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-52
end_property_list 
<component> 62 
n_bounds 7
bounds 50 25 9 72 -27 -69 -10 
property_list 
material 2
region 53
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-53
end_property_list 
<component> 63 
n_bounds 4
bounds -72 -10 9 73 
property_list 
material 3
region 54
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-54
end_property_list 
<component> 64 
n_bounds 3
bounds -73 -10 9 
property_list 
material 4
region 55
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-55
end_property_list 
<component> 65 
n_bounds 6
bounds 50 27 9 -33 -69 -10 
property_list 
material 2
region 56
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-56
end_property_list 
<component> 66 
n_bounds 7
bounds 50 33 9 74 -36 -69 -10 
property_list 
material 2
region 57
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-57
end_property_list 
<component> 67 
n_bounds 4
bounds -74 -10 9 75 
property_list 
material 3
region 58
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-58
end_property_list 
<component> 68 
n_bounds 3
bounds -75 -10 9 
property_list 
material 4
region 59
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-59
end_property_list 
<component> 69 
n_bounds 7
bounds 50 36 9 76 -39 -69 -10 
property_list 
material 2
region 60
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-60
end_property_list 
<component> 70 
n_bounds 4
bounds -76 -10 9 77 
property_list 
material 3
region 61
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-61
end_property_list 
<component> 71 
n_bounds 3
bounds -77 -10 9 
property_list 
material 4
region 62
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-62
end_property_list 
<component> 72 
n_bounds 6
bounds 50 39 9 -42 -69 -10 
property_list 
material 2
region 63
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-63
end_property_list 
<component> 73 
n_bounds 7
bounds 50 42 9 78 -45 -69 -10 
property_list 
material 2
region 64
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-64
end_property_list 
<component> 74 
n_bounds 4
bounds -78 -10 9 79 
property_list 
material 3
region 65
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-65
end_property_list 
<component> 75 
n_bounds 3
bounds -79 -10 9 
property_list 
material 4
region 66
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-66
end_property_list 
<component> 76 
n_bounds 7
bounds 50 45 9 80 -48 -69 -10 
property_list 
material 2
region 67
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-67
end_property_list 
<component> 77 
n_bounds 4
bounds -80 -10 9 81 
property_list 
material 3
region 68
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-68
end_property_list 
<component> 78 
n_bounds 3
bounds -81 -10 9 
property_list 
material 4
region 69
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-69
end_property_list 
<component> 79 
n_bounds 8
bounds 69 23 52 83 9 -25 -82 -10 
property_list 
material 2
region 70
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-70
end_property_list 
<component> 80 
n_bounds 6
bounds 23 54 84 9 -83 -10 
property_list 
material 3
region 71
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-71
end_property_list 
<component> 81 
n_bounds 4
bounds 23 9 -84 -10 
property_list 
material 4
region 72
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-72
end_property_list 
<component> 82 
n_bounds 7
bounds 69 25 9 85 -27 -82 -10 
property_list 
material 2
region 73
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-73
end_property_list 
<component> 83 
n_bounds 4
bounds -85 -10 9 86 
property_list 
material 3
region 74
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-74
end_property_list 
<component> 84 
n_bounds 3
bounds -86 -10 9 
property_list 
material 4
region 75
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-75
end_property_list 
<component> 85 
n_bounds 7
bounds 69 27 9 87 -33 -82 -10 
property_list 
material 2
region 76
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-76
end_property_list 
<component> 86 
n_bounds 4
bounds -87 -10 9 88 
property_list 
material 3
region 77
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-77
end_property_list 
<component> 87 
n_bounds 3
bounds -88 -10 9 
property_list 
material 4
region 78
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-78
end_property_list 
<component> 88 
n_bounds 7
bounds 69 33 9 89 -36 -82 -10 
property_list 
material 2
region 79
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-79
end_property_list 
<component> 89 
n_bounds 4
bounds -89 -10 9 90 
property_list 
material 3
region 80
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-80
end_property_list 
<component> 90 
n_bounds 3
bounds -90 -10 9 
property_list 
material 4
region 81
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-81
end_property_list 
<component> 91 
n_bounds 7
bounds 69 36 9 91 -39 -82 -10 
property_list 
material 2
region 82
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-82
end_property_list 
<component> 92 
n_bounds 4
bounds -91 -10 9 92 
property_list 
material 3
region 83
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-83
end_property_list 
<component> 93 
n_bounds 3
bounds -92 -10 9 
property_list 
material 4
region 84
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-84
end_property_list 
<component> 94 
n_bounds 7
bounds 69 39 9 93 -42 -82 -10 
property_list 
material 2
region 85
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-85
end_property_list 
<component> 95 
n_bounds 4
bounds -93 -10 9 94 
property_list 
material 3
region 86
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-86
end_property_list 
<component> 96 
n_bounds 3
bounds -94 -10 9 
property_list 
material 4
region 87
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-87
end_property_list 
<component> 97 
n_bounds 7
bounds 69 42 9 95 -45 -82 -10 
property_list 
material 2
region 88
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-88
end_property_list 
<component> 98 
n_bounds 4
bounds -95 -10 9 96 
property_list 
material 3
region 89
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-89
end_property_list 
<component> 99 
n_bounds 3
bounds -96 -10 9 
property_list 
material 4
region 90
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-90
end_property_list 
<component> 100 
n_bounds 7
bounds 69 45 9 97 -48 -82 -10 
property_list 
material 2
region 91
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-91
end_property_list 
<component> 101 
n_bounds 4
bounds -97 -10 9 98 
property_list 
material 3
region 92
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-92
end_property_list 
<component> 102 
n_bounds 3
bounds -98 -10 9 
property_list 
material 4
region 93
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-93
end_property_list 
<component> 103 
n_bounds 8
bounds 82 23 52 100 9 -25 -99 -10 
property_list 
material 2
region 94
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-94
end_property_list 
<component> 104 
n_bounds 6
bounds 23 54 101 9 -100 -10 
property_list 
material 3
region 95
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-95
end_property_list 
<component> 105 
n_bounds 4
bounds 23 9 -101 -10 
property_list 
material 4
region 96
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-96
end_property_list 
<component> 106 
n_bounds 7
bounds 82 25 9 102 -27 -99 -10 
property_list 
material 2
region 97
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-97
end_property_list 
<component> 107 
n_bounds 4
bounds -102 -10 9 103 
property_list 
material 3
region 98
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-98
end_property_list 
<component> 108 
n_bounds 3
bounds -103 -10 9 
property_list 
material 4
region 99
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-99
end_property_list 
<component> 109 
n_bounds 7
bounds 82 27 9 104 -33 -99 -10 
property_list 
material 2
region 100
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-100
end_property_list 
<component> 110 
n_bounds 4
bounds -104 -10 9 105 
property_list 
material 3
region 101
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-101
end_property_list 
<component> 111 
n_bounds 3
bounds -105 -10 9 
property_list 
material 4
region 102
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-102
end_property_list 
<component> 112 
n_bounds 7
bounds 82 33 9 106 -36 -99 -10 
property_list 
material 2
region 103
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-103
end_property_list 
<component> 113 
n_bounds 4
bounds -106 -10 9 107 
property_list 
material 3
region 104
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-104
end_property_list 
<component> 114 
n_bounds 3
bounds -107 -10 9 
property_list 
material 4
region 105
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-105
end_property_list 
<component> 115 
n_bounds 6
bounds 82 36 9 -39 -99 -10 
property_list 
material 2
region 106
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-106
end_property_list 
<component> 116 
n_bounds 7
bounds 82 39 9 108 -42 -99 -10 
property_list 
material 2
region 107
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-107
end_property_list 
<component> 117 
n_bounds 4
bounds -108 -10 9 109 
property_list 
material 3
region 108
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-108
end_property_list 
<component> 118 
n_bounds 3
bounds -109 -10 9 
property_list 
material 4
region 109
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-109
end_property_list 
<component> 119 
n_bounds 7
bounds 82 42 9 110 -45 -99 -10 
property_list 
material 2
region 110
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-110
end_property_list 
<component> 120 
n_bounds 4
bounds -110 -10 9 111 
property_list 
material 3
region 111
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-111
end_property_list 
<component> 121 
n_bounds 3
bounds -111 -10 9 
property_list 
material 4
region 112
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-112
end_property_list 
<component> 122 
n_bounds 7
bounds 82 45 9 112 -48 -99 -10 
property_list 
material 2
region 113
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-113
end_property_list 
<component> 123 
n_bounds 4
bounds -112 -10 9 113 
property_list 
material 3
region 114
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-114
end_property_list 
<component> 124 
n_bounds 3
bounds -113 -10 9 
property_list 
material 4
region 115
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-115
end_property_list 
<component> 125 
n_bounds 8
bounds 99 23 52 115 9 -25 -114 -10 
property_list 
material 2
region 116
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-116
end_property_list 
<component> 126 
n_bounds 6
bounds 23 54 116 9 -115 -10 
property_list 
material 3
region 117
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-117
end_property_list 
<component> 127 
n_bounds 4
bounds 23 9 -116 -10 
property_list 
material 4
region 118
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-118
end_property_list 
<component> 128 
n_bounds 7
bounds 99 25 9 117 -27 -114 -10 
property_list 
material 2
region 119
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-119
end_property_list 
<component> 129 
n_bounds 4
bounds -117 -10 9 118 
property_list 
material 3
region 120
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-120
end_property_list 
<component> 130 
n_bounds 3
bounds -118 -10 9 
property_list 
material 4
region 121
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-121
end_property_list 
<component> 131 
n_bounds 6
bounds 99 27 9 -33 -114 -10 
property_list 
material 2
region 122
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-122
end_property_list 
<component> 132 
n_bounds 7
bounds 99 33 9 119 -36 -114 -10 
property_list 
material 2
region 123
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-123
end_property_list 
<component> 133 
n_bounds 4
bounds -119 -10 9 120 
property_list 
material 3
region 124
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-124
end_property_list 
<component> 134 
n_bounds 3
bounds -120 -10 9 
property_list 
material 4
region 125
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-125
end_property_list 
<component> 135 
n_bounds 7
bounds 99 36 9 121 -39 -114 -10 
property_list 
material 2
region 126
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-126
end_property_list 
<component> 136 
n_bounds 4
bounds -121 -10 9 122 
property_list 
material 3
region 127
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-127
end_property_list 
<component> 137 
n_bounds 3
bounds -122 -10 9 
property_list 
material 4
region 128
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-128
end_property_list 
<component> 138 
n_bounds 7
bounds 99 39 9 123 -42 -114 -10 
property_list 
material 2
region 129
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-129
end_property_list 
<component> 139 
n_bounds 4
bounds -123 -10 9 124 
property_list 
material 3
region 130
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-130
end_property_list 
<component> 140 
n_bounds 3
bounds -124 -10 9 
property_list 
material 4
region 131
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-131
end_property_list 
<component> 141 
n_bounds 7
bounds 99 42 9 125 -45 -114 -10 
property_list 
material 2
region 132
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-132
end_property_list 
<component> 142 
n_bounds 4
bounds -125 -10 9 126 
property_list 
material 3
region 133
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-133
end_property_list 
<component> 143 
n_bounds 3
bounds -126 -10 9 
property_list 
material 4
region 134
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-134
end_property_list 
<component> 144 
n_bounds 7
bounds 99 45 9 127 -48 -114 -10 
property_list 
material 2
region 135
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-135
end_property_list 
<component> 145 
n_bounds 4
bounds -127 -10 9 128 
property_list 
material 3
region 136
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-136
end_property_list 
<component> 146 
n_bounds 3
bounds -128 -10 9 
property_list 
material 4
region 137
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-137
end_property_list 
<component> 147 
n_bounds 8
bounds 114 23 52 130 9 -25 -129 -10 
property_list 
material 2
region 138
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-138
end_property_list 
<component> 148 
n_bounds 6
bounds 23 54 131 9 -130 -10 
property_list 
material 3
region 139
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-139
end_property_list 
<component> 149 
n_bounds 4
bounds 23 9 -131 -10 
property_list 
material 4
region 140
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-140
end_property_list 
<component> 150 
n_bounds 7
bounds 114 25 9 132 -27 -129 -10 
property_list 
material 2
region 141
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-141
end_property_list 
<component> 151 
n_bounds 4
bounds -132 -10 9 133 
property_list 
material 3
region 142
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-142
end_property_list 
<component> 152 
n_bounds 3
bounds -133 -10 9 
property_list 
material 4
region 143
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-143
end_property_list 
<component> 153 
n_bounds 7
bounds 114 27 9 134 -33 -129 -10 
property_list 
material 2
region 144
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-144
end_property_list 
<component> 154 
n_bounds 4
bounds -134 -10 9 135 
property_list 
material 3
region 145
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-145
end_property_list 
<component> 155 
n_bounds 3
bounds -135 -10 9 
property_list 
material 4
region 146
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-146
end_property_list 
<component> 156 
n_bounds 7
bounds 114 33 9 136 -36 -129 -10 
property_list 
material 2
region 147
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-147
end_property_list 
<component> 157 
n_bounds 4
bounds -136 -10 9 137 
property_list 
material 3
region 148
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-148
end_property_list 
<component> 158 
n_bounds 3
bounds -137 -10 9 
property_list 
material 4
region 149
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-149
end_property_list 
<component> 159 
n_bounds 7
bounds 114 36 9 138 -39 -129 -10 
property_list 
material 2
region 150
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-150
end_property_list 
<component> 160 
n_bounds 4
bounds -138 -10 9 139 
property_list 
material 3
region 151
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-151
end_property_list 
<component> 161 
n_bounds 3
bounds -139 -10 9 
property_list 
material 4
region 152
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-152
end_property_list 
<component> 162 
n_bounds 7
bounds 114 39 9 140 -42 -129 -10 
property_list 
material 2
region 153
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-153
end_property_list 
<component> 163 
n_bounds 4
bounds -140 -10 9 141 
property_list 
material 3
region 154
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-154
end_property_list 
<component> 164 
n_bounds 3
bounds -141 -10 9 
property_list 
material 4
region 155
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-155
end_property_list 
<component> 165 
n_bounds 7
bounds 114 42 9 142 -45 -129 -10 
property_list 
material 2
region 156
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-156
end_property_list 
<component> 166 
n_bounds 4
bounds -142 -10 9 143 
property_list 
material 3
region 157
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-157
end_property_list 
<component> 167 
n_bounds 3
bounds -143 -10 9 
property_list 
material 4
region 158
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-158
end_property_list 
<component> 168 
n_bounds 7
bounds 114 45 9 144 -48 -129 -10 
property_list 
material 2
region 159
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-159
end_property_list 
<component> 169 
n_bounds 4
bounds -144 -10 9 145 
property_list 
material 3
region 160
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-160
end_property_list 
<component> 170 
n_bounds 3
bounds -145 -10 9 
property_list 
material 4
region 161
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-161
end_property_list 
<component> 171 
n_bounds 8
bounds 129 23 52 147 9 -25 -146 -10 
property_list 
material 2
region 162
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-162
end_property_list 
<component> 172 
n_bounds 6
bounds 23 54 148 9 -147 -10 
property_list 
material 3
region 163
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-163
end_property_list 
<component> 173 
n_bounds 4
bounds 23 9 -148 -10 
property_list 
material 4
region 164
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-164
end_property_list 
<component> 174 
n_bounds 7
bounds 129 25 9 149 -27 -146 -10 
property_list 
material 2
region 165
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-165
end_property_list 
<component> 175 
n_bounds 4
bounds -149 -10 9 150 
property_list 
material 3
region 166
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-166
end_property_list 
<component> 176 
n_bounds 3
bounds -150 -10 9 
property_list 
material 4
region 167
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-167
end_property_list 
<component> 177 
n_bounds 7
bounds 129 27 9 151 -33 -146 -10 
property_list 
material 2
region 168
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-168
end_property_list 
<component> 178 
n_bounds 4
bounds -151 -10 9 152 
property_list 
material 3
region 169
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-169
end_property_list 
<component> 179 
n_bounds 3
bounds -152 -10 9 
property_list 
material 4
region 170
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-170
end_property_list 
<component> 180 
n_bounds 7
bounds 129 33 9 153 -36 -146 -10 
property_list 
material 2
region 171
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-171
end_property_list 
<component> 181 
n_bounds 4
bounds -153 -10 9 154 
property_list 
material 3
region 172
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-172
end_property_list 
<component> 182 
n_bounds 3
bounds -154 -10 9 
property_list 
material 4
region 173
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-173
end_property_list 
<component> 183 
n_bounds 7
bounds 129 36 9 155 -39 -146 -10 
property_list 
material 2
region 174
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-174
end_property_list 
<component> 184 
n_bounds 4
bounds -155 -10 9 156 
property_list 
material 3
region 175
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-175
end_property_list 
<component> 185 
n_bounds 3
bounds -156 -10 9 
property_list 
material 4
region 176
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-176
end_property_list 
<component> 186 
n_bounds 7
bounds 129 39 9 157 -42 -146 -10 
property_list 
material 2
region 177
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-177
end_property_list 
<component> 187 
n_bounds 4
bounds -157 -10 9 158 
property_list 
material 3
region 178
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-178
end_property_list 
<component> 188 
n_bounds 3
bounds -158 -10 9 
property_list 
material 4
region 179
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-179
end_property_list 
<component> 189 
n_bounds 7
bounds 129 42 9 159 -45 -146 -10 
property_list 
material 2
region 180
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-180
end_property_list 
<component> 190 
n_bounds 4
bounds -159 -10 9 160 
property_list 
material 3
region 181
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-181
end_property_list 
<component> 191 
n_bounds 3
bounds -160 -10 9 
property_list 
material 4
region 182
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-182
end_property_list 
<component> 192 
n_bounds 7
bounds 129 45 9 161 -48 -146 -10 
property_list 
material 2
region 183
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-183
end_property_list 
<component> 193 
n_bounds 4
bounds -161 -10 9 162 
property_list 
material 3
region 184
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-184
end_property_list 
<component> 194 
n_bounds 3
bounds -162 -10 9 
property_list 
material 4
region 185
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-185
end_property_list 
<component> 195 
n_bounds 8
bounds 24 29 163 48 9 -164 -26 -10 
property_list 
material 2
region 186
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-186
end_property_list 
<component> 196 
n_bounds 6
bounds 24 31 165 9 -163 -10 
property_list 
material 3
region 187
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-187
end_property_list 
<component> 197 
n_bounds 4
bounds 24 9 -165 -10 
property_list 
material 4
region 188
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-188
end_property_list 
<component> 198 
n_bounds 8
bounds 24 29 166 164 9 -167 -26 -10 
property_list 
material 2
region 189
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-189
end_property_list 
<component> 199 
n_bounds 6
bounds 24 31 168 9 -166 -10 
property_list 
material 3
region 190
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-190
end_property_list 
<component> 200 
n_bounds 4
bounds 24 9 -168 -10 
property_list 
material 4
region 191
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-191
end_property_list 
<component> 201 
n_bounds 8
bounds 24 29 169 167 9 -12 -26 -10 
property_list 
material 2
region 192
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-192
end_property_list 
<component> 202 
n_bounds 6
bounds 24 31 170 9 -169 -10 
property_list 
material 3
region 193
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-193
end_property_list 
<component> 203 
n_bounds 4
bounds 24 9 -170 -10 
property_list 
material 4
region 194
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-194
end_property_list 
<component> 204 
n_bounds 8
bounds 24 29 171 12 9 -172 -26 -10 
property_list 
material 2
region 195
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-195
end_property_list 
<component> 205 
n_bounds 6
bounds 24 31 173 9 -171 -10 
property_list 
material 3
region 196
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-196
end_property_list 
<component> 206 
n_bounds 4
bounds 24 9 -173 -10 
property_list 
material 4
region 197
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-197
end_property_list 
<component> 207 
n_bounds 8
bounds 24 29 174 172 9 -175 -26 -10 
property_list 
material 2
region 198
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-198
end_property_list 
<component> 208 
n_bounds 6
bounds 24 31 176 9 -174 -10 
property_list 
material 3
region 199
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-199
end_property_list 
<component> 209 
n_bounds 4
bounds 24 9 -176 -10 
property_list 
material 4
region 200
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-200
end_property_list 
<component> 210 
n_bounds 8
bounds 24 29 177 175 9 -178 -26 -10 
property_list 
material 2
region 201
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-201
end_property_list 
<component> 211 
n_bounds 6
bounds 24 31 179 9 -177 -10 
property_list 
material 3
region 202
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-202
end_property_list 
<component> 212 
n_bounds 4
bounds 24 9 -179 -10 
property_list 
material 4
region 203
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-203
end_property_list 
<component> 213 
n_bounds 8
bounds 24 29 180 178 9 -181 -26 -10 
property_list 
material 2
region 204
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-204
end_property_list 
<component> 214 
n_bounds 6
bounds 24 31 182 9 -180 -10 
property_list 
material 3
region 205
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-205
end_property_list 
<component> 215 
n_bounds 4
bounds 24 9 -182 -10 
property_list 
material 4
region 206
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-206
end_property_list 
<component> 216 
n_bounds 6
bounds 24 181 9 -183 -26 -10 
property_list 
material 2
region 207
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-207
end_property_list 
<component> 217 
n_bounds 8
bounds 24 29 184 183 9 -185 -26 -10 
property_list 
material 2
region 208
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-208
end_property_list 
<component> 218 
n_bounds 6
bounds 24 31 186 9 -184 -10 
property_list 
material 3
region 209
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-209
end_property_list 
<component> 219 
n_bounds 4
bounds 24 9 -186 -10 
property_list 
material 4
region 210
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-210
end_property_list 
<component> 220 
n_bounds 8
bounds 24 29 187 185 9 -188 -26 -10 
property_list 
material 2
region 211
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-211
end_property_list 
<component> 221 
n_bounds 6
bounds 24 31 189 9 -187 -10 
property_list 
material 3
region 212
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-212
end_property_list 
<component> 222 
n_bounds 4
bounds 24 9 -189 -10 
property_list 
material 4
region 213
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-213
end_property_list 
<component> 223 
n_bounds 8
bounds 24 29 190 188 9 -191 -26 -10 
property_list 
material 2
region 214
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-214
end_property_list 
<component> 224 
n_bounds 6
bounds 24 31 192 9 -190 -10 
property_list 
material 3
region 215
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-215
end_property_list 
<component> 225 
n_bounds 4
bounds 24 9 -192 -10 
property_list 
material 4
region 216
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-216
end_property_list 
<component> 226 
n_bounds 8
bounds 24 29 193 191 9 -194 -26 -10 
property_list 
material 2
region 217
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-217
end_property_list 
<component> 227 
n_bounds 6
bounds 24 31 195 9 -193 -10 
property_list 
material 3
region 218
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-218
end_property_list 
<component> 228 
n_bounds 4
bounds 24 9 -195 -10 
property_list 
material 4
region 219
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-219
end_property_list 
<component> 229 
n_bounds 8
bounds 24 29 196 194 9 -15 -26 -10 
property_list 
material 2
region 220
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-220
end_property_list 
<component> 230 
n_bounds 6
bounds 24 31 197 9 -196 -10 
property_list 
material 3
region 221
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-221
end_property_list 
<component> 231 
n_bounds 4
bounds 24 9 -197 -10 
property_list 
material 4
region 222
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-222
end_property_list 
<component> 232 
n_bounds 8
bounds 24 29 198 15 9 -199 -26 -10 
property_list 
material 2
region 223
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-223
end_property_list 
<component> 233 
n_bounds 6
bounds 24 31 200 9 -198 -10 
property_list 
material 3
region 224
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-224
end_property_list 
<component> 234 
n_bounds 4
bounds 24 9 -200 -10 
property_list 
material 4
region 225
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-225
end_property_list 
<component> 235 
n_bounds 8
bounds 24 29 201 199 9 -202 -26 -10 
property_list 
material 2
region 226
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-226
end_property_list 
<component> 236 
n_bounds 6
bounds 24 31 203 9 -201 -10 
property_list 
material 3
region 227
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-227
end_property_list 
<component> 237 
n_bounds 4
bounds 24 9 -203 -10 
property_list 
material 4
region 228
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-228
end_property_list 
<component> 238 
n_bounds 7
bounds 26 48 9 204 -164 -50 -10 
property_list 
material 2
region 229
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-229
end_property_list 
<component> 239 
n_bounds 4
bounds -204 -10 9 205 
property_list 
material 3
region 230
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-230
end_property_list 
<component> 240 
n_bounds 3
bounds -205 -10 9 
property_list 
material 4
region 231
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-231
end_property_list 
<component> 241 
n_bounds 7
bounds 26 164 9 206 -167 -50 -10 
property_list 
material 2
region 232
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-232
end_property_list 
<component> 242 
n_bounds 4
bounds -206 -10 9 207 
property_list 
material 3
region 233
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-233
end_property_list 
<component> 243 
n_bounds 3
bounds -207 -10 9 
property_list 
material 4
region 234
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-234
end_property_list 
<component> 244 
n_bounds 7
bounds 26 167 9 208 -12 -50 -10 
property_list 
material 2
region 235
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-235
end_property_list 
<component> 245 
n_bounds 4
bounds -208 -10 9 209 
property_list 
material 3
region 236
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-236
end_property_list 
<component> 246 
n_bounds 3
bounds -209 -10 9 
property_list 
material 4
region 237
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-237
end_property_list 
<component> 247 
n_bounds 7
bounds 26 12 9 210 -172 -50 -10 
property_list 
material 2
region 238
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-238
end_property_list 
<component> 248 
n_bounds 4
bounds -210 -10 9 211 
property_list 
material 3
region 239
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-239
end_property_list 
<component> 249 
n_bounds 3
bounds -211 -10 9 
property_list 
material 4
region 240
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-240
end_property_list 
<component> 250 
n_bounds 7
bounds 26 172 9 212 -175 -50 -10 
property_list 
material 2
region 241
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-241
end_property_list 
<component> 251 
n_bounds 4
bounds -212 -10 9 213 
property_list 
material 3
region 242
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-242
end_property_list 
<component> 252 
n_bounds 3
bounds -213 -10 9 
property_list 
material 4
region 243
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-243
end_property_list 
<component> 253 
n_bounds 7
bounds 26 175 9 214 -178 -50 -10 
property_list 
material 2
region 244
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-244
end_property_list 
<component> 254 
n_bounds 4
bounds -214 -10 9 215 
property_list 
material 3
region 245
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-245
end_property_list 
<component> 255 
n_bounds 3
bounds -215 -10 9 
property_list 
material 4
region 246
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-246
end_property_list 
<component> 256 
n_bounds 7
bounds 26 178 9 216 -181 -50 -10 
property_list 
material 2
region 247
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-247
end_property_list 
<component> 257 
n_bounds 4
bounds -216 -10 9 217 
property_list 
material 3
region 248
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-248
end_property_list 
<component> 258 
n_bounds 3
bounds -217 -10 9 
property_list 
material 4
region 249
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-249
end_property_list 
<component> 259 
n_bounds 7
bounds 26 181 9 218 -183 -50 -10 
property_list 
material 2
region 250
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-250
end_property_list 
<component> 260 
n_bounds 4
bounds -218 -10 9 219 
property_list 
material 3
region 251
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-251
end_property_list 
<component> 261 
n_bounds 3
bounds -219 -10 9 
property_list 
material 4
region 252
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-252
end_property_list 
<component> 262 
n_bounds 7
bounds 26 183 9 220 -185 -50 -10 
property_list 
material 2
region 253
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-253
end_property_list 
<component> 263 
n_bounds 4
bounds -220 -10 9 221 
property_list 
material 3
region 254
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-254
end_property_list 
<component> 264 
n_bounds 3
bounds -221 -10 9 
property_list 
material 4
region 255
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-255
end_property_list 
<component> 265 
n_bounds 7
bounds 26 185 9 222 -188 -50 -10 
property_list 
material 2
region 256
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-256
end_property_list 
<component> 266 
n_bounds 4
bounds -222 -10 9 223 
property_list 
material 3
region 257
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-257
end_property_list 
<component> 267 
n_bounds 3
bounds -223 -10 9 
property_list 
material 4
region 258
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-258
end_property_list 
<component> 268 
n_bounds 7
bounds 26 188 9 224 -191 -50 -10 
property_list 
material 2
region 259
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-259
end_property_list 
<component> 269 
n_bounds 4
bounds -224 -10 9 225 
property_list 
material 3
region 260
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-260
end_property_list 
<component> 270 
n_bounds 3
bounds -225 -10 9 
property_list 
material 4
region 261
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-261
end_property_list 
<component> 271 
n_bounds 7
bounds 26 191 9 226 -194 -50 -10 
property_list 
material 2
region 262
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-262
end_property_list 
<component> 272 
n_bounds 4
bounds -226 -10 9 227 
property_list 
material 3
region 263
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-263
end_property_list 
<component> 273 
n_bounds 3
bounds -227 -10 9 
property_list 
material 4
region 264
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-264
end_property_list 
<component> 274 
n_bounds 7
bounds 26 194 9 228 -15 -50 -10 
property_list 
material 2
region 265
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-265
end_property_list 
<component> 275 
n_bounds 4
bounds -228 -10 9 229 
property_list 
material 3
region 266
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-266
end_property_list 
<component> 276 
n_bounds 3
bounds -229 -10 9 
property_list 
material 4
region 267
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-267
end_property_list 
<component> 277 
n_bounds 7
bounds 26 15 9 230 -199 -50 -10 
property_list 
material 2
region 268
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-268
end_property_list 
<component> 278 
n_bounds 4
bounds -230 -10 9 231 
property_list 
material 3
region 269
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-269
end_property_list 
<component> 279 
n_bounds 3
bounds -231 -10 9 
property_list 
material 4
region 270
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-270
end_property_list 
<component> 280 
n_bounds 7
bounds 26 199 9 232 -202 -50 -10 
property_list 
material 2
region 271
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-271
end_property_list 
<component> 281 
n_bounds 4
bounds -232 -10 9 233 
property_list 
material 3
region 272
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-272
end_property_list 
<component> 282 
n_bounds 3
bounds -233 -10 9 
property_list 
material 4
region 273
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-273
end_property_list 
<component> 283 
n_bounds 7
bounds 50 48 9 234 -164 -69 -10 
property_list 
material 2
region 274
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-274
end_property_list 
<component> 284 
n_bounds 4
bounds -234 -10 9 235 
property_list 
material 3
region 275
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-275
end_property_list 
<component> 285 
n_bounds 3
bounds -235 -10 9 
property_list 
material 4
region 276
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-276
end_property_list 
<component> 286 
n_bounds 7
bounds 50 164 9 236 -167 -69 -10 
property_list 
material 2
region 277
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-277
end_property_list 
<component> 287 
n_bounds 4
bounds -236 -10 9 237 
property_list 
material 3
region 278
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-278
end_property_list 
<component> 288 
n_bounds 3
bounds -237 -10 9 
property_list 
material 4
region 279
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-279
end_property_list 
<component> 289 
n_bounds 6
bounds 50 167 9 -12 -69 -10 
property_list 
material 2
region 280
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-280
end_property_list 
<component> 290 
n_bounds 7
bounds 50 12 9 238 -172 -69 -10 
property_list 
material 2
region 281
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-281
end_property_list 
<component> 291 
n_bounds 4
bounds -238 -10 9 239 
property_list 
material 3
region 282
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-282
end_property_list 
<component> 292 
n_bounds 3
bounds -239 -10 9 
property_list 
material 4
region 283
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-283
end_property_list 
<component> 293 
n_bounds 7
bounds 50 172 9 240 -175 -69 -10 
property_list 
material 2
region 284
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-284
end_property_list 
<component> 294 
n_bounds 4
bounds -240 -10 9 241 
property_list 
material 3
region 285
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-285
end_property_list 
<component> 295 
n_bounds 3
bounds -241 -10 9 
property_list 
material 4
region 286
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-286
end_property_list 
<component> 296 
n_bounds 6
bounds 50 175 9 -178 -69 -10 
property_list 
material 2
region 287
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-287
end_property_list 
<component> 297 
n_bounds 7
bounds 50 178 9 242 -181 -69 -10 
property_list 
material 2
region 288
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-288
end_property_list 
<component> 298 
n_bounds 4
bounds -242 -10 9 243 
property_list 
material 3
region 289
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-289
end_property_list 
<component> 299 
n_bounds 3
bounds -243 -10 9 
property_list 
material 4
region 290
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-290
end_property_list 
<component> 300 
n_bounds 7
bounds 50 181 9 244 -183 -69 -10 
property_list 
material 2
region 291
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-291
end_property_list 
<component> 301 
n_bounds 4
bounds -244 -10 9 245 
property_list 
material 3
region 292
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-292
end_property_list 
<component> 302 
n_bounds 3
bounds -245 -10 9 
property_list 
material 4
region 293
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-293
end_property_list 
<component> 303 
n_bounds 7
bounds 50 183 9 246 -185 -69 -10 
property_list 
material 2
region 294
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-294
end_property_list 
<component> 304 
n_bounds 4
bounds -246 -10 9 247 
property_list 
material 3
region 295
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-295
end_property_list 
<component> 305 
n_bounds 3
bounds -247 -10 9 
property_list 
material 4
region 296
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-296
end_property_list 
<component> 306 
n_bounds 6
bounds 50 185 9 -188 -69 -10 
property_list 
material 2
region 297
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-297
end_property_list 
<component> 307 
n_bounds 7
bounds 50 188 9 248 -191 -69 -10 
property_list 
material 2
region 298
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-298
end_property_list 
<component> 308 
n_bounds 4
bounds -248 -10 9 249 
property_list 
material 3
region 299
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-299
end_property_list 
<component> 309 
n_bounds 3
bounds -249 -10 9 
property_list 
material 4
region 300
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-300
end_property_list 
<component> 310 
n_bounds 7
bounds 50 191 9 250 -194 -69 -10 
property_list 
material 2
region 301
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-301
end_property_list 
<component> 311 
n_bounds 4
bounds -250 -10 9 251 
property_list 
material 3
region 302
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-302
end_property_list 
<component> 312 
n_bounds 3
bounds -251 -10 9 
property_list 
material 4
region 303
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-303
end_property_list 
<component> 313 
n_bounds 6
bounds 50 194 9 -15 -69 -10 
property_list 
material 2
region 304
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-304
end_property_list 
<component> 314 
n_bounds 7
bounds 50 15 9 252 -199 -69 -10 
property_list 
material 2
region 305
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-305
end_property_list 
<component> 315 
n_bounds 4
bounds -252 -10 9 253 
property_list 
material 3
region 306
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-306
end_property_list 
<component> 316 
n_bounds 3
bounds -253 -10 9 
property_list 
material 4
region 307
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-307
end_property_list 
<component> 317 
n_bounds 7
bounds 50 199 9 254 -202 -69 -10 
property_list 
material 2
region 308
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-308
end_property_list 
<component> 318 
n_bounds 4
bounds -254 -10 9 255 
property_list 
material 3
region 309
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-309
end_property_list 
<component> 319 
n_bounds 3
bounds -255 -10 9 
property_list 
material 4
region 310
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-310
end_property_list 
<component> 320 
n_bounds 7
bounds 69 48 9 256 -164 -82 -10 
property_list 
material 2
region 311
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-311
end_property_list 
<component> 321 
n_bounds 4
bounds -256 -10 9 257 
property_list 
material 3
region 312
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-312
end_property_list 
<component> 322 
n_bounds 3
bounds -257 -10 9 
property_list 
material 4
region 313
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-313
end_property_list 
<component> 323 
n_bounds 7
bounds 69 164 9 258 -167 -82 -10 
property_list 
material 2
region 314
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-314
end_property_list 
<component> 324 
n_bounds 4
bounds -258 -10 9 259 
property_list 
material 3
region 315
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-315
end_property_list 
<component> 325 
n_bounds 3
bounds -259 -10 9 
property_list 
material 4
region 316
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-316
end_property_list 
<component> 326 
n_bounds 7
bounds 69 167 9 260 -12 -82 -10 
property_list 
material 2
region 317
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-317
end_property_list 
<component> 327 
n_bounds 4
bounds -260 -10 9 261 
property_list 
material 3
region 318
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-318
end_property_list 
<component> 328 
n_bounds 3
bounds -261 -10 9 
property_list 
material 4
region 319
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-319
end_property_list 
<component> 329 
n_bounds 7
bounds 69 12 9 262 -172 -82 -10 
property_list 
material 2
region 320
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-320
end_property_list 
<component> 330 
n_bounds 4
bounds -262 -10 9 263 
property_list 
material 3
region 321
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-321
end_property_list 
<component> 331 
n_bounds 3
bounds -263 -10 9 
property_list 
material 4
region 322
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-322
end_property_list 
<component> 332 
n_bounds 7
bounds 69 172 9 264 -175 -82 -10 
property_list 
material 2
region 323
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-323
end_property_list 
<component> 333 
n_bounds 4
bounds -264 -10 9 265 
property_list 
material 3
region 324
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-324
end_property_list 
<component> 334 
n_bounds 3
bounds -265 -10 9 
property_list 
material 4
region 325
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-325
end_property_list 
<component> 335 
n_bounds 7
bounds 69 175 9 266 -178 -82 -10 
property_list 
material 2
region 326
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-326
end_property_list 
<component> 336 
n_bounds 4
bounds -266 -10 9 267 
property_list 
material 3
region 327
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-327
end_property_list 
<component> 337 
n_bounds 3
bounds -267 -10 9 
property_list 
material 4
region 328
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-328
end_property_list 
<component> 338 
n_bounds 7
bounds 69 178 9 268 -181 -82 -10 
property_list 
material 2
region 329
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-329
end_property_list 
<component> 339 
n_bounds 4
bounds -268 -10 9 269 
property_list 
material 3
region 330
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-330
end_property_list 
<component> 340 
n_bounds 3
bounds -269 -10 9 
property_list 
material 4
region 331
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-331
end_property_list 
<component> 341 
n_bounds 7
bounds 69 181 9 270 -183 -82 -10 
property_list 
material 2
region 332
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-332
end_property_list 
<component> 342 
n_bounds 4
bounds -270 -10 9 271 
property_list 
material 3
region 333
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-333
end_property_list 
<component> 343 
n_bounds 3
bounds -271 -10 9 
property_list 
material 4
region 334
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-334
end_property_list 
<component> 344 
n_bounds 7
bounds 69 183 9 272 -185 -82 -10 
property_list 
material 2
region 335
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-335
end_property_list 
<component> 345 
n_bounds 4
bounds -272 -10 9 273 
property_list 
material 3
region 336
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-336
end_property_list 
<component> 346 
n_bounds 3
bounds -273 -10 9 
property_list 
material 4
region 337
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-337
end_property_list 
<component> 347 
n_bounds 7
bounds 69 185 9 274 -188 -82 -10 
property_list 
material 2
region 338
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-338
end_property_list 
<component> 348 
n_bounds 4
bounds -274 -10 9 275 
property_list 
material 3
region 339
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-339
end_property_list 
<component> 349 
n_bounds 3
bounds -275 -10 9 
property_list 
material 4
region 340
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-340
end_property_list 
<component> 350 
n_bounds 7
bounds 69 188 9 276 -191 -82 -10 
property_list 
material 2
region 341
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-341
end_property_list 
<component> 351 
n_bounds 4
bounds -276 -10 9 277 
property_list 
material 3
region 342
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-342
end_property_list 
<component> 352 
n_bounds 3
bounds -277 -10 9 
property_list 
material 4
region 343
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-343
end_property_list 
<component> 353 
n_bounds 7
bounds 69 191 9 278 -194 -82 -10 
property_list 
material 2
region 344
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-344
end_property_list 
<component> 354 
n_bounds 4
bounds -278 -10 9 279 
property_list 
material 3
region 345
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-345
end_property_list 
<component> 355 
n_bounds 3
bounds -279 -10 9 
property_list 
material 4
region 346
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-346
end_property_list 
<component> 356 
n_bounds 7
bounds 69 194 9 280 -15 -82 -10 
property_list 
material 2
region 347
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-347
end_property_list 
<component> 357 
n_bounds 4
bounds -280 -10 9 281 
property_list 
material 3
region 348
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-348
end_property_list 
<component> 358 
n_bounds 3
bounds -281 -10 9 
property_list 
material 4
region 349
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-349
end_property_list 
<component> 359 
n_bounds 7
bounds 69 15 9 282 -199 -82 -10 
property_list 
material 2
region 350
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-350
end_property_list 
<component> 360 
n_bounds 4
bounds -282 -10 9 283 
property_list 
material 3
region 351
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-351
end_property_list 
<component> 361 
n_bounds 3
bounds -283 -10 9 
property_list 
material 4
region 352
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-352
end_property_list 
<component> 362 
n_bounds 7
bounds 69 199 9 284 -202 -82 -10 
property_list 
material 2
region 353
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-353
end_property_list 
<component> 363 
n_bounds 4
bounds -284 -10 9 285 
property_list 
material 3
region 354
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-354
end_property_list 
<component> 364 
n_bounds 3
bounds -285 -10 9 
property_list 
material 4
region 355
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-355
end_property_list 
<component> 365 
n_bounds 7
bounds 82 48 9 286 -164 -99 -10 
property_list 
material 2
region 356
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-356
end_property_list 
<component> 366 
n_bounds 4
bounds -286 -10 9 287 
property_list 
material 3
region 357
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-357
end_property_list 
<component> 367 
n_bounds 3
bounds -287 -10 9 
property_list 
material 4
region 358
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-358
end_property_list 
<component> 368 
n_bounds 7
bounds 82 164 9 288 -167 -99 -10 
property_list 
material 2
region 359
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-359
end_property_list 
<component> 369 
n_bounds 4
bounds -288 -10 9 289 
property_list 
material 3
region 360
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-360
end_property_list 
<component> 370 
n_bounds 3
bounds -289 -10 9 
property_list 
material 4
region 361
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-361
end_property_list 
<component> 371 
n_bounds 7
bounds 82 167 9 290 -12 -99 -10 
property_list 
material 2
region 362
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-362
end_property_list 
<component> 372 
n_bounds 4
bounds -290 -10 9 291 
property_list 
material 3
region 363
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-363
end_property_list 
<component> 373 
n_bounds 3
bounds -291 -10 9 
property_list 
material 4
region 364
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-364
end_property_list 
<component> 374 
n_bounds 6
bounds 82 12 9 -172 -99 -10 
property_list 
material 2
region 365
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-365
end_property_list 
<component> 375 
n_bounds 7
bounds 82 172 9 292 -175 -99 -10 
property_list 
material 2
region 366
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-366
end_property_list 
<component> 376 
n_bounds 4
bounds -292 -10 9 293 
property_list 
material 3
region 367
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-367
end_property_list 
<component> 377 
n_bounds 3
bounds -293 -10 9 
property_list 
material 4
region 368
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-368
end_property_list 
<component> 378 
n_bounds 7
bounds 82 175 9 294 -178 -99 -10 
property_list 
material 2
region 369
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-369
end_property_list 
<component> 379 
n_bounds 4
bounds -294 -10 9 295 
property_list 
material 3
region 370
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-370
end_property_list 
<component> 380 
n_bounds 3
bounds -295 -10 9 
property_list 
material 4
region 371
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-371
end_property_list 
<component> 381 
n_bounds 7
bounds 82 178 9 296 -181 -99 -10 
property_list 
material 2
region 372
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-372
end_property_list 
<component> 382 
n_bounds 4
bounds -296 -10 9 297 
property_list 
material 3
region 373
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-373
end_property_list 
<component> 383 
n_bounds 3
bounds -297 -10 9 
property_list 
material 4
region 374
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-374
end_property_list 
<component> 384 
n_bounds 7
bounds 82 181 9 298 -183 -99 -10 
property_list 
material 2
region 375
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-375
end_property_list 
<component> 385 
n_bounds 4
bounds -298 -10 9 299 
property_list 
material 3
region 376
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-376
end_property_list 
<component> 386 
n_bounds 3
bounds -299 -10 9 
property_list 
material 4
region 377
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-377
end_property_list 
<component> 387 
n_bounds 7
bounds 82 183 9 300 -185 -99 -10 
property_list 
material 2
region 378
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-378
end_property_list 
<component> 388 
n_bounds 4
bounds -300 -10 9 301 
property_list 
material 3
region 379
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-379
end_property_list 
<component> 389 
n_bounds 3
bounds -301 -10 9 
property_list 
material 4
region 380
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-380
end_property_list 
<component> 390 
n_bounds 7
bounds 82 185 9 302 -188 -99 -10 
property_list 
material 2
region 381
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-381
end_property_list 
<component> 391 
n_bounds 4
bounds -302 -10 9 303 
property_list 
material 3
region 382
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-382
end_property_list 
<component> 392 
n_bounds 3
bounds -303 -10 9 
property_list 
material 4
region 383
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-383
end_property_list 
<component> 393 
n_bounds 7
bounds 82 188 9 304 -191 -99 -10 
property_list 
material 2
region 384
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-384
end_property_list 
<component> 394 
n_bounds 4
bounds -304 -10 9 305 
property_list 
material 3
region 385
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-385
end_property_list 
<component> 395 
n_bounds 3
bounds -305 -10 9 
property_list 
material 4
region 386
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-386
end_property_list 
<component> 396 
n_bounds 6
bounds 82 191 9 -194 -99 -10 
property_list 
material 2
region 387
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-387
end_property_list 
<component> 397 
n_bounds 7
bounds 82 194 9 306 -15 -99 -10 
property_list 
material 2
region 388
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-388
end_property_list 
<component> 398 
n_bounds 4
bounds -306 -10 9 307 
property_list 
material 3
region 389
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-389
end_property_list 
<component> 399 
n_bounds 3
bounds -307 -10 9 
property_list 
material 4
region 390
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-390
end_property_list 
<component> 400 
n_bounds 7
bounds 82 15 9 308 -199 -99 -10 
property_list 
material 2
region 391
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-391
end_property_list 
<component> 401 
n_bounds 4
bounds -308 -10 9 309 
property_list 
material 3
region 392
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-392
end_property_list 
<component> 402 
n_bounds 3
bounds -309 -10 9 
property_list 
material 4
region 393
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-393
end_property_list 
<component> 403 
n_bounds 7
bounds 82 199 9 310 -202 -99 -10 
property_list 
material 2
region 394
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-394
end_property_list 
<component> 404 
n_bounds 4
bounds -310 -10 9 311 
property_list 
material 3
region 395
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-395
end_property_list 
<component> 405 
n_bounds 3
bounds -311 -10 9 
property_list 
material 4
region 396
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-396
end_property_list 
<component> 406 
n_bounds 7
bounds 99 48 9 312 -164 -114 -10 
property_list 
material 2
region 397
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-397
end_property_list 
<component> 407 
n_bounds 4
bounds -312 -10 9 313 
property_list 
material 3
region 398
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-398
end_property_list 
<component> 408 
n_bounds 3
bounds -313 -10 9 
property_list 
material 4
region 399
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-399
end_property_list 
<component> 409 
n_bounds 7
bounds 99 164 9 314 -167 -114 -10 
property_list 
material 2
region 400
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-400
end_property_list 
<component> 410 
n_bounds 4
bounds -314 -10 9 315 
property_list 
material 3
region 401
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-401
end_property_list 
<component> 411 
n_bounds 3
bounds -315 -10 9 
property_list 
material 4
region 402
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-402
end_property_list 
<component> 412 
n_bounds 7
bounds 99 167 9 316 -12 -114 -10 
property_list 
material 2
region 403
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-403
end_property_list 
<component> 413 
n_bounds 4
bounds -316 -10 9 317 
property_list 
material 3
region 404
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-404
end_property_list 
<component> 414 
n_bounds 3
bounds -317 -10 9 
property_list 
material 4
region 405
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-405
end_property_list 
<component> 415 
n_bounds 7
bounds 99 12 9 318 -172 -114 -10 
property_list 
material 2
region 406
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-406
end_property_list 
<component> 416 
n_bounds 4
bounds -318 -10 9 319 
property_list 
material 3
region 407
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-407
end_property_list 
<component> 417 
n_bounds 3
bounds -319 -10 9 
property_list 
material 4
region 408
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-408
end_property_list 
<component> 418 
n_bounds 7
bounds 99 172 9 320 -175 -114 -10 
property_list 
material 2
region 409
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-409
end_property_list 
<component> 419 
n_bounds 4
bounds -320 -10 9 321 
property_list 
material 3
region 410
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-410
end_property_list 
<component> 420 
n_bounds 3
bounds -321 -10 9 
property_list 
material 4
region 411
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-411
end_property_list 
<component> 421 
n_bounds 6
bounds 99 175 9 -178 -114 -10 
property_list 
material 2
region 412
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-412
end_property_list 
<component> 422 
n_bounds 7
bounds 99 178 9 322 -181 -114 -10 
property_list 
material 2
region 413
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-413
end_property_list 
<component> 423 
n_bounds 4
bounds -322 -10 9 323 
property_list 
material 3
region 414
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-414
end_property_list 
<component> 424 
n_bounds 3
bounds -323 -10 9 
property_list 
material 4
region 415
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-415
end_property_list 
<component> 425 
n_bounds 7
bounds 99 181 9 324 -183 -114 -10 
property_list 
material 2
region 416
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-416
end_property_list 
<component> 426 
n_bounds 4
bounds -324 -10 9 325 
property_list 
material 3
region 417
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-417
end_property_list 
<component> 427 
n_bounds 3
bounds -325 -10 9 
property_list 
material 4
region 418
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-418
end_property_list 
<component> 428 
n_bounds 7
bounds 99 183 9 326 -185 -114 -10 
property_list 
material 2
region 419
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-419
end_property_list 
<component> 429 
n_bounds 4
bounds -326 -10 9 327 
property_list 
material 3
region 420
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-420
end_property_list 
<component> 430 
n_bounds 3
bounds -327 -10 9 
property_list 
material 4
region 421
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-421
end_property_list 
<component> 431 
n_bounds 6
bounds 99 185 9 -188 -114 -10 
property_list 
material 2
region 422
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-422
end_property_list 
<component> 432 
n_bounds 7
bounds 99 188 9 328 -191 -114 -10 
property_list 
material 2
region 423
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-423
end_property_list 
<component> 433 
n_bounds 4
bounds -328 -10 9 329 
property_list 
material 3
region 424
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-424
end_property_list 
<component> 434 
n_bounds 3
bounds -329 -10 9 
property_list 
material 4
region 425
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-425
end_property_list 
<component> 435 
n_bounds 7
bounds 99 191 9 330 -194 -114 -10 
property_list 
material 2
region 426
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-426
end_property_list 
<component> 436 
n_bounds 4
bounds -330 -10 9 331 
property_list 
material 3
region 427
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-427
end_property_list 
<component> 437 
n_bounds 3
bounds -331 -10 9 
property_list 
material 4
region 428
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-428
end_property_list 
<component> 438 
n_bounds 7
bounds 99 194 9 332 -15 -114 -10 
property_list 
material 2
region 429
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-429
end_property_list 
<component> 439 
n_bounds 4
bounds -332 -10 9 333 
property_list 
material 3
region 430
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-430
end_property_list 
<component> 440 
n_bounds 3
bounds -333 -10 9 
property_list 
material 4
region 431
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-431
end_property_list 
<component> 441 
n_bounds 7
bounds 99 15 9 334 -199 -114 -10 
property_list 
material 2
region 432
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-432
end_property_list 
<component> 442 
n_bounds 4
bounds -334 -10 9 335 
property_list 
material 3
region 433
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-433
end_property_list 
<component> 443 
n_bounds 3
bounds -335 -10 9 
property_list 
material 4
region 434
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-434
end_property_list 
<component> 444 
n_bounds 7
bounds 99 199 9 336 -202 -114 -10 
property_list 
material 2
region 435
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-435
end_property_list 
<component> 445 
n_bounds 4
bounds -336 -10 9 337 
property_list 
material 3
region 436
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-436
end_property_list 
<component> 446 
n_bounds 3
bounds -337 -10 9 
property_list 
material 4
region 437
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-437
end_property_list 
<component> 447 
n_bounds 7
bounds 114 48 9 338 -164 -129 -10 
property_list 
material 2
region 438
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-438
end_property_list 
<component> 448 
n_bounds 4
bounds -338 -10 9 339 
property_list 
material 3
region 439
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-439
end_property_list 
<component> 449 
n_bounds 3
bounds -339 -10 9 
property_list 
material 4
region 440
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-440
end_property_list 
<component> 450 
n_bounds 7
bounds 114 164 9 340 -167 -129 -10 
property_list 
material 2
region 441
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-441
end_property_list 
<component> 451 
n_bounds 4
bounds -340 -10 9 341 
property_list 
material 3
region 442
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-442
end_property_list 
<component> 452 
n_bounds 3
bounds -341 -10 9 
property_list 
material 4
region 443
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-443
end_property_list 
<component> 453 
n_bounds 7
bounds 114 167 9 342 -12 -129 -10 
property_list 
material 2
region 444
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-444
end_property_list 
<component> 454 
n_bounds 4
bounds -342 -10 9 343 
property_list 
material 3
region 445
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-445
end_property_list 
<component> 455 
n_bounds 3
bounds -343 -10 9 
property_list 
material 4
region 446
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-446
end_property_list 
<component> 456 
n_bounds 7
bounds 114 12 9 344 -172 -129 -10 
property_list 
material 2
region 447
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-447
end_property_list 
<component> 457 
n_bounds 4
bounds -344 -10 9 345 
property_list 
material 3
region 448
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-448
end_property_list 
<component> 458 
n_bounds 3
bounds -345 -10 9 
property_list 
material 4
region 449
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-449
end_property_list 
<component> 459 
n_bounds 7
bounds 114 172 9 346 -175 -129 -10 
property_list 
material 2
region 450
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-450
end_property_list 
<component> 460 
n_bounds 4
bounds -346 -10 9 347 
property_list 
material 3
region 451
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-451
end_property_list 
<component> 461 
n_bounds 3
bounds -347 -10 9 
property_list 
material 4
region 452
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-452
end_property_list 
<component> 462 
n_bounds 7
bounds 114 175 9 348 -178 -129 -10 
property_list 
material 2
region 453
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-453
end_property_list 
<component> 463 
n_bounds 4
bounds -348 -10 9 349 
property_list 
material 3
region 454
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-454
end_property_list 
<component> 464 
n_bounds 3
bounds -349 -10 9 
property_list 
material 4
region 455
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-455
end_property_list 
<component> 465 
n_bounds 7
bounds 114 178 9 350 -181 -129 -10 
property_list 
material 2
region 456
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-456
end_property_list 
<component> 466 
n_bounds 4
bounds -350 -10 9 351 
property_list 
material 3
region 457
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-457
end_property_list 
<component> 467 
n_bounds 3
bounds -351 -10 9 
property_list 
material 4
region 458
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-458
end_property_list 
<component> 468 
n_bounds 7
bounds 114 181 9 352 -183 -129 -10 
property_list 
material 2
region 459
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-459
end_property_list 
<component> 469 
n_bounds 4
bounds -352 -10 9 353 
property_list 
material 3
region 460
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-460
end_property_list 
<component> 470 
n_bounds 3
bounds -353 -10 9 
property_list 
material 4
region 461
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-461
end_property_list 
<component> 471 
n_bounds 7
bounds 114 183 9 354 -185 -129 -10 
property_list 
material 2
region 462
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-462
end_property_list 
<component> 472 
n_bounds 4
bounds -354 -10 9 355 
property_list 
material 3
region 463
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-463
end_property_list 
<component> 473 
n_bounds 3
bounds -355 -10 9 
property_list 
material 4
region 464
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-464
end_property_list 
<component> 474 
n_bounds 7
bounds 114 185 9 356 -188 -129 -10 
property_list 
material 2
region 465
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-465
end_property_list 
<component> 475 
n_bounds 4
bounds -356 -10 9 357 
property_list 
material 3
region 466
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-466
end_property_list 
<component> 476 
n_bounds 3
bounds -357 -10 9 
property_list 
material 4
region 467
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-467
end_property_list 
<component> 477 
n_bounds 7
bounds 114 188 9 358 -191 -129 -10 
property_list 
material 2
region 468
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-468
end_property_list 
<component> 478 
n_bounds 4
bounds -358 -10 9 359 
property_list 
material 3
region 469
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-469
end_property_list 
<component> 479 
n_bounds 3
bounds -359 -10 9 
property_list 
material 4
region 470
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-470
end_property_list 
<component> 480 
n_bounds 7
bounds 114 191 9 360 -194 -129 -10 
property_list 
material 2
region 471
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-471
end_property_list 
<component> 481 
n_bounds 4
bounds -360 -10 9 361 
property_list 
material 3
region 472
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-472
end_property_list 
<component> 482 
n_bounds 3
bounds -361 -10 9 
property_list 
material 4
region 473
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-473
end_property_list 
<component> 483 
n_bounds 7
bounds 114 194 9 362 -15 -129 -10 
property_list 
material 2
region 474
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-474
end_property_list 
<component> 484 
n_bounds 4
bounds -362 -10 9 363 
property_list 
material 3
region 475
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-475
end_property_list 
<component> 485 
n_bounds 3
bounds -363 -10 9 
property_list 
material 4
region 476
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-476
end_property_list 
<component> 486 
n_bounds 7
bounds 114 15 9 364 -199 -129 -10 
property_list 
material 2
region 477
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-477
end_property_list 
<component> 487 
n_bounds 4
bounds -364 -10 9 365 
property_list 
material 3
region 478
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-478
end_property_list 
<component> 488 
n_bounds 3
bounds -365 -10 9 
property_list 
material 4
region 479
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-479
end_property_list 
<component> 489 
n_bounds 7
bounds 114 199 9 366 -202 -129 -10 
property_list 
material 2
region 480
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-480
end_property_list 
<component> 490 
n_bounds 4
bounds -366 -10 9 367 
property_list 
material 3
region 481
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-481
end_property_list 
<component> 491 
n_bounds 3
bounds -367 -10 9 
property_list 
material 4
region 482
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-482
end_property_list 
<component> 492 
n_bounds 7
bounds 129 48 9 368 -164 -146 -10 
property_list 
material 2
region 483
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-483
end_property_list 
<component> 493 
n_bounds 4
bounds -368 -10 9 369 
property_list 
material 3
region 484
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-484
end_property_list 
<component> 494 
n_bounds 3
bounds -369 -10 9 
property_list 
material 4
region 485
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-485
end_property_list 
<component> 495 
n_bounds 7
bounds 129 164 9 370 -167 -146 -10 
property_list 
material 2
region 486
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-486
end_property_list 
<component> 496 
n_bounds 4
bounds -370 -10 9 371 
property_list 
material 3
region 487
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-487
end_property_list 
<component> 497 
n_bounds 3
bounds -371 -10 9 
property_list 
material 4
region 488
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-488
end_property_list 
<component> 498 
n_bounds 7
bounds 129 167 9 372 -12 -146 -10 
property_list 
material 2
region 489
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-489
end_property_list 
<component> 499 
n_bounds 4
bounds -372 -10 9 373 
property_list 
material 3
region 490
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-490
end_property_list 
<component> 500 
n_bounds 3
bounds -373 -10 9 
property_list 
material 4
region 491
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-491
end_property_list 
<component> 501 
n_bounds 7
bounds 129 12 9 374 -172 -146 -10 
property_list 
material 2
region 492
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-492
end_property_list 
<component> 502 
n_bounds 4
bounds -374 -10 9 375 
property_list 
material 3
region 493
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-493
end_property_list 
<component> 503 
n_bounds 3
bounds -375 -10 9 
property_list 
material 4
region 494
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-494
end_property_list 
<component> 504 
n_bounds 7
bounds 129 172 9 376 -175 -146 -10 
property_list 
material 2
region 495
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-495
end_property_list 
<component> 505 
n_bounds 4
bounds -376 -10 9 377 
property_list 
material 3
region 496
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-496
end_property_list 
<component> 506 
n_bounds 3
bounds -377 -10 9 
property_list 
material 4
region 497
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-497
end_property_list 
<component> 507 
n_bounds 7
bounds 129 175 9 378 -178 -146 -10 
property_list 
material 2
region 498
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-498
end_property_list 
<component> 508 
n_bounds 4
bounds -378 -10 9 379 
property_list 
material 3
region 499
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-499
end_property_list 
<component> 509 
n_bounds 3
bounds -379 -10 9 
property_list 
material 4
region 500
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-500
end_property_list 
<component> 510 
n_bounds 7
bounds 129 178 9 380 -181 -146 -10 
property_list 
material 2
region 501
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-501
end_property_list 
<component> 511 
n_bounds 4
bounds -380 -10 9 381 
property_list 
material 3
region 502
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-502
end_property_list 
<component> 512 
n_bounds 3
bounds -381 -10 9 
property_list 
material 4
region 503
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-503
end_property_list 
<component> 513 
n_bounds 7
bounds 129 181 9 382 -183 -146 -10 
property_list 
material 2
region 504
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-504
end_property_list 
<component> 514 
n_bounds 4
bounds -382 -10 9 383 
property_list 
material 3
region 505
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-505
end_property_list 
<component> 515 
n_bounds 3
bounds -383 -10 9 
property_list 
material 4
region 506
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-506
end_property_list 
<component> 516 
n_bounds 7
bounds 129 183 9 384 -185 -146 -10 
property_list 
material 2
region 507
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-507
end_property_list 
<component> 517 
n_bounds 4
bounds -384 -10 9 385 
property_list 
material 3
region 508
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-508
end_property_list 
<component> 518 
n_bounds 3
bounds -385 -10 9 
property_list 
material 4
region 509
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-509
end_property_list 
<component> 519 
n_bounds 7
bounds 129 185 9 386 -188 -146 -10 
property_list 
material 2
region 510
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-510
end_property_list 
<component> 520 
n_bounds 4
bounds -386 -10 9 387 
property_list 
material 3
region 511
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-511
end_property_list 
<component> 521 
n_bounds 3
bounds -387 -10 9 
property_list 
material 4
region 512
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-512
end_property_list 
<component> 522 
n_bounds 7
bounds 129 188 9 388 -191 -146 -10 
property_list 
material 2
region 513
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-513
end_property_list 
<component> 523 
n_bounds 4
bounds -388 -10 9 389 
property_list 
material 3
region 514
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-514
end_property_list 
<component> 524 
n_bounds 3
bounds -389 -10 9 
property_list 
material 4
region 515
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-515
end_property_list 
<component> 525 
n_bounds 7
bounds 129 191 9 390 -194 -146 -10 
property_list 
material 2
region 516
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-516
end_property_list 
<component> 526 
n_bounds 4
bounds -390 -10 9 391 
property_list 
material 3
region 517
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-517
end_property_list 
<component> 527 
n_bounds 3
bounds -391 -10 9 
property_list 
material 4
region 518
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-518
end_property_list 
<component> 528 
n_bounds 7
bounds 129 194 9 392 -15 -146 -10 
property_list 
material 2
region 519
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-519
end_property_list 
<component> 529 
n_bounds 4
bounds -392 -10 9 393 
property_list 
material 3
region 520
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-520
end_property_list 
<component> 530 
n_bounds 3
bounds -393 -10 9 
property_list 
material 4
region 521
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-521
end_property_list 
<component> 531 
n_bounds 7
bounds 129 15 9 394 -199 -146 -10 
property_list 
material 2
region 522
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-522
end_property_list 
<component> 532 
n_bounds 4
bounds -394 -10 9 395 
property_list 
material 3
region 523
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-523
end_property_list 
<component> 533 
n_bounds 3
bounds -395 -10 9 
property_list 
material 4
region 524
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-524
end_property_list 
<component> 534 
n_bounds 7
bounds 129 199 9 396 -202 -146 -10 
property_list 
material 2
region 525
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-525
end_property_list 
<component> 535 
n_bounds 4
bounds -396 -10 9 397 
property_list 
material 3
region 526
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-526
end_property_list 
<component> 536 
n_bounds 3
bounds -397 -10 9 
property_list 
material 4
region 527
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-527
end_property_list 
<component> 537 
n_bounds 8
bounds 146 23 52 399 9 -25 -398 -10 
property_list 
material 2
region 528
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-528
end_property_list 
<component> 538 
n_bounds 6
bounds 23 54 400 9 -399 -10 
property_list 
material 3
region 529
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-529
end_property_list 
<component> 539 
n_bounds 4
bounds 23 9 -400 -10 
property_list 
material 4
region 530
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-530
end_property_list 
<component> 540 
n_bounds 7
bounds 146 25 9 401 -27 -398 -10 
property_list 
material 2
region 531
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-531
end_property_list 
<component> 541 
n_bounds 4
bounds -401 -10 9 402 
property_list 
material 3
region 532
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-532
end_property_list 
<component> 542 
n_bounds 3
bounds -402 -10 9 
property_list 
material 4
region 533
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-533
end_property_list 
<component> 543 
n_bounds 7
bounds 146 27 9 403 -33 -398 -10 
property_list 
material 2
region 534
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-534
end_property_list 
<component> 544 
n_bounds 4
bounds -403 -10 9 404 
property_list 
material 3
region 535
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-535
end_property_list 
<component> 545 
n_bounds 3
bounds -404 -10 9 
property_list 
material 4
region 536
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-536
end_property_list 
<component> 546 
n_bounds 7
bounds 146 33 9 405 -36 -398 -10 
property_list 
material 2
region 537
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-537
end_property_list 
<component> 547 
n_bounds 4
bounds -405 -10 9 406 
property_list 
material 3
region 538
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-538
end_property_list 
<component> 548 
n_bounds 3
bounds -406 -10 9 
property_list 
material 4
region 539
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-539
end_property_list 
<component> 549 
n_bounds 7
bounds 146 36 9 407 -39 -398 -10 
property_list 
material 2
region 540
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-540
end_property_list 
<component> 550 
n_bounds 4
bounds -407 -10 9 408 
property_list 
material 3
region 541
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-541
end_property_list 
<component> 551 
n_bounds 3
bounds -408 -10 9 
property_list 
material 4
region 542
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-542
end_property_list 
<component> 552 
n_bounds 7
bounds 146 39 9 409 -42 -398 -10 
property_list 
material 2
region 543
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-543
end_property_list 
<component> 553 
n_bounds 4
bounds -409 -10 9 410 
property_list 
material 3
region 544
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-544
end_property_list 
<component> 554 
n_bounds 3
bounds -410 -10 9 
property_list 
material 4
region 545
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-545
end_property_list 
<component> 555 
n_bounds 7
bounds 146 42 9 411 -45 -398 -10 
property_list 
material 2
region 546
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-546
end_property_list 
<component> 556 
n_bounds 4
bounds -411 -10 9 412 
property_list 
material 3
region 547
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-547
end_property_list 
<component> 557 
n_bounds 3
bounds -412 -10 9 
property_list 
material 4
region 548
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-548
end_property_list 
<component> 558 
n_bounds 7
bounds 146 45 9 413 -48 -398 -10 
property_list 
material 2
region 549
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-549
end_property_list 
<component> 559 
n_bounds 4
bounds -413 -10 9 414 
property_list 
material 3
region 550
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-550
end_property_list 
<component> 560 
n_bounds 3
bounds -414 -10 9 
property_list 
material 4
region 551
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-551
end_property_list 
<component> 561 
n_bounds 8
bounds 398 23 52 416 9 -25 -415 -10 
property_list 
material 2
region 552
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-552
end_property_list 
<component> 562 
n_bounds 6
bounds 23 54 417 9 -416 -10 
property_list 
material 3
region 553
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-553
end_property_list 
<component> 563 
n_bounds 4
bounds 23 9 -417 -10 
property_list 
material 4
region 554
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-554
end_property_list 
<component> 564 
n_bounds 7
bounds 398 25 9 418 -27 -415 -10 
property_list 
material 2
region 555
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-555
end_property_list 
<component> 565 
n_bounds 4
bounds -418 -10 9 419 
property_list 
material 3
region 556
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-556
end_property_list 
<component> 566 
n_bounds 3
bounds -419 -10 9 
property_list 
material 4
region 557
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-557
end_property_list 
<component> 567 
n_bounds 7
bounds 398 27 9 420 -33 -415 -10 
property_list 
material 2
region 558
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-558
end_property_list 
<component> 568 
n_bounds 4
bounds -420 -10 9 421 
property_list 
material 3
region 559
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-559
end_property_list 
<component> 569 
n_bounds 3
bounds -421 -10 9 
property_list 
material 4
region 560
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-560
end_property_list 
<component> 570 
n_bounds 7
bounds 398 33 9 422 -36 -415 -10 
property_list 
material 2
region 561
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-561
end_property_list 
<component> 571 
n_bounds 4
bounds -422 -10 9 423 
property_list 
material 3
region 562
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-562
end_property_list 
<component> 572 
n_bounds 3
bounds -423 -10 9 
property_list 
material 4
region 563
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-563
end_property_list 
<component> 573 
n_bounds 7
bounds 398 36 9 424 -39 -415 -10 
property_list 
material 2
region 564
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-564
end_property_list 
<component> 574 
n_bounds 4
bounds -424 -10 9 425 
property_list 
material 3
region 565
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-565
end_property_list 
<component> 575 
n_bounds 3
bounds -425 -10 9 
property_list 
material 4
region 566
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-566
end_property_list 
<component> 576 
n_bounds 7
bounds 398 39 9 426 -42 -415 -10 
property_list 
material 2
region 567
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-567
end_property_list 
<component> 577 
n_bounds 4
bounds -426 -10 9 427 
property_list 
material 3
region 568
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-568
end_property_list 
<component> 578 
n_bounds 3
bounds -427 -10 9 
property_list 
material 4
region 569
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-569
end_property_list 
<component> 579 
n_bounds 7
bounds 398 42 9 428 -45 -415 -10 
property_list 
material 2
region 570
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-570
end_property_list 
<component> 580 
n_bounds 4
bounds -428 -10 9 429 
property_list 
material 3
region 571
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-571
end_property_list 
<component> 581 
n_bounds 3
bounds -429 -10 9 
property_list 
material 4
region 572
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-572
end_property_list 
<component> 582 
n_bounds 7
bounds 398 45 9 430 -48 -415 -10 
property_list 
material 2
region 573
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-573
end_property_list 
<component> 583 
n_bounds 4
bounds -430 -10 9 431 
property_list 
material 3
region 574
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-574
end_property_list 
<component> 584 
n_bounds 3
bounds -431 -10 9 
property_list 
material 4
region 575
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-575
end_property_list 
<component> 585 
n_bounds 8
bounds 415 23 52 432 9 -25 -21 -10 
property_list 
material 2
region 576
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-576
end_property_list 
<component> 586 
n_bounds 6
bounds 23 54 433 9 -432 -10 
property_list 
material 3
region 577
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-577
end_property_list 
<component> 587 
n_bounds 4
bounds 23 9 -433 -10 
property_list 
material 4
region 578
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-578
end_property_list 
<component> 588 
n_bounds 7
bounds 415 25 9 434 -27 -21 -10 
property_list 
material 2
region 579
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-579
end_property_list 
<component> 589 
n_bounds 4
bounds -434 -10 9 435 
property_list 
material 3
region 580
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-580
end_property_list 
<component> 590 
n_bounds 3
bounds -435 -10 9 
property_list 
material 4
region 581
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-581
end_property_list 
<component> 591 
n_bounds 6
bounds 415 27 9 -33 -21 -10 
property_list 
material 2
region 582
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-582
end_property_list 
<component> 592 
n_bounds 7
bounds 415 33 9 436 -36 -21 -10 
property_list 
material 2
region 583
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-583
end_property_list 
<component> 593 
n_bounds 4
bounds -436 -10 9 437 
property_list 
material 3
region 584
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-584
end_property_list 
<component> 594 
n_bounds 3
bounds -437 -10 9 
property_list 
material 4
region 585
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-585
end_property_list 
<component> 595 
n_bounds 7
bounds 415 36 9 438 -39 -21 -10 
property_list 
material 2
region 586
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-586
end_property_list 
<component> 596 
n_bounds 4
bounds -438 -10 9 439 
property_list 
material 3
region 587
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-587
end_property_list 
<component> 597 
n_bounds 3
bounds -439 -10 9 
property_list 
material 4
region 588
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-588
end_property_list 
<component> 598 
n_bounds 7
bounds 415 39 9 440 -42 -21 -10 
property_list 
material 2
region 589
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-589
end_property_list 
<component> 599 
n_bounds 4
bounds -440 -10 9 441 
property_list 
material 3
region 590
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-590
end_property_list 
<component> 600 
n_bounds 3
bounds -441 -10 9 
property_list 
material 4
region 591
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-591
end_property_list 
<component> 601 
n_bounds 7
bounds 415 42 9 442 -45 -21 -10 
property_list 
material 2
region 592
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-592
end_property_list 
<component> 602 
n_bounds 4
bounds -442 -10 9 443 
property_list 
material 3
region 593
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-593
end_property_list 
<component> 603 
n_bounds 3
bounds -443 -10 9 
property_list 
material 4
region 594
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-594
end_property_list 
<component> 604 
n_bounds 7
bounds 415 45 9 444 -48 -21 -10 
property_list 
material 2
region 595
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-595
end_property_list 
<component> 605 
n_bounds 4
bounds -444 -10 9 445 
property_list 
material 3
region 596
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-596
end_property_list 
<component> 606 
n_bounds 3
bounds -445 -10 9 
property_list 
material 4
region 597
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-597
end_property_list 
<component> 607 
n_bounds 8
bounds 21 23 52 447 9 -25 -446 -10 
property_list 
material 2
region 598
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-598
end_property_list 
<component> 608 
n_bounds 6
bounds 23 54 448 9 -447 -10 
property_list 
material 3
region 599
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-599
end_property_list 
<component> 609 
n_bounds 4
bounds 23 9 -448 -10 
property_list 
material 4
region 600
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-600
end_property_list 
<component> 610 
n_bounds 7
bounds 21 25 9 449 -27 -446 -10 
property_list 
material 2
region 601
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-601
end_property_list 
<component> 611 
n_bounds 4
bounds -449 -10 9 450 
property_list 
material 3
region 602
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-602
end_property_list 
<component> 612 
n_bounds 3
bounds -450 -10 9 
property_list 
material 4
region 603
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-603
end_property_list 
<component> 613 
n_bounds 7
bounds 21 27 9 451 -33 -446 -10 
property_list 
material 2
region 604
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-604
end_property_list 
<component> 614 
n_bounds 4
bounds -451 -10 9 452 
property_list 
material 3
region 605
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-605
end_property_list 
<component> 615 
n_bounds 3
bounds -452 -10 9 
property_list 
material 4
region 606
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-606
end_property_list 
<component> 616 
n_bounds 7
bounds 21 33 9 453 -36 -446 -10 
property_list 
material 2
region 607
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-607
end_property_list 
<component> 617 
n_bounds 4
bounds -453 -10 9 454 
property_list 
material 3
region 608
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-608
end_property_list 
<component> 618 
n_bounds 3
bounds -454 -10 9 
property_list 
material 4
region 609
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-609
end_property_list 
<component> 619 
n_bounds 6
bounds 21 36 9 -39 -446 -10 
property_list 
material 2
region 610
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-610
end_property_list 
<component> 620 
n_bounds 7
bounds 21 39 9 455 -42 -446 -10 
property_list 
material 2
region 611
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-611
end_property_list 
<component> 621 
n_bounds 4
bounds -455 -10 9 456 
property_list 
material 3
region 612
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-612
end_property_list 
<component> 622 
n_bounds 3
bounds -456 -10 9 
property_list 
material 4
region 613
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-613
end_property_list 
<component> 623 
n_bounds 7
bounds 21 42 9 457 -45 -446 -10 
property_list 
material 2
region 614
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-614
end_property_list 
<component> 624 
n_bounds 4
bounds -457 -10 9 458 
property_list 
material 3
region 615
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-615
end_property_list 
<component> 625 
n_bounds 3
bounds -458 -10 9 
property_list 
material 4
region 616
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-616
end_property_list 
<component> 626 
n_bounds 7
bounds 21 45 9 459 -48 -446 -10 
property_list 
material 2
region 617
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-617
end_property_list 
<component> 627 
n_bounds 4
bounds -459 -10 9 460 
property_list 
material 3
region 618
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-618
end_property_list 
<component> 628 
n_bounds 3
bounds -460 -10 9 
property_list 
material 4
region 619
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-619
end_property_list 
<component> 629 
n_bounds 8
bounds 446 23 52 462 9 -25 -461 -10 
property_list 
material 2
region 620
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-620
end_property_list 
<component> 630 
n_bounds 6
bounds 23 54 463 9 -462 -10 
property_list 
material 3
region 621
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-621
end_property_list 
<component> 631 
n_bounds 4
bounds 23 9 -463 -10 
property_list 
material 4
region 622
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-622
end_property_list 
<component> 632 
n_bounds 7
bounds 446 25 9 464 -27 -461 -10 
property_list 
material 2
region 623
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-623
end_property_list 
<component> 633 
n_bounds 4
bounds -464 -10 9 465 
property_list 
material 3
region 624
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-624
end_property_list 
<component> 634 
n_bounds 3
bounds -465 -10 9 
property_list 
material 4
region 625
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-625
end_property_list 
<component> 635 
n_bounds 7
bounds 446 27 9 466 -33 -461 -10 
property_list 
material 2
region 626
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-626
end_property_list 
<component> 636 
n_bounds 4
bounds -466 -10 9 467 
property_list 
material 3
region 627
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-627
end_property_list 
<component> 637 
n_bounds 3
bounds -467 -10 9 
property_list 
material 4
region 628
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-628
end_property_list 
<component> 638 
n_bounds 7
bounds 446 33 9 468 -36 -461 -10 
property_list 
material 2
region 629
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-629
end_property_list 
<component> 639 
n_bounds 4
bounds -468 -10 9 469 
property_list 
material 3
region 630
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-630
end_property_list 
<component> 640 
n_bounds 3
bounds -469 -10 9 
property_list 
material 4
region 631
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-631
end_property_list 
<component> 641 
n_bounds 7
bounds 446 36 9 470 -39 -461 -10 
property_list 
material 2
region 632
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-632
end_property_list 
<component> 642 
n_bounds 4
bounds -470 -10 9 471 
property_list 
material 3
region 633
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-633
end_property_list 
<component> 643 
n_bounds 3
bounds -471 -10 9 
property_list 
material 4
region 634
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-634
end_property_list 
<component> 644 
n_bounds 7
bounds 446 39 9 472 -42 -461 -10 
property_list 
material 2
region 635
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-635
end_property_list 
<component> 645 
n_bounds 4
bounds -472 -10 9 473 
property_list 
material 3
region 636
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-636
end_property_list 
<component> 646 
n_bounds 3
bounds -473 -10 9 
property_list 
material 4
region 637
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-637
end_property_list 
<component> 647 
n_bounds 7
bounds 446 42 9 474 -45 -461 -10 
property_list 
material 2
region 638
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-638
end_property_list 
<component> 648 
n_bounds 4
bounds -474 -10 9 475 
property_list 
material 3
region 639
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-639
end_property_list 
<component> 649 
n_bounds 3
bounds -475 -10 9 
property_list 
material 4
region 640
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-640
end_property_list 
<component> 650 
n_bounds 7
bounds 446 45 9 476 -48 -461 -10 
property_list 
material 2
region 641
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-641
end_property_list 
<component> 651 
n_bounds 4
bounds -476 -10 9 477 
property_list 
material 3
region 642
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-642
end_property_list 
<component> 652 
n_bounds 3
bounds -477 -10 9 
property_list 
material 4
region 643
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-643
end_property_list 
<component> 653 
n_bounds 8
bounds 461 23 52 479 9 -25 -478 -10 
property_list 
material 2
region 644
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-644
end_property_list 
<component> 654 
n_bounds 6
bounds 23 54 480 9 -479 -10 
property_list 
material 3
region 645
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-645
end_property_list 
<component> 655 
n_bounds 4
bounds 23 9 -480 -10 
property_list 
material 4
region 646
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-646
end_property_list 
<component> 656 
n_bounds 7
bounds 461 25 9 481 -27 -478 -10 
property_list 
material 2
region 647
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-647
end_property_list 
<component> 657 
n_bounds 4
bounds -481 -10 9 482 
property_list 
material 3
region 648
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-648
end_property_list 
<component> 658 
n_bounds 3
bounds -482 -10 9 
property_list 
material 4
region 649
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-649
end_property_list 
<component> 659 
n_bounds 6
bounds 461 27 9 -33 -478 -10 
property_list 
material 2
region 650
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-650
end_property_list 
<component> 660 
n_bounds 7
bounds 461 33 9 483 -36 -478 -10 
property_list 
material 2
region 651
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-651
end_property_list 
<component> 661 
n_bounds 4
bounds -483 -10 9 484 
property_list 
material 3
region 652
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-652
end_property_list 
<component> 662 
n_bounds 3
bounds -484 -10 9 
property_list 
material 4
region 653
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-653
end_property_list 
<component> 663 
n_bounds 7
bounds 461 36 9 485 -39 -478 -10 
property_list 
material 2
region 654
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-654
end_property_list 
<component> 664 
n_bounds 4
bounds -485 -10 9 486 
property_list 
material 3
region 655
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-655
end_property_list 
<component> 665 
n_bounds 3
bounds -486 -10 9 
property_list 
material 4
region 656
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-656
end_property_list 
<component> 666 
n_bounds 6
bounds 461 39 9 -42 -478 -10 
property_list 
material 2
region 657
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-657
end_property_list 
<component> 667 
n_bounds 7
bounds 461 42 9 487 -45 -478 -10 
property_list 
material 2
region 658
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-658
end_property_list 
<component> 668 
n_bounds 4
bounds -487 -10 9 488 
property_list 
material 3
region 659
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-659
end_property_list 
<component> 669 
n_bounds 3
bounds -488 -10 9 
property_list 
material 4
region 660
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-660
end_property_list 
<component> 670 
n_bounds 7
bounds 461 45 9 489 -48 -478 -10 
property_list 
material 2
region 661
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-661
end_property_list 
<component> 671 
n_bounds 4
bounds -489 -10 9 490 
property_list 
material 3
region 662
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-662
end_property_list 
<component> 672 
n_bounds 3
bounds -490 -10 9 
property_list 
material 4
region 663
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-663
end_property_list 
<component> 673 
n_bounds 8
bounds 478 23 52 492 9 -25 -491 -10 
property_list 
material 2
region 664
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-664
end_property_list 
<component> 674 
n_bounds 6
bounds 23 54 493 9 -492 -10 
property_list 
material 3
region 665
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-665
end_property_list 
<component> 675 
n_bounds 4
bounds 23 9 -493 -10 
property_list 
material 4
region 666
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-666
end_property_list 
<component> 676 
n_bounds 7
bounds 478 25 9 494 -27 -491 -10 
property_list 
material 2
region 667
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-667
end_property_list 
<component> 677 
n_bounds 4
bounds -494 -10 9 495 
property_list 
material 3
region 668
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-668
end_property_list 
<component> 678 
n_bounds 3
bounds -495 -10 9 
property_list 
material 4
region 669
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-669
end_property_list 
<component> 679 
n_bounds 7
bounds 478 27 9 496 -33 -491 -10 
property_list 
material 2
region 670
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-670
end_property_list 
<component> 680 
n_bounds 4
bounds -496 -10 9 497 
property_list 
material 3
region 671
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-671
end_property_list 
<component> 681 
n_bounds 3
bounds -497 -10 9 
property_list 
material 4
region 672
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-672
end_property_list 
<component> 682 
n_bounds 7
bounds 478 33 9 498 -36 -491 -10 
property_list 
material 2
region 673
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-673
end_property_list 
<component> 683 
n_bounds 4
bounds -498 -10 9 499 
property_list 
material 3
region 674
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-674
end_property_list 
<component> 684 
n_bounds 3
bounds -499 -10 9 
property_list 
material 4
region 675
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-675
end_property_list 
<component> 685 
n_bounds 7
bounds 478 36 9 500 -39 -491 -10 
property_list 
material 2
region 676
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-676
end_property_list 
<component> 686 
n_bounds 4
bounds -500 -10 9 501 
property_list 
material 3
region 677
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-677
end_property_list 
<component> 687 
n_bounds 3
bounds -501 -10 9 
property_list 
material 4
region 678
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-678
end_property_list 
<component> 688 
n_bounds 7
bounds 478 39 9 502 -42 -491 -10 
property_list 
material 2
region 679
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-679
end_property_list 
<component> 689 
n_bounds 4
bounds -502 -10 9 503 
property_list 
material 3
region 680
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-680
end_property_list 
<component> 690 
n_bounds 3
bounds -503 -10 9 
property_list 
material 4
region 681
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-681
end_property_list 
<component> 691 
n_bounds 7
bounds 478 42 9 504 -45 -491 -10 
property_list 
material 2
region 682
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-682
end_property_list 
<component> 692 
n_bounds 4
bounds -504 -10 9 505 
property_list 
material 3
region 683
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-683
end_property_list 
<component> 693 
n_bounds 3
bounds -505 -10 9 
property_list 
material 4
region 684
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-684
end_property_list 
<component> 694 
n_bounds 7
bounds 478 45 9 506 -48 -491 -10 
property_list 
material 2
region 685
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-685
end_property_list 
<component> 695 
n_bounds 4
bounds -506 -10 9 507 
property_list 
material 3
region 686
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-686
end_property_list 
<component> 696 
n_bounds 3
bounds -507 -10 9 
property_list 
material 4
region 687
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-687
end_property_list 
<component> 697 
n_bounds 6
bounds 491 23 9 -25 -508 -10 
property_list 
material 2
region 688
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-688
end_property_list 
<component> 698 
n_bounds 7
bounds 491 25 9 509 -27 -508 -10 
property_list 
material 2
region 689
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-689
end_property_list 
<component> 699 
n_bounds 4
bounds -509 -10 9 510 
property_list 
material 3
region 690
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-690
end_property_list 
<component> 700 
n_bounds 3
bounds -510 -10 9 
property_list 
material 4
region 691
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-691
end_property_list 
<component> 701 
n_bounds 7
bounds 491 27 9 511 -33 -508 -10 
property_list 
material 2
region 692
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-692
end_property_list 
<component> 702 
n_bounds 4
bounds -511 -10 9 512 
property_list 
material 3
region 693
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-693
end_property_list 
<component> 703 
n_bounds 3
bounds -512 -10 9 
property_list 
material 4
region 694
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-694
end_property_list 
<component> 704 
n_bounds 7
bounds 491 33 9 513 -36 -508 -10 
property_list 
material 2
region 695
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-695
end_property_list 
<component> 705 
n_bounds 4
bounds -513 -10 9 514 
property_list 
material 3
region 696
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-696
end_property_list 
<component> 706 
n_bounds 3
bounds -514 -10 9 
property_list 
material 4
region 697
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-697
end_property_list 
<component> 707 
n_bounds 7
bounds 491 36 9 515 -39 -508 -10 
property_list 
material 2
region 698
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-698
end_property_list 
<component> 708 
n_bounds 4
bounds -515 -10 9 516 
property_list 
material 3
region 699
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-699
end_property_list 
<component> 709 
n_bounds 3
bounds -516 -10 9 
property_list 
material 4
region 700
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-700
end_property_list 
<component> 710 
n_bounds 7
bounds 491 39 9 517 -42 -508 -10 
property_list 
material 2
region 701
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-701
end_property_list 
<component> 711 
n_bounds 4
bounds -517 -10 9 518 
property_list 
material 3
region 702
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-702
end_property_list 
<component> 712 
n_bounds 3
bounds -518 -10 9 
property_list 
material 4
region 703
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-703
end_property_list 
<component> 713 
n_bounds 7
bounds 491 42 9 519 -45 -508 -10 
property_list 
material 2
region 704
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-704
end_property_list 
<component> 714 
n_bounds 4
bounds -519 -10 9 520 
property_list 
material 3
region 705
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-705
end_property_list 
<component> 715 
n_bounds 3
bounds -520 -10 9 
property_list 
material 4
region 706
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-706
end_property_list 
<component> 716 
n_bounds 7
bounds 491 45 9 521 -48 -508 -10 
property_list 
material 2
region 707
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-707
end_property_list 
<component> 717 
n_bounds 4
bounds -521 -10 9 522 
property_list 
material 3
region 708
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-708
end_property_list 
<component> 718 
n_bounds 3
bounds -522 -10 9 
property_list 
material 4
region 709
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-709
end_property_list 
<component> 719 
n_bounds 8
bounds 508 23 52 524 9 -25 -523 -10 
property_list 
material 2
region 710
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-710
end_property_list 
<component> 720 
n_bounds 6
bounds 23 54 525 9 -524 -10 
property_list 
material 3
region 711
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-711
end_property_list 
<component> 721 
n_bounds 4
bounds 23 9 -525 -10 
property_list 
material 4
region 712
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-712
end_property_list 
<component> 722 
n_bounds 7
bounds 508 25 9 526 -27 -523 -10 
property_list 
material 2
region 713
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-713
end_property_list 
<component> 723 
n_bounds 4
bounds -526 -10 9 527 
property_list 
material 3
region 714
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-714
end_property_list 
<component> 724 
n_bounds 3
bounds -527 -10 9 
property_list 
material 4
region 715
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-715
end_property_list 
<component> 725 
n_bounds 7
bounds 508 27 9 528 -33 -523 -10 
property_list 
material 2
region 716
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-716
end_property_list 
<component> 726 
n_bounds 4
bounds -528 -10 9 529 
property_list 
material 3
region 717
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-717
end_property_list 
<component> 727 
n_bounds 3
bounds -529 -10 9 
property_list 
material 4
region 718
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-718
end_property_list 
<component> 728 
n_bounds 7
bounds 508 33 9 530 -36 -523 -10 
property_list 
material 2
region 719
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-719
end_property_list 
<component> 729 
n_bounds 4
bounds -530 -10 9 531 
property_list 
material 3
region 720
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-720
end_property_list 
<component> 730 
n_bounds 3
bounds -531 -10 9 
property_list 
material 4
region 721
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-721
end_property_list 
<component> 731 
n_bounds 7
bounds 508 36 9 532 -39 -523 -10 
property_list 
material 2
region 722
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-722
end_property_list 
<component> 732 
n_bounds 4
bounds -532 -10 9 533 
property_list 
material 3
region 723
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-723
end_property_list 
<component> 733 
n_bounds 3
bounds -533 -10 9 
property_list 
material 4
region 724
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-724
end_property_list 
<component> 734 
n_bounds 7
bounds 508 39 9 534 -42 -523 -10 
property_list 
material 2
region 725
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-725
end_property_list 
<component> 735 
n_bounds 4
bounds -534 -10 9 535 
property_list 
material 3
region 726
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-726
end_property_list 
<component> 736 
n_bounds 3
bounds -535 -10 9 
property_list 
material 4
region 727
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-727
end_property_list 
<component> 737 
n_bounds 7
bounds 508 42 9 536 -45 -523 -10 
property_list 
material 2
region 728
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-728
end_property_list 
<component> 738 
n_bounds 4
bounds -536 -10 9 537 
property_list 
material 3
region 729
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-729
end_property_list 
<component> 739 
n_bounds 3
bounds -537 -10 9 
property_list 
material 4
region 730
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-730
end_property_list 
<component> 740 
n_bounds 7
bounds 508 45 9 538 -48 -523 -10 
property_list 
material 2
region 731
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-731
end_property_list 
<component> 741 
n_bounds 4
bounds -538 -10 9 539 
property_list 
material 3
region 732
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-732
end_property_list 
<component> 742 
n_bounds 3
bounds -539 -10 9 
property_list 
material 4
region 733
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-733
end_property_list 
<component> 743 
n_bounds 8
bounds 523 23 52 541 9 -25 -540 -10 
property_list 
material 2
region 734
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-734
end_property_list 
<component> 744 
n_bounds 6
bounds 23 54 542 9 -541 -10 
property_list 
material 3
region 735
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-735
end_property_list 
<component> 745 
n_bounds 4
bounds 23 9 -542 -10 
property_list 
material 4
region 736
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-736
end_property_list 
<component> 746 
n_bounds 7
bounds 523 25 9 543 -27 -540 -10 
property_list 
material 2
region 737
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-737
end_property_list 
<component> 747 
n_bounds 4
bounds -543 -10 9 544 
property_list 
material 3
region 738
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-738
end_property_list 
<component> 748 
n_bounds 3
bounds -544 -10 9 
property_list 
material 4
region 739
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-739
end_property_list 
<component> 749 
n_bounds 6
bounds 523 27 9 -33 -540 -10 
property_list 
material 2
region 740
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-740
end_property_list 
<component> 750 
n_bounds 7
bounds 523 33 9 545 -36 -540 -10 
property_list 
material 2
region 741
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-741
end_property_list 
<component> 751 
n_bounds 4
bounds -545 -10 9 546 
property_list 
material 3
region 742
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-742
end_property_list 
<component> 752 
n_bounds 3
bounds -546 -10 9 
property_list 
material 4
region 743
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-743
end_property_list 
<component> 753 
n_bounds 7
bounds 523 36 9 547 -39 -540 -10 
property_list 
material 2
region 744
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-744
end_property_list 
<component> 754 
n_bounds 4
bounds -547 -10 9 548 
property_list 
material 3
region 745
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-745
end_property_list 
<component> 755 
n_bounds 3
bounds -548 -10 9 
property_list 
material 4
region 746
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-746
end_property_list 
<component> 756 
n_bounds 6
bounds 523 39 9 -42 -540 -10 
property_list 
material 2
region 747
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-747
end_property_list 
<component> 757 
n_bounds 7
bounds 523 42 9 549 -45 -540 -10 
property_list 
material 2
region 748
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-748
end_property_list 
<component> 758 
n_bounds 4
bounds -549 -10 9 550 
property_list 
material 3
region 749
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-749
end_property_list 
<component> 759 
n_bounds 3
bounds -550 -10 9 
property_list 
material 4
region 750
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-750
end_property_list 
<component> 760 
n_bounds 7
bounds 523 45 9 551 -48 -540 -10 
property_list 
material 2
region 751
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-751
end_property_list 
<component> 761 
n_bounds 4
bounds -551 -10 9 552 
property_list 
material 3
region 752
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-752
end_property_list 
<component> 762 
n_bounds 3
bounds -552 -10 9 
property_list 
material 4
region 753
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-753
end_property_list 
<component> 763 
n_bounds 8
bounds 540 23 52 554 9 -25 -553 -10 
property_list 
material 2
region 754
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-754
end_property_list 
<component> 764 
n_bounds 6
bounds 23 54 555 9 -554 -10 
property_list 
material 3
region 755
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-755
end_property_list 
<component> 765 
n_bounds 4
bounds 23 9 -555 -10 
property_list 
material 4
region 756
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-756
end_property_list 
<component> 766 
n_bounds 7
bounds 540 25 9 556 -27 -553 -10 
property_list 
material 2
region 757
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-757
end_property_list 
<component> 767 
n_bounds 4
bounds -556 -10 9 557 
property_list 
material 3
region 758
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-758
end_property_list 
<component> 768 
n_bounds 3
bounds -557 -10 9 
property_list 
material 4
region 759
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-759
end_property_list 
<component> 769 
n_bounds 7
bounds 540 27 9 558 -33 -553 -10 
property_list 
material 2
region 760
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-760
end_property_list 
<component> 770 
n_bounds 4
bounds -558 -10 9 559 
property_list 
material 3
region 761
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-761
end_property_list 
<component> 771 
n_bounds 3
bounds -559 -10 9 
property_list 
material 4
region 762
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-762
end_property_list 
<component> 772 
n_bounds 7
bounds 540 33 9 560 -36 -553 -10 
property_list 
material 2
region 763
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-763
end_property_list 
<component> 773 
n_bounds 4
bounds -560 -10 9 561 
property_list 
material 3
region 764
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-764
end_property_list 
<component> 774 
n_bounds 3
bounds -561 -10 9 
property_list 
material 4
region 765
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-765
end_property_list 
<component> 775 
n_bounds 7
bounds 540 36 9 562 -39 -553 -10 
property_list 
material 2
region 766
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-766
end_property_list 
<component> 776 
n_bounds 4
bounds -562 -10 9 563 
property_list 
material 3
region 767
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-767
end_property_list 
<component> 777 
n_bounds 3
bounds -563 -10 9 
property_list 
material 4
region 768
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-768
end_property_list 
<component> 778 
n_bounds 7
bounds 540 39 9 564 -42 -553 -10 
property_list 
material 2
region 769
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-769
end_property_list 
<component> 779 
n_bounds 4
bounds -564 -10 9 565 
property_list 
material 3
region 770
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-770
end_property_list 
<component> 780 
n_bounds 3
bounds -565 -10 9 
property_list 
material 4
region 771
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-771
end_property_list 
<component> 781 
n_bounds 7
bounds 540 42 9 566 -45 -553 -10 
property_list 
material 2
region 772
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-772
end_property_list 
<component> 782 
n_bounds 4
bounds -566 -10 9 567 
property_list 
material 3
region 773
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-773
end_property_list 
<component> 783 
n_bounds 3
bounds -567 -10 9 
property_list 
material 4
region 774
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-774
end_property_list 
<component> 784 
n_bounds 7
bounds 540 45 9 568 -48 -553 -10 
property_list 
material 2
region 775
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-775
end_property_list 
<component> 785 
n_bounds 4
bounds -568 -10 9 569 
property_list 
material 3
region 776
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-776
end_property_list 
<component> 786 
n_bounds 3
bounds -569 -10 9 
property_list 
material 4
region 777
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-777
end_property_list 
<component> 787 
n_bounds 8
bounds 553 23 52 571 9 -25 -570 -10 
property_list 
material 2
region 778
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-778
end_property_list 
<component> 788 
n_bounds 6
bounds 23 54 572 9 -571 -10 
property_list 
material 3
region 779
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-779
end_property_list 
<component> 789 
n_bounds 4
bounds 23 9 -572 -10 
property_list 
material 4
region 780
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-780
end_property_list 
<component> 790 
n_bounds 7
bounds 553 25 9 573 -27 -570 -10 
property_list 
material 2
region 781
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-781
end_property_list 
<component> 791 
n_bounds 4
bounds -573 -10 9 574 
property_list 
material 3
region 782
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-782
end_property_list 
<component> 792 
n_bounds 3
bounds -574 -10 9 
property_list 
material 4
region 783
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-783
end_property_list 
<component> 793 
n_bounds 7
bounds 553 27 9 575 -33 -570 -10 
property_list 
material 2
region 784
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-784
end_property_list 
<component> 794 
n_bounds 4
bounds -575 -10 9 576 
property_list 
material 3
region 785
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-785
end_property_list 
<component> 795 
n_bounds 3
bounds -576 -10 9 
property_list 
material 4
region 786
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-786
end_property_list 
<component> 796 
n_bounds 7
bounds 553 33 9 577 -36 -570 -10 
property_list 
material 2
region 787
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-787
end_property_list 
<component> 797 
n_bounds 4
bounds -577 -10 9 578 
property_list 
material 3
region 788
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-788
end_property_list 
<component> 798 
n_bounds 3
bounds -578 -10 9 
property_list 
material 4
region 789
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-789
end_property_list 
<component> 799 
n_bounds 6
bounds 553 36 9 -39 -570 -10 
property_list 
material 2
region 790
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-790
end_property_list 
<component> 800 
n_bounds 7
bounds 553 39 9 579 -42 -570 -10 
property_list 
material 2
region 791
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-791
end_property_list 
<component> 801 
n_bounds 4
bounds -579 -10 9 580 
property_list 
material 3
region 792
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-792
end_property_list 
<component> 802 
n_bounds 3
bounds -580 -10 9 
property_list 
material 4
region 793
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-793
end_property_list 
<component> 803 
n_bounds 7
bounds 553 42 9 581 -45 -570 -10 
property_list 
material 2
region 794
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-794
end_property_list 
<component> 804 
n_bounds 4
bounds -581 -10 9 582 
property_list 
material 3
region 795
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-795
end_property_list 
<component> 805 
n_bounds 3
bounds -582 -10 9 
property_list 
material 4
region 796
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-796
end_property_list 
<component> 806 
n_bounds 7
bounds 553 45 9 583 -48 -570 -10 
property_list 
material 2
region 797
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-797
end_property_list 
<component> 807 
n_bounds 4
bounds -583 -10 9 584 
property_list 
material 3
region 798
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-798
end_property_list 
<component> 808 
n_bounds 3
bounds -584 -10 9 
property_list 
material 4
region 799
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-799
end_property_list 
<component> 809 
n_bounds 8
bounds 570 23 52 585 9 -25 -20 -10 
property_list 
material 2
region 800
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-800
end_property_list 
<component> 810 
n_bounds 6
bounds 23 54 586 9 -585 -10 
property_list 
material 3
region 801
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-801
end_property_list 
<component> 811 
n_bounds 4
bounds 23 9 -586 -10 
property_list 
material 4
region 802
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-802
end_property_list 
<component> 812 
n_bounds 7
bounds 570 25 9 587 -27 -20 -10 
property_list 
material 2
region 803
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-803
end_property_list 
<component> 813 
n_bounds 4
bounds -587 -10 9 588 
property_list 
material 3
region 804
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-804
end_property_list 
<component> 814 
n_bounds 3
bounds -588 -10 9 
property_list 
material 4
region 805
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-805
end_property_list 
<component> 815 
n_bounds 6
bounds 570 27 9 -33 -20 -10 
property_list 
material 2
region 806
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-806
end_property_list 
<component> 816 
n_bounds 7
bounds 570 33 9 589 -36 -20 -10 
property_list 
material 2
region 807
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-807
end_property_list 
<component> 817 
n_bounds 4
bounds -589 -10 9 590 
property_list 
material 3
region 808
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-808
end_property_list 
<component> 818 
n_bounds 3
bounds -590 -10 9 
property_list 
material 4
region 809
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-809
end_property_list 
<component> 819 
n_bounds 7
bounds 570 36 9 591 -39 -20 -10 
property_list 
material 2
region 810
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-810
end_property_list 
<component> 820 
n_bounds 4
bounds -591 -10 9 592 
property_list 
material 3
region 811
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-811
end_property_list 
<component> 821 
n_bounds 3
bounds -592 -10 9 
property_list 
material 4
region 812
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-812
end_property_list 
<component> 822 
n_bounds 7
bounds 570 39 9 593 -42 -20 -10 
property_list 
material 2
region 813
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-813
end_property_list 
<component> 823 
n_bounds 4
bounds -593 -10 9 594 
property_list 
material 3
region 814
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-814
end_property_list 
<component> 824 
n_bounds 3
bounds -594 -10 9 
property_list 
material 4
region 815
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-815
end_property_list 
<component> 825 
n_bounds 7
bounds 570 42 9 595 -45 -20 -10 
property_list 
material 2
region 816
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-816
end_property_list 
<component> 826 
n_bounds 4
bounds -595 -10 9 596 
property_list 
material 3
region 817
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-817
end_property_list 
<component> 827 
n_bounds 3
bounds -596 -10 9 
property_list 
material 4
region 818
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-818
end_property_list 
<component> 828 
n_bounds 7
bounds 570 45 9 597 -48 -20 -10 
property_list 
material 2
region 819
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-819
end_property_list 
<component> 829 
n_bounds 4
bounds -597 -10 9 598 
property_list 
material 3
region 820
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-820
end_property_list 
<component> 830 
n_bounds 3
bounds -598 -10 9 
property_list 
material 4
region 821
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-821
end_property_list 
<component> 831 
n_bounds 8
bounds 20 23 52 600 9 -25 -599 -10 
property_list 
material 2
region 822
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-822
end_property_list 
<component> 832 
n_bounds 6
bounds 23 54 601 9 -600 -10 
property_list 
material 3
region 823
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-823
end_property_list 
<component> 833 
n_bounds 4
bounds 23 9 -601 -10 
property_list 
material 4
region 824
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-824
end_property_list 
<component> 834 
n_bounds 7
bounds 20 25 9 602 -27 -599 -10 
property_list 
material 2
region 825
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-825
end_property_list 
<component> 835 
n_bounds 4
bounds -602 -10 9 603 
property_list 
material 3
region 826
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-826
end_property_list 
<component> 836 
n_bounds 3
bounds -603 -10 9 
property_list 
material 4
region 827
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-827
end_property_list 
<component> 837 
n_bounds 7
bounds 20 27 9 604 -33 -599 -10 
property_list 
material 2
region 828
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-828
end_property_list 
<component> 838 
n_bounds 4
bounds -604 -10 9 605 
property_list 
material 3
region 829
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-829
end_property_list 
<component> 839 
n_bounds 3
bounds -605 -10 9 
property_list 
material 4
region 830
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-830
end_property_list 
<component> 840 
n_bounds 7
bounds 20 33 9 606 -36 -599 -10 
property_list 
material 2
region 831
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-831
end_property_list 
<component> 841 
n_bounds 4
bounds -606 -10 9 607 
property_list 
material 3
region 832
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-832
end_property_list 
<component> 842 
n_bounds 3
bounds -607 -10 9 
property_list 
material 4
region 833
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-833
end_property_list 
<component> 843 
n_bounds 7
bounds 20 36 9 608 -39 -599 -10 
property_list 
material 2
region 834
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-834
end_property_list 
<component> 844 
n_bounds 4
bounds -608 -10 9 609 
property_list 
material 3
region 835
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-835
end_property_list 
<component> 845 
n_bounds 3
bounds -609 -10 9 
property_list 
material 4
region 836
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-836
end_property_list 
<component> 846 
n_bounds 7
bounds 20 39 9 610 -42 -599 -10 
property_list 
material 2
region 837
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-837
end_property_list 
<component> 847 
n_bounds 4
bounds -610 -10 9 611 
property_list 
material 3
region 838
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-838
end_property_list 
<component> 848 
n_bounds 3
bounds -611 -10 9 
property_list 
material 4
region 839
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-839
end_property_list 
<component> 849 
n_bounds 7
bounds 20 42 9 612 -45 -599 -10 
property_list 
material 2
region 840
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-840
end_property_list 
<component> 850 
n_bounds 4
bounds -612 -10 9 613 
property_list 
material 3
region 841
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-841
end_property_list 
<component> 851 
n_bounds 3
bounds -613 -10 9 
property_list 
material 4
region 842
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-842
end_property_list 
<component> 852 
n_bounds 7
bounds 20 45 9 614 -48 -599 -10 
property_list 
material 2
region 843
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-843
end_property_list 
<component> 853 
n_bounds 4
bounds -614 -10 9 615 
property_list 
material 3
region 844
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-844
end_property_list 
<component> 854 
n_bounds 3
bounds -615 -10 9 
property_list 
material 4
region 845
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-845
end_property_list 
<component> 855 
n_bounds 8
bounds 599 23 52 617 9 -25 -616 -10 
property_list 
material 2
region 846
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-846
end_property_list 
<component> 856 
n_bounds 6
bounds 23 54 618 9 -617 -10 
property_list 
material 3
region 847
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-847
end_property_list 
<component> 857 
n_bounds 4
bounds 23 9 -618 -10 
property_list 
material 4
region 848
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-848
end_property_list 
<component> 858 
n_bounds 7
bounds 599 25 9 619 -27 -616 -10 
property_list 
material 2
region 849
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-849
end_property_list 
<component> 859 
n_bounds 4
bounds -619 -10 9 620 
property_list 
material 3
region 850
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-850
end_property_list 
<component> 860 
n_bounds 3
bounds -620 -10 9 
property_list 
material 4
region 851
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-851
end_property_list 
<component> 861 
n_bounds 7
bounds 599 27 9 621 -33 -616 -10 
property_list 
material 2
region 852
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-852
end_property_list 
<component> 862 
n_bounds 4
bounds -621 -10 9 622 
property_list 
material 3
region 853
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-853
end_property_list 
<component> 863 
n_bounds 3
bounds -622 -10 9 
property_list 
material 4
region 854
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-854
end_property_list 
<component> 864 
n_bounds 7
bounds 599 33 9 623 -36 -616 -10 
property_list 
material 2
region 855
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-855
end_property_list 
<component> 865 
n_bounds 4
bounds -623 -10 9 624 
property_list 
material 3
region 856
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-856
end_property_list 
<component> 866 
n_bounds 3
bounds -624 -10 9 
property_list 
material 4
region 857
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-857
end_property_list 
<component> 867 
n_bounds 7
bounds 599 36 9 625 -39 -616 -10 
property_list 
material 2
region 858
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-858
end_property_list 
<component> 868 
n_bounds 4
bounds -625 -10 9 626 
property_list 
material 3
region 859
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-859
end_property_list 
<component> 869 
n_bounds 3
bounds -626 -10 9 
property_list 
material 4
region 860
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-860
end_property_list 
<component> 870 
n_bounds 7
bounds 599 39 9 627 -42 -616 -10 
property_list 
material 2
region 861
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-861
end_property_list 
<component> 871 
n_bounds 4
bounds -627 -10 9 628 
property_list 
material 3
region 862
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-862
end_property_list 
<component> 872 
n_bounds 3
bounds -628 -10 9 
property_list 
material 4
region 863
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-863
end_property_list 
<component> 873 
n_bounds 7
bounds 599 42 9 629 -45 -616 -10 
property_list 
material 2
region 864
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-864
end_property_list 
<component> 874 
n_bounds 4
bounds -629 -10 9 630 
property_list 
material 3
region 865
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-865
end_property_list 
<component> 875 
n_bounds 3
bounds -630 -10 9 
property_list 
material 4
region 866
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-866
end_property_list 
<component> 876 
n_bounds 7
bounds 599 45 9 631 -48 -616 -10 
property_list 
material 2
region 867
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-867
end_property_list 
<component> 877 
n_bounds 4
bounds -631 -10 9 632 
property_list 
material 3
region 868
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-868
end_property_list 
<component> 878 
n_bounds 3
bounds -632 -10 9 
property_list 
material 4
region 869
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-869
end_property_list 
<component> 879 
n_bounds 7
bounds 146 48 9 633 -164 -398 -10 
property_list 
material 2
region 870
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-870
end_property_list 
<component> 880 
n_bounds 4
bounds -633 -10 9 634 
property_list 
material 3
region 871
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-871
end_property_list 
<component> 881 
n_bounds 3
bounds -634 -10 9 
property_list 
material 4
region 872
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-872
end_property_list 
<component> 882 
n_bounds 7
bounds 146 164 9 635 -167 -398 -10 
property_list 
material 2
region 873
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-873
end_property_list 
<component> 883 
n_bounds 4
bounds -635 -10 9 636 
property_list 
material 3
region 874
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-874
end_property_list 
<component> 884 
n_bounds 3
bounds -636 -10 9 
property_list 
material 4
region 875
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-875
end_property_list 
<component> 885 
n_bounds 7
bounds 146 167 9 637 -12 -398 -10 
property_list 
material 2
region 876
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-876
end_property_list 
<component> 886 
n_bounds 4
bounds -637 -10 9 638 
property_list 
material 3
region 877
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-877
end_property_list 
<component> 887 
n_bounds 3
bounds -638 -10 9 
property_list 
material 4
region 878
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-878
end_property_list 
<component> 888 
n_bounds 7
bounds 146 12 9 639 -172 -398 -10 
property_list 
material 2
region 879
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-879
end_property_list 
<component> 889 
n_bounds 4
bounds -639 -10 9 640 
property_list 
material 3
region 880
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-880
end_property_list 
<component> 890 
n_bounds 3
bounds -640 -10 9 
property_list 
material 4
region 881
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-881
end_property_list 
<component> 891 
n_bounds 7
bounds 146 172 9 641 -175 -398 -10 
property_list 
material 2
region 882
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-882
end_property_list 
<component> 892 
n_bounds 4
bounds -641 -10 9 642 
property_list 
material 3
region 883
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-883
end_property_list 
<component> 893 
n_bounds 3
bounds -642 -10 9 
property_list 
material 4
region 884
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-884
end_property_list 
<component> 894 
n_bounds 7
bounds 146 175 9 643 -178 -398 -10 
property_list 
material 2
region 885
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-885
end_property_list 
<component> 895 
n_bounds 4
bounds -643 -10 9 644 
property_list 
material 3
region 886
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-886
end_property_list 
<component> 896 
n_bounds 3
bounds -644 -10 9 
property_list 
material 4
region 887
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-887
end_property_list 
<component> 897 
n_bounds 7
bounds 146 178 9 645 -181 -398 -10 
property_list 
material 2
region 888
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-888
end_property_list 
<component> 898 
n_bounds 4
bounds -645 -10 9 646 
property_list 
material 3
region 889
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-889
end_property_list 
<component> 899 
n_bounds 3
bounds -646 -10 9 
property_list 
material 4
region 890
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-890
end_property_list 
<component> 900 
n_bounds 7
bounds 146 181 9 647 -183 -398 -10 
property_list 
material 2
region 891
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-891
end_property_list 
<component> 901 
n_bounds 4
bounds -647 -10 9 648 
property_list 
material 3
region 892
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-892
end_property_list 
<component> 902 
n_bounds 3
bounds -648 -10 9 
property_list 
material 4
region 893
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-893
end_property_list 
<component> 903 
n_bounds 7
bounds 146 183 9 649 -185 -398 -10 
property_list 
material 2
region 894
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-894
end_property_list 
<component> 904 
n_bounds 4
bounds -649 -10 9 650 
property_list 
material 3
region 895
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-895
end_property_list 
<component> 905 
n_bounds 3
bounds -650 -10 9 
property_list 
material 4
region 896
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-896
end_property_list 
<component> 906 
n_bounds 7
bounds 146 185 9 651 -188 -398 -10 
property_list 
material 2
region 897
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-897
end_property_list 
<component> 907 
n_bounds 4
bounds -651 -10 9 652 
property_list 
material 3
region 898
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-898
end_property_list 
<component> 908 
n_bounds 3
bounds -652 -10 9 
property_list 
material 4
region 899
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-899
end_property_list 
<component> 909 
n_bounds 7
bounds 146 188 9 653 -191 -398 -10 
property_list 
material 2
region 900
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-900
end_property_list 
<component> 910 
n_bounds 4
bounds -653 -10 9 654 
property_list 
material 3
region 901
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-901
end_property_list 
<component> 911 
n_bounds 3
bounds -654 -10 9 
property_list 
material 4
region 902
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-902
end_property_list 
<component> 912 
n_bounds 7
bounds 146 191 9 655 -194 -398 -10 
property_list 
material 2
region 903
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-903
end_property_list 
<component> 913 
n_bounds 4
bounds -655 -10 9 656 
property_list 
material 3
region 904
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-904
end_property_list 
<component> 914 
n_bounds 3
bounds -656 -10 9 
property_list 
material 4
region 905
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-905
end_property_list 
<component> 915 
n_bounds 7
bounds 146 194 9 657 -15 -398 -10 
property_list 
material 2
region 906
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-906
end_property_list 
<component> 916 
n_bounds 4
bounds -657 -10 9 658 
property_list 
material 3
region 907
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-907
end_property_list 
<component> 917 
n_bounds 3
bounds -658 -10 9 
property_list 
material 4
region 908
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-908
end_property_list 
<component> 918 
n_bounds 7
bounds 146 15 9 659 -199 -398 -10 
property_list 
material 2
region 909
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-909
end_property_list 
<component> 919 
n_bounds 4
bounds -659 -10 9 660 
property_list 
material 3
region 910
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-910
end_property_list 
<component> 920 
n_bounds 3
bounds -660 -10 9 
property_list 
material 4
region 911
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-911
end_property_list 
<component> 921 
n_bounds 7
bounds 146 199 9 661 -202 -398 -10 
property_list 
material 2
region 912
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-912
end_property_list 
<component> 922 
n_bounds 4
bounds -661 -10 9 662 
property_list 
material 3
region 913
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-913
end_property_list 
<component> 923 
n_bounds 3
bounds -662 -10 9 
property_list 
material 4
region 914
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-914
end_property_list 
<component> 924 
n_bounds 7
bounds 398 48 9 663 -164 -415 -10 
property_list 
material 2
region 915
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-915
end_property_list 
<component> 925 
n_bounds 4
bounds -663 -10 9 664 
property_list 
material 3
region 916
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-916
end_property_list 
<component> 926 
n_bounds 3
bounds -664 -10 9 
property_list 
material 4
region 917
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-917
end_property_list 
<component> 927 
n_bounds 7
bounds 398 164 9 665 -167 -415 -10 
property_list 
material 2
region 918
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-918
end_property_list 
<component> 928 
n_bounds 4
bounds -665 -10 9 666 
property_list 
material 3
region 919
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-919
end_property_list 
<component> 929 
n_bounds 3
bounds -666 -10 9 
property_list 
material 4
region 920
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-920
end_property_list 
<component> 930 
n_bounds 7
bounds 398 167 9 667 -12 -415 -10 
property_list 
material 2
region 921
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-921
end_property_list 
<component> 931 
n_bounds 4
bounds -667 -10 9 668 
property_list 
material 3
region 922
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-922
end_property_list 
<component> 932 
n_bounds 3
bounds -668 -10 9 
property_list 
material 4
region 923
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-923
end_property_list 
<component> 933 
n_bounds 7
bounds 398 12 9 669 -172 -415 -10 
property_list 
material 2
region 924
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-924
end_property_list 
<component> 934 
n_bounds 4
bounds -669 -10 9 670 
property_list 
material 3
region 925
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-925
end_property_list 
<component> 935 
n_bounds 3
bounds -670 -10 9 
property_list 
material 4
region 926
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-926
end_property_list 
<component> 936 
n_bounds 7
bounds 398 172 9 671 -175 -415 -10 
property_list 
material 2
region 927
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-927
end_property_list 
<component> 937 
n_bounds 4
bounds -671 -10 9 672 
property_list 
material 3
region 928
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-928
end_property_list 
<component> 938 
n_bounds 3
bounds -672 -10 9 
property_list 
material 4
region 929
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-929
end_property_list 
<component> 939 
n_bounds 7
bounds 398 175 9 673 -178 -415 -10 
property_list 
material 2
region 930
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-930
end_property_list 
<component> 940 
n_bounds 4
bounds -673 -10 9 674 
property_list 
material 3
region 931
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-931
end_property_list 
<component> 941 
n_bounds 3
bounds -674 -10 9 
property_list 
material 4
region 932
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-932
end_property_list 
<component> 942 
n_bounds 7
bounds 398 178 9 675 -181 -415 -10 
property_list 
material 2
region 933
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-933
end_property_list 
<component> 943 
n_bounds 4
bounds -675 -10 9 676 
property_list 
material 3
region 934
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-934
end_property_list 
<component> 944 
n_bounds 3
bounds -676 -10 9 
property_list 
material 4
region 935
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-935
end_property_list 
<component> 945 
n_bounds 7
bounds 398 181 9 677 -183 -415 -10 
property_list 
material 2
region 936
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-936
end_property_list 
<component> 946 
n_bounds 4
bounds -677 -10 9 678 
property_list 
material 3
region 937
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-937
end_property_list 
<component> 947 
n_bounds 3
bounds -678 -10 9 
property_list 
material 4
region 938
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-938
end_property_list 
<component> 948 
n_bounds 7
bounds 398 183 9 679 -185 -415 -10 
property_list 
material 2
region 939
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-939
end_property_list 
<component> 949 
n_bounds 4
bounds -679 -10 9 680 
property_list 
material 3
region 940
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-940
end_property_list 
<component> 950 
n_bounds 3
bounds -680 -10 9 
property_list 
material 4
region 941
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-941
end_property_list 
<component> 951 
n_bounds 7
bounds 398 185 9 681 -188 -415 -10 
property_list 
material 2
region 942
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-942
end_property_list 
<component> 952 
n_bounds 4
bounds -681 -10 9 682 
property_list 
material 3
region 943
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-943
end_property_list 
<component> 953 
n_bounds 3
bounds -682 -10 9 
property_list 
material 4
region 944
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-944
end_property_list 
<component> 954 
n_bounds 7
bounds 398 188 9 683 -191 -415 -10 
property_list 
material 2
region 945
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-945
end_property_list 
<component> 955 
n_bounds 4
bounds -683 -10 9 684 
property_list 
material 3
region 946
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-946
end_property_list 
<component> 956 
n_bounds 3
bounds -684 -10 9 
property_list 
material 4
region 947
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-947
end_property_list 
<component> 957 
n_bounds 7
bounds 398 191 9 685 -194 -415 -10 
property_list 
material 2
region 948
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-948
end_property_list 
<component> 958 
n_bounds 4
bounds -685 -10 9 686 
property_list 
material 3
region 949
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-949
end_property_list 
<component> 959 
n_bounds 3
bounds -686 -10 9 
property_list 
material 4
region 950
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-950
end_property_list 
<component> 960 
n_bounds 7
bounds 398 194 9 687 -15 -415 -10 
property_list 
material 2
region 951
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-951
end_property_list 
<component> 961 
n_bounds 4
bounds -687 -10 9 688 
property_list 
material 3
region 952
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-952
end_property_list 
<component> 962 
n_bounds 3
bounds -688 -10 9 
property_list 
material 4
region 953
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-953
end_property_list 
<component> 963 
n_bounds 7
bounds 398 15 9 689 -199 -415 -10 
property_list 
material 2
region 954
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-954
end_property_list 
<component> 964 
n_bounds 4
bounds -689 -10 9 690 
property_list 
material 3
region 955
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-955
end_property_list 
<component> 965 
n_bounds 3
bounds -690 -10 9 
property_list 
material 4
region 956
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-956
end_property_list 
<component> 966 
n_bounds 7
bounds 398 199 9 691 -202 -415 -10 
property_list 
material 2
region 957
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-957
end_property_list 
<component> 967 
n_bounds 4
bounds -691 -10 9 692 
property_list 
material 3
region 958
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-958
end_property_list 
<component> 968 
n_bounds 3
bounds -692 -10 9 
property_list 
material 4
region 959
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-959
end_property_list 
<component> 969 
n_bounds 7
bounds 415 48 9 693 -164 -21 -10 
property_list 
material 2
region 960
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-960
end_property_list 
<component> 970 
n_bounds 4
bounds -693 -10 9 694 
property_list 
material 3
region 961
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-961
end_property_list 
<component> 971 
n_bounds 3
bounds -694 -10 9 
property_list 
material 4
region 962
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-962
end_property_list 
<component> 972 
n_bounds 7
bounds 415 164 9 695 -167 -21 -10 
property_list 
material 2
region 963
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-963
end_property_list 
<component> 973 
n_bounds 4
bounds -695 -10 9 696 
property_list 
material 3
region 964
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-964
end_property_list 
<component> 974 
n_bounds 3
bounds -696 -10 9 
property_list 
material 4
region 965
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-965
end_property_list 
<component> 975 
n_bounds 7
bounds 415 167 9 697 -12 -21 -10 
property_list 
material 2
region 966
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-966
end_property_list 
<component> 976 
n_bounds 4
bounds -697 -10 9 698 
property_list 
material 3
region 967
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-967
end_property_list 
<component> 977 
n_bounds 3
bounds -698 -10 9 
property_list 
material 4
region 968
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-968
end_property_list 
<component> 978 
n_bounds 7
bounds 415 12 9 699 -172 -21 -10 
property_list 
material 2
region 969
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-969
end_property_list 
<component> 979 
n_bounds 4
bounds -699 -10 9 700 
property_list 
material 3
region 970
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-970
end_property_list 
<component> 980 
n_bounds 3
bounds -700 -10 9 
property_list 
material 4
region 971
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-971
end_property_list 
<component> 981 
n_bounds 7
bounds 415 172 9 701 -175 -21 -10 
property_list 
material 2
region 972
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-972
end_property_list 
<component> 982 
n_bounds 4
bounds -701 -10 9 702 
property_list 
material 3
region 973
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-973
end_property_list 
<component> 983 
n_bounds 3
bounds -702 -10 9 
property_list 
material 4
region 974
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-974
end_property_list 
<component> 984 
n_bounds 6
bounds 415 175 9 -178 -21 -10 
property_list 
material 2
region 975
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-975
end_property_list 
<component> 985 
n_bounds 7
bounds 415 178 9 703 -181 -21 -10 
property_list 
material 2
region 976
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-976
end_property_list 
<component> 986 
n_bounds 4
bounds -703 -10 9 704 
property_list 
material 3
region 977
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-977
end_property_list 
<component> 987 
n_bounds 3
bounds -704 -10 9 
property_list 
material 4
region 978
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-978
end_property_list 
<component> 988 
n_bounds 7
bounds 415 181 9 705 -183 -21 -10 
property_list 
material 2
region 979
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-979
end_property_list 
<component> 989 
n_bounds 4
bounds -705 -10 9 706 
property_list 
material 3
region 980
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-980
end_property_list 
<component> 990 
n_bounds 3
bounds -706 -10 9 
property_list 
material 4
region 981
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-981
end_property_list 
<component> 991 
n_bounds 7
bounds 415 183 9 707 -185 -21 -10 
property_list 
material 2
region 982
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-982
end_property_list 
<component> 992 
n_bounds 4
bounds -707 -10 9 708 
property_list 
material 3
region 983
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-983
end_property_list 
<component> 993 
n_bounds 3
bounds -708 -10 9 
property_list 
material 4
region 984
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-984
end_property_list 
<component> 994 
n_bounds 6
bounds 415 185 9 -188 -21 -10 
property_list 
material 2
region 985
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-985
end_property_list 
<component> 995 
n_bounds 7
bounds 415 188 9 709 -191 -21 -10 
property_list 
material 2
region 986
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-986
end_property_list 
<component> 996 
n_bounds 4
bounds -709 -10 9 710 
property_list 
material 3
region 987
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-987
end_property_list 
<component> 997 
n_bounds 3
bounds -710 -10 9 
property_list 
material 4
region 988
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-988
end_property_list 
<component> 998 
n_bounds 7
bounds 415 191 9 711 -194 -21 -10 
property_list 
material 2
region 989
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-989
end_property_list 
<component> 999 
n_bounds 4
bounds -711 -10 9 712 
property_list 
material 3
region 990
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-990
end_property_list 
<component> 1000 
n_bounds 3
bounds -712 -10 9 
property_list 
material 4
region 991
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-991
end_property_list 
<component> 1001 
n_bounds 7
bounds 415 194 9 713 -15 -21 -10 
property_list 
material 2
region 992
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-992
end_property_list 
<component> 1002 
n_bounds 4
bounds -713 -10 9 714 
property_list 
material 3
region 993
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-993
end_property_list 
<component> 1003 
n_bounds 3
bounds -714 -10 9 
property_list 
material 4
region 994
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-994
end_property_list 
<component> 1004 
n_bounds 7
bounds 415 15 9 715 -199 -21 -10 
property_list 
material 2
region 995
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-995
end_property_list 
<component> 1005 
n_bounds 4
bounds -715 -10 9 716 
property_list 
material 3
region 996
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-996
end_property_list 
<component> 1006 
n_bounds 3
bounds -716 -10 9 
property_list 
material 4
region 997
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-997
end_property_list 
<component> 1007 
n_bounds 7
bounds 415 199 9 717 -202 -21 -10 
property_list 
material 2
region 998
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-998
end_property_list 
<component> 1008 
n_bounds 4
bounds -717 -10 9 718 
property_list 
material 3
region 999
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-999
end_property_list 
<component> 1009 
n_bounds 3
bounds -718 -10 9 
property_list 
material 4
region 1000
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1000
end_property_list 
<component> 1010 
n_bounds 7
bounds 21 48 9 719 -164 -446 -10 
property_list 
material 2
region 1001
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1001
end_property_list 
<component> 1011 
n_bounds 4
bounds -719 -10 9 720 
property_list 
material 3
region 1002
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1002
end_property_list 
<component> 1012 
n_bounds 3
bounds -720 -10 9 
property_list 
material 4
region 1003
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1003
end_property_list 
<component> 1013 
n_bounds 7
bounds 21 164 9 721 -167 -446 -10 
property_list 
material 2
region 1004
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1004
end_property_list 
<component> 1014 
n_bounds 4
bounds -721 -10 9 722 
property_list 
material 3
region 1005
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1005
end_property_list 
<component> 1015 
n_bounds 3
bounds -722 -10 9 
property_list 
material 4
region 1006
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1006
end_property_list 
<component> 1016 
n_bounds 7
bounds 21 167 9 723 -12 -446 -10 
property_list 
material 2
region 1007
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1007
end_property_list 
<component> 1017 
n_bounds 4
bounds -723 -10 9 724 
property_list 
material 3
region 1008
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1008
end_property_list 
<component> 1018 
n_bounds 3
bounds -724 -10 9 
property_list 
material 4
region 1009
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1009
end_property_list 
<component> 1019 
n_bounds 6
bounds 21 12 9 -172 -446 -10 
property_list 
material 2
region 1010
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1010
end_property_list 
<component> 1020 
n_bounds 7
bounds 21 172 9 725 -175 -446 -10 
property_list 
material 2
region 1011
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1011
end_property_list 
<component> 1021 
n_bounds 4
bounds -725 -10 9 726 
property_list 
material 3
region 1012
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1012
end_property_list 
<component> 1022 
n_bounds 3
bounds -726 -10 9 
property_list 
material 4
region 1013
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1013
end_property_list 
<component> 1023 
n_bounds 7
bounds 21 175 9 727 -178 -446 -10 
property_list 
material 2
region 1014
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1014
end_property_list 
<component> 1024 
n_bounds 4
bounds -727 -10 9 728 
property_list 
material 3
region 1015
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1015
end_property_list 
<component> 1025 
n_bounds 3
bounds -728 -10 9 
property_list 
material 4
region 1016
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1016
end_property_list 
<component> 1026 
n_bounds 7
bounds 21 178 9 729 -181 -446 -10 
property_list 
material 2
region 1017
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1017
end_property_list 
<component> 1027 
n_bounds 4
bounds -729 -10 9 730 
property_list 
material 3
region 1018
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1018
end_property_list 
<component> 1028 
n_bounds 3
bounds -730 -10 9 
property_list 
material 4
region 1019
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1019
end_property_list 
<component> 1029 
n_bounds 7
bounds 21 181 9 731 -183 -446 -10 
property_list 
material 2
region 1020
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1020
end_property_list 
<component> 1030 
n_bounds 4
bounds -731 -10 9 732 
property_list 
material 3
region 1021
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1021
end_property_list 
<component> 1031 
n_bounds 3
bounds -732 -10 9 
property_list 
material 4
region 1022
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1022
end_property_list 
<component> 1032 
n_bounds 7
bounds 21 183 9 733 -185 -446 -10 
property_list 
material 2
region 1023
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1023
end_property_list 
<component> 1033 
n_bounds 4
bounds -733 -10 9 734 
property_list 
material 3
region 1024
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1024
end_property_list 
<component> 1034 
n_bounds 3
bounds -734 -10 9 
property_list 
material 4
region 1025
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1025
end_property_list 
<component> 1035 
n_bounds 7
bounds 21 185 9 735 -188 -446 -10 
property_list 
material 2
region 1026
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1026
end_property_list 
<component> 1036 
n_bounds 4
bounds -735 -10 9 736 
property_list 
material 3
region 1027
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1027
end_property_list 
<component> 1037 
n_bounds 3
bounds -736 -10 9 
property_list 
material 4
region 1028
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1028
end_property_list 
<component> 1038 
n_bounds 7
bounds 21 188 9 737 -191 -446 -10 
property_list 
material 2
region 1029
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1029
end_property_list 
<component> 1039 
n_bounds 4
bounds -737 -10 9 738 
property_list 
material 3
region 1030
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1030
end_property_list 
<component> 1040 
n_bounds 3
bounds -738 -10 9 
property_list 
material 4
region 1031
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1031
end_property_list 
<component> 1041 
n_bounds 6
bounds 21 191 9 -194 -446 -10 
property_list 
material 2
region 1032
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1032
end_property_list 
<component> 1042 
n_bounds 7
bounds 21 194 9 739 -15 -446 -10 
property_list 
material 2
region 1033
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1033
end_property_list 
<component> 1043 
n_bounds 4
bounds -739 -10 9 740 
property_list 
material 3
region 1034
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1034
end_property_list 
<component> 1044 
n_bounds 3
bounds -740 -10 9 
property_list 
material 4
region 1035
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1035
end_property_list 
<component> 1045 
n_bounds 7
bounds 21 15 9 741 -199 -446 -10 
property_list 
material 2
region 1036
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1036
end_property_list 
<component> 1046 
n_bounds 4
bounds -741 -10 9 742 
property_list 
material 3
region 1037
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1037
end_property_list 
<component> 1047 
n_bounds 3
bounds -742 -10 9 
property_list 
material 4
region 1038
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1038
end_property_list 
<component> 1048 
n_bounds 7
bounds 21 199 9 743 -202 -446 -10 
property_list 
material 2
region 1039
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1039
end_property_list 
<component> 1049 
n_bounds 4
bounds -743 -10 9 744 
property_list 
material 3
region 1040
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1040
end_property_list 
<component> 1050 
n_bounds 3
bounds -744 -10 9 
property_list 
material 4
region 1041
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1041
end_property_list 
<component> 1051 
n_bounds 7
bounds 446 48 9 745 -164 -461 -10 
property_list 
material 2
region 1042
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1042
end_property_list 
<component> 1052 
n_bounds 4
bounds -745 -10 9 746 
property_list 
material 3
region 1043
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1043
end_property_list 
<component> 1053 
n_bounds 3
bounds -746 -10 9 
property_list 
material 4
region 1044
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1044
end_property_list 
<component> 1054 
n_bounds 7
bounds 446 164 9 747 -167 -461 -10 
property_list 
material 2
region 1045
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1045
end_property_list 
<component> 1055 
n_bounds 4
bounds -747 -10 9 748 
property_list 
material 3
region 1046
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1046
end_property_list 
<component> 1056 
n_bounds 3
bounds -748 -10 9 
property_list 
material 4
region 1047
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1047
end_property_list 
<component> 1057 
n_bounds 7
bounds 446 167 9 749 -12 -461 -10 
property_list 
material 2
region 1048
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1048
end_property_list 
<component> 1058 
n_bounds 4
bounds -749 -10 9 750 
property_list 
material 3
region 1049
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1049
end_property_list 
<component> 1059 
n_bounds 3
bounds -750 -10 9 
property_list 
material 4
region 1050
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1050
end_property_list 
<component> 1060 
n_bounds 7
bounds 446 12 9 751 -172 -461 -10 
property_list 
material 2
region 1051
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1051
end_property_list 
<component> 1061 
n_bounds 4
bounds -751 -10 9 752 
property_list 
material 3
region 1052
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1052
end_property_list 
<component> 1062 
n_bounds 3
bounds -752 -10 9 
property_list 
material 4
region 1053
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1053
end_property_list 
<component> 1063 
n_bounds 7
bounds 446 172 9 753 -175 -461 -10 
property_list 
material 2
region 1054
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1054
end_property_list 
<component> 1064 
n_bounds 4
bounds -753 -10 9 754 
property_list 
material 3
region 1055
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1055
end_property_list 
<component> 1065 
n_bounds 3
bounds -754 -10 9 
property_list 
material 4
region 1056
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1056
end_property_list 
<component> 1066 
n_bounds 7
bounds 446 175 9 755 -178 -461 -10 
property_list 
material 2
region 1057
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1057
end_property_list 
<component> 1067 
n_bounds 4
bounds -755 -10 9 756 
property_list 
material 3
region 1058
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1058
end_property_list 
<component> 1068 
n_bounds 3
bounds -756 -10 9 
property_list 
material 4
region 1059
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1059
end_property_list 
<component> 1069 
n_bounds 7
bounds 446 178 9 757 -181 -461 -10 
property_list 
material 2
region 1060
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1060
end_property_list 
<component> 1070 
n_bounds 4
bounds -757 -10 9 758 
property_list 
material 3
region 1061
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1061
end_property_list 
<component> 1071 
n_bounds 3
bounds -758 -10 9 
property_list 
material 4
region 1062
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1062
end_property_list 
<component> 1072 
n_bounds 7
bounds 446 181 9 759 -183 -461 -10 
property_list 
material 2
region 1063
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1063
end_property_list 
<component> 1073 
n_bounds 4
bounds -759 -10 9 760 
property_list 
material 3
region 1064
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1064
end_property_list 
<component> 1074 
n_bounds 3
bounds -760 -10 9 
property_list 
material 4
region 1065
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1065
end_property_list 
<component> 1075 
n_bounds 7
bounds 446 183 9 761 -185 -461 -10 
property_list 
material 2
region 1066
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1066
end_property_list 
<component> 1076 
n_bounds 4
bounds -761 -10 9 762 
property_list 
material 3
region 1067
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1067
end_property_list 
<component> 1077 
n_bounds 3
bounds -762 -10 9 
property_list 
material 4
region 1068
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1068
end_property_list 
<component> 1078 
n_bounds 7
bounds 446 185 9 763 -188 -461 -10 
property_list 
material 2
region 1069
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1069
end_property_list 
<component> 1079 
n_bounds 4
bounds -763 -10 9 764 
property_list 
material 3
region 1070
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1070
end_property_list 
<component> 1080 
n_bounds 3
bounds -764 -10 9 
property_list 
material 4
region 1071
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1071
end_property_list 
<component> 1081 
n_bounds 7
bounds 446 188 9 765 -191 -461 -10 
property_list 
material 2
region 1072
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1072
end_property_list 
<component> 1082 
n_bounds 4
bounds -765 -10 9 766 
property_list 
material 3
region 1073
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1073
end_property_list 
<component> 1083 
n_bounds 3
bounds -766 -10 9 
property_list 
material 4
region 1074
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1074
end_property_list 
<component> 1084 
n_bounds 7
bounds 446 191 9 767 -194 -461 -10 
property_list 
material 2
region 1075
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1075
end_property_list 
<component> 1085 
n_bounds 4
bounds -767 -10 9 768 
property_list 
material 3
region 1076
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1076
end_property_list 
<component> 1086 
n_bounds 3
bounds -768 -10 9 
property_list 
material 4
region 1077
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1077
end_property_list 
<component> 1087 
n_bounds 7
bounds 446 194 9 769 -15 -461 -10 
property_list 
material 2
region 1078
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1078
end_property_list 
<component> 1088 
n_bounds 4
bounds -769 -10 9 770 
property_list 
material 3
region 1079
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1079
end_property_list 
<component> 1089 
n_bounds 3
bounds -770 -10 9 
property_list 
material 4
region 1080
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1080
end_property_list 
<component> 1090 
n_bounds 7
bounds 446 15 9 771 -199 -461 -10 
property_list 
material 2
region 1081
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1081
end_property_list 
<component> 1091 
n_bounds 4
bounds -771 -10 9 772 
property_list 
material 3
region 1082
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1082
end_property_list 
<component> 1092 
n_bounds 3
bounds -772 -10 9 
property_list 
material 4
region 1083
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1083
end_property_list 
<component> 1093 
n_bounds 7
bounds 446 199 9 773 -202 -461 -10 
property_list 
material 2
region 1084
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1084
end_property_list 
<component> 1094 
n_bounds 4
bounds -773 -10 9 774 
property_list 
material 3
region 1085
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1085
end_property_list 
<component> 1095 
n_bounds 3
bounds -774 -10 9 
property_list 
material 4
region 1086
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1086
end_property_list 
<component> 1096 
n_bounds 7
bounds 461 48 9 775 -164 -478 -10 
property_list 
material 2
region 1087
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1087
end_property_list 
<component> 1097 
n_bounds 4
bounds -775 -10 9 776 
property_list 
material 3
region 1088
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1088
end_property_list 
<component> 1098 
n_bounds 3
bounds -776 -10 9 
property_list 
material 4
region 1089
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1089
end_property_list 
<component> 1099 
n_bounds 7
bounds 461 164 9 777 -167 -478 -10 
property_list 
material 2
region 1090
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1090
end_property_list 
<component> 1100 
n_bounds 4
bounds -777 -10 9 778 
property_list 
material 3
region 1091
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1091
end_property_list 
<component> 1101 
n_bounds 3
bounds -778 -10 9 
property_list 
material 4
region 1092
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1092
end_property_list 
<component> 1102 
n_bounds 6
bounds 461 167 9 -12 -478 -10 
property_list 
material 2
region 1093
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1093
end_property_list 
<component> 1103 
n_bounds 7
bounds 461 12 9 779 -172 -478 -10 
property_list 
material 2
region 1094
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1094
end_property_list 
<component> 1104 
n_bounds 4
bounds -779 -10 9 780 
property_list 
material 3
region 1095
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1095
end_property_list 
<component> 1105 
n_bounds 3
bounds -780 -10 9 
property_list 
material 4
region 1096
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1096
end_property_list 
<component> 1106 
n_bounds 7
bounds 461 172 9 781 -175 -478 -10 
property_list 
material 2
region 1097
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1097
end_property_list 
<component> 1107 
n_bounds 4
bounds -781 -10 9 782 
property_list 
material 3
region 1098
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1098
end_property_list 
<component> 1108 
n_bounds 3
bounds -782 -10 9 
property_list 
material 4
region 1099
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1099
end_property_list 
<component> 1109 
n_bounds 6
bounds 461 175 9 -178 -478 -10 
property_list 
material 2
region 1100
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1100
end_property_list 
<component> 1110 
n_bounds 7
bounds 461 178 9 783 -181 -478 -10 
property_list 
material 2
region 1101
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1101
end_property_list 
<component> 1111 
n_bounds 4
bounds -783 -10 9 784 
property_list 
material 3
region 1102
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1102
end_property_list 
<component> 1112 
n_bounds 3
bounds -784 -10 9 
property_list 
material 4
region 1103
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1103
end_property_list 
<component> 1113 
n_bounds 7
bounds 461 181 9 785 -183 -478 -10 
property_list 
material 2
region 1104
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1104
end_property_list 
<component> 1114 
n_bounds 4
bounds -785 -10 9 786 
property_list 
material 3
region 1105
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1105
end_property_list 
<component> 1115 
n_bounds 3
bounds -786 -10 9 
property_list 
material 4
region 1106
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1106
end_property_list 
<component> 1116 
n_bounds 7
bounds 461 183 9 787 -185 -478 -10 
property_list 
material 2
region 1107
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1107
end_property_list 
<component> 1117 
n_bounds 4
bounds -787 -10 9 788 
property_list 
material 3
region 1108
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1108
end_property_list 
<component> 1118 
n_bounds 3
bounds -788 -10 9 
property_list 
material 4
region 1109
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1109
end_property_list 
<component> 1119 
n_bounds 6
bounds 461 185 9 -188 -478 -10 
property_list 
material 2
region 1110
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1110
end_property_list 
<component> 1120 
n_bounds 7
bounds 461 188 9 789 -191 -478 -10 
property_list 
material 2
region 1111
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1111
end_property_list 
<component> 1121 
n_bounds 4
bounds -789 -10 9 790 
property_list 
material 3
region 1112
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1112
end_property_list 
<component> 1122 
n_bounds 3
bounds -790 -10 9 
property_list 
material 4
region 1113
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1113
end_property_list 
<component> 1123 
n_bounds 7
bounds 461 191 9 791 -194 -478 -10 
property_list 
material 2
region 1114
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1114
end_property_list 
<component> 1124 
n_bounds 4
bounds -791 -10 9 792 
property_list 
material 3
region 1115
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1115
end_property_list 
<component> 1125 
n_bounds 3
bounds -792 -10 9 
property_list 
material 4
region 1116
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1116
end_property_list 
<component> 1126 
n_bounds 6
bounds 461 194 9 -15 -478 -10 
property_list 
material 2
region 1117
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1117
end_property_list 
<component> 1127 
n_bounds 7
bounds 461 15 9 793 -199 -478 -10 
property_list 
material 2
region 1118
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1118
end_property_list 
<component> 1128 
n_bounds 4
bounds -793 -10 9 794 
property_list 
material 3
region 1119
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1119
end_property_list 
<component> 1129 
n_bounds 3
bounds -794 -10 9 
property_list 
material 4
region 1120
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1120
end_property_list 
<component> 1130 
n_bounds 7
bounds 461 199 9 795 -202 -478 -10 
property_list 
material 2
region 1121
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1121
end_property_list 
<component> 1131 
n_bounds 4
bounds -795 -10 9 796 
property_list 
material 3
region 1122
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1122
end_property_list 
<component> 1132 
n_bounds 3
bounds -796 -10 9 
property_list 
material 4
region 1123
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1123
end_property_list 
<component> 1133 
n_bounds 7
bounds 478 48 9 797 -164 -491 -10 
property_list 
material 2
region 1124
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1124
end_property_list 
<component> 1134 
n_bounds 4
bounds -797 -10 9 798 
property_list 
material 3
region 1125
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1125
end_property_list 
<component> 1135 
n_bounds 3
bounds -798 -10 9 
property_list 
material 4
region 1126
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1126
end_property_list 
<component> 1136 
n_bounds 7
bounds 478 164 9 799 -167 -491 -10 
property_list 
material 2
region 1127
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1127
end_property_list 
<component> 1137 
n_bounds 4
bounds -799 -10 9 800 
property_list 
material 3
region 1128
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1128
end_property_list 
<component> 1138 
n_bounds 3
bounds -800 -10 9 
property_list 
material 4
region 1129
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1129
end_property_list 
<component> 1139 
n_bounds 7
bounds 478 167 9 801 -12 -491 -10 
property_list 
material 2
region 1130
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1130
end_property_list 
<component> 1140 
n_bounds 4
bounds -801 -10 9 802 
property_list 
material 3
region 1131
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1131
end_property_list 
<component> 1141 
n_bounds 3
bounds -802 -10 9 
property_list 
material 4
region 1132
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1132
end_property_list 
<component> 1142 
n_bounds 7
bounds 478 12 9 803 -172 -491 -10 
property_list 
material 2
region 1133
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1133
end_property_list 
<component> 1143 
n_bounds 4
bounds -803 -10 9 804 
property_list 
material 3
region 1134
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1134
end_property_list 
<component> 1144 
n_bounds 3
bounds -804 -10 9 
property_list 
material 4
region 1135
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1135
end_property_list 
<component> 1145 
n_bounds 7
bounds 478 172 9 805 -175 -491 -10 
property_list 
material 2
region 1136
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1136
end_property_list 
<component> 1146 
n_bounds 4
bounds -805 -10 9 806 
property_list 
material 3
region 1137
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1137
end_property_list 
<component> 1147 
n_bounds 3
bounds -806 -10 9 
property_list 
material 4
region 1138
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1138
end_property_list 
<component> 1148 
n_bounds 7
bounds 478 175 9 807 -178 -491 -10 
property_list 
material 2
region 1139
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1139
end_property_list 
<component> 1149 
n_bounds 4
bounds -807 -10 9 808 
property_list 
material 3
region 1140
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1140
end_property_list 
<component> 1150 
n_bounds 3
bounds -808 -10 9 
property_list 
material 4
region 1141
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1141
end_property_list 
<component> 1151 
n_bounds 7
bounds 478 178 9 809 -181 -491 -10 
property_list 
material 2
region 1142
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1142
end_property_list 
<component> 1152 
n_bounds 4
bounds -809 -10 9 810 
property_list 
material 3
region 1143
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1143
end_property_list 
<component> 1153 
n_bounds 3
bounds -810 -10 9 
property_list 
material 4
region 1144
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1144
end_property_list 
<component> 1154 
n_bounds 7
bounds 478 181 9 811 -183 -491 -10 
property_list 
material 2
region 1145
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1145
end_property_list 
<component> 1155 
n_bounds 4
bounds -811 -10 9 812 
property_list 
material 3
region 1146
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1146
end_property_list 
<component> 1156 
n_bounds 3
bounds -812 -10 9 
property_list 
material 4
region 1147
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1147
end_property_list 
<component> 1157 
n_bounds 7
bounds 478 183 9 813 -185 -491 -10 
property_list 
material 2
region 1148
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1148
end_property_list 
<component> 1158 
n_bounds 4
bounds -813 -10 9 814 
property_list 
material 3
region 1149
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1149
end_property_list 
<component> 1159 
n_bounds 3
bounds -814 -10 9 
property_list 
material 4
region 1150
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1150
end_property_list 
<component> 1160 
n_bounds 7
bounds 478 185 9 815 -188 -491 -10 
property_list 
material 2
region 1151
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1151
end_property_list 
<component> 1161 
n_bounds 4
bounds -815 -10 9 816 
property_list 
material 3
region 1152
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1152
end_property_list 
<component> 1162 
n_bounds 3
bounds -816 -10 9 
property_list 
material 4
region 1153
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1153
end_property_list 
<component> 1163 
n_bounds 7
bounds 478 188 9 817 -191 -491 -10 
property_list 
material 2
region 1154
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1154
end_property_list 
<component> 1164 
n_bounds 4
bounds -817 -10 9 818 
property_list 
material 3
region 1155
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1155
end_property_list 
<component> 1165 
n_bounds 3
bounds -818 -10 9 
property_list 
material 4
region 1156
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1156
end_property_list 
<component> 1166 
n_bounds 7
bounds 478 191 9 819 -194 -491 -10 
property_list 
material 2
region 1157
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1157
end_property_list 
<component> 1167 
n_bounds 4
bounds -819 -10 9 820 
property_list 
material 3
region 1158
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1158
end_property_list 
<component> 1168 
n_bounds 3
bounds -820 -10 9 
property_list 
material 4
region 1159
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1159
end_property_list 
<component> 1169 
n_bounds 7
bounds 478 194 9 821 -15 -491 -10 
property_list 
material 2
region 1160
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1160
end_property_list 
<component> 1170 
n_bounds 4
bounds -821 -10 9 822 
property_list 
material 3
region 1161
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1161
end_property_list 
<component> 1171 
n_bounds 3
bounds -822 -10 9 
property_list 
material 4
region 1162
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1162
end_property_list 
<component> 1172 
n_bounds 7
bounds 478 15 9 823 -199 -491 -10 
property_list 
material 2
region 1163
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1163
end_property_list 
<component> 1173 
n_bounds 4
bounds -823 -10 9 824 
property_list 
material 3
region 1164
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1164
end_property_list 
<component> 1174 
n_bounds 3
bounds -824 -10 9 
property_list 
material 4
region 1165
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1165
end_property_list 
<component> 1175 
n_bounds 7
bounds 478 199 9 825 -202 -491 -10 
property_list 
material 2
region 1166
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1166
end_property_list 
<component> 1176 
n_bounds 4
bounds -825 -10 9 826 
property_list 
material 3
region 1167
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1167
end_property_list 
<component> 1177 
n_bounds 3
bounds -826 -10 9 
property_list 
material 4
region 1168
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1168
end_property_list 
<component> 1178 
n_bounds 7
bounds 491 48 9 827 -164 -508 -10 
property_list 
material 2
region 1169
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1169
end_property_list 
<component> 1179 
n_bounds 4
bounds -827 -10 9 828 
property_list 
material 3
region 1170
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1170
end_property_list 
<component> 1180 
n_bounds 3
bounds -828 -10 9 
property_list 
material 4
region 1171
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1171
end_property_list 
<component> 1181 
n_bounds 7
bounds 491 164 9 829 -167 -508 -10 
property_list 
material 2
region 1172
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1172
end_property_list 
<component> 1182 
n_bounds 4
bounds -829 -10 9 830 
property_list 
material 3
region 1173
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1173
end_property_list 
<component> 1183 
n_bounds 3
bounds -830 -10 9 
property_list 
material 4
region 1174
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1174
end_property_list 
<component> 1184 
n_bounds 7
bounds 491 167 9 831 -12 -508 -10 
property_list 
material 2
region 1175
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1175
end_property_list 
<component> 1185 
n_bounds 4
bounds -831 -10 9 832 
property_list 
material 3
region 1176
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1176
end_property_list 
<component> 1186 
n_bounds 3
bounds -832 -10 9 
property_list 
material 4
region 1177
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1177
end_property_list 
<component> 1187 
n_bounds 7
bounds 491 12 9 833 -172 -508 -10 
property_list 
material 2
region 1178
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1178
end_property_list 
<component> 1188 
n_bounds 4
bounds -833 -10 9 834 
property_list 
material 3
region 1179
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1179
end_property_list 
<component> 1189 
n_bounds 3
bounds -834 -10 9 
property_list 
material 4
region 1180
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1180
end_property_list 
<component> 1190 
n_bounds 7
bounds 491 172 9 835 -175 -508 -10 
property_list 
material 2
region 1181
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1181
end_property_list 
<component> 1191 
n_bounds 4
bounds -835 -10 9 836 
property_list 
material 3
region 1182
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1182
end_property_list 
<component> 1192 
n_bounds 3
bounds -836 -10 9 
property_list 
material 4
region 1183
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1183
end_property_list 
<component> 1193 
n_bounds 7
bounds 491 175 9 837 -178 -508 -10 
property_list 
material 2
region 1184
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1184
end_property_list 
<component> 1194 
n_bounds 4
bounds -837 -10 9 838 
property_list 
material 3
region 1185
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1185
end_property_list 
<component> 1195 
n_bounds 3
bounds -838 -10 9 
property_list 
material 4
region 1186
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1186
end_property_list 
<component> 1196 
n_bounds 7
bounds 491 178 9 839 -181 -508 -10 
property_list 
material 2
region 1187
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1187
end_property_list 
<component> 1197 
n_bounds 4
bounds -839 -10 9 840 
property_list 
material 3
region 1188
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1188
end_property_list 
<component> 1198 
n_bounds 3
bounds -840 -10 9 
property_list 
material 4
region 1189
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1189
end_property_list 
<component> 1199 
n_bounds 6
bounds 491 181 9 -183 -508 -10 
property_list 
material 2
region 1190
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1190
end_property_list 
<component> 1200 
n_bounds 7
bounds 491 183 9 841 -185 -508 -10 
property_list 
material 2
region 1191
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1191
end_property_list 
<component> 1201 
n_bounds 4
bounds -841 -10 9 842 
property_list 
material 3
region 1192
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1192
end_property_list 
<component> 1202 
n_bounds 3
bounds -842 -10 9 
property_list 
material 4
region 1193
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1193
end_property_list 
<component> 1203 
n_bounds 7
bounds 491 185 9 843 -188 -508 -10 
property_list 
material 2
region 1194
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1194
end_property_list 
<component> 1204 
n_bounds 4
bounds -843 -10 9 844 
property_list 
material 3
region 1195
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1195
end_property_list 
<component> 1205 
n_bounds 3
bounds -844 -10 9 
property_list 
material 4
region 1196
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1196
end_property_list 
<component> 1206 
n_bounds 7
bounds 491 188 9 845 -191 -508 -10 
property_list 
material 2
region 1197
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1197
end_property_list 
<component> 1207 
n_bounds 4
bounds -845 -10 9 846 
property_list 
material 3
region 1198
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1198
end_property_list 
<component> 1208 
n_bounds 3
bounds -846 -10 9 
property_list 
material 4
region 1199
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1199
end_property_list 
<component> 1209 
n_bounds 7
bounds 491 191 9 847 -194 -508 -10 
property_list 
material 2
region 1200
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1200
end_property_list 
<component> 1210 
n_bounds 4
bounds -847 -10 9 848 
property_list 
material 3
region 1201
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1201
end_property_list 
<component> 1211 
n_bounds 3
bounds -848 -10 9 
property_list 
material 4
region 1202
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1202
end_property_list 
<component> 1212 
n_bounds 7
bounds 491 194 9 849 -15 -508 -10 
property_list 
material 2
region 1203
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1203
end_property_list 
<component> 1213 
n_bounds 4
bounds -849 -10 9 850 
property_list 
material 3
region 1204
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1204
end_property_list 
<component> 1214 
n_bounds 3
bounds -850 -10 9 
property_list 
material 4
region 1205
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1205
end_property_list 
<component> 1215 
n_bounds 7
bounds 491 15 9 851 -199 -508 -10 
property_list 
material 2
region 1206
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1206
end_property_list 
<component> 1216 
n_bounds 4
bounds -851 -10 9 852 
property_list 
material 3
region 1207
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1207
end_property_list 
<component> 1217 
n_bounds 3
bounds -852 -10 9 
property_list 
material 4
region 1208
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1208
end_property_list 
<component> 1218 
n_bounds 7
bounds 491 199 9 853 -202 -508 -10 
property_list 
material 2
region 1209
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1209
end_property_list 
<component> 1219 
n_bounds 4
bounds -853 -10 9 854 
property_list 
material 3
region 1210
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1210
end_property_list 
<component> 1220 
n_bounds 3
bounds -854 -10 9 
property_list 
material 4
region 1211
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1211
end_property_list 
<component> 1221 
n_bounds 7
bounds 508 48 9 855 -164 -523 -10 
property_list 
material 2
region 1212
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1212
end_property_list 
<component> 1222 
n_bounds 4
bounds -855 -10 9 856 
property_list 
material 3
region 1213
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1213
end_property_list 
<component> 1223 
n_bounds 3
bounds -856 -10 9 
property_list 
material 4
region 1214
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1214
end_property_list 
<component> 1224 
n_bounds 7
bounds 508 164 9 857 -167 -523 -10 
property_list 
material 2
region 1215
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1215
end_property_list 
<component> 1225 
n_bounds 4
bounds -857 -10 9 858 
property_list 
material 3
region 1216
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1216
end_property_list 
<component> 1226 
n_bounds 3
bounds -858 -10 9 
property_list 
material 4
region 1217
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1217
end_property_list 
<component> 1227 
n_bounds 7
bounds 508 167 9 859 -12 -523 -10 
property_list 
material 2
region 1218
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1218
end_property_list 
<component> 1228 
n_bounds 4
bounds -859 -10 9 860 
property_list 
material 3
region 1219
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1219
end_property_list 
<component> 1229 
n_bounds 3
bounds -860 -10 9 
property_list 
material 4
region 1220
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1220
end_property_list 
<component> 1230 
n_bounds 7
bounds 508 12 9 861 -172 -523 -10 
property_list 
material 2
region 1221
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1221
end_property_list 
<component> 1231 
n_bounds 4
bounds -861 -10 9 862 
property_list 
material 3
region 1222
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1222
end_property_list 
<component> 1232 
n_bounds 3
bounds -862 -10 9 
property_list 
material 4
region 1223
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1223
end_property_list 
<component> 1233 
n_bounds 7
bounds 508 172 9 863 -175 -523 -10 
property_list 
material 2
region 1224
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1224
end_property_list 
<component> 1234 
n_bounds 4
bounds -863 -10 9 864 
property_list 
material 3
region 1225
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1225
end_property_list 
<component> 1235 
n_bounds 3
bounds -864 -10 9 
property_list 
material 4
region 1226
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1226
end_property_list 
<component> 1236 
n_bounds 7
bounds 508 175 9 865 -178 -523 -10 
property_list 
material 2
region 1227
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1227
end_property_list 
<component> 1237 
n_bounds 4
bounds -865 -10 9 866 
property_list 
material 3
region 1228
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1228
end_property_list 
<component> 1238 
n_bounds 3
bounds -866 -10 9 
property_list 
material 4
region 1229
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1229
end_property_list 
<component> 1239 
n_bounds 7
bounds 508 178 9 867 -181 -523 -10 
property_list 
material 2
region 1230
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1230
end_property_list 
<component> 1240 
n_bounds 4
bounds -867 -10 9 868 
property_list 
material 3
region 1231
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1231
end_property_list 
<component> 1241 
n_bounds 3
bounds -868 -10 9 
property_list 
material 4
region 1232
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1232
end_property_list 
<component> 1242 
n_bounds 7
bounds 508 181 9 869 -183 -523 -10 
property_list 
material 2
region 1233
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1233
end_property_list 
<component> 1243 
n_bounds 4
bounds -869 -10 9 870 
property_list 
material 3
region 1234
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1234
end_property_list 
<component> 1244 
n_bounds 3
bounds -870 -10 9 
property_list 
material 4
region 1235
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1235
end_property_list 
<component> 1245 
n_bounds 7
bounds 508 183 9 871 -185 -523 -10 
property_list 
material 2
region 1236
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1236
end_property_list 
<component> 1246 
n_bounds 4
bounds -871 -10 9 872 
property_list 
material 3
region 1237
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1237
end_property_list 
<component> 1247 
n_bounds 3
bounds -872 -10 9 
property_list 
material 4
region 1238
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1238
end_property_list 
<component> 1248 
n_bounds 7
bounds 508 185 9 873 -188 -523 -10 
property_list 
material 2
region 1239
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1239
end_property_list 
<component> 1249 
n_bounds 4
bounds -873 -10 9 874 
property_list 
material 3
region 1240
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1240
end_property_list 
<component> 1250 
n_bounds 3
bounds -874 -10 9 
property_list 
material 4
region 1241
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1241
end_property_list 
<component> 1251 
n_bounds 7
bounds 508 188 9 875 -191 -523 -10 
property_list 
material 2
region 1242
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1242
end_property_list 
<component> 1252 
n_bounds 4
bounds -875 -10 9 876 
property_list 
material 3
region 1243
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1243
end_property_list 
<component> 1253 
n_bounds 3
bounds -876 -10 9 
property_list 
material 4
region 1244
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1244
end_property_list 
<component> 1254 
n_bounds 7
bounds 508 191 9 877 -194 -523 -10 
property_list 
material 2
region 1245
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1245
end_property_list 
<component> 1255 
n_bounds 4
bounds -877 -10 9 878 
property_list 
material 3
region 1246
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1246
end_property_list 
<component> 1256 
n_bounds 3
bounds -878 -10 9 
property_list 
material 4
region 1247
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1247
end_property_list 
<component> 1257 
n_bounds 7
bounds 508 194 9 879 -15 -523 -10 
property_list 
material 2
region 1248
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1248
end_property_list 
<component> 1258 
n_bounds 4
bounds -879 -10 9 880 
property_list 
material 3
region 1249
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1249
end_property_list 
<component> 1259 
n_bounds 3
bounds -880 -10 9 
property_list 
material 4
region 1250
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1250
end_property_list 
<component> 1260 
n_bounds 7
bounds 508 15 9 881 -199 -523 -10 
property_list 
material 2
region 1251
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1251
end_property_list 
<component> 1261 
n_bounds 4
bounds -881 -10 9 882 
property_list 
material 3
region 1252
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1252
end_property_list 
<component> 1262 
n_bounds 3
bounds -882 -10 9 
property_list 
material 4
region 1253
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1253
end_property_list 
<component> 1263 
n_bounds 7
bounds 508 199 9 883 -202 -523 -10 
property_list 
material 2
region 1254
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1254
end_property_list 
<component> 1264 
n_bounds 4
bounds -883 -10 9 884 
property_list 
material 3
region 1255
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1255
end_property_list 
<component> 1265 
n_bounds 3
bounds -884 -10 9 
property_list 
material 4
region 1256
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1256
end_property_list 
<component> 1266 
n_bounds 7
bounds 523 48 9 885 -164 -540 -10 
property_list 
material 2
region 1257
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1257
end_property_list 
<component> 1267 
n_bounds 4
bounds -885 -10 9 886 
property_list 
material 3
region 1258
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1258
end_property_list 
<component> 1268 
n_bounds 3
bounds -886 -10 9 
property_list 
material 4
region 1259
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1259
end_property_list 
<component> 1269 
n_bounds 7
bounds 523 164 9 887 -167 -540 -10 
property_list 
material 2
region 1260
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1260
end_property_list 
<component> 1270 
n_bounds 4
bounds -887 -10 9 888 
property_list 
material 3
region 1261
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1261
end_property_list 
<component> 1271 
n_bounds 3
bounds -888 -10 9 
property_list 
material 4
region 1262
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1262
end_property_list 
<component> 1272 
n_bounds 6
bounds 523 167 9 -12 -540 -10 
property_list 
material 2
region 1263
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1263
end_property_list 
<component> 1273 
n_bounds 7
bounds 523 12 9 889 -172 -540 -10 
property_list 
material 2
region 1264
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1264
end_property_list 
<component> 1274 
n_bounds 4
bounds -889 -10 9 890 
property_list 
material 3
region 1265
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1265
end_property_list 
<component> 1275 
n_bounds 3
bounds -890 -10 9 
property_list 
material 4
region 1266
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1266
end_property_list 
<component> 1276 
n_bounds 7
bounds 523 172 9 891 -175 -540 -10 
property_list 
material 2
region 1267
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1267
end_property_list 
<component> 1277 
n_bounds 4
bounds -891 -10 9 892 
property_list 
material 3
region 1268
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1268
end_property_list 
<component> 1278 
n_bounds 3
bounds -892 -10 9 
property_list 
material 4
region 1269
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1269
end_property_list 
<component> 1279 
n_bounds 6
bounds 523 175 9 -178 -540 -10 
property_list 
material 2
region 1270
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1270
end_property_list 
<component> 1280 
n_bounds 7
bounds 523 178 9 893 -181 -540 -10 
property_list 
material 2
region 1271
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1271
end_property_list 
<component> 1281 
n_bounds 4
bounds -893 -10 9 894 
property_list 
material 3
region 1272
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1272
end_property_list 
<component> 1282 
n_bounds 3
bounds -894 -10 9 
property_list 
material 4
region 1273
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1273
end_property_list 
<component> 1283 
n_bounds 7
bounds 523 181 9 895 -183 -540 -10 
property_list 
material 2
region 1274
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1274
end_property_list 
<component> 1284 
n_bounds 4
bounds -895 -10 9 896 
property_list 
material 3
region 1275
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1275
end_property_list 
<component> 1285 
n_bounds 3
bounds -896 -10 9 
property_list 
material 4
region 1276
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1276
end_property_list 
<component> 1286 
n_bounds 7
bounds 523 183 9 897 -185 -540 -10 
property_list 
material 2
region 1277
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1277
end_property_list 
<component> 1287 
n_bounds 4
bounds -897 -10 9 898 
property_list 
material 3
region 1278
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1278
end_property_list 
<component> 1288 
n_bounds 3
bounds -898 -10 9 
property_list 
material 4
region 1279
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1279
end_property_list 
<component> 1289 
n_bounds 6
bounds 523 185 9 -188 -540 -10 
property_list 
material 2
region 1280
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1280
end_property_list 
<component> 1290 
n_bounds 7
bounds 523 188 9 899 -191 -540 -10 
property_list 
material 2
region 1281
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1281
end_property_list 
<component> 1291 
n_bounds 4
bounds -899 -10 9 900 
property_list 
material 3
region 1282
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1282
end_property_list 
<component> 1292 
n_bounds 3
bounds -900 -10 9 
property_list 
material 4
region 1283
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1283
end_property_list 
<component> 1293 
n_bounds 7
bounds 523 191 9 901 -194 -540 -10 
property_list 
material 2
region 1284
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1284
end_property_list 
<component> 1294 
n_bounds 4
bounds -901 -10 9 902 
property_list 
material 3
region 1285
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1285
end_property_list 
<component> 1295 
n_bounds 3
bounds -902 -10 9 
property_list 
material 4
region 1286
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1286
end_property_list 
<component> 1296 
n_bounds 6
bounds 523 194 9 -15 -540 -10 
property_list 
material 2
region 1287
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1287
end_property_list 
<component> 1297 
n_bounds 7
bounds 523 15 9 903 -199 -540 -10 
property_list 
material 2
region 1288
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1288
end_property_list 
<component> 1298 
n_bounds 4
bounds -903 -10 9 904 
property_list 
material 3
region 1289
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1289
end_property_list 
<component> 1299 
n_bounds 3
bounds -904 -10 9 
property_list 
material 4
region 1290
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1290
end_property_list 
<component> 1300 
n_bounds 7
bounds 523 199 9 905 -202 -540 -10 
property_list 
material 2
region 1291
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1291
end_property_list 
<component> 1301 
n_bounds 4
bounds -905 -10 9 906 
property_list 
material 3
region 1292
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1292
end_property_list 
<component> 1302 
n_bounds 3
bounds -906 -10 9 
property_list 
material 4
region 1293
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1293
end_property_list 
<component> 1303 
n_bounds 7
bounds 540 48 9 907 -164 -553 -10 
property_list 
material 2
region 1294
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1294
end_property_list 
<component> 1304 
n_bounds 4
bounds -907 -10 9 908 
property_list 
material 3
region 1295
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1295
end_property_list 
<component> 1305 
n_bounds 3
bounds -908 -10 9 
property_list 
material 4
region 1296
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1296
end_property_list 
<component> 1306 
n_bounds 7
bounds 540 164 9 909 -167 -553 -10 
property_list 
material 2
region 1297
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1297
end_property_list 
<component> 1307 
n_bounds 4
bounds -909 -10 9 910 
property_list 
material 3
region 1298
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1298
end_property_list 
<component> 1308 
n_bounds 3
bounds -910 -10 9 
property_list 
material 4
region 1299
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1299
end_property_list 
<component> 1309 
n_bounds 7
bounds 540 167 9 911 -12 -553 -10 
property_list 
material 2
region 1300
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1300
end_property_list 
<component> 1310 
n_bounds 4
bounds -911 -10 9 912 
property_list 
material 3
region 1301
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1301
end_property_list 
<component> 1311 
n_bounds 3
bounds -912 -10 9 
property_list 
material 4
region 1302
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1302
end_property_list 
<component> 1312 
n_bounds 7
bounds 540 12 9 913 -172 -553 -10 
property_list 
material 2
region 1303
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1303
end_property_list 
<component> 1313 
n_bounds 4
bounds -913 -10 9 914 
property_list 
material 3
region 1304
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1304
end_property_list 
<component> 1314 
n_bounds 3
bounds -914 -10 9 
property_list 
material 4
region 1305
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1305
end_property_list 
<component> 1315 
n_bounds 7
bounds 540 172 9 915 -175 -553 -10 
property_list 
material 2
region 1306
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1306
end_property_list 
<component> 1316 
n_bounds 4
bounds -915 -10 9 916 
property_list 
material 3
region 1307
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1307
end_property_list 
<component> 1317 
n_bounds 3
bounds -916 -10 9 
property_list 
material 4
region 1308
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1308
end_property_list 
<component> 1318 
n_bounds 7
bounds 540 175 9 917 -178 -553 -10 
property_list 
material 2
region 1309
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1309
end_property_list 
<component> 1319 
n_bounds 4
bounds -917 -10 9 918 
property_list 
material 3
region 1310
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1310
end_property_list 
<component> 1320 
n_bounds 3
bounds -918 -10 9 
property_list 
material 4
region 1311
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1311
end_property_list 
<component> 1321 
n_bounds 7
bounds 540 178 9 919 -181 -553 -10 
property_list 
material 2
region 1312
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1312
end_property_list 
<component> 1322 
n_bounds 4
bounds -919 -10 9 920 
property_list 
material 3
region 1313
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1313
end_property_list 
<component> 1323 
n_bounds 3
bounds -920 -10 9 
property_list 
material 4
region 1314
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1314
end_property_list 
<component> 1324 
n_bounds 7
bounds 540 181 9 921 -183 -553 -10 
property_list 
material 2
region 1315
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1315
end_property_list 
<component> 1325 
n_bounds 4
bounds -921 -10 9 922 
property_list 
material 3
region 1316
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1316
end_property_list 
<component> 1326 
n_bounds 3
bounds -922 -10 9 
property_list 
material 4
region 1317
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1317
end_property_list 
<component> 1327 
n_bounds 7
bounds 540 183 9 923 -185 -553 -10 
property_list 
material 2
region 1318
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1318
end_property_list 
<component> 1328 
n_bounds 4
bounds -923 -10 9 924 
property_list 
material 3
region 1319
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1319
end_property_list 
<component> 1329 
n_bounds 3
bounds -924 -10 9 
property_list 
material 4
region 1320
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1320
end_property_list 
<component> 1330 
n_bounds 7
bounds 540 185 9 925 -188 -553 -10 
property_list 
material 2
region 1321
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1321
end_property_list 
<component> 1331 
n_bounds 4
bounds -925 -10 9 926 
property_list 
material 3
region 1322
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1322
end_property_list 
<component> 1332 
n_bounds 3
bounds -926 -10 9 
property_list 
material 4
region 1323
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1323
end_property_list 
<component> 1333 
n_bounds 7
bounds 540 188 9 927 -191 -553 -10 
property_list 
material 2
region 1324
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1324
end_property_list 
<component> 1334 
n_bounds 4
bounds -927 -10 9 928 
property_list 
material 3
region 1325
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1325
end_property_list 
<component> 1335 
n_bounds 3
bounds -928 -10 9 
property_list 
material 4
region 1326
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1326
end_property_list 
<component> 1336 
n_bounds 7
bounds 540 191 9 929 -194 -553 -10 
property_list 
material 2
region 1327
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1327
end_property_list 
<component> 1337 
n_bounds 4
bounds -929 -10 9 930 
property_list 
material 3
region 1328
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1328
end_property_list 
<component> 1338 
n_bounds 3
bounds -930 -10 9 
property_list 
material 4
region 1329
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1329
end_property_list 
<component> 1339 
n_bounds 7
bounds 540 194 9 931 -15 -553 -10 
property_list 
material 2
region 1330
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1330
end_property_list 
<component> 1340 
n_bounds 4
bounds -931 -10 9 932 
property_list 
material 3
region 1331
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1331
end_property_list 
<component> 1341 
n_bounds 3
bounds -932 -10 9 
property_list 
material 4
region 1332
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1332
end_property_list 
<component> 1342 
n_bounds 7
bounds 540 15 9 933 -199 -553 -10 
property_list 
material 2
region 1333
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1333
end_property_list 
<component> 1343 
n_bounds 4
bounds -933 -10 9 934 
property_list 
material 3
region 1334
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1334
end_property_list 
<component> 1344 
n_bounds 3
bounds -934 -10 9 
property_list 
material 4
region 1335
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1335
end_property_list 
<component> 1345 
n_bounds 7
bounds 540 199 9 935 -202 -553 -10 
property_list 
material 2
region 1336
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1336
end_property_list 
<component> 1346 
n_bounds 4
bounds -935 -10 9 936 
property_list 
material 3
region 1337
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1337
end_property_list 
<component> 1347 
n_bounds 3
bounds -936 -10 9 
property_list 
material 4
region 1338
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1338
end_property_list 
<component> 1348 
n_bounds 7
bounds 553 48 9 937 -164 -570 -10 
property_list 
material 2
region 1339
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1339
end_property_list 
<component> 1349 
n_bounds 4
bounds -937 -10 9 938 
property_list 
material 3
region 1340
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1340
end_property_list 
<component> 1350 
n_bounds 3
bounds -938 -10 9 
property_list 
material 4
region 1341
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1341
end_property_list 
<component> 1351 
n_bounds 7
bounds 553 164 9 939 -167 -570 -10 
property_list 
material 2
region 1342
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1342
end_property_list 
<component> 1352 
n_bounds 4
bounds -939 -10 9 940 
property_list 
material 3
region 1343
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1343
end_property_list 
<component> 1353 
n_bounds 3
bounds -940 -10 9 
property_list 
material 4
region 1344
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1344
end_property_list 
<component> 1354 
n_bounds 7
bounds 553 167 9 941 -12 -570 -10 
property_list 
material 2
region 1345
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1345
end_property_list 
<component> 1355 
n_bounds 4
bounds -941 -10 9 942 
property_list 
material 3
region 1346
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1346
end_property_list 
<component> 1356 
n_bounds 3
bounds -942 -10 9 
property_list 
material 4
region 1347
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1347
end_property_list 
<component> 1357 
n_bounds 6
bounds 553 12 9 -172 -570 -10 
property_list 
material 2
region 1348
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1348
end_property_list 
<component> 1358 
n_bounds 7
bounds 553 172 9 943 -175 -570 -10 
property_list 
material 2
region 1349
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1349
end_property_list 
<component> 1359 
n_bounds 4
bounds -943 -10 9 944 
property_list 
material 3
region 1350
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1350
end_property_list 
<component> 1360 
n_bounds 3
bounds -944 -10 9 
property_list 
material 4
region 1351
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1351
end_property_list 
<component> 1361 
n_bounds 7
bounds 553 175 9 945 -178 -570 -10 
property_list 
material 2
region 1352
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1352
end_property_list 
<component> 1362 
n_bounds 4
bounds -945 -10 9 946 
property_list 
material 3
region 1353
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1353
end_property_list 
<component> 1363 
n_bounds 3
bounds -946 -10 9 
property_list 
material 4
region 1354
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1354
end_property_list 
<component> 1364 
n_bounds 7
bounds 553 178 9 947 -181 -570 -10 
property_list 
material 2
region 1355
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1355
end_property_list 
<component> 1365 
n_bounds 4
bounds -947 -10 9 948 
property_list 
material 3
region 1356
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1356
end_property_list 
<component> 1366 
n_bounds 3
bounds -948 -10 9 
property_list 
material 4
region 1357
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1357
end_property_list 
<component> 1367 
n_bounds 7
bounds 553 181 9 949 -183 -570 -10 
property_list 
material 2
region 1358
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1358
end_property_list 
<component> 1368 
n_bounds 4
bounds -949 -10 9 950 
property_list 
material 3
region 1359
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1359
end_property_list 
<component> 1369 
n_bounds 3
bounds -950 -10 9 
property_list 
material 4
region 1360
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1360
end_property_list 
<component> 1370 
n_bounds 7
bounds 553 183 9 951 -185 -570 -10 
property_list 
material 2
region 1361
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1361
end_property_list 
<component> 1371 
n_bounds 4
bounds -951 -10 9 952 
property_list 
material 3
region 1362
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1362
end_property_list 
<component> 1372 
n_bounds 3
bounds -952 -10 9 
property_list 
material 4
region 1363
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1363
end_property_list 
<component> 1373 
n_bounds 7
bounds 553 185 9 953 -188 -570 -10 
property_list 
material 2
region 1364
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1364
end_property_list 
<component> 1374 
n_bounds 4
bounds -953 -10 9 954 
property_list 
material 3
region 1365
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1365
end_property_list 
<component> 1375 
n_bounds 3
bounds -954 -10 9 
property_list 
material 4
region 1366
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1366
end_property_list 
<component> 1376 
n_bounds 7
bounds 553 188 9 955 -191 -570 -10 
property_list 
material 2
region 1367
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1367
end_property_list 
<component> 1377 
n_bounds 4
bounds -955 -10 9 956 
property_list 
material 3
region 1368
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1368
end_property_list 
<component> 1378 
n_bounds 3
bounds -956 -10 9 
property_list 
material 4
region 1369
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1369
end_property_list 
<component> 1379 
n_bounds 6
bounds 553 191 9 -194 -570 -10 
property_list 
material 2
region 1370
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1370
end_property_list 
<component> 1380 
n_bounds 7
bounds 553 194 9 957 -15 -570 -10 
property_list 
material 2
region 1371
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1371
end_property_list 
<component> 1381 
n_bounds 4
bounds -957 -10 9 958 
property_list 
material 3
region 1372
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1372
end_property_list 
<component> 1382 
n_bounds 3
bounds -958 -10 9 
property_list 
material 4
region 1373
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1373
end_property_list 
<component> 1383 
n_bounds 7
bounds 553 15 9 959 -199 -570 -10 
property_list 
material 2
region 1374
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1374
end_property_list 
<component> 1384 
n_bounds 4
bounds -959 -10 9 960 
property_list 
material 3
region 1375
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1375
end_property_list 
<component> 1385 
n_bounds 3
bounds -960 -10 9 
property_list 
material 4
region 1376
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1376
end_property_list 
<component> 1386 
n_bounds 7
bounds 553 199 9 961 -202 -570 -10 
property_list 
material 2
region 1377
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1377
end_property_list 
<component> 1387 
n_bounds 4
bounds -961 -10 9 962 
property_list 
material 3
region 1378
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1378
end_property_list 
<component> 1388 
n_bounds 3
bounds -962 -10 9 
property_list 
material 4
region 1379
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1379
end_property_list 
<component> 1389 
n_bounds 7
bounds 570 48 9 963 -164 -20 -10 
property_list 
material 2
region 1380
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1380
end_property_list 
<component> 1390 
n_bounds 4
bounds -963 -10 9 964 
property_list 
material 3
region 1381
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1381
end_property_list 
<component> 1391 
n_bounds 3
bounds -964 -10 9 
property_list 
material 4
region 1382
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1382
end_property_list 
<component> 1392 
n_bounds 7
bounds 570 164 9 965 -167 -20 -10 
property_list 
material 2
region 1383
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1383
end_property_list 
<component> 1393 
n_bounds 4
bounds -965 -10 9 966 
property_list 
material 3
region 1384
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1384
end_property_list 
<component> 1394 
n_bounds 3
bounds -966 -10 9 
property_list 
material 4
region 1385
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1385
end_property_list 
<component> 1395 
n_bounds 7
bounds 570 167 9 967 -12 -20 -10 
property_list 
material 2
region 1386
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1386
end_property_list 
<component> 1396 
n_bounds 4
bounds -967 -10 9 968 
property_list 
material 3
region 1387
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1387
end_property_list 
<component> 1397 
n_bounds 3
bounds -968 -10 9 
property_list 
material 4
region 1388
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1388
end_property_list 
<component> 1398 
n_bounds 7
bounds 570 12 9 969 -172 -20 -10 
property_list 
material 2
region 1389
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1389
end_property_list 
<component> 1399 
n_bounds 4
bounds -969 -10 9 970 
property_list 
material 3
region 1390
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1390
end_property_list 
<component> 1400 
n_bounds 3
bounds -970 -10 9 
property_list 
material 4
region 1391
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1391
end_property_list 
<component> 1401 
n_bounds 7
bounds 570 172 9 971 -175 -20 -10 
property_list 
material 2
region 1392
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1392
end_property_list 
<component> 1402 
n_bounds 4
bounds -971 -10 9 972 
property_list 
material 3
region 1393
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1393
end_property_list 
<component> 1403 
n_bounds 3
bounds -972 -10 9 
property_list 
material 4
region 1394
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1394
end_property_list 
<component> 1404 
n_bounds 6
bounds 570 175 9 -178 -20 -10 
property_list 
material 2
region 1395
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1395
end_property_list 
<component> 1405 
n_bounds 7
bounds 570 178 9 973 -181 -20 -10 
property_list 
material 2
region 1396
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1396
end_property_list 
<component> 1406 
n_bounds 4
bounds -973 -10 9 974 
property_list 
material 3
region 1397
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1397
end_property_list 
<component> 1407 
n_bounds 3
bounds -974 -10 9 
property_list 
material 4
region 1398
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1398
end_property_list 
<component> 1408 
n_bounds 7
bounds 570 181 9 975 -183 -20 -10 
property_list 
material 2
region 1399
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1399
end_property_list 
<component> 1409 
n_bounds 4
bounds -975 -10 9 976 
property_list 
material 3
region 1400
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1400
end_property_list 
<component> 1410 
n_bounds 3
bounds -976 -10 9 
property_list 
material 4
region 1401
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1401
end_property_list 
<component> 1411 
n_bounds 7
bounds 570 183 9 977 -185 -20 -10 
property_list 
material 2
region 1402
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1402
end_property_list 
<component> 1412 
n_bounds 4
bounds -977 -10 9 978 
property_list 
material 3
region 1403
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1403
end_property_list 
<component> 1413 
n_bounds 3
bounds -978 -10 9 
property_list 
material 4
region 1404
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1404
end_property_list 
<component> 1414 
n_bounds 6
bounds 570 185 9 -188 -20 -10 
property_list 
material 2
region 1405
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1405
end_property_list 
<component> 1415 
n_bounds 7
bounds 570 188 9 979 -191 -20 -10 
property_list 
material 2
region 1406
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1406
end_property_list 
<component> 1416 
n_bounds 4
bounds -979 -10 9 980 
property_list 
material 3
region 1407
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1407
end_property_list 
<component> 1417 
n_bounds 3
bounds -980 -10 9 
property_list 
material 4
region 1408
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1408
end_property_list 
<component> 1418 
n_bounds 7
bounds 570 191 9 981 -194 -20 -10 
property_list 
material 2
region 1409
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1409
end_property_list 
<component> 1419 
n_bounds 4
bounds -981 -10 9 982 
property_list 
material 3
region 1410
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1410
end_property_list 
<component> 1420 
n_bounds 3
bounds -982 -10 9 
property_list 
material 4
region 1411
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1411
end_property_list 
<component> 1421 
n_bounds 7
bounds 570 194 9 983 -15 -20 -10 
property_list 
material 2
region 1412
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1412
end_property_list 
<component> 1422 
n_bounds 4
bounds -983 -10 9 984 
property_list 
material 3
region 1413
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1413
end_property_list 
<component> 1423 
n_bounds 3
bounds -984 -10 9 
property_list 
material 4
region 1414
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1414
end_property_list 
<component> 1424 
n_bounds 7
bounds 570 15 9 985 -199 -20 -10 
property_list 
material 2
region 1415
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1415
end_property_list 
<component> 1425 
n_bounds 4
bounds -985 -10 9 986 
property_list 
material 3
region 1416
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1416
end_property_list 
<component> 1426 
n_bounds 3
bounds -986 -10 9 
property_list 
material 4
region 1417
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1417
end_property_list 
<component> 1427 
n_bounds 7
bounds 570 199 9 987 -202 -20 -10 
property_list 
material 2
region 1418
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1418
end_property_list 
<component> 1428 
n_bounds 4
bounds -987 -10 9 988 
property_list 
material 3
region 1419
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1419
end_property_list 
<component> 1429 
n_bounds 3
bounds -988 -10 9 
property_list 
material 4
region 1420
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1420
end_property_list 
<component> 1430 
n_bounds 7
bounds 20 48 9 989 -164 -599 -10 
property_list 
material 2
region 1421
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1421
end_property_list 
<component> 1431 
n_bounds 4
bounds -989 -10 9 990 
property_list 
material 3
region 1422
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1422
end_property_list 
<component> 1432 
n_bounds 3
bounds -990 -10 9 
property_list 
material 4
region 1423
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1423
end_property_list 
<component> 1433 
n_bounds 7
bounds 20 164 9 991 -167 -599 -10 
property_list 
material 2
region 1424
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1424
end_property_list 
<component> 1434 
n_bounds 4
bounds -991 -10 9 992 
property_list 
material 3
region 1425
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1425
end_property_list 
<component> 1435 
n_bounds 3
bounds -992 -10 9 
property_list 
material 4
region 1426
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1426
end_property_list 
<component> 1436 
n_bounds 7
bounds 20 167 9 993 -12 -599 -10 
property_list 
material 2
region 1427
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1427
end_property_list 
<component> 1437 
n_bounds 4
bounds -993 -10 9 994 
property_list 
material 3
region 1428
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1428
end_property_list 
<component> 1438 
n_bounds 3
bounds -994 -10 9 
property_list 
material 4
region 1429
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1429
end_property_list 
<component> 1439 
n_bounds 7
bounds 20 12 9 995 -172 -599 -10 
property_list 
material 2
region 1430
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1430
end_property_list 
<component> 1440 
n_bounds 4
bounds -995 -10 9 996 
property_list 
material 3
region 1431
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1431
end_property_list 
<component> 1441 
n_bounds 3
bounds -996 -10 9 
property_list 
material 4
region 1432
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1432
end_property_list 
<component> 1442 
n_bounds 7
bounds 20 172 9 997 -175 -599 -10 
property_list 
material 2
region 1433
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1433
end_property_list 
<component> 1443 
n_bounds 4
bounds -997 -10 9 998 
property_list 
material 3
region 1434
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1434
end_property_list 
<component> 1444 
n_bounds 3
bounds -998 -10 9 
property_list 
material 4
region 1435
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1435
end_property_list 
<component> 1445 
n_bounds 7
bounds 20 175 9 999 -178 -599 -10 
property_list 
material 2
region 1436
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1436
end_property_list 
<component> 1446 
n_bounds 4
bounds -999 -10 9 1000 
property_list 
material 3
region 1437
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1437
end_property_list 
<component> 1447 
n_bounds 3
bounds -1000 -10 9 
property_list 
material 4
region 1438
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1438
end_property_list 
<component> 1448 
n_bounds 7
bounds 20 178 9 1001 -181 -599 -10 
property_list 
material 2
region 1439
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1439
end_property_list 
<component> 1449 
n_bounds 4
bounds -1001 -10 9 1002 
property_list 
material 3
region 1440
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1440
end_property_list 
<component> 1450 
n_bounds 3
bounds -1002 -10 9 
property_list 
material 4
region 1441
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1441
end_property_list 
<component> 1451 
n_bounds 7
bounds 20 181 9 1003 -183 -599 -10 
property_list 
material 2
region 1442
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1442
end_property_list 
<component> 1452 
n_bounds 4
bounds -1003 -10 9 1004 
property_list 
material 3
region 1443
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1443
end_property_list 
<component> 1453 
n_bounds 3
bounds -1004 -10 9 
property_list 
material 4
region 1444
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1444
end_property_list 
<component> 1454 
n_bounds 7
bounds 20 183 9 1005 -185 -599 -10 
property_list 
material 2
region 1445
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1445
end_property_list 
<component> 1455 
n_bounds 4
bounds -1005 -10 9 1006 
property_list 
material 3
region 1446
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1446
end_property_list 
<component> 1456 
n_bounds 3
bounds -1006 -10 9 
property_list 
material 4
region 1447
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1447
end_property_list 
<component> 1457 
n_bounds 7
bounds 20 185 9 1007 -188 -599 -10 
property_list 
material 2
region 1448
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1448
end_property_list 
<component> 1458 
n_bounds 4
bounds -1007 -10 9 1008 
property_list 
material 3
region 1449
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1449
end_property_list 
<component> 1459 
n_bounds 3
bounds -1008 -10 9 
property_list 
material 4
region 1450
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1450
end_property_list 
<component> 1460 
n_bounds 7
bounds 20 188 9 1009 -191 -599 -10 
property_list 
material 2
region 1451
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1451
end_property_list 
<component> 1461 
n_bounds 4
bounds -1009 -10 9 1010 
property_list 
material 3
region 1452
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1452
end_property_list 
<component> 1462 
n_bounds 3
bounds -1010 -10 9 
property_list 
material 4
region 1453
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1453
end_property_list 
<component> 1463 
n_bounds 7
bounds 20 191 9 1011 -194 -599 -10 
property_list 
material 2
region 1454
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1454
end_property_list 
<component> 1464 
n_bounds 4
bounds -1011 -10 9 1012 
property_list 
material 3
region 1455
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1455
end_property_list 
<component> 1465 
n_bounds 3
bounds -1012 -10 9 
property_list 
material 4
region 1456
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1456
end_property_list 
<component> 1466 
n_bounds 7
bounds 20 194 9 1013 -15 -599 -10 
property_list 
material 2
region 1457
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1457
end_property_list 
<component> 1467 
n_bounds 4
bounds -1013 -10 9 1014 
property_list 
material 3
region 1458
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1458
end_property_list 
<component> 1468 
n_bounds 3
bounds -1014 -10 9 
property_list 
material 4
region 1459
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1459
end_property_list 
<component> 1469 
n_bounds 7
bounds 20 15 9 1015 -199 -599 -10 
property_list 
material 2
region 1460
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1460
end_property_list 
<component> 1470 
n_bounds 4
bounds -1015 -10 9 1016 
property_list 
material 3
region 1461
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1461
end_property_list 
<component> 1471 
n_bounds 3
bounds -1016 -10 9 
property_list 
material 4
region 1462
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1462
end_property_list 
<component> 1472 
n_bounds 7
bounds 20 199 9 1017 -202 -599 -10 
property_list 
material 2
region 1463
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1463
end_property_list 
<component> 1473 
n_bounds 4
bounds -1017 -10 9 1018 
property_list 
material 3
region 1464
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1464
end_property_list 
<component> 1474 
n_bounds 3
bounds -1018 -10 9 
property_list 
material 4
region 1465
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1465
end_property_list 
<component> 1475 
n_bounds 7
bounds 599 48 9 1019 -164 -616 -10 
property_list 
material 2
region 1466
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1466
end_property_list 
<component> 1476 
n_bounds 4
bounds -1019 -10 9 1020 
property_list 
material 3
region 1467
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1467
end_property_list 
<component> 1477 
n_bounds 3
bounds -1020 -10 9 
property_list 
material 4
region 1468
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1468
end_property_list 
<component> 1478 
n_bounds 7
bounds 599 164 9 1021 -167 -616 -10 
property_list 
material 2
region 1469
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1469
end_property_list 
<component> 1479 
n_bounds 4
bounds -1021 -10 9 1022 
property_list 
material 3
region 1470
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1470
end_property_list 
<component> 1480 
n_bounds 3
bounds -1022 -10 9 
property_list 
material 4
region 1471
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1471
end_property_list 
<component> 1481 
n_bounds 7
bounds 599 167 9 1023 -12 -616 -10 
property_list 
material 2
region 1472
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1472
end_property_list 
<component> 1482 
n_bounds 4
bounds -1023 -10 9 1024 
property_list 
material 3
region 1473
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1473
end_property_list 
<component> 1483 
n_bounds 3
bounds -1024 -10 9 
property_list 
material 4
region 1474
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1474
end_property_list 
<component> 1484 
n_bounds 7
bounds 599 12 9 1025 -172 -616 -10 
property_list 
material 2
region 1475
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1475
end_property_list 
<component> 1485 
n_bounds 4
bounds -1025 -10 9 1026 
property_list 
material 3
region 1476
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1476
end_property_list 
<component> 1486 
n_bounds 3
bounds -1026 -10 9 
property_list 
material 4
region 1477
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1477
end_property_list 
<component> 1487 
n_bounds 7
bounds 599 172 9 1027 -175 -616 -10 
property_list 
material 2
region 1478
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1478
end_property_list 
<component> 1488 
n_bounds 4
bounds -1027 -10 9 1028 
property_list 
material 3
region 1479
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1479
end_property_list 
<component> 1489 
n_bounds 3
bounds -1028 -10 9 
property_list 
material 4
region 1480
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1480
end_property_list 
<component> 1490 
n_bounds 7
bounds 599 175 9 1029 -178 -616 -10 
property_list 
material 2
region 1481
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1481
end_property_list 
<component> 1491 
n_bounds 4
bounds -1029 -10 9 1030 
property_list 
material 3
region 1482
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1482
end_property_list 
<component> 1492 
n_bounds 3
bounds -1030 -10 9 
property_list 
material 4
region 1483
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1483
end_property_list 
<component> 1493 
n_bounds 7
bounds 599 178 9 1031 -181 -616 -10 
property_list 
material 2
region 1484
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1484
end_property_list 
<component> 1494 
n_bounds 4
bounds -1031 -10 9 1032 
property_list 
material 3
region 1485
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1485
end_property_list 
<component> 1495 
n_bounds 3
bounds -1032 -10 9 
property_list 
material 4
region 1486
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1486
end_property_list 
<component> 1496 
n_bounds 7
bounds 599 181 9 1033 -183 -616 -10 
property_list 
material 2
region 1487
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1487
end_property_list 
<component> 1497 
n_bounds 4
bounds -1033 -10 9 1034 
property_list 
material 3
region 1488
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1488
end_property_list 
<component> 1498 
n_bounds 3
bounds -1034 -10 9 
property_list 
material 4
region 1489
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1489
end_property_list 
<component> 1499 
n_bounds 7
bounds 599 183 9 1035 -185 -616 -10 
property_list 
material 2
region 1490
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1490
end_property_list 
<component> 1500 
n_bounds 4
bounds -1035 -10 9 1036 
property_list 
material 3
region 1491
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1491
end_property_list 
<component> 1501 
n_bounds 3
bounds -1036 -10 9 
property_list 
material 4
region 1492
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1492
end_property_list 
<component> 1502 
n_bounds 7
bounds 599 185 9 1037 -188 -616 -10 
property_list 
material 2
region 1493
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1493
end_property_list 
<component> 1503 
n_bounds 4
bounds -1037 -10 9 1038 
property_list 
material 3
region 1494
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1494
end_property_list 
<component> 1504 
n_bounds 3
bounds -1038 -10 9 
property_list 
material 4
region 1495
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1495
end_property_list 
<component> 1505 
n_bounds 7
bounds 599 188 9 1039 -191 -616 -10 
property_list 
material 2
region 1496
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1496
end_property_list 
<component> 1506 
n_bounds 4
bounds -1039 -10 9 1040 
property_list 
material 3
region 1497
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1497
end_property_list 
<component> 1507 
n_bounds 3
bounds -1040 -10 9 
property_list 
material 4
region 1498
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1498
end_property_list 
<component> 1508 
n_bounds 7
bounds 599 191 9 1041 -194 -616 -10 
property_list 
material 2
region 1499
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1499
end_property_list 
<component> 1509 
n_bounds 4
bounds -1041 -10 9 1042 
property_list 
material 3
region 1500
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1500
end_property_list 
<component> 1510 
n_bounds 3
bounds -1042 -10 9 
property_list 
material 4
region 1501
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1501
end_property_list 
<component> 1511 
n_bounds 7
bounds 599 194 9 1043 -15 -616 -10 
property_list 
material 2
region 1502
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1502
end_property_list 
<component> 1512 
n_bounds 4
bounds -1043 -10 9 1044 
property_list 
material 3
region 1503
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1503
end_property_list 
<component> 1513 
n_bounds 3
bounds -1044 -10 9 
property_list 
material 4
region 1504
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1504
end_property_list 
<component> 1514 
n_bounds 7
bounds 599 15 9 1045 -199 -616 -10 
property_list 
material 2
region 1505
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1505
end_property_list 
<component> 1515 
n_bounds 4
bounds -1045 -10 9 1046 
property_list 
material 3
region 1506
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1506
end_property_list 
<component> 1516 
n_bounds 3
bounds -1046 -10 9 
property_list 
material 4
region 1507
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1507
end_property_list 
<component> 1517 
n_bounds 7
bounds 599 199 9 1047 -202 -616 -10 
property_list 
material 2
region 1508
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1508
end_property_list 
<component> 1518 
n_bounds 4
bounds -1047 -10 9 1048 
property_list 
material 3
region 1509
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1509
end_property_list 
<component> 1519 
n_bounds 3
bounds -1048 -10 9 
property_list 
material 4
region 1510
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1510
end_property_list 
<component> 1520 
n_bounds 8
bounds 24 29 1049 202 9 -1050 -26 -10 
property_list 
material 2
region 1511
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1511
end_property_list 
<component> 1521 
n_bounds 6
bounds 24 31 1051 9 -1049 -10 
property_list 
material 3
region 1512
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1512
end_property_list 
<component> 1522 
n_bounds 4
bounds 24 9 -1051 -10 
property_list 
material 4
region 1513
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1513
end_property_list 
<component> 1523 
n_bounds 8
bounds 24 29 1052 1050 9 -1053 -26 -10 
property_list 
material 2
region 1514
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1514
end_property_list 
<component> 1524 
n_bounds 6
bounds 24 31 1054 9 -1052 -10 
property_list 
material 3
region 1515
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1515
end_property_list 
<component> 1525 
n_bounds 4
bounds 24 9 -1054 -10 
property_list 
material 4
region 1516
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1516
end_property_list 
<component> 1526 
n_bounds 8
bounds 24 29 1055 1053 9 -1056 -26 -10 
property_list 
material 2
region 1517
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1517
end_property_list 
<component> 1527 
n_bounds 6
bounds 24 31 1057 9 -1055 -10 
property_list 
material 3
region 1518
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1518
end_property_list 
<component> 1528 
n_bounds 4
bounds 24 9 -1057 -10 
property_list 
material 4
region 1519
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1519
end_property_list 
<component> 1529 
n_bounds 8
bounds 24 29 1058 1056 9 -1059 -26 -10 
property_list 
material 2
region 1520
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1520
end_property_list 
<component> 1530 
n_bounds 6
bounds 24 31 1060 9 -1058 -10 
property_list 
material 3
region 1521
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1521
end_property_list 
<component> 1531 
n_bounds 4
bounds 24 9 -1060 -10 
property_list 
material 4
region 1522
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1522
end_property_list 
<component> 1532 
n_bounds 8
bounds 24 29 1061 1059 9 -1062 -26 -10 
property_list 
material 2
region 1523
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1523
end_property_list 
<component> 1533 
n_bounds 6
bounds 24 31 1063 9 -1061 -10 
property_list 
material 3
region 1524
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1524
end_property_list 
<component> 1534 
n_bounds 4
bounds 24 9 -1063 -10 
property_list 
material 4
region 1525
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1525
end_property_list 
<component> 1535 
n_bounds 8
bounds 24 29 1064 1062 9 -1065 -26 -10 
property_list 
material 2
region 1526
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1526
end_property_list 
<component> 1536 
n_bounds 6
bounds 24 31 1066 9 -1064 -10 
property_list 
material 3
region 1527
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1527
end_property_list 
<component> 1537 
n_bounds 4
bounds 24 9 -1066 -10 
property_list 
material 4
region 1528
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1528
end_property_list 
<component> 1538 
n_bounds 8
bounds 24 29 1067 1065 9 -1068 -26 -10 
property_list 
material 2
region 1529
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1529
end_property_list 
<component> 1539 
n_bounds 6
bounds 24 31 1069 9 -1067 -10 
property_list 
material 3
region 1530
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1530
end_property_list 
<component> 1540 
n_bounds 4
bounds 24 9 -1069 -10 
property_list 
material 4
region 1531
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1531
end_property_list 
<component> 1541 
n_bounds 8
bounds 24 29 1070 1068 9 -17 -26 -10 
property_list 
material 2
region 1532
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1532
end_property_list 
<component> 1542 
n_bounds 6
bounds 24 31 1071 9 -1070 -10 
property_list 
material 3
region 1533
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1533
end_property_list 
<component> 1543 
n_bounds 4
bounds 24 9 -1071 -10 
property_list 
material 4
region 1534
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1534
end_property_list 
<component> 1544 
n_bounds 8
bounds 24 29 1072 17 9 -1073 -26 -10 
property_list 
material 2
region 1535
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1535
end_property_list 
<component> 1545 
n_bounds 6
bounds 24 31 1074 9 -1072 -10 
property_list 
material 3
region 1536
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1536
end_property_list 
<component> 1546 
n_bounds 4
bounds 24 9 -1074 -10 
property_list 
material 4
region 1537
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1537
end_property_list 
<component> 1547 
n_bounds 8
bounds 24 29 1075 1073 9 -1076 -26 -10 
property_list 
material 2
region 1538
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1538
end_property_list 
<component> 1548 
n_bounds 6
bounds 24 31 1077 9 -1075 -10 
property_list 
material 3
region 1539
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1539
end_property_list 
<component> 1549 
n_bounds 4
bounds 24 9 -1077 -10 
property_list 
material 4
region 1540
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1540
end_property_list 
<component> 1550 
n_bounds 8
bounds 24 29 1078 1076 9 -1079 -26 -10 
property_list 
material 2
region 1541
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1541
end_property_list 
<component> 1551 
n_bounds 6
bounds 24 31 1080 9 -1078 -10 
property_list 
material 3
region 1542
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1542
end_property_list 
<component> 1552 
n_bounds 4
bounds 24 9 -1080 -10 
property_list 
material 4
region 1543
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1543
end_property_list 
<component> 1553 
n_bounds 8
bounds 24 29 1081 1079 9 -1082 -26 -10 
property_list 
material 2
region 1544
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1544
end_property_list 
<component> 1554 
n_bounds 6
bounds 24 31 1083 9 -1081 -10 
property_list 
material 3
region 1545
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1545
end_property_list 
<component> 1555 
n_bounds 4
bounds 24 9 -1083 -10 
property_list 
material 4
region 1546
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1546
end_property_list 
<component> 1556 
n_bounds 8
bounds 24 29 1084 1082 9 -19 -26 -10 
property_list 
material 2
region 1547
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1547
end_property_list 
<component> 1557 
n_bounds 6
bounds 24 31 1085 9 -1084 -10 
property_list 
material 3
region 1548
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1548
end_property_list 
<component> 1558 
n_bounds 4
bounds 24 9 -1085 -10 
property_list 
material 4
region 1549
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1549
end_property_list 
<component> 1559 
n_bounds 8
bounds 24 29 1086 19 9 -1087 -26 -10 
property_list 
material 2
region 1550
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1550
end_property_list 
<component> 1560 
n_bounds 6
bounds 24 31 1088 9 -1086 -10 
property_list 
material 3
region 1551
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1551
end_property_list 
<component> 1561 
n_bounds 4
bounds 24 9 -1088 -10 
property_list 
material 4
region 1552
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1552
end_property_list 
<component> 1562 
n_bounds 8
bounds 24 29 1089 1087 9 -1090 -26 -10 
property_list 
material 2
region 1553
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1553
end_property_list 
<component> 1563 
n_bounds 6
bounds 24 31 1091 9 -1089 -10 
property_list 
material 3
region 1554
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1554
end_property_list 
<component> 1564 
n_bounds 4
bounds 24 9 -1091 -10 
property_list 
material 4
region 1555
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1555
end_property_list 
<component> 1565 
n_bounds 8
bounds 24 29 1092 1090 9 -1093 -26 -10 
property_list 
material 2
region 1556
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1556
end_property_list 
<component> 1566 
n_bounds 6
bounds 24 31 1094 9 -1092 -10 
property_list 
material 3
region 1557
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1557
end_property_list 
<component> 1567 
n_bounds 4
bounds 24 9 -1094 -10 
property_list 
material 4
region 1558
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1558
end_property_list 
<component> 1568 
n_bounds 8
bounds 24 29 1095 1093 9 -1096 -26 -10 
property_list 
material 2
region 1559
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1559
end_property_list 
<component> 1569 
n_bounds 6
bounds 24 31 1097 9 -1095 -10 
property_list 
material 3
region 1560
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1560
end_property_list 
<component> 1570 
n_bounds 4
bounds 24 9 -1097 -10 
property_list 
material 4
region 1561
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1561
end_property_list 
<component> 1571 
n_bounds 8
bounds 24 29 1098 1096 9 -22 -26 -10 
property_list 
material 2
region 1562
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1562
end_property_list 
<component> 1572 
n_bounds 6
bounds 24 31 1099 9 -1098 -10 
property_list 
material 3
region 1563
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1563
end_property_list 
<component> 1573 
n_bounds 4
bounds 24 9 -1099 -10 
property_list 
material 4
region 1564
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1564
end_property_list 
<component> 1574 
n_bounds 7
bounds 26 202 9 1100 -1050 -50 -10 
property_list 
material 2
region 1565
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1565
end_property_list 
<component> 1575 
n_bounds 4
bounds -1100 -10 9 1101 
property_list 
material 3
region 1566
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1566
end_property_list 
<component> 1576 
n_bounds 3
bounds -1101 -10 9 
property_list 
material 4
region 1567
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1567
end_property_list 
<component> 1577 
n_bounds 7
bounds 26 1050 9 1102 -1053 -50 -10 
property_list 
material 2
region 1568
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1568
end_property_list 
<component> 1578 
n_bounds 4
bounds -1102 -10 9 1103 
property_list 
material 3
region 1569
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1569
end_property_list 
<component> 1579 
n_bounds 3
bounds -1103 -10 9 
property_list 
material 4
region 1570
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1570
end_property_list 
<component> 1580 
n_bounds 7
bounds 26 1053 9 1104 -1056 -50 -10 
property_list 
material 2
region 1571
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1571
end_property_list 
<component> 1581 
n_bounds 4
bounds -1104 -10 9 1105 
property_list 
material 3
region 1572
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1572
end_property_list 
<component> 1582 
n_bounds 3
bounds -1105 -10 9 
property_list 
material 4
region 1573
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1573
end_property_list 
<component> 1583 
n_bounds 7
bounds 26 1056 9 1106 -1059 -50 -10 
property_list 
material 2
region 1574
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1574
end_property_list 
<component> 1584 
n_bounds 4
bounds -1106 -10 9 1107 
property_list 
material 3
region 1575
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1575
end_property_list 
<component> 1585 
n_bounds 3
bounds -1107 -10 9 
property_list 
material 4
region 1576
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1576
end_property_list 
<component> 1586 
n_bounds 7
bounds 26 1059 9 1108 -1062 -50 -10 
property_list 
material 2
region 1577
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1577
end_property_list 
<component> 1587 
n_bounds 4
bounds -1108 -10 9 1109 
property_list 
material 3
region 1578
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1578
end_property_list 
<component> 1588 
n_bounds 3
bounds -1109 -10 9 
property_list 
material 4
region 1579
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1579
end_property_list 
<component> 1589 
n_bounds 7
bounds 26 1062 9 1110 -1065 -50 -10 
property_list 
material 2
region 1580
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1580
end_property_list 
<component> 1590 
n_bounds 4
bounds -1110 -10 9 1111 
property_list 
material 3
region 1581
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1581
end_property_list 
<component> 1591 
n_bounds 3
bounds -1111 -10 9 
property_list 
material 4
region 1582
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1582
end_property_list 
<component> 1592 
n_bounds 7
bounds 26 1065 9 1112 -1068 -50 -10 
property_list 
material 2
region 1583
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1583
end_property_list 
<component> 1593 
n_bounds 4
bounds -1112 -10 9 1113 
property_list 
material 3
region 1584
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1584
end_property_list 
<component> 1594 
n_bounds 3
bounds -1113 -10 9 
property_list 
material 4
region 1585
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1585
end_property_list 
<component> 1595 
n_bounds 7
bounds 26 1068 9 1114 -17 -50 -10 
property_list 
material 2
region 1586
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1586
end_property_list 
<component> 1596 
n_bounds 4
bounds -1114 -10 9 1115 
property_list 
material 3
region 1587
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1587
end_property_list 
<component> 1597 
n_bounds 3
bounds -1115 -10 9 
property_list 
material 4
region 1588
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1588
end_property_list 
<component> 1598 
n_bounds 7
bounds 26 17 9 1116 -1073 -50 -10 
property_list 
material 2
region 1589
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1589
end_property_list 
<component> 1599 
n_bounds 4
bounds -1116 -10 9 1117 
property_list 
material 3
region 1590
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1590
end_property_list 
<component> 1600 
n_bounds 3
bounds -1117 -10 9 
property_list 
material 4
region 1591
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1591
end_property_list 
<component> 1601 
n_bounds 7
bounds 26 1073 9 1118 -1076 -50 -10 
property_list 
material 2
region 1592
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1592
end_property_list 
<component> 1602 
n_bounds 4
bounds -1118 -10 9 1119 
property_list 
material 3
region 1593
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1593
end_property_list 
<component> 1603 
n_bounds 3
bounds -1119 -10 9 
property_list 
material 4
region 1594
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1594
end_property_list 
<component> 1604 
n_bounds 7
bounds 26 1076 9 1120 -1079 -50 -10 
property_list 
material 2
region 1595
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1595
end_property_list 
<component> 1605 
n_bounds 4
bounds -1120 -10 9 1121 
property_list 
material 3
region 1596
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1596
end_property_list 
<component> 1606 
n_bounds 3
bounds -1121 -10 9 
property_list 
material 4
region 1597
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1597
end_property_list 
<component> 1607 
n_bounds 7
bounds 26 1079 9 1122 -1082 -50 -10 
property_list 
material 2
region 1598
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1598
end_property_list 
<component> 1608 
n_bounds 4
bounds -1122 -10 9 1123 
property_list 
material 3
region 1599
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1599
end_property_list 
<component> 1609 
n_bounds 3
bounds -1123 -10 9 
property_list 
material 4
region 1600
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1600
end_property_list 
<component> 1610 
n_bounds 7
bounds 26 1082 9 1124 -19 -50 -10 
property_list 
material 2
region 1601
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1601
end_property_list 
<component> 1611 
n_bounds 4
bounds -1124 -10 9 1125 
property_list 
material 3
region 1602
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1602
end_property_list 
<component> 1612 
n_bounds 3
bounds -1125 -10 9 
property_list 
material 4
region 1603
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1603
end_property_list 
<component> 1613 
n_bounds 7
bounds 26 19 9 1126 -1087 -50 -10 
property_list 
material 2
region 1604
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1604
end_property_list 
<component> 1614 
n_bounds 4
bounds -1126 -10 9 1127 
property_list 
material 3
region 1605
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1605
end_property_list 
<component> 1615 
n_bounds 3
bounds -1127 -10 9 
property_list 
material 4
region 1606
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1606
end_property_list 
<component> 1616 
n_bounds 7
bounds 26 1087 9 1128 -1090 -50 -10 
property_list 
material 2
region 1607
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1607
end_property_list 
<component> 1617 
n_bounds 4
bounds -1128 -10 9 1129 
property_list 
material 3
region 1608
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1608
end_property_list 
<component> 1618 
n_bounds 3
bounds -1129 -10 9 
property_list 
material 4
region 1609
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1609
end_property_list 
<component> 1619 
n_bounds 7
bounds 26 1090 9 1130 -1093 -50 -10 
property_list 
material 2
region 1610
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1610
end_property_list 
<component> 1620 
n_bounds 4
bounds -1130 -10 9 1131 
property_list 
material 3
region 1611
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1611
end_property_list 
<component> 1621 
n_bounds 3
bounds -1131 -10 9 
property_list 
material 4
region 1612
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1612
end_property_list 
<component> 1622 
n_bounds 7
bounds 26 1093 9 1132 -1096 -50 -10 
property_list 
material 2
region 1613
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1613
end_property_list 
<component> 1623 
n_bounds 4
bounds -1132 -10 9 1133 
property_list 
material 3
region 1614
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1614
end_property_list 
<component> 1624 
n_bounds 3
bounds -1133 -10 9 
property_list 
material 4
region 1615
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1615
end_property_list 
<component> 1625 
n_bounds 7
bounds 26 1096 9 1134 -22 -50 -10 
property_list 
material 2
region 1616
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1616
end_property_list 
<component> 1626 
n_bounds 4
bounds -1134 -10 9 1135 
property_list 
material 3
region 1617
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1617
end_property_list 
<component> 1627 
n_bounds 3
bounds -1135 -10 9 
property_list 
material 4
region 1618
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1618
end_property_list 
<component> 1628 
n_bounds 7
bounds 50 202 9 1136 -1050 -69 -10 
property_list 
material 2
region 1619
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1619
end_property_list 
<component> 1629 
n_bounds 4
bounds -1136 -10 9 1137 
property_list 
material 3
region 1620
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1620
end_property_list 
<component> 1630 
n_bounds 3
bounds -1137 -10 9 
property_list 
material 4
region 1621
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1621
end_property_list 
<component> 1631 
n_bounds 7
bounds 50 1050 9 1138 -1053 -69 -10 
property_list 
material 2
region 1622
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1622
end_property_list 
<component> 1632 
n_bounds 4
bounds -1138 -10 9 1139 
property_list 
material 3
region 1623
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1623
end_property_list 
<component> 1633 
n_bounds 3
bounds -1139 -10 9 
property_list 
material 4
region 1624
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1624
end_property_list 
<component> 1634 
n_bounds 7
bounds 50 1053 9 1140 -1056 -69 -10 
property_list 
material 2
region 1625
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1625
end_property_list 
<component> 1635 
n_bounds 4
bounds -1140 -10 9 1141 
property_list 
material 3
region 1626
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1626
end_property_list 
<component> 1636 
n_bounds 3
bounds -1141 -10 9 
property_list 
material 4
region 1627
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1627
end_property_list 
<component> 1637 
n_bounds 7
bounds 50 1056 9 1142 -1059 -69 -10 
property_list 
material 2
region 1628
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1628
end_property_list 
<component> 1638 
n_bounds 4
bounds -1142 -10 9 1143 
property_list 
material 3
region 1629
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1629
end_property_list 
<component> 1639 
n_bounds 3
bounds -1143 -10 9 
property_list 
material 4
region 1630
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1630
end_property_list 
<component> 1640 
n_bounds 7
bounds 50 1059 9 1144 -1062 -69 -10 
property_list 
material 2
region 1631
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1631
end_property_list 
<component> 1641 
n_bounds 4
bounds -1144 -10 9 1145 
property_list 
material 3
region 1632
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1632
end_property_list 
<component> 1642 
n_bounds 3
bounds -1145 -10 9 
property_list 
material 4
region 1633
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1633
end_property_list 
<component> 1643 
n_bounds 7
bounds 50 1062 9 1146 -1065 -69 -10 
property_list 
material 2
region 1634
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1634
end_property_list 
<component> 1644 
n_bounds 4
bounds -1146 -10 9 1147 
property_list 
material 3
region 1635
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1635
end_property_list 
<component> 1645 
n_bounds 3
bounds -1147 -10 9 
property_list 
material 4
region 1636
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1636
end_property_list 
<component> 1646 
n_bounds 7
bounds 50 1065 9 1148 -1068 -69 -10 
property_list 
material 2
region 1637
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1637
end_property_list 
<component> 1647 
n_bounds 4
bounds -1148 -10 9 1149 
property_list 
material 3
region 1638
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1638
end_property_list 
<component> 1648 
n_bounds 3
bounds -1149 -10 9 
property_list 
material 4
region 1639
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1639
end_property_list 
<component> 1649 
n_bounds 7
bounds 50 1068 9 1150 -17 -69 -10 
property_list 
material 2
region 1640
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1640
end_property_list 
<component> 1650 
n_bounds 4
bounds -1150 -10 9 1151 
property_list 
material 3
region 1641
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1641
end_property_list 
<component> 1651 
n_bounds 3
bounds -1151 -10 9 
property_list 
material 4
region 1642
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1642
end_property_list 
<component> 1652 
n_bounds 7
bounds 50 17 9 1152 -1073 -69 -10 
property_list 
material 2
region 1643
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1643
end_property_list 
<component> 1653 
n_bounds 4
bounds -1152 -10 9 1153 
property_list 
material 3
region 1644
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1644
end_property_list 
<component> 1654 
n_bounds 3
bounds -1153 -10 9 
property_list 
material 4
region 1645
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1645
end_property_list 
<component> 1655 
n_bounds 7
bounds 50 1073 9 1154 -1076 -69 -10 
property_list 
material 2
region 1646
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1646
end_property_list 
<component> 1656 
n_bounds 4
bounds -1154 -10 9 1155 
property_list 
material 3
region 1647
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1647
end_property_list 
<component> 1657 
n_bounds 3
bounds -1155 -10 9 
property_list 
material 4
region 1648
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1648
end_property_list 
<component> 1658 
n_bounds 7
bounds 50 1076 9 1156 -1079 -69 -10 
property_list 
material 2
region 1649
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1649
end_property_list 
<component> 1659 
n_bounds 4
bounds -1156 -10 9 1157 
property_list 
material 3
region 1650
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1650
end_property_list 
<component> 1660 
n_bounds 3
bounds -1157 -10 9 
property_list 
material 4
region 1651
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1651
end_property_list 
<component> 1661 
n_bounds 7
bounds 50 1079 9 1158 -1082 -69 -10 
property_list 
material 2
region 1652
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1652
end_property_list 
<component> 1662 
n_bounds 4
bounds -1158 -10 9 1159 
property_list 
material 3
region 1653
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1653
end_property_list 
<component> 1663 
n_bounds 3
bounds -1159 -10 9 
property_list 
material 4
region 1654
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1654
end_property_list 
<component> 1664 
n_bounds 7
bounds 50 1082 9 1160 -19 -69 -10 
property_list 
material 2
region 1655
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1655
end_property_list 
<component> 1665 
n_bounds 4
bounds -1160 -10 9 1161 
property_list 
material 3
region 1656
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1656
end_property_list 
<component> 1666 
n_bounds 3
bounds -1161 -10 9 
property_list 
material 4
region 1657
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1657
end_property_list 
<component> 1667 
n_bounds 7
bounds 50 19 9 1162 -1087 -69 -10 
property_list 
material 2
region 1658
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1658
end_property_list 
<component> 1668 
n_bounds 4
bounds -1162 -10 9 1163 
property_list 
material 3
region 1659
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1659
end_property_list 
<component> 1669 
n_bounds 3
bounds -1163 -10 9 
property_list 
material 4
region 1660
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1660
end_property_list 
<component> 1670 
n_bounds 7
bounds 50 1087 9 1164 -1090 -69 -10 
property_list 
material 2
region 1661
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1661
end_property_list 
<component> 1671 
n_bounds 4
bounds -1164 -10 9 1165 
property_list 
material 3
region 1662
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1662
end_property_list 
<component> 1672 
n_bounds 3
bounds -1165 -10 9 
property_list 
material 4
region 1663
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1663
end_property_list 
<component> 1673 
n_bounds 7
bounds 50 1090 9 1166 -1093 -69 -10 
property_list 
material 2
region 1664
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1664
end_property_list 
<component> 1674 
n_bounds 4
bounds -1166 -10 9 1167 
property_list 
material 3
region 1665
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1665
end_property_list 
<component> 1675 
n_bounds 3
bounds -1167 -10 9 
property_list 
material 4
region 1666
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1666
end_property_list 
<component> 1676 
n_bounds 7
bounds 50 1093 9 1168 -1096 -69 -10 
property_list 
material 2
region 1667
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1667
end_property_list 
<component> 1677 
n_bounds 4
bounds -1168 -10 9 1169 
property_list 
material 3
region 1668
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1668
end_property_list 
<component> 1678 
n_bounds 3
bounds -1169 -10 9 
property_list 
material 4
region 1669
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1669
end_property_list 
<component> 1679 
n_bounds 7
bounds 50 1096 9 1170 -22 -69 -10 
property_list 
material 2
region 1670
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1670
end_property_list 
<component> 1680 
n_bounds 4
bounds -1170 -10 9 1171 
property_list 
material 3
region 1671
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1671
end_property_list 
<component> 1681 
n_bounds 3
bounds -1171 -10 9 
property_list 
material 4
region 1672
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1672
end_property_list 
<component> 1682 
n_bounds 7
bounds 69 202 9 1172 -1050 -82 -10 
property_list 
material 2
region 1673
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1673
end_property_list 
<component> 1683 
n_bounds 4
bounds -1172 -10 9 1173 
property_list 
material 3
region 1674
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1674
end_property_list 
<component> 1684 
n_bounds 3
bounds -1173 -10 9 
property_list 
material 4
region 1675
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1675
end_property_list 
<component> 1685 
n_bounds 7
bounds 69 1050 9 1174 -1053 -82 -10 
property_list 
material 2
region 1676
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1676
end_property_list 
<component> 1686 
n_bounds 4
bounds -1174 -10 9 1175 
property_list 
material 3
region 1677
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1677
end_property_list 
<component> 1687 
n_bounds 3
bounds -1175 -10 9 
property_list 
material 4
region 1678
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1678
end_property_list 
<component> 1688 
n_bounds 7
bounds 69 1053 9 1176 -1056 -82 -10 
property_list 
material 2
region 1679
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1679
end_property_list 
<component> 1689 
n_bounds 4
bounds -1176 -10 9 1177 
property_list 
material 3
region 1680
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1680
end_property_list 
<component> 1690 
n_bounds 3
bounds -1177 -10 9 
property_list 
material 4
region 1681
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1681
end_property_list 
<component> 1691 
n_bounds 7
bounds 69 1056 9 1178 -1059 -82 -10 
property_list 
material 2
region 1682
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1682
end_property_list 
<component> 1692 
n_bounds 4
bounds -1178 -10 9 1179 
property_list 
material 3
region 1683
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1683
end_property_list 
<component> 1693 
n_bounds 3
bounds -1179 -10 9 
property_list 
material 4
region 1684
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1684
end_property_list 
<component> 1694 
n_bounds 7
bounds 69 1059 9 1180 -1062 -82 -10 
property_list 
material 2
region 1685
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1685
end_property_list 
<component> 1695 
n_bounds 4
bounds -1180 -10 9 1181 
property_list 
material 3
region 1686
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1686
end_property_list 
<component> 1696 
n_bounds 3
bounds -1181 -10 9 
property_list 
material 4
region 1687
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1687
end_property_list 
<component> 1697 
n_bounds 7
bounds 69 1062 9 1182 -1065 -82 -10 
property_list 
material 2
region 1688
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1688
end_property_list 
<component> 1698 
n_bounds 4
bounds -1182 -10 9 1183 
property_list 
material 3
region 1689
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1689
end_property_list 
<component> 1699 
n_bounds 3
bounds -1183 -10 9 
property_list 
material 4
region 1690
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1690
end_property_list 
<component> 1700 
n_bounds 7
bounds 69 1065 9 1184 -1068 -82 -10 
property_list 
material 2
region 1691
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1691
end_property_list 
<component> 1701 
n_bounds 4
bounds -1184 -10 9 1185 
property_list 
material 3
region 1692
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1692
end_property_list 
<component> 1702 
n_bounds 3
bounds -1185 -10 9 
property_list 
material 4
region 1693
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1693
end_property_list 
<component> 1703 
n_bounds 7
bounds 69 1068 9 1186 -17 -82 -10 
property_list 
material 2
region 1694
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1694
end_property_list 
<component> 1704 
n_bounds 4
bounds -1186 -10 9 1187 
property_list 
material 3
region 1695
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1695
end_property_list 
<component> 1705 
n_bounds 3
bounds -1187 -10 9 
property_list 
material 4
region 1696
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1696
end_property_list 
<component> 1706 
n_bounds 7
bounds 69 17 9 1188 -1073 -82 -10 
property_list 
material 2
region 1697
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1697
end_property_list 
<component> 1707 
n_bounds 4
bounds -1188 -10 9 1189 
property_list 
material 3
region 1698
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1698
end_property_list 
<component> 1708 
n_bounds 3
bounds -1189 -10 9 
property_list 
material 4
region 1699
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1699
end_property_list 
<component> 1709 
n_bounds 7
bounds 69 1073 9 1190 -1076 -82 -10 
property_list 
material 2
region 1700
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1700
end_property_list 
<component> 1710 
n_bounds 4
bounds -1190 -10 9 1191 
property_list 
material 3
region 1701
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1701
end_property_list 
<component> 1711 
n_bounds 3
bounds -1191 -10 9 
property_list 
material 4
region 1702
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1702
end_property_list 
<component> 1712 
n_bounds 7
bounds 69 1076 9 1192 -1079 -82 -10 
property_list 
material 2
region 1703
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1703
end_property_list 
<component> 1713 
n_bounds 4
bounds -1192 -10 9 1193 
property_list 
material 3
region 1704
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1704
end_property_list 
<component> 1714 
n_bounds 3
bounds -1193 -10 9 
property_list 
material 4
region 1705
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1705
end_property_list 
<component> 1715 
n_bounds 7
bounds 69 1079 9 1194 -1082 -82 -10 
property_list 
material 2
region 1706
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1706
end_property_list 
<component> 1716 
n_bounds 4
bounds -1194 -10 9 1195 
property_list 
material 3
region 1707
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1707
end_property_list 
<component> 1717 
n_bounds 3
bounds -1195 -10 9 
property_list 
material 4
region 1708
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1708
end_property_list 
<component> 1718 
n_bounds 7
bounds 69 1082 9 1196 -19 -82 -10 
property_list 
material 2
region 1709
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1709
end_property_list 
<component> 1719 
n_bounds 4
bounds -1196 -10 9 1197 
property_list 
material 3
region 1710
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1710
end_property_list 
<component> 1720 
n_bounds 3
bounds -1197 -10 9 
property_list 
material 4
region 1711
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1711
end_property_list 
<component> 1721 
n_bounds 7
bounds 69 19 9 1198 -1087 -82 -10 
property_list 
material 2
region 1712
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1712
end_property_list 
<component> 1722 
n_bounds 4
bounds -1198 -10 9 1199 
property_list 
material 3
region 1713
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1713
end_property_list 
<component> 1723 
n_bounds 3
bounds -1199 -10 9 
property_list 
material 4
region 1714
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1714
end_property_list 
<component> 1724 
n_bounds 7
bounds 69 1087 9 1200 -1090 -82 -10 
property_list 
material 2
region 1715
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1715
end_property_list 
<component> 1725 
n_bounds 4
bounds -1200 -10 9 1201 
property_list 
material 3
region 1716
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1716
end_property_list 
<component> 1726 
n_bounds 3
bounds -1201 -10 9 
property_list 
material 4
region 1717
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1717
end_property_list 
<component> 1727 
n_bounds 7
bounds 69 1090 9 1202 -1093 -82 -10 
property_list 
material 2
region 1718
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1718
end_property_list 
<component> 1728 
n_bounds 4
bounds -1202 -10 9 1203 
property_list 
material 3
region 1719
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1719
end_property_list 
<component> 1729 
n_bounds 3
bounds -1203 -10 9 
property_list 
material 4
region 1720
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1720
end_property_list 
<component> 1730 
n_bounds 7
bounds 69 1093 9 1204 -1096 -82 -10 
property_list 
material 2
region 1721
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1721
end_property_list 
<component> 1731 
n_bounds 4
bounds -1204 -10 9 1205 
property_list 
material 3
region 1722
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1722
end_property_list 
<component> 1732 
n_bounds 3
bounds -1205 -10 9 
property_list 
material 4
region 1723
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1723
end_property_list 
<component> 1733 
n_bounds 7
bounds 69 1096 9 1206 -22 -82 -10 
property_list 
material 2
region 1724
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1724
end_property_list 
<component> 1734 
n_bounds 4
bounds -1206 -10 9 1207 
property_list 
material 3
region 1725
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1725
end_property_list 
<component> 1735 
n_bounds 3
bounds -1207 -10 9 
property_list 
material 4
region 1726
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1726
end_property_list 
<component> 1736 
n_bounds 7
bounds 82 202 9 1208 -1050 -99 -10 
property_list 
material 2
region 1727
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1727
end_property_list 
<component> 1737 
n_bounds 4
bounds -1208 -10 9 1209 
property_list 
material 3
region 1728
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1728
end_property_list 
<component> 1738 
n_bounds 3
bounds -1209 -10 9 
property_list 
material 4
region 1729
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1729
end_property_list 
<component> 1739 
n_bounds 7
bounds 82 1050 9 1210 -1053 -99 -10 
property_list 
material 2
region 1730
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1730
end_property_list 
<component> 1740 
n_bounds 4
bounds -1210 -10 9 1211 
property_list 
material 3
region 1731
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1731
end_property_list 
<component> 1741 
n_bounds 3
bounds -1211 -10 9 
property_list 
material 4
region 1732
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1732
end_property_list 
<component> 1742 
n_bounds 7
bounds 82 1053 9 1212 -1056 -99 -10 
property_list 
material 2
region 1733
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1733
end_property_list 
<component> 1743 
n_bounds 4
bounds -1212 -10 9 1213 
property_list 
material 3
region 1734
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1734
end_property_list 
<component> 1744 
n_bounds 3
bounds -1213 -10 9 
property_list 
material 4
region 1735
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1735
end_property_list 
<component> 1745 
n_bounds 7
bounds 82 1056 9 1214 -1059 -99 -10 
property_list 
material 2
region 1736
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1736
end_property_list 
<component> 1746 
n_bounds 4
bounds -1214 -10 9 1215 
property_list 
material 3
region 1737
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1737
end_property_list 
<component> 1747 
n_bounds 3
bounds -1215 -10 9 
property_list 
material 4
region 1738
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1738
end_property_list 
<component> 1748 
n_bounds 7
bounds 82 1059 9 1216 -1062 -99 -10 
property_list 
material 2
region 1739
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1739
end_property_list 
<component> 1749 
n_bounds 4
bounds -1216 -10 9 1217 
property_list 
material 3
region 1740
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1740
end_property_list 
<component> 1750 
n_bounds 3
bounds -1217 -10 9 
property_list 
material 4
region 1741
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1741
end_property_list 
<component> 1751 
n_bounds 7
bounds 82 1062 9 1218 -1065 -99 -10 
property_list 
material 2
region 1742
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1742
end_property_list 
<component> 1752 
n_bounds 4
bounds -1218 -10 9 1219 
property_list 
material 3
region 1743
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1743
end_property_list 
<component> 1753 
n_bounds 3
bounds -1219 -10 9 
property_list 
material 4
region 1744
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1744
end_property_list 
<component> 1754 
n_bounds 7
bounds 82 1065 9 1220 -1068 -99 -10 
property_list 
material 2
region 1745
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1745
end_property_list 
<component> 1755 
n_bounds 4
bounds -1220 -10 9 1221 
property_list 
material 3
region 1746
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1746
end_property_list 
<component> 1756 
n_bounds 3
bounds -1221 -10 9 
property_list 
material 4
region 1747
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1747
end_property_list 
<component> 1757 
n_bounds 7
bounds 82 1068 9 1222 -17 -99 -10 
property_list 
material 2
region 1748
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1748
end_property_list 
<component> 1758 
n_bounds 4
bounds -1222 -10 9 1223 
property_list 
material 3
region 1749
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1749
end_property_list 
<component> 1759 
n_bounds 3
bounds -1223 -10 9 
property_list 
material 4
region 1750
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1750
end_property_list 
<component> 1760 
n_bounds 7
bounds 82 17 9 1224 -1073 -99 -10 
property_list 
material 2
region 1751
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1751
end_property_list 
<component> 1761 
n_bounds 4
bounds -1224 -10 9 1225 
property_list 
material 3
region 1752
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1752
end_property_list 
<component> 1762 
n_bounds 3
bounds -1225 -10 9 
property_list 
material 4
region 1753
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1753
end_property_list 
<component> 1763 
n_bounds 7
bounds 82 1073 9 1226 -1076 -99 -10 
property_list 
material 2
region 1754
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1754
end_property_list 
<component> 1764 
n_bounds 4
bounds -1226 -10 9 1227 
property_list 
material 3
region 1755
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1755
end_property_list 
<component> 1765 
n_bounds 3
bounds -1227 -10 9 
property_list 
material 4
region 1756
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1756
end_property_list 
<component> 1766 
n_bounds 7
bounds 82 1076 9 1228 -1079 -99 -10 
property_list 
material 2
region 1757
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1757
end_property_list 
<component> 1767 
n_bounds 4
bounds -1228 -10 9 1229 
property_list 
material 3
region 1758
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1758
end_property_list 
<component> 1768 
n_bounds 3
bounds -1229 -10 9 
property_list 
material 4
region 1759
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1759
end_property_list 
<component> 1769 
n_bounds 7
bounds 82 1079 9 1230 -1082 -99 -10 
property_list 
material 2
region 1760
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1760
end_property_list 
<component> 1770 
n_bounds 4
bounds -1230 -10 9 1231 
property_list 
material 3
region 1761
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1761
end_property_list 
<component> 1771 
n_bounds 3
bounds -1231 -10 9 
property_list 
material 4
region 1762
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1762
end_property_list 
<component> 1772 
n_bounds 7
bounds 82 1082 9 1232 -19 -99 -10 
property_list 
material 2
region 1763
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1763
end_property_list 
<component> 1773 
n_bounds 4
bounds -1232 -10 9 1233 
property_list 
material 3
region 1764
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1764
end_property_list 
<component> 1774 
n_bounds 3
bounds -1233 -10 9 
property_list 
material 4
region 1765
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1765
end_property_list 
<component> 1775 
n_bounds 7
bounds 82 19 9 1234 -1087 -99 -10 
property_list 
material 2
region 1766
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1766
end_property_list 
<component> 1776 
n_bounds 4
bounds -1234 -10 9 1235 
property_list 
material 3
region 1767
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1767
end_property_list 
<component> 1777 
n_bounds 3
bounds -1235 -10 9 
property_list 
material 4
region 1768
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1768
end_property_list 
<component> 1778 
n_bounds 7
bounds 82 1087 9 1236 -1090 -99 -10 
property_list 
material 2
region 1769
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1769
end_property_list 
<component> 1779 
n_bounds 4
bounds -1236 -10 9 1237 
property_list 
material 3
region 1770
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1770
end_property_list 
<component> 1780 
n_bounds 3
bounds -1237 -10 9 
property_list 
material 4
region 1771
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1771
end_property_list 
<component> 1781 
n_bounds 7
bounds 82 1090 9 1238 -1093 -99 -10 
property_list 
material 2
region 1772
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1772
end_property_list 
<component> 1782 
n_bounds 4
bounds -1238 -10 9 1239 
property_list 
material 3
region 1773
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1773
end_property_list 
<component> 1783 
n_bounds 3
bounds -1239 -10 9 
property_list 
material 4
region 1774
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1774
end_property_list 
<component> 1784 
n_bounds 7
bounds 82 1093 9 1240 -1096 -99 -10 
property_list 
material 2
region 1775
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1775
end_property_list 
<component> 1785 
n_bounds 4
bounds -1240 -10 9 1241 
property_list 
material 3
region 1776
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1776
end_property_list 
<component> 1786 
n_bounds 3
bounds -1241 -10 9 
property_list 
material 4
region 1777
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1777
end_property_list 
<component> 1787 
n_bounds 7
bounds 82 1096 9 1242 -22 -99 -10 
property_list 
material 2
region 1778
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1778
end_property_list 
<component> 1788 
n_bounds 4
bounds -1242 -10 9 1243 
property_list 
material 3
region 1779
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1779
end_property_list 
<component> 1789 
n_bounds 3
bounds -1243 -10 9 
property_list 
material 4
region 1780
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1780
end_property_list 
<component> 1790 
n_bounds 7
bounds 99 202 9 1244 -1050 -114 -10 
property_list 
material 2
region 1781
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1781
end_property_list 
<component> 1791 
n_bounds 4
bounds -1244 -10 9 1245 
property_list 
material 3
region 1782
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1782
end_property_list 
<component> 1792 
n_bounds 3
bounds -1245 -10 9 
property_list 
material 4
region 1783
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1783
end_property_list 
<component> 1793 
n_bounds 7
bounds 99 1050 9 1246 -1053 -114 -10 
property_list 
material 2
region 1784
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1784
end_property_list 
<component> 1794 
n_bounds 4
bounds -1246 -10 9 1247 
property_list 
material 3
region 1785
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1785
end_property_list 
<component> 1795 
n_bounds 3
bounds -1247 -10 9 
property_list 
material 4
region 1786
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1786
end_property_list 
<component> 1796 
n_bounds 7
bounds 99 1053 9 1248 -1056 -114 -10 
property_list 
material 2
region 1787
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1787
end_property_list 
<component> 1797 
n_bounds 4
bounds -1248 -10 9 1249 
property_list 
material 3
region 1788
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1788
end_property_list 
<component> 1798 
n_bounds 3
bounds -1249 -10 9 
property_list 
material 4
region 1789
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1789
end_property_list 
<component> 1799 
n_bounds 7
bounds 99 1056 9 1250 -1059 -114 -10 
property_list 
material 2
region 1790
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1790
end_property_list 
<component> 1800 
n_bounds 4
bounds -1250 -10 9 1251 
property_list 
material 3
region 1791
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1791
end_property_list 
<component> 1801 
n_bounds 3
bounds -1251 -10 9 
property_list 
material 4
region 1792
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1792
end_property_list 
<component> 1802 
n_bounds 7
bounds 99 1059 9 1252 -1062 -114 -10 
property_list 
material 2
region 1793
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1793
end_property_list 
<component> 1803 
n_bounds 4
bounds -1252 -10 9 1253 
property_list 
material 3
region 1794
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1794
end_property_list 
<component> 1804 
n_bounds 3
bounds -1253 -10 9 
property_list 
material 4
region 1795
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1795
end_property_list 
<component> 1805 
n_bounds 7
bounds 99 1062 9 1254 -1065 -114 -10 
property_list 
material 2
region 1796
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1796
end_property_list 
<component> 1806 
n_bounds 4
bounds -1254 -10 9 1255 
property_list 
material 3
region 1797
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1797
end_property_list 
<component> 1807 
n_bounds 3
bounds -1255 -10 9 
property_list 
material 4
region 1798
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1798
end_property_list 
<component> 1808 
n_bounds 7
bounds 99 1065 9 1256 -1068 -114 -10 
property_list 
material 2
region 1799
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1799
end_property_list 
<component> 1809 
n_bounds 4
bounds -1256 -10 9 1257 
property_list 
material 3
region 1800
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1800
end_property_list 
<component> 1810 
n_bounds 3
bounds -1257 -10 9 
property_list 
material 4
region 1801
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1801
end_property_list 
<component> 1811 
n_bounds 7
bounds 99 1068 9 1258 -17 -114 -10 
property_list 
material 2
region 1802
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1802
end_property_list 
<component> 1812 
n_bounds 4
bounds -1258 -10 9 1259 
property_list 
material 3
region 1803
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1803
end_property_list 
<component> 1813 
n_bounds 3
bounds -1259 -10 9 
property_list 
material 4
region 1804
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1804
end_property_list 
<component> 1814 
n_bounds 7
bounds 99 17 9 1260 -1073 -114 -10 
property_list 
material 2
region 1805
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1805
end_property_list 
<component> 1815 
n_bounds 4
bounds -1260 -10 9 1261 
property_list 
material 3
region 1806
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1806
end_property_list 
<component> 1816 
n_bounds 3
bounds -1261 -10 9 
property_list 
material 4
region 1807
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1807
end_property_list 
<component> 1817 
n_bounds 7
bounds 99 1073 9 1262 -1076 -114 -10 
property_list 
material 2
region 1808
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1808
end_property_list 
<component> 1818 
n_bounds 4
bounds -1262 -10 9 1263 
property_list 
material 3
region 1809
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1809
end_property_list 
<component> 1819 
n_bounds 3
bounds -1263 -10 9 
property_list 
material 4
region 1810
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1810
end_property_list 
<component> 1820 
n_bounds 7
bounds 99 1076 9 1264 -1079 -114 -10 
property_list 
material 2
region 1811
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1811
end_property_list 
<component> 1821 
n_bounds 4
bounds -1264 -10 9 1265 
property_list 
material 3
region 1812
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1812
end_property_list 
<component> 1822 
n_bounds 3
bounds -1265 -10 9 
property_list 
material 4
region 1813
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1813
end_property_list 
<component> 1823 
n_bounds 7
bounds 99 1079 9 1266 -1082 -114 -10 
property_list 
material 2
region 1814
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1814
end_property_list 
<component> 1824 
n_bounds 4
bounds -1266 -10 9 1267 
property_list 
material 3
region 1815
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1815
end_property_list 
<component> 1825 
n_bounds 3
bounds -1267 -10 9 
property_list 
material 4
region 1816
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1816
end_property_list 
<component> 1826 
n_bounds 7
bounds 99 1082 9 1268 -19 -114 -10 
property_list 
material 2
region 1817
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1817
end_property_list 
<component> 1827 
n_bounds 4
bounds -1268 -10 9 1269 
property_list 
material 3
region 1818
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1818
end_property_list 
<component> 1828 
n_bounds 3
bounds -1269 -10 9 
property_list 
material 4
region 1819
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1819
end_property_list 
<component> 1829 
n_bounds 7
bounds 99 19 9 1270 -1087 -114 -10 
property_list 
material 2
region 1820
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1820
end_property_list 
<component> 1830 
n_bounds 4
bounds -1270 -10 9 1271 
property_list 
material 3
region 1821
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1821
end_property_list 
<component> 1831 
n_bounds 3
bounds -1271 -10 9 
property_list 
material 4
region 1822
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1822
end_property_list 
<component> 1832 
n_bounds 7
bounds 99 1087 9 1272 -1090 -114 -10 
property_list 
material 2
region 1823
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1823
end_property_list 
<component> 1833 
n_bounds 4
bounds -1272 -10 9 1273 
property_list 
material 3
region 1824
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1824
end_property_list 
<component> 1834 
n_bounds 3
bounds -1273 -10 9 
property_list 
material 4
region 1825
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1825
end_property_list 
<component> 1835 
n_bounds 7
bounds 99 1090 9 1274 -1093 -114 -10 
property_list 
material 2
region 1826
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1826
end_property_list 
<component> 1836 
n_bounds 4
bounds -1274 -10 9 1275 
property_list 
material 3
region 1827
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1827
end_property_list 
<component> 1837 
n_bounds 3
bounds -1275 -10 9 
property_list 
material 4
region 1828
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1828
end_property_list 
<component> 1838 
n_bounds 7
bounds 99 1093 9 1276 -1096 -114 -10 
property_list 
material 2
region 1829
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1829
end_property_list 
<component> 1839 
n_bounds 4
bounds -1276 -10 9 1277 
property_list 
material 3
region 1830
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1830
end_property_list 
<component> 1840 
n_bounds 3
bounds -1277 -10 9 
property_list 
material 4
region 1831
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1831
end_property_list 
<component> 1841 
n_bounds 7
bounds 99 1096 9 1278 -22 -114 -10 
property_list 
material 2
region 1832
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1832
end_property_list 
<component> 1842 
n_bounds 4
bounds -1278 -10 9 1279 
property_list 
material 3
region 1833
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1833
end_property_list 
<component> 1843 
n_bounds 3
bounds -1279 -10 9 
property_list 
material 4
region 1834
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1834
end_property_list 
<component> 1844 
n_bounds 7
bounds 114 202 9 1280 -1050 -129 -10 
property_list 
material 2
region 1835
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1835
end_property_list 
<component> 1845 
n_bounds 4
bounds -1280 -10 9 1281 
property_list 
material 3
region 1836
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1836
end_property_list 
<component> 1846 
n_bounds 3
bounds -1281 -10 9 
property_list 
material 4
region 1837
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1837
end_property_list 
<component> 1847 
n_bounds 7
bounds 114 1050 9 1282 -1053 -129 -10 
property_list 
material 2
region 1838
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1838
end_property_list 
<component> 1848 
n_bounds 4
bounds -1282 -10 9 1283 
property_list 
material 3
region 1839
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1839
end_property_list 
<component> 1849 
n_bounds 3
bounds -1283 -10 9 
property_list 
material 4
region 1840
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1840
end_property_list 
<component> 1850 
n_bounds 7
bounds 114 1053 9 1284 -1056 -129 -10 
property_list 
material 2
region 1841
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1841
end_property_list 
<component> 1851 
n_bounds 4
bounds -1284 -10 9 1285 
property_list 
material 3
region 1842
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1842
end_property_list 
<component> 1852 
n_bounds 3
bounds -1285 -10 9 
property_list 
material 4
region 1843
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1843
end_property_list 
<component> 1853 
n_bounds 7
bounds 114 1056 9 1286 -1059 -129 -10 
property_list 
material 2
region 1844
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1844
end_property_list 
<component> 1854 
n_bounds 4
bounds -1286 -10 9 1287 
property_list 
material 3
region 1845
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1845
end_property_list 
<component> 1855 
n_bounds 3
bounds -1287 -10 9 
property_list 
material 4
region 1846
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1846
end_property_list 
<component> 1856 
n_bounds 7
bounds 114 1059 9 1288 -1062 -129 -10 
property_list 
material 2
region 1847
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1847
end_property_list 
<component> 1857 
n_bounds 4
bounds -1288 -10 9 1289 
property_list 
material 3
region 1848
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1848
end_property_list 
<component> 1858 
n_bounds 3
bounds -1289 -10 9 
property_list 
material 4
region 1849
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1849
end_property_list 
<component> 1859 
n_bounds 7
bounds 114 1062 9 1290 -1065 -129 -10 
property_list 
material 2
region 1850
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1850
end_property_list 
<component> 1860 
n_bounds 4
bounds -1290 -10 9 1291 
property_list 
material 3
region 1851
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1851
end_property_list 
<component> 1861 
n_bounds 3
bounds -1291 -10 9 
property_list 
material 4
region 1852
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1852
end_property_list 
<component> 1862 
n_bounds 7
bounds 114 1065 9 1292 -1068 -129 -10 
property_list 
material 2
region 1853
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1853
end_property_list 
<component> 1863 
n_bounds 4
bounds -1292 -10 9 1293 
property_list 
material 3
region 1854
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1854
end_property_list 
<component> 1864 
n_bounds 3
bounds -1293 -10 9 
property_list 
material 4
region 1855
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1855
end_property_list 
<component> 1865 
n_bounds 7
bounds 114 1068 9 1294 -17 -129 -10 
property_list 
material 2
region 1856
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1856
end_property_list 
<component> 1866 
n_bounds 4
bounds -1294 -10 9 1295 
property_list 
material 3
region 1857
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1857
end_property_list 
<component> 1867 
n_bounds 3
bounds -1295 -10 9 
property_list 
material 4
region 1858
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1858
end_property_list 
<component> 1868 
n_bounds 7
bounds 114 17 9 1296 -1073 -129 -10 
property_list 
material 2
region 1859
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1859
end_property_list 
<component> 1869 
n_bounds 4
bounds -1296 -10 9 1297 
property_list 
material 3
region 1860
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1860
end_property_list 
<component> 1870 
n_bounds 3
bounds -1297 -10 9 
property_list 
material 4
region 1861
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1861
end_property_list 
<component> 1871 
n_bounds 7
bounds 114 1073 9 1298 -1076 -129 -10 
property_list 
material 2
region 1862
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1862
end_property_list 
<component> 1872 
n_bounds 4
bounds -1298 -10 9 1299 
property_list 
material 3
region 1863
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1863
end_property_list 
<component> 1873 
n_bounds 3
bounds -1299 -10 9 
property_list 
material 4
region 1864
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1864
end_property_list 
<component> 1874 
n_bounds 7
bounds 114 1076 9 1300 -1079 -129 -10 
property_list 
material 2
region 1865
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1865
end_property_list 
<component> 1875 
n_bounds 4
bounds -1300 -10 9 1301 
property_list 
material 3
region 1866
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1866
end_property_list 
<component> 1876 
n_bounds 3
bounds -1301 -10 9 
property_list 
material 4
region 1867
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1867
end_property_list 
<component> 1877 
n_bounds 7
bounds 114 1079 9 1302 -1082 -129 -10 
property_list 
material 2
region 1868
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1868
end_property_list 
<component> 1878 
n_bounds 4
bounds -1302 -10 9 1303 
property_list 
material 3
region 1869
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1869
end_property_list 
<component> 1879 
n_bounds 3
bounds -1303 -10 9 
property_list 
material 4
region 1870
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1870
end_property_list 
<component> 1880 
n_bounds 7
bounds 114 1082 9 1304 -19 -129 -10 
property_list 
material 2
region 1871
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1871
end_property_list 
<component> 1881 
n_bounds 4
bounds -1304 -10 9 1305 
property_list 
material 3
region 1872
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1872
end_property_list 
<component> 1882 
n_bounds 3
bounds -1305 -10 9 
property_list 
material 4
region 1873
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1873
end_property_list 
<component> 1883 
n_bounds 7
bounds 114 19 9 1306 -1087 -129 -10 
property_list 
material 2
region 1874
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1874
end_property_list 
<component> 1884 
n_bounds 4
bounds -1306 -10 9 1307 
property_list 
material 3
region 1875
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1875
end_property_list 
<component> 1885 
n_bounds 3
bounds -1307 -10 9 
property_list 
material 4
region 1876
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1876
end_property_list 
<component> 1886 
n_bounds 7
bounds 114 1087 9 1308 -1090 -129 -10 
property_list 
material 2
region 1877
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1877
end_property_list 
<component> 1887 
n_bounds 4
bounds -1308 -10 9 1309 
property_list 
material 3
region 1878
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1878
end_property_list 
<component> 1888 
n_bounds 3
bounds -1309 -10 9 
property_list 
material 4
region 1879
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1879
end_property_list 
<component> 1889 
n_bounds 7
bounds 114 1090 9 1310 -1093 -129 -10 
property_list 
material 2
region 1880
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1880
end_property_list 
<component> 1890 
n_bounds 4
bounds -1310 -10 9 1311 
property_list 
material 3
region 1881
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1881
end_property_list 
<component> 1891 
n_bounds 3
bounds -1311 -10 9 
property_list 
material 4
region 1882
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1882
end_property_list 
<component> 1892 
n_bounds 7
bounds 114 1093 9 1312 -1096 -129 -10 
property_list 
material 2
region 1883
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1883
end_property_list 
<component> 1893 
n_bounds 4
bounds -1312 -10 9 1313 
property_list 
material 3
region 1884
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1884
end_property_list 
<component> 1894 
n_bounds 3
bounds -1313 -10 9 
property_list 
material 4
region 1885
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1885
end_property_list 
<component> 1895 
n_bounds 7
bounds 114 1096 9 1314 -22 -129 -10 
property_list 
material 2
region 1886
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1886
end_property_list 
<component> 1896 
n_bounds 4
bounds -1314 -10 9 1315 
property_list 
material 3
region 1887
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1887
end_property_list 
<component> 1897 
n_bounds 3
bounds -1315 -10 9 
property_list 
material 4
region 1888
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1888
end_property_list 
<component> 1898 
n_bounds 7
bounds 129 202 9 1316 -1050 -146 -10 
property_list 
material 2
region 1889
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1889
end_property_list 
<component> 1899 
n_bounds 4
bounds -1316 -10 9 1317 
property_list 
material 3
region 1890
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1890
end_property_list 
<component> 1900 
n_bounds 3
bounds -1317 -10 9 
property_list 
material 4
region 1891
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1891
end_property_list 
<component> 1901 
n_bounds 7
bounds 129 1050 9 1318 -1053 -146 -10 
property_list 
material 2
region 1892
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1892
end_property_list 
<component> 1902 
n_bounds 4
bounds -1318 -10 9 1319 
property_list 
material 3
region 1893
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1893
end_property_list 
<component> 1903 
n_bounds 3
bounds -1319 -10 9 
property_list 
material 4
region 1894
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1894
end_property_list 
<component> 1904 
n_bounds 7
bounds 129 1053 9 1320 -1056 -146 -10 
property_list 
material 2
region 1895
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1895
end_property_list 
<component> 1905 
n_bounds 4
bounds -1320 -10 9 1321 
property_list 
material 3
region 1896
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1896
end_property_list 
<component> 1906 
n_bounds 3
bounds -1321 -10 9 
property_list 
material 4
region 1897
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1897
end_property_list 
<component> 1907 
n_bounds 7
bounds 129 1056 9 1322 -1059 -146 -10 
property_list 
material 2
region 1898
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1898
end_property_list 
<component> 1908 
n_bounds 4
bounds -1322 -10 9 1323 
property_list 
material 3
region 1899
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1899
end_property_list 
<component> 1909 
n_bounds 3
bounds -1323 -10 9 
property_list 
material 4
region 1900
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1900
end_property_list 
<component> 1910 
n_bounds 7
bounds 129 1059 9 1324 -1062 -146 -10 
property_list 
material 2
region 1901
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1901
end_property_list 
<component> 1911 
n_bounds 4
bounds -1324 -10 9 1325 
property_list 
material 3
region 1902
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1902
end_property_list 
<component> 1912 
n_bounds 3
bounds -1325 -10 9 
property_list 
material 4
region 1903
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1903
end_property_list 
<component> 1913 
n_bounds 7
bounds 129 1062 9 1326 -1065 -146 -10 
property_list 
material 2
region 1904
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1904
end_property_list 
<component> 1914 
n_bounds 4
bounds -1326 -10 9 1327 
property_list 
material 3
region 1905
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1905
end_property_list 
<component> 1915 
n_bounds 3
bounds -1327 -10 9 
property_list 
material 4
region 1906
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1906
end_property_list 
<component> 1916 
n_bounds 7
bounds 129 1065 9 1328 -1068 -146 -10 
property_list 
material 2
region 1907
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1907
end_property_list 
<component> 1917 
n_bounds 4
bounds -1328 -10 9 1329 
property_list 
material 3
region 1908
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1908
end_property_list 
<component> 1918 
n_bounds 3
bounds -1329 -10 9 
property_list 
material 4
region 1909
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1909
end_property_list 
<component> 1919 
n_bounds 7
bounds 129 1068 9 1330 -17 -146 -10 
property_list 
material 2
region 1910
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1910
end_property_list 
<component> 1920 
n_bounds 4
bounds -1330 -10 9 1331 
property_list 
material 3
region 1911
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1911
end_property_list 
<component> 1921 
n_bounds 3
bounds -1331 -10 9 
property_list 
material 4
region 1912
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1912
end_property_list 
<component> 1922 
n_bounds 7
bounds 129 17 9 1332 -1073 -146 -10 
property_list 
material 2
region 1913
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1913
end_property_list 
<component> 1923 
n_bounds 4
bounds -1332 -10 9 1333 
property_list 
material 3
region 1914
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1914
end_property_list 
<component> 1924 
n_bounds 3
bounds -1333 -10 9 
property_list 
material 4
region 1915
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1915
end_property_list 
<component> 1925 
n_bounds 7
bounds 129 1073 9 1334 -1076 -146 -10 
property_list 
material 2
region 1916
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1916
end_property_list 
<component> 1926 
n_bounds 4
bounds -1334 -10 9 1335 
property_list 
material 3
region 1917
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1917
end_property_list 
<component> 1927 
n_bounds 3
bounds -1335 -10 9 
property_list 
material 4
region 1918
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1918
end_property_list 
<component> 1928 
n_bounds 7
bounds 129 1076 9 1336 -1079 -146 -10 
property_list 
material 2
region 1919
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1919
end_property_list 
<component> 1929 
n_bounds 4
bounds -1336 -10 9 1337 
property_list 
material 3
region 1920
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1920
end_property_list 
<component> 1930 
n_bounds 3
bounds -1337 -10 9 
property_list 
material 4
region 1921
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1921
end_property_list 
<component> 1931 
n_bounds 7
bounds 129 1079 9 1338 -1082 -146 -10 
property_list 
material 2
region 1922
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1922
end_property_list 
<component> 1932 
n_bounds 4
bounds -1338 -10 9 1339 
property_list 
material 3
region 1923
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1923
end_property_list 
<component> 1933 
n_bounds 3
bounds -1339 -10 9 
property_list 
material 4
region 1924
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1924
end_property_list 
<component> 1934 
n_bounds 7
bounds 129 1082 9 1340 -19 -146 -10 
property_list 
material 2
region 1925
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1925
end_property_list 
<component> 1935 
n_bounds 4
bounds -1340 -10 9 1341 
property_list 
material 3
region 1926
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1926
end_property_list 
<component> 1936 
n_bounds 3
bounds -1341 -10 9 
property_list 
material 4
region 1927
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1927
end_property_list 
<component> 1937 
n_bounds 7
bounds 129 19 9 1342 -1087 -146 -10 
property_list 
material 2
region 1928
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1928
end_property_list 
<component> 1938 
n_bounds 4
bounds -1342 -10 9 1343 
property_list 
material 3
region 1929
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1929
end_property_list 
<component> 1939 
n_bounds 3
bounds -1343 -10 9 
property_list 
material 4
region 1930
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1930
end_property_list 
<component> 1940 
n_bounds 7
bounds 129 1087 9 1344 -1090 -146 -10 
property_list 
material 2
region 1931
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1931
end_property_list 
<component> 1941 
n_bounds 4
bounds -1344 -10 9 1345 
property_list 
material 3
region 1932
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1932
end_property_list 
<component> 1942 
n_bounds 3
bounds -1345 -10 9 
property_list 
material 4
region 1933
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1933
end_property_list 
<component> 1943 
n_bounds 7
bounds 129 1090 9 1346 -1093 -146 -10 
property_list 
material 2
region 1934
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1934
end_property_list 
<component> 1944 
n_bounds 4
bounds -1346 -10 9 1347 
property_list 
material 3
region 1935
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1935
end_property_list 
<component> 1945 
n_bounds 3
bounds -1347 -10 9 
property_list 
material 4
region 1936
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1936
end_property_list 
<component> 1946 
n_bounds 7
bounds 129 1093 9 1348 -1096 -146 -10 
property_list 
material 2
region 1937
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1937
end_property_list 
<component> 1947 
n_bounds 4
bounds -1348 -10 9 1349 
property_list 
material 3
region 1938
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1938
end_property_list 
<component> 1948 
n_bounds 3
bounds -1349 -10 9 
property_list 
material 4
region 1939
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1939
end_property_list 
<component> 1949 
n_bounds 7
bounds 129 1096 9 1350 -22 -146 -10 
property_list 
material 2
region 1940
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1940
end_property_list 
<component> 1950 
n_bounds 4
bounds -1350 -10 9 1351 
property_list 
material 3
region 1941
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1941
end_property_list 
<component> 1951 
n_bounds 3
bounds -1351 -10 9 
property_list 
material 4
region 1942
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1942
end_property_list 
<component> 1952 
n_bounds 7
bounds 146 202 9 1352 -1050 -398 -10 
property_list 
material 2
region 1943
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1943
end_property_list 
<component> 1953 
n_bounds 4
bounds -1352 -10 9 1353 
property_list 
material 3
region 1944
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1944
end_property_list 
<component> 1954 
n_bounds 3
bounds -1353 -10 9 
property_list 
material 4
region 1945
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1945
end_property_list 
<component> 1955 
n_bounds 7
bounds 146 1050 9 1354 -1053 -398 -10 
property_list 
material 2
region 1946
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1946
end_property_list 
<component> 1956 
n_bounds 4
bounds -1354 -10 9 1355 
property_list 
material 3
region 1947
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1947
end_property_list 
<component> 1957 
n_bounds 3
bounds -1355 -10 9 
property_list 
material 4
region 1948
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1948
end_property_list 
<component> 1958 
n_bounds 7
bounds 146 1053 9 1356 -1056 -398 -10 
property_list 
material 2
region 1949
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1949
end_property_list 
<component> 1959 
n_bounds 4
bounds -1356 -10 9 1357 
property_list 
material 3
region 1950
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1950
end_property_list 
<component> 1960 
n_bounds 3
bounds -1357 -10 9 
property_list 
material 4
region 1951
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1951
end_property_list 
<component> 1961 
n_bounds 7
bounds 146 1056 9 1358 -1059 -398 -10 
property_list 
material 2
region 1952
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1952
end_property_list 
<component> 1962 
n_bounds 4
bounds -1358 -10 9 1359 
property_list 
material 3
region 1953
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1953
end_property_list 
<component> 1963 
n_bounds 3
bounds -1359 -10 9 
property_list 
material 4
region 1954
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1954
end_property_list 
<component> 1964 
n_bounds 7
bounds 146 1059 9 1360 -1062 -398 -10 
property_list 
material 2
region 1955
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1955
end_property_list 
<component> 1965 
n_bounds 4
bounds -1360 -10 9 1361 
property_list 
material 3
region 1956
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1956
end_property_list 
<component> 1966 
n_bounds 3
bounds -1361 -10 9 
property_list 
material 4
region 1957
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1957
end_property_list 
<component> 1967 
n_bounds 7
bounds 146 1062 9 1362 -1065 -398 -10 
property_list 
material 2
region 1958
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1958
end_property_list 
<component> 1968 
n_bounds 4
bounds -1362 -10 9 1363 
property_list 
material 3
region 1959
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1959
end_property_list 
<component> 1969 
n_bounds 3
bounds -1363 -10 9 
property_list 
material 4
region 1960
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1960
end_property_list 
<component> 1970 
n_bounds 7
bounds 146 1065 9 1364 -1068 -398 -10 
property_list 
material 2
region 1961
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1961
end_property_list 
<component> 1971 
n_bounds 4
bounds -1364 -10 9 1365 
property_list 
material 3
region 1962
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1962
end_property_list 
<component> 1972 
n_bounds 3
bounds -1365 -10 9 
property_list 
material 4
region 1963
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1963
end_property_list 
<component> 1973 
n_bounds 7
bounds 146 1068 9 1366 -17 -398 -10 
property_list 
material 2
region 1964
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1964
end_property_list 
<component> 1974 
n_bounds 4
bounds -1366 -10 9 1367 
property_list 
material 3
region 1965
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1965
end_property_list 
<component> 1975 
n_bounds 3
bounds -1367 -10 9 
property_list 
material 4
region 1966
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1966
end_property_list 
<component> 1976 
n_bounds 7
bounds 146 17 9 1368 -1073 -398 -10 
property_list 
material 2
region 1967
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1967
end_property_list 
<component> 1977 
n_bounds 4
bounds -1368 -10 9 1369 
property_list 
material 3
region 1968
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1968
end_property_list 
<component> 1978 
n_bounds 3
bounds -1369 -10 9 
property_list 
material 4
region 1969
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1969
end_property_list 
<component> 1979 
n_bounds 7
bounds 146 1073 9 1370 -1076 -398 -10 
property_list 
material 2
region 1970
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1970
end_property_list 
<component> 1980 
n_bounds 4
bounds -1370 -10 9 1371 
property_list 
material 3
region 1971
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1971
end_property_list 
<component> 1981 
n_bounds 3
bounds -1371 -10 9 
property_list 
material 4
region 1972
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1972
end_property_list 
<component> 1982 
n_bounds 7
bounds 146 1076 9 1372 -1079 -398 -10 
property_list 
material 2
region 1973
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1973
end_property_list 
<component> 1983 
n_bounds 4
bounds -1372 -10 9 1373 
property_list 
material 3
region 1974
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1974
end_property_list 
<component> 1984 
n_bounds 3
bounds -1373 -10 9 
property_list 
material 4
region 1975
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1975
end_property_list 
<component> 1985 
n_bounds 7
bounds 146 1079 9 1374 -1082 -398 -10 
property_list 
material 2
region 1976
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1976
end_property_list 
<component> 1986 
n_bounds 4
bounds -1374 -10 9 1375 
property_list 
material 3
region 1977
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1977
end_property_list 
<component> 1987 
n_bounds 3
bounds -1375 -10 9 
property_list 
material 4
region 1978
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1978
end_property_list 
<component> 1988 
n_bounds 7
bounds 146 1082 9 1376 -19 -398 -10 
property_list 
material 2
region 1979
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1979
end_property_list 
<component> 1989 
n_bounds 4
bounds -1376 -10 9 1377 
property_list 
material 3
region 1980
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1980
end_property_list 
<component> 1990 
n_bounds 3
bounds -1377 -10 9 
property_list 
material 4
region 1981
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1981
end_property_list 
<component> 1991 
n_bounds 7
bounds 146 19 9 1378 -1087 -398 -10 
property_list 
material 2
region 1982
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1982
end_property_list 
<component> 1992 
n_bounds 4
bounds -1378 -10 9 1379 
property_list 
material 3
region 1983
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1983
end_property_list 
<component> 1993 
n_bounds 3
bounds -1379 -10 9 
property_list 
material 4
region 1984
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1984
end_property_list 
<component> 1994 
n_bounds 7
bounds 146 1087 9 1380 -1090 -398 -10 
property_list 
material 2
region 1985
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1985
end_property_list 
<component> 1995 
n_bounds 4
bounds -1380 -10 9 1381 
property_list 
material 3
region 1986
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1986
end_property_list 
<component> 1996 
n_bounds 3
bounds -1381 -10 9 
property_list 
material 4
region 1987
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1987
end_property_list 
<component> 1997 
n_bounds 7
bounds 146 1090 9 1382 -1093 -398 -10 
property_list 
material 2
region 1988
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1988
end_property_list 
<component> 1998 
n_bounds 4
bounds -1382 -10 9 1383 
property_list 
material 3
region 1989
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1989
end_property_list 
<component> 1999 
n_bounds 3
bounds -1383 -10 9 
property_list 
material 4
region 1990
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1990
end_property_list 
<component> 2000 
n_bounds 7
bounds 146 1093 9 1384 -1096 -398 -10 
property_list 
material 2
region 1991
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1991
end_property_list 
<component> 2001 
n_bounds 4
bounds -1384 -10 9 1385 
property_list 
material 3
region 1992
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1992
end_property_list 
<component> 2002 
n_bounds 3
bounds -1385 -10 9 
property_list 
material 4
region 1993
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1993
end_property_list 
<component> 2003 
n_bounds 7
bounds 146 1096 9 1386 -22 -398 -10 
property_list 
material 2
region 1994
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1994
end_property_list 
<component> 2004 
n_bounds 4
bounds -1386 -10 9 1387 
property_list 
material 3
region 1995
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1995
end_property_list 
<component> 2005 
n_bounds 3
bounds -1387 -10 9 
property_list 
material 4
region 1996
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1996
end_property_list 
<component> 2006 
n_bounds 7
bounds 398 202 9 1388 -1050 -415 -10 
property_list 
material 2
region 1997
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-1997
end_property_list 
<component> 2007 
n_bounds 4
bounds -1388 -10 9 1389 
property_list 
material 3
region 1998
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-1998
end_property_list 
<component> 2008 
n_bounds 3
bounds -1389 -10 9 
property_list 
material 4
region 1999
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-1999
end_property_list 
<component> 2009 
n_bounds 7
bounds 398 1050 9 1390 -1053 -415 -10 
property_list 
material 2
region 2000
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2000
end_property_list 
<component> 2010 
n_bounds 4
bounds -1390 -10 9 1391 
property_list 
material 3
region 2001
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2001
end_property_list 
<component> 2011 
n_bounds 3
bounds -1391 -10 9 
property_list 
material 4
region 2002
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2002
end_property_list 
<component> 2012 
n_bounds 7
bounds 398 1053 9 1392 -1056 -415 -10 
property_list 
material 2
region 2003
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2003
end_property_list 
<component> 2013 
n_bounds 4
bounds -1392 -10 9 1393 
property_list 
material 3
region 2004
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2004
end_property_list 
<component> 2014 
n_bounds 3
bounds -1393 -10 9 
property_list 
material 4
region 2005
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2005
end_property_list 
<component> 2015 
n_bounds 7
bounds 398 1056 9 1394 -1059 -415 -10 
property_list 
material 2
region 2006
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2006
end_property_list 
<component> 2016 
n_bounds 4
bounds -1394 -10 9 1395 
property_list 
material 3
region 2007
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2007
end_property_list 
<component> 2017 
n_bounds 3
bounds -1395 -10 9 
property_list 
material 4
region 2008
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2008
end_property_list 
<component> 2018 
n_bounds 7
bounds 398 1059 9 1396 -1062 -415 -10 
property_list 
material 2
region 2009
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2009
end_property_list 
<component> 2019 
n_bounds 4
bounds -1396 -10 9 1397 
property_list 
material 3
region 2010
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2010
end_property_list 
<component> 2020 
n_bounds 3
bounds -1397 -10 9 
property_list 
material 4
region 2011
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2011
end_property_list 
<component> 2021 
n_bounds 7
bounds 398 1062 9 1398 -1065 -415 -10 
property_list 
material 2
region 2012
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2012
end_property_list 
<component> 2022 
n_bounds 4
bounds -1398 -10 9 1399 
property_list 
material 3
region 2013
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2013
end_property_list 
<component> 2023 
n_bounds 3
bounds -1399 -10 9 
property_list 
material 4
region 2014
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2014
end_property_list 
<component> 2024 
n_bounds 7
bounds 398 1065 9 1400 -1068 -415 -10 
property_list 
material 2
region 2015
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2015
end_property_list 
<component> 2025 
n_bounds 4
bounds -1400 -10 9 1401 
property_list 
material 3
region 2016
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2016
end_property_list 
<component> 2026 
n_bounds 3
bounds -1401 -10 9 
property_list 
material 4
region 2017
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2017
end_property_list 
<component> 2027 
n_bounds 7
bounds 398 1068 9 1402 -17 -415 -10 
property_list 
material 2
region 2018
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2018
end_property_list 
<component> 2028 
n_bounds 4
bounds -1402 -10 9 1403 
property_list 
material 3
region 2019
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2019
end_property_list 
<component> 2029 
n_bounds 3
bounds -1403 -10 9 
property_list 
material 4
region 2020
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2020
end_property_list 
<component> 2030 
n_bounds 7
bounds 398 17 9 1404 -1073 -415 -10 
property_list 
material 2
region 2021
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2021
end_property_list 
<component> 2031 
n_bounds 4
bounds -1404 -10 9 1405 
property_list 
material 3
region 2022
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2022
end_property_list 
<component> 2032 
n_bounds 3
bounds -1405 -10 9 
property_list 
material 4
region 2023
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2023
end_property_list 
<component> 2033 
n_bounds 7
bounds 398 1073 9 1406 -1076 -415 -10 
property_list 
material 2
region 2024
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2024
end_property_list 
<component> 2034 
n_bounds 4
bounds -1406 -10 9 1407 
property_list 
material 3
region 2025
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2025
end_property_list 
<component> 2035 
n_bounds 3
bounds -1407 -10 9 
property_list 
material 4
region 2026
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2026
end_property_list 
<component> 2036 
n_bounds 7
bounds 398 1076 9 1408 -1079 -415 -10 
property_list 
material 2
region 2027
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2027
end_property_list 
<component> 2037 
n_bounds 4
bounds -1408 -10 9 1409 
property_list 
material 3
region 2028
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2028
end_property_list 
<component> 2038 
n_bounds 3
bounds -1409 -10 9 
property_list 
material 4
region 2029
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2029
end_property_list 
<component> 2039 
n_bounds 7
bounds 398 1079 9 1410 -1082 -415 -10 
property_list 
material 2
region 2030
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2030
end_property_list 
<component> 2040 
n_bounds 4
bounds -1410 -10 9 1411 
property_list 
material 3
region 2031
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2031
end_property_list 
<component> 2041 
n_bounds 3
bounds -1411 -10 9 
property_list 
material 4
region 2032
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2032
end_property_list 
<component> 2042 
n_bounds 7
bounds 398 1082 9 1412 -19 -415 -10 
property_list 
material 2
region 2033
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2033
end_property_list 
<component> 2043 
n_bounds 4
bounds -1412 -10 9 1413 
property_list 
material 3
region 2034
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2034
end_property_list 
<component> 2044 
n_bounds 3
bounds -1413 -10 9 
property_list 
material 4
region 2035
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2035
end_property_list 
<component> 2045 
n_bounds 7
bounds 398 19 9 1414 -1087 -415 -10 
property_list 
material 2
region 2036
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2036
end_property_list 
<component> 2046 
n_bounds 4
bounds -1414 -10 9 1415 
property_list 
material 3
region 2037
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2037
end_property_list 
<component> 2047 
n_bounds 3
bounds -1415 -10 9 
property_list 
material 4
region 2038
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2038
end_property_list 
<component> 2048 
n_bounds 7
bounds 398 1087 9 1416 -1090 -415 -10 
property_list 
material 2
region 2039
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2039
end_property_list 
<component> 2049 
n_bounds 4
bounds -1416 -10 9 1417 
property_list 
material 3
region 2040
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2040
end_property_list 
<component> 2050 
n_bounds 3
bounds -1417 -10 9 
property_list 
material 4
region 2041
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2041
end_property_list 
<component> 2051 
n_bounds 7
bounds 398 1090 9 1418 -1093 -415 -10 
property_list 
material 2
region 2042
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2042
end_property_list 
<component> 2052 
n_bounds 4
bounds -1418 -10 9 1419 
property_list 
material 3
region 2043
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2043
end_property_list 
<component> 2053 
n_bounds 3
bounds -1419 -10 9 
property_list 
material 4
region 2044
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2044
end_property_list 
<component> 2054 
n_bounds 7
bounds 398 1093 9 1420 -1096 -415 -10 
property_list 
material 2
region 2045
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2045
end_property_list 
<component> 2055 
n_bounds 4
bounds -1420 -10 9 1421 
property_list 
material 3
region 2046
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2046
end_property_list 
<component> 2056 
n_bounds 3
bounds -1421 -10 9 
property_list 
material 4
region 2047
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2047
end_property_list 
<component> 2057 
n_bounds 7
bounds 398 1096 9 1422 -22 -415 -10 
property_list 
material 2
region 2048
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2048
end_property_list 
<component> 2058 
n_bounds 4
bounds -1422 -10 9 1423 
property_list 
material 3
region 2049
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2049
end_property_list 
<component> 2059 
n_bounds 3
bounds -1423 -10 9 
property_list 
material 4
region 2050
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2050
end_property_list 
<component> 2060 
n_bounds 7
bounds 415 202 9 1424 -1050 -21 -10 
property_list 
material 2
region 2051
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2051
end_property_list 
<component> 2061 
n_bounds 4
bounds -1424 -10 9 1425 
property_list 
material 3
region 2052
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2052
end_property_list 
<component> 2062 
n_bounds 3
bounds -1425 -10 9 
property_list 
material 4
region 2053
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2053
end_property_list 
<component> 2063 
n_bounds 7
bounds 415 1050 9 1426 -1053 -21 -10 
property_list 
material 2
region 2054
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2054
end_property_list 
<component> 2064 
n_bounds 4
bounds -1426 -10 9 1427 
property_list 
material 3
region 2055
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2055
end_property_list 
<component> 2065 
n_bounds 3
bounds -1427 -10 9 
property_list 
material 4
region 2056
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2056
end_property_list 
<component> 2066 
n_bounds 7
bounds 415 1053 9 1428 -1056 -21 -10 
property_list 
material 2
region 2057
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2057
end_property_list 
<component> 2067 
n_bounds 4
bounds -1428 -10 9 1429 
property_list 
material 3
region 2058
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2058
end_property_list 
<component> 2068 
n_bounds 3
bounds -1429 -10 9 
property_list 
material 4
region 2059
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2059
end_property_list 
<component> 2069 
n_bounds 7
bounds 415 1056 9 1430 -1059 -21 -10 
property_list 
material 2
region 2060
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2060
end_property_list 
<component> 2070 
n_bounds 4
bounds -1430 -10 9 1431 
property_list 
material 3
region 2061
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2061
end_property_list 
<component> 2071 
n_bounds 3
bounds -1431 -10 9 
property_list 
material 4
region 2062
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2062
end_property_list 
<component> 2072 
n_bounds 7
bounds 415 1059 9 1432 -1062 -21 -10 
property_list 
material 2
region 2063
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2063
end_property_list 
<component> 2073 
n_bounds 4
bounds -1432 -10 9 1433 
property_list 
material 3
region 2064
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2064
end_property_list 
<component> 2074 
n_bounds 3
bounds -1433 -10 9 
property_list 
material 4
region 2065
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2065
end_property_list 
<component> 2075 
n_bounds 7
bounds 415 1062 9 1434 -1065 -21 -10 
property_list 
material 2
region 2066
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2066
end_property_list 
<component> 2076 
n_bounds 4
bounds -1434 -10 9 1435 
property_list 
material 3
region 2067
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2067
end_property_list 
<component> 2077 
n_bounds 3
bounds -1435 -10 9 
property_list 
material 4
region 2068
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2068
end_property_list 
<component> 2078 
n_bounds 7
bounds 415 1065 9 1436 -1068 -21 -10 
property_list 
material 2
region 2069
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2069
end_property_list 
<component> 2079 
n_bounds 4
bounds -1436 -10 9 1437 
property_list 
material 3
region 2070
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2070
end_property_list 
<component> 2080 
n_bounds 3
bounds -1437 -10 9 
property_list 
material 4
region 2071
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2071
end_property_list 
<component> 2081 
n_bounds 7
bounds 415 1068 9 1438 -17 -21 -10 
property_list 
material 2
region 2072
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2072
end_property_list 
<component> 2082 
n_bounds 4
bounds -1438 -10 9 1439 
property_list 
material 3
region 2073
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2073
end_property_list 
<component> 2083 
n_bounds 3
bounds -1439 -10 9 
property_list 
material 4
region 2074
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2074
end_property_list 
<component> 2084 
n_bounds 7
bounds 415 17 9 1440 -1073 -21 -10 
property_list 
material 2
region 2075
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2075
end_property_list 
<component> 2085 
n_bounds 4
bounds -1440 -10 9 1441 
property_list 
material 3
region 2076
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2076
end_property_list 
<component> 2086 
n_bounds 3
bounds -1441 -10 9 
property_list 
material 4
region 2077
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2077
end_property_list 
<component> 2087 
n_bounds 7
bounds 415 1073 9 1442 -1076 -21 -10 
property_list 
material 2
region 2078
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2078
end_property_list 
<component> 2088 
n_bounds 4
bounds -1442 -10 9 1443 
property_list 
material 3
region 2079
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2079
end_property_list 
<component> 2089 
n_bounds 3
bounds -1443 -10 9 
property_list 
material 4
region 2080
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2080
end_property_list 
<component> 2090 
n_bounds 7
bounds 415 1076 9 1444 -1079 -21 -10 
property_list 
material 2
region 2081
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2081
end_property_list 
<component> 2091 
n_bounds 4
bounds -1444 -10 9 1445 
property_list 
material 3
region 2082
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2082
end_property_list 
<component> 2092 
n_bounds 3
bounds -1445 -10 9 
property_list 
material 4
region 2083
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2083
end_property_list 
<component> 2093 
n_bounds 7
bounds 415 1079 9 1446 -1082 -21 -10 
property_list 
material 2
region 2084
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2084
end_property_list 
<component> 2094 
n_bounds 4
bounds -1446 -10 9 1447 
property_list 
material 3
region 2085
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2085
end_property_list 
<component> 2095 
n_bounds 3
bounds -1447 -10 9 
property_list 
material 4
region 2086
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2086
end_property_list 
<component> 2096 
n_bounds 7
bounds 415 1082 9 1448 -19 -21 -10 
property_list 
material 2
region 2087
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2087
end_property_list 
<component> 2097 
n_bounds 4
bounds -1448 -10 9 1449 
property_list 
material 3
region 2088
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2088
end_property_list 
<component> 2098 
n_bounds 3
bounds -1449 -10 9 
property_list 
material 4
region 2089
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2089
end_property_list 
<component> 2099 
n_bounds 7
bounds 415 19 9 1450 -1087 -21 -10 
property_list 
material 2
region 2090
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2090
end_property_list 
<component> 2100 
n_bounds 4
bounds -1450 -10 9 1451 
property_list 
material 3
region 2091
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2091
end_property_list 
<component> 2101 
n_bounds 3
bounds -1451 -10 9 
property_list 
material 4
region 2092
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2092
end_property_list 
<component> 2102 
n_bounds 7
bounds 415 1087 9 1452 -1090 -21 -10 
property_list 
material 2
region 2093
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2093
end_property_list 
<component> 2103 
n_bounds 4
bounds -1452 -10 9 1453 
property_list 
material 3
region 2094
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2094
end_property_list 
<component> 2104 
n_bounds 3
bounds -1453 -10 9 
property_list 
material 4
region 2095
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2095
end_property_list 
<component> 2105 
n_bounds 7
bounds 415 1090 9 1454 -1093 -21 -10 
property_list 
material 2
region 2096
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2096
end_property_list 
<component> 2106 
n_bounds 4
bounds -1454 -10 9 1455 
property_list 
material 3
region 2097
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2097
end_property_list 
<component> 2107 
n_bounds 3
bounds -1455 -10 9 
property_list 
material 4
region 2098
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2098
end_property_list 
<component> 2108 
n_bounds 7
bounds 415 1093 9 1456 -1096 -21 -10 
property_list 
material 2
region 2099
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2099
end_property_list 
<component> 2109 
n_bounds 4
bounds -1456 -10 9 1457 
property_list 
material 3
region 2100
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2100
end_property_list 
<component> 2110 
n_bounds 3
bounds -1457 -10 9 
property_list 
material 4
region 2101
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2101
end_property_list 
<component> 2111 
n_bounds 7
bounds 415 1096 9 1458 -22 -21 -10 
property_list 
material 2
region 2102
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2102
end_property_list 
<component> 2112 
n_bounds 4
bounds -1458 -10 9 1459 
property_list 
material 3
region 2103
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2103
end_property_list 
<component> 2113 
n_bounds 3
bounds -1459 -10 9 
property_list 
material 4
region 2104
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2104
end_property_list 
<component> 2114 
n_bounds 7
bounds 21 202 9 1460 -1050 -446 -10 
property_list 
material 2
region 2105
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2105
end_property_list 
<component> 2115 
n_bounds 4
bounds -1460 -10 9 1461 
property_list 
material 3
region 2106
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2106
end_property_list 
<component> 2116 
n_bounds 3
bounds -1461 -10 9 
property_list 
material 4
region 2107
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2107
end_property_list 
<component> 2117 
n_bounds 7
bounds 21 1050 9 1462 -1053 -446 -10 
property_list 
material 2
region 2108
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2108
end_property_list 
<component> 2118 
n_bounds 4
bounds -1462 -10 9 1463 
property_list 
material 3
region 2109
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2109
end_property_list 
<component> 2119 
n_bounds 3
bounds -1463 -10 9 
property_list 
material 4
region 2110
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2110
end_property_list 
<component> 2120 
n_bounds 7
bounds 21 1053 9 1464 -1056 -446 -10 
property_list 
material 2
region 2111
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2111
end_property_list 
<component> 2121 
n_bounds 4
bounds -1464 -10 9 1465 
property_list 
material 3
region 2112
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2112
end_property_list 
<component> 2122 
n_bounds 3
bounds -1465 -10 9 
property_list 
material 4
region 2113
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2113
end_property_list 
<component> 2123 
n_bounds 7
bounds 21 1056 9 1466 -1059 -446 -10 
property_list 
material 2
region 2114
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2114
end_property_list 
<component> 2124 
n_bounds 4
bounds -1466 -10 9 1467 
property_list 
material 3
region 2115
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2115
end_property_list 
<component> 2125 
n_bounds 3
bounds -1467 -10 9 
property_list 
material 4
region 2116
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2116
end_property_list 
<component> 2126 
n_bounds 7
bounds 21 1059 9 1468 -1062 -446 -10 
property_list 
material 2
region 2117
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2117
end_property_list 
<component> 2127 
n_bounds 4
bounds -1468 -10 9 1469 
property_list 
material 3
region 2118
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2118
end_property_list 
<component> 2128 
n_bounds 3
bounds -1469 -10 9 
property_list 
material 4
region 2119
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2119
end_property_list 
<component> 2129 
n_bounds 7
bounds 21 1062 9 1470 -1065 -446 -10 
property_list 
material 2
region 2120
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2120
end_property_list 
<component> 2130 
n_bounds 4
bounds -1470 -10 9 1471 
property_list 
material 3
region 2121
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2121
end_property_list 
<component> 2131 
n_bounds 3
bounds -1471 -10 9 
property_list 
material 4
region 2122
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2122
end_property_list 
<component> 2132 
n_bounds 7
bounds 21 1065 9 1472 -1068 -446 -10 
property_list 
material 2
region 2123
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2123
end_property_list 
<component> 2133 
n_bounds 4
bounds -1472 -10 9 1473 
property_list 
material 3
region 2124
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2124
end_property_list 
<component> 2134 
n_bounds 3
bounds -1473 -10 9 
property_list 
material 4
region 2125
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2125
end_property_list 
<component> 2135 
n_bounds 7
bounds 21 1068 9 1474 -17 -446 -10 
property_list 
material 2
region 2126
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2126
end_property_list 
<component> 2136 
n_bounds 4
bounds -1474 -10 9 1475 
property_list 
material 3
region 2127
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2127
end_property_list 
<component> 2137 
n_bounds 3
bounds -1475 -10 9 
property_list 
material 4
region 2128
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2128
end_property_list 
<component> 2138 
n_bounds 7
bounds 21 17 9 1476 -1073 -446 -10 
property_list 
material 2
region 2129
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2129
end_property_list 
<component> 2139 
n_bounds 4
bounds -1476 -10 9 1477 
property_list 
material 3
region 2130
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2130
end_property_list 
<component> 2140 
n_bounds 3
bounds -1477 -10 9 
property_list 
material 4
region 2131
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2131
end_property_list 
<component> 2141 
n_bounds 7
bounds 21 1073 9 1478 -1076 -446 -10 
property_list 
material 2
region 2132
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2132
end_property_list 
<component> 2142 
n_bounds 4
bounds -1478 -10 9 1479 
property_list 
material 3
region 2133
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2133
end_property_list 
<component> 2143 
n_bounds 3
bounds -1479 -10 9 
property_list 
material 4
region 2134
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2134
end_property_list 
<component> 2144 
n_bounds 7
bounds 21 1076 9 1480 -1079 -446 -10 
property_list 
material 2
region 2135
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2135
end_property_list 
<component> 2145 
n_bounds 4
bounds -1480 -10 9 1481 
property_list 
material 3
region 2136
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2136
end_property_list 
<component> 2146 
n_bounds 3
bounds -1481 -10 9 
property_list 
material 4
region 2137
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2137
end_property_list 
<component> 2147 
n_bounds 7
bounds 21 1079 9 1482 -1082 -446 -10 
property_list 
material 2
region 2138
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2138
end_property_list 
<component> 2148 
n_bounds 4
bounds -1482 -10 9 1483 
property_list 
material 3
region 2139
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2139
end_property_list 
<component> 2149 
n_bounds 3
bounds -1483 -10 9 
property_list 
material 4
region 2140
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2140
end_property_list 
<component> 2150 
n_bounds 7
bounds 21 1082 9 1484 -19 -446 -10 
property_list 
material 2
region 2141
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2141
end_property_list 
<component> 2151 
n_bounds 4
bounds -1484 -10 9 1485 
property_list 
material 3
region 2142
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2142
end_property_list 
<component> 2152 
n_bounds 3
bounds -1485 -10 9 
property_list 
material 4
region 2143
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2143
end_property_list 
<component> 2153 
n_bounds 7
bounds 446 202 9 1486 -1050 -461 -10 
property_list 
material 2
region 2144
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2144
end_property_list 
<component> 2154 
n_bounds 4
bounds -1486 -10 9 1487 
property_list 
material 3
region 2145
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2145
end_property_list 
<component> 2155 
n_bounds 3
bounds -1487 -10 9 
property_list 
material 4
region 2146
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2146
end_property_list 
<component> 2156 
n_bounds 7
bounds 446 1050 9 1488 -1053 -461 -10 
property_list 
material 2
region 2147
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2147
end_property_list 
<component> 2157 
n_bounds 4
bounds -1488 -10 9 1489 
property_list 
material 3
region 2148
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2148
end_property_list 
<component> 2158 
n_bounds 3
bounds -1489 -10 9 
property_list 
material 4
region 2149
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2149
end_property_list 
<component> 2159 
n_bounds 7
bounds 446 1053 9 1490 -1056 -461 -10 
property_list 
material 2
region 2150
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2150
end_property_list 
<component> 2160 
n_bounds 4
bounds -1490 -10 9 1491 
property_list 
material 3
region 2151
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2151
end_property_list 
<component> 2161 
n_bounds 3
bounds -1491 -10 9 
property_list 
material 4
region 2152
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2152
end_property_list 
<component> 2162 
n_bounds 7
bounds 446 1056 9 1492 -1059 -461 -10 
property_list 
material 2
region 2153
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2153
end_property_list 
<component> 2163 
n_bounds 4
bounds -1492 -10 9 1493 
property_list 
material 3
region 2154
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2154
end_property_list 
<component> 2164 
n_bounds 3
bounds -1493 -10 9 
property_list 
material 4
region 2155
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2155
end_property_list 
<component> 2165 
n_bounds 7
bounds 446 1059 9 1494 -1062 -461 -10 
property_list 
material 2
region 2156
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2156
end_property_list 
<component> 2166 
n_bounds 4
bounds -1494 -10 9 1495 
property_list 
material 3
region 2157
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2157
end_property_list 
<component> 2167 
n_bounds 3
bounds -1495 -10 9 
property_list 
material 4
region 2158
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2158
end_property_list 
<component> 2168 
n_bounds 7
bounds 446 1062 9 1496 -1065 -461 -10 
property_list 
material 2
region 2159
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2159
end_property_list 
<component> 2169 
n_bounds 4
bounds -1496 -10 9 1497 
property_list 
material 3
region 2160
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2160
end_property_list 
<component> 2170 
n_bounds 3
bounds -1497 -10 9 
property_list 
material 4
region 2161
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2161
end_property_list 
<component> 2171 
n_bounds 7
bounds 446 1065 9 1498 -1068 -461 -10 
property_list 
material 2
region 2162
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2162
end_property_list 
<component> 2172 
n_bounds 4
bounds -1498 -10 9 1499 
property_list 
material 3
region 2163
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2163
end_property_list 
<component> 2173 
n_bounds 3
bounds -1499 -10 9 
property_list 
material 4
region 2164
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2164
end_property_list 
<component> 2174 
n_bounds 7
bounds 446 1068 9 1500 -17 -461 -10 
property_list 
material 2
region 2165
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2165
end_property_list 
<component> 2175 
n_bounds 4
bounds -1500 -10 9 1501 
property_list 
material 3
region 2166
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2166
end_property_list 
<component> 2176 
n_bounds 3
bounds -1501 -10 9 
property_list 
material 4
region 2167
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2167
end_property_list 
<component> 2177 
n_bounds 7
bounds 446 17 9 1502 -1073 -461 -10 
property_list 
material 2
region 2168
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2168
end_property_list 
<component> 2178 
n_bounds 4
bounds -1502 -10 9 1503 
property_list 
material 3
region 2169
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2169
end_property_list 
<component> 2179 
n_bounds 3
bounds -1503 -10 9 
property_list 
material 4
region 2170
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2170
end_property_list 
<component> 2180 
n_bounds 7
bounds 446 1073 9 1504 -1076 -461 -10 
property_list 
material 2
region 2171
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2171
end_property_list 
<component> 2181 
n_bounds 4
bounds -1504 -10 9 1505 
property_list 
material 3
region 2172
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2172
end_property_list 
<component> 2182 
n_bounds 3
bounds -1505 -10 9 
property_list 
material 4
region 2173
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2173
end_property_list 
<component> 2183 
n_bounds 7
bounds 446 1076 9 1506 -1079 -461 -10 
property_list 
material 2
region 2174
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2174
end_property_list 
<component> 2184 
n_bounds 4
bounds -1506 -10 9 1507 
property_list 
material 3
region 2175
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2175
end_property_list 
<component> 2185 
n_bounds 3
bounds -1507 -10 9 
property_list 
material 4
region 2176
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2176
end_property_list 
<component> 2186 
n_bounds 7
bounds 446 1079 9 1508 -1082 -461 -10 
property_list 
material 2
region 2177
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2177
end_property_list 
<component> 2187 
n_bounds 4
bounds -1508 -10 9 1509 
property_list 
material 3
region 2178
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2178
end_property_list 
<component> 2188 
n_bounds 3
bounds -1509 -10 9 
property_list 
material 4
region 2179
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2179
end_property_list 
<component> 2189 
n_bounds 7
bounds 446 1082 9 1510 -19 -461 -10 
property_list 
material 2
region 2180
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2180
end_property_list 
<component> 2190 
n_bounds 4
bounds -1510 -10 9 1511 
property_list 
material 3
region 2181
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2181
end_property_list 
<component> 2191 
n_bounds 3
bounds -1511 -10 9 
property_list 
material 4
region 2182
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2182
end_property_list 
<component> 2192 
n_bounds 7
bounds 461 202 9 1512 -1050 -478 -10 
property_list 
material 2
region 2183
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2183
end_property_list 
<component> 2193 
n_bounds 4
bounds -1512 -10 9 1513 
property_list 
material 3
region 2184
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2184
end_property_list 
<component> 2194 
n_bounds 3
bounds -1513 -10 9 
property_list 
material 4
region 2185
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2185
end_property_list 
<component> 2195 
n_bounds 7
bounds 461 1050 9 1514 -1053 -478 -10 
property_list 
material 2
region 2186
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2186
end_property_list 
<component> 2196 
n_bounds 4
bounds -1514 -10 9 1515 
property_list 
material 3
region 2187
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2187
end_property_list 
<component> 2197 
n_bounds 3
bounds -1515 -10 9 
property_list 
material 4
region 2188
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2188
end_property_list 
<component> 2198 
n_bounds 7
bounds 461 1053 9 1516 -1056 -478 -10 
property_list 
material 2
region 2189
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2189
end_property_list 
<component> 2199 
n_bounds 4
bounds -1516 -10 9 1517 
property_list 
material 3
region 2190
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2190
end_property_list 
<component> 2200 
n_bounds 3
bounds -1517 -10 9 
property_list 
material 4
region 2191
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2191
end_property_list 
<component> 2201 
n_bounds 7
bounds 461 1056 9 1518 -1059 -478 -10 
property_list 
material 2
region 2192
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2192
end_property_list 
<component> 2202 
n_bounds 4
bounds -1518 -10 9 1519 
property_list 
material 3
region 2193
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2193
end_property_list 
<component> 2203 
n_bounds 3
bounds -1519 -10 9 
property_list 
material 4
region 2194
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2194
end_property_list 
<component> 2204 
n_bounds 7
bounds 461 1059 9 1520 -1062 -478 -10 
property_list 
material 2
region 2195
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2195
end_property_list 
<component> 2205 
n_bounds 4
bounds -1520 -10 9 1521 
property_list 
material 3
region 2196
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2196
end_property_list 
<component> 2206 
n_bounds 3
bounds -1521 -10 9 
property_list 
material 4
region 2197
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2197
end_property_list 
<component> 2207 
n_bounds 7
bounds 461 1062 9 1522 -1065 -478 -10 
property_list 
material 2
region 2198
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2198
end_property_list 
<component> 2208 
n_bounds 4
bounds -1522 -10 9 1523 
property_list 
material 3
region 2199
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2199
end_property_list 
<component> 2209 
n_bounds 3
bounds -1523 -10 9 
property_list 
material 4
region 2200
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2200
end_property_list 
<component> 2210 
n_bounds 7
bounds 461 1065 9 1524 -1068 -478 -10 
property_list 
material 2
region 2201
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2201
end_property_list 
<component> 2211 
n_bounds 4
bounds -1524 -10 9 1525 
property_list 
material 3
region 2202
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2202
end_property_list 
<component> 2212 
n_bounds 3
bounds -1525 -10 9 
property_list 
material 4
region 2203
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2203
end_property_list 
<component> 2213 
n_bounds 7
bounds 461 1068 9 1526 -17 -478 -10 
property_list 
material 2
region 2204
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2204
end_property_list 
<component> 2214 
n_bounds 4
bounds -1526 -10 9 1527 
property_list 
material 3
region 2205
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2205
end_property_list 
<component> 2215 
n_bounds 3
bounds -1527 -10 9 
property_list 
material 4
region 2206
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2206
end_property_list 
<component> 2216 
n_bounds 7
bounds 461 17 9 1528 -1073 -478 -10 
property_list 
material 2
region 2207
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2207
end_property_list 
<component> 2217 
n_bounds 4
bounds -1528 -10 9 1529 
property_list 
material 3
region 2208
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2208
end_property_list 
<component> 2218 
n_bounds 3
bounds -1529 -10 9 
property_list 
material 4
region 2209
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2209
end_property_list 
<component> 2219 
n_bounds 7
bounds 461 1073 9 1530 -1076 -478 -10 
property_list 
material 2
region 2210
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2210
end_property_list 
<component> 2220 
n_bounds 4
bounds -1530 -10 9 1531 
property_list 
material 3
region 2211
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2211
end_property_list 
<component> 2221 
n_bounds 3
bounds -1531 -10 9 
property_list 
material 4
region 2212
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2212
end_property_list 
<component> 2222 
n_bounds 7
bounds 461 1076 9 1532 -1079 -478 -10 
property_list 
material 2
region 2213
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2213
end_property_list 
<component> 2223 
n_bounds 4
bounds -1532 -10 9 1533 
property_list 
material 3
region 2214
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2214
end_property_list 
<component> 2224 
n_bounds 3
bounds -1533 -10 9 
property_list 
material 4
region 2215
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2215
end_property_list 
<component> 2225 
n_bounds 7
bounds 461 1079 9 1534 -1082 -478 -10 
property_list 
material 2
region 2216
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2216
end_property_list 
<component> 2226 
n_bounds 4
bounds -1534 -10 9 1535 
property_list 
material 3
region 2217
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2217
end_property_list 
<component> 2227 
n_bounds 3
bounds -1535 -10 9 
property_list 
material 4
region 2218
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2218
end_property_list 
<component> 2228 
n_bounds 7
bounds 461 1082 9 1536 -19 -478 -10 
property_list 
material 2
region 2219
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2219
end_property_list 
<component> 2229 
n_bounds 4
bounds -1536 -10 9 1537 
property_list 
material 3
region 2220
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2220
end_property_list 
<component> 2230 
n_bounds 3
bounds -1537 -10 9 
property_list 
material 4
region 2221
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2221
end_property_list 
<component> 2231 
n_bounds 7
bounds 478 202 9 1538 -1050 -491 -10 
property_list 
material 2
region 2222
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2222
end_property_list 
<component> 2232 
n_bounds 4
bounds -1538 -10 9 1539 
property_list 
material 3
region 2223
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2223
end_property_list 
<component> 2233 
n_bounds 3
bounds -1539 -10 9 
property_list 
material 4
region 2224
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2224
end_property_list 
<component> 2234 
n_bounds 7
bounds 478 1050 9 1540 -1053 -491 -10 
property_list 
material 2
region 2225
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2225
end_property_list 
<component> 2235 
n_bounds 4
bounds -1540 -10 9 1541 
property_list 
material 3
region 2226
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2226
end_property_list 
<component> 2236 
n_bounds 3
bounds -1541 -10 9 
property_list 
material 4
region 2227
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2227
end_property_list 
<component> 2237 
n_bounds 7
bounds 478 1053 9 1542 -1056 -491 -10 
property_list 
material 2
region 2228
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2228
end_property_list 
<component> 2238 
n_bounds 4
bounds -1542 -10 9 1543 
property_list 
material 3
region 2229
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2229
end_property_list 
<component> 2239 
n_bounds 3
bounds -1543 -10 9 
property_list 
material 4
region 2230
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2230
end_property_list 
<component> 2240 
n_bounds 7
bounds 478 1056 9 1544 -1059 -491 -10 
property_list 
material 2
region 2231
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2231
end_property_list 
<component> 2241 
n_bounds 4
bounds -1544 -10 9 1545 
property_list 
material 3
region 2232
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2232
end_property_list 
<component> 2242 
n_bounds 3
bounds -1545 -10 9 
property_list 
material 4
region 2233
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2233
end_property_list 
<component> 2243 
n_bounds 7
bounds 478 1059 9 1546 -1062 -491 -10 
property_list 
material 2
region 2234
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2234
end_property_list 
<component> 2244 
n_bounds 4
bounds -1546 -10 9 1547 
property_list 
material 3
region 2235
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2235
end_property_list 
<component> 2245 
n_bounds 3
bounds -1547 -10 9 
property_list 
material 4
region 2236
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2236
end_property_list 
<component> 2246 
n_bounds 7
bounds 478 1062 9 1548 -1065 -491 -10 
property_list 
material 2
region 2237
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2237
end_property_list 
<component> 2247 
n_bounds 4
bounds -1548 -10 9 1549 
property_list 
material 3
region 2238
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2238
end_property_list 
<component> 2248 
n_bounds 3
bounds -1549 -10 9 
property_list 
material 4
region 2239
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2239
end_property_list 
<component> 2249 
n_bounds 7
bounds 478 1065 9 1550 -1068 -491 -10 
property_list 
material 2
region 2240
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2240
end_property_list 
<component> 2250 
n_bounds 4
bounds -1550 -10 9 1551 
property_list 
material 3
region 2241
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2241
end_property_list 
<component> 2251 
n_bounds 3
bounds -1551 -10 9 
property_list 
material 4
region 2242
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2242
end_property_list 
<component> 2252 
n_bounds 7
bounds 478 1068 9 1552 -17 -491 -10 
property_list 
material 2
region 2243
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2243
end_property_list 
<component> 2253 
n_bounds 4
bounds -1552 -10 9 1553 
property_list 
material 3
region 2244
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2244
end_property_list 
<component> 2254 
n_bounds 3
bounds -1553 -10 9 
property_list 
material 4
region 2245
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2245
end_property_list 
<component> 2255 
n_bounds 7
bounds 478 17 9 1554 -1073 -491 -10 
property_list 
material 2
region 2246
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2246
end_property_list 
<component> 2256 
n_bounds 4
bounds -1554 -10 9 1555 
property_list 
material 3
region 2247
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2247
end_property_list 
<component> 2257 
n_bounds 3
bounds -1555 -10 9 
property_list 
material 4
region 2248
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2248
end_property_list 
<component> 2258 
n_bounds 7
bounds 478 1073 9 1556 -1076 -491 -10 
property_list 
material 2
region 2249
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2249
end_property_list 
<component> 2259 
n_bounds 4
bounds -1556 -10 9 1557 
property_list 
material 3
region 2250
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2250
end_property_list 
<component> 2260 
n_bounds 3
bounds -1557 -10 9 
property_list 
material 4
region 2251
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2251
end_property_list 
<component> 2261 
n_bounds 7
bounds 478 1076 9 1558 -1079 -491 -10 
property_list 
material 2
region 2252
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2252
end_property_list 
<component> 2262 
n_bounds 4
bounds -1558 -10 9 1559 
property_list 
material 3
region 2253
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2253
end_property_list 
<component> 2263 
n_bounds 3
bounds -1559 -10 9 
property_list 
material 4
region 2254
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2254
end_property_list 
<component> 2264 
n_bounds 7
bounds 478 1079 9 1560 -1082 -491 -10 
property_list 
material 2
region 2255
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2255
end_property_list 
<component> 2265 
n_bounds 4
bounds -1560 -10 9 1561 
property_list 
material 3
region 2256
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2256
end_property_list 
<component> 2266 
n_bounds 3
bounds -1561 -10 9 
property_list 
material 4
region 2257
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2257
end_property_list 
<component> 2267 
n_bounds 7
bounds 478 1082 9 1562 -19 -491 -10 
property_list 
material 2
region 2258
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2258
end_property_list 
<component> 2268 
n_bounds 4
bounds -1562 -10 9 1563 
property_list 
material 3
region 2259
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2259
end_property_list 
<component> 2269 
n_bounds 3
bounds -1563 -10 9 
property_list 
material 4
region 2260
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2260
end_property_list 
<component> 2270 
n_bounds 7
bounds 491 202 9 1564 -1050 -508 -10 
property_list 
material 2
region 2261
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2261
end_property_list 
<component> 2271 
n_bounds 4
bounds -1564 -10 9 1565 
property_list 
material 3
region 2262
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2262
end_property_list 
<component> 2272 
n_bounds 3
bounds -1565 -10 9 
property_list 
material 4
region 2263
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2263
end_property_list 
<component> 2273 
n_bounds 7
bounds 491 1050 9 1566 -1053 -508 -10 
property_list 
material 2
region 2264
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2264
end_property_list 
<component> 2274 
n_bounds 4
bounds -1566 -10 9 1567 
property_list 
material 3
region 2265
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2265
end_property_list 
<component> 2275 
n_bounds 3
bounds -1567 -10 9 
property_list 
material 4
region 2266
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2266
end_property_list 
<component> 2276 
n_bounds 7
bounds 491 1053 9 1568 -1056 -508 -10 
property_list 
material 2
region 2267
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2267
end_property_list 
<component> 2277 
n_bounds 4
bounds -1568 -10 9 1569 
property_list 
material 3
region 2268
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2268
end_property_list 
<component> 2278 
n_bounds 3
bounds -1569 -10 9 
property_list 
material 4
region 2269
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2269
end_property_list 
<component> 2279 
n_bounds 7
bounds 491 1056 9 1570 -1059 -508 -10 
property_list 
material 2
region 2270
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2270
end_property_list 
<component> 2280 
n_bounds 4
bounds -1570 -10 9 1571 
property_list 
material 3
region 2271
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2271
end_property_list 
<component> 2281 
n_bounds 3
bounds -1571 -10 9 
property_list 
material 4
region 2272
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2272
end_property_list 
<component> 2282 
n_bounds 7
bounds 491 1059 9 1572 -1062 -508 -10 
property_list 
material 2
region 2273
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2273
end_property_list 
<component> 2283 
n_bounds 4
bounds -1572 -10 9 1573 
property_list 
material 3
region 2274
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2274
end_property_list 
<component> 2284 
n_bounds 3
bounds -1573 -10 9 
property_list 
material 4
region 2275
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2275
end_property_list 
<component> 2285 
n_bounds 7
bounds 491 1062 9 1574 -1065 -508 -10 
property_list 
material 2
region 2276
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2276
end_property_list 
<component> 2286 
n_bounds 4
bounds -1574 -10 9 1575 
property_list 
material 3
region 2277
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2277
end_property_list 
<component> 2287 
n_bounds 3
bounds -1575 -10 9 
property_list 
material 4
region 2278
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2278
end_property_list 
<component> 2288 
n_bounds 7
bounds 491 1065 9 1576 -1068 -508 -10 
property_list 
material 2
region 2279
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2279
end_property_list 
<component> 2289 
n_bounds 4
bounds -1576 -10 9 1577 
property_list 
material 3
region 2280
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2280
end_property_list 
<component> 2290 
n_bounds 3
bounds -1577 -10 9 
property_list 
material 4
region 2281
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2281
end_property_list 
<component> 2291 
n_bounds 7
bounds 491 1068 9 1578 -17 -508 -10 
property_list 
material 2
region 2282
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2282
end_property_list 
<component> 2292 
n_bounds 4
bounds -1578 -10 9 1579 
property_list 
material 3
region 2283
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2283
end_property_list 
<component> 2293 
n_bounds 3
bounds -1579 -10 9 
property_list 
material 4
region 2284
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2284
end_property_list 
<component> 2294 
n_bounds 7
bounds 491 17 9 1580 -1073 -508 -10 
property_list 
material 2
region 2285
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2285
end_property_list 
<component> 2295 
n_bounds 4
bounds -1580 -10 9 1581 
property_list 
material 3
region 2286
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2286
end_property_list 
<component> 2296 
n_bounds 3
bounds -1581 -10 9 
property_list 
material 4
region 2287
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2287
end_property_list 
<component> 2297 
n_bounds 7
bounds 491 1073 9 1582 -1076 -508 -10 
property_list 
material 2
region 2288
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2288
end_property_list 
<component> 2298 
n_bounds 4
bounds -1582 -10 9 1583 
property_list 
material 3
region 2289
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2289
end_property_list 
<component> 2299 
n_bounds 3
bounds -1583 -10 9 
property_list 
material 4
region 2290
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2290
end_property_list 
<component> 2300 
n_bounds 7
bounds 491 1076 9 1584 -1079 -508 -10 
property_list 
material 2
region 2291
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2291
end_property_list 
<component> 2301 
n_bounds 4
bounds -1584 -10 9 1585 
property_list 
material 3
region 2292
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2292
end_property_list 
<component> 2302 
n_bounds 3
bounds -1585 -10 9 
property_list 
material 4
region 2293
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2293
end_property_list 
<component> 2303 
n_bounds 7
bounds 491 1079 9 1586 -1082 -508 -10 
property_list 
material 2
region 2294
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2294
end_property_list 
<component> 2304 
n_bounds 4
bounds -1586 -10 9 1587 
property_list 
material 3
region 2295
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2295
end_property_list 
<component> 2305 
n_bounds 3
bounds -1587 -10 9 
property_list 
material 4
region 2296
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2296
end_property_list 
<component> 2306 
n_bounds 7
bounds 491 1082 9 1588 -19 -508 -10 
property_list 
material 2
region 2297
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2297
end_property_list 
<component> 2307 
n_bounds 4
bounds -1588 -10 9 1589 
property_list 
material 3
region 2298
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2298
end_property_list 
<component> 2308 
n_bounds 3
bounds -1589 -10 9 
property_list 
material 4
region 2299
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2299
end_property_list 
<component> 2309 
n_bounds 7
bounds 508 202 9 1590 -1050 -523 -10 
property_list 
material 2
region 2300
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2300
end_property_list 
<component> 2310 
n_bounds 4
bounds -1590 -10 9 1591 
property_list 
material 3
region 2301
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2301
end_property_list 
<component> 2311 
n_bounds 3
bounds -1591 -10 9 
property_list 
material 4
region 2302
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2302
end_property_list 
<component> 2312 
n_bounds 7
bounds 508 1050 9 1592 -1053 -523 -10 
property_list 
material 2
region 2303
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2303
end_property_list 
<component> 2313 
n_bounds 4
bounds -1592 -10 9 1593 
property_list 
material 3
region 2304
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2304
end_property_list 
<component> 2314 
n_bounds 3
bounds -1593 -10 9 
property_list 
material 4
region 2305
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2305
end_property_list 
<component> 2315 
n_bounds 7
bounds 508 1053 9 1594 -1056 -523 -10 
property_list 
material 2
region 2306
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2306
end_property_list 
<component> 2316 
n_bounds 4
bounds -1594 -10 9 1595 
property_list 
material 3
region 2307
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2307
end_property_list 
<component> 2317 
n_bounds 3
bounds -1595 -10 9 
property_list 
material 4
region 2308
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2308
end_property_list 
<component> 2318 
n_bounds 7
bounds 508 1056 9 1596 -1059 -523 -10 
property_list 
material 2
region 2309
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2309
end_property_list 
<component> 2319 
n_bounds 4
bounds -1596 -10 9 1597 
property_list 
material 3
region 2310
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2310
end_property_list 
<component> 2320 
n_bounds 3
bounds -1597 -10 9 
property_list 
material 4
region 2311
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2311
end_property_list 
<component> 2321 
n_bounds 7
bounds 508 1059 9 1598 -1062 -523 -10 
property_list 
material 2
region 2312
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2312
end_property_list 
<component> 2322 
n_bounds 4
bounds -1598 -10 9 1599 
property_list 
material 3
region 2313
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2313
end_property_list 
<component> 2323 
n_bounds 3
bounds -1599 -10 9 
property_list 
material 4
region 2314
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2314
end_property_list 
<component> 2324 
n_bounds 7
bounds 508 1062 9 1600 -1065 -523 -10 
property_list 
material 2
region 2315
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2315
end_property_list 
<component> 2325 
n_bounds 4
bounds -1600 -10 9 1601 
property_list 
material 3
region 2316
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2316
end_property_list 
<component> 2326 
n_bounds 3
bounds -1601 -10 9 
property_list 
material 4
region 2317
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2317
end_property_list 
<component> 2327 
n_bounds 7
bounds 508 1065 9 1602 -1068 -523 -10 
property_list 
material 2
region 2318
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2318
end_property_list 
<component> 2328 
n_bounds 4
bounds -1602 -10 9 1603 
property_list 
material 3
region 2319
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2319
end_property_list 
<component> 2329 
n_bounds 3
bounds -1603 -10 9 
property_list 
material 4
region 2320
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2320
end_property_list 
<component> 2330 
n_bounds 7
bounds 508 1068 9 1604 -17 -523 -10 
property_list 
material 2
region 2321
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2321
end_property_list 
<component> 2331 
n_bounds 4
bounds -1604 -10 9 1605 
property_list 
material 3
region 2322
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2322
end_property_list 
<component> 2332 
n_bounds 3
bounds -1605 -10 9 
property_list 
material 4
region 2323
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2323
end_property_list 
<component> 2333 
n_bounds 7
bounds 508 17 9 1606 -1073 -523 -10 
property_list 
material 2
region 2324
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2324
end_property_list 
<component> 2334 
n_bounds 4
bounds -1606 -10 9 1607 
property_list 
material 3
region 2325
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2325
end_property_list 
<component> 2335 
n_bounds 3
bounds -1607 -10 9 
property_list 
material 4
region 2326
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2326
end_property_list 
<component> 2336 
n_bounds 7
bounds 508 1073 9 1608 -1076 -523 -10 
property_list 
material 2
region 2327
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2327
end_property_list 
<component> 2337 
n_bounds 4
bounds -1608 -10 9 1609 
property_list 
material 3
region 2328
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2328
end_property_list 
<component> 2338 
n_bounds 3
bounds -1609 -10 9 
property_list 
material 4
region 2329
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2329
end_property_list 
<component> 2339 
n_bounds 7
bounds 508 1076 9 1610 -1079 -523 -10 
property_list 
material 2
region 2330
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2330
end_property_list 
<component> 2340 
n_bounds 4
bounds -1610 -10 9 1611 
property_list 
material 3
region 2331
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2331
end_property_list 
<component> 2341 
n_bounds 3
bounds -1611 -10 9 
property_list 
material 4
region 2332
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2332
end_property_list 
<component> 2342 
n_bounds 7
bounds 508 1079 9 1612 -1082 -523 -10 
property_list 
material 2
region 2333
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2333
end_property_list 
<component> 2343 
n_bounds 4
bounds -1612 -10 9 1613 
property_list 
material 3
region 2334
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2334
end_property_list 
<component> 2344 
n_bounds 3
bounds -1613 -10 9 
property_list 
material 4
region 2335
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2335
end_property_list 
<component> 2345 
n_bounds 7
bounds 508 1082 9 1614 -19 -523 -10 
property_list 
material 2
region 2336
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2336
end_property_list 
<component> 2346 
n_bounds 4
bounds -1614 -10 9 1615 
property_list 
material 3
region 2337
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2337
end_property_list 
<component> 2347 
n_bounds 3
bounds -1615 -10 9 
property_list 
material 4
region 2338
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2338
end_property_list 
<component> 2348 
n_bounds 7
bounds 523 202 9 1616 -1050 -540 -10 
property_list 
material 2
region 2339
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2339
end_property_list 
<component> 2349 
n_bounds 4
bounds -1616 -10 9 1617 
property_list 
material 3
region 2340
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2340
end_property_list 
<component> 2350 
n_bounds 3
bounds -1617 -10 9 
property_list 
material 4
region 2341
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2341
end_property_list 
<component> 2351 
n_bounds 7
bounds 523 1050 9 1618 -1053 -540 -10 
property_list 
material 2
region 2342
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2342
end_property_list 
<component> 2352 
n_bounds 4
bounds -1618 -10 9 1619 
property_list 
material 3
region 2343
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2343
end_property_list 
<component> 2353 
n_bounds 3
bounds -1619 -10 9 
property_list 
material 4
region 2344
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2344
end_property_list 
<component> 2354 
n_bounds 7
bounds 523 1053 9 1620 -1056 -540 -10 
property_list 
material 2
region 2345
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2345
end_property_list 
<component> 2355 
n_bounds 4
bounds -1620 -10 9 1621 
property_list 
material 3
region 2346
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2346
end_property_list 
<component> 2356 
n_bounds 3
bounds -1621 -10 9 
property_list 
material 4
region 2347
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2347
end_property_list 
<component> 2357 
n_bounds 7
bounds 523 1056 9 1622 -1059 -540 -10 
property_list 
material 2
region 2348
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2348
end_property_list 
<component> 2358 
n_bounds 4
bounds -1622 -10 9 1623 
property_list 
material 3
region 2349
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2349
end_property_list 
<component> 2359 
n_bounds 3
bounds -1623 -10 9 
property_list 
material 4
region 2350
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2350
end_property_list 
<component> 2360 
n_bounds 7
bounds 523 1059 9 1624 -1062 -540 -10 
property_list 
material 2
region 2351
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2351
end_property_list 
<component> 2361 
n_bounds 4
bounds -1624 -10 9 1625 
property_list 
material 3
region 2352
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2352
end_property_list 
<component> 2362 
n_bounds 3
bounds -1625 -10 9 
property_list 
material 4
region 2353
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2353
end_property_list 
<component> 2363 
n_bounds 7
bounds 523 1062 9 1626 -1065 -540 -10 
property_list 
material 2
region 2354
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2354
end_property_list 
<component> 2364 
n_bounds 4
bounds -1626 -10 9 1627 
property_list 
material 3
region 2355
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2355
end_property_list 
<component> 2365 
n_bounds 3
bounds -1627 -10 9 
property_list 
material 4
region 2356
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2356
end_property_list 
<component> 2366 
n_bounds 7
bounds 523 1065 9 1628 -1068 -540 -10 
property_list 
material 2
region 2357
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2357
end_property_list 
<component> 2367 
n_bounds 4
bounds -1628 -10 9 1629 
property_list 
material 3
region 2358
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2358
end_property_list 
<component> 2368 
n_bounds 3
bounds -1629 -10 9 
property_list 
material 4
region 2359
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2359
end_property_list 
<component> 2369 
n_bounds 7
bounds 523 1068 9 1630 -17 -540 -10 
property_list 
material 2
region 2360
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2360
end_property_list 
<component> 2370 
n_bounds 4
bounds -1630 -10 9 1631 
property_list 
material 3
region 2361
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2361
end_property_list 
<component> 2371 
n_bounds 3
bounds -1631 -10 9 
property_list 
material 4
region 2362
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2362
end_property_list 
<component> 2372 
n_bounds 7
bounds 523 17 9 1632 -1073 -540 -10 
property_list 
material 2
region 2363
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2363
end_property_list 
<component> 2373 
n_bounds 4
bounds -1632 -10 9 1633 
property_list 
material 3
region 2364
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2364
end_property_list 
<component> 2374 
n_bounds 3
bounds -1633 -10 9 
property_list 
material 4
region 2365
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2365
end_property_list 
<component> 2375 
n_bounds 7
bounds 523 1073 9 1634 -1076 -540 -10 
property_list 
material 2
region 2366
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2366
end_property_list 
<component> 2376 
n_bounds 4
bounds -1634 -10 9 1635 
property_list 
material 3
region 2367
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2367
end_property_list 
<component> 2377 
n_bounds 3
bounds -1635 -10 9 
property_list 
material 4
region 2368
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2368
end_property_list 
<component> 2378 
n_bounds 7
bounds 523 1076 9 1636 -1079 -540 -10 
property_list 
material 2
region 2369
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2369
end_property_list 
<component> 2379 
n_bounds 4
bounds -1636 -10 9 1637 
property_list 
material 3
region 2370
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2370
end_property_list 
<component> 2380 
n_bounds 3
bounds -1637 -10 9 
property_list 
material 4
region 2371
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2371
end_property_list 
<component> 2381 
n_bounds 7
bounds 523 1079 9 1638 -1082 -540 -10 
property_list 
material 2
region 2372
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2372
end_property_list 
<component> 2382 
n_bounds 4
bounds -1638 -10 9 1639 
property_list 
material 3
region 2373
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2373
end_property_list 
<component> 2383 
n_bounds 3
bounds -1639 -10 9 
property_list 
material 4
region 2374
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2374
end_property_list 
<component> 2384 
n_bounds 7
bounds 523 1082 9 1640 -19 -540 -10 
property_list 
material 2
region 2375
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2375
end_property_list 
<component> 2385 
n_bounds 4
bounds -1640 -10 9 1641 
property_list 
material 3
region 2376
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2376
end_property_list 
<component> 2386 
n_bounds 3
bounds -1641 -10 9 
property_list 
material 4
region 2377
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2377
end_property_list 
<component> 2387 
n_bounds 7
bounds 540 202 9 1642 -1050 -553 -10 
property_list 
material 2
region 2378
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2378
end_property_list 
<component> 2388 
n_bounds 4
bounds -1642 -10 9 1643 
property_list 
material 3
region 2379
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2379
end_property_list 
<component> 2389 
n_bounds 3
bounds -1643 -10 9 
property_list 
material 4
region 2380
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2380
end_property_list 
<component> 2390 
n_bounds 7
bounds 540 1050 9 1644 -1053 -553 -10 
property_list 
material 2
region 2381
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2381
end_property_list 
<component> 2391 
n_bounds 4
bounds -1644 -10 9 1645 
property_list 
material 3
region 2382
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2382
end_property_list 
<component> 2392 
n_bounds 3
bounds -1645 -10 9 
property_list 
material 4
region 2383
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2383
end_property_list 
<component> 2393 
n_bounds 7
bounds 540 1053 9 1646 -1056 -553 -10 
property_list 
material 2
region 2384
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2384
end_property_list 
<component> 2394 
n_bounds 4
bounds -1646 -10 9 1647 
property_list 
material 3
region 2385
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2385
end_property_list 
<component> 2395 
n_bounds 3
bounds -1647 -10 9 
property_list 
material 4
region 2386
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2386
end_property_list 
<component> 2396 
n_bounds 7
bounds 540 1056 9 1648 -1059 -553 -10 
property_list 
material 2
region 2387
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2387
end_property_list 
<component> 2397 
n_bounds 4
bounds -1648 -10 9 1649 
property_list 
material 3
region 2388
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2388
end_property_list 
<component> 2398 
n_bounds 3
bounds -1649 -10 9 
property_list 
material 4
region 2389
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2389
end_property_list 
<component> 2399 
n_bounds 7
bounds 540 1059 9 1650 -1062 -553 -10 
property_list 
material 2
region 2390
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2390
end_property_list 
<component> 2400 
n_bounds 4
bounds -1650 -10 9 1651 
property_list 
material 3
region 2391
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2391
end_property_list 
<component> 2401 
n_bounds 3
bounds -1651 -10 9 
property_list 
material 4
region 2392
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2392
end_property_list 
<component> 2402 
n_bounds 7
bounds 540 1062 9 1652 -1065 -553 -10 
property_list 
material 2
region 2393
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2393
end_property_list 
<component> 2403 
n_bounds 4
bounds -1652 -10 9 1653 
property_list 
material 3
region 2394
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2394
end_property_list 
<component> 2404 
n_bounds 3
bounds -1653 -10 9 
property_list 
material 4
region 2395
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2395
end_property_list 
<component> 2405 
n_bounds 7
bounds 540 1065 9 1654 -1068 -553 -10 
property_list 
material 2
region 2396
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2396
end_property_list 
<component> 2406 
n_bounds 4
bounds -1654 -10 9 1655 
property_list 
material 3
region 2397
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2397
end_property_list 
<component> 2407 
n_bounds 3
bounds -1655 -10 9 
property_list 
material 4
region 2398
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2398
end_property_list 
<component> 2408 
n_bounds 7
bounds 540 1068 9 1656 -17 -553 -10 
property_list 
material 2
region 2399
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2399
end_property_list 
<component> 2409 
n_bounds 4
bounds -1656 -10 9 1657 
property_list 
material 3
region 2400
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2400
end_property_list 
<component> 2410 
n_bounds 3
bounds -1657 -10 9 
property_list 
material 4
region 2401
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2401
end_property_list 
<component> 2411 
n_bounds 7
bounds 540 17 9 1658 -1073 -553 -10 
property_list 
material 2
region 2402
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2402
end_property_list 
<component> 2412 
n_bounds 4
bounds -1658 -10 9 1659 
property_list 
material 3
region 2403
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2403
end_property_list 
<component> 2413 
n_bounds 3
bounds -1659 -10 9 
property_list 
material 4
region 2404
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2404
end_property_list 
<component> 2414 
n_bounds 7
bounds 540 1073 9 1660 -1076 -553 -10 
property_list 
material 2
region 2405
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2405
end_property_list 
<component> 2415 
n_bounds 4
bounds -1660 -10 9 1661 
property_list 
material 3
region 2406
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2406
end_property_list 
<component> 2416 
n_bounds 3
bounds -1661 -10 9 
property_list 
material 4
region 2407
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2407
end_property_list 
<component> 2417 
n_bounds 7
bounds 540 1076 9 1662 -1079 -553 -10 
property_list 
material 2
region 2408
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2408
end_property_list 
<component> 2418 
n_bounds 4
bounds -1662 -10 9 1663 
property_list 
material 3
region 2409
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2409
end_property_list 
<component> 2419 
n_bounds 3
bounds -1663 -10 9 
property_list 
material 4
region 2410
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2410
end_property_list 
<component> 2420 
n_bounds 7
bounds 540 1079 9 1664 -1082 -553 -10 
property_list 
material 2
region 2411
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2411
end_property_list 
<component> 2421 
n_bounds 4
bounds -1664 -10 9 1665 
property_list 
material 3
region 2412
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2412
end_property_list 
<component> 2422 
n_bounds 3
bounds -1665 -10 9 
property_list 
material 4
region 2413
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2413
end_property_list 
<component> 2423 
n_bounds 7
bounds 540 1082 9 1666 -19 -553 -10 
property_list 
material 2
region 2414
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2414
end_property_list 
<component> 2424 
n_bounds 4
bounds -1666 -10 9 1667 
property_list 
material 3
region 2415
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2415
end_property_list 
<component> 2425 
n_bounds 3
bounds -1667 -10 9 
property_list 
material 4
region 2416
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2416
end_property_list 
<component> 2426 
n_bounds 7
bounds 553 202 9 1668 -1050 -570 -10 
property_list 
material 2
region 2417
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2417
end_property_list 
<component> 2427 
n_bounds 4
bounds -1668 -10 9 1669 
property_list 
material 3
region 2418
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2418
end_property_list 
<component> 2428 
n_bounds 3
bounds -1669 -10 9 
property_list 
material 4
region 2419
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2419
end_property_list 
<component> 2429 
n_bounds 7
bounds 553 1050 9 1670 -1053 -570 -10 
property_list 
material 2
region 2420
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2420
end_property_list 
<component> 2430 
n_bounds 4
bounds -1670 -10 9 1671 
property_list 
material 3
region 2421
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2421
end_property_list 
<component> 2431 
n_bounds 3
bounds -1671 -10 9 
property_list 
material 4
region 2422
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2422
end_property_list 
<component> 2432 
n_bounds 7
bounds 553 1053 9 1672 -1056 -570 -10 
property_list 
material 2
region 2423
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2423
end_property_list 
<component> 2433 
n_bounds 4
bounds -1672 -10 9 1673 
property_list 
material 3
region 2424
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2424
end_property_list 
<component> 2434 
n_bounds 3
bounds -1673 -10 9 
property_list 
material 4
region 2425
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2425
end_property_list 
<component> 2435 
n_bounds 7
bounds 553 1056 9 1674 -1059 -570 -10 
property_list 
material 2
region 2426
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2426
end_property_list 
<component> 2436 
n_bounds 4
bounds -1674 -10 9 1675 
property_list 
material 3
region 2427
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2427
end_property_list 
<component> 2437 
n_bounds 3
bounds -1675 -10 9 
property_list 
material 4
region 2428
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2428
end_property_list 
<component> 2438 
n_bounds 7
bounds 553 1059 9 1676 -1062 -570 -10 
property_list 
material 2
region 2429
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2429
end_property_list 
<component> 2439 
n_bounds 4
bounds -1676 -10 9 1677 
property_list 
material 3
region 2430
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2430
end_property_list 
<component> 2440 
n_bounds 3
bounds -1677 -10 9 
property_list 
material 4
region 2431
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2431
end_property_list 
<component> 2441 
n_bounds 7
bounds 553 1062 9 1678 -1065 -570 -10 
property_list 
material 2
region 2432
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2432
end_property_list 
<component> 2442 
n_bounds 4
bounds -1678 -10 9 1679 
property_list 
material 3
region 2433
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2433
end_property_list 
<component> 2443 
n_bounds 3
bounds -1679 -10 9 
property_list 
material 4
region 2434
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2434
end_property_list 
<component> 2444 
n_bounds 7
bounds 553 1065 9 1680 -1068 -570 -10 
property_list 
material 2
region 2435
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2435
end_property_list 
<component> 2445 
n_bounds 4
bounds -1680 -10 9 1681 
property_list 
material 3
region 2436
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2436
end_property_list 
<component> 2446 
n_bounds 3
bounds -1681 -10 9 
property_list 
material 4
region 2437
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2437
end_property_list 
<component> 2447 
n_bounds 7
bounds 553 1068 9 1682 -17 -570 -10 
property_list 
material 2
region 2438
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2438
end_property_list 
<component> 2448 
n_bounds 4
bounds -1682 -10 9 1683 
property_list 
material 3
region 2439
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2439
end_property_list 
<component> 2449 
n_bounds 3
bounds -1683 -10 9 
property_list 
material 4
region 2440
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2440
end_property_list 
<component> 2450 
n_bounds 7
bounds 553 17 9 1684 -1073 -570 -10 
property_list 
material 2
region 2441
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2441
end_property_list 
<component> 2451 
n_bounds 4
bounds -1684 -10 9 1685 
property_list 
material 3
region 2442
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2442
end_property_list 
<component> 2452 
n_bounds 3
bounds -1685 -10 9 
property_list 
material 4
region 2443
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2443
end_property_list 
<component> 2453 
n_bounds 7
bounds 553 1073 9 1686 -1076 -570 -10 
property_list 
material 2
region 2444
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2444
end_property_list 
<component> 2454 
n_bounds 4
bounds -1686 -10 9 1687 
property_list 
material 3
region 2445
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2445
end_property_list 
<component> 2455 
n_bounds 3
bounds -1687 -10 9 
property_list 
material 4
region 2446
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2446
end_property_list 
<component> 2456 
n_bounds 7
bounds 553 1076 9 1688 -1079 -570 -10 
property_list 
material 2
region 2447
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2447
end_property_list 
<component> 2457 
n_bounds 4
bounds -1688 -10 9 1689 
property_list 
material 3
region 2448
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2448
end_property_list 
<component> 2458 
n_bounds 3
bounds -1689 -10 9 
property_list 
material 4
region 2449
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2449
end_property_list 
<component> 2459 
n_bounds 7
bounds 553 1079 9 1690 -1082 -570 -10 
property_list 
material 2
region 2450
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2450
end_property_list 
<component> 2460 
n_bounds 4
bounds -1690 -10 9 1691 
property_list 
material 3
region 2451
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2451
end_property_list 
<component> 2461 
n_bounds 3
bounds -1691 -10 9 
property_list 
material 4
region 2452
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2452
end_property_list 
<component> 2462 
n_bounds 7
bounds 553 1082 9 1692 -19 -570 -10 
property_list 
material 2
region 2453
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2453
end_property_list 
<component> 2463 
n_bounds 4
bounds -1692 -10 9 1693 
property_list 
material 3
region 2454
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2454
end_property_list 
<component> 2464 
n_bounds 3
bounds -1693 -10 9 
property_list 
material 4
region 2455
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2455
end_property_list 
<component> 2465 
n_bounds 7
bounds 570 202 9 1694 -1050 -20 -10 
property_list 
material 2
region 2456
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2456
end_property_list 
<component> 2466 
n_bounds 4
bounds -1694 -10 9 1695 
property_list 
material 3
region 2457
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2457
end_property_list 
<component> 2467 
n_bounds 3
bounds -1695 -10 9 
property_list 
material 4
region 2458
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2458
end_property_list 
<component> 2468 
n_bounds 7
bounds 570 1050 9 1696 -1053 -20 -10 
property_list 
material 2
region 2459
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2459
end_property_list 
<component> 2469 
n_bounds 4
bounds -1696 -10 9 1697 
property_list 
material 3
region 2460
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2460
end_property_list 
<component> 2470 
n_bounds 3
bounds -1697 -10 9 
property_list 
material 4
region 2461
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2461
end_property_list 
<component> 2471 
n_bounds 7
bounds 570 1053 9 1698 -1056 -20 -10 
property_list 
material 2
region 2462
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2462
end_property_list 
<component> 2472 
n_bounds 4
bounds -1698 -10 9 1699 
property_list 
material 3
region 2463
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2463
end_property_list 
<component> 2473 
n_bounds 3
bounds -1699 -10 9 
property_list 
material 4
region 2464
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2464
end_property_list 
<component> 2474 
n_bounds 7
bounds 570 1056 9 1700 -1059 -20 -10 
property_list 
material 2
region 2465
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2465
end_property_list 
<component> 2475 
n_bounds 4
bounds -1700 -10 9 1701 
property_list 
material 3
region 2466
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2466
end_property_list 
<component> 2476 
n_bounds 3
bounds -1701 -10 9 
property_list 
material 4
region 2467
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2467
end_property_list 
<component> 2477 
n_bounds 7
bounds 570 1059 9 1702 -1062 -20 -10 
property_list 
material 2
region 2468
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2468
end_property_list 
<component> 2478 
n_bounds 4
bounds -1702 -10 9 1703 
property_list 
material 3
region 2469
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2469
end_property_list 
<component> 2479 
n_bounds 3
bounds -1703 -10 9 
property_list 
material 4
region 2470
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2470
end_property_list 
<component> 2480 
n_bounds 7
bounds 570 1062 9 1704 -1065 -20 -10 
property_list 
material 2
region 2471
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2471
end_property_list 
<component> 2481 
n_bounds 4
bounds -1704 -10 9 1705 
property_list 
material 3
region 2472
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2472
end_property_list 
<component> 2482 
n_bounds 3
bounds -1705 -10 9 
property_list 
material 4
region 2473
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2473
end_property_list 
<component> 2483 
n_bounds 7
bounds 570 1065 9 1706 -1068 -20 -10 
property_list 
material 2
region 2474
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2474
end_property_list 
<component> 2484 
n_bounds 4
bounds -1706 -10 9 1707 
property_list 
material 3
region 2475
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2475
end_property_list 
<component> 2485 
n_bounds 3
bounds -1707 -10 9 
property_list 
material 4
region 2476
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2476
end_property_list 
<component> 2486 
n_bounds 7
bounds 570 1068 9 1708 -17 -20 -10 
property_list 
material 2
region 2477
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2477
end_property_list 
<component> 2487 
n_bounds 4
bounds -1708 -10 9 1709 
property_list 
material 3
region 2478
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2478
end_property_list 
<component> 2488 
n_bounds 3
bounds -1709 -10 9 
property_list 
material 4
region 2479
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2479
end_property_list 
<component> 2489 
n_bounds 7
bounds 570 17 9 1710 -1073 -20 -10 
property_list 
material 2
region 2480
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2480
end_property_list 
<component> 2490 
n_bounds 4
bounds -1710 -10 9 1711 
property_list 
material 3
region 2481
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2481
end_property_list 
<component> 2491 
n_bounds 3
bounds -1711 -10 9 
property_list 
material 4
region 2482
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2482
end_property_list 
<component> 2492 
n_bounds 7
bounds 570 1073 9 1712 -1076 -20 -10 
property_list 
material 2
region 2483
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2483
end_property_list 
<component> 2493 
n_bounds 4
bounds -1712 -10 9 1713 
property_list 
material 3
region 2484
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2484
end_property_list 
<component> 2494 
n_bounds 3
bounds -1713 -10 9 
property_list 
material 4
region 2485
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2485
end_property_list 
<component> 2495 
n_bounds 7
bounds 570 1076 9 1714 -1079 -20 -10 
property_list 
material 2
region 2486
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2486
end_property_list 
<component> 2496 
n_bounds 4
bounds -1714 -10 9 1715 
property_list 
material 3
region 2487
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2487
end_property_list 
<component> 2497 
n_bounds 3
bounds -1715 -10 9 
property_list 
material 4
region 2488
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2488
end_property_list 
<component> 2498 
n_bounds 7
bounds 570 1079 9 1716 -1082 -20 -10 
property_list 
material 2
region 2489
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2489
end_property_list 
<component> 2499 
n_bounds 4
bounds -1716 -10 9 1717 
property_list 
material 3
region 2490
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2490
end_property_list 
<component> 2500 
n_bounds 3
bounds -1717 -10 9 
property_list 
material 4
region 2491
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2491
end_property_list 
<component> 2501 
n_bounds 7
bounds 570 1082 9 1718 -19 -20 -10 
property_list 
material 2
region 2492
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2492
end_property_list 
<component> 2502 
n_bounds 4
bounds -1718 -10 9 1719 
property_list 
material 3
region 2493
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2493
end_property_list 
<component> 2503 
n_bounds 3
bounds -1719 -10 9 
property_list 
material 4
region 2494
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2494
end_property_list 
<component> 2504 
n_bounds 7
bounds 20 202 9 1720 -1050 -599 -10 
property_list 
material 2
region 2495
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2495
end_property_list 
<component> 2505 
n_bounds 4
bounds -1720 -10 9 1721 
property_list 
material 3
region 2496
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2496
end_property_list 
<component> 2506 
n_bounds 3
bounds -1721 -10 9 
property_list 
material 4
region 2497
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2497
end_property_list 
<component> 2507 
n_bounds 7
bounds 20 1050 9 1722 -1053 -599 -10 
property_list 
material 2
region 2498
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2498
end_property_list 
<component> 2508 
n_bounds 4
bounds -1722 -10 9 1723 
property_list 
material 3
region 2499
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2499
end_property_list 
<component> 2509 
n_bounds 3
bounds -1723 -10 9 
property_list 
material 4
region 2500
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2500
end_property_list 
<component> 2510 
n_bounds 7
bounds 20 1053 9 1724 -1056 -599 -10 
property_list 
material 2
region 2501
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2501
end_property_list 
<component> 2511 
n_bounds 4
bounds -1724 -10 9 1725 
property_list 
material 3
region 2502
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2502
end_property_list 
<component> 2512 
n_bounds 3
bounds -1725 -10 9 
property_list 
material 4
region 2503
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2503
end_property_list 
<component> 2513 
n_bounds 7
bounds 20 1056 9 1726 -1059 -599 -10 
property_list 
material 2
region 2504
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2504
end_property_list 
<component> 2514 
n_bounds 4
bounds -1726 -10 9 1727 
property_list 
material 3
region 2505
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2505
end_property_list 
<component> 2515 
n_bounds 3
bounds -1727 -10 9 
property_list 
material 4
region 2506
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2506
end_property_list 
<component> 2516 
n_bounds 7
bounds 20 1059 9 1728 -1062 -599 -10 
property_list 
material 2
region 2507
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2507
end_property_list 
<component> 2517 
n_bounds 4
bounds -1728 -10 9 1729 
property_list 
material 3
region 2508
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2508
end_property_list 
<component> 2518 
n_bounds 3
bounds -1729 -10 9 
property_list 
material 4
region 2509
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2509
end_property_list 
<component> 2519 
n_bounds 7
bounds 20 1062 9 1730 -1065 -599 -10 
property_list 
material 2
region 2510
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2510
end_property_list 
<component> 2520 
n_bounds 4
bounds -1730 -10 9 1731 
property_list 
material 3
region 2511
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2511
end_property_list 
<component> 2521 
n_bounds 3
bounds -1731 -10 9 
property_list 
material 4
region 2512
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2512
end_property_list 
<component> 2522 
n_bounds 7
bounds 20 1065 9 1732 -1068 -599 -10 
property_list 
material 2
region 2513
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2513
end_property_list 
<component> 2523 
n_bounds 4
bounds -1732 -10 9 1733 
property_list 
material 3
region 2514
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2514
end_property_list 
<component> 2524 
n_bounds 3
bounds -1733 -10 9 
property_list 
material 4
region 2515
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2515
end_property_list 
<component> 2525 
n_bounds 7
bounds 20 1068 9 1734 -17 -599 -10 
property_list 
material 2
region 2516
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2516
end_property_list 
<component> 2526 
n_bounds 4
bounds -1734 -10 9 1735 
property_list 
material 3
region 2517
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2517
end_property_list 
<component> 2527 
n_bounds 3
bounds -1735 -10 9 
property_list 
material 4
region 2518
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2518
end_property_list 
<component> 2528 
n_bounds 7
bounds 599 202 9 1736 -1050 -616 -10 
property_list 
material 2
region 2519
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2519
end_property_list 
<component> 2529 
n_bounds 4
bounds -1736 -10 9 1737 
property_list 
material 3
region 2520
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2520
end_property_list 
<component> 2530 
n_bounds 3
bounds -1737 -10 9 
property_list 
material 4
region 2521
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2521
end_property_list 
<component> 2531 
n_bounds 7
bounds 599 1050 9 1738 -1053 -616 -10 
property_list 
material 2
region 2522
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2522
end_property_list 
<component> 2532 
n_bounds 4
bounds -1738 -10 9 1739 
property_list 
material 3
region 2523
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2523
end_property_list 
<component> 2533 
n_bounds 3
bounds -1739 -10 9 
property_list 
material 4
region 2524
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2524
end_property_list 
<component> 2534 
n_bounds 7
bounds 599 1053 9 1740 -1056 -616 -10 
property_list 
material 2
region 2525
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2525
end_property_list 
<component> 2535 
n_bounds 4
bounds -1740 -10 9 1741 
property_list 
material 3
region 2526
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2526
end_property_list 
<component> 2536 
n_bounds 3
bounds -1741 -10 9 
property_list 
material 4
region 2527
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2527
end_property_list 
<component> 2537 
n_bounds 7
bounds 599 1056 9 1742 -1059 -616 -10 
property_list 
material 2
region 2528
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2528
end_property_list 
<component> 2538 
n_bounds 4
bounds -1742 -10 9 1743 
property_list 
material 3
region 2529
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2529
end_property_list 
<component> 2539 
n_bounds 3
bounds -1743 -10 9 
property_list 
material 4
region 2530
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2530
end_property_list 
<component> 2540 
n_bounds 7
bounds 599 1059 9 1744 -1062 -616 -10 
property_list 
material 2
region 2531
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2531
end_property_list 
<component> 2541 
n_bounds 4
bounds -1744 -10 9 1745 
property_list 
material 3
region 2532
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2532
end_property_list 
<component> 2542 
n_bounds 3
bounds -1745 -10 9 
property_list 
material 4
region 2533
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2533
end_property_list 
<component> 2543 
n_bounds 7
bounds 599 1062 9 1746 -1065 -616 -10 
property_list 
material 2
region 2534
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2534
end_property_list 
<component> 2544 
n_bounds 4
bounds -1746 -10 9 1747 
property_list 
material 3
region 2535
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2535
end_property_list 
<component> 2545 
n_bounds 3
bounds -1747 -10 9 
property_list 
material 4
region 2536
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2536
end_property_list 
<component> 2546 
n_bounds 7
bounds 599 1065 9 1748 -1068 -616 -10 
property_list 
material 2
region 2537
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2537
end_property_list 
<component> 2547 
n_bounds 4
bounds -1748 -10 9 1749 
property_list 
material 3
region 2538
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2538
end_property_list 
<component> 2548 
n_bounds 3
bounds -1749 -10 9 
property_list 
material 4
region 2539
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2539
end_property_list 
<component> 2549 
n_bounds 7
bounds 599 1068 9 1750 -17 -616 -10 
property_list 
material 2
region 2540
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2540
end_property_list 
<component> 2550 
n_bounds 4
bounds -1750 -10 9 1751 
property_list 
material 3
region 2541
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2541
end_property_list 
<component> 2551 
n_bounds 3
bounds -1751 -10 9 
property_list 
material 4
region 2542
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2542
end_property_list 
<component> 2552 
n_bounds 8
bounds 616 23 52 1753 9 -25 -1752 -10 
property_list 
material 2
region 2543
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2543
end_property_list 
<component> 2553 
n_bounds 6
bounds 23 54 1754 9 -1753 -10 
property_list 
material 3
region 2544
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2544
end_property_list 
<component> 2554 
n_bounds 4
bounds 23 9 -1754 -10 
property_list 
material 4
region 2545
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2545
end_property_list 
<component> 2555 
n_bounds 7
bounds 616 25 9 1755 -27 -1752 -10 
property_list 
material 2
region 2546
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2546
end_property_list 
<component> 2556 
n_bounds 4
bounds -1755 -10 9 1756 
property_list 
material 3
region 2547
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2547
end_property_list 
<component> 2557 
n_bounds 3
bounds -1756 -10 9 
property_list 
material 4
region 2548
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2548
end_property_list 
<component> 2558 
n_bounds 7
bounds 616 27 9 1757 -33 -1752 -10 
property_list 
material 2
region 2549
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2549
end_property_list 
<component> 2559 
n_bounds 4
bounds -1757 -10 9 1758 
property_list 
material 3
region 2550
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2550
end_property_list 
<component> 2560 
n_bounds 3
bounds -1758 -10 9 
property_list 
material 4
region 2551
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2551
end_property_list 
<component> 2561 
n_bounds 7
bounds 616 33 9 1759 -36 -1752 -10 
property_list 
material 2
region 2552
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2552
end_property_list 
<component> 2562 
n_bounds 4
bounds -1759 -10 9 1760 
property_list 
material 3
region 2553
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2553
end_property_list 
<component> 2563 
n_bounds 3
bounds -1760 -10 9 
property_list 
material 4
region 2554
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2554
end_property_list 
<component> 2564 
n_bounds 7
bounds 616 36 9 1761 -39 -1752 -10 
property_list 
material 2
region 2555
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2555
end_property_list 
<component> 2565 
n_bounds 4
bounds -1761 -10 9 1762 
property_list 
material 3
region 2556
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2556
end_property_list 
<component> 2566 
n_bounds 3
bounds -1762 -10 9 
property_list 
material 4
region 2557
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2557
end_property_list 
<component> 2567 
n_bounds 7
bounds 616 39 9 1763 -42 -1752 -10 
property_list 
material 2
region 2558
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2558
end_property_list 
<component> 2568 
n_bounds 4
bounds -1763 -10 9 1764 
property_list 
material 3
region 2559
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2559
end_property_list 
<component> 2569 
n_bounds 3
bounds -1764 -10 9 
property_list 
material 4
region 2560
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2560
end_property_list 
<component> 2570 
n_bounds 7
bounds 616 42 9 1765 -45 -1752 -10 
property_list 
material 2
region 2561
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2561
end_property_list 
<component> 2571 
n_bounds 4
bounds -1765 -10 9 1766 
property_list 
material 3
region 2562
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2562
end_property_list 
<component> 2572 
n_bounds 3
bounds -1766 -10 9 
property_list 
material 4
region 2563
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2563
end_property_list 
<component> 2573 
n_bounds 7
bounds 616 45 9 1767 -48 -1752 -10 
property_list 
material 2
region 2564
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2564
end_property_list 
<component> 2574 
n_bounds 4
bounds -1767 -10 9 1768 
property_list 
material 3
region 2565
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2565
end_property_list 
<component> 2575 
n_bounds 3
bounds -1768 -10 9 
property_list 
material 4
region 2566
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2566
end_property_list 
<component> 2576 
n_bounds 7
bounds 616 48 9 1769 -164 -1752 -10 
property_list 
material 2
region 2567
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2567
end_property_list 
<component> 2577 
n_bounds 4
bounds -1769 -10 9 1770 
property_list 
material 3
region 2568
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2568
end_property_list 
<component> 2578 
n_bounds 3
bounds -1770 -10 9 
property_list 
material 4
region 2569
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2569
end_property_list 
<component> 2579 
n_bounds 7
bounds 616 164 9 1771 -167 -1752 -10 
property_list 
material 2
region 2570
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2570
end_property_list 
<component> 2580 
n_bounds 4
bounds -1771 -10 9 1772 
property_list 
material 3
region 2571
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2571
end_property_list 
<component> 2581 
n_bounds 3
bounds -1772 -10 9 
property_list 
material 4
region 2572
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2572
end_property_list 
<component> 2582 
n_bounds 7
bounds 616 167 9 1773 -12 -1752 -10 
property_list 
material 2
region 2573
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2573
end_property_list 
<component> 2583 
n_bounds 4
bounds -1773 -10 9 1774 
property_list 
material 3
region 2574
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2574
end_property_list 
<component> 2584 
n_bounds 3
bounds -1774 -10 9 
property_list 
material 4
region 2575
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2575
end_property_list 
<component> 2585 
n_bounds 8
bounds 1752 23 52 1776 9 -25 -1775 -10 
property_list 
material 2
region 2576
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2576
end_property_list 
<component> 2586 
n_bounds 6
bounds 23 54 1777 9 -1776 -10 
property_list 
material 3
region 2577
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2577
end_property_list 
<component> 2587 
n_bounds 4
bounds 23 9 -1777 -10 
property_list 
material 4
region 2578
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2578
end_property_list 
<component> 2588 
n_bounds 7
bounds 1752 25 9 1778 -27 -1775 -10 
property_list 
material 2
region 2579
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2579
end_property_list 
<component> 2589 
n_bounds 4
bounds -1778 -10 9 1779 
property_list 
material 3
region 2580
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2580
end_property_list 
<component> 2590 
n_bounds 3
bounds -1779 -10 9 
property_list 
material 4
region 2581
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2581
end_property_list 
<component> 2591 
n_bounds 7
bounds 1752 27 9 1780 -33 -1775 -10 
property_list 
material 2
region 2582
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2582
end_property_list 
<component> 2592 
n_bounds 4
bounds -1780 -10 9 1781 
property_list 
material 3
region 2583
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2583
end_property_list 
<component> 2593 
n_bounds 3
bounds -1781 -10 9 
property_list 
material 4
region 2584
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2584
end_property_list 
<component> 2594 
n_bounds 7
bounds 1752 33 9 1782 -36 -1775 -10 
property_list 
material 2
region 2585
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2585
end_property_list 
<component> 2595 
n_bounds 4
bounds -1782 -10 9 1783 
property_list 
material 3
region 2586
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2586
end_property_list 
<component> 2596 
n_bounds 3
bounds -1783 -10 9 
property_list 
material 4
region 2587
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2587
end_property_list 
<component> 2597 
n_bounds 7
bounds 1752 36 9 1784 -39 -1775 -10 
property_list 
material 2
region 2588
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2588
end_property_list 
<component> 2598 
n_bounds 4
bounds -1784 -10 9 1785 
property_list 
material 3
region 2589
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2589
end_property_list 
<component> 2599 
n_bounds 3
bounds -1785 -10 9 
property_list 
material 4
region 2590
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2590
end_property_list 
<component> 2600 
n_bounds 7
bounds 1752 39 9 1786 -42 -1775 -10 
property_list 
material 2
region 2591
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2591
end_property_list 
<component> 2601 
n_bounds 4
bounds -1786 -10 9 1787 
property_list 
material 3
region 2592
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2592
end_property_list 
<component> 2602 
n_bounds 3
bounds -1787 -10 9 
property_list 
material 4
region 2593
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2593
end_property_list 
<component> 2603 
n_bounds 7
bounds 1752 42 9 1788 -45 -1775 -10 
property_list 
material 2
region 2594
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2594
end_property_list 
<component> 2604 
n_bounds 4
bounds -1788 -10 9 1789 
property_list 
material 3
region 2595
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2595
end_property_list 
<component> 2605 
n_bounds 3
bounds -1789 -10 9 
property_list 
material 4
region 2596
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2596
end_property_list 
<component> 2606 
n_bounds 7
bounds 1752 45 9 1790 -48 -1775 -10 
property_list 
material 2
region 2597
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2597
end_property_list 
<component> 2607 
n_bounds 4
bounds -1790 -10 9 1791 
property_list 
material 3
region 2598
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2598
end_property_list 
<component> 2608 
n_bounds 3
bounds -1791 -10 9 
property_list 
material 4
region 2599
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2599
end_property_list 
<component> 2609 
n_bounds 7
bounds 1752 48 9 1792 -164 -1775 -10 
property_list 
material 2
region 2600
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2600
end_property_list 
<component> 2610 
n_bounds 4
bounds -1792 -10 9 1793 
property_list 
material 3
region 2601
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2601
end_property_list 
<component> 2611 
n_bounds 3
bounds -1793 -10 9 
property_list 
material 4
region 2602
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2602
end_property_list 
<component> 2612 
n_bounds 7
bounds 1752 164 9 1794 -167 -1775 -10 
property_list 
material 2
region 2603
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2603
end_property_list 
<component> 2613 
n_bounds 4
bounds -1794 -10 9 1795 
property_list 
material 3
region 2604
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2604
end_property_list 
<component> 2614 
n_bounds 3
bounds -1795 -10 9 
property_list 
material 4
region 2605
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2605
end_property_list 
<component> 2615 
n_bounds 7
bounds 1752 167 9 1796 -12 -1775 -10 
property_list 
material 2
region 2606
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2606
end_property_list 
<component> 2616 
n_bounds 4
bounds -1796 -10 9 1797 
property_list 
material 3
region 2607
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2607
end_property_list 
<component> 2617 
n_bounds 3
bounds -1797 -10 9 
property_list 
material 4
region 2608
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2608
end_property_list 
<component> 2618 
n_bounds 8
bounds 1775 23 52 1799 9 -25 -1798 -10 
property_list 
material 2
region 2609
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2609
end_property_list 
<component> 2619 
n_bounds 6
bounds 23 54 1800 9 -1799 -10 
property_list 
material 3
region 2610
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2610
end_property_list 
<component> 2620 
n_bounds 4
bounds 23 9 -1800 -10 
property_list 
material 4
region 2611
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2611
end_property_list 
<component> 2621 
n_bounds 7
bounds 1775 25 9 1801 -27 -1798 -10 
property_list 
material 2
region 2612
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2612
end_property_list 
<component> 2622 
n_bounds 4
bounds -1801 -10 9 1802 
property_list 
material 3
region 2613
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2613
end_property_list 
<component> 2623 
n_bounds 3
bounds -1802 -10 9 
property_list 
material 4
region 2614
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2614
end_property_list 
<component> 2624 
n_bounds 7
bounds 1775 27 9 1803 -33 -1798 -10 
property_list 
material 2
region 2615
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2615
end_property_list 
<component> 2625 
n_bounds 4
bounds -1803 -10 9 1804 
property_list 
material 3
region 2616
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2616
end_property_list 
<component> 2626 
n_bounds 3
bounds -1804 -10 9 
property_list 
material 4
region 2617
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2617
end_property_list 
<component> 2627 
n_bounds 7
bounds 1775 33 9 1805 -36 -1798 -10 
property_list 
material 2
region 2618
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2618
end_property_list 
<component> 2628 
n_bounds 4
bounds -1805 -10 9 1806 
property_list 
material 3
region 2619
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2619
end_property_list 
<component> 2629 
n_bounds 3
bounds -1806 -10 9 
property_list 
material 4
region 2620
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2620
end_property_list 
<component> 2630 
n_bounds 7
bounds 1775 36 9 1807 -39 -1798 -10 
property_list 
material 2
region 2621
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2621
end_property_list 
<component> 2631 
n_bounds 4
bounds -1807 -10 9 1808 
property_list 
material 3
region 2622
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2622
end_property_list 
<component> 2632 
n_bounds 3
bounds -1808 -10 9 
property_list 
material 4
region 2623
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2623
end_property_list 
<component> 2633 
n_bounds 7
bounds 1775 39 9 1809 -42 -1798 -10 
property_list 
material 2
region 2624
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2624
end_property_list 
<component> 2634 
n_bounds 4
bounds -1809 -10 9 1810 
property_list 
material 3
region 2625
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2625
end_property_list 
<component> 2635 
n_bounds 3
bounds -1810 -10 9 
property_list 
material 4
region 2626
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2626
end_property_list 
<component> 2636 
n_bounds 7
bounds 1775 42 9 1811 -45 -1798 -10 
property_list 
material 2
region 2627
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2627
end_property_list 
<component> 2637 
n_bounds 4
bounds -1811 -10 9 1812 
property_list 
material 3
region 2628
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2628
end_property_list 
<component> 2638 
n_bounds 3
bounds -1812 -10 9 
property_list 
material 4
region 2629
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2629
end_property_list 
<component> 2639 
n_bounds 7
bounds 1775 45 9 1813 -48 -1798 -10 
property_list 
material 2
region 2630
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2630
end_property_list 
<component> 2640 
n_bounds 4
bounds -1813 -10 9 1814 
property_list 
material 3
region 2631
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2631
end_property_list 
<component> 2641 
n_bounds 3
bounds -1814 -10 9 
property_list 
material 4
region 2632
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2632
end_property_list 
<component> 2642 
n_bounds 7
bounds 1775 48 9 1815 -164 -1798 -10 
property_list 
material 2
region 2633
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2633
end_property_list 
<component> 2643 
n_bounds 4
bounds -1815 -10 9 1816 
property_list 
material 3
region 2634
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2634
end_property_list 
<component> 2644 
n_bounds 3
bounds -1816 -10 9 
property_list 
material 4
region 2635
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2635
end_property_list 
<component> 2645 
n_bounds 7
bounds 1775 164 9 1817 -167 -1798 -10 
property_list 
material 2
region 2636
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2636
end_property_list 
<component> 2646 
n_bounds 4
bounds -1817 -10 9 1818 
property_list 
material 3
region 2637
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2637
end_property_list 
<component> 2647 
n_bounds 3
bounds -1818 -10 9 
property_list 
material 4
region 2638
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2638
end_property_list 
<component> 2648 
n_bounds 7
bounds 1775 167 9 1819 -12 -1798 -10 
property_list 
material 2
region 2639
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2639
end_property_list 
<component> 2649 
n_bounds 4
bounds -1819 -10 9 1820 
property_list 
material 3
region 2640
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2640
end_property_list 
<component> 2650 
n_bounds 3
bounds -1820 -10 9 
property_list 
material 4
region 2641
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2641
end_property_list 
<component> 2651 
n_bounds 8
bounds 1798 23 52 1822 9 -25 -1821 -10 
property_list 
material 2
region 2642
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2642
end_property_list 
<component> 2652 
n_bounds 6
bounds 23 54 1823 9 -1822 -10 
property_list 
material 3
region 2643
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2643
end_property_list 
<component> 2653 
n_bounds 4
bounds 23 9 -1823 -10 
property_list 
material 4
region 2644
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2644
end_property_list 
<component> 2654 
n_bounds 7
bounds 1798 25 9 1824 -27 -1821 -10 
property_list 
material 2
region 2645
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2645
end_property_list 
<component> 2655 
n_bounds 4
bounds -1824 -10 9 1825 
property_list 
material 3
region 2646
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2646
end_property_list 
<component> 2656 
n_bounds 3
bounds -1825 -10 9 
property_list 
material 4
region 2647
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2647
end_property_list 
<component> 2657 
n_bounds 7
bounds 1798 27 9 1826 -33 -1821 -10 
property_list 
material 2
region 2648
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2648
end_property_list 
<component> 2658 
n_bounds 4
bounds -1826 -10 9 1827 
property_list 
material 3
region 2649
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2649
end_property_list 
<component> 2659 
n_bounds 3
bounds -1827 -10 9 
property_list 
material 4
region 2650
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2650
end_property_list 
<component> 2660 
n_bounds 7
bounds 1798 33 9 1828 -36 -1821 -10 
property_list 
material 2
region 2651
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2651
end_property_list 
<component> 2661 
n_bounds 4
bounds -1828 -10 9 1829 
property_list 
material 3
region 2652
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2652
end_property_list 
<component> 2662 
n_bounds 3
bounds -1829 -10 9 
property_list 
material 4
region 2653
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2653
end_property_list 
<component> 2663 
n_bounds 7
bounds 1798 36 9 1830 -39 -1821 -10 
property_list 
material 2
region 2654
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2654
end_property_list 
<component> 2664 
n_bounds 4
bounds -1830 -10 9 1831 
property_list 
material 3
region 2655
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2655
end_property_list 
<component> 2665 
n_bounds 3
bounds -1831 -10 9 
property_list 
material 4
region 2656
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2656
end_property_list 
<component> 2666 
n_bounds 7
bounds 1798 39 9 1832 -42 -1821 -10 
property_list 
material 2
region 2657
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2657
end_property_list 
<component> 2667 
n_bounds 4
bounds -1832 -10 9 1833 
property_list 
material 3
region 2658
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2658
end_property_list 
<component> 2668 
n_bounds 3
bounds -1833 -10 9 
property_list 
material 4
region 2659
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2659
end_property_list 
<component> 2669 
n_bounds 7
bounds 1798 42 9 1834 -45 -1821 -10 
property_list 
material 2
region 2660
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2660
end_property_list 
<component> 2670 
n_bounds 4
bounds -1834 -10 9 1835 
property_list 
material 3
region 2661
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2661
end_property_list 
<component> 2671 
n_bounds 3
bounds -1835 -10 9 
property_list 
material 4
region 2662
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2662
end_property_list 
<component> 2672 
n_bounds 7
bounds 1798 45 9 1836 -48 -1821 -10 
property_list 
material 2
region 2663
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2663
end_property_list 
<component> 2673 
n_bounds 4
bounds -1836 -10 9 1837 
property_list 
material 3
region 2664
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2664
end_property_list 
<component> 2674 
n_bounds 3
bounds -1837 -10 9 
property_list 
material 4
region 2665
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2665
end_property_list 
<component> 2675 
n_bounds 7
bounds 1798 48 9 1838 -164 -1821 -10 
property_list 
material 2
region 2666
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2666
end_property_list 
<component> 2676 
n_bounds 4
bounds -1838 -10 9 1839 
property_list 
material 3
region 2667
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2667
end_property_list 
<component> 2677 
n_bounds 3
bounds -1839 -10 9 
property_list 
material 4
region 2668
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2668
end_property_list 
<component> 2678 
n_bounds 7
bounds 1798 164 9 1840 -167 -1821 -10 
property_list 
material 2
region 2669
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2669
end_property_list 
<component> 2679 
n_bounds 4
bounds -1840 -10 9 1841 
property_list 
material 3
region 2670
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2670
end_property_list 
<component> 2680 
n_bounds 3
bounds -1841 -10 9 
property_list 
material 4
region 2671
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2671
end_property_list 
<component> 2681 
n_bounds 7
bounds 1798 167 9 1842 -12 -1821 -10 
property_list 
material 2
region 2672
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2672
end_property_list 
<component> 2682 
n_bounds 4
bounds -1842 -10 9 1843 
property_list 
material 3
region 2673
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2673
end_property_list 
<component> 2683 
n_bounds 3
bounds -1843 -10 9 
property_list 
material 4
region 2674
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2674
end_property_list 
<component> 2684 
n_bounds 8
bounds 1821 23 52 1845 9 -25 -1844 -10 
property_list 
material 2
region 2675
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2675
end_property_list 
<component> 2685 
n_bounds 6
bounds 23 54 1846 9 -1845 -10 
property_list 
material 3
region 2676
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2676
end_property_list 
<component> 2686 
n_bounds 4
bounds 23 9 -1846 -10 
property_list 
material 4
region 2677
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2677
end_property_list 
<component> 2687 
n_bounds 7
bounds 1821 25 9 1847 -27 -1844 -10 
property_list 
material 2
region 2678
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2678
end_property_list 
<component> 2688 
n_bounds 4
bounds -1847 -10 9 1848 
property_list 
material 3
region 2679
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2679
end_property_list 
<component> 2689 
n_bounds 3
bounds -1848 -10 9 
property_list 
material 4
region 2680
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2680
end_property_list 
<component> 2690 
n_bounds 7
bounds 1821 27 9 1849 -33 -1844 -10 
property_list 
material 2
region 2681
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2681
end_property_list 
<component> 2691 
n_bounds 4
bounds -1849 -10 9 1850 
property_list 
material 3
region 2682
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2682
end_property_list 
<component> 2692 
n_bounds 3
bounds -1850 -10 9 
property_list 
material 4
region 2683
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2683
end_property_list 
<component> 2693 
n_bounds 7
bounds 1821 33 9 1851 -36 -1844 -10 
property_list 
material 2
region 2684
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2684
end_property_list 
<component> 2694 
n_bounds 4
bounds -1851 -10 9 1852 
property_list 
material 3
region 2685
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2685
end_property_list 
<component> 2695 
n_bounds 3
bounds -1852 -10 9 
property_list 
material 4
region 2686
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2686
end_property_list 
<component> 2696 
n_bounds 7
bounds 1821 36 9 1853 -39 -1844 -10 
property_list 
material 2
region 2687
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2687
end_property_list 
<component> 2697 
n_bounds 4
bounds -1853 -10 9 1854 
property_list 
material 3
region 2688
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2688
end_property_list 
<component> 2698 
n_bounds 3
bounds -1854 -10 9 
property_list 
material 4
region 2689
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2689
end_property_list 
<component> 2699 
n_bounds 7
bounds 1821 39 9 1855 -42 -1844 -10 
property_list 
material 2
region 2690
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2690
end_property_list 
<component> 2700 
n_bounds 4
bounds -1855 -10 9 1856 
property_list 
material 3
region 2691
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2691
end_property_list 
<component> 2701 
n_bounds 3
bounds -1856 -10 9 
property_list 
material 4
region 2692
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2692
end_property_list 
<component> 2702 
n_bounds 7
bounds 1821 42 9 1857 -45 -1844 -10 
property_list 
material 2
region 2693
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2693
end_property_list 
<component> 2703 
n_bounds 4
bounds -1857 -10 9 1858 
property_list 
material 3
region 2694
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2694
end_property_list 
<component> 2704 
n_bounds 3
bounds -1858 -10 9 
property_list 
material 4
region 2695
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2695
end_property_list 
<component> 2705 
n_bounds 7
bounds 1821 45 9 1859 -48 -1844 -10 
property_list 
material 2
region 2696
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2696
end_property_list 
<component> 2706 
n_bounds 4
bounds -1859 -10 9 1860 
property_list 
material 3
region 2697
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2697
end_property_list 
<component> 2707 
n_bounds 3
bounds -1860 -10 9 
property_list 
material 4
region 2698
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2698
end_property_list 
<component> 2708 
n_bounds 7
bounds 1821 48 9 1861 -164 -1844 -10 
property_list 
material 2
region 2699
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2699
end_property_list 
<component> 2709 
n_bounds 4
bounds -1861 -10 9 1862 
property_list 
material 3
region 2700
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2700
end_property_list 
<component> 2710 
n_bounds 3
bounds -1862 -10 9 
property_list 
material 4
region 2701
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2701
end_property_list 
<component> 2711 
n_bounds 7
bounds 1821 164 9 1863 -167 -1844 -10 
property_list 
material 2
region 2702
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2702
end_property_list 
<component> 2712 
n_bounds 4
bounds -1863 -10 9 1864 
property_list 
material 3
region 2703
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2703
end_property_list 
<component> 2713 
n_bounds 3
bounds -1864 -10 9 
property_list 
material 4
region 2704
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2704
end_property_list 
<component> 2714 
n_bounds 7
bounds 1821 167 9 1865 -12 -1844 -10 
property_list 
material 2
region 2705
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2705
end_property_list 
<component> 2715 
n_bounds 4
bounds -1865 -10 9 1866 
property_list 
material 3
region 2706
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2706
end_property_list 
<component> 2716 
n_bounds 3
bounds -1866 -10 9 
property_list 
material 4
region 2707
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2707
end_property_list 
<component> 2717 
n_bounds 8
bounds 1844 23 52 1868 9 -25 -1867 -10 
property_list 
material 2
region 2708
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2708
end_property_list 
<component> 2718 
n_bounds 6
bounds 23 54 1869 9 -1868 -10 
property_list 
material 3
region 2709
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2709
end_property_list 
<component> 2719 
n_bounds 4
bounds 23 9 -1869 -10 
property_list 
material 4
region 2710
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2710
end_property_list 
<component> 2720 
n_bounds 7
bounds 1844 25 9 1870 -27 -1867 -10 
property_list 
material 2
region 2711
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2711
end_property_list 
<component> 2721 
n_bounds 4
bounds -1870 -10 9 1871 
property_list 
material 3
region 2712
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2712
end_property_list 
<component> 2722 
n_bounds 3
bounds -1871 -10 9 
property_list 
material 4
region 2713
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2713
end_property_list 
<component> 2723 
n_bounds 7
bounds 1844 27 9 1872 -33 -1867 -10 
property_list 
material 2
region 2714
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2714
end_property_list 
<component> 2724 
n_bounds 4
bounds -1872 -10 9 1873 
property_list 
material 3
region 2715
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2715
end_property_list 
<component> 2725 
n_bounds 3
bounds -1873 -10 9 
property_list 
material 4
region 2716
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2716
end_property_list 
<component> 2726 
n_bounds 7
bounds 1844 33 9 1874 -36 -1867 -10 
property_list 
material 2
region 2717
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2717
end_property_list 
<component> 2727 
n_bounds 4
bounds -1874 -10 9 1875 
property_list 
material 3
region 2718
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2718
end_property_list 
<component> 2728 
n_bounds 3
bounds -1875 -10 9 
property_list 
material 4
region 2719
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2719
end_property_list 
<component> 2729 
n_bounds 7
bounds 1844 36 9 1876 -39 -1867 -10 
property_list 
material 2
region 2720
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2720
end_property_list 
<component> 2730 
n_bounds 4
bounds -1876 -10 9 1877 
property_list 
material 3
region 2721
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2721
end_property_list 
<component> 2731 
n_bounds 3
bounds -1877 -10 9 
property_list 
material 4
region 2722
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2722
end_property_list 
<component> 2732 
n_bounds 7
bounds 1844 39 9 1878 -42 -1867 -10 
property_list 
material 2
region 2723
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2723
end_property_list 
<component> 2733 
n_bounds 4
bounds -1878 -10 9 1879 
property_list 
material 3
region 2724
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2724
end_property_list 
<component> 2734 
n_bounds 3
bounds -1879 -10 9 
property_list 
material 4
region 2725
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2725
end_property_list 
<component> 2735 
n_bounds 7
bounds 1844 42 9 1880 -45 -1867 -10 
property_list 
material 2
region 2726
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2726
end_property_list 
<component> 2736 
n_bounds 4
bounds -1880 -10 9 1881 
property_list 
material 3
region 2727
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2727
end_property_list 
<component> 2737 
n_bounds 3
bounds -1881 -10 9 
property_list 
material 4
region 2728
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2728
end_property_list 
<component> 2738 
n_bounds 7
bounds 1844 45 9 1882 -48 -1867 -10 
property_list 
material 2
region 2729
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2729
end_property_list 
<component> 2739 
n_bounds 4
bounds -1882 -10 9 1883 
property_list 
material 3
region 2730
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2730
end_property_list 
<component> 2740 
n_bounds 3
bounds -1883 -10 9 
property_list 
material 4
region 2731
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2731
end_property_list 
<component> 2741 
n_bounds 7
bounds 1844 48 9 1884 -164 -1867 -10 
property_list 
material 2
region 2732
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2732
end_property_list 
<component> 2742 
n_bounds 4
bounds -1884 -10 9 1885 
property_list 
material 3
region 2733
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2733
end_property_list 
<component> 2743 
n_bounds 3
bounds -1885 -10 9 
property_list 
material 4
region 2734
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2734
end_property_list 
<component> 2744 
n_bounds 7
bounds 1844 164 9 1886 -167 -1867 -10 
property_list 
material 2
region 2735
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2735
end_property_list 
<component> 2745 
n_bounds 4
bounds -1886 -10 9 1887 
property_list 
material 3
region 2736
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2736
end_property_list 
<component> 2746 
n_bounds 3
bounds -1887 -10 9 
property_list 
material 4
region 2737
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2737
end_property_list 
<component> 2747 
n_bounds 7
bounds 1844 167 9 1888 -12 -1867 -10 
property_list 
material 2
region 2738
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2738
end_property_list 
<component> 2748 
n_bounds 4
bounds -1888 -10 9 1889 
property_list 
material 3
region 2739
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2739
end_property_list 
<component> 2749 
n_bounds 3
bounds -1889 -10 9 
property_list 
material 4
region 2740
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2740
end_property_list 
<component> 2750 
n_bounds 8
bounds 1867 23 52 1891 9 -25 -1890 -10 
property_list 
material 2
region 2741
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2741
end_property_list 
<component> 2751 
n_bounds 6
bounds 23 54 1892 9 -1891 -10 
property_list 
material 3
region 2742
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2742
end_property_list 
<component> 2752 
n_bounds 4
bounds 23 9 -1892 -10 
property_list 
material 4
region 2743
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2743
end_property_list 
<component> 2753 
n_bounds 7
bounds 1867 25 9 1893 -27 -1890 -10 
property_list 
material 2
region 2744
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2744
end_property_list 
<component> 2754 
n_bounds 4
bounds -1893 -10 9 1894 
property_list 
material 3
region 2745
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2745
end_property_list 
<component> 2755 
n_bounds 3
bounds -1894 -10 9 
property_list 
material 4
region 2746
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2746
end_property_list 
<component> 2756 
n_bounds 7
bounds 1867 27 9 1895 -33 -1890 -10 
property_list 
material 2
region 2747
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2747
end_property_list 
<component> 2757 
n_bounds 4
bounds -1895 -10 9 1896 
property_list 
material 3
region 2748
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2748
end_property_list 
<component> 2758 
n_bounds 3
bounds -1896 -10 9 
property_list 
material 4
region 2749
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2749
end_property_list 
<component> 2759 
n_bounds 7
bounds 1867 33 9 1897 -36 -1890 -10 
property_list 
material 2
region 2750
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2750
end_property_list 
<component> 2760 
n_bounds 4
bounds -1897 -10 9 1898 
property_list 
material 3
region 2751
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2751
end_property_list 
<component> 2761 
n_bounds 3
bounds -1898 -10 9 
property_list 
material 4
region 2752
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2752
end_property_list 
<component> 2762 
n_bounds 7
bounds 1867 36 9 1899 -39 -1890 -10 
property_list 
material 2
region 2753
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2753
end_property_list 
<component> 2763 
n_bounds 4
bounds -1899 -10 9 1900 
property_list 
material 3
region 2754
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2754
end_property_list 
<component> 2764 
n_bounds 3
bounds -1900 -10 9 
property_list 
material 4
region 2755
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2755
end_property_list 
<component> 2765 
n_bounds 7
bounds 1867 39 9 1901 -42 -1890 -10 
property_list 
material 2
region 2756
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2756
end_property_list 
<component> 2766 
n_bounds 4
bounds -1901 -10 9 1902 
property_list 
material 3
region 2757
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2757
end_property_list 
<component> 2767 
n_bounds 3
bounds -1902 -10 9 
property_list 
material 4
region 2758
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2758
end_property_list 
<component> 2768 
n_bounds 7
bounds 1867 42 9 1903 -45 -1890 -10 
property_list 
material 2
region 2759
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2759
end_property_list 
<component> 2769 
n_bounds 4
bounds -1903 -10 9 1904 
property_list 
material 3
region 2760
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2760
end_property_list 
<component> 2770 
n_bounds 3
bounds -1904 -10 9 
property_list 
material 4
region 2761
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2761
end_property_list 
<component> 2771 
n_bounds 7
bounds 1867 45 9 1905 -48 -1890 -10 
property_list 
material 2
region 2762
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2762
end_property_list 
<component> 2772 
n_bounds 4
bounds -1905 -10 9 1906 
property_list 
material 3
region 2763
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2763
end_property_list 
<component> 2773 
n_bounds 3
bounds -1906 -10 9 
property_list 
material 4
region 2764
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2764
end_property_list 
<component> 2774 
n_bounds 7
bounds 1867 48 9 1907 -164 -1890 -10 
property_list 
material 2
region 2765
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2765
end_property_list 
<component> 2775 
n_bounds 4
bounds -1907 -10 9 1908 
property_list 
material 3
region 2766
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2766
end_property_list 
<component> 2776 
n_bounds 3
bounds -1908 -10 9 
property_list 
material 4
region 2767
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2767
end_property_list 
<component> 2777 
n_bounds 7
bounds 1867 164 9 1909 -167 -1890 -10 
property_list 
material 2
region 2768
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2768
end_property_list 
<component> 2778 
n_bounds 4
bounds -1909 -10 9 1910 
property_list 
material 3
region 2769
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2769
end_property_list 
<component> 2779 
n_bounds 3
bounds -1910 -10 9 
property_list 
material 4
region 2770
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2770
end_property_list 
<component> 2780 
n_bounds 7
bounds 1867 167 9 1911 -12 -1890 -10 
property_list 
material 2
region 2771
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2771
end_property_list 
<component> 2781 
n_bounds 4
bounds -1911 -10 9 1912 
property_list 
material 3
region 2772
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2772
end_property_list 
<component> 2782 
n_bounds 3
bounds -1912 -10 9 
property_list 
material 4
region 2773
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2773
end_property_list 
<component> 2783 
n_bounds 8
bounds 1890 23 52 1913 9 -25 -16 -10 
property_list 
material 2
region 2774
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2774
end_property_list 
<component> 2784 
n_bounds 6
bounds 23 54 1914 9 -1913 -10 
property_list 
material 3
region 2775
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2775
end_property_list 
<component> 2785 
n_bounds 4
bounds 23 9 -1914 -10 
property_list 
material 4
region 2776
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2776
end_property_list 
<component> 2786 
n_bounds 7
bounds 1890 25 9 1915 -27 -16 -10 
property_list 
material 2
region 2777
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2777
end_property_list 
<component> 2787 
n_bounds 4
bounds -1915 -10 9 1916 
property_list 
material 3
region 2778
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2778
end_property_list 
<component> 2788 
n_bounds 3
bounds -1916 -10 9 
property_list 
material 4
region 2779
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2779
end_property_list 
<component> 2789 
n_bounds 7
bounds 1890 27 9 1917 -33 -16 -10 
property_list 
material 2
region 2780
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2780
end_property_list 
<component> 2790 
n_bounds 4
bounds -1917 -10 9 1918 
property_list 
material 3
region 2781
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2781
end_property_list 
<component> 2791 
n_bounds 3
bounds -1918 -10 9 
property_list 
material 4
region 2782
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2782
end_property_list 
<component> 2792 
n_bounds 7
bounds 1890 33 9 1919 -36 -16 -10 
property_list 
material 2
region 2783
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2783
end_property_list 
<component> 2793 
n_bounds 4
bounds -1919 -10 9 1920 
property_list 
material 3
region 2784
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2784
end_property_list 
<component> 2794 
n_bounds 3
bounds -1920 -10 9 
property_list 
material 4
region 2785
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2785
end_property_list 
<component> 2795 
n_bounds 7
bounds 1890 36 9 1921 -39 -16 -10 
property_list 
material 2
region 2786
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2786
end_property_list 
<component> 2796 
n_bounds 4
bounds -1921 -10 9 1922 
property_list 
material 3
region 2787
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2787
end_property_list 
<component> 2797 
n_bounds 3
bounds -1922 -10 9 
property_list 
material 4
region 2788
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2788
end_property_list 
<component> 2798 
n_bounds 7
bounds 1890 39 9 1923 -42 -16 -10 
property_list 
material 2
region 2789
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2789
end_property_list 
<component> 2799 
n_bounds 4
bounds -1923 -10 9 1924 
property_list 
material 3
region 2790
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2790
end_property_list 
<component> 2800 
n_bounds 3
bounds -1924 -10 9 
property_list 
material 4
region 2791
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2791
end_property_list 
<component> 2801 
n_bounds 7
bounds 1890 42 9 1925 -45 -16 -10 
property_list 
material 2
region 2792
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2792
end_property_list 
<component> 2802 
n_bounds 4
bounds -1925 -10 9 1926 
property_list 
material 3
region 2793
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2793
end_property_list 
<component> 2803 
n_bounds 3
bounds -1926 -10 9 
property_list 
material 4
region 2794
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2794
end_property_list 
<component> 2804 
n_bounds 7
bounds 1890 45 9 1927 -48 -16 -10 
property_list 
material 2
region 2795
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2795
end_property_list 
<component> 2805 
n_bounds 4
bounds -1927 -10 9 1928 
property_list 
material 3
region 2796
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2796
end_property_list 
<component> 2806 
n_bounds 3
bounds -1928 -10 9 
property_list 
material 4
region 2797
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2797
end_property_list 
<component> 2807 
n_bounds 7
bounds 1890 48 9 1929 -164 -16 -10 
property_list 
material 2
region 2798
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2798
end_property_list 
<component> 2808 
n_bounds 4
bounds -1929 -10 9 1930 
property_list 
material 3
region 2799
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2799
end_property_list 
<component> 2809 
n_bounds 3
bounds -1930 -10 9 
property_list 
material 4
region 2800
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2800
end_property_list 
<component> 2810 
n_bounds 7
bounds 1890 164 9 1931 -167 -16 -10 
property_list 
material 2
region 2801
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2801
end_property_list 
<component> 2811 
n_bounds 4
bounds -1931 -10 9 1932 
property_list 
material 3
region 2802
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2802
end_property_list 
<component> 2812 
n_bounds 3
bounds -1932 -10 9 
property_list 
material 4
region 2803
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2803
end_property_list 
<component> 2813 
n_bounds 7
bounds 1890 167 9 1933 -12 -16 -10 
property_list 
material 2
region 2804
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2804
end_property_list 
<component> 2814 
n_bounds 4
bounds -1933 -10 9 1934 
property_list 
material 3
region 2805
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2805
end_property_list 
<component> 2815 
n_bounds 3
bounds -1934 -10 9 
property_list 
material 4
region 2806
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2806
end_property_list 
<component> 2816 
n_bounds 8
bounds 16 23 52 1936 9 -25 -1935 -10 
property_list 
material 2
region 2807
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2807
end_property_list 
<component> 2817 
n_bounds 6
bounds 23 54 1937 9 -1936 -10 
property_list 
material 3
region 2808
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2808
end_property_list 
<component> 2818 
n_bounds 4
bounds 23 9 -1937 -10 
property_list 
material 4
region 2809
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2809
end_property_list 
<component> 2819 
n_bounds 7
bounds 16 25 9 1938 -27 -1935 -10 
property_list 
material 2
region 2810
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2810
end_property_list 
<component> 2820 
n_bounds 4
bounds -1938 -10 9 1939 
property_list 
material 3
region 2811
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2811
end_property_list 
<component> 2821 
n_bounds 3
bounds -1939 -10 9 
property_list 
material 4
region 2812
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2812
end_property_list 
<component> 2822 
n_bounds 7
bounds 16 27 9 1940 -33 -1935 -10 
property_list 
material 2
region 2813
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2813
end_property_list 
<component> 2823 
n_bounds 4
bounds -1940 -10 9 1941 
property_list 
material 3
region 2814
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2814
end_property_list 
<component> 2824 
n_bounds 3
bounds -1941 -10 9 
property_list 
material 4
region 2815
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2815
end_property_list 
<component> 2825 
n_bounds 7
bounds 16 33 9 1942 -36 -1935 -10 
property_list 
material 2
region 2816
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2816
end_property_list 
<component> 2826 
n_bounds 4
bounds -1942 -10 9 1943 
property_list 
material 3
region 2817
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2817
end_property_list 
<component> 2827 
n_bounds 3
bounds -1943 -10 9 
property_list 
material 4
region 2818
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2818
end_property_list 
<component> 2828 
n_bounds 7
bounds 16 36 9 1944 -39 -1935 -10 
property_list 
material 2
region 2819
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2819
end_property_list 
<component> 2829 
n_bounds 4
bounds -1944 -10 9 1945 
property_list 
material 3
region 2820
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2820
end_property_list 
<component> 2830 
n_bounds 3
bounds -1945 -10 9 
property_list 
material 4
region 2821
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2821
end_property_list 
<component> 2831 
n_bounds 7
bounds 16 39 9 1946 -42 -1935 -10 
property_list 
material 2
region 2822
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2822
end_property_list 
<component> 2832 
n_bounds 4
bounds -1946 -10 9 1947 
property_list 
material 3
region 2823
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2823
end_property_list 
<component> 2833 
n_bounds 3
bounds -1947 -10 9 
property_list 
material 4
region 2824
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2824
end_property_list 
<component> 2834 
n_bounds 7
bounds 16 42 9 1948 -45 -1935 -10 
property_list 
material 2
region 2825
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2825
end_property_list 
<component> 2835 
n_bounds 4
bounds -1948 -10 9 1949 
property_list 
material 3
region 2826
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2826
end_property_list 
<component> 2836 
n_bounds 3
bounds -1949 -10 9 
property_list 
material 4
region 2827
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2827
end_property_list 
<component> 2837 
n_bounds 7
bounds 16 45 9 1950 -48 -1935 -10 
property_list 
material 2
region 2828
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2828
end_property_list 
<component> 2838 
n_bounds 4
bounds -1950 -10 9 1951 
property_list 
material 3
region 2829
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2829
end_property_list 
<component> 2839 
n_bounds 3
bounds -1951 -10 9 
property_list 
material 4
region 2830
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2830
end_property_list 
<component> 2840 
n_bounds 7
bounds 16 48 9 1952 -164 -1935 -10 
property_list 
material 2
region 2831
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2831
end_property_list 
<component> 2841 
n_bounds 4
bounds -1952 -10 9 1953 
property_list 
material 3
region 2832
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2832
end_property_list 
<component> 2842 
n_bounds 3
bounds -1953 -10 9 
property_list 
material 4
region 2833
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2833
end_property_list 
<component> 2843 
n_bounds 7
bounds 16 164 9 1954 -167 -1935 -10 
property_list 
material 2
region 2834
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2834
end_property_list 
<component> 2844 
n_bounds 4
bounds -1954 -10 9 1955 
property_list 
material 3
region 2835
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2835
end_property_list 
<component> 2845 
n_bounds 3
bounds -1955 -10 9 
property_list 
material 4
region 2836
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2836
end_property_list 
<component> 2846 
n_bounds 7
bounds 16 167 9 1956 -12 -1935 -10 
property_list 
material 2
region 2837
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2837
end_property_list 
<component> 2847 
n_bounds 4
bounds -1956 -10 9 1957 
property_list 
material 3
region 2838
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2838
end_property_list 
<component> 2848 
n_bounds 3
bounds -1957 -10 9 
property_list 
material 4
region 2839
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2839
end_property_list 
<component> 2849 
n_bounds 8
bounds 1935 23 52 1959 9 -25 -1958 -10 
property_list 
material 2
region 2840
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2840
end_property_list 
<component> 2850 
n_bounds 6
bounds 23 54 1960 9 -1959 -10 
property_list 
material 3
region 2841
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2841
end_property_list 
<component> 2851 
n_bounds 4
bounds 23 9 -1960 -10 
property_list 
material 4
region 2842
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2842
end_property_list 
<component> 2852 
n_bounds 7
bounds 1935 25 9 1961 -27 -1958 -10 
property_list 
material 2
region 2843
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2843
end_property_list 
<component> 2853 
n_bounds 4
bounds -1961 -10 9 1962 
property_list 
material 3
region 2844
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2844
end_property_list 
<component> 2854 
n_bounds 3
bounds -1962 -10 9 
property_list 
material 4
region 2845
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2845
end_property_list 
<component> 2855 
n_bounds 7
bounds 1935 27 9 1963 -33 -1958 -10 
property_list 
material 2
region 2846
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2846
end_property_list 
<component> 2856 
n_bounds 4
bounds -1963 -10 9 1964 
property_list 
material 3
region 2847
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2847
end_property_list 
<component> 2857 
n_bounds 3
bounds -1964 -10 9 
property_list 
material 4
region 2848
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2848
end_property_list 
<component> 2858 
n_bounds 7
bounds 1935 33 9 1965 -36 -1958 -10 
property_list 
material 2
region 2849
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2849
end_property_list 
<component> 2859 
n_bounds 4
bounds -1965 -10 9 1966 
property_list 
material 3
region 2850
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2850
end_property_list 
<component> 2860 
n_bounds 3
bounds -1966 -10 9 
property_list 
material 4
region 2851
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2851
end_property_list 
<component> 2861 
n_bounds 7
bounds 1935 36 9 1967 -39 -1958 -10 
property_list 
material 2
region 2852
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2852
end_property_list 
<component> 2862 
n_bounds 4
bounds -1967 -10 9 1968 
property_list 
material 3
region 2853
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2853
end_property_list 
<component> 2863 
n_bounds 3
bounds -1968 -10 9 
property_list 
material 4
region 2854
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2854
end_property_list 
<component> 2864 
n_bounds 7
bounds 1935 39 9 1969 -42 -1958 -10 
property_list 
material 2
region 2855
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2855
end_property_list 
<component> 2865 
n_bounds 4
bounds -1969 -10 9 1970 
property_list 
material 3
region 2856
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2856
end_property_list 
<component> 2866 
n_bounds 3
bounds -1970 -10 9 
property_list 
material 4
region 2857
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2857
end_property_list 
<component> 2867 
n_bounds 7
bounds 1935 42 9 1971 -45 -1958 -10 
property_list 
material 2
region 2858
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2858
end_property_list 
<component> 2868 
n_bounds 4
bounds -1971 -10 9 1972 
property_list 
material 3
region 2859
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2859
end_property_list 
<component> 2869 
n_bounds 3
bounds -1972 -10 9 
property_list 
material 4
region 2860
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2860
end_property_list 
<component> 2870 
n_bounds 7
bounds 1935 45 9 1973 -48 -1958 -10 
property_list 
material 2
region 2861
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2861
end_property_list 
<component> 2871 
n_bounds 4
bounds -1973 -10 9 1974 
property_list 
material 3
region 2862
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2862
end_property_list 
<component> 2872 
n_bounds 3
bounds -1974 -10 9 
property_list 
material 4
region 2863
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2863
end_property_list 
<component> 2873 
n_bounds 7
bounds 1935 48 9 1975 -164 -1958 -10 
property_list 
material 2
region 2864
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2864
end_property_list 
<component> 2874 
n_bounds 4
bounds -1975 -10 9 1976 
property_list 
material 3
region 2865
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2865
end_property_list 
<component> 2875 
n_bounds 3
bounds -1976 -10 9 
property_list 
material 4
region 2866
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2866
end_property_list 
<component> 2876 
n_bounds 7
bounds 1935 164 9 1977 -167 -1958 -10 
property_list 
material 2
region 2867
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2867
end_property_list 
<component> 2877 
n_bounds 4
bounds -1977 -10 9 1978 
property_list 
material 3
region 2868
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2868
end_property_list 
<component> 2878 
n_bounds 3
bounds -1978 -10 9 
property_list 
material 4
region 2869
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2869
end_property_list 
<component> 2879 
n_bounds 7
bounds 1935 167 9 1979 -12 -1958 -10 
property_list 
material 2
region 2870
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2870
end_property_list 
<component> 2880 
n_bounds 4
bounds -1979 -10 9 1980 
property_list 
material 3
region 2871
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2871
end_property_list 
<component> 2881 
n_bounds 3
bounds -1980 -10 9 
property_list 
material 4
region 2872
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2872
end_property_list 
<component> 2882 
n_bounds 8
bounds 1958 23 52 1982 9 -25 -1981 -10 
property_list 
material 2
region 2873
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2873
end_property_list 
<component> 2883 
n_bounds 6
bounds 23 54 1983 9 -1982 -10 
property_list 
material 3
region 2874
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2874
end_property_list 
<component> 2884 
n_bounds 4
bounds 23 9 -1983 -10 
property_list 
material 4
region 2875
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2875
end_property_list 
<component> 2885 
n_bounds 7
bounds 1958 25 9 1984 -27 -1981 -10 
property_list 
material 2
region 2876
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2876
end_property_list 
<component> 2886 
n_bounds 4
bounds -1984 -10 9 1985 
property_list 
material 3
region 2877
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2877
end_property_list 
<component> 2887 
n_bounds 3
bounds -1985 -10 9 
property_list 
material 4
region 2878
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2878
end_property_list 
<component> 2888 
n_bounds 7
bounds 1958 27 9 1986 -33 -1981 -10 
property_list 
material 2
region 2879
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2879
end_property_list 
<component> 2889 
n_bounds 4
bounds -1986 -10 9 1987 
property_list 
material 3
region 2880
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2880
end_property_list 
<component> 2890 
n_bounds 3
bounds -1987 -10 9 
property_list 
material 4
region 2881
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2881
end_property_list 
<component> 2891 
n_bounds 7
bounds 1958 33 9 1988 -36 -1981 -10 
property_list 
material 2
region 2882
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2882
end_property_list 
<component> 2892 
n_bounds 4
bounds -1988 -10 9 1989 
property_list 
material 3
region 2883
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2883
end_property_list 
<component> 2893 
n_bounds 3
bounds -1989 -10 9 
property_list 
material 4
region 2884
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2884
end_property_list 
<component> 2894 
n_bounds 7
bounds 1958 36 9 1990 -39 -1981 -10 
property_list 
material 2
region 2885
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2885
end_property_list 
<component> 2895 
n_bounds 4
bounds -1990 -10 9 1991 
property_list 
material 3
region 2886
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2886
end_property_list 
<component> 2896 
n_bounds 3
bounds -1991 -10 9 
property_list 
material 4
region 2887
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2887
end_property_list 
<component> 2897 
n_bounds 7
bounds 1958 39 9 1992 -42 -1981 -10 
property_list 
material 2
region 2888
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2888
end_property_list 
<component> 2898 
n_bounds 4
bounds -1992 -10 9 1993 
property_list 
material 3
region 2889
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2889
end_property_list 
<component> 2899 
n_bounds 3
bounds -1993 -10 9 
property_list 
material 4
region 2890
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2890
end_property_list 
<component> 2900 
n_bounds 7
bounds 1958 42 9 1994 -45 -1981 -10 
property_list 
material 2
region 2891
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2891
end_property_list 
<component> 2901 
n_bounds 4
bounds -1994 -10 9 1995 
property_list 
material 3
region 2892
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2892
end_property_list 
<component> 2902 
n_bounds 3
bounds -1995 -10 9 
property_list 
material 4
region 2893
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2893
end_property_list 
<component> 2903 
n_bounds 7
bounds 1958 45 9 1996 -48 -1981 -10 
property_list 
material 2
region 2894
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2894
end_property_list 
<component> 2904 
n_bounds 4
bounds -1996 -10 9 1997 
property_list 
material 3
region 2895
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2895
end_property_list 
<component> 2905 
n_bounds 3
bounds -1997 -10 9 
property_list 
material 4
region 2896
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2896
end_property_list 
<component> 2906 
n_bounds 7
bounds 1958 48 9 1998 -164 -1981 -10 
property_list 
material 2
region 2897
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2897
end_property_list 
<component> 2907 
n_bounds 4
bounds -1998 -10 9 1999 
property_list 
material 3
region 2898
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2898
end_property_list 
<component> 2908 
n_bounds 3
bounds -1999 -10 9 
property_list 
material 4
region 2899
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2899
end_property_list 
<component> 2909 
n_bounds 7
bounds 1958 164 9 2000 -167 -1981 -10 
property_list 
material 2
region 2900
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2900
end_property_list 
<component> 2910 
n_bounds 4
bounds -2000 -10 9 2001 
property_list 
material 3
region 2901
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2901
end_property_list 
<component> 2911 
n_bounds 3
bounds -2001 -10 9 
property_list 
material 4
region 2902
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2902
end_property_list 
<component> 2912 
n_bounds 7
bounds 1958 167 9 2002 -12 -1981 -10 
property_list 
material 2
region 2903
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2903
end_property_list 
<component> 2913 
n_bounds 4
bounds -2002 -10 9 2003 
property_list 
material 3
region 2904
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2904
end_property_list 
<component> 2914 
n_bounds 3
bounds -2003 -10 9 
property_list 
material 4
region 2905
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2905
end_property_list 
<component> 2915 
n_bounds 8
bounds 1981 23 52 2005 9 -25 -2004 -10 
property_list 
material 2
region 2906
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2906
end_property_list 
<component> 2916 
n_bounds 6
bounds 23 54 2006 9 -2005 -10 
property_list 
material 3
region 2907
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2907
end_property_list 
<component> 2917 
n_bounds 4
bounds 23 9 -2006 -10 
property_list 
material 4
region 2908
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2908
end_property_list 
<component> 2918 
n_bounds 7
bounds 1981 25 9 2007 -27 -2004 -10 
property_list 
material 2
region 2909
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2909
end_property_list 
<component> 2919 
n_bounds 4
bounds -2007 -10 9 2008 
property_list 
material 3
region 2910
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2910
end_property_list 
<component> 2920 
n_bounds 3
bounds -2008 -10 9 
property_list 
material 4
region 2911
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2911
end_property_list 
<component> 2921 
n_bounds 7
bounds 1981 27 9 2009 -33 -2004 -10 
property_list 
material 2
region 2912
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2912
end_property_list 
<component> 2922 
n_bounds 4
bounds -2009 -10 9 2010 
property_list 
material 3
region 2913
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2913
end_property_list 
<component> 2923 
n_bounds 3
bounds -2010 -10 9 
property_list 
material 4
region 2914
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2914
end_property_list 
<component> 2924 
n_bounds 7
bounds 1981 33 9 2011 -36 -2004 -10 
property_list 
material 2
region 2915
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2915
end_property_list 
<component> 2925 
n_bounds 4
bounds -2011 -10 9 2012 
property_list 
material 3
region 2916
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2916
end_property_list 
<component> 2926 
n_bounds 3
bounds -2012 -10 9 
property_list 
material 4
region 2917
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2917
end_property_list 
<component> 2927 
n_bounds 7
bounds 1981 36 9 2013 -39 -2004 -10 
property_list 
material 2
region 2918
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2918
end_property_list 
<component> 2928 
n_bounds 4
bounds -2013 -10 9 2014 
property_list 
material 3
region 2919
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2919
end_property_list 
<component> 2929 
n_bounds 3
bounds -2014 -10 9 
property_list 
material 4
region 2920
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2920
end_property_list 
<component> 2930 
n_bounds 7
bounds 1981 39 9 2015 -42 -2004 -10 
property_list 
material 2
region 2921
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2921
end_property_list 
<component> 2931 
n_bounds 4
bounds -2015 -10 9 2016 
property_list 
material 3
region 2922
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2922
end_property_list 
<component> 2932 
n_bounds 3
bounds -2016 -10 9 
property_list 
material 4
region 2923
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2923
end_property_list 
<component> 2933 
n_bounds 7
bounds 1981 42 9 2017 -45 -2004 -10 
property_list 
material 2
region 2924
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2924
end_property_list 
<component> 2934 
n_bounds 4
bounds -2017 -10 9 2018 
property_list 
material 3
region 2925
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2925
end_property_list 
<component> 2935 
n_bounds 3
bounds -2018 -10 9 
property_list 
material 4
region 2926
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2926
end_property_list 
<component> 2936 
n_bounds 7
bounds 1981 45 9 2019 -48 -2004 -10 
property_list 
material 2
region 2927
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2927
end_property_list 
<component> 2937 
n_bounds 4
bounds -2019 -10 9 2020 
property_list 
material 3
region 2928
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2928
end_property_list 
<component> 2938 
n_bounds 3
bounds -2020 -10 9 
property_list 
material 4
region 2929
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2929
end_property_list 
<component> 2939 
n_bounds 7
bounds 1981 48 9 2021 -164 -2004 -10 
property_list 
material 2
region 2930
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2930
end_property_list 
<component> 2940 
n_bounds 4
bounds -2021 -10 9 2022 
property_list 
material 3
region 2931
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2931
end_property_list 
<component> 2941 
n_bounds 3
bounds -2022 -10 9 
property_list 
material 4
region 2932
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2932
end_property_list 
<component> 2942 
n_bounds 7
bounds 1981 164 9 2023 -167 -2004 -10 
property_list 
material 2
region 2933
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2933
end_property_list 
<component> 2943 
n_bounds 4
bounds -2023 -10 9 2024 
property_list 
material 3
region 2934
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2934
end_property_list 
<component> 2944 
n_bounds 3
bounds -2024 -10 9 
property_list 
material 4
region 2935
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2935
end_property_list 
<component> 2945 
n_bounds 7
bounds 1981 167 9 2025 -12 -2004 -10 
property_list 
material 2
region 2936
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2936
end_property_list 
<component> 2946 
n_bounds 4
bounds -2025 -10 9 2026 
property_list 
material 3
region 2937
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2937
end_property_list 
<component> 2947 
n_bounds 3
bounds -2026 -10 9 
property_list 
material 4
region 2938
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2938
end_property_list 
<component> 2948 
n_bounds 8
bounds 2004 23 52 2027 9 -25 -14 -10 
property_list 
material 2
region 2939
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2939
end_property_list 
<component> 2949 
n_bounds 6
bounds 23 54 2028 9 -2027 -10 
property_list 
material 3
region 2940
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2940
end_property_list 
<component> 2950 
n_bounds 4
bounds 23 9 -2028 -10 
property_list 
material 4
region 2941
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2941
end_property_list 
<component> 2951 
n_bounds 7
bounds 2004 25 9 2029 -27 -14 -10 
property_list 
material 2
region 2942
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2942
end_property_list 
<component> 2952 
n_bounds 4
bounds -2029 -10 9 2030 
property_list 
material 3
region 2943
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2943
end_property_list 
<component> 2953 
n_bounds 3
bounds -2030 -10 9 
property_list 
material 4
region 2944
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2944
end_property_list 
<component> 2954 
n_bounds 7
bounds 2004 27 9 2031 -33 -14 -10 
property_list 
material 2
region 2945
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2945
end_property_list 
<component> 2955 
n_bounds 4
bounds -2031 -10 9 2032 
property_list 
material 3
region 2946
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2946
end_property_list 
<component> 2956 
n_bounds 3
bounds -2032 -10 9 
property_list 
material 4
region 2947
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2947
end_property_list 
<component> 2957 
n_bounds 7
bounds 2004 33 9 2033 -36 -14 -10 
property_list 
material 2
region 2948
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2948
end_property_list 
<component> 2958 
n_bounds 4
bounds -2033 -10 9 2034 
property_list 
material 3
region 2949
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2949
end_property_list 
<component> 2959 
n_bounds 3
bounds -2034 -10 9 
property_list 
material 4
region 2950
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2950
end_property_list 
<component> 2960 
n_bounds 7
bounds 2004 36 9 2035 -39 -14 -10 
property_list 
material 2
region 2951
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2951
end_property_list 
<component> 2961 
n_bounds 4
bounds -2035 -10 9 2036 
property_list 
material 3
region 2952
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2952
end_property_list 
<component> 2962 
n_bounds 3
bounds -2036 -10 9 
property_list 
material 4
region 2953
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2953
end_property_list 
<component> 2963 
n_bounds 7
bounds 2004 39 9 2037 -42 -14 -10 
property_list 
material 2
region 2954
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2954
end_property_list 
<component> 2964 
n_bounds 4
bounds -2037 -10 9 2038 
property_list 
material 3
region 2955
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2955
end_property_list 
<component> 2965 
n_bounds 3
bounds -2038 -10 9 
property_list 
material 4
region 2956
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2956
end_property_list 
<component> 2966 
n_bounds 7
bounds 2004 42 9 2039 -45 -14 -10 
property_list 
material 2
region 2957
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2957
end_property_list 
<component> 2967 
n_bounds 4
bounds -2039 -10 9 2040 
property_list 
material 3
region 2958
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2958
end_property_list 
<component> 2968 
n_bounds 3
bounds -2040 -10 9 
property_list 
material 4
region 2959
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2959
end_property_list 
<component> 2969 
n_bounds 7
bounds 2004 45 9 2041 -48 -14 -10 
property_list 
material 2
region 2960
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2960
end_property_list 
<component> 2970 
n_bounds 4
bounds -2041 -10 9 2042 
property_list 
material 3
region 2961
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2961
end_property_list 
<component> 2971 
n_bounds 3
bounds -2042 -10 9 
property_list 
material 4
region 2962
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2962
end_property_list 
<component> 2972 
n_bounds 7
bounds 2004 48 9 2043 -164 -14 -10 
property_list 
material 2
region 2963
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2963
end_property_list 
<component> 2973 
n_bounds 4
bounds -2043 -10 9 2044 
property_list 
material 3
region 2964
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2964
end_property_list 
<component> 2974 
n_bounds 3
bounds -2044 -10 9 
property_list 
material 4
region 2965
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2965
end_property_list 
<component> 2975 
n_bounds 7
bounds 2004 164 9 2045 -167 -14 -10 
property_list 
material 2
region 2966
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2966
end_property_list 
<component> 2976 
n_bounds 4
bounds -2045 -10 9 2046 
property_list 
material 3
region 2967
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2967
end_property_list 
<component> 2977 
n_bounds 3
bounds -2046 -10 9 
property_list 
material 4
region 2968
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2968
end_property_list 
<component> 2978 
n_bounds 7
bounds 2004 167 9 2047 -12 -14 -10 
property_list 
material 2
region 2969
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2969
end_property_list 
<component> 2979 
n_bounds 4
bounds -2047 -10 9 2048 
property_list 
material 3
region 2970
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2970
end_property_list 
<component> 2980 
n_bounds 3
bounds -2048 -10 9 
property_list 
material 4
region 2971
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2971
end_property_list 
<component> 2981 
n_bounds 8
bounds 14 23 52 2050 9 -25 -2049 -10 
property_list 
material 2
region 2972
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2972
end_property_list 
<component> 2982 
n_bounds 6
bounds 23 54 2051 9 -2050 -10 
property_list 
material 3
region 2973
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2973
end_property_list 
<component> 2983 
n_bounds 4
bounds 23 9 -2051 -10 
property_list 
material 4
region 2974
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2974
end_property_list 
<component> 2984 
n_bounds 7
bounds 14 25 9 2052 -27 -2049 -10 
property_list 
material 2
region 2975
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2975
end_property_list 
<component> 2985 
n_bounds 4
bounds -2052 -10 9 2053 
property_list 
material 3
region 2976
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2976
end_property_list 
<component> 2986 
n_bounds 3
bounds -2053 -10 9 
property_list 
material 4
region 2977
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2977
end_property_list 
<component> 2987 
n_bounds 7
bounds 14 27 9 2054 -33 -2049 -10 
property_list 
material 2
region 2978
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2978
end_property_list 
<component> 2988 
n_bounds 4
bounds -2054 -10 9 2055 
property_list 
material 3
region 2979
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2979
end_property_list 
<component> 2989 
n_bounds 3
bounds -2055 -10 9 
property_list 
material 4
region 2980
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2980
end_property_list 
<component> 2990 
n_bounds 7
bounds 14 33 9 2056 -36 -2049 -10 
property_list 
material 2
region 2981
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2981
end_property_list 
<component> 2991 
n_bounds 4
bounds -2056 -10 9 2057 
property_list 
material 3
region 2982
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2982
end_property_list 
<component> 2992 
n_bounds 3
bounds -2057 -10 9 
property_list 
material 4
region 2983
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2983
end_property_list 
<component> 2993 
n_bounds 7
bounds 14 36 9 2058 -39 -2049 -10 
property_list 
material 2
region 2984
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2984
end_property_list 
<component> 2994 
n_bounds 4
bounds -2058 -10 9 2059 
property_list 
material 3
region 2985
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2985
end_property_list 
<component> 2995 
n_bounds 3
bounds -2059 -10 9 
property_list 
material 4
region 2986
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2986
end_property_list 
<component> 2996 
n_bounds 7
bounds 14 39 9 2060 -42 -2049 -10 
property_list 
material 2
region 2987
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2987
end_property_list 
<component> 2997 
n_bounds 4
bounds -2060 -10 9 2061 
property_list 
material 3
region 2988
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2988
end_property_list 
<component> 2998 
n_bounds 3
bounds -2061 -10 9 
property_list 
material 4
region 2989
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2989
end_property_list 
<component> 2999 
n_bounds 7
bounds 14 42 9 2062 -45 -2049 -10 
property_list 
material 2
region 2990
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2990
end_property_list 
<component> 3000 
n_bounds 4
bounds -2062 -10 9 2063 
property_list 
material 3
region 2991
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2991
end_property_list 
<component> 3001 
n_bounds 3
bounds -2063 -10 9 
property_list 
material 4
region 2992
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2992
end_property_list 
<component> 3002 
n_bounds 7
bounds 14 45 9 2064 -48 -2049 -10 
property_list 
material 2
region 2993
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2993
end_property_list 
<component> 3003 
n_bounds 4
bounds -2064 -10 9 2065 
property_list 
material 3
region 2994
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2994
end_property_list 
<component> 3004 
n_bounds 3
bounds -2065 -10 9 
property_list 
material 4
region 2995
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2995
end_property_list 
<component> 3005 
n_bounds 7
bounds 14 48 9 2066 -164 -2049 -10 
property_list 
material 2
region 2996
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2996
end_property_list 
<component> 3006 
n_bounds 4
bounds -2066 -10 9 2067 
property_list 
material 3
region 2997
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-2997
end_property_list 
<component> 3007 
n_bounds 3
bounds -2067 -10 9 
property_list 
material 4
region 2998
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-2998
end_property_list 
<component> 3008 
n_bounds 7
bounds 14 164 9 2068 -167 -2049 -10 
property_list 
material 2
region 2999
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-2999
end_property_list 
<component> 3009 
n_bounds 4
bounds -2068 -10 9 2069 
property_list 
material 3
region 3000
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3000
end_property_list 
<component> 3010 
n_bounds 3
bounds -2069 -10 9 
property_list 
material 4
region 3001
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3001
end_property_list 
<component> 3011 
n_bounds 7
bounds 14 167 9 2070 -12 -2049 -10 
property_list 
material 2
region 3002
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3002
end_property_list 
<component> 3012 
n_bounds 4
bounds -2070 -10 9 2071 
property_list 
material 3
region 3003
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3003
end_property_list 
<component> 3013 
n_bounds 3
bounds -2071 -10 9 
property_list 
material 4
region 3004
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3004
end_property_list 
<component> 3014 
n_bounds 8
bounds 2049 23 52 2073 9 -25 -2072 -10 
property_list 
material 2
region 3005
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3005
end_property_list 
<component> 3015 
n_bounds 6
bounds 23 54 2074 9 -2073 -10 
property_list 
material 3
region 3006
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3006
end_property_list 
<component> 3016 
n_bounds 4
bounds 23 9 -2074 -10 
property_list 
material 4
region 3007
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3007
end_property_list 
<component> 3017 
n_bounds 7
bounds 2049 25 9 2075 -27 -2072 -10 
property_list 
material 2
region 3008
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3008
end_property_list 
<component> 3018 
n_bounds 4
bounds -2075 -10 9 2076 
property_list 
material 3
region 3009
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3009
end_property_list 
<component> 3019 
n_bounds 3
bounds -2076 -10 9 
property_list 
material 4
region 3010
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3010
end_property_list 
<component> 3020 
n_bounds 7
bounds 2049 27 9 2077 -33 -2072 -10 
property_list 
material 2
region 3011
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3011
end_property_list 
<component> 3021 
n_bounds 4
bounds -2077 -10 9 2078 
property_list 
material 3
region 3012
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3012
end_property_list 
<component> 3022 
n_bounds 3
bounds -2078 -10 9 
property_list 
material 4
region 3013
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3013
end_property_list 
<component> 3023 
n_bounds 7
bounds 2049 33 9 2079 -36 -2072 -10 
property_list 
material 2
region 3014
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3014
end_property_list 
<component> 3024 
n_bounds 4
bounds -2079 -10 9 2080 
property_list 
material 3
region 3015
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3015
end_property_list 
<component> 3025 
n_bounds 3
bounds -2080 -10 9 
property_list 
material 4
region 3016
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3016
end_property_list 
<component> 3026 
n_bounds 7
bounds 2049 36 9 2081 -39 -2072 -10 
property_list 
material 2
region 3017
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3017
end_property_list 
<component> 3027 
n_bounds 4
bounds -2081 -10 9 2082 
property_list 
material 3
region 3018
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3018
end_property_list 
<component> 3028 
n_bounds 3
bounds -2082 -10 9 
property_list 
material 4
region 3019
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3019
end_property_list 
<component> 3029 
n_bounds 7
bounds 2049 39 9 2083 -42 -2072 -10 
property_list 
material 2
region 3020
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3020
end_property_list 
<component> 3030 
n_bounds 4
bounds -2083 -10 9 2084 
property_list 
material 3
region 3021
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3021
end_property_list 
<component> 3031 
n_bounds 3
bounds -2084 -10 9 
property_list 
material 4
region 3022
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3022
end_property_list 
<component> 3032 
n_bounds 7
bounds 2049 42 9 2085 -45 -2072 -10 
property_list 
material 2
region 3023
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3023
end_property_list 
<component> 3033 
n_bounds 4
bounds -2085 -10 9 2086 
property_list 
material 3
region 3024
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3024
end_property_list 
<component> 3034 
n_bounds 3
bounds -2086 -10 9 
property_list 
material 4
region 3025
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3025
end_property_list 
<component> 3035 
n_bounds 7
bounds 2049 45 9 2087 -48 -2072 -10 
property_list 
material 2
region 3026
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3026
end_property_list 
<component> 3036 
n_bounds 4
bounds -2087 -10 9 2088 
property_list 
material 3
region 3027
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3027
end_property_list 
<component> 3037 
n_bounds 3
bounds -2088 -10 9 
property_list 
material 4
region 3028
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3028
end_property_list 
<component> 3038 
n_bounds 7
bounds 2049 48 9 2089 -164 -2072 -10 
property_list 
material 2
region 3029
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3029
end_property_list 
<component> 3039 
n_bounds 4
bounds -2089 -10 9 2090 
property_list 
material 3
region 3030
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3030
end_property_list 
<component> 3040 
n_bounds 3
bounds -2090 -10 9 
property_list 
material 4
region 3031
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3031
end_property_list 
<component> 3041 
n_bounds 7
bounds 2049 164 9 2091 -167 -2072 -10 
property_list 
material 2
region 3032
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3032
end_property_list 
<component> 3042 
n_bounds 4
bounds -2091 -10 9 2092 
property_list 
material 3
region 3033
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3033
end_property_list 
<component> 3043 
n_bounds 3
bounds -2092 -10 9 
property_list 
material 4
region 3034
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3034
end_property_list 
<component> 3044 
n_bounds 7
bounds 2049 167 9 2093 -12 -2072 -10 
property_list 
material 2
region 3035
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3035
end_property_list 
<component> 3045 
n_bounds 4
bounds -2093 -10 9 2094 
property_list 
material 3
region 3036
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3036
end_property_list 
<component> 3046 
n_bounds 3
bounds -2094 -10 9 
property_list 
material 4
region 3037
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3037
end_property_list 
<component> 3047 
n_bounds 8
bounds 2072 23 52 2096 9 -25 -2095 -10 
property_list 
material 2
region 3038
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3038
end_property_list 
<component> 3048 
n_bounds 6
bounds 23 54 2097 9 -2096 -10 
property_list 
material 3
region 3039
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3039
end_property_list 
<component> 3049 
n_bounds 4
bounds 23 9 -2097 -10 
property_list 
material 4
region 3040
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3040
end_property_list 
<component> 3050 
n_bounds 7
bounds 2072 25 9 2098 -27 -2095 -10 
property_list 
material 2
region 3041
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3041
end_property_list 
<component> 3051 
n_bounds 4
bounds -2098 -10 9 2099 
property_list 
material 3
region 3042
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3042
end_property_list 
<component> 3052 
n_bounds 3
bounds -2099 -10 9 
property_list 
material 4
region 3043
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3043
end_property_list 
<component> 3053 
n_bounds 7
bounds 2072 27 9 2100 -33 -2095 -10 
property_list 
material 2
region 3044
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3044
end_property_list 
<component> 3054 
n_bounds 4
bounds -2100 -10 9 2101 
property_list 
material 3
region 3045
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3045
end_property_list 
<component> 3055 
n_bounds 3
bounds -2101 -10 9 
property_list 
material 4
region 3046
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3046
end_property_list 
<component> 3056 
n_bounds 7
bounds 2072 33 9 2102 -36 -2095 -10 
property_list 
material 2
region 3047
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3047
end_property_list 
<component> 3057 
n_bounds 4
bounds -2102 -10 9 2103 
property_list 
material 3
region 3048
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3048
end_property_list 
<component> 3058 
n_bounds 3
bounds -2103 -10 9 
property_list 
material 4
region 3049
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3049
end_property_list 
<component> 3059 
n_bounds 7
bounds 2072 36 9 2104 -39 -2095 -10 
property_list 
material 2
region 3050
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3050
end_property_list 
<component> 3060 
n_bounds 4
bounds -2104 -10 9 2105 
property_list 
material 3
region 3051
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3051
end_property_list 
<component> 3061 
n_bounds 3
bounds -2105 -10 9 
property_list 
material 4
region 3052
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3052
end_property_list 
<component> 3062 
n_bounds 7
bounds 2072 39 9 2106 -42 -2095 -10 
property_list 
material 2
region 3053
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3053
end_property_list 
<component> 3063 
n_bounds 4
bounds -2106 -10 9 2107 
property_list 
material 3
region 3054
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3054
end_property_list 
<component> 3064 
n_bounds 3
bounds -2107 -10 9 
property_list 
material 4
region 3055
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3055
end_property_list 
<component> 3065 
n_bounds 7
bounds 2072 42 9 2108 -45 -2095 -10 
property_list 
material 2
region 3056
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3056
end_property_list 
<component> 3066 
n_bounds 4
bounds -2108 -10 9 2109 
property_list 
material 3
region 3057
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3057
end_property_list 
<component> 3067 
n_bounds 3
bounds -2109 -10 9 
property_list 
material 4
region 3058
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3058
end_property_list 
<component> 3068 
n_bounds 7
bounds 2072 45 9 2110 -48 -2095 -10 
property_list 
material 2
region 3059
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3059
end_property_list 
<component> 3069 
n_bounds 4
bounds -2110 -10 9 2111 
property_list 
material 3
region 3060
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3060
end_property_list 
<component> 3070 
n_bounds 3
bounds -2111 -10 9 
property_list 
material 4
region 3061
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3061
end_property_list 
<component> 3071 
n_bounds 7
bounds 2072 48 9 2112 -164 -2095 -10 
property_list 
material 2
region 3062
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3062
end_property_list 
<component> 3072 
n_bounds 4
bounds -2112 -10 9 2113 
property_list 
material 3
region 3063
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3063
end_property_list 
<component> 3073 
n_bounds 3
bounds -2113 -10 9 
property_list 
material 4
region 3064
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3064
end_property_list 
<component> 3074 
n_bounds 7
bounds 2072 164 9 2114 -167 -2095 -10 
property_list 
material 2
region 3065
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3065
end_property_list 
<component> 3075 
n_bounds 4
bounds -2114 -10 9 2115 
property_list 
material 3
region 3066
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3066
end_property_list 
<component> 3076 
n_bounds 3
bounds -2115 -10 9 
property_list 
material 4
region 3067
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3067
end_property_list 
<component> 3077 
n_bounds 7
bounds 2072 167 9 2116 -12 -2095 -10 
property_list 
material 2
region 3068
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3068
end_property_list 
<component> 3078 
n_bounds 4
bounds -2116 -10 9 2117 
property_list 
material 3
region 3069
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3069
end_property_list 
<component> 3079 
n_bounds 3
bounds -2117 -10 9 
property_list 
material 4
region 3070
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3070
end_property_list 
<component> 3080 
n_bounds 8
bounds 2095 23 52 2119 9 -25 -2118 -10 
property_list 
material 2
region 3071
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3071
end_property_list 
<component> 3081 
n_bounds 6
bounds 23 54 2120 9 -2119 -10 
property_list 
material 3
region 3072
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3072
end_property_list 
<component> 3082 
n_bounds 4
bounds 23 9 -2120 -10 
property_list 
material 4
region 3073
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3073
end_property_list 
<component> 3083 
n_bounds 7
bounds 2095 25 9 2121 -27 -2118 -10 
property_list 
material 2
region 3074
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3074
end_property_list 
<component> 3084 
n_bounds 4
bounds -2121 -10 9 2122 
property_list 
material 3
region 3075
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3075
end_property_list 
<component> 3085 
n_bounds 3
bounds -2122 -10 9 
property_list 
material 4
region 3076
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3076
end_property_list 
<component> 3086 
n_bounds 7
bounds 2095 27 9 2123 -33 -2118 -10 
property_list 
material 2
region 3077
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3077
end_property_list 
<component> 3087 
n_bounds 4
bounds -2123 -10 9 2124 
property_list 
material 3
region 3078
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3078
end_property_list 
<component> 3088 
n_bounds 3
bounds -2124 -10 9 
property_list 
material 4
region 3079
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3079
end_property_list 
<component> 3089 
n_bounds 7
bounds 2095 33 9 2125 -36 -2118 -10 
property_list 
material 2
region 3080
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3080
end_property_list 
<component> 3090 
n_bounds 4
bounds -2125 -10 9 2126 
property_list 
material 3
region 3081
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3081
end_property_list 
<component> 3091 
n_bounds 3
bounds -2126 -10 9 
property_list 
material 4
region 3082
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3082
end_property_list 
<component> 3092 
n_bounds 7
bounds 2095 36 9 2127 -39 -2118 -10 
property_list 
material 2
region 3083
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3083
end_property_list 
<component> 3093 
n_bounds 4
bounds -2127 -10 9 2128 
property_list 
material 3
region 3084
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3084
end_property_list 
<component> 3094 
n_bounds 3
bounds -2128 -10 9 
property_list 
material 4
region 3085
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3085
end_property_list 
<component> 3095 
n_bounds 7
bounds 2095 39 9 2129 -42 -2118 -10 
property_list 
material 2
region 3086
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3086
end_property_list 
<component> 3096 
n_bounds 4
bounds -2129 -10 9 2130 
property_list 
material 3
region 3087
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3087
end_property_list 
<component> 3097 
n_bounds 3
bounds -2130 -10 9 
property_list 
material 4
region 3088
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3088
end_property_list 
<component> 3098 
n_bounds 7
bounds 2095 42 9 2131 -45 -2118 -10 
property_list 
material 2
region 3089
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3089
end_property_list 
<component> 3099 
n_bounds 4
bounds -2131 -10 9 2132 
property_list 
material 3
region 3090
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3090
end_property_list 
<component> 3100 
n_bounds 3
bounds -2132 -10 9 
property_list 
material 4
region 3091
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3091
end_property_list 
<component> 3101 
n_bounds 7
bounds 2095 45 9 2133 -48 -2118 -10 
property_list 
material 2
region 3092
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3092
end_property_list 
<component> 3102 
n_bounds 4
bounds -2133 -10 9 2134 
property_list 
material 3
region 3093
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3093
end_property_list 
<component> 3103 
n_bounds 3
bounds -2134 -10 9 
property_list 
material 4
region 3094
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3094
end_property_list 
<component> 3104 
n_bounds 7
bounds 2095 48 9 2135 -164 -2118 -10 
property_list 
material 2
region 3095
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3095
end_property_list 
<component> 3105 
n_bounds 4
bounds -2135 -10 9 2136 
property_list 
material 3
region 3096
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3096
end_property_list 
<component> 3106 
n_bounds 3
bounds -2136 -10 9 
property_list 
material 4
region 3097
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3097
end_property_list 
<component> 3107 
n_bounds 7
bounds 2095 164 9 2137 -167 -2118 -10 
property_list 
material 2
region 3098
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3098
end_property_list 
<component> 3108 
n_bounds 4
bounds -2137 -10 9 2138 
property_list 
material 3
region 3099
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3099
end_property_list 
<component> 3109 
n_bounds 3
bounds -2138 -10 9 
property_list 
material 4
region 3100
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3100
end_property_list 
<component> 3110 
n_bounds 7
bounds 2095 167 9 2139 -12 -2118 -10 
property_list 
material 2
region 3101
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3101
end_property_list 
<component> 3111 
n_bounds 4
bounds -2139 -10 9 2140 
property_list 
material 3
region 3102
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3102
end_property_list 
<component> 3112 
n_bounds 3
bounds -2140 -10 9 
property_list 
material 4
region 3103
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3103
end_property_list 
<component> 3113 
n_bounds 8
bounds 2118 23 52 2141 9 -25 -11 -10 
property_list 
material 2
region 3104
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3104
end_property_list 
<component> 3114 
n_bounds 6
bounds 23 54 2142 9 -2141 -10 
property_list 
material 3
region 3105
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3105
end_property_list 
<component> 3115 
n_bounds 4
bounds 23 9 -2142 -10 
property_list 
material 4
region 3106
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3106
end_property_list 
<component> 3116 
n_bounds 7
bounds 2118 25 9 2143 -27 -11 -10 
property_list 
material 2
region 3107
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3107
end_property_list 
<component> 3117 
n_bounds 4
bounds -2143 -10 9 2144 
property_list 
material 3
region 3108
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3108
end_property_list 
<component> 3118 
n_bounds 3
bounds -2144 -10 9 
property_list 
material 4
region 3109
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3109
end_property_list 
<component> 3119 
n_bounds 7
bounds 2118 27 9 2145 -33 -11 -10 
property_list 
material 2
region 3110
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3110
end_property_list 
<component> 3120 
n_bounds 4
bounds -2145 -10 9 2146 
property_list 
material 3
region 3111
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3111
end_property_list 
<component> 3121 
n_bounds 3
bounds -2146 -10 9 
property_list 
material 4
region 3112
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3112
end_property_list 
<component> 3122 
n_bounds 7
bounds 2118 33 9 2147 -36 -11 -10 
property_list 
material 2
region 3113
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3113
end_property_list 
<component> 3123 
n_bounds 4
bounds -2147 -10 9 2148 
property_list 
material 3
region 3114
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3114
end_property_list 
<component> 3124 
n_bounds 3
bounds -2148 -10 9 
property_list 
material 4
region 3115
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3115
end_property_list 
<component> 3125 
n_bounds 7
bounds 2118 36 9 2149 -39 -11 -10 
property_list 
material 2
region 3116
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3116
end_property_list 
<component> 3126 
n_bounds 4
bounds -2149 -10 9 2150 
property_list 
material 3
region 3117
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3117
end_property_list 
<component> 3127 
n_bounds 3
bounds -2150 -10 9 
property_list 
material 4
region 3118
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3118
end_property_list 
<component> 3128 
n_bounds 7
bounds 2118 39 9 2151 -42 -11 -10 
property_list 
material 2
region 3119
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3119
end_property_list 
<component> 3129 
n_bounds 4
bounds -2151 -10 9 2152 
property_list 
material 3
region 3120
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3120
end_property_list 
<component> 3130 
n_bounds 3
bounds -2152 -10 9 
property_list 
material 4
region 3121
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3121
end_property_list 
<component> 3131 
n_bounds 7
bounds 2118 42 9 2153 -45 -11 -10 
property_list 
material 2
region 3122
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3122
end_property_list 
<component> 3132 
n_bounds 4
bounds -2153 -10 9 2154 
property_list 
material 3
region 3123
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3123
end_property_list 
<component> 3133 
n_bounds 3
bounds -2154 -10 9 
property_list 
material 4
region 3124
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3124
end_property_list 
<component> 3134 
n_bounds 7
bounds 2118 45 9 2155 -48 -11 -10 
property_list 
material 2
region 3125
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3125
end_property_list 
<component> 3135 
n_bounds 4
bounds -2155 -10 9 2156 
property_list 
material 3
region 3126
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3126
end_property_list 
<component> 3136 
n_bounds 3
bounds -2156 -10 9 
property_list 
material 4
region 3127
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3127
end_property_list 
<component> 3137 
n_bounds 7
bounds 2118 48 9 2157 -164 -11 -10 
property_list 
material 2
region 3128
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3128
end_property_list 
<component> 3138 
n_bounds 4
bounds -2157 -10 9 2158 
property_list 
material 3
region 3129
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3129
end_property_list 
<component> 3139 
n_bounds 3
bounds -2158 -10 9 
property_list 
material 4
region 3130
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3130
end_property_list 
<component> 3140 
n_bounds 7
bounds 2118 164 9 2159 -167 -11 -10 
property_list 
material 2
region 3131
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3131
end_property_list 
<component> 3141 
n_bounds 4
bounds -2159 -10 9 2160 
property_list 
material 3
region 3132
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3132
end_property_list 
<component> 3142 
n_bounds 3
bounds -2160 -10 9 
property_list 
material 4
region 3133
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3133
end_property_list 
<component> 3143 
n_bounds 7
bounds 2118 167 9 2161 -12 -11 -10 
property_list 
material 2
region 3134
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3134
end_property_list 
<component> 3144 
n_bounds 4
bounds -2161 -10 9 2162 
property_list 
material 3
region 3135
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3135
end_property_list 
<component> 3145 
n_bounds 3
bounds -2162 -10 9 
property_list 
material 4
region 3136
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3136
end_property_list 
<component> 3146 
n_bounds 7
bounds 616 12 9 2163 -172 -1752 -10 
property_list 
material 2
region 3137
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3137
end_property_list 
<component> 3147 
n_bounds 4
bounds -2163 -10 9 2164 
property_list 
material 3
region 3138
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3138
end_property_list 
<component> 3148 
n_bounds 3
bounds -2164 -10 9 
property_list 
material 4
region 3139
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3139
end_property_list 
<component> 3149 
n_bounds 7
bounds 616 172 9 2165 -175 -1752 -10 
property_list 
material 2
region 3140
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3140
end_property_list 
<component> 3150 
n_bounds 4
bounds -2165 -10 9 2166 
property_list 
material 3
region 3141
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3141
end_property_list 
<component> 3151 
n_bounds 3
bounds -2166 -10 9 
property_list 
material 4
region 3142
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3142
end_property_list 
<component> 3152 
n_bounds 7
bounds 616 175 9 2167 -178 -1752 -10 
property_list 
material 2
region 3143
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3143
end_property_list 
<component> 3153 
n_bounds 4
bounds -2167 -10 9 2168 
property_list 
material 3
region 3144
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3144
end_property_list 
<component> 3154 
n_bounds 3
bounds -2168 -10 9 
property_list 
material 4
region 3145
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3145
end_property_list 
<component> 3155 
n_bounds 7
bounds 616 178 9 2169 -181 -1752 -10 
property_list 
material 2
region 3146
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3146
end_property_list 
<component> 3156 
n_bounds 4
bounds -2169 -10 9 2170 
property_list 
material 3
region 3147
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3147
end_property_list 
<component> 3157 
n_bounds 3
bounds -2170 -10 9 
property_list 
material 4
region 3148
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3148
end_property_list 
<component> 3158 
n_bounds 7
bounds 616 181 9 2171 -183 -1752 -10 
property_list 
material 2
region 3149
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3149
end_property_list 
<component> 3159 
n_bounds 4
bounds -2171 -10 9 2172 
property_list 
material 3
region 3150
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3150
end_property_list 
<component> 3160 
n_bounds 3
bounds -2172 -10 9 
property_list 
material 4
region 3151
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3151
end_property_list 
<component> 3161 
n_bounds 7
bounds 616 183 9 2173 -185 -1752 -10 
property_list 
material 2
region 3152
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3152
end_property_list 
<component> 3162 
n_bounds 4
bounds -2173 -10 9 2174 
property_list 
material 3
region 3153
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3153
end_property_list 
<component> 3163 
n_bounds 3
bounds -2174 -10 9 
property_list 
material 4
region 3154
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3154
end_property_list 
<component> 3164 
n_bounds 7
bounds 616 185 9 2175 -188 -1752 -10 
property_list 
material 2
region 3155
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3155
end_property_list 
<component> 3165 
n_bounds 4
bounds -2175 -10 9 2176 
property_list 
material 3
region 3156
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3156
end_property_list 
<component> 3166 
n_bounds 3
bounds -2176 -10 9 
property_list 
material 4
region 3157
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3157
end_property_list 
<component> 3167 
n_bounds 7
bounds 616 188 9 2177 -191 -1752 -10 
property_list 
material 2
region 3158
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3158
end_property_list 
<component> 3168 
n_bounds 4
bounds -2177 -10 9 2178 
property_list 
material 3
region 3159
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3159
end_property_list 
<component> 3169 
n_bounds 3
bounds -2178 -10 9 
property_list 
material 4
region 3160
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3160
end_property_list 
<component> 3170 
n_bounds 7
bounds 616 191 9 2179 -194 -1752 -10 
property_list 
material 2
region 3161
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3161
end_property_list 
<component> 3171 
n_bounds 4
bounds -2179 -10 9 2180 
property_list 
material 3
region 3162
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3162
end_property_list 
<component> 3172 
n_bounds 3
bounds -2180 -10 9 
property_list 
material 4
region 3163
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3163
end_property_list 
<component> 3173 
n_bounds 7
bounds 616 194 9 2181 -15 -1752 -10 
property_list 
material 2
region 3164
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3164
end_property_list 
<component> 3174 
n_bounds 4
bounds -2181 -10 9 2182 
property_list 
material 3
region 3165
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3165
end_property_list 
<component> 3175 
n_bounds 3
bounds -2182 -10 9 
property_list 
material 4
region 3166
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3166
end_property_list 
<component> 3176 
n_bounds 7
bounds 1752 12 9 2183 -172 -1775 -10 
property_list 
material 2
region 3167
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3167
end_property_list 
<component> 3177 
n_bounds 4
bounds -2183 -10 9 2184 
property_list 
material 3
region 3168
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3168
end_property_list 
<component> 3178 
n_bounds 3
bounds -2184 -10 9 
property_list 
material 4
region 3169
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3169
end_property_list 
<component> 3179 
n_bounds 7
bounds 1752 172 9 2185 -175 -1775 -10 
property_list 
material 2
region 3170
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3170
end_property_list 
<component> 3180 
n_bounds 4
bounds -2185 -10 9 2186 
property_list 
material 3
region 3171
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3171
end_property_list 
<component> 3181 
n_bounds 3
bounds -2186 -10 9 
property_list 
material 4
region 3172
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3172
end_property_list 
<component> 3182 
n_bounds 7
bounds 1752 175 9 2187 -178 -1775 -10 
property_list 
material 2
region 3173
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3173
end_property_list 
<component> 3183 
n_bounds 4
bounds -2187 -10 9 2188 
property_list 
material 3
region 3174
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3174
end_property_list 
<component> 3184 
n_bounds 3
bounds -2188 -10 9 
property_list 
material 4
region 3175
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3175
end_property_list 
<component> 3185 
n_bounds 7
bounds 1752 178 9 2189 -181 -1775 -10 
property_list 
material 2
region 3176
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3176
end_property_list 
<component> 3186 
n_bounds 4
bounds -2189 -10 9 2190 
property_list 
material 3
region 3177
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3177
end_property_list 
<component> 3187 
n_bounds 3
bounds -2190 -10 9 
property_list 
material 4
region 3178
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3178
end_property_list 
<component> 3188 
n_bounds 7
bounds 1752 181 9 2191 -183 -1775 -10 
property_list 
material 2
region 3179
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3179
end_property_list 
<component> 3189 
n_bounds 4
bounds -2191 -10 9 2192 
property_list 
material 3
region 3180
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3180
end_property_list 
<component> 3190 
n_bounds 3
bounds -2192 -10 9 
property_list 
material 4
region 3181
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3181
end_property_list 
<component> 3191 
n_bounds 7
bounds 1752 183 9 2193 -185 -1775 -10 
property_list 
material 2
region 3182
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3182
end_property_list 
<component> 3192 
n_bounds 4
bounds -2193 -10 9 2194 
property_list 
material 3
region 3183
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3183
end_property_list 
<component> 3193 
n_bounds 3
bounds -2194 -10 9 
property_list 
material 4
region 3184
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3184
end_property_list 
<component> 3194 
n_bounds 7
bounds 1752 185 9 2195 -188 -1775 -10 
property_list 
material 2
region 3185
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3185
end_property_list 
<component> 3195 
n_bounds 4
bounds -2195 -10 9 2196 
property_list 
material 3
region 3186
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3186
end_property_list 
<component> 3196 
n_bounds 3
bounds -2196 -10 9 
property_list 
material 4
region 3187
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3187
end_property_list 
<component> 3197 
n_bounds 7
bounds 1752 188 9 2197 -191 -1775 -10 
property_list 
material 2
region 3188
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3188
end_property_list 
<component> 3198 
n_bounds 4
bounds -2197 -10 9 2198 
property_list 
material 3
region 3189
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3189
end_property_list 
<component> 3199 
n_bounds 3
bounds -2198 -10 9 
property_list 
material 4
region 3190
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3190
end_property_list 
<component> 3200 
n_bounds 7
bounds 1752 191 9 2199 -194 -1775 -10 
property_list 
material 2
region 3191
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3191
end_property_list 
<component> 3201 
n_bounds 4
bounds -2199 -10 9 2200 
property_list 
material 3
region 3192
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3192
end_property_list 
<component> 3202 
n_bounds 3
bounds -2200 -10 9 
property_list 
material 4
region 3193
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3193
end_property_list 
<component> 3203 
n_bounds 7
bounds 1752 194 9 2201 -15 -1775 -10 
property_list 
material 2
region 3194
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3194
end_property_list 
<component> 3204 
n_bounds 4
bounds -2201 -10 9 2202 
property_list 
material 3
region 3195
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3195
end_property_list 
<component> 3205 
n_bounds 3
bounds -2202 -10 9 
property_list 
material 4
region 3196
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3196
end_property_list 
<component> 3206 
n_bounds 7
bounds 1775 12 9 2203 -172 -1798 -10 
property_list 
material 2
region 3197
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3197
end_property_list 
<component> 3207 
n_bounds 4
bounds -2203 -10 9 2204 
property_list 
material 3
region 3198
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3198
end_property_list 
<component> 3208 
n_bounds 3
bounds -2204 -10 9 
property_list 
material 4
region 3199
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3199
end_property_list 
<component> 3209 
n_bounds 7
bounds 1775 172 9 2205 -175 -1798 -10 
property_list 
material 2
region 3200
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3200
end_property_list 
<component> 3210 
n_bounds 4
bounds -2205 -10 9 2206 
property_list 
material 3
region 3201
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3201
end_property_list 
<component> 3211 
n_bounds 3
bounds -2206 -10 9 
property_list 
material 4
region 3202
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3202
end_property_list 
<component> 3212 
n_bounds 7
bounds 1775 175 9 2207 -178 -1798 -10 
property_list 
material 2
region 3203
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3203
end_property_list 
<component> 3213 
n_bounds 4
bounds -2207 -10 9 2208 
property_list 
material 3
region 3204
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3204
end_property_list 
<component> 3214 
n_bounds 3
bounds -2208 -10 9 
property_list 
material 4
region 3205
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3205
end_property_list 
<component> 3215 
n_bounds 7
bounds 1775 178 9 2209 -181 -1798 -10 
property_list 
material 2
region 3206
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3206
end_property_list 
<component> 3216 
n_bounds 4
bounds -2209 -10 9 2210 
property_list 
material 3
region 3207
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3207
end_property_list 
<component> 3217 
n_bounds 3
bounds -2210 -10 9 
property_list 
material 4
region 3208
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3208
end_property_list 
<component> 3218 
n_bounds 7
bounds 1775 181 9 2211 -183 -1798 -10 
property_list 
material 2
region 3209
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3209
end_property_list 
<component> 3219 
n_bounds 4
bounds -2211 -10 9 2212 
property_list 
material 3
region 3210
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3210
end_property_list 
<component> 3220 
n_bounds 3
bounds -2212 -10 9 
property_list 
material 4
region 3211
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3211
end_property_list 
<component> 3221 
n_bounds 7
bounds 1775 183 9 2213 -185 -1798 -10 
property_list 
material 2
region 3212
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3212
end_property_list 
<component> 3222 
n_bounds 4
bounds -2213 -10 9 2214 
property_list 
material 3
region 3213
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3213
end_property_list 
<component> 3223 
n_bounds 3
bounds -2214 -10 9 
property_list 
material 4
region 3214
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3214
end_property_list 
<component> 3224 
n_bounds 7
bounds 1775 185 9 2215 -188 -1798 -10 
property_list 
material 2
region 3215
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3215
end_property_list 
<component> 3225 
n_bounds 4
bounds -2215 -10 9 2216 
property_list 
material 3
region 3216
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3216
end_property_list 
<component> 3226 
n_bounds 3
bounds -2216 -10 9 
property_list 
material 4
region 3217
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3217
end_property_list 
<component> 3227 
n_bounds 7
bounds 1775 188 9 2217 -191 -1798 -10 
property_list 
material 2
region 3218
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3218
end_property_list 
<component> 3228 
n_bounds 4
bounds -2217 -10 9 2218 
property_list 
material 3
region 3219
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3219
end_property_list 
<component> 3229 
n_bounds 3
bounds -2218 -10 9 
property_list 
material 4
region 3220
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3220
end_property_list 
<component> 3230 
n_bounds 7
bounds 1775 191 9 2219 -194 -1798 -10 
property_list 
material 2
region 3221
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3221
end_property_list 
<component> 3231 
n_bounds 4
bounds -2219 -10 9 2220 
property_list 
material 3
region 3222
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3222
end_property_list 
<component> 3232 
n_bounds 3
bounds -2220 -10 9 
property_list 
material 4
region 3223
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3223
end_property_list 
<component> 3233 
n_bounds 7
bounds 1775 194 9 2221 -15 -1798 -10 
property_list 
material 2
region 3224
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3224
end_property_list 
<component> 3234 
n_bounds 4
bounds -2221 -10 9 2222 
property_list 
material 3
region 3225
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3225
end_property_list 
<component> 3235 
n_bounds 3
bounds -2222 -10 9 
property_list 
material 4
region 3226
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3226
end_property_list 
<component> 3236 
n_bounds 7
bounds 1798 12 9 2223 -172 -1821 -10 
property_list 
material 2
region 3227
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3227
end_property_list 
<component> 3237 
n_bounds 4
bounds -2223 -10 9 2224 
property_list 
material 3
region 3228
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3228
end_property_list 
<component> 3238 
n_bounds 3
bounds -2224 -10 9 
property_list 
material 4
region 3229
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3229
end_property_list 
<component> 3239 
n_bounds 7
bounds 1798 172 9 2225 -175 -1821 -10 
property_list 
material 2
region 3230
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3230
end_property_list 
<component> 3240 
n_bounds 4
bounds -2225 -10 9 2226 
property_list 
material 3
region 3231
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3231
end_property_list 
<component> 3241 
n_bounds 3
bounds -2226 -10 9 
property_list 
material 4
region 3232
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3232
end_property_list 
<component> 3242 
n_bounds 7
bounds 1798 175 9 2227 -178 -1821 -10 
property_list 
material 2
region 3233
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3233
end_property_list 
<component> 3243 
n_bounds 4
bounds -2227 -10 9 2228 
property_list 
material 3
region 3234
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3234
end_property_list 
<component> 3244 
n_bounds 3
bounds -2228 -10 9 
property_list 
material 4
region 3235
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3235
end_property_list 
<component> 3245 
n_bounds 7
bounds 1798 178 9 2229 -181 -1821 -10 
property_list 
material 2
region 3236
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3236
end_property_list 
<component> 3246 
n_bounds 4
bounds -2229 -10 9 2230 
property_list 
material 3
region 3237
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3237
end_property_list 
<component> 3247 
n_bounds 3
bounds -2230 -10 9 
property_list 
material 4
region 3238
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3238
end_property_list 
<component> 3248 
n_bounds 7
bounds 1798 181 9 2231 -183 -1821 -10 
property_list 
material 2
region 3239
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3239
end_property_list 
<component> 3249 
n_bounds 4
bounds -2231 -10 9 2232 
property_list 
material 3
region 3240
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3240
end_property_list 
<component> 3250 
n_bounds 3
bounds -2232 -10 9 
property_list 
material 4
region 3241
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3241
end_property_list 
<component> 3251 
n_bounds 7
bounds 1798 183 9 2233 -185 -1821 -10 
property_list 
material 2
region 3242
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3242
end_property_list 
<component> 3252 
n_bounds 4
bounds -2233 -10 9 2234 
property_list 
material 3
region 3243
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3243
end_property_list 
<component> 3253 
n_bounds 3
bounds -2234 -10 9 
property_list 
material 4
region 3244
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3244
end_property_list 
<component> 3254 
n_bounds 7
bounds 1798 185 9 2235 -188 -1821 -10 
property_list 
material 2
region 3245
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3245
end_property_list 
<component> 3255 
n_bounds 4
bounds -2235 -10 9 2236 
property_list 
material 3
region 3246
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3246
end_property_list 
<component> 3256 
n_bounds 3
bounds -2236 -10 9 
property_list 
material 4
region 3247
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3247
end_property_list 
<component> 3257 
n_bounds 7
bounds 1798 188 9 2237 -191 -1821 -10 
property_list 
material 2
region 3248
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3248
end_property_list 
<component> 3258 
n_bounds 4
bounds -2237 -10 9 2238 
property_list 
material 3
region 3249
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3249
end_property_list 
<component> 3259 
n_bounds 3
bounds -2238 -10 9 
property_list 
material 4
region 3250
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3250
end_property_list 
<component> 3260 
n_bounds 7
bounds 1798 191 9 2239 -194 -1821 -10 
property_list 
material 2
region 3251
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3251
end_property_list 
<component> 3261 
n_bounds 4
bounds -2239 -10 9 2240 
property_list 
material 3
region 3252
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3252
end_property_list 
<component> 3262 
n_bounds 3
bounds -2240 -10 9 
property_list 
material 4
region 3253
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3253
end_property_list 
<component> 3263 
n_bounds 7
bounds 1798 194 9 2241 -15 -1821 -10 
property_list 
material 2
region 3254
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3254
end_property_list 
<component> 3264 
n_bounds 4
bounds -2241 -10 9 2242 
property_list 
material 3
region 3255
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3255
end_property_list 
<component> 3265 
n_bounds 3
bounds -2242 -10 9 
property_list 
material 4
region 3256
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3256
end_property_list 
<component> 3266 
n_bounds 7
bounds 1821 12 9 2243 -172 -1844 -10 
property_list 
material 2
region 3257
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3257
end_property_list 
<component> 3267 
n_bounds 4
bounds -2243 -10 9 2244 
property_list 
material 3
region 3258
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3258
end_property_list 
<component> 3268 
n_bounds 3
bounds -2244 -10 9 
property_list 
material 4
region 3259
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3259
end_property_list 
<component> 3269 
n_bounds 7
bounds 1821 172 9 2245 -175 -1844 -10 
property_list 
material 2
region 3260
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3260
end_property_list 
<component> 3270 
n_bounds 4
bounds -2245 -10 9 2246 
property_list 
material 3
region 3261
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3261
end_property_list 
<component> 3271 
n_bounds 3
bounds -2246 -10 9 
property_list 
material 4
region 3262
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3262
end_property_list 
<component> 3272 
n_bounds 7
bounds 1821 175 9 2247 -178 -1844 -10 
property_list 
material 2
region 3263
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3263
end_property_list 
<component> 3273 
n_bounds 4
bounds -2247 -10 9 2248 
property_list 
material 3
region 3264
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3264
end_property_list 
<component> 3274 
n_bounds 3
bounds -2248 -10 9 
property_list 
material 4
region 3265
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3265
end_property_list 
<component> 3275 
n_bounds 7
bounds 1821 178 9 2249 -181 -1844 -10 
property_list 
material 2
region 3266
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3266
end_property_list 
<component> 3276 
n_bounds 4
bounds -2249 -10 9 2250 
property_list 
material 3
region 3267
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3267
end_property_list 
<component> 3277 
n_bounds 3
bounds -2250 -10 9 
property_list 
material 4
region 3268
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3268
end_property_list 
<component> 3278 
n_bounds 7
bounds 1821 181 9 2251 -183 -1844 -10 
property_list 
material 2
region 3269
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3269
end_property_list 
<component> 3279 
n_bounds 4
bounds -2251 -10 9 2252 
property_list 
material 3
region 3270
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3270
end_property_list 
<component> 3280 
n_bounds 3
bounds -2252 -10 9 
property_list 
material 4
region 3271
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3271
end_property_list 
<component> 3281 
n_bounds 7
bounds 1821 183 9 2253 -185 -1844 -10 
property_list 
material 2
region 3272
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3272
end_property_list 
<component> 3282 
n_bounds 4
bounds -2253 -10 9 2254 
property_list 
material 3
region 3273
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3273
end_property_list 
<component> 3283 
n_bounds 3
bounds -2254 -10 9 
property_list 
material 4
region 3274
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3274
end_property_list 
<component> 3284 
n_bounds 7
bounds 1821 185 9 2255 -188 -1844 -10 
property_list 
material 2
region 3275
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3275
end_property_list 
<component> 3285 
n_bounds 4
bounds -2255 -10 9 2256 
property_list 
material 3
region 3276
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3276
end_property_list 
<component> 3286 
n_bounds 3
bounds -2256 -10 9 
property_list 
material 4
region 3277
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3277
end_property_list 
<component> 3287 
n_bounds 7
bounds 1821 188 9 2257 -191 -1844 -10 
property_list 
material 2
region 3278
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3278
end_property_list 
<component> 3288 
n_bounds 4
bounds -2257 -10 9 2258 
property_list 
material 3
region 3279
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3279
end_property_list 
<component> 3289 
n_bounds 3
bounds -2258 -10 9 
property_list 
material 4
region 3280
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3280
end_property_list 
<component> 3290 
n_bounds 7
bounds 1821 191 9 2259 -194 -1844 -10 
property_list 
material 2
region 3281
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3281
end_property_list 
<component> 3291 
n_bounds 4
bounds -2259 -10 9 2260 
property_list 
material 3
region 3282
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3282
end_property_list 
<component> 3292 
n_bounds 3
bounds -2260 -10 9 
property_list 
material 4
region 3283
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3283
end_property_list 
<component> 3293 
n_bounds 7
bounds 1821 194 9 2261 -15 -1844 -10 
property_list 
material 2
region 3284
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3284
end_property_list 
<component> 3294 
n_bounds 4
bounds -2261 -10 9 2262 
property_list 
material 3
region 3285
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3285
end_property_list 
<component> 3295 
n_bounds 3
bounds -2262 -10 9 
property_list 
material 4
region 3286
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3286
end_property_list 
<component> 3296 
n_bounds 7
bounds 1844 12 9 2263 -172 -1867 -10 
property_list 
material 2
region 3287
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3287
end_property_list 
<component> 3297 
n_bounds 4
bounds -2263 -10 9 2264 
property_list 
material 3
region 3288
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3288
end_property_list 
<component> 3298 
n_bounds 3
bounds -2264 -10 9 
property_list 
material 4
region 3289
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3289
end_property_list 
<component> 3299 
n_bounds 7
bounds 1844 172 9 2265 -175 -1867 -10 
property_list 
material 2
region 3290
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3290
end_property_list 
<component> 3300 
n_bounds 4
bounds -2265 -10 9 2266 
property_list 
material 3
region 3291
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3291
end_property_list 
<component> 3301 
n_bounds 3
bounds -2266 -10 9 
property_list 
material 4
region 3292
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3292
end_property_list 
<component> 3302 
n_bounds 7
bounds 1844 175 9 2267 -178 -1867 -10 
property_list 
material 2
region 3293
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3293
end_property_list 
<component> 3303 
n_bounds 4
bounds -2267 -10 9 2268 
property_list 
material 3
region 3294
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3294
end_property_list 
<component> 3304 
n_bounds 3
bounds -2268 -10 9 
property_list 
material 4
region 3295
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3295
end_property_list 
<component> 3305 
n_bounds 7
bounds 1844 178 9 2269 -181 -1867 -10 
property_list 
material 2
region 3296
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3296
end_property_list 
<component> 3306 
n_bounds 4
bounds -2269 -10 9 2270 
property_list 
material 3
region 3297
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3297
end_property_list 
<component> 3307 
n_bounds 3
bounds -2270 -10 9 
property_list 
material 4
region 3298
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3298
end_property_list 
<component> 3308 
n_bounds 7
bounds 1844 181 9 2271 -183 -1867 -10 
property_list 
material 2
region 3299
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3299
end_property_list 
<component> 3309 
n_bounds 4
bounds -2271 -10 9 2272 
property_list 
material 3
region 3300
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3300
end_property_list 
<component> 3310 
n_bounds 3
bounds -2272 -10 9 
property_list 
material 4
region 3301
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3301
end_property_list 
<component> 3311 
n_bounds 7
bounds 1844 183 9 2273 -185 -1867 -10 
property_list 
material 2
region 3302
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3302
end_property_list 
<component> 3312 
n_bounds 4
bounds -2273 -10 9 2274 
property_list 
material 3
region 3303
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3303
end_property_list 
<component> 3313 
n_bounds 3
bounds -2274 -10 9 
property_list 
material 4
region 3304
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3304
end_property_list 
<component> 3314 
n_bounds 7
bounds 1844 185 9 2275 -188 -1867 -10 
property_list 
material 2
region 3305
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3305
end_property_list 
<component> 3315 
n_bounds 4
bounds -2275 -10 9 2276 
property_list 
material 3
region 3306
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3306
end_property_list 
<component> 3316 
n_bounds 3
bounds -2276 -10 9 
property_list 
material 4
region 3307
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3307
end_property_list 
<component> 3317 
n_bounds 7
bounds 1844 188 9 2277 -191 -1867 -10 
property_list 
material 2
region 3308
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3308
end_property_list 
<component> 3318 
n_bounds 4
bounds -2277 -10 9 2278 
property_list 
material 3
region 3309
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3309
end_property_list 
<component> 3319 
n_bounds 3
bounds -2278 -10 9 
property_list 
material 4
region 3310
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3310
end_property_list 
<component> 3320 
n_bounds 7
bounds 1844 191 9 2279 -194 -1867 -10 
property_list 
material 2
region 3311
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3311
end_property_list 
<component> 3321 
n_bounds 4
bounds -2279 -10 9 2280 
property_list 
material 3
region 3312
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3312
end_property_list 
<component> 3322 
n_bounds 3
bounds -2280 -10 9 
property_list 
material 4
region 3313
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3313
end_property_list 
<component> 3323 
n_bounds 7
bounds 1844 194 9 2281 -15 -1867 -10 
property_list 
material 2
region 3314
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3314
end_property_list 
<component> 3324 
n_bounds 4
bounds -2281 -10 9 2282 
property_list 
material 3
region 3315
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3315
end_property_list 
<component> 3325 
n_bounds 3
bounds -2282 -10 9 
property_list 
material 4
region 3316
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3316
end_property_list 
<component> 3326 
n_bounds 7
bounds 1867 12 9 2283 -172 -1890 -10 
property_list 
material 2
region 3317
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3317
end_property_list 
<component> 3327 
n_bounds 4
bounds -2283 -10 9 2284 
property_list 
material 3
region 3318
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3318
end_property_list 
<component> 3328 
n_bounds 3
bounds -2284 -10 9 
property_list 
material 4
region 3319
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3319
end_property_list 
<component> 3329 
n_bounds 7
bounds 1867 172 9 2285 -175 -1890 -10 
property_list 
material 2
region 3320
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3320
end_property_list 
<component> 3330 
n_bounds 4
bounds -2285 -10 9 2286 
property_list 
material 3
region 3321
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3321
end_property_list 
<component> 3331 
n_bounds 3
bounds -2286 -10 9 
property_list 
material 4
region 3322
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3322
end_property_list 
<component> 3332 
n_bounds 7
bounds 1867 175 9 2287 -178 -1890 -10 
property_list 
material 2
region 3323
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3323
end_property_list 
<component> 3333 
n_bounds 4
bounds -2287 -10 9 2288 
property_list 
material 3
region 3324
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3324
end_property_list 
<component> 3334 
n_bounds 3
bounds -2288 -10 9 
property_list 
material 4
region 3325
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3325
end_property_list 
<component> 3335 
n_bounds 7
bounds 1867 178 9 2289 -181 -1890 -10 
property_list 
material 2
region 3326
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3326
end_property_list 
<component> 3336 
n_bounds 4
bounds -2289 -10 9 2290 
property_list 
material 3
region 3327
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3327
end_property_list 
<component> 3337 
n_bounds 3
bounds -2290 -10 9 
property_list 
material 4
region 3328
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3328
end_property_list 
<component> 3338 
n_bounds 7
bounds 1867 181 9 2291 -183 -1890 -10 
property_list 
material 2
region 3329
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3329
end_property_list 
<component> 3339 
n_bounds 4
bounds -2291 -10 9 2292 
property_list 
material 3
region 3330
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3330
end_property_list 
<component> 3340 
n_bounds 3
bounds -2292 -10 9 
property_list 
material 4
region 3331
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3331
end_property_list 
<component> 3341 
n_bounds 7
bounds 1867 183 9 2293 -185 -1890 -10 
property_list 
material 2
region 3332
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3332
end_property_list 
<component> 3342 
n_bounds 4
bounds -2293 -10 9 2294 
property_list 
material 3
region 3333
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3333
end_property_list 
<component> 3343 
n_bounds 3
bounds -2294 -10 9 
property_list 
material 4
region 3334
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3334
end_property_list 
<component> 3344 
n_bounds 7
bounds 1867 185 9 2295 -188 -1890 -10 
property_list 
material 2
region 3335
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3335
end_property_list 
<component> 3345 
n_bounds 4
bounds -2295 -10 9 2296 
property_list 
material 3
region 3336
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3336
end_property_list 
<component> 3346 
n_bounds 3
bounds -2296 -10 9 
property_list 
material 4
region 3337
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3337
end_property_list 
<component> 3347 
n_bounds 7
bounds 1867 188 9 2297 -191 -1890 -10 
property_list 
material 2
region 3338
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3338
end_property_list 
<component> 3348 
n_bounds 4
bounds -2297 -10 9 2298 
property_list 
material 3
region 3339
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3339
end_property_list 
<component> 3349 
n_bounds 3
bounds -2298 -10 9 
property_list 
material 4
region 3340
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3340
end_property_list 
<component> 3350 
n_bounds 7
bounds 1867 191 9 2299 -194 -1890 -10 
property_list 
material 2
region 3341
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3341
end_property_list 
<component> 3351 
n_bounds 4
bounds -2299 -10 9 2300 
property_list 
material 3
region 3342
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3342
end_property_list 
<component> 3352 
n_bounds 3
bounds -2300 -10 9 
property_list 
material 4
region 3343
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3343
end_property_list 
<component> 3353 
n_bounds 7
bounds 1867 194 9 2301 -15 -1890 -10 
property_list 
material 2
region 3344
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3344
end_property_list 
<component> 3354 
n_bounds 4
bounds -2301 -10 9 2302 
property_list 
material 3
region 3345
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3345
end_property_list 
<component> 3355 
n_bounds 3
bounds -2302 -10 9 
property_list 
material 4
region 3346
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3346
end_property_list 
<component> 3356 
n_bounds 7
bounds 1890 12 9 2303 -172 -16 -10 
property_list 
material 2
region 3347
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3347
end_property_list 
<component> 3357 
n_bounds 4
bounds -2303 -10 9 2304 
property_list 
material 3
region 3348
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3348
end_property_list 
<component> 3358 
n_bounds 3
bounds -2304 -10 9 
property_list 
material 4
region 3349
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3349
end_property_list 
<component> 3359 
n_bounds 7
bounds 1890 172 9 2305 -175 -16 -10 
property_list 
material 2
region 3350
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3350
end_property_list 
<component> 3360 
n_bounds 4
bounds -2305 -10 9 2306 
property_list 
material 3
region 3351
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3351
end_property_list 
<component> 3361 
n_bounds 3
bounds -2306 -10 9 
property_list 
material 4
region 3352
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3352
end_property_list 
<component> 3362 
n_bounds 7
bounds 1890 175 9 2307 -178 -16 -10 
property_list 
material 2
region 3353
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3353
end_property_list 
<component> 3363 
n_bounds 4
bounds -2307 -10 9 2308 
property_list 
material 3
region 3354
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3354
end_property_list 
<component> 3364 
n_bounds 3
bounds -2308 -10 9 
property_list 
material 4
region 3355
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3355
end_property_list 
<component> 3365 
n_bounds 7
bounds 1890 178 9 2309 -181 -16 -10 
property_list 
material 2
region 3356
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3356
end_property_list 
<component> 3366 
n_bounds 4
bounds -2309 -10 9 2310 
property_list 
material 3
region 3357
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3357
end_property_list 
<component> 3367 
n_bounds 3
bounds -2310 -10 9 
property_list 
material 4
region 3358
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3358
end_property_list 
<component> 3368 
n_bounds 7
bounds 1890 181 9 2311 -183 -16 -10 
property_list 
material 2
region 3359
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3359
end_property_list 
<component> 3369 
n_bounds 4
bounds -2311 -10 9 2312 
property_list 
material 3
region 3360
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3360
end_property_list 
<component> 3370 
n_bounds 3
bounds -2312 -10 9 
property_list 
material 4
region 3361
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3361
end_property_list 
<component> 3371 
n_bounds 7
bounds 1890 183 9 2313 -185 -16 -10 
property_list 
material 2
region 3362
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3362
end_property_list 
<component> 3372 
n_bounds 4
bounds -2313 -10 9 2314 
property_list 
material 3
region 3363
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3363
end_property_list 
<component> 3373 
n_bounds 3
bounds -2314 -10 9 
property_list 
material 4
region 3364
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3364
end_property_list 
<component> 3374 
n_bounds 7
bounds 1890 185 9 2315 -188 -16 -10 
property_list 
material 2
region 3365
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3365
end_property_list 
<component> 3375 
n_bounds 4
bounds -2315 -10 9 2316 
property_list 
material 3
region 3366
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3366
end_property_list 
<component> 3376 
n_bounds 3
bounds -2316 -10 9 
property_list 
material 4
region 3367
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3367
end_property_list 
<component> 3377 
n_bounds 7
bounds 1890 188 9 2317 -191 -16 -10 
property_list 
material 2
region 3368
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3368
end_property_list 
<component> 3378 
n_bounds 4
bounds -2317 -10 9 2318 
property_list 
material 3
region 3369
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3369
end_property_list 
<component> 3379 
n_bounds 3
bounds -2318 -10 9 
property_list 
material 4
region 3370
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3370
end_property_list 
<component> 3380 
n_bounds 7
bounds 1890 191 9 2319 -194 -16 -10 
property_list 
material 2
region 3371
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3371
end_property_list 
<component> 3381 
n_bounds 4
bounds -2319 -10 9 2320 
property_list 
material 3
region 3372
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3372
end_property_list 
<component> 3382 
n_bounds 3
bounds -2320 -10 9 
property_list 
material 4
region 3373
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3373
end_property_list 
<component> 3383 
n_bounds 7
bounds 1890 194 9 2321 -15 -16 -10 
property_list 
material 2
region 3374
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3374
end_property_list 
<component> 3384 
n_bounds 4
bounds -2321 -10 9 2322 
property_list 
material 3
region 3375
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3375
end_property_list 
<component> 3385 
n_bounds 3
bounds -2322 -10 9 
property_list 
material 4
region 3376
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3376
end_property_list 
<component> 3386 
n_bounds 7
bounds 16 12 9 2323 -172 -1935 -10 
property_list 
material 2
region 3377
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3377
end_property_list 
<component> 3387 
n_bounds 4
bounds -2323 -10 9 2324 
property_list 
material 3
region 3378
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3378
end_property_list 
<component> 3388 
n_bounds 3
bounds -2324 -10 9 
property_list 
material 4
region 3379
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3379
end_property_list 
<component> 3389 
n_bounds 7
bounds 16 172 9 2325 -175 -1935 -10 
property_list 
material 2
region 3380
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3380
end_property_list 
<component> 3390 
n_bounds 4
bounds -2325 -10 9 2326 
property_list 
material 3
region 3381
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3381
end_property_list 
<component> 3391 
n_bounds 3
bounds -2326 -10 9 
property_list 
material 4
region 3382
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3382
end_property_list 
<component> 3392 
n_bounds 7
bounds 16 175 9 2327 -178 -1935 -10 
property_list 
material 2
region 3383
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3383
end_property_list 
<component> 3393 
n_bounds 4
bounds -2327 -10 9 2328 
property_list 
material 3
region 3384
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3384
end_property_list 
<component> 3394 
n_bounds 3
bounds -2328 -10 9 
property_list 
material 4
region 3385
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3385
end_property_list 
<component> 3395 
n_bounds 7
bounds 16 178 9 2329 -181 -1935 -10 
property_list 
material 2
region 3386
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3386
end_property_list 
<component> 3396 
n_bounds 4
bounds -2329 -10 9 2330 
property_list 
material 3
region 3387
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3387
end_property_list 
<component> 3397 
n_bounds 3
bounds -2330 -10 9 
property_list 
material 4
region 3388
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3388
end_property_list 
<component> 3398 
n_bounds 7
bounds 16 181 9 2331 -183 -1935 -10 
property_list 
material 2
region 3389
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3389
end_property_list 
<component> 3399 
n_bounds 4
bounds -2331 -10 9 2332 
property_list 
material 3
region 3390
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3390
end_property_list 
<component> 3400 
n_bounds 3
bounds -2332 -10 9 
property_list 
material 4
region 3391
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3391
end_property_list 
<component> 3401 
n_bounds 7
bounds 16 183 9 2333 -185 -1935 -10 
property_list 
material 2
region 3392
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3392
end_property_list 
<component> 3402 
n_bounds 4
bounds -2333 -10 9 2334 
property_list 
material 3
region 3393
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3393
end_property_list 
<component> 3403 
n_bounds 3
bounds -2334 -10 9 
property_list 
material 4
region 3394
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3394
end_property_list 
<component> 3404 
n_bounds 7
bounds 16 185 9 2335 -188 -1935 -10 
property_list 
material 2
region 3395
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3395
end_property_list 
<component> 3405 
n_bounds 4
bounds -2335 -10 9 2336 
property_list 
material 3
region 3396
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3396
end_property_list 
<component> 3406 
n_bounds 3
bounds -2336 -10 9 
property_list 
material 4
region 3397
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3397
end_property_list 
<component> 3407 
n_bounds 7
bounds 16 188 9 2337 -191 -1935 -10 
property_list 
material 2
region 3398
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3398
end_property_list 
<component> 3408 
n_bounds 4
bounds -2337 -10 9 2338 
property_list 
material 3
region 3399
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3399
end_property_list 
<component> 3409 
n_bounds 3
bounds -2338 -10 9 
property_list 
material 4
region 3400
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3400
end_property_list 
<component> 3410 
n_bounds 7
bounds 16 191 9 2339 -194 -1935 -10 
property_list 
material 2
region 3401
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3401
end_property_list 
<component> 3411 
n_bounds 4
bounds -2339 -10 9 2340 
property_list 
material 3
region 3402
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3402
end_property_list 
<component> 3412 
n_bounds 3
bounds -2340 -10 9 
property_list 
material 4
region 3403
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3403
end_property_list 
<component> 3413 
n_bounds 7
bounds 16 194 9 2341 -15 -1935 -10 
property_list 
material 2
region 3404
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3404
end_property_list 
<component> 3414 
n_bounds 4
bounds -2341 -10 9 2342 
property_list 
material 3
region 3405
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3405
end_property_list 
<component> 3415 
n_bounds 3
bounds -2342 -10 9 
property_list 
material 4
region 3406
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3406
end_property_list 
<component> 3416 
n_bounds 7
bounds 1935 12 9 2343 -172 -1958 -10 
property_list 
material 2
region 3407
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3407
end_property_list 
<component> 3417 
n_bounds 4
bounds -2343 -10 9 2344 
property_list 
material 3
region 3408
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3408
end_property_list 
<component> 3418 
n_bounds 3
bounds -2344 -10 9 
property_list 
material 4
region 3409
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3409
end_property_list 
<component> 3419 
n_bounds 7
bounds 1935 172 9 2345 -175 -1958 -10 
property_list 
material 2
region 3410
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3410
end_property_list 
<component> 3420 
n_bounds 4
bounds -2345 -10 9 2346 
property_list 
material 3
region 3411
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3411
end_property_list 
<component> 3421 
n_bounds 3
bounds -2346 -10 9 
property_list 
material 4
region 3412
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3412
end_property_list 
<component> 3422 
n_bounds 7
bounds 1935 175 9 2347 -178 -1958 -10 
property_list 
material 2
region 3413
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3413
end_property_list 
<component> 3423 
n_bounds 4
bounds -2347 -10 9 2348 
property_list 
material 3
region 3414
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3414
end_property_list 
<component> 3424 
n_bounds 3
bounds -2348 -10 9 
property_list 
material 4
region 3415
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3415
end_property_list 
<component> 3425 
n_bounds 7
bounds 1935 178 9 2349 -181 -1958 -10 
property_list 
material 2
region 3416
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3416
end_property_list 
<component> 3426 
n_bounds 4
bounds -2349 -10 9 2350 
property_list 
material 3
region 3417
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3417
end_property_list 
<component> 3427 
n_bounds 3
bounds -2350 -10 9 
property_list 
material 4
region 3418
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3418
end_property_list 
<component> 3428 
n_bounds 7
bounds 1935 181 9 2351 -183 -1958 -10 
property_list 
material 2
region 3419
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3419
end_property_list 
<component> 3429 
n_bounds 4
bounds -2351 -10 9 2352 
property_list 
material 3
region 3420
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3420
end_property_list 
<component> 3430 
n_bounds 3
bounds -2352 -10 9 
property_list 
material 4
region 3421
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3421
end_property_list 
<component> 3431 
n_bounds 7
bounds 1935 183 9 2353 -185 -1958 -10 
property_list 
material 2
region 3422
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3422
end_property_list 
<component> 3432 
n_bounds 4
bounds -2353 -10 9 2354 
property_list 
material 3
region 3423
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3423
end_property_list 
<component> 3433 
n_bounds 3
bounds -2354 -10 9 
property_list 
material 4
region 3424
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3424
end_property_list 
<component> 3434 
n_bounds 7
bounds 1935 185 9 2355 -188 -1958 -10 
property_list 
material 2
region 3425
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3425
end_property_list 
<component> 3435 
n_bounds 4
bounds -2355 -10 9 2356 
property_list 
material 3
region 3426
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3426
end_property_list 
<component> 3436 
n_bounds 3
bounds -2356 -10 9 
property_list 
material 4
region 3427
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3427
end_property_list 
<component> 3437 
n_bounds 7
bounds 1935 188 9 2357 -191 -1958 -10 
property_list 
material 2
region 3428
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3428
end_property_list 
<component> 3438 
n_bounds 4
bounds -2357 -10 9 2358 
property_list 
material 3
region 3429
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3429
end_property_list 
<component> 3439 
n_bounds 3
bounds -2358 -10 9 
property_list 
material 4
region 3430
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3430
end_property_list 
<component> 3440 
n_bounds 7
bounds 1935 191 9 2359 -194 -1958 -10 
property_list 
material 2
region 3431
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3431
end_property_list 
<component> 3441 
n_bounds 4
bounds -2359 -10 9 2360 
property_list 
material 3
region 3432
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3432
end_property_list 
<component> 3442 
n_bounds 3
bounds -2360 -10 9 
property_list 
material 4
region 3433
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3433
end_property_list 
<component> 3443 
n_bounds 7
bounds 1935 194 9 2361 -15 -1958 -10 
property_list 
material 2
region 3434
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3434
end_property_list 
<component> 3444 
n_bounds 4
bounds -2361 -10 9 2362 
property_list 
material 3
region 3435
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3435
end_property_list 
<component> 3445 
n_bounds 3
bounds -2362 -10 9 
property_list 
material 4
region 3436
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3436
end_property_list 
<component> 3446 
n_bounds 7
bounds 1958 12 9 2363 -172 -1981 -10 
property_list 
material 2
region 3437
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3437
end_property_list 
<component> 3447 
n_bounds 4
bounds -2363 -10 9 2364 
property_list 
material 3
region 3438
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3438
end_property_list 
<component> 3448 
n_bounds 3
bounds -2364 -10 9 
property_list 
material 4
region 3439
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3439
end_property_list 
<component> 3449 
n_bounds 7
bounds 1958 172 9 2365 -175 -1981 -10 
property_list 
material 2
region 3440
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3440
end_property_list 
<component> 3450 
n_bounds 4
bounds -2365 -10 9 2366 
property_list 
material 3
region 3441
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3441
end_property_list 
<component> 3451 
n_bounds 3
bounds -2366 -10 9 
property_list 
material 4
region 3442
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3442
end_property_list 
<component> 3452 
n_bounds 7
bounds 1958 175 9 2367 -178 -1981 -10 
property_list 
material 2
region 3443
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3443
end_property_list 
<component> 3453 
n_bounds 4
bounds -2367 -10 9 2368 
property_list 
material 3
region 3444
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3444
end_property_list 
<component> 3454 
n_bounds 3
bounds -2368 -10 9 
property_list 
material 4
region 3445
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3445
end_property_list 
<component> 3455 
n_bounds 7
bounds 1958 178 9 2369 -181 -1981 -10 
property_list 
material 2
region 3446
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3446
end_property_list 
<component> 3456 
n_bounds 4
bounds -2369 -10 9 2370 
property_list 
material 3
region 3447
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3447
end_property_list 
<component> 3457 
n_bounds 3
bounds -2370 -10 9 
property_list 
material 4
region 3448
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3448
end_property_list 
<component> 3458 
n_bounds 7
bounds 1958 181 9 2371 -183 -1981 -10 
property_list 
material 2
region 3449
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3449
end_property_list 
<component> 3459 
n_bounds 4
bounds -2371 -10 9 2372 
property_list 
material 3
region 3450
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3450
end_property_list 
<component> 3460 
n_bounds 3
bounds -2372 -10 9 
property_list 
material 4
region 3451
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3451
end_property_list 
<component> 3461 
n_bounds 7
bounds 1958 183 9 2373 -185 -1981 -10 
property_list 
material 2
region 3452
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3452
end_property_list 
<component> 3462 
n_bounds 4
bounds -2373 -10 9 2374 
property_list 
material 3
region 3453
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3453
end_property_list 
<component> 3463 
n_bounds 3
bounds -2374 -10 9 
property_list 
material 4
region 3454
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3454
end_property_list 
<component> 3464 
n_bounds 7
bounds 1958 185 9 2375 -188 -1981 -10 
property_list 
material 2
region 3455
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3455
end_property_list 
<component> 3465 
n_bounds 4
bounds -2375 -10 9 2376 
property_list 
material 3
region 3456
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3456
end_property_list 
<component> 3466 
n_bounds 3
bounds -2376 -10 9 
property_list 
material 4
region 3457
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3457
end_property_list 
<component> 3467 
n_bounds 7
bounds 1958 188 9 2377 -191 -1981 -10 
property_list 
material 2
region 3458
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3458
end_property_list 
<component> 3468 
n_bounds 4
bounds -2377 -10 9 2378 
property_list 
material 3
region 3459
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3459
end_property_list 
<component> 3469 
n_bounds 3
bounds -2378 -10 9 
property_list 
material 4
region 3460
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3460
end_property_list 
<component> 3470 
n_bounds 7
bounds 1958 191 9 2379 -194 -1981 -10 
property_list 
material 2
region 3461
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3461
end_property_list 
<component> 3471 
n_bounds 4
bounds -2379 -10 9 2380 
property_list 
material 3
region 3462
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3462
end_property_list 
<component> 3472 
n_bounds 3
bounds -2380 -10 9 
property_list 
material 4
region 3463
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3463
end_property_list 
<component> 3473 
n_bounds 7
bounds 1958 194 9 2381 -15 -1981 -10 
property_list 
material 2
region 3464
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3464
end_property_list 
<component> 3474 
n_bounds 4
bounds -2381 -10 9 2382 
property_list 
material 3
region 3465
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3465
end_property_list 
<component> 3475 
n_bounds 3
bounds -2382 -10 9 
property_list 
material 4
region 3466
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3466
end_property_list 
<component> 3476 
n_bounds 7
bounds 1981 12 9 2383 -172 -2004 -10 
property_list 
material 2
region 3467
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3467
end_property_list 
<component> 3477 
n_bounds 4
bounds -2383 -10 9 2384 
property_list 
material 3
region 3468
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3468
end_property_list 
<component> 3478 
n_bounds 3
bounds -2384 -10 9 
property_list 
material 4
region 3469
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3469
end_property_list 
<component> 3479 
n_bounds 7
bounds 1981 172 9 2385 -175 -2004 -10 
property_list 
material 2
region 3470
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3470
end_property_list 
<component> 3480 
n_bounds 4
bounds -2385 -10 9 2386 
property_list 
material 3
region 3471
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3471
end_property_list 
<component> 3481 
n_bounds 3
bounds -2386 -10 9 
property_list 
material 4
region 3472
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3472
end_property_list 
<component> 3482 
n_bounds 7
bounds 1981 175 9 2387 -178 -2004 -10 
property_list 
material 2
region 3473
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3473
end_property_list 
<component> 3483 
n_bounds 4
bounds -2387 -10 9 2388 
property_list 
material 3
region 3474
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3474
end_property_list 
<component> 3484 
n_bounds 3
bounds -2388 -10 9 
property_list 
material 4
region 3475
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3475
end_property_list 
<component> 3485 
n_bounds 7
bounds 1981 178 9 2389 -181 -2004 -10 
property_list 
material 2
region 3476
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3476
end_property_list 
<component> 3486 
n_bounds 4
bounds -2389 -10 9 2390 
property_list 
material 3
region 3477
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3477
end_property_list 
<component> 3487 
n_bounds 3
bounds -2390 -10 9 
property_list 
material 4
region 3478
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3478
end_property_list 
<component> 3488 
n_bounds 7
bounds 1981 181 9 2391 -183 -2004 -10 
property_list 
material 2
region 3479
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3479
end_property_list 
<component> 3489 
n_bounds 4
bounds -2391 -10 9 2392 
property_list 
material 3
region 3480
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3480
end_property_list 
<component> 3490 
n_bounds 3
bounds -2392 -10 9 
property_list 
material 4
region 3481
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3481
end_property_list 
<component> 3491 
n_bounds 7
bounds 1981 183 9 2393 -185 -2004 -10 
property_list 
material 2
region 3482
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3482
end_property_list 
<component> 3492 
n_bounds 4
bounds -2393 -10 9 2394 
property_list 
material 3
region 3483
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3483
end_property_list 
<component> 3493 
n_bounds 3
bounds -2394 -10 9 
property_list 
material 4
region 3484
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3484
end_property_list 
<component> 3494 
n_bounds 7
bounds 1981 185 9 2395 -188 -2004 -10 
property_list 
material 2
region 3485
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3485
end_property_list 
<component> 3495 
n_bounds 4
bounds -2395 -10 9 2396 
property_list 
material 3
region 3486
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3486
end_property_list 
<component> 3496 
n_bounds 3
bounds -2396 -10 9 
property_list 
material 4
region 3487
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3487
end_property_list 
<component> 3497 
n_bounds 7
bounds 1981 188 9 2397 -191 -2004 -10 
property_list 
material 2
region 3488
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3488
end_property_list 
<component> 3498 
n_bounds 4
bounds -2397 -10 9 2398 
property_list 
material 3
region 3489
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3489
end_property_list 
<component> 3499 
n_bounds 3
bounds -2398 -10 9 
property_list 
material 4
region 3490
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3490
end_property_list 
<component> 3500 
n_bounds 7
bounds 1981 191 9 2399 -194 -2004 -10 
property_list 
material 2
region 3491
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3491
end_property_list 
<component> 3501 
n_bounds 4
bounds -2399 -10 9 2400 
property_list 
material 3
region 3492
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3492
end_property_list 
<component> 3502 
n_bounds 3
bounds -2400 -10 9 
property_list 
material 4
region 3493
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3493
end_property_list 
<component> 3503 
n_bounds 7
bounds 1981 194 9 2401 -15 -2004 -10 
property_list 
material 2
region 3494
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3494
end_property_list 
<component> 3504 
n_bounds 4
bounds -2401 -10 9 2402 
property_list 
material 3
region 3495
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3495
end_property_list 
<component> 3505 
n_bounds 3
bounds -2402 -10 9 
property_list 
material 4
region 3496
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3496
end_property_list 
<component> 3506 
n_bounds 7
bounds 2004 12 9 2403 -172 -14 -10 
property_list 
material 2
region 3497
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3497
end_property_list 
<component> 3507 
n_bounds 4
bounds -2403 -10 9 2404 
property_list 
material 3
region 3498
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3498
end_property_list 
<component> 3508 
n_bounds 3
bounds -2404 -10 9 
property_list 
material 4
region 3499
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3499
end_property_list 
<component> 3509 
n_bounds 7
bounds 2004 172 9 2405 -175 -14 -10 
property_list 
material 2
region 3500
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3500
end_property_list 
<component> 3510 
n_bounds 4
bounds -2405 -10 9 2406 
property_list 
material 3
region 3501
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3501
end_property_list 
<component> 3511 
n_bounds 3
bounds -2406 -10 9 
property_list 
material 4
region 3502
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3502
end_property_list 
<component> 3512 
n_bounds 7
bounds 2004 175 9 2407 -178 -14 -10 
property_list 
material 2
region 3503
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3503
end_property_list 
<component> 3513 
n_bounds 4
bounds -2407 -10 9 2408 
property_list 
material 3
region 3504
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3504
end_property_list 
<component> 3514 
n_bounds 3
bounds -2408 -10 9 
property_list 
material 4
region 3505
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3505
end_property_list 
<component> 3515 
n_bounds 7
bounds 2004 178 9 2409 -181 -14 -10 
property_list 
material 2
region 3506
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3506
end_property_list 
<component> 3516 
n_bounds 4
bounds -2409 -10 9 2410 
property_list 
material 3
region 3507
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3507
end_property_list 
<component> 3517 
n_bounds 3
bounds -2410 -10 9 
property_list 
material 4
region 3508
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3508
end_property_list 
<component> 3518 
n_bounds 7
bounds 2004 181 9 2411 -183 -14 -10 
property_list 
material 2
region 3509
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3509
end_property_list 
<component> 3519 
n_bounds 4
bounds -2411 -10 9 2412 
property_list 
material 3
region 3510
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3510
end_property_list 
<component> 3520 
n_bounds 3
bounds -2412 -10 9 
property_list 
material 4
region 3511
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3511
end_property_list 
<component> 3521 
n_bounds 7
bounds 2004 183 9 2413 -185 -14 -10 
property_list 
material 2
region 3512
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3512
end_property_list 
<component> 3522 
n_bounds 4
bounds -2413 -10 9 2414 
property_list 
material 3
region 3513
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3513
end_property_list 
<component> 3523 
n_bounds 3
bounds -2414 -10 9 
property_list 
material 4
region 3514
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3514
end_property_list 
<component> 3524 
n_bounds 7
bounds 2004 185 9 2415 -188 -14 -10 
property_list 
material 2
region 3515
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3515
end_property_list 
<component> 3525 
n_bounds 4
bounds -2415 -10 9 2416 
property_list 
material 3
region 3516
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3516
end_property_list 
<component> 3526 
n_bounds 3
bounds -2416 -10 9 
property_list 
material 4
region 3517
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3517
end_property_list 
<component> 3527 
n_bounds 7
bounds 2004 188 9 2417 -191 -14 -10 
property_list 
material 2
region 3518
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3518
end_property_list 
<component> 3528 
n_bounds 4
bounds -2417 -10 9 2418 
property_list 
material 3
region 3519
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3519
end_property_list 
<component> 3529 
n_bounds 3
bounds -2418 -10 9 
property_list 
material 4
region 3520
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3520
end_property_list 
<component> 3530 
n_bounds 7
bounds 2004 191 9 2419 -194 -14 -10 
property_list 
material 2
region 3521
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3521
end_property_list 
<component> 3531 
n_bounds 4
bounds -2419 -10 9 2420 
property_list 
material 3
region 3522
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3522
end_property_list 
<component> 3532 
n_bounds 3
bounds -2420 -10 9 
property_list 
material 4
region 3523
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3523
end_property_list 
<component> 3533 
n_bounds 7
bounds 2004 194 9 2421 -15 -14 -10 
property_list 
material 2
region 3524
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3524
end_property_list 
<component> 3534 
n_bounds 4
bounds -2421 -10 9 2422 
property_list 
material 3
region 3525
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3525
end_property_list 
<component> 3535 
n_bounds 3
bounds -2422 -10 9 
property_list 
material 4
region 3526
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3526
end_property_list 
<component> 3536 
n_bounds 7
bounds 616 15 9 2423 -199 -1752 -10 
property_list 
material 2
region 3527
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3527
end_property_list 
<component> 3537 
n_bounds 4
bounds -2423 -10 9 2424 
property_list 
material 3
region 3528
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3528
end_property_list 
<component> 3538 
n_bounds 3
bounds -2424 -10 9 
property_list 
material 4
region 3529
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3529
end_property_list 
<component> 3539 
n_bounds 7
bounds 616 199 9 2425 -202 -1752 -10 
property_list 
material 2
region 3530
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3530
end_property_list 
<component> 3540 
n_bounds 4
bounds -2425 -10 9 2426 
property_list 
material 3
region 3531
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3531
end_property_list 
<component> 3541 
n_bounds 3
bounds -2426 -10 9 
property_list 
material 4
region 3532
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3532
end_property_list 
<component> 3542 
n_bounds 7
bounds 616 202 9 2427 -1050 -1752 -10 
property_list 
material 2
region 3533
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3533
end_property_list 
<component> 3543 
n_bounds 4
bounds -2427 -10 9 2428 
property_list 
material 3
region 3534
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3534
end_property_list 
<component> 3544 
n_bounds 3
bounds -2428 -10 9 
property_list 
material 4
region 3535
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3535
end_property_list 
<component> 3545 
n_bounds 7
bounds 616 1050 9 2429 -1053 -1752 -10 
property_list 
material 2
region 3536
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3536
end_property_list 
<component> 3546 
n_bounds 4
bounds -2429 -10 9 2430 
property_list 
material 3
region 3537
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3537
end_property_list 
<component> 3547 
n_bounds 3
bounds -2430 -10 9 
property_list 
material 4
region 3538
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3538
end_property_list 
<component> 3548 
n_bounds 7
bounds 616 1053 9 2431 -1056 -1752 -10 
property_list 
material 2
region 3539
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3539
end_property_list 
<component> 3549 
n_bounds 4
bounds -2431 -10 9 2432 
property_list 
material 3
region 3540
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3540
end_property_list 
<component> 3550 
n_bounds 3
bounds -2432 -10 9 
property_list 
material 4
region 3541
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3541
end_property_list 
<component> 3551 
n_bounds 7
bounds 616 1056 9 2433 -1059 -1752 -10 
property_list 
material 2
region 3542
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3542
end_property_list 
<component> 3552 
n_bounds 4
bounds -2433 -10 9 2434 
property_list 
material 3
region 3543
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3543
end_property_list 
<component> 3553 
n_bounds 3
bounds -2434 -10 9 
property_list 
material 4
region 3544
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3544
end_property_list 
<component> 3554 
n_bounds 7
bounds 616 1059 9 2435 -1062 -1752 -10 
property_list 
material 2
region 3545
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3545
end_property_list 
<component> 3555 
n_bounds 4
bounds -2435 -10 9 2436 
property_list 
material 3
region 3546
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3546
end_property_list 
<component> 3556 
n_bounds 3
bounds -2436 -10 9 
property_list 
material 4
region 3547
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3547
end_property_list 
<component> 3557 
n_bounds 7
bounds 616 1062 9 2437 -1065 -1752 -10 
property_list 
material 2
region 3548
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3548
end_property_list 
<component> 3558 
n_bounds 4
bounds -2437 -10 9 2438 
property_list 
material 3
region 3549
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3549
end_property_list 
<component> 3559 
n_bounds 3
bounds -2438 -10 9 
property_list 
material 4
region 3550
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3550
end_property_list 
<component> 3560 
n_bounds 7
bounds 616 1065 9 2439 -1068 -1752 -10 
property_list 
material 2
region 3551
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3551
end_property_list 
<component> 3561 
n_bounds 4
bounds -2439 -10 9 2440 
property_list 
material 3
region 3552
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3552
end_property_list 
<component> 3562 
n_bounds 3
bounds -2440 -10 9 
property_list 
material 4
region 3553
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3553
end_property_list 
<component> 3563 
n_bounds 7
bounds 616 1068 9 2441 -17 -1752 -10 
property_list 
material 2
region 3554
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3554
end_property_list 
<component> 3564 
n_bounds 4
bounds -2441 -10 9 2442 
property_list 
material 3
region 3555
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3555
end_property_list 
<component> 3565 
n_bounds 3
bounds -2442 -10 9 
property_list 
material 4
region 3556
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3556
end_property_list 
<component> 3566 
n_bounds 7
bounds 1752 15 9 2443 -199 -1775 -10 
property_list 
material 2
region 3557
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3557
end_property_list 
<component> 3567 
n_bounds 4
bounds -2443 -10 9 2444 
property_list 
material 3
region 3558
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3558
end_property_list 
<component> 3568 
n_bounds 3
bounds -2444 -10 9 
property_list 
material 4
region 3559
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3559
end_property_list 
<component> 3569 
n_bounds 7
bounds 1752 199 9 2445 -202 -1775 -10 
property_list 
material 2
region 3560
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3560
end_property_list 
<component> 3570 
n_bounds 4
bounds -2445 -10 9 2446 
property_list 
material 3
region 3561
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3561
end_property_list 
<component> 3571 
n_bounds 3
bounds -2446 -10 9 
property_list 
material 4
region 3562
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3562
end_property_list 
<component> 3572 
n_bounds 7
bounds 1752 202 9 2447 -1050 -1775 -10 
property_list 
material 2
region 3563
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3563
end_property_list 
<component> 3573 
n_bounds 4
bounds -2447 -10 9 2448 
property_list 
material 3
region 3564
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3564
end_property_list 
<component> 3574 
n_bounds 3
bounds -2448 -10 9 
property_list 
material 4
region 3565
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3565
end_property_list 
<component> 3575 
n_bounds 7
bounds 1752 1050 9 2449 -1053 -1775 -10 
property_list 
material 2
region 3566
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3566
end_property_list 
<component> 3576 
n_bounds 4
bounds -2449 -10 9 2450 
property_list 
material 3
region 3567
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3567
end_property_list 
<component> 3577 
n_bounds 3
bounds -2450 -10 9 
property_list 
material 4
region 3568
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3568
end_property_list 
<component> 3578 
n_bounds 7
bounds 1752 1053 9 2451 -1056 -1775 -10 
property_list 
material 2
region 3569
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3569
end_property_list 
<component> 3579 
n_bounds 4
bounds -2451 -10 9 2452 
property_list 
material 3
region 3570
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3570
end_property_list 
<component> 3580 
n_bounds 3
bounds -2452 -10 9 
property_list 
material 4
region 3571
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3571
end_property_list 
<component> 3581 
n_bounds 7
bounds 1752 1056 9 2453 -1059 -1775 -10 
property_list 
material 2
region 3572
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3572
end_property_list 
<component> 3582 
n_bounds 4
bounds -2453 -10 9 2454 
property_list 
material 3
region 3573
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3573
end_property_list 
<component> 3583 
n_bounds 3
bounds -2454 -10 9 
property_list 
material 4
region 3574
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3574
end_property_list 
<component> 3584 
n_bounds 7
bounds 1752 1059 9 2455 -1062 -1775 -10 
property_list 
material 2
region 3575
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3575
end_property_list 
<component> 3585 
n_bounds 4
bounds -2455 -10 9 2456 
property_list 
material 3
region 3576
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3576
end_property_list 
<component> 3586 
n_bounds 3
bounds -2456 -10 9 
property_list 
material 4
region 3577
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3577
end_property_list 
<component> 3587 
n_bounds 7
bounds 1752 1062 9 2457 -1065 -1775 -10 
property_list 
material 2
region 3578
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3578
end_property_list 
<component> 3588 
n_bounds 4
bounds -2457 -10 9 2458 
property_list 
material 3
region 3579
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3579
end_property_list 
<component> 3589 
n_bounds 3
bounds -2458 -10 9 
property_list 
material 4
region 3580
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3580
end_property_list 
<component> 3590 
n_bounds 7
bounds 1752 1065 9 2459 -1068 -1775 -10 
property_list 
material 2
region 3581
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3581
end_property_list 
<component> 3591 
n_bounds 4
bounds -2459 -10 9 2460 
property_list 
material 3
region 3582
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3582
end_property_list 
<component> 3592 
n_bounds 3
bounds -2460 -10 9 
property_list 
material 4
region 3583
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3583
end_property_list 
<component> 3593 
n_bounds 7
bounds 1752 1068 9 2461 -17 -1775 -10 
property_list 
material 2
region 3584
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3584
end_property_list 
<component> 3594 
n_bounds 4
bounds -2461 -10 9 2462 
property_list 
material 3
region 3585
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3585
end_property_list 
<component> 3595 
n_bounds 3
bounds -2462 -10 9 
property_list 
material 4
region 3586
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3586
end_property_list 
<component> 3596 
n_bounds 7
bounds 1775 15 9 2463 -199 -1798 -10 
property_list 
material 2
region 3587
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3587
end_property_list 
<component> 3597 
n_bounds 4
bounds -2463 -10 9 2464 
property_list 
material 3
region 3588
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3588
end_property_list 
<component> 3598 
n_bounds 3
bounds -2464 -10 9 
property_list 
material 4
region 3589
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3589
end_property_list 
<component> 3599 
n_bounds 7
bounds 1775 199 9 2465 -202 -1798 -10 
property_list 
material 2
region 3590
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3590
end_property_list 
<component> 3600 
n_bounds 4
bounds -2465 -10 9 2466 
property_list 
material 3
region 3591
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3591
end_property_list 
<component> 3601 
n_bounds 3
bounds -2466 -10 9 
property_list 
material 4
region 3592
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3592
end_property_list 
<component> 3602 
n_bounds 7
bounds 1775 202 9 2467 -1050 -1798 -10 
property_list 
material 2
region 3593
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3593
end_property_list 
<component> 3603 
n_bounds 4
bounds -2467 -10 9 2468 
property_list 
material 3
region 3594
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3594
end_property_list 
<component> 3604 
n_bounds 3
bounds -2468 -10 9 
property_list 
material 4
region 3595
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3595
end_property_list 
<component> 3605 
n_bounds 7
bounds 1775 1050 9 2469 -1053 -1798 -10 
property_list 
material 2
region 3596
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3596
end_property_list 
<component> 3606 
n_bounds 4
bounds -2469 -10 9 2470 
property_list 
material 3
region 3597
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3597
end_property_list 
<component> 3607 
n_bounds 3
bounds -2470 -10 9 
property_list 
material 4
region 3598
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3598
end_property_list 
<component> 3608 
n_bounds 7
bounds 1775 1053 9 2471 -1056 -1798 -10 
property_list 
material 2
region 3599
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3599
end_property_list 
<component> 3609 
n_bounds 4
bounds -2471 -10 9 2472 
property_list 
material 3
region 3600
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3600
end_property_list 
<component> 3610 
n_bounds 3
bounds -2472 -10 9 
property_list 
material 4
region 3601
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3601
end_property_list 
<component> 3611 
n_bounds 7
bounds 1775 1056 9 2473 -1059 -1798 -10 
property_list 
material 2
region 3602
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3602
end_property_list 
<component> 3612 
n_bounds 4
bounds -2473 -10 9 2474 
property_list 
material 3
region 3603
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3603
end_property_list 
<component> 3613 
n_bounds 3
bounds -2474 -10 9 
property_list 
material 4
region 3604
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3604
end_property_list 
<component> 3614 
n_bounds 7
bounds 1775 1059 9 2475 -1062 -1798 -10 
property_list 
material 2
region 3605
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3605
end_property_list 
<component> 3615 
n_bounds 4
bounds -2475 -10 9 2476 
property_list 
material 3
region 3606
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3606
end_property_list 
<component> 3616 
n_bounds 3
bounds -2476 -10 9 
property_list 
material 4
region 3607
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3607
end_property_list 
<component> 3617 
n_bounds 7
bounds 1775 1062 9 2477 -1065 -1798 -10 
property_list 
material 2
region 3608
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3608
end_property_list 
<component> 3618 
n_bounds 4
bounds -2477 -10 9 2478 
property_list 
material 3
region 3609
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3609
end_property_list 
<component> 3619 
n_bounds 3
bounds -2478 -10 9 
property_list 
material 4
region 3610
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3610
end_property_list 
<component> 3620 
n_bounds 7
bounds 1775 1065 9 2479 -1068 -1798 -10 
property_list 
material 2
region 3611
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3611
end_property_list 
<component> 3621 
n_bounds 4
bounds -2479 -10 9 2480 
property_list 
material 3
region 3612
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3612
end_property_list 
<component> 3622 
n_bounds 3
bounds -2480 -10 9 
property_list 
material 4
region 3613
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3613
end_property_list 
<component> 3623 
n_bounds 7
bounds 1775 1068 9 2481 -17 -1798 -10 
property_list 
material 2
region 3614
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3614
end_property_list 
<component> 3624 
n_bounds 4
bounds -2481 -10 9 2482 
property_list 
material 3
region 3615
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3615
end_property_list 
<component> 3625 
n_bounds 3
bounds -2482 -10 9 
property_list 
material 4
region 3616
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3616
end_property_list 
<component> 3626 
n_bounds 7
bounds 1798 15 9 2483 -199 -1821 -10 
property_list 
material 2
region 3617
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3617
end_property_list 
<component> 3627 
n_bounds 4
bounds -2483 -10 9 2484 
property_list 
material 3
region 3618
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3618
end_property_list 
<component> 3628 
n_bounds 3
bounds -2484 -10 9 
property_list 
material 4
region 3619
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3619
end_property_list 
<component> 3629 
n_bounds 7
bounds 1798 199 9 2485 -202 -1821 -10 
property_list 
material 2
region 3620
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3620
end_property_list 
<component> 3630 
n_bounds 4
bounds -2485 -10 9 2486 
property_list 
material 3
region 3621
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3621
end_property_list 
<component> 3631 
n_bounds 3
bounds -2486 -10 9 
property_list 
material 4
region 3622
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3622
end_property_list 
<component> 3632 
n_bounds 7
bounds 1798 202 9 2487 -1050 -1821 -10 
property_list 
material 2
region 3623
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3623
end_property_list 
<component> 3633 
n_bounds 4
bounds -2487 -10 9 2488 
property_list 
material 3
region 3624
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3624
end_property_list 
<component> 3634 
n_bounds 3
bounds -2488 -10 9 
property_list 
material 4
region 3625
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3625
end_property_list 
<component> 3635 
n_bounds 7
bounds 1798 1050 9 2489 -1053 -1821 -10 
property_list 
material 2
region 3626
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3626
end_property_list 
<component> 3636 
n_bounds 4
bounds -2489 -10 9 2490 
property_list 
material 3
region 3627
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3627
end_property_list 
<component> 3637 
n_bounds 3
bounds -2490 -10 9 
property_list 
material 4
region 3628
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3628
end_property_list 
<component> 3638 
n_bounds 7
bounds 1798 1053 9 2491 -1056 -1821 -10 
property_list 
material 2
region 3629
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3629
end_property_list 
<component> 3639 
n_bounds 4
bounds -2491 -10 9 2492 
property_list 
material 3
region 3630
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3630
end_property_list 
<component> 3640 
n_bounds 3
bounds -2492 -10 9 
property_list 
material 4
region 3631
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3631
end_property_list 
<component> 3641 
n_bounds 7
bounds 1798 1056 9 2493 -1059 -1821 -10 
property_list 
material 2
region 3632
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3632
end_property_list 
<component> 3642 
n_bounds 4
bounds -2493 -10 9 2494 
property_list 
material 3
region 3633
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3633
end_property_list 
<component> 3643 
n_bounds 3
bounds -2494 -10 9 
property_list 
material 4
region 3634
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3634
end_property_list 
<component> 3644 
n_bounds 7
bounds 1798 1059 9 2495 -1062 -1821 -10 
property_list 
material 2
region 3635
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3635
end_property_list 
<component> 3645 
n_bounds 4
bounds -2495 -10 9 2496 
property_list 
material 3
region 3636
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3636
end_property_list 
<component> 3646 
n_bounds 3
bounds -2496 -10 9 
property_list 
material 4
region 3637
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3637
end_property_list 
<component> 3647 
n_bounds 7
bounds 1798 1062 9 2497 -1065 -1821 -10 
property_list 
material 2
region 3638
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3638
end_property_list 
<component> 3648 
n_bounds 4
bounds -2497 -10 9 2498 
property_list 
material 3
region 3639
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3639
end_property_list 
<component> 3649 
n_bounds 3
bounds -2498 -10 9 
property_list 
material 4
region 3640
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3640
end_property_list 
<component> 3650 
n_bounds 7
bounds 1798 1065 9 2499 -1068 -1821 -10 
property_list 
material 2
region 3641
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3641
end_property_list 
<component> 3651 
n_bounds 4
bounds -2499 -10 9 2500 
property_list 
material 3
region 3642
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3642
end_property_list 
<component> 3652 
n_bounds 3
bounds -2500 -10 9 
property_list 
material 4
region 3643
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3643
end_property_list 
<component> 3653 
n_bounds 7
bounds 1798 1068 9 2501 -17 -1821 -10 
property_list 
material 2
region 3644
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3644
end_property_list 
<component> 3654 
n_bounds 4
bounds -2501 -10 9 2502 
property_list 
material 3
region 3645
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3645
end_property_list 
<component> 3655 
n_bounds 3
bounds -2502 -10 9 
property_list 
material 4
region 3646
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3646
end_property_list 
<component> 3656 
n_bounds 7
bounds 1821 15 9 2503 -199 -1844 -10 
property_list 
material 2
region 3647
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3647
end_property_list 
<component> 3657 
n_bounds 4
bounds -2503 -10 9 2504 
property_list 
material 3
region 3648
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3648
end_property_list 
<component> 3658 
n_bounds 3
bounds -2504 -10 9 
property_list 
material 4
region 3649
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3649
end_property_list 
<component> 3659 
n_bounds 7
bounds 1821 199 9 2505 -202 -1844 -10 
property_list 
material 2
region 3650
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3650
end_property_list 
<component> 3660 
n_bounds 4
bounds -2505 -10 9 2506 
property_list 
material 3
region 3651
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3651
end_property_list 
<component> 3661 
n_bounds 3
bounds -2506 -10 9 
property_list 
material 4
region 3652
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3652
end_property_list 
<component> 3662 
n_bounds 7
bounds 1821 202 9 2507 -1050 -1844 -10 
property_list 
material 2
region 3653
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3653
end_property_list 
<component> 3663 
n_bounds 4
bounds -2507 -10 9 2508 
property_list 
material 3
region 3654
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3654
end_property_list 
<component> 3664 
n_bounds 3
bounds -2508 -10 9 
property_list 
material 4
region 3655
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3655
end_property_list 
<component> 3665 
n_bounds 7
bounds 1821 1050 9 2509 -1053 -1844 -10 
property_list 
material 2
region 3656
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3656
end_property_list 
<component> 3666 
n_bounds 4
bounds -2509 -10 9 2510 
property_list 
material 3
region 3657
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3657
end_property_list 
<component> 3667 
n_bounds 3
bounds -2510 -10 9 
property_list 
material 4
region 3658
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3658
end_property_list 
<component> 3668 
n_bounds 7
bounds 1821 1053 9 2511 -1056 -1844 -10 
property_list 
material 2
region 3659
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3659
end_property_list 
<component> 3669 
n_bounds 4
bounds -2511 -10 9 2512 
property_list 
material 3
region 3660
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3660
end_property_list 
<component> 3670 
n_bounds 3
bounds -2512 -10 9 
property_list 
material 4
region 3661
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3661
end_property_list 
<component> 3671 
n_bounds 7
bounds 1821 1056 9 2513 -1059 -1844 -10 
property_list 
material 2
region 3662
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3662
end_property_list 
<component> 3672 
n_bounds 4
bounds -2513 -10 9 2514 
property_list 
material 3
region 3663
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3663
end_property_list 
<component> 3673 
n_bounds 3
bounds -2514 -10 9 
property_list 
material 4
region 3664
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3664
end_property_list 
<component> 3674 
n_bounds 7
bounds 1821 1059 9 2515 -1062 -1844 -10 
property_list 
material 2
region 3665
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3665
end_property_list 
<component> 3675 
n_bounds 4
bounds -2515 -10 9 2516 
property_list 
material 3
region 3666
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3666
end_property_list 
<component> 3676 
n_bounds 3
bounds -2516 -10 9 
property_list 
material 4
region 3667
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3667
end_property_list 
<component> 3677 
n_bounds 7
bounds 1821 1062 9 2517 -1065 -1844 -10 
property_list 
material 2
region 3668
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3668
end_property_list 
<component> 3678 
n_bounds 4
bounds -2517 -10 9 2518 
property_list 
material 3
region 3669
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3669
end_property_list 
<component> 3679 
n_bounds 3
bounds -2518 -10 9 
property_list 
material 4
region 3670
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3670
end_property_list 
<component> 3680 
n_bounds 7
bounds 1821 1065 9 2519 -1068 -1844 -10 
property_list 
material 2
region 3671
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3671
end_property_list 
<component> 3681 
n_bounds 4
bounds -2519 -10 9 2520 
property_list 
material 3
region 3672
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3672
end_property_list 
<component> 3682 
n_bounds 3
bounds -2520 -10 9 
property_list 
material 4
region 3673
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3673
end_property_list 
<component> 3683 
n_bounds 7
bounds 1821 1068 9 2521 -17 -1844 -10 
property_list 
material 2
region 3674
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3674
end_property_list 
<component> 3684 
n_bounds 4
bounds -2521 -10 9 2522 
property_list 
material 3
region 3675
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3675
end_property_list 
<component> 3685 
n_bounds 3
bounds -2522 -10 9 
property_list 
material 4
region 3676
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3676
end_property_list 
<component> 3686 
n_bounds 7
bounds 1844 15 9 2523 -199 -1867 -10 
property_list 
material 2
region 3677
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3677
end_property_list 
<component> 3687 
n_bounds 4
bounds -2523 -10 9 2524 
property_list 
material 3
region 3678
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3678
end_property_list 
<component> 3688 
n_bounds 3
bounds -2524 -10 9 
property_list 
material 4
region 3679
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3679
end_property_list 
<component> 3689 
n_bounds 7
bounds 1844 199 9 2525 -202 -1867 -10 
property_list 
material 2
region 3680
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3680
end_property_list 
<component> 3690 
n_bounds 4
bounds -2525 -10 9 2526 
property_list 
material 3
region 3681
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3681
end_property_list 
<component> 3691 
n_bounds 3
bounds -2526 -10 9 
property_list 
material 4
region 3682
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3682
end_property_list 
<component> 3692 
n_bounds 7
bounds 1844 202 9 2527 -1050 -1867 -10 
property_list 
material 2
region 3683
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3683
end_property_list 
<component> 3693 
n_bounds 4
bounds -2527 -10 9 2528 
property_list 
material 3
region 3684
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3684
end_property_list 
<component> 3694 
n_bounds 3
bounds -2528 -10 9 
property_list 
material 4
region 3685
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3685
end_property_list 
<component> 3695 
n_bounds 7
bounds 1844 1050 9 2529 -1053 -1867 -10 
property_list 
material 2
region 3686
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3686
end_property_list 
<component> 3696 
n_bounds 4
bounds -2529 -10 9 2530 
property_list 
material 3
region 3687
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3687
end_property_list 
<component> 3697 
n_bounds 3
bounds -2530 -10 9 
property_list 
material 4
region 3688
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3688
end_property_list 
<component> 3698 
n_bounds 7
bounds 1844 1053 9 2531 -1056 -1867 -10 
property_list 
material 2
region 3689
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3689
end_property_list 
<component> 3699 
n_bounds 4
bounds -2531 -10 9 2532 
property_list 
material 3
region 3690
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3690
end_property_list 
<component> 3700 
n_bounds 3
bounds -2532 -10 9 
property_list 
material 4
region 3691
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3691
end_property_list 
<component> 3701 
n_bounds 7
bounds 1844 1056 9 2533 -1059 -1867 -10 
property_list 
material 2
region 3692
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3692
end_property_list 
<component> 3702 
n_bounds 4
bounds -2533 -10 9 2534 
property_list 
material 3
region 3693
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3693
end_property_list 
<component> 3703 
n_bounds 3
bounds -2534 -10 9 
property_list 
material 4
region 3694
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3694
end_property_list 
<component> 3704 
n_bounds 7
bounds 1844 1059 9 2535 -1062 -1867 -10 
property_list 
material 2
region 3695
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3695
end_property_list 
<component> 3705 
n_bounds 4
bounds -2535 -10 9 2536 
property_list 
material 3
region 3696
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3696
end_property_list 
<component> 3706 
n_bounds 3
bounds -2536 -10 9 
property_list 
material 4
region 3697
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3697
end_property_list 
<component> 3707 
n_bounds 7
bounds 1844 1062 9 2537 -1065 -1867 -10 
property_list 
material 2
region 3698
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3698
end_property_list 
<component> 3708 
n_bounds 4
bounds -2537 -10 9 2538 
property_list 
material 3
region 3699
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3699
end_property_list 
<component> 3709 
n_bounds 3
bounds -2538 -10 9 
property_list 
material 4
region 3700
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3700
end_property_list 
<component> 3710 
n_bounds 7
bounds 1844 1065 9 2539 -1068 -1867 -10 
property_list 
material 2
region 3701
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3701
end_property_list 
<component> 3711 
n_bounds 4
bounds -2539 -10 9 2540 
property_list 
material 3
region 3702
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3702
end_property_list 
<component> 3712 
n_bounds 3
bounds -2540 -10 9 
property_list 
material 4
region 3703
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3703
end_property_list 
<component> 3713 
n_bounds 7
bounds 1844 1068 9 2541 -17 -1867 -10 
property_list 
material 2
region 3704
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3704
end_property_list 
<component> 3714 
n_bounds 4
bounds -2541 -10 9 2542 
property_list 
material 3
region 3705
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3705
end_property_list 
<component> 3715 
n_bounds 3
bounds -2542 -10 9 
property_list 
material 4
region 3706
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3706
end_property_list 
<component> 3716 
n_bounds 7
bounds 1867 15 9 2543 -199 -1890 -10 
property_list 
material 2
region 3707
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3707
end_property_list 
<component> 3717 
n_bounds 4
bounds -2543 -10 9 2544 
property_list 
material 3
region 3708
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3708
end_property_list 
<component> 3718 
n_bounds 3
bounds -2544 -10 9 
property_list 
material 4
region 3709
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3709
end_property_list 
<component> 3719 
n_bounds 7
bounds 1867 199 9 2545 -202 -1890 -10 
property_list 
material 2
region 3710
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3710
end_property_list 
<component> 3720 
n_bounds 4
bounds -2545 -10 9 2546 
property_list 
material 3
region 3711
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3711
end_property_list 
<component> 3721 
n_bounds 3
bounds -2546 -10 9 
property_list 
material 4
region 3712
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3712
end_property_list 
<component> 3722 
n_bounds 7
bounds 1867 202 9 2547 -1050 -1890 -10 
property_list 
material 2
region 3713
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3713
end_property_list 
<component> 3723 
n_bounds 4
bounds -2547 -10 9 2548 
property_list 
material 3
region 3714
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3714
end_property_list 
<component> 3724 
n_bounds 3
bounds -2548 -10 9 
property_list 
material 4
region 3715
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3715
end_property_list 
<component> 3725 
n_bounds 7
bounds 1867 1050 9 2549 -1053 -1890 -10 
property_list 
material 2
region 3716
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3716
end_property_list 
<component> 3726 
n_bounds 4
bounds -2549 -10 9 2550 
property_list 
material 3
region 3717
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3717
end_property_list 
<component> 3727 
n_bounds 3
bounds -2550 -10 9 
property_list 
material 4
region 3718
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3718
end_property_list 
<component> 3728 
n_bounds 7
bounds 1867 1053 9 2551 -1056 -1890 -10 
property_list 
material 2
region 3719
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3719
end_property_list 
<component> 3729 
n_bounds 4
bounds -2551 -10 9 2552 
property_list 
material 3
region 3720
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3720
end_property_list 
<component> 3730 
n_bounds 3
bounds -2552 -10 9 
property_list 
material 4
region 3721
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3721
end_property_list 
<component> 3731 
n_bounds 7
bounds 1867 1056 9 2553 -1059 -1890 -10 
property_list 
material 2
region 3722
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3722
end_property_list 
<component> 3732 
n_bounds 4
bounds -2553 -10 9 2554 
property_list 
material 3
region 3723
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3723
end_property_list 
<component> 3733 
n_bounds 3
bounds -2554 -10 9 
property_list 
material 4
region 3724
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3724
end_property_list 
<component> 3734 
n_bounds 7
bounds 1867 1059 9 2555 -1062 -1890 -10 
property_list 
material 2
region 3725
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3725
end_property_list 
<component> 3735 
n_bounds 4
bounds -2555 -10 9 2556 
property_list 
material 3
region 3726
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3726
end_property_list 
<component> 3736 
n_bounds 3
bounds -2556 -10 9 
property_list 
material 4
region 3727
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3727
end_property_list 
<component> 3737 
n_bounds 7
bounds 1867 1062 9 2557 -1065 -1890 -10 
property_list 
material 2
region 3728
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3728
end_property_list 
<component> 3738 
n_bounds 4
bounds -2557 -10 9 2558 
property_list 
material 3
region 3729
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3729
end_property_list 
<component> 3739 
n_bounds 3
bounds -2558 -10 9 
property_list 
material 4
region 3730
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3730
end_property_list 
<component> 3740 
n_bounds 7
bounds 1867 1065 9 2559 -1068 -1890 -10 
property_list 
material 2
region 3731
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3731
end_property_list 
<component> 3741 
n_bounds 4
bounds -2559 -10 9 2560 
property_list 
material 3
region 3732
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3732
end_property_list 
<component> 3742 
n_bounds 3
bounds -2560 -10 9 
property_list 
material 4
region 3733
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3733
end_property_list 
<component> 3743 
n_bounds 7
bounds 1867 1068 9 2561 -17 -1890 -10 
property_list 
material 2
region 3734
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3734
end_property_list 
<component> 3744 
n_bounds 4
bounds -2561 -10 9 2562 
property_list 
material 3
region 3735
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3735
end_property_list 
<component> 3745 
n_bounds 3
bounds -2562 -10 9 
property_list 
material 4
region 3736
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3736
end_property_list 
<component> 3746 
n_bounds 7
bounds 1890 15 9 2563 -199 -16 -10 
property_list 
material 2
region 3737
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3737
end_property_list 
<component> 3747 
n_bounds 4
bounds -2563 -10 9 2564 
property_list 
material 3
region 3738
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3738
end_property_list 
<component> 3748 
n_bounds 3
bounds -2564 -10 9 
property_list 
material 4
region 3739
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3739
end_property_list 
<component> 3749 
n_bounds 7
bounds 1890 199 9 2565 -202 -16 -10 
property_list 
material 2
region 3740
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3740
end_property_list 
<component> 3750 
n_bounds 4
bounds -2565 -10 9 2566 
property_list 
material 3
region 3741
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3741
end_property_list 
<component> 3751 
n_bounds 3
bounds -2566 -10 9 
property_list 
material 4
region 3742
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3742
end_property_list 
<component> 3752 
n_bounds 7
bounds 1890 202 9 2567 -1050 -16 -10 
property_list 
material 2
region 3743
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3743
end_property_list 
<component> 3753 
n_bounds 4
bounds -2567 -10 9 2568 
property_list 
material 3
region 3744
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3744
end_property_list 
<component> 3754 
n_bounds 3
bounds -2568 -10 9 
property_list 
material 4
region 3745
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3745
end_property_list 
<component> 3755 
n_bounds 7
bounds 1890 1050 9 2569 -1053 -16 -10 
property_list 
material 2
region 3746
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3746
end_property_list 
<component> 3756 
n_bounds 4
bounds -2569 -10 9 2570 
property_list 
material 3
region 3747
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3747
end_property_list 
<component> 3757 
n_bounds 3
bounds -2570 -10 9 
property_list 
material 4
region 3748
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3748
end_property_list 
<component> 3758 
n_bounds 7
bounds 1890 1053 9 2571 -1056 -16 -10 
property_list 
material 2
region 3749
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3749
end_property_list 
<component> 3759 
n_bounds 4
bounds -2571 -10 9 2572 
property_list 
material 3
region 3750
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3750
end_property_list 
<component> 3760 
n_bounds 3
bounds -2572 -10 9 
property_list 
material 4
region 3751
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3751
end_property_list 
<component> 3761 
n_bounds 7
bounds 1890 1056 9 2573 -1059 -16 -10 
property_list 
material 2
region 3752
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3752
end_property_list 
<component> 3762 
n_bounds 4
bounds -2573 -10 9 2574 
property_list 
material 3
region 3753
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3753
end_property_list 
<component> 3763 
n_bounds 3
bounds -2574 -10 9 
property_list 
material 4
region 3754
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3754
end_property_list 
<component> 3764 
n_bounds 7
bounds 1890 1059 9 2575 -1062 -16 -10 
property_list 
material 2
region 3755
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3755
end_property_list 
<component> 3765 
n_bounds 4
bounds -2575 -10 9 2576 
property_list 
material 3
region 3756
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3756
end_property_list 
<component> 3766 
n_bounds 3
bounds -2576 -10 9 
property_list 
material 4
region 3757
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3757
end_property_list 
<component> 3767 
n_bounds 7
bounds 1890 1062 9 2577 -1065 -16 -10 
property_list 
material 2
region 3758
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3758
end_property_list 
<component> 3768 
n_bounds 4
bounds -2577 -10 9 2578 
property_list 
material 3
region 3759
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3759
end_property_list 
<component> 3769 
n_bounds 3
bounds -2578 -10 9 
property_list 
material 4
region 3760
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3760
end_property_list 
<component> 3770 
n_bounds 7
bounds 1890 1065 9 2579 -1068 -16 -10 
property_list 
material 2
region 3761
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3761
end_property_list 
<component> 3771 
n_bounds 4
bounds -2579 -10 9 2580 
property_list 
material 3
region 3762
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3762
end_property_list 
<component> 3772 
n_bounds 3
bounds -2580 -10 9 
property_list 
material 4
region 3763
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CELL_0-3763
end_property_list 
<component> 3773 
n_bounds 7
bounds 1890 1068 9 2581 -17 -16 -10 
property_list 
material 2
region 3764
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/CLAD_0-3764
end_property_list 
<component> 3774 
n_bounds 4
bounds -2581 -10 9 2582 
property_list 
material 3
region 3765
volume 0.0
! PUMA: /FULLCORE_0-1/GEO2D_PART_001/FUEL_0-3765
end_property_list 
<component> 3775 
n_bounds 3
bounds -2582 -10 9 
property_list 
material 4
region 3766
volume 0.0
end_property_list 
end_component_list)"
}; // vector mc21_geometry_inputs_


const std::vector<std::string> Mc21Test::mc21_material_inputs_ = {
R"(title                            Converted from Old
!
materials                        4
!
<MATERIAL>                       1
material_type                    single-phase
material_name                    C0_VOID
material_category                other
nuclide_list
O16                              1.00000000E-20
end_nuclide_list
end_material
!
<MATERIAL>                       2
material_type                    single-phase
material_name                    CWATER
material_category                other
nuclide_list
B10                              1.48210000E-5
B11                              5.96570000E-5
H-H2O                            6.67370000E-2
O16                              3.33690000E-2
end_nuclide_list
end_material
!
<MATERIAL>                       3
material_type                    single-phase
material_name                    CCLAD
material_category                other
nuclide_list
AL27                             5.39850000E-2
CR50                             2.52140000E-6
CR52                             4.86220000E-5
CR53                             5.51280000E-6
CR54                             1.37240000E-6
CU63                             4.10540000E-5
CU65                             1.82990000E-5
FE54                             1.11570000E-5
FE56                             1.73440000E-4
FE57                             3.97110000E-6
FE58                             5.29480000E-7
MG24                             4.903067279999999E-4
MG25                             6.20720000E-5
MG26                             6.83412720E-5
MN55                             4.11910000E-5
SI28                             2.97260000E-4
SI29                             1.50510000E-5
SI30                             9.91300000E-6
TI46                             3.89919750E-6
TI47                             3.5163671999999995E-6
TI48                             3.48422836E-5
TI49                             2.55692830E-6
TI50                             2.44822340E-6
end_nuclide_list
end_material
!
<MATERIAL>                       4
material_type                    single-phase
material_name                    CFUEL
material_category                other
nuclide_list
B10                              2.60550000E-7
O16                              4.56830000E-2
U234                             4.56890000E-6
U235                             5.68680000E-4
U238                             2.22680000E-2
end_nuclide_list
end_material)"
}; // vector mc21_geometry_inputs_


std::string Mc21Test::exeAppTest(std::ofstream &flog, std::ofstream &fresult, const jobscript::PbsScript &pbs_script, const std::string &dir_path) const {
  std::string script_cmd_result;
  std::string module_load_result;
  std::string script_cmd;
  std::string modules_str;

//  pbs_script.generate();
  fresult << module_name_version(pbs_script.getModules()[pbs_script.getModules().size()-1]) << "\t" << dir_path << "\t" << pbs_script.getJobName() << " job." << std::endl;
//  std::cout << pbs_script.getExeName() << " " << pbs_script.getExeArgs() << std::endl;
  if (modules_load(flog, pbs_script.getModules(), module_load_result)) {
    modules_str = modules_string(pbs_script.getModules());
    script_cmd = "module purge;module load pbs;" + modules_str + ";" + pbs_script.getExeName() + " " + pbs_script.getExeArgs() + " 2>&1";
    flog << "Submit Command: " << script_cmd << std::endl;
    script_cmd_result = exec(script_cmd.c_str());
  } else {
    script_cmd_result = "fatal";
  }
  return script_cmd_result;
}



Mc21Test::Mc21Test(const jobscript::PbsScript &p_s): AppTest("mc21", "", p_s , mc21_inputs_.size()),
                                                     log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                     result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                     flog_(log_file_name_,std::ios_base::app),
                                                     fresult_(result_file_name_,std::ios_base::app) {}


Mc21Test::Mc21Test(const jobscript::PbsScript &p_s, const std::string &e_n): AppTest("mc21", "", p_s , mc21_inputs_.size(), e_n),
                                                                             log_file_name_(getHostName() + "_" + getTestName() + "_test.log"),
                                                                             result_file_name_(getHostName() + "_" + getTestName() + "_results.out"),
                                                                             flog_(log_file_name_,std::ios_base::app),
                                                                             fresult_(result_file_name_,std::ios_base::app) {}


void Mc21Test::runTest() {
  std::string cmd_result;
  std::string script_cmd_result;
  std::string mc21_dir;
//  std::cout << "Execute runTest member function from Mc21Test object " << __FILE__ << "\t" <<__LINE__ << "\t" << getTestObjectCount() << "\t" << getTestNumber() << std::endl;
  if (!flog_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << log_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  if (!fresult_.is_open()) {
      std::cerr << "Error: (" << __FILE__ << "," << __LINE__ << ") Opening file " << result_file_name_ << std::endl;
      exit(EXIT_FAILURE);
  }
  std::cout << "Testing: " << module_name_version(getPbsScripts()[0].getModules()[getPbsScripts()[0].getModules().size()-1]) << std::endl;
  int c_i = 0;
  for (auto mc21_input: mc21_inputs_) {
    mc21_dir = "mc21_" + std::to_string(getTestNumber()) + "_" + std::to_string(c_i);
    makeDir(mc21_dir);
    changeDir(mc21_dir);
    createFileFromStr(getInputFileNames()[c_i], mc21_input);
    createFileFromStr("geometry_input", mc21_geometry_inputs_[c_i]);
    createFileFromStr("material_input", mc21_material_inputs_[c_i]);
//    script_cmd_result = subPbsScript(flog_, getPbsScripts()[c_i]);
    script_cmd_result = exeAppTest(flog_, fresult_, getPbsScripts()[c_i], mc21_dir);
    checkSubmitResult(script_cmd_result, flog_, fresult_);
    changeDir("..");
    ++c_i;
  }
}


} // namespace hpcswtest

