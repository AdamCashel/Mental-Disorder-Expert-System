#include "interface.h"
// print a vector of strings
void print_list(std::vector<std::string> vector){
    for(auto x : vector)
        std::cout << x << std::endl;
}

// print a vector of type Variable (prints the name)
void print_list(std::vector<Variable> vector){
    for(auto x : vector){
        std::cout << x.get_name() << std::endl;
    }
}

extern void intro_directions()
{
    std::cout << "-------------------Mental Health Disorder Diagnostic Tool-------------------" <<std::endl;
    std::cout << "Enter 'y' for yes, 'n' for no, or a number to answer questions" <<std::endl;
}

extern std::string to_upper_case(std::string stringTemp)
{
    for(int i = 0; i < stringTemp.length(); i++)
    {
        stringTemp[i] = toupper(stringTemp[i]);
    }
}