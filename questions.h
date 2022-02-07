#pragma once
#include <vector>
#include <string>
#include <iostream>

extern const int F_QUESTION_COUNT;
extern const int B_QUESTION_COUNT;

enum chains {
    FORWARD,
    BACKWARD
};

extern void initialize_questions(int, std::vector<std::string> &);
