#ifndef PRIEST_ABILITY_H
#define PRIEST_ABILITY_H

#include <map>
#include "../spell/Spell.h"
#include "../spellcaster/SpellCaster.h"


class SpellCaster;
class Spell;

class PriestAbility : MagicAbility {
public:
    PriestAbility(SpellCaster* owner, Spell* spell);
    virtual ~PriestAbility();

    void changeSpell(Spell* newSpell);
    virtual void cast(SpellCaster* owner, Unit* enemy);
};

#endif // PRIEST_ABILITY_H
