
/**********************************OBSERVER INTERFACE************************************/
/**An abstract class defines the Observer interface:**/
#ifndef i_observer_h
#define i_observer_h


class IObserver{
    public:
        virtual ~IObserver(){};
        virtual void Update() = 0;
};

#endif
