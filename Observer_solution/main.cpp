#include <iostream>
#include "clock_timer.h"
#include "analog_clock.h"
#include "digital_clock.h"
#include "state_change_manager.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

    StateChangeManager* manager = new StateChangeManager();
    ClockTimer* timer = new ClockTimer(manager);
    AnalogClock* analog = new AnalogClock(manager, timer);
    DigitalClock* digital = new DigitalClock(manager, timer);

    timer->Start();
    timer->Start();

    delete manager;
    delete timer;
    delete analog;

	return 0;


}
