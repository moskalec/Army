#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H

#include "../unit/Unit.h"
#include "../ability/MagicAbility.h"
#include "../state/MagicState.h"
#include "../ability/DefaultAbility.h"

class MagicAbility;

class SpellCaster: public Unit {
    protected:
        MagicState* magicState;
        MagicAbility* magicAbility;

    public:
        SpellCaster(const char* title, int hitPoints, int damage, int mana);
        virtual ~SpellCaster();

        int getMana() const;
        int getManaLimit() const;

        void addMana(int extra);
        void spendMana(int cost);

        void changeSpell(int newSpell);
        virtual void cast(Unit* enemy);

};

#endif // SPELL_CASTER_H
