#pragma once
#include "dialogue.h"
#include "variable.h"

extern void print_list(std::vector<std::string>);

extern void print_list(std::vector<Variable>);

extern void intro_directions();

extern void intro_treatment();

extern void end_message();

extern std::string to_upper_case(std::string);

extern void diagnoseOutput(std::string);