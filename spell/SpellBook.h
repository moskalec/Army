#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <map>

#include "Spell.h"
#include "FireBall.h"
#include "Heal.h"

enum spells {FIRE_BALL, HEAL};

class SpellBook {
    protected:
        std::map<int, Spell*>* spellBook;
//        std::map<int, Spell*>::iterator it;
    public:
        SpellBook();
        ~SpellBook();
        Spell* changeSpell(int spellName);

};

#endif //SPELLBOOK_H
