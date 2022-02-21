#include <iostream>
#include <string>
#include <vector>
#include "variable.h"
#include "interface.h"

extern void instantiate(std::string, std::vector<Variable> &, std::vector<int> &);

extern int determine_member_concl_list(std::string, std::vector<Variable>, int = 1);

extern bool condition_switch(int,  std::vector<Variable> varList);