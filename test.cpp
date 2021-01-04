#include "pch.h"
#include <gtest/gtest.h>
#include "Algo.h"
#include "Grammar.h"
#include "Production.h"
#include "Situation.h"


TEST(AlgoFunc, Scan) {
	FormalGrammar grammar;
	Algo earley{ grammar };

	earley.word = "test";
	Situation situation{ {'S', "tS"}, 0, 0 };
	earley.parse_list.resize(2);
	earley.parse_list[0].insert(situation);

	earley.scan(1);

	situation.dot_position += 1;

	ASSERT_TRUE(earley.parse_list[1].count(situation));
}

TEST(AlgoFunc, Complete) {
	FormalGrammar grammar;
	Algo earley{ grammar };

	earley.word = "test";
	Situation situation{ {'S', "tS"}, 0, 2 };
	earley.parse_list.resize(2);
	earley.parse_list[1].insert(situation);

	Situation another_situation{ {'S', "qS"}, 0, 1 };
	earley.parse_list[0].insert(another_situation);

	earley.complete(1);

	another_situation.dot_position += 1;

	ASSERT_TRUE(earley.parse_list[1].count(another_situation));
}

TEST(AlgoFunc, Predict) {
	FormalGrammar grammar;
	grammar.add_production({ 'S', "testing" });
	Algo earley{ grammar };

	earley.word = "test";
	Situation situation{ {'W', "tS"}, 0, 1 };
	earley.parse_list.resize(3);
	earley.parse_list[2].insert(situation);

	earley.predict(2);

	ASSERT_TRUE(earley.parse_list[2].count({ {'S', "testing"}, 2, 0 }));
}

TEST(General, Check_word) {
	FormalGrammar grammar;
	grammar.start_symbol = 'S';
	grammar.add_production({ 'S', "(S)S" });
	grammar.add_production({ 'S', "" });

	Algo earley{ grammar };

	ASSERT_TRUE(earley.check_word("()(())()"));
	ASSERT_TRUE(earley.check_word(""));
	ASSERT_FALSE(earley.check_word("()))((()"));
	ASSERT_FALSE(earley.check_word("("));
}