#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "SpellCaster.h"
#include "../spell/FireBall.h"

#include "../interface/Observerable.h"

class Necromancer : public SpellCaster {
    public:
        Necromancer(const char* title, int hitPoints, int damage, int mana);
        virtual ~Necromancer();

        virtual void attack(Unit* enemy);
        virtual void update(Observerable* customer);

        void changeSpell(Spell* newSpell);
};

#endif // NECROMANCER_H
