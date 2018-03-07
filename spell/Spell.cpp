#include "Spell.h"

Spell::Spell(int actionPoints, int cost)
    : actionPoints(actionPoints), cost(cost) {}

Spell::~Spell() {}

int Spell::getActionPoints() const {
    return this->actionPoints;
}

int Spell::getCost() const {
    return this->cost;
}
void Spell::action(Unit* target) {
}