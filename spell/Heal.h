#ifndef HEAL_H
#define HEAL_H

#include "Spell.h"
#include "../spellcaster/SpellCaster.h"

class SpellCaster;

class Heal : public Spell {
    public:
        Heal(int actionPoints, int cost);
        virtual ~Heal();
        virtual void action(SpellCaster* owner, Unit* target);
};

#endif // HEAL_H
