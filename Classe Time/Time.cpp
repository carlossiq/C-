#include <iostream>
using std::cout;

#include <iomanip>
using std::setw;
using std::setfill;

#include "Time.h"

Time::Time()
{
    hour = minute = second = 0;
}

void Time::setTime(int h, int m, int s)
{
    hour = (h > 0 && h < 24) ? h : 0;
    minute = (m > 0 && m < 60) ? m : 0;
    second = (s > 0 && s < 60) ? s : 0;
}

void Time::printUniversal()
{
    cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
}

void Time::printStandard()
{
    cout << ( (hour == 0 || hour == 12) ? 12 : hour%12) << ":";
    cout << setfill('0') << setw(2) << minute << ":" << setw(2) << second << (hour < 12 ? " AM" : " PM");
}

int main()
{
    Time t;
    cout << "O tempo universal inicial e ";
    t.printUniversal();
    cout << "\nO tempo inicial padrao e ";
    t.printStandard();

    t.setTime(14, 2, 53);
    cout << "\nO tempo universal e ";
    t.printUniversal();
    cout << "\nO tempo padrao e ";
    t.printStandard();
    
    return 0;
}