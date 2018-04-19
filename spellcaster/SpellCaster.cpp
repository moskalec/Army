#include "SpellCaster.h"

SpellCaster::SpellCaster(const char* title, int hitPoints, int damage, int mana, bool battleMagician, bool isWarlock)
    : Unit(title, hitPoints, damage), magicState(new MagicState(mana, battleMagician, isWarlock)) {
        this->ability = new DefaultAbility(this);
    }

SpellCaster::~SpellCaster() {
    delete(this->magicState);
    delete(this->magicAbility);
}

int SpellCaster::getMana() const {
    return this->magicState->getMana();
}

int SpellCaster::getManaLimit() const {
    return this->magicState->getManaLimit();
}

bool SpellCaster::getBattleMagician() const {
    return this->magicState->getBattleMagician();
}

bool SpellCaster::getIsWarlock() const {
    return this->magicState->getIsWarlock();
}

void SpellCaster::addMana(int extra) {
    this->magicState->addMana(extra);
}

void SpellCaster::spendMana(int cost) {
    this->magicState->spendMana(cost);
}

void SpellCaster::changeSpell(SPELL_NAME newSpell) {
    this->magicAbility->changeSpell(newSpell);
}

void SpellCaster::cast(SpellCaster* owner, Unit* enemy) {
    this->magicAbility->cast(owner, enemy);
}
