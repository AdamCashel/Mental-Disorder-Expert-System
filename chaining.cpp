#include "chaining.h"
#include <algorithm>
#include <iostream>

// this function is an updated version of the one in the provides C program.
// it checks to see if a variable has been instantiated (has been evaluated)
void instantiate(std::string var, std::vector<Variable> &varList, std::vector<int> &instList) {
    // look for variable in variable list
    int idx = -1;
    for(int i = 1; i < var.size(); i++){
        if(var == varList[i].get_name()){
            idx = i;
            break;
        }
    }
    
    // if variable not found
    if(idx == -1){
        std::cerr << "variable not found\n";
        return;
    }

    // if variable has already been instantiated, return
    if(instList[idx] == 1)
        return;

    // if not instantiated, instantiate variable
    // set index of variable to 1 in the instantiated list
    instList[idx] = 1;

    //  variable is YES/NO
    if (varList[idx].get_type() == 1){
        // prompt user for input
        std::cout << "Input YES or NO for " << varList[idx].get_name() << std::endl;
        std::string temp; std::cin >> temp;
        varList[idx].set_str_value(temp);
    }
    // variable is numerical value
    else {
        // prompt user for input
        std::cout << "Input a real number for " << varList[idx].get_name() << std::endl;
        double temp; std::cin >> temp;
        varList[idx].set_num_value(temp);
    }
}

// updated version of fuction in the provided C program
// searches for variable name in conclusion list
// return index if found, -1 if not found
int determine_member_concl_list(std::string name, std::vector<std::string> concl_list){
    for(int i = 1; i < concl_list.size(); i++){
        if(name == concl_list[i])
            return i;
    }
    return -1;
}
