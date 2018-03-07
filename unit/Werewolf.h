#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Unit.h"
#include "../ability/DefaultAbility.h"

class Werewolf : public Unit {
public:
    Werewolf(const char* title, int hitPoints, int damage);
    virtual ~Werewolf();

    void takeMagicDamage(int dmg);
    void transform(State* newState);
};

#endif // WEREWOLF_H
