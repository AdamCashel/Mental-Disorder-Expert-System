#include <iostream>
#include <string>
#include <vector>
#include "variable.h"
#include "interface.h"

extern void instantiate(std::string, std::vector<Variable> &, std::vector<int> &);

extern int determine_member_concl_list(std::string, std::vector<Variable>, int = 1);

extern bool if_condition_switch(int,  std::vector<Variable>);

extern std::string then_condition_switch(int);

extern bool condition_switch_forward(int, std::vector<Variable>);

extern std::string condition_switch_disordertype(int);

extern int disordertype_helper(std::string);

extern int determine_variable_location_CVL(std::string, std::vector<Variable>, int);
