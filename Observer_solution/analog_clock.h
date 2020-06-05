
/*************************************************************************************************/
/****************************************CONCRETE ANALOG CLOCK***********************************/
/**An AnalogClock class can be defined in the same way.**/

#ifndef analog_clock_h
#define analog_clock_h
#include "i_widget.h"
#include "i_observer.h"
#include "clock_timer.h"
#include "i_subscriber.h"
#include <iostream>
#include <sstream>
#define TO_STRING( x ) dynamic_cast< std::ostringstream & >( \
 ( std::ostringstream() << std::dec << x ) ).str()

class AnalogClock: public IWidget, public IObserver
{
    public:
        AnalogClock (ISubscriber* newManager, ClockTimer* timer){
            manager = newManager;
            subject = timer;
            manager->Attach(this);
        }

        ~AnalogClock (){
            std::cout<<"destruye analogClock"<<std::endl;
            manager->Dettach(this);
        }

        void Update (){
             std::cout<<"Update-AnalogClock"<<std::endl;
                Draw();
        }

        void Draw (){
             std::cout<<"Draw-AnaloglClock"<<std::endl;
         // get the new values from the subject
            std::string hours = TO_STRING(subject->GetHour());
            std::string minutes = TO_STRING(subject->GetMinute());
            std::string seconds = TO_STRING(subject->GetSecond());
            if(hours.size() == 1){hours = "0"+hours;}
            if(minutes.size() == 1){minutes = "0"+minutes;}
            if(seconds.size() == 1){seconds = "0"+seconds;}
            // draw the digital clock
            std::cout <<"I am Analog: "<< hours<<":"<<minutes<<":"<<seconds<<std::endl;
        }

    private:
        ISubscriber* manager;
        ClockTimer* subject;
};

#endif

