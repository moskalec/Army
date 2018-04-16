#include "Demon.h"

Demon::Demon(Unit* owner, const char* title, int hitPoints, int damage):
        Soldier(title, hitPoints, damage), owner(owner) {
}

Demon::~Demon() {}

void Demon::ensureHisOwner(Unit* enemy) {
    if ( enemy == this->owner ) {
        throw UnitCantAttackHisOwnerException();
    }
}

void Demon::attack(Unit* enemy) {
    ensureHisOwner(enemy);

    Unit::attack(enemy);
}