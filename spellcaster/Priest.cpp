#include "Priest.h"

Priest::Priest(const char* title, int hitPoints, int damage, int mana)
        : SpellCaster(title, hitPoints, damage, mana, false, false) {
    this->magicAbility = new MagicAbility(this, new FireBall(30, 30));
}

Priest::~Priest() {}

void Priest::changeSpell(Spell* newSpell) {
    SpellCaster::changeSpell(newSpell);
}