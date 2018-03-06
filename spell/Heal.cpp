#include "Heal.h"

Heal::Heal(int actionPoints, int cost) : Spell(actionPoints, cost) {}

Heal::~Heal() {}

void Heal::action(Unit* target) {
    target->addHitPoints(this->actionPoints);
}
