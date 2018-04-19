#ifndef SPELL_BOOK_H
#define SPELL_BOOK_H

#include <map>
#include "../spellcaster/SpellCaster.h"

class Spell;

class SpellBook {
    protected:
        std::map<SPELL_NAME, Spell*>* spellBook;
    public:
        SpellBook();
        ~SpellBook();

        const std::map<SPELL_NAME, Spell*>& getSpellBook() const;
        Spell* changeSpell(SPELL_NAME newSpell);
};
#endif //SPELL_BOOK_H
