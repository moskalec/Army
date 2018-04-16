#include "MagicState.h"

MagicState::MagicState(int mana, bool battleMagician) : mana(mana), manaLimit(mana), battleMagician(battleMagician) {}

MagicState::~MagicState() {}

int MagicState::getMana() const {
    return this->mana;
}

int MagicState::getManaLimit() const {
    return this->manaLimit;
}

bool MagicState::getBattleMagician() {
    return this->battleMagician;
}

void MagicState::addMana(int extra) {
    int total = this->mana + extra;
    if ( total > this->manaLimit ) {
        this->mana = this->manaLimit;
        return;
    }
    this->mana = total;
}

void MagicState::spendMana(int cost) {
    if ( cost > this->mana ) {
        throw OutOfManaException();
    }
    this->mana -= cost;
}
