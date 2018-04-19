#include "Wizard.h"

Wizard::Wizard(const char* title, int hitPoints, int damage, int mana)
    : SpellCaster(title, hitPoints, damage, mana, true, false) {
        this->magicAbility = new MagicAbility(this, new FireBall(30, 30));
}

Wizard::~Wizard() {}

void Wizard::changeSpell(SPELL_NAME newSpell) {
    SpellCaster::changeSpell(newSpell);
}