#include "MagicState.h"

MagicState::MagicState(int mana, bool battleMagician=true, bool isWarlock=false) : mana(mana), manaLimit(mana), battleMagician(battleMagician), isWarlock(isWarlock) {}

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

bool MagicState::getIsWarlock() {
    return this->isWarlock;
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
