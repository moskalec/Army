#include "Berserker.h"

Berserker::Berserker(const char* title, int hitPoints, int damage):
        Unit(title, hitPoints, damage) {
    this->ability = new DefaultAbility(this);
}

void Berserker::takeMagicDamage(int dmg) {
}


Berserker::~Berserker() {}
