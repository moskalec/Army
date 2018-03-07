#include "Wizard.h"

Wizard::Wizard(const char* title, int hitPoints, int damage, int mana)
    : SpellCaster(title, hitPoints, damage, mana) {
        this->magicAbility = new MagicAbility(this, new SpellBook());//new FireBall(30, 30));
}

Wizard::~Wizard() {}
//
//void Wizard::changeSpell(int spellName) { //(Spell* newSpell) {
//        this->spellBook->changeSpell(spellName);    //(newSpell);
//}

//void MagicAbility::changeSpell(int spellName) {
//    delete(this->spell);
//    this->spell = this->owner->spellBook->changeSpell(spellName); //newSpell; //new Spell(this->owner->spellBook->changeSpell(spellName));
//}

void Wizard::changeSpell(int newSpell) {
    SpellCaster::changeSpell(newSpell);//this->magicAbility = new MagicAbility(this, this->spellBook->changeSpell(spellName));
}