#include <iostream>
#include <string>
#include <vector>
#include "variable.h"

extern void instantiate(Variable, std::vector<Variable> &, std::vector<int> &);

extern int determine_member_concl_list(std::string, std::vector<Variable>, int = 1);

extern int condition_switch(bool);