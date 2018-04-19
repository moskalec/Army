#ifndef WARLOCK_H
#define WARLOCK_H

#include "SpellCaster.h"
#include "../spell/FireBall.h"
#include "../unit/Demon.h"

class Warlock : public SpellCaster {
public:
    Warlock(const char* title, int hitPoints, int damage, int mana);
    virtual ~Warlock();

    void changeSpell(SPELL_NAME newSpell);

    Demon* summonDemon(Unit* owner);
};

#endif //WARLOCK_H
