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

void print_list_values(std::vector<Variable> vector){
    for(int i = 1; i < vector.size(); i++){
        if(vector[i].get_type() == 1){
            printf("NAME: %s VALUE: %s\n", vector[i].get_name().c_str(), vector[i].get_str_value().c_str());
        } else {
            printf("NAME: %s VALUE: %.2f\n ", vector[i].get_name().c_str(), vector[i].get_num_value());
        }
    }
}

extern void intro_directions()
{
    std::cout << "========================================================================================" <<std::endl;
    std::cout << "========================================================================================" <<std::endl;
    std::cout << "========================================================================================" <<std::endl;
    std::cout << "========================================================================================" <<std::endl;
    std::cout << "======================== Mental Health Disorder Diagnostic Tool ========================" <<std::endl;
    std::cout << "========================================================================================" <<std::endl;
    std::cout << "============================ Directions on How to use Tool =============================" <<std::endl;
    std::cout << "========================================================================================" <<std::endl;
    std::cout << "            Enter 'y' for yes, 'n' for no, or a number to answer questions              " <<std::endl;
    std::cout << "========================================================================================" <<std::endl;
    std::cout << "========================================================================================" <<std::endl;
    std::cout << "======================================= Examples =======================================" <<std::endl;
    std::cout << "             Input YES or NO for SUICIDAL IDEATION                                      " <<std::endl;
    std::cout << "             yes                                                                        " <<std::endl;
    std::cout << "             Input a real number for SYMPTOMS < 2 YEARS                                 " <<std::endl;
    std::cout << "             1                                                                          " <<std::endl;
    std::cout << "========================================================================================" <<std::endl;
    std::cout << "========================================================================================" <<std::endl;
    std::cout << "========================================================================================" <<std::endl;
}

extern void intro_treatment()
{
    std::cout << "========================================================================================" <<  std::endl; 
    std::cout << "========================================================================================" <<  std::endl; 
    std::cout << "================================== Treatment Section ==================================="<< std::endl; 
    std::cout << "========================================================================================" <<  std::endl; 
    std::cout << "==================================== Diagnoses for =====================================" << /*Disorder Conclusion Variable <<*/ std::endl; 
    std::cout << "========================================================================================" <<  std::endl; 
}

extern void end_message()
{
    std::cout << "========================================================================================" << std::endl; 
    std::cout << "========================================================================================" << std::endl; 
    std::cout << "================================ End of Mental Disorder Tool ===========================" << std::endl; 
    std::cout << "========================================================================================" << std::endl; 
    std::cout << "=========================================== Exit =======================================" << std::endl; 
    std::cout << "========================================================================================" << std::endl; 
}

extern std::string to_upper_case(std::string stringTemp)
{   
    for(int i = 0; i < stringTemp.length(); i++)
    {
        stringTemp[i] = toupper(stringTemp[i]);
    }
    return stringTemp; 
}

extern void diagnoseOutput(std::string inputDisorder)
{
    std::cout<< "Patient has been diagnosed with " << inputDisorder << std::endl;
}