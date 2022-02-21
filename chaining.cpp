#include <algorithm>
#include <iostream>
#include "chaining.h"

// this function is an updated version of the one in the provides C program.
// it checks to see if a variable has been instantiated (has been evaluated)
void instantiate(std::string var, std::vector<Variable> &varList, std::vector<int> &instList) {
    // look for variable in variable list
    int idx = -1;
    std::cout << "<instantiate> searching for: " << var << std::endl;
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

    std::cout << "<instantiate> variable found\n";

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
        temp = to_upper_case(temp);
        varList[idx].set_str_value(temp);
    }
    // variable is numerical value
    else {
        // prompt user for input
        std::cout << "Input a REAL NUMBER for " << varList[idx].get_name() << std::endl;
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
        
        case 8:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" && 
                varList[4].get_str_value() == "NO" && varList[5].get_str_value() == "YES" && 
                varList[11].get_str_value() == "YES" && varList[10].get_str_value() == "YES" && 
                varList[9].get_str_value() == "YES")
                return true;
            break;
        case 9:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
                varList[13].get_str_value() == "YES" && varList[14].get_str_value() == "YES" &&
                varList[33].get_num_value() > 2)
                return true;
            break;
        case 10:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
                varList[13].get_str_value() == "YES" && varList[14].get_str_value() == "YES" &&
                varList[33].get_num_value() > 2)
                return true;
            break;
        case 11:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
                varList[13].get_str_value() == "YES" && varList[14].get_str_value() == "NO" &&
                varList[15].get_str_value() == "YES" && varList[33].get_num_value() < 2)
                return true;
            break;
        case 12:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
                varList[13].get_str_value() == "YES" && varList[14].get_str_value() == "NO" &&
                varList[15].get_str_value() == "YES" && varList[33].get_num_value() > 2)
                return true;
            break;
        case 13:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
                varList[13].get_str_value() == "NO" && varList[16].get_str_value() == "NO" && 
                varList[14].get_str_value() == "YES" && varList[33].get_num_value() < 2)
                return true;
            break;
        case 14: 
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
                varList[13].get_str_value() == "NO" && varList[16].get_str_value() == "NO" &&
                varList[14].get_str_value() == "YES" && varList[33].get_num_value() > 2)
                return true;
            break;
        case 15:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
                varList[13].get_str_value() == "NO" && varList[16].get_str_value() == "NO" &&
                varList[14].get_str_value() == "NO" && varList[15].get_str_value() == "YES" &&
                varList[33].get_num_value() < 2)
                return true;
            break;
        case 16:
            if(varList[2].get_str_value() == "Yes" && varList[3].get_str_value() == "YES" && 
                varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
                varList[13].get_str_value() == "NO" && varList[16].get_str_value() == "NO" &&
                varList[14].get_str_value() == "NO" && varList[15].get_str_value() == "YES" &&
                varList[33].get_num_value() > 2)
                return true;
            break;
        case 17:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
                varList[13].get_str_value() == "NO" && varList[16].get_str_value() == "YES" &&
                varList[15].get_str_value() == "YES" && varList[33].get_num_value() < 2)
                return true;
            break;
        case 18:
        if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
            varList[13].get_str_value() == "NO" && varList[16].get_str_value() == "YES" &&
            varList[15].get_str_value() == "YES" && varList[33].get_num_value() < 2)
            return true;
            break;
        case 19:
        if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "NO" &&
            varList[16].get_str_value() == "NO" && varList[14].get_str_value() == "NO" &&
            varList[33].get_num_value() < 2)
            return true;
            break;
        case 20:
        if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "NO" &&
            varList[16].get_str_value() == "NO" && varList[14].get_str_value() == "YES" &&
            varList[33].get_num_value() > 2)
            return true;
            break;
        case 21:
        if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "NO" &&
            varList[16].get_str_value() == "NO" && varList[14].get_str_value() == "NO" &&
            varList[15].get_str_value() == "YES" && varList[33].get_num_value() < 2)
            return true;
            break;
        case 22:
        if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "NO" &&
            varList[16].get_str_value() == "NO" && varList[14].get_str_value() == "NO" &&
            varList[15].get_str_value() == "YES" && varList[33].get_num_value() > 2)
            return true;
            break;
        case 23:
        if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "NO" &&
            varList[16].get_str_value() == "NO" && varList[15].get_str_value() == "YES" && 
            varList[3].get_num_value() < 2)
            return true;
            break;
        case 24:
        if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "NO" &&
            varList[16].get_str_value() == "NO" && varList[15].get_str_value() == "YES" &&
            varList[33].get_num_value() > 2)
            return true;
            break;
        case 25:
        if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
            varList[17].get_str_value() == "NO" && varList[34].get_str_value() == "YES" &&
            varList[19].get_str_value() == "YES" && varList[18].get_str_value() == "YES")
            return true;
            break;
        case 26:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "NO" &&
            varList[34].get_str_value() == "YES" && varList[19].get_str_value() == "NO" &&
            varList[20].get_str_value() == "YES" && varList[18].get_str_value() == "YES")
            return true;
            break;
        case 27:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
            varList[17].get_str_value() == "NO" && varList[34].get_str_value() == "NO" &&
            varList[21].get_str_value() == "NO" && varList[19].get_str_value() == "YES" &&
            varList[18].get_str_value() == "YES")
            return true;
            break;
        case 28:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
            varList[17].get_str_value() == "NO" && varList[34].get_str_value() == "NO" &&
            varList[21].get_str_value() == "NO" && varList[19].get_str_value() == "NO" &&
            varList[20].get_str_value() == "YES" && varList[19].get_str_value() == "YES")
            return true;
            break;
        case 29:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
            varList[17].get_str_value() == "NO" && varList[34].get_str_value() == "NO" &&
            varList[21].get_str_value() == "YES" && varList[19].get_str_value() == "NO" &&
            varList[20].get_str_value() == "YES" && varList[19].get_str_value() == "YES")
            return true;
            break;
        case 30:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
            varList[17].get_str_value() == "NO" && varList[21].get_str_value() == "NO" && 
            varList[19].get_str_value() == "YES" && varList[18].get_str_value() == "YES")
            return true;
            break;
        case 31:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
            varList[17].get_str_value() == "NO" && varList[21].get_str_value() == "NO" && 
            varList[19].get_str_value() == "NO" && varList[18].get_str_value() == "YES" &&
            varList[20].get_str_value() == "YES")
            return true;
            break;
        case 32:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[12].get_str_value() == "YES" &&
            varList[17].get_str_value() == "NO" && varList[21].get_str_value() == "YES" && 
            varList[20].get_str_value() == "YES" && varList[18].get_str_value() == "YES")
            return true;
            break;
        case 33:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[22].get_str_value() == "NO" &&
            varList[25].get_str_value() == "YES" && varList[23].get_str_value() == "YES" && 
            varList[24].get_str_value() == "NO")
            return true;
            break;
        case 34:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[22].get_str_value() == "NO" &&
            varList[25].get_str_value() == "YES" && varList[23].get_str_value() == "YES" && 
            varList[24].get_str_value() == "YES")
            return true;
            break;
        case 35:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[22].get_str_value() == "NO" &&
            varList[25].get_str_value() == "NO" && varList[26].get_str_value() == "NO" && 
            varList[23].get_str_value() == "YES" && varList[24].get_str_value() == "NO")
            return true;
            break;
        case 36:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
            varList[4].get_str_value() == "YES" && varList[22].get_str_value() == "NO" &&
            varList[25].get_str_value() == "NO" && varList[26].get_str_value() == "NO" && 
            varList[23].get_str_value() == "YES" && varList[24].get_str_value() == "YES")
            return true;
            break;
        case 37:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "YES" && varList[22].get_str_value() == "NO" &&
                varList[25].get_str_value() == "NO" && varList[26].get_str_value() == "YES" &&
                varList[24].get_str_value() == "NO")
                return true;
                break;
        case 38:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "YES" && varList[22].get_str_value() == "NO" &&
                varList[25].get_str_value() == "NO" && varList[26].get_str_value() == "YES" &&
                varList[24].get_str_value() == "YES")
                return true;
                break;
        case 39:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "YES" && varList[22].get_str_value() == "YES" &&
                varList[26].get_str_value() == "NO" && varList[23].get_str_value() == "NO" &&
                varList[23].get_str_value() == "YES" && varList[24].get_str_value() == "NO")
                return true;
                break;
        case 40:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "YES" && varList[22].get_str_value() == "YES" &&
                varList[26].get_str_value() == "NO" && varList[23].get_str_value() == "YES" &&
                varList[24].get_str_value() == "YES")
                return true;
                break;
        case 41:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "YES" && varList[22].get_str_value() == "YES" &&
                varList[26].get_str_value() == "YES" && varList[24].get_str_value() == "NO")
                return true;
                break;
        case 42:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[4].get_str_value() == "YES" && varList[22].get_str_value() == "YES" &&
                varList[26].get_str_value() == "YES" && varList[24].get_str_value() == "YES")
                return true;
                break;
        case 43:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "NO" && varList[22].get_str_value() == "NO" &&
                varList[25].get_str_value() == "YES" && varList[23].get_str_value() == "YES" &&
                varList[24].get_str_value() == "NO")
                return true;
                break;
        case 44:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "NO" && varList[22].get_str_value() == "NO" &&
                varList[25].get_str_value() == "YES" && varList[23].get_str_value() == "YES" &&
                varList[24].get_str_value() == "YES")
                return true;
                break;
        case 45:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "NO" && varList[22].get_str_value() == "NO" &&
                varList[25].get_str_value() == "NO" && varList[26].get_str_value() == "NO" &&
                varList[23].get_str_value() == "YES" && varList[24].get_str_value() == "NO")
                break;
        case 46:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "NO" && varList[22].get_str_value() == "NO" &&
                varList[25].get_str_value() == "NO" && varList[26].get_str_value() == "NO" &&
                varList[23].get_str_value() == "YES" && varList[24].get_str_value() == "YES")
                break;
        case 47:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "NO" && varList[22].get_str_value() == "NO" &&
                varList[25].get_str_value() == "NO" && varList[26].get_str_value() == "YES" &&
                varList[24].get_str_value() == "NO")
                return true;
                break;
        case 48:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "NO" && varList[22].get_str_value() == "NO" &&
                varList[25].get_str_value() == "NO" && varList[26].get_str_value() == "YES" &&
                varList[24].get_str_value() == "YES")
                return true;
                break;
        case 49:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "NO" && varList[22].get_str_value() == "YES" &&
                varList[26].get_str_value() == "NO" && varList[23].get_str_value() == "YES" &&
                varList[24].get_str_value() == "NO")
                return true;
                break;
        case 50:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "NO" && varList[22].get_str_value() == "YES" &&
                varList[26].get_str_value() == "NO" && varList[23].get_str_value() == "YES" &&
                varList[24].get_str_value() == "YES")
                return true;
                break;
        case 51:
            if(varList[2].get_str_value() == "YEs" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "NO" && varList[22].get_str_value() == "YES" &&
                varList[26].get_str_value() == "YES" && varList[24].get_str_value() == "NO")
                return true;
                break;
        case 52:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "NO" && varList[22].get_str_value() == "YES" &&
                varList[26].get_str_value() == "YES" && varList[24].get_str_value() == "YES")
                return true;
                break;
        case 53:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "YES" && varList[27].get_str_value() == "YES" &&
                varList[28].get_str_value() == "YES" && varList[29].get_str_value() == "YES" &&
                varList[12].get_str_value() == "NO" && varList[30].get_num_value() > 6)
                return true;
                break;
        case 54:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "YES" && varList[27].get_str_value() == "YES" &&
                varList[28].get_str_value() == "YES" && varList[29].get_str_value() == "YES" &&
                varList[12].get_str_value() == "YES")
                return true;
                break;
        case 55:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "YES" && varList[27].get_str_value() == "YES" &&
                varList[28].get_str_value() == "NO" && varList[31].get_str_value() == "NO" &&
                varList[29].get_str_value() == "YES" && varList[12].get_str_value() == "NO" &&
                varList[30].get_num_value() > 6)
                break;
        case 56:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "YES" &&
                varList[35].get_str_value() == "YES" && varList[27].get_str_value() == "YES" &&
                varList[28].get_str_value() == "NO" && varList[31].get_str_value() == "NO" && 
                varList[29].get_str_value() == "YES" && varList[12].get_str_value() == "YES")
                return true;
                break;
        case 57:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "YES" && varList[27].get_str_value() == "YES" &&
                varList[28].get_str_value() == "NO" && varList[31].get_str_value() == "YES" &&
                varList[32].get_str_value() == "YES" && varList[12].get_str_value() == "NO" &&
                varList[30].get_num_value() > 6)
                return true;
                break;
        case 58:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "YES" && varList[27].get_str_value() == "YES" &&
                varList[28].get_str_value() == "NO" && varList[31].get_str_value() == "YES" &&
                varList[32].get_str_value() == "YES" && varList[12].get_str_value() == "YES")
                return true;
                break;
        case 59:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "YES" && varList[27].get_str_value() == "NO" &&
                varList[31].get_str_value() == "NO" && varList[29].get_str_value() == "YES" &&
                varList[12].get_str_value() == "NO" && varList[30].get_num_value() > 6)
                return true;
                break;
        case 60:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "YES" && varList[27].get_str_value() == "NO" &&
                varList[31].get_str_value() == "NO"  && varList[29].get_str_value() == "YES" &&
                varList[12].get_str_value() == "YES")
                return true;
                break;
        case 61:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "YES" && varList[27].get_str_value() == "NO" &&
                varList[31].get_str_value() == "YES" && varList[32].get_str_value() == "YES" &&
                varList[12].get_str_value() == "NO" && varList[30].get_num_value() > 6)
                return true;
                break;
        case 62:
            if(varList[2].get_str_value() == "YES" && varList[3].get_str_value() == "NO" &&
                varList[35].get_str_value() == "YES" && varList[27].get_str_value() == "NO" &&
                varList[31].get_str_value() == "YES" && varList[32].get_str_value() == "YES" &&
                varList[12].get_str_value() == "YES")
                return true;
                break;
        default:
            return false;
            break;
    }
    return false;
}

bool condition_switch_forward(int statementNum, std::vector<Variable> varList)
{
    switch(statementNum){
        case 1:
            if(varList[1].get_str_value() == "NO")
                return true;
            break;
        case 2:
            if(varList[1].get_str_value() == "YES" && varList[2].get_str_value() == "YES" &&
                varList[3].get_num_value() >= 3)
                return true;
            break;
        case 3:
            if(varList[1].get_str_value() == "YES" && varList[2].get_str_value() == "YES" &&
                varList[3].get_num_value() < 3)
                return true;
            break;
        case 4:
            if(varList[1].get_str_value() == "YES" && varList[4].get_str_value() == "YES" &&
                varList[5].get_num_value() > 6)
                return true;
            break;
        case 5:
            if(varList[1].get_str_value() == "YES" && varList[4].get_str_value() == "YES" &&
                varList[5].get_num_value() < 6)
                return true;
            break;
        case 6:
            if(varList[1].get_str_value() == "YES" && varList[6].get_str_value() == "YES" && 
                varList[7].get_str_value() == "NO")
                return true;
            break;
        case 7:
            if(varList[1].get_str_value() == "YES" && varList[6].get_str_value() == "YES" &&
                varList[7].get_str_value() == "YES")
                return true;
            break;
        case 8:
            if(varList[1].get_str_value() == "YES" && varList[8].get_str_value() == "YES" &&
                varList[9].get_num_value() > 10)
                return true;
            break;
        case 9:
            if(varList[1].get_str_value() == "YES" && varList[8].get_str_value() == "YES" &&
                10 > varList[9].get_num_value() >= 1)
                return true;
            break;
        case 10:
            if(varList[1].get_str_value() == "YES" && varList[8].get_str_value() == "YES" &&
                varList[9].get_num_value() == 0 && varList[10].get_str_value() == "YES")
                return true;
            break;
        case 11:
            if(varList[1].get_str_value() == "YES" && varList[8].get_str_value() == "YES" &&
                varList[9].get_num_value() == 0 && varList[10].get_str_value() == "YES")
                return true;
            break;
        default:
            return false;
            break;
    }
    return false;
}

//Function helper for condition_switch_disordertype() to take disorder diagnoses string into an int for switch statements
int disordertype_helper(std::string disorderTemp)
{
    int disorderNumber = 0;
    if(disorderTemp == "NONE")
    {
        disorderNumber = 1;
    }
    else if(disorderTemp == "DISSOCIATIVE IDENTITY DISORDER")
    {
        disorderNumber = 2;
    }
    else if(disorderTemp == "DYSTHYMIA")
    {
        disorderNumber = 3;
    }
    else if(disorderTemp == "BIPOLAR 1")
    {
        disorderNumber = 4;
    }
    else if(disorderTemp == "GENERALIZED ANXIETY DISORDER")
    {
        disorderNumber = 5;
    }
    else if(disorderTemp == "PANIC DISORDER WITH AGORAPHOBIA")
    {
        disorderNumber = 6;
    }
    else if(disorderTemp == "SCHIZOPHRENIA")
    {
        disorderNumber = 7;
    }
    else if(disorderTemp == "SCHIZOAFFECTIVE")
    {
        disorderNumber = 8;
    }
    else if(disorderTemp == "MAJOR DEPRESSIVE DISORDER")
    {
        disorderNumber = 9;
    }
    else
    {
        disorderNumber = -1;
        std::cout << "ERROR IN DISORDERTYPE_HELPER()" << std::endl;
    }
    return disorderNumber;
}

//Function to find the disorder type given what the disorder diagnoses is
std::string condition_switch_disordertype(std::string disorder)
{
    int disorderNumber = disordertype_helper(disorder);
    std::string disorder_type = "";
    switch(disorderNumber){
        case 1:
            disorder_type = "NONE";
            return disorder_type;
            break;
        case 2:
            disorder_type = "PERSONALITY";
            return disorder_type;
            break;
        case 3:
            disorder_type = "MOOD";
            return disorder_type;
            break;
        case 4:
            disorder_type = "MOOD";
            return disorder_type;
            break;
        case 5:
            disorder_type = "ANXIETY";
            return disorder_type;
            break;
        case 6:
            disorder_type = "ANXIETY";
            return disorder_type;
            break;
        case 7:
            disorder_type = "PSYCHOTIC";
            return disorder_type;
            break;
        case 8:
            disorder_type = "PSYCHOTIC";
            return disorder_type;
            break;
        case 9:
            disorder_type = "MOOD";
            return disorder_type;
            break;
        default:
            return disorder_type;
            break;
    }
}