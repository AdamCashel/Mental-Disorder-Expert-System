#include <iostream>
#include <stack>

#include "initialize.h"
#include "interface.h"
#include "variable.h"

// the following lists are initialized to empty strings
// in accordance to known max lengths for each list
// conclusion list
std::vector<std::string> conclusionList(CONCL_LIST_SIZE, "");

// variable list
std::vector<Variable> varList(VAR_LIST_SIZE, 0);

// clause variable list
std::vector<Variable> clauseVarList(CLAUSE_VAR_LIST_SIZE, 0);

// initialized to 0 for all variables
// instantialed list
std::vector<int> instantiatedList(VAR_LIST_SIZE, 0);

// statement stack
std::stack<int> statementStack();

// clause stack
std::stack<int> clauseStack();

int main() {
    // initialize and declare conclusion and variable list
    init_concl_list(conclusionList);
    init_var_list(varList);
    init_clause_var_list(clauseVarList);

    // display values for user to see
    std::cout << "CONCLUSION LIST\n";
    print_list(conclusionList);

    std::cout << std::endl;

    std::cout << "VARIABLE LIST\n";
    print_list(varList);

    std::cout << std::endl;

    std::cout << "CLAUSE VARIABLE LIST\n";
    print_list(clauseVarList);
}