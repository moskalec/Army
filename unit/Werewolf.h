#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Unit.h"
#include "../ability/DefaultAbility.h"

class Werewolf : public Unit {
public:
    Werewolf(const char* title, int hitPoints, int damage);
    virtual ~Werewolf();

    virtual void takeMagicDamage(int dmg);
    void transform();
};

#endif // WEREWOLF_H
