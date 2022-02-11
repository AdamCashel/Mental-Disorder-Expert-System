#include "dialogue.h"
#include <fstream>

const int F_QUESTION_COUNT = 7;
const int F_RESPONSE_COUNT = 11;

const int B_QUESTION_COUNT = 35;
const int B_RESPONSE_COUNT = 8;

void initialize_questions(int chain, std::vector<std::string> &vector) {
    std::ifstream inputFile;
    std::string line;

    if (chain == FORWARD) {
        inputFile.open("./data/forward-chaining-questions.txt");

        for(int i = 0; i < F_QUESTION_COUNT; i++){
            getline(inputFile, line);
            vector[i] = line; 
        }

    } else if (chain == BACKWARD) {
        inputFile.open("./data/backward-chaining-questions.txt");

        for(int i = 0; i < B_QUESTION_COUNT; i++){
            getline(inputFile, line);
            vector[i] = line; 
        }
        
    } else {
        std::cerr << "Invalid chain value" << std::endl;
    }

    inputFile.close();
}

void initialize_responses(int chain, std::vector<std::string> &vector) {
    std::ifstream inputFile;
    std::string line;

    if (chain == FORWARD) {
        inputFile.open("./data/forward-chaining-responses.txt");

        for(int i = 0; i < F_RESPONSE_COUNT; i++){
            getline(inputFile, line);
            vector[i] = line; 
        }

    } else if (chain == BACKWARD) {
        inputFile.open("./data/backward-chaining-responses.txt");

        for(int i = 0; i < B_RESPONSE_COUNT; i++){
            getline(inputFile, line);
            vector[i] = line; 
        }
        
    } else {
        std::cerr << "Invalid chain value" << std::endl;
    }

    inputFile.close();
}
