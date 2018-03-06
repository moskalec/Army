#ifndef WEREWOLF_ABILITY_H
#define WEREWOLF_ABILITY_H

#include "Ability.h"

class WerewolfAbility : public Ability {
public:
    WerewolfAbility(Unit* owner);
    virtual ~WerewolfAbility();

};

#endif // WEREWOLF_ABILITY_H
