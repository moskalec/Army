#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H

#include "../unit/Unit.h"
#include "../ability/MagicAbility.h"
#include "../state/MagicState.h"
#include "../ability/DefaultAbility.h"

class MagicAbility;
class Spell;

class SpellCaster: public Unit {
    protected:
        MagicState* magicState;
        MagicAbility* magicAbility;

    public:
        SpellCaster(const char* title, int hitPoints, int damage, int mana, bool battleMagician, bool isWarlock);
        virtual ~SpellCaster();

        int getMana() const;
        int getManaLimit() const;
        bool getBattleMagician() const;
        bool getIsWarlock() const;

        void addMana(int extra);
        void spendMana(int cost);

        void changeSpell(SPELL_NAME newSpell);
        virtual void cast(SpellCaster* owner, Unit* enemy);

};

#endif // SPELL_CASTER_H
