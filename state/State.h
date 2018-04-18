#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../exceptions.h"

#include "../interface/Observerable.h"

class Observerable;


class State {
    protected:
        const char* title;
        int hitPoints;
        int hitPointsLimit;
        int damage;

        bool vampire;

        void _takeDamage(int dmg);
        void _takeMagicDamage(int dmg);

    public:
        State(const char* title, int hitPoints, int damage);
        virtual ~State();

        void ensureIsAlive();

        const char* getTitle() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;

        void addHitPoints(int hp);
        void takeDamage(int dmg);
        void takeMagicDamage(int dmg);

        bool isVampire();
        void turnVampire();
};

#endif // STATE_H
