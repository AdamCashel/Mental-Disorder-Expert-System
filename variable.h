#pragma once
#include <string>

// Variable class
// Used for variable and clause variable list
// Can store the name of variable and a value of either type string or double
// getters and setters to access values
class Variable{
    private:
        std::string name;

        // variables have two types for values
        // type 0: no type
        // type 1: YES OR NO
        // type 2: numberical value
        int type;

        std::string str_value;
        double d_value;
        
    public:
        Variable(int);

        std::string get_name() { return name; };
        int get_type() { return type; };
        std::string get_str_value() { return str_value; };
        double get_num_value() { return d_value; };

        void set_name(std::string);
        void set_type(int);
        void set_str_value(std::string);
        void set_num_value(double);
        

};