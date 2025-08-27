#include "IObservable.h"


bool IObservable::addObserver(IObserver* observer)
{
    for (auto *o : observers)
        if (o == observer) return false;
    observers.append(observer);
    return true;
}


bool IObservable::delObserver(IObserver* observer)
{
    return observers.removeOne(observer);
}
