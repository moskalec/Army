#ifndef SPELL_H
#define SPELL_H

#include "../unit/Unit.h"
#include "../spellcaster/SpellCaster.h"

class SpellCaster;

class Spell {
    protected:
        int actionPoints;
        int cost;

    public:
        Spell(int actionPoints, int cost);
        virtual ~Spell();

        int getActionPoints() const;
        int getCost() const;

        virtual void action(SpellCaster* owner, Unit* target);
};

#endif // SPELL_H
