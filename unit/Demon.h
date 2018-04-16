#ifndef DEMON_H
#define DEMON_H

#include "Soldier.h"

class Demon : public Soldier {
    protected:
        Unit* owner;

        void ensureHisOwner(Unit* enemy);

public:
    Demon(Unit* owner, const char* title, int hitPoints, int damage);
    virtual ~Demon();


    virtual void attack(Unit* enemy);
};


#endif // DEMON_H
