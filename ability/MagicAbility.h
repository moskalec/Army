#ifndef MAGIC_ABILITY_H
#define MAGIC_ABILITY_H

#include "../spell/Spell.h"
#include "../spellcaster/SpellCaster.h"
#include "../spell/SpellBook.h"


class SpellCaster;

class MagicAbility {
    protected:
        SpellCaster* owner;
        Spell* spell;
        SpellBook* spellBook;

    public:
        MagicAbility(SpellCaster* owner, SpellBook* spellBook); //, Spell* spell
        virtual ~MagicAbility();

        void changeSpell(int spellName); //Spell* newSpell);
        virtual void cast(Unit* enemy);
};

#endif // MAGIC_ABILITY_H
