#ifndef clock_timer_h
#define clock_timer_h
#include "i_notifier.h"
#include "i_subscriber.h"
#include <iostream>


class ClockTimer{
    public:
        ClockTimer(INotifier* newNotifier){
            notifier = newNotifier;
            m_hours = 0;
            m_minutes = 0;
            m_seconds = 0;
        }

        ~ClockTimer(){
        std::cout<<"destruye clockTimer"<<std::endl;}

        int GetHour( void ){
            return this->m_hours;
        }

        int GetMinute( void ){
            return this->m_minutes;
        }

        int GetSecond( void ){
            return this->m_seconds;
        }

        std::string Start (){
            std::cout<<"Start-ClockTimer"<<std::endl;

         // No update internal time-keeping state, only a demo.
         // ...
             m_seconds++;
            if(m_seconds == 60){
                m_seconds = 0;
                m_minutes++;
                if(m_minutes == 60){
                    m_seconds = 0;
                    m_minutes = 0;
                    m_hours++;
                    if(m_hours == 24){
                        m_seconds = 0;
                        m_minutes = 0;
                        m_hours = 0;
                    }
                }
            }
            notifier->Notify();
            return 0;
        }

    private:
        int m_hours;
        int m_minutes;
        int m_seconds;
        INotifier* notifier;
};

#endif

