#include <iostream>
#include <stack>

#include "initialize.h"
#include "interface.h"
#include "variable.h"
#include "chaining.h"

// the following lists are initialized to empty strings
// in accordance to known max lengths for each list
// conclusion list
std::vector<Variable> conclusionList(CONCL_LIST_SIZE, 0);

// variable list
std::vector<Variable> varList(VAR_LIST_SIZE, 0);

// clause variable list
std::vector<Variable> clauseVarList(CLAUSE_VAR_LIST_SIZE, 0);

// initialized to 0 for all variables
// instantialed list
std::vector<int> instantiatedList(VAR_LIST_SIZE, 0);

// statement stack
std::stack<int> statementStack;

// clause stack
std::stack<int> clauseStack;

Variable var(0);


//Diagnose Mental Disorder Function (Backward Chaining)
void diagnoseDisorder()
{   
    // INITIAL INPUT
    // promt user for a conclusion to verify
    std::cout << "Enter Conclusion: \n" << std::endl;
    std::string conclusion; std::cin >> conclusion;

    // check if conclusion is valid
    int statementNum = determine_member_concl_list(conclusion, conclusionList);
    
    // if the index is not -1, then the clause was found and is valid
    if(statementNum != -1){
        // push the statement number (index) onto the statement stack
        std::cout << "Conclusion found.\n";
        statementStack.push(statementNum);
        // push 1 onto the clause stack
        // !!! STILL NEED TO FIND OUT WHY !!!
        clauseStack.push(1);
    }

}

//Treatment for Disorder Function (Forward Chaining)
void disorderTreatment()
{

}

//Asks user for the initial symptoms of patient
void initialSymtoms()
{

}


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

    //Start getting symptoms from user


    //After user has entered initial symptoms ask user questions and start diagnoseDisorder()
    diagnoseDisorder();

    //After getting mental disorder diagnoses call disorderTreatment()
    disorderTreatment();

    
}