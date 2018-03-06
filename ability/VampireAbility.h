#ifndef VAMPIRE_ABILITY_H
#define VAMPIRE_ABILITY_H

#include "Ability.h"

class VampireAbility : public Ability {
public:
    VampireAbility(Unit* owner);
    virtual ~VampireAbility();

    virtual void attack(Unit* enemy);
    virtual void counterAttack(Unit* enemy);
};

#endif // VAMPIRE_ABILITY_H
