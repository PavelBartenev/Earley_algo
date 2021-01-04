#pragma once

#include "Production.h"
#include "Situation.h"


struct Situation {
    Production rule;
    int position;
    int dot_position;

    Situation();

    Situation(const Production& rule, int position, int dot_position);

    bool operator <(const Situation& other) const;
};
