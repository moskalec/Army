#ifndef WARLOCK_ABILITY_H
#define WARLOCK_ABILITY_H

#include <map>
#include "../spell/Spell.h"
#include "../spellcaster/SpellCaster.h"


class Demon;
class SpellCaster;
class Spell;

class WarlockAbility : MagicAbility {
public:
    WarlockAbility(SpellCaster* owner, Spell* spell);
    virtual ~WarlockAbility();

    void changeSpell(Spell* newSpell);
    virtual void cast(SpellCaster* owner, Unit* enemy);
};

#endif // WARLOCK_ABILITY_H
