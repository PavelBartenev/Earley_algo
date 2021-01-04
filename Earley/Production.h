#pragma once

#include <string>


struct Production {
    char nonterminal;
    std::string result;

    Production();

    Production(char nonterminal, const std::string& result);

    bool operator <(const Production& other) const;
};
