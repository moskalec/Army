#include "FireBall.h"

FireBall::FireBall(int actionPoints, int cost) : Spell(actionPoints, cost) {}

FireBall::~FireBall() {}

void FireBall::action(SpellCaster* owner, Unit* target) {
    if ( owner->getIsWarlock() ) {
        target->takeMagicDamage(this->getActionPoints() / 2);
    } else if ( owner->getBattleMagician() ) {
        target->takeMagicDamage(this->getActionPoints());
    } else if ( !owner->getBattleMagician() ) {
        if (target->isVampire()) {
            target->takeMagicDamage(this->getActionPoints() * 2);
        } else {
            target->takeMagicDamage(this->getActionPoints() / 2);
        }
    }
}
