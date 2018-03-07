#include "Werewolf.h"

Werewolf::Werewolf(const char* title, int hitPoints, int damage):
        Unit(title, hitPoints, damage) {
    this->ability = new DefaultAbility(this);//WerewolfAbility(this);
}

Werewolf::~Werewolf() {}


void Werewolf::takeMagicDamage(int dmg) {
    if( this->getTitle() == "Wolf") {
        Unit::takeMagicDamage(dmg*2);
    } else {
        Unit::takeMagicDamage(dmg);
    }
}

void Werewolf::transform(State* newState) {
    this->ensureIsAlive();
    delete(this->state);
    this->state = newState;
}