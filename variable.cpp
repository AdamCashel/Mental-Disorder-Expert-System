#include "variable.h"

Variable::Variable(int type){
    this->name = "";
    this->str_value = "";
    this->d_value = 0.0;
    this->type = type;
}

void Variable::set_name(std::string name){
    this->name = name;
}

void Variable::set_str_value(std::string value){
    this->str_value = value;
}

void Variable::set_num_value(double value){
    this->d_value = value;
}