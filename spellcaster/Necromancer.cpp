#include "Necromancer.h"

Necromancer::Necromancer(const char* title, int hitPoints, int damage, int mana)
        :  SpellCaster(title, hitPoints, damage, mana, true, false) {
    this->magicAbility = new MagicAbility(this, new FireBall(30, 30));
}

Necromancer::~Necromancer() {}

void Necromancer::changeSpell(Spell* newSpell) {
    SpellCaster::changeSpell(newSpell);
}

void Necromancer::attack(Unit* enemy) {
    Unit::attack(enemy);
    this->addObserverable(enemy);
}

void Necromancer::update(Observerable* enemy) {
    Observer::update(enemy);

    this->addHitPoints( this->getHitPointsLimit() / 10 );
}