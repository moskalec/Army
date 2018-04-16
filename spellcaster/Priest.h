#ifndef PRIEST_H
#define PRIEST_H

#include "SpellCaster.h"
#include "../spell/FireBall.h"


class Priest : public SpellCaster {
public:
    Priest(const char* title, int hitPoints, int damage, int mana);
    virtual ~Priest();

    void changeSpell(Spell* newSpell);
};

#endif // PRIEST_H
