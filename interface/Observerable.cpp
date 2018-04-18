#include "Observerable.h"

Observerable::Observerable() : observerList(new std::set<Observer*>()) {}

Observerable::~Observerable() {}

void Observerable::attach(Observer* customer) {
    this->observerList->insert(customer);
}

void Observerable::detach(Observer* customer) {
    std::set<Observer*>::iterator it = observerList->find(customer);

    if ( it != observerList->end() ) {
        observerList->erase(it);
    }
}

void Observerable::notify() {
    std::set<Observer*>::iterator it;

    for ( it = observerList->begin(); it != observerList->end(); it++ ) {
        Observer* necr = *it;

        necr->update(this);
    }
}