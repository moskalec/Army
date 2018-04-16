#include "Wizard.h"

Wizard::Wizard(const char* title, int hitPoints, int damage, int mana)
    : SpellCaster(title, hitPoints, damage, mana, true) {
        this->magicAbility = new MagicAbility(this, new FireBall(30, 30));
}

Wizard::~Wizard() {}

void Wizard::changeSpell(Spell* newSpell) {
    SpellCaster::changeSpell(newSpell);
}