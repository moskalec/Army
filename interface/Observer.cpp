#include "Observer.h"

Observer::Observer() : observerableList(new std::set<Observerable*>()) {}

Observer::~Observer() {
    this->notifyObserverables();
}

void Observer::addObserverable(Observerable *victim) {
    this->observerableList->insert(victim);
    victim->attach(this);
}

void Observer::notifyObserverables() {
    std::set<Observerable*>::iterator it;

    for ( it = observerableList->begin(); it != observerableList->end(); it++ ) {
        Observerable* victim = *it;

        victim->detach(this);
    }
}

void Observer::update(Observerable *victim) {
    std::set<Observerable*>::iterator it = observerableList->find(victim);

    if ( it != observerableList->end() ) {
        observerableList->erase(it);
    }
}