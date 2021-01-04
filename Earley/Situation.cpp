#include "Situation.h"
#include "Production.h"

Situation::Situation() = default;

Situation::Situation(const Production & rule, int position, int dot_position)
    : rule{ rule }, position{ position }, dot_position{ dot_position } {}

bool Situation::operator <(const Situation & other) const {
    return (position < other.position ||
        position == other.position && dot_position < other.dot_position ||
        position == other.position && dot_position == other.dot_position && rule < other.rule);
}