/****************************************CONCRETE DIGITAL CLOCK********************************/
/**Now we can define a class DigitalClock that displays the time. It inherits its graphical functionality from
 * a Widget class provided by a user interface toolkit. The Observer interface is mixed into the DigitalClock
interface by inheriting from Observer.**/

#ifndef digitalclock_h
#define digitalclock_h
#include "i_widget.h"
#include "i_observer.h"
#include "clock_timer.h"
#include "i_subscriber.h"
#include <sstream>
#define TO_STRING( x ) dynamic_cast< std::ostringstream & >( \
 ( std::ostringstream() << std::dec << x ) ).str()


class DigitalClock: public IWidget, public IObserver
{
    public:
        DigitalClock(ISubscriber* newManager, ClockTimer* timer){
            manager = newManager;
            subject = timer;
            manager->Attach(this);
        }

        ~DigitalClock (){
            std::cout<<"destruye digitalClock"<<std::endl;
            manager->Dettach(this);
        }

        void Update(){
            std::cout<<"Update-DigitalClock"<<std::endl;
            Draw();
        }

        void Draw (){
            std::cout<<"Draw-DigitalClock"<<std::endl;
            // get the new values from the subject
            std::string hours = TO_STRING(subject->GetHour());
            std::string minutes = TO_STRING(subject->GetMinute());
            std::string seconds = TO_STRING(subject->GetSecond());
            // draw the digital clock
            if(hours.size() == 1){hours = "0"+hours;}
            if(minutes.size() == 1){minutes = "0"+minutes;}
            if(seconds.size() == 1){seconds = "0"+seconds;}
            std::cout <<"I am Digital: "<< hours<<":"<<minutes<<":"<<seconds<<std::endl;
        }

    private:
        ISubscriber* manager;
        ClockTimer* subject;
};

#endif
