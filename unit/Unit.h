#ifndef UNIT_H
#define UNIT_H

#include "../state/State.h"
#include "../ability/Ability.h"
#include "../interface/Observer.h"
#include "../interface/Observerable.h"

class Ability;

enum SPELL_NAME {
    FIRE_BALL=1,
    HEAL
};

class Unit : public Observer, public Observerable {
    protected:
        State* state;
        Ability* ability;

    public:
        Unit(const char* title, int hitPoints, int damage);
        virtual ~Unit();

        void ensureIsAlive();

        const char* getTitle() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;

        void addHitPoints(int hp);
        void takeDamage(int dmg);

        bool isVampire();
        void turnVampire();

        virtual void transform();
        virtual void takeMagicDamage(int dmg);
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

#endif // UNIT_H
