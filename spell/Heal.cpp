#include "Heal.h"

Heal::Heal(int actionPoints, int cost) : Spell(actionPoints, cost) {}

Heal::~Heal() {}

void Heal::action(SpellCaster* owner, Unit* target) {
    if ( owner->getBattleMagician() ) {
        target->addHitPoints(this->getActionPoints() / 2);
    } else {
        target->addHitPoints(this->getActionPoints() );
    }
}