#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "Grammar.h"
#include "Production.h"
#include "Situation.h"
#include "Algo.h"


int main() 
{
    FormalGrammar grammar;
    char start_symbol = '@';

    std::cout << "Enter the start symbol of your grammar:\n";
    while (start_symbol == '@') {
        std::cin >> start_symbol;
        if (start_symbol == '@')
            std::cout << "This symbol is reserved. Please, choose another one:\n";
    }

    grammar.start_symbol = start_symbol;

    int productions_num = 0;
    std::cout << "Enter the number of production rules:\n";
    std::cin >> productions_num;

    std::cout << "Enter the production rules one per line in format: \"Nonterminal Product\"\n(for empty word use '1')\n";

    char nonterm = '@';
    std::string product;
    std::string rule;

    std::cin.ignore();
    for (int i = 0; i < productions_num; ++i) {
        std::getline(std::cin, rule, std::cin.widen('\n'));

        for (char letter : rule) {
            if (letter == ' ')
                continue;
            if (nonterm == '@')
                nonterm = letter;
            else
                product += letter;
        }

        if (product == "1")
            product = "";

        grammar.add_production({ nonterm, product });

        product.clear();
        nonterm = '@';
    }

    std::cout << "Enter the list of used nonterminal symbols without spaces:\n";
    std::string nonterminals;
    std::cin >> nonterminals;
    for (char nonterm : nonterminals)
        grammar.add_nonterminal(nonterm);

    std::cout << "Enter the list of used terminal symbols without spaces:\n";
    std::string terminals;
    std::cin >> terminals;
    for (char term : terminals)
        grammar.add_terminal(term);

    Algo earley{ grammar };

    int words_num = 0;
    std::cout << "Enter the number of words you want to check and then enter words one per line:\n";
    std::cin >> words_num;

    std::string word;
    std::vector<std::pair<std::string, std::string>> results;
    for (int i = 0; i < words_num; ++i) {
        std::cin >> word;
        results.push_back(std::make_pair(word, (earley.check_word(word) ? "Yes" : "No")));
    }

    std::cout << "\n";
    for (auto& word_check : results)
        std::cout << word_check.first << " - " << word_check.second << "\n";

    return 0;
}
