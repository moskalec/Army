#include "SpellBook.h"
#include "FireBall.h"
#include "Heal.h"

SpellBook::SpellBook () {
    this->spellBook = new std::map<SPELL_NAME, Spell*>();
    this->spellBook->insert(std::pair<SPELL_NAME, Spell*>(FIRE_BALL, new FireBall(30, 30)));
    this->spellBook->insert(std::pair<SPELL_NAME, Spell*>(HEAL, new Heal(30, 30)));
}

SpellBook::~SpellBook() {
    std::map<SPELL_NAME, Spell*>::iterator it;

    for ( it = this->spellBook->begin(); it != this->spellBook->end(); it++ ) {
        delete it->second;
    }

  delete spellBook;
}

const std::map<SPELL_NAME, Spell*>& SpellBook::getSpellBook() const{
    return *(this->spellBook);
};

Spell* SpellBook::changeSpell(SPELL_NAME newSpell) {
    std::map<SPELL_NAME, Spell*>::iterator it = this->spellBook->find(newSpell);
    return it->second;
}