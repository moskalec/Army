#include "SpellBook.h"

SpellBook::SpellBook() {
    this->spellBook = new std::map<int, Spell*>();
    this->spellBook->insert(std::make_pair<int, Spell*>(FIRE_BALL, new FireBall(30, 30)) );
    this->spellBook->insert(std::make_pair<int, Spell*>(HEAL, new Heal(40, 40)) );
//    this->it = this->spellBook->begin();
}
SpellBook::~SpellBook() {
    delete(spellBook);
}

Spell* SpellBook::changeSpell(int spellName) {
    return spellBook->find(spellName)->second;
}