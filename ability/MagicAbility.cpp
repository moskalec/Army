#include "MagicAbility.h"

MagicAbility::MagicAbility(SpellCaster* owner, SpellBook* spellBook)
    : owner(owner), spellBook(spellBook) {
    this->spell = this->spellBook->changeSpell(FIRE_BALL);
}

MagicAbility::~MagicAbility() {
    delete(this->spell);
    delete(this->spellBook);
}

void MagicAbility::changeSpell(int spellName) {     //Spell* newSpell) {
    delete(this->spell);
    this->spell = this->spellBook->changeSpell(spellName);
}

void MagicAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    this->owner->spendMana(this->spell->getCost());
    this->spell->action(enemy);
}
