#pragma once
#include <vector>
#include <string>
#include <iostream>

enum chains {
    FORWARD,
    BACKWARD
};

extern void initialize_questions(chains, std::vector<std::string> &);
