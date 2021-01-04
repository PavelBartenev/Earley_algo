#include "Grammar.h"
#include "Production.h"
#include <string>
#include <set>


FormalGrammar::FormalGrammar() = default;

FormalGrammar::FormalGrammar(const std::set<char>& terminals, const std::set<char>& nonterminals,
    char start_symbol, const std::set<Production> productions)
    : terminals{ terminals }, nonterminals{ nonterminals },
    start_symbol{ start_symbol }, productions{ productions } {}

void FormalGrammar::add_production(const Production& prod) {
    productions.insert(prod);
}

void FormalGrammar::add_nonterminal(char nonterm) {
    nonterminals.insert(nonterm);
}

void FormalGrammar::add_terminal(char term) {
    terminals.insert(term);
}