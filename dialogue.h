#pragma once
#include <iostream>
#include <string>
#include <vector>

// FORWARD CHAINING VARIABLES
extern const int F_QUESTION_COUNT;
extern const int F_RESPONSE_COUNT;

// BACKWARD CHAINING VARIABLES
extern const int B_QUESTION_COUNT;
extern const int B_RESPONSE_COUNT;

enum chains { FORWARD, BACKWARD };

// function: initialize_questions
// description:
//  will load a vector of strings with the questions
//  that will be used when gathering user input
// params:
//   first: chain value of type int (FORWARD/BACKWARD)
//   second: vector of strings to be initialized
extern void initialize_questions(int, std::vector<std::string> &);

// function: initialize_responses
// description:
//  will load a vector of strings with the responses
//  that will be used when diagnosing the patient or
//  finding a treatment
// params:
//   first: chain value of type int (FORWARD/BACKWARD)
//   second: vector of strings to be initialized
extern void initialize_responses(int, std::vector<std::string> &);
