#include "PriestAbility.h"

PriestAbility::PriestAbility(SpellCaster* owner, Spell* spell) : MagicAbility(owner, spell) {}

PriestAbility::~PriestAbility() {
    delete(this->spell);
}

void PriestAbility::cast(SpellCaster* owner, Unit* enemy) {
    this->owner->ensureIsAlive();
    this->owner->spendMana(this->spell->getCost());
    this->spell->action(owner, enemy);
}
