#include "Production.h"
#include <string>


Production::Production() = default;

Production::Production(char nonterminal, const std::string& result)
    : nonterminal{ nonterminal }, result{ result } {}

bool Production::operator <(const Production& other) const {
    return (nonterminal < other.nonterminal ||
        nonterminal == other.nonterminal && result < other.result);
}