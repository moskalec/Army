#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"
#include "../ability/DefaultAbility.h"

class Soldier : public Unit {
    public:
        Soldier(const char* title, int hitPoints, int damage);
        virtual ~Soldier();
};

#endif // SOLDIER_H
