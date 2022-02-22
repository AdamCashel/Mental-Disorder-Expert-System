#include <iostream>
#include <stack>
#include <queue>

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


Variable var(0);

//Diagnose Mental Disorder Function (Backward Chaining)
void diagnoseDisorder()
{   
    std::string diagnosedDisorder = "";
    // INITIAL INPUT
    // promt user for a conclusion to verify
    std::cout << "Enter Conclusion: \n";
    std::string conclusion; std::cin >> conclusion;
    conclusion = to_upper_case(conclusion);
    // check if conclusion is valid
    int statementNum = determine_member_concl_list(conclusion, conclusionList);
    
    // if the index is not -1, then the clause was found and is valid
    while(statementNum != -1){
        // push the statement number (index) onto the statement stack
        std::cout << "CONCLUSION FOUND\n";

        bool invokeThen = false;
        do{
            statementStack.push(statementNum);
            // push 1 onto the clause stack
            // !!! STILL NEED TO FIND OUT WHY !!!
            // seems to be used as an offset in the clause variable list
            clauseStack.push(1);
            do{
                //
                // calculate clause var index
                std::cout << "<diagnoseDisorder> statementStack top: " << statementStack.top() << std::endl;
                int clauseVarIdx = (statementStack.top() - 1) * 10 + clauseStack.top();

                std::cout << "<diagnoseDisorder> calculated clause variable index: " << clauseVarIdx << std::endl;
                
                var = clauseVarList[clauseVarIdx];
                std::cout << "<diagnoseDisorder> variable at calculated index: " << var.get_name() << std::endl;
                // match up the clause variable that was found0
                // to the variable in the variable list
                var = varList[find_var_index(var.get_name(), varList)];

                std::cout << "<diagnoseDisorder> variable value: " << var.get_str_value() << std::endl;
                // if the index in the clauseVarList does not go to nothing
                if(var.get_name() != ""){
                    // is the variable a conclusion?
                    statementNum = determine_member_concl_list(var.get_name(), conclusionList);
                    if(statementNum != -1){
                        // variable is a conclusion, push onto stack
                        statementStack.push(statementNum);
                        clauseStack.push(1);
                    }
                    else {
                        // instantiate the variable
                        instantiate(var.get_name(), varList, instantiatedList);
                        // increate clauseStack top value
                        clauseStack.top()++;
                    }
                }
            }while(var.get_name() != "");
            
            statementNum = statementStack.top();
            invokeThen = false;
            
            // call check on if part of the knowledge base (switch statement)
            std::cout << "<diagnoseDisorder> calling if condition switch on statement number: " << statementNum << std::endl;
            invokeThen = if_condition_switch(statementNum, varList);
            std::cout << std::boolalpha << "<diagnoseDisorder> if condition switch result: " << invokeThen << std::endl; 
            if(!invokeThen){
                // did not satify any conditions
                // get next conclusion in stack
                int conclVarIdx = statementStack.top();
                var = conclusionList[conclVarIdx];
                statementNum = determine_member_concl_list(var.get_name(), conclusionList, (statementStack.top() + 1));
                statementStack.pop();
            }
        } while (!invokeThen && statementNum != 0);

        // TODO:    
        // implement then condition switch
        std::string disorder = then_condition_switch(statementNum);
        std::cout << disorder << std::endl;
        /// if statementStack is empty, complete
        /// else pop next statement number from stack and continue
        statementStack.pop();
        if(statementStack.empty())
            break;
        else{
            statementNum = statementStack.top();
        } 
    };
    std::cout << "Disorder found\n";
}

//Treatment for Disorder Function (Forward Chaining)
void disorderTreatment(std::string disorder_given)
{
    //Introduction of treatment diagnoses
    intro_treatment();
    //Check the clause variable list for the first instace for if condtion is present
    //After finding what clause # its at the # is converted through the equation to the given rule #
    
    //While loop until treatment is found
    int current_index = 0;
    std::string search_variable = ""; //Add variable
    bool treatment_found = false;
    while(!treatment_found)
    {
        //Search for variable in clause variable list and get index location
        int CVL_INDEX = determine_variable_location_CVL(search_variable, ForwardclauseVarList, current_index); 
        //Convert slot number to corresponding rule number by using formula function
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
    initialSymptoms();

    //After user has entered initial symptoms ask user questions and start diagnoseDisorder()
    init_concl_list_forward(ForwardclauseVarList);
    init_var_list_forward(varListForward);
    diagnoseDisorder();

    //After getting mental disorder diagnoses call disorderTreatment()
    std::string dummy_disorder = " ";
    disorderTreatment(dummy_disorder);

    //End of Program
    end_message();
}