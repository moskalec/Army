#ifndef MAGIC_STATE_H
#define MAGIC_STATE_H

#include <iostream>
#include "../exceptions.h"

class MagicState {
    protected:
        int mana;
        int manaLimit;
        bool battleMagician;

    public:
        MagicState(int mana, bool battleMagician);
        virtual ~MagicState();

        int getMana() const;
        int getManaLimit() const;
        bool getBattleMagician();

        void addMana(int extra);
        void spendMana(int cost);
};

#endif // MAGIC_STATE_H
