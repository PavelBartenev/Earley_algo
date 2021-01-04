#include "Algo.h"
#include <string>
#include <vector>
#include <set>
#include "Situation.h"
#include "Grammar.h"


Algo::Algo(const FormalGrammar& grammar)
        : grammar{ grammar } {}


void Algo::scan(int situations_set_num) {
    if (situations_set_num == 0)
        return;

    for (auto& situation : parse_list[situations_set_num - 1]) {
        if (situation.dot_position == situation.rule.result.length())
            continue;

        if (situation.rule.result[situation.dot_position] == word[situations_set_num - 1])
            parse_list[situations_set_num].insert({ situation.rule, situation.position, situation.dot_position + 1 });
    }
}

void Algo::complete(int situations_set_num) {
    std::set<Situation> situations_to_insert;

    for (auto& situation : parse_list[situations_set_num]) {
        if (situation.dot_position == situation.rule.result.length())
            for (auto& another_situation : parse_list[situation.position]) {
                if (another_situation.dot_position == another_situation.rule.result.length())
                    continue;

                if (another_situation.rule.result[another_situation.dot_position] == situation.rule.nonterminal)
                    situations_to_insert.insert({ another_situation.rule, another_situation.position, another_situation.dot_position + 1 });
            }
    }

    for (auto& situation : situations_to_insert)
        parse_list[situations_set_num].insert(situation);
}

void Algo::predict(int situations_set_num) {
    std::set<Situation> situations_to_insert;

    for (auto& situation : parse_list[situations_set_num]) {
        if (situation.dot_position == situation.rule.result.length())
            continue;

        for (auto& rule : grammar.productions)
            if (situation.rule.result[situation.dot_position] == rule.nonterminal)
                situations_to_insert.insert({ rule, situations_set_num, 0 });
    }

    for (auto& situation : situations_to_insert)
        parse_list[situations_set_num].insert(situation);
}

bool Algo::check_word(const std::string& new_word) {
    word = new_word;
    parse_list.clear();
    parse_list.resize(word.length() + 1);

    char old_start_symbol = grammar.start_symbol;
    grammar.nonterminals.insert('@');
    grammar.start_symbol = '@';

    Production new_rule = { '@', std::string{old_start_symbol} };
    grammar.productions.insert(new_rule);
    parse_list[0].insert({ new_rule, 0, 0 });

    for (int situations_set_num = 0; situations_set_num <= word.length(); ++situations_set_num) {
        scan(situations_set_num);

        int size = 0;
        while (size != parse_list[situations_set_num].size()) {
            size = parse_list[situations_set_num].size();
            complete(situations_set_num);
            predict(situations_set_num);
        }
    }

    return parse_list.back().count({ new_rule, 0, 1 });
}