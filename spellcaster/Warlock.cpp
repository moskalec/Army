#include "Warlock.h"

Warlock::Warlock(const char* title, int hitPoint, int damage, int manaPoint) : SpellCaster(title, hitPoint, damage, manaPoint, true, true) {
    this->magicAbility = new MagicAbility(this, new FireBall(30, 30));
}

Warlock::~Warlock() {}


void Warlock::changeSpell(Spell* newSpell) {
    SpellCaster::changeSpell(newSpell);
}

Demon* Warlock::summonDemon(Unit* owner) {
    Demon* demon = new Demon(owner, "Demon", this->getHitPointsLimit(), this->getDamage());
    return demon;
}