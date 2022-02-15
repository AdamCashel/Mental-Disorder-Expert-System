#include <algorithm>
#include <iostream>
#include "chaining.h"

// this function is an updated version of the one in the provides C program.
// it checks to see if a variable has been instantiated (has been evaluated)
void instantiate(std::string var, std::vector<Variable> &varList, std::vector<int> &instList) {
    // look for variable in variable list
    int idx = -1;
    for(int i = 1; i < varList.size(); i++){
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
int determine_member_concl_list(std::string name, std::vector<Variable> concl_list, int start /* = 1*/){
    for(int i = start; i < concl_list.size(); i++){
        if(name == concl_list[i].get_name())
            return i;
    }
    return -1;
}


bool condition_switch(int statementNum, std::vector<Variable> varList){
    // varList[idx], where idx = respective variable for the rules
    switch(statementNum){
        case 1:
            if(varList[1].get_str_value() == "NO")
                return true;
            break;
        
        case 2:
            if(varList[1].get_str_value() == "YES")
                return true;
            break;
        
        case 3:
            if (varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "NO" && varList[5].get_str_value() == "NO" &&
                varList[6].get_str_value() == "YES" && varList[7].get_str_value() == "YES" &&
                varList[8].get_str_value() == "YES" && varList[9].get_str_value() == "YES")
                return true;
            break;

        case 4:
            if (varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "NO" && varList[5].get_str_value() == "NO" &&
                varList[6].get_str_value() == "YES" && varList[7].get_str_value() == "NO" &&
                varList[10].get_str_value() == "YES" && varList[9].get_str_value() == "YES")
                return true;
            break;
        
        case 5:
            if (varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "NO" && varList[5].get_str_value() == "NO" &&
                varList[6].get_str_value() == "NO" && varList[11].get_str_value() == "NO" &&
                varList[8].get_str_value() == "YES" && varList[9].get_str_value() == "YES" &&
                varList[7].get_str_value() == "YES")
                return true;
            break;

        case 6:
            if (varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "NO" && varList[5].get_str_value() == "NO" &&
                varList[6].get_str_value() == "YES" && varList[11].get_str_value() == "NO" &&
                varList[7].get_str_value() == "NO" && varList[10].get_str_value() == "YES" &&
                varList[9].get_str_value() == "YES")
                return true;
            break;

        case 7:
            if (varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "NO" && varList[5].get_str_value() == "NO" &&
                varList[6].get_str_value() == "NO" && varList[11].get_str_value() == "YES" &&
                varList[10].get_str_value() == "YES" && varList[9].get_str_value() == "YES")
                return true;
            break;

        default:
            return false;
            break;
    }
}