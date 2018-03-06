#ifndef HEAL_H
#define HEAL_H

#include "Spell.h"

class Heal : public Spell {
    public:
        Heal(int actionPoints, int cost);
        virtual ~Heal();
        virtual void action(Unit* target);
};

#endif // HEAL_H
