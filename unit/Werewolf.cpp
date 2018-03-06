#include "Werewolf.h"

Werewolf::Werewolf(const char* title, int hitPoints, int damage):
        Unit(title, hitPoints, damage) {
    this->ability = new DefaultAbility(this);//WerewolfAbility(this);
}

Werewolf::~Werewolf() {}


void Werewolf::takeMagicDamage(int dmg) {
    this->state->takeMagicDamage(this->state->getTitle() == "Wolf" ? dmg * 2 : dmg);
}

void Werewolf::transform() {
    this->ensureIsAlive();
    delete(this->state);
    this->state = new State("Wolf", 250, 50);
}