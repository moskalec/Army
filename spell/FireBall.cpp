#include "FireBall.h"

FireBall::FireBall(int actionPoints, int cost) : Spell(actionPoints, cost) {}

FireBall::~FireBall() {}

void FireBall::action(SpellCaster* owner, Unit* target) {
    if ( owner->getBattleMagician() ) {
        target->takeMagicDamage(this->getActionPoints());
    } else {
        if (target->isVampire()) {
            target->takeMagicDamage(this->getActionPoints() * 2);
        } else {
            target->takeMagicDamage(this->getActionPoints() / 2);
        }
    }
}
