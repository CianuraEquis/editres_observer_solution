#ifndef i_notifier_h
#define i_notifier_h
#include <list>

class INotifier{
    public:
        virtual ~INotifier(){}
        virtual void Notify() = 0;
};

#endif
