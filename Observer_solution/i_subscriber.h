#ifndef i_subscriber_h
#define i_subscriber_h
#include "i_observer.h"
#include <list>


class ISubscriber{
    public:
        virtual ~ISubscriber(){}
        virtual void Attach (IObserver* observer) = 0;
        virtual void Dettach (IObserver* observer) = 0;
        //virtual list<IObserver*> getObservers()= 0;
        //virtual void Notify () = 0;
};

#endif
