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