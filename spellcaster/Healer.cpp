#include "Healer.h"

Healer::Healer(const char* title, int hitPoints, int damage, int mana)
        : SpellCaster(title, hitPoints, damage, mana, false, false) {
    this->magicAbility = new MagicAbility(this, new FireBall(30, 30));
}

Healer::~Healer() {}

void Healer::changeSpell(Spell* newSpell) {
    SpellCaster::changeSpell(newSpell);
}