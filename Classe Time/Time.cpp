#include "Time.h"

int main()
{
    Time tempo;
    tempo.setHour(22).setMinute(25).setSecond(36);
    tempo.printUniversal();
    tempo.printStandard();
    tempo.setTime(20,20,20).printStandard();
    
    return 0;
}