#ifndef MAGIC_ABILITY_H
#define MAGIC_ABILITY_H

#include <map>
#include "../spell/Spell.h"
#include "../spellcaster/SpellCaster.h"


class SpellCaster;

class MagicAbility {
    protected:
        SpellCaster* owner;
        Spell* spell;

    public:
        MagicAbility(SpellCaster* owner, Spell* spell);
        virtual ~MagicAbility();

        void changeSpell(Spell* newSpell);
        virtual void cast(Unit* enemy);
};

#endif // MAGIC_ABILITY_H
