#include <iostream>
#include <string>
#include <vector>
#include "variable.h"

extern void instantiate(std::string, std::vector<Variable> &, std::vector<int> &);

extern int determine_member_concl_list(std::string, std::vector<Variable>, int = 1);

extern int condition_switch(bool);

extern bool condition_switch_forward(int statementNum, std::vector<Variable> varList);

extern bool condition_switch_disordertype(int statementNum, std::vector<Variable> varList);

extern int disordertype_helper(std::string);