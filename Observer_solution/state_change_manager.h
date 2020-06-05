/*Project : Observer Example
 Authors : Erich Gamma, Richard Helm, Ralph Johnson and John
Vlissides
 Implementer : Gabriel Nicolás González Ferreira
**/
#ifndef state_change_manager_h
#define state_change_manager_h

#include <sstream>
#define TO_STRING( x ) dynamic_cast< std::ostringstream & >( \
 ( std::ostringstream() << std::dec << x ) ).str()
#include <iostream>
#include <list>
#include <string>
#include "i_subscriber.h"
#include "i_notifier.h"
#include "i_observer.h"
using namespace std;



class StateChangeManager : public ISubscriber, public INotifier {
    public:
        StateChangeManager(){};

        virtual ~StateChangeManager(){
        std::cout<<"destruye stateChangeManager"<<std::endl;}

        void Attach (IObserver* newObserver){
            std::cout<<"Attach-StateChangeManager"<<std::endl;
            listObservers.push_front(newObserver);
        }
        void Dettach (IObserver* newObserver){
            std::cout<<"Dettach-StateChangeManager"<<std::endl;
            listObservers.remove(newObserver);
        }
        /*list<IObserver*> getObservers(){
            return listObservers;
        }*/

        virtual void Notify(){
            std::cout<<"Notify-StateChangeManager"<<std::endl;
            list<IObserver*>::iterator it;
            for (it = listObservers.begin() ; it != listObservers.end(); ++it){
                (*it)->Update();
            }
        }

    private:
        list<IObserver*> listObservers;
};

#endif
