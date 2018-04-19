#ifndef FIRE_BALL_H
#define FIRE_BALL_H

#include "Spell.h"
#include "../spellcaster/SpellCaster.h"

class SpellCaster;

class FireBall : public Spell {
    public:
        FireBall(int actionPoints, int cost);
        virtual ~FireBall();
        virtual void action(SpellCaster* owner, Unit* target);
};

#endif // FIRE_BALL_H
