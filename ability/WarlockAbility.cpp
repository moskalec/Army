#include "WarlockAbility.h"

WarlockAbility::WarlockAbility(SpellCaster* owner, Spell* spell) : MagicAbility(owner, spell) {}

WarlockAbility::~WarlockAbility() {
    delete(this->spell);
}

void WarlockAbility::cast(SpellCaster* owner, Unit* enemy) {
    this->owner->ensureIsAlive();
    this->owner->spendMana(this->spell->getCost());
    this->spell->action(owner, enemy);
}