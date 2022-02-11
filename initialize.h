#pragma once
#include <string>
#include <vector>
#include "variable.h"

extern const int CONCL_LIST_SIZE;
extern const int VAR_LIST_SIZE;
extern const int CLAUSE_VAR_LIST_SIZE;

extern void init_concl_list(std::vector<std::string> &);

extern void init_var_list(std::vector<Variable> &);

extern void init_clause_var_list(std::vector<Variable> &);
