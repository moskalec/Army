#ifndef MAGIC_ABILITY_H
#define MAGIC_ABILITY_H

#include "../spellcaster/SpellCaster.h"
#include "../spell/Spell.h"
#include "../spell/SpellBook.h"


class SpellCaster;
class Spell;
class SpellBook;

enum SPELL_NAME;

class MagicAbility {
    protected:
        SpellCaster* owner;
        Spell* spell;
        SpellBook* spellBook;
    public:
        MagicAbility(SpellCaster* owner, Spell* spell);
        virtual ~MagicAbility();

        void changeSpell(SPELL_NAME newSpell);
        void cast(SpellCaster* owner, Unit* enemy);
};

#endif // MAGIC_ABILITY_H
