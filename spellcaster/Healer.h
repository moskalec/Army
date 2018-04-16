#ifndef HEALER_H
#define HEALER_H

#include "SpellCaster.h"
#include "../spell/FireBall.h"


class Healer : public SpellCaster {
public:
    Healer(const char* title, int hitPoints, int damage, int mana);
    virtual ~Healer();

    void changeSpell(Spell* newSpell);
};

#endif // HEALER_H
