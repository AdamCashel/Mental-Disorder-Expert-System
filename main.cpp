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
        std::cout << "CONCLUSION FOUND\n";

        bool invokeThen = false;
        do{
            statementStack.push(statementNum);
            // push 1 onto the clause stack
            // !!! STILL NEED TO FIND OUT WHY !!!
            // seems to be used as an offset in the clause variable list

            clauseStack.push(1);
            do{
                // calculate clause var index
                int clauseVarIdx = (statementStack.top() - 1) * 10 + clauseStack.top();
                
                var = clauseVarList[clauseVarIdx];
                // if the index in the clauseVarList goes to nothing
                if(var.get_name() != ""){
                    // is the variable a conclusion?
                    statementNum = determine_member_concl_list(var.get_name(), conclusionList);
                    if(statementNum != -1){
                        // variable is a conclusion, push onto stack
                        statementStack.push(statementNum);
                        clauseStack.push(1);
                    }
                    else {
                        //instantiate the variable
                        instantiate(var, varList, instantiatedList);
                        // increate clauseStack top value
                        clauseStack.top()++;
                    }
                }
            }while(var.get_name() != "");
            
            statementNum = statementStack.top();
            invokeThen = false;
            
            // call check on if part of the knowledge base (switch statement)

            if(!invokeThen){
                // did not satify any conditions
                // get next conclusion in stack
                int conclVarIdx = statementStack.top();
                var = conclusionList[conclVarIdx];
                statementNum = determine_member_concl_list(var.get_name(), conclusionList, (statementStack.top() + 1));
                statementStack.pop();
            }
        } while (!invokeThen && statementNum != 0);
    }
    else{
         std::cout << "CONCLUSION NOT FOUND\n";
    }

}

//Treatment for Disorder Function (Forward Chaining)
void disorderTreatment()
{

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
        getline(std::cin, user_answer);
        user_answer = to_upper_case(user_answer);
        while(user_answer != "s")
        {
            std::cout << "Enter Patient Symptom" << std::endl;
            getline(std::cin, user_answer);
            user_answer = to_upper_case(user_answer);
            bool found = false;
            int i = 0;
            while(!found && i < 33)
            {
                if(user_answer == varList[i].get_name())
                {
                    found = true;
                    if(varList[i].get_type() == 2)
                    {
                         std::cout << "Enter Value for " << user_answer << std::endl;
                         getline(std::cin, user_answer);
                         varList[i].set_str_value(user_answer);
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
    std::cout << "CONCLUSION LIST\n";
    print_list(conclusionList);

    std::cout << std::endl;

    std::cout << "VARIABLE LIST\n";
    print_list(varList);

    std::cout << std::endl;

    std::cout << "CLAUSE VARIABLE LIST\n";
    print_list(clauseVarList);

    //Start getting symptoms from user
    initialSymptoms();

    //After user has entered initial symptoms ask user questions and start diagnoseDisorder()
    diagnoseDisorder();

    //After getting mental disorder diagnoses call disorderTreatment()
    disorderTreatment();

    
}