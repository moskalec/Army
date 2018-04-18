#ifndef OBSERVER_H
#define OBSERVER_H

#include <set>
#include "Observerable.h"

class Observerable;

class Observer {
    protected:
        std::set<Observerable*>* observerableList;

    public:
        Observer();
        virtual ~Observer();

        void addObserverable(Observerable* victim);
        void notifyObserverables();
        virtual void update(Observerable* victim);
};

#endif //OBSERVER_H
