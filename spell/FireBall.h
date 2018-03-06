#ifndef FIRE_BALL_H
#define FIRE_BALL_H

#include "Spell.h"

class FireBall : public Spell {
    public:
        FireBall(int actionPoints, int cost);
        virtual ~FireBall();
        virtual void action(Unit* target);
};

#endif // FIRE_BALL_H
