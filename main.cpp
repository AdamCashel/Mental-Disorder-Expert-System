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
// clause variable pointer
int clauseVariablePointer[2] = {};
// conclusion variable queue
std::queue<Variable> conclusionQueue;

//Varaible List Forward
std::vector<Variable> varListForward(FORWARD_VAR_LIST_SIZE, 0);

// clause varaible list Forward
std::vector<Variable> ForwardclauseVarList(CONCL_FORWARD_LIST_SIZE, 0);

// Variable Pointer Array
//First index is rule number second index is clause number
int variable_pointer[2] = {};

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
    
    //Take care of patient has been diagnosed with a mental disorder before while

    //What kind of disorder was diagnosed before while

    int current_index = 0;
    std::string search_variable = ""; //Add variable
    
    //Check the clause variable list for the first instace for if condtion is present
    //After finding what clause # its at the # is converted through the equation to the given rule #
    //While loop until treatment is found
    bool treatment_found = false;
    while(!treatment_found)
    {
        //Search for variable in clause variable list and get index location
        int CVL_INDEX = determine_variable_location_CVL(search_variable, ForwardclauseVarList, current_index); 
        //Convert slot number to corresponding rule number by using formula function
        int rule_num = rule_number_formula(CVL_INDEX);
        variable_pointer[0] = rule_num;
    }
   
}

//Asks user for the initial symptoms of patient
void initialSymptoms()
{
    std::string user_answer = "";
    intro_directions();
    std::cout << "Do you have any symptoms of the patient? (y/n)" <<std::endl;
    getline(std::cin, user_answer);
    user_answer = to_upper_case(user_answer);
    if(user_answer == "Y")
    {
        std::cout << "Enter symptoms of the patient already obtained. Press 's' to stop" << std::endl;
        while(user_answer != "S")
        {
            std::cout << "Enter Patient Symptom" << std::endl;
            getline(std::cin, user_answer);
            user_answer = to_upper_case(user_answer);
            bool found = false;
            int i = 0;
            while(!found && i < VAR_LIST_SIZE)
            {
                if(user_answer == varList[i].get_name())
                {
                    found = true;
                    if(varList[i].get_type() == 2)
                    {
                         std::cout << "Enter Value for " << user_answer << std::endl;
                         getline(std::cin, user_answer);
                         varList[i].set_str_value(user_answer);
                         instantiatedList[i] = 1;
                    }
                    std::cout << user_answer << " was found in symptom list" << std::endl;
                }
                i++;
            }
            if(found == false)
            {
                std::cout << user_answer << " not found" << std::endl;
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
    /*
    std::cout << "CONCLUSION LIST\n";
    print_list(conclusionList);

    std::cout << std::endl;

    std::cout << "VARIABLE LIST\n";
    print_list(varList);

    std::cout << std::endl;

    std::cout << "CLAUSE VARIABLE LIST\n";
    print_list(clauseVarList);
    */
    //Start getting symptoms from user
    //initialSymptoms();
    

    //After user has entered initial symptoms ask user questions and start diagnoseDisorder()
    init_concl_list_forward(ForwardclauseVarList);
    init_var_list_forward(varListForward);
    std::string disorder;
    disorder = diagnose_disorder();
    std::cout << "Patient diagnosed with " << disorder << std::endl;

    //After getting mental disorder diagnoses call disorderTreatment()
    std::string dummy_disorder = " ";
    disorderTreatment(dummy_disorder);

    //End of Program
    end_message();
}