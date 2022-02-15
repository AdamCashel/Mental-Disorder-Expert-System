#include "initialize.h"
#include <fstream>
#include <iostream>

// starting index is 1, so we add 1 to size
const int CONCL_LIST_SIZE = 62 + 1;
const int VAR_LIST_SIZE = 32 + 1;

// we have a maximum of 9 variables in our if clauses
// since we have 17 rules, with at most 9 variables each,
// the max length of our clause variable list is 153
const int CLAUSE_VAR_LIST_SIZE = 153 + 1;

// places the values below in the vector of strings passed
void init_concl_list(std::vector<Variable> &vector) {
    std::ifstream inputFile;
    std::string line;
    inputFile.open("./data/backward-chaining-conclusionlist.txt");
    for(int i = 1; i < CONCL_LIST_SIZE; i++){
        getline(inputFile, line);
        vector[i].set_name(line);
    }
    inputFile.close();
}

// places the values below in the vector of type Variable
// TODO:
// review for abbreviations of variable names
void init_var_list(std::vector<Variable> &vector) {
    std::ifstream inputFile;
    std::string line;

    inputFile.open("./data/backward-chaining-variablelist.txt");
    for(int i = 1; i < VAR_LIST_SIZE; i++){
        getline(inputFile, line);
        vector[i].set_name(line);
    }
    inputFile.close();
}

// places the values below in the vector of type Variable
// due to this list being so long, it as placed in a file and then read
// to initialize the list

// TODO:
// create initialization function for conclusion variable list
// need to specify types
void init_clause_var_list(std::vector<Variable> &vector){
    std::ifstream inputFile;
    std::string line;

    inputFile.open("./data/backward-chaining-clauselist.txt");
    for(int i = 1; i < CLAUSE_VAR_LIST_SIZE; i++){
        getline(inputFile, line);
        vector[i].set_name(line);
    }
    inputFile.close();
}

//Formula used to get clause number output by rule number input (Backward Chaining)
int clause_number_formula(int rule_numb)
{
    int clause_temp = ((10 *(rule_numb / 10)) - 1) + 1;
    return clause_temp;
}

//Formula to get rule number output by clause number input (Forward Chaining)
int rule_number_formula(int clause_numb)
{
    int rule_temp = ((clause_numb / 10)) * 10;
    return rule_temp;
} 