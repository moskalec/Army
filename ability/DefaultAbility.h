#ifndef DEFAULT_ABILITY_H
#define DEFAULT_ABILITY_H

#include "Ability.h"

class DefaultAbility : public Ability {
    public:
        DefaultAbility(Unit* owner);
        virtual ~DefaultAbility();
        
        virtual void attack(Unit* enemy);
};

#endif // DEFAULT_ABILITY_H
