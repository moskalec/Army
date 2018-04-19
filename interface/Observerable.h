#ifndef OBSERVERABLE_H
#define OBSERVERABLE_H

#include <set>
#include "Observer.h"

class Observer;

class Observerable {
    protected:
        std::set<Observer*>* observerList;

    public:
        Observerable();
        virtual ~Observerable();

        void attach(Observer* customer);
        void detach(Observer* customer);
        void notify();
};

#endif //OBSERVERABLE_H
