#ifndef MAGIC_STATE_H
#define MAGIC_STATE_H

#include <iostream>
#include "../exceptions.h"

class MagicState {
    protected:
        int mana;
        int manaLimit;
        bool battleMagician;
        bool isWarlock;

    public:
        MagicState(int mana, bool battleMagician, bool isWarlock);
        virtual ~MagicState();

        int getMana() const;
        int getManaLimit() const;
        bool getBattleMagician();
        bool getIsWarlock();

        void addMana(int extra);
        void spendMana(int cost);
};

#endif // MAGIC_STATE_H
