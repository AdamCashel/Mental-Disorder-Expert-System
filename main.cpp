#include <iostream>
#include <stack>
#include <queue>
#include <unistd.h>

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

// Forward Chaining Variables
// conclusion variable queue
std::queue<Variable> conclusionQueue;

//Varaible List Forward
std::vector<Variable> forwardVarList(FORWARD_VAR_LIST_SIZE, 0);

// clause varaible list Forward
std::vector<Variable> forwardClauseVarList(FORWARD_CLAUSE_VAR_LIST_SIZE, 0);

// Clause Variable Pointer Array
//First index is rule number second index is clause number
int variable_pointer[2] = {};

// initialized to 0 for all variables
// instantialed list
std::vector<int> forwardInstantiatedList(FORWARD_VAR_LIST_SIZE, 0);

std::vector<std::string> forwardResponses(FORWARD_CONCL_LIST_SIZE);

// Variable used as the current variable
Variable var(0);

std::string diagnose_disorder(){
    std::cout << "ENTER CONCLUSION:\n";
    std::string conclusion; std::cin >> conclusion;
    conclusion = to_upper_case(conclusion);

    // runtime variables
    int statementNumber;

    bool stacksAreEmpty = false;
    bool invokeThen = false;
    bool recalculateIndex = false;
    bool varIsConclusion = false;


    // recalculateIndex is a wrapper used to mimic
    // the "goto b545" call in line 267 of the example program

    // varIsConclusion is a wrapper used to mimic
    // the "goto b520" call in line 152 of the example program

    while(!stacksAreEmpty){
        if(recalculateIndex != true){
            if(varIsConclusion != true){
                // determine if conclusion is in conclusion list
                statementNumber = determine_member_concl_list(conclusion, conclusionList);
            }
        }
        // if conclusion found in list
        if(statementNumber != -1){
            do{
                varIsConclusion = false;

                if(recalculateIndex != true){
                    statementStack.push(statementNumber);
                    clauseStack.push(1);
                }
                do{
                    recalculateIndex = false;

                    int clauseIndex = (statementStack.top() - 1) * 10 + clauseStack.top();
                    var = clauseVarList[clauseIndex];
                    

                    if(var.get_name() != ""){
                        // check if variable is a conclusion
                        // -1 if not a conclusion
                        statementNumber = determine_member_concl_list(var.get_name(), conclusionList);
                        if(statementNumber != -1){
                            // if the variable IS a conclusion
                            varIsConclusion = true;
                            break;
                        }
                        else {
                            // if the variable IS NOT a conclusion
                            instantiate(var.get_name(), varList, instantiatedList);
                            clauseStack.top()++;
                        }
                    }

                }while(var.get_name() != "");
                
                if(varIsConclusion)
                    break;

                statementNumber = statementStack.top();
                invokeThen = false;
                invokeThen = if_condition_switch(statementNumber, varList);
                
                if(invokeThen == false){
                    var = conclusionList[statementStack.top()];
                    statementNumber = determine_member_concl_list(var.get_name(), conclusionList, (statementStack.top() + 1));
                    
                    statementStack.pop();
                    clauseStack.pop();
                }

            }while(invokeThen == false && statementNumber != -1);

            // used to mimic goto 520
            if(varIsConclusion)
                continue;

            if(statementNumber != -1){
                std::string returnValue = then_condition_switch(statementNumber, varList);
                statementStack.pop();
                clauseStack.pop();

                if(statementStack.empty() && clauseStack.empty()){
                    std::cout << "DONE\n";
                    stacksAreEmpty = true;
                    return returnValue;
                } else {
                    clauseStack.top()++;
                    recalculateIndex = true;
                }
            }
        }
    }
    return "";
}

//Treatment for Disorder Function (Forward Chaining)
void disorderTreatment(std::string disorder_given)
{
    //Introduction of treatment diagnoses
    intro_treatment();
    
    //Skip Forward chaining no treatment needed
    if(disorder_given == "NONE")
    {
        std::cout << "No Treatment needed for Patient" << std::endl;
    }
    else
    {
        //Take care of patient has been diagnosed with a mental disorder before while
        forwardVarList[1].set_str_value("YES");
        forwardInstantiatedList[1] = 1;
        //What kind of disorder was diagnosed before while
        std::string disorder_type = condition_switch_disordertype(disorder_given);
        forwardVarList[2].set_str_value(disorder_type);
        forwardInstantiatedList[2] = 1;

        std::string search_variable = "DIAGNOSED"; //Add variable
    
        //Check the clause variable list for the first instace for if condtion is present
        //After finding what clause # its at the # is converted through the equation to the given rule #
        //While loop until treatment is found
        bool treatment_found = false;

        while(!treatment_found){
            //Search for variable in clause variable list and get index location
            int CVL_INDEX = determine_variable_location_CVL(search_variable, forwardClauseVarList, variable_pointer[1] + 1);

            if(CVL_INDEX == -1){
                std::cout << "ERROR: Treatment knowledge base does not contain this.\n";
                return;
            }

            variable_pointer[1] = CVL_INDEX;

            do{

                // Convert slot number to corresponding rule number by using formula function
                int rule_num = rule_number_formula(variable_pointer[1]);
                variable_pointer[0] = rule_num;
                variable_pointer[1]++;

                CVL_INDEX = variable_pointer[1];

                var = forwardClauseVarList[CVL_INDEX];

                if(var.get_name() != ""){
                    instantiate(var.get_name(), forwardVarList, forwardInstantiatedList);
                }

            }while(var.get_name() != "");


            treatment_found = condition_switch_forward(variable_pointer[0], forwardVarList);
            if(treatment_found){

                std::cout << "TREATMENT:\n";
                std::cout << forwardResponses[variable_pointer[0] / 10] << std::endl;
            }
        }
    }
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

    // display how to use program
    intro_directions();

    //After user has entered initial symptoms ask user questions and start diagnoseDisorder()
    init_clause_var_list_forward(forwardClauseVarList);
    init_var_list_forward(forwardVarList);
    init_responses_forward(forwardResponses);
    std::string disorder;
    disorder = diagnose_disorder();
    std::cout << "Patient diagnosed with " << disorder << std::endl;

    //After getting mental disorder diagnoses call disorderTreatment()
    disorderTreatment(disorder);

    //End of Program
    end_message();
}