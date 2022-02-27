#pragma once
#include <string>
#include <vector>
#include "variable.h"

extern const int CONCL_LIST_SIZE;
extern const int VAR_LIST_SIZE;
extern const int CLAUSE_VAR_LIST_SIZE;
extern const int FORWARD_CONCL_LIST_SIZE;
extern const int FORWARD_VAR_LIST_SIZE;
extern const int FORWARD_CLAUSE_VAR_LIST_SIZE;

extern void init_concl_list(std::vector<Variable> &);

extern void init_concl_list_forward(std::vector<Variable> &);

extern void init_var_list(std::vector<Variable> &);

extern void init_var_list_forward(std::vector<Variable> &);

extern void init_clause_var_list(std::vector<Variable> &);

extern void init_clause_var_list_forward(std::vector<Variable> &);

extern void init_responses_forward(std::vector<std::string> &);

extern int clause_number_formula(int);

extern int rule_number_formula(int);

extern int find_var_index(std::string, std::vector<Variable>);


