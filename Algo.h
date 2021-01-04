#pragma once

#include <string>
#include <vector>
#include <set>
#include "Situation.h"
#include "Grammar.h"


class Algo {
public:
    FormalGrammar grammar;
    std::string word;
    std::vector<std::set<Situation>> parse_list;


    Algo(const FormalGrammar& grammar);

    bool check_word(const std::string& new_word);

    void scan(int situations_set_num);

    void complete(int situations_set_num);

    void predict(int situations_set_num);
};
