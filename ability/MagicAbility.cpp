#include "MagicAbility.h"

MagicAbility::MagicAbility(SpellCaster* owner, Spell* spell)
    : owner(owner), spell(spell) {
    this->spellBook = new SpellBook();
}

MagicAbility::~MagicAbility() {
    delete(this->spell);
}

void MagicAbility::changeSpell(SPELL_NAME newSpell) {
    delete(this->spell);
    this->spell = this->spellBook->changeSpell(newSpell);
}

void MagicAbility::cast(SpellCaster* owner, Unit* enemy) {
    this->owner->ensureIsAlive();
    this->owner->spendMana(this->spell->getCost());
    this->spell->action(owner, enemy);
}

