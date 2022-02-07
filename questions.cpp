#include "b_questions.h"

void initialize_questions(int chain, std::vector<std::string> &vector){
    if(chain == FORWARD){
        // TODO:
        // Implement the rest of the questions and responses for forward chaining
    }
    else if(chain == BACKWARD){
        vector[0] = "Does the patient have of show symptoms of a mental disorder?";
        vector[1] = "Patient does not meet criteria.";
        vector[2] = "Patient possibly qualifies for a mental disorder.";
        vector[3] = "Does the patient have suicial ideation?";
        // TODO:
        // Implement the rest of the questions and responses for backward chaining
    }
    else{
        std::cerr << "Invalid chain value" << std::endl;
    }
}

