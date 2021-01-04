#pragma once

#include <string>
#include <set>
#include "Production.h"


struct FormalGrammar {
    std::set<char> terminals;
    std::set<char> nonterminals;

    char start_symbol;
    std::set<Production> productions;

    FormalGrammar();

    FormalGrammar(const std::set<char>& terminals, const std::set<char>& nonterminals,
        char start_symbol, const std::set<Production> productions);

    void add_production(const Production& prod);

    void add_nonterminal(char nonterm);

    void add_terminal(char term);
};