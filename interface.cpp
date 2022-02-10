#include "interface.h"

void print_list(std::vector<std::string> vector){
    for(auto x : vector)
        std::cout << x << std::endl;
}

void print_list(std::vector<Variable> vector){
    for(auto x : vector){
        std::cout << x.get_name() << std::endl;
    }
}