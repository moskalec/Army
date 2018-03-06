#include "DefaultAbility.h"

DefaultAbility::DefaultAbility(Unit* owner): Ability(owner) {}

DefaultAbility::~DefaultAbility() {}

void DefaultAbility::attack(Unit* enemy) {
    this->Ability::attack(enemy);
}
