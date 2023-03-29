#include <iostream>
#include <iomanip>
#include <exception>
#include <stdexcept>
using namespace std ;
#include "Time.h"


Time::Time()
{
    Hour = 0 ;
    Minute = 0 ;
}

Time::Time(unsigned int h, unsigned int m)
{
    setTime(h, m) ;
}

Time::Time(const Time &ttc)
{
    setHour(ttc.getHour()) ;
    setMinute(ttc.getMinute()) ;
}

void Time::setHour(unsigned int h)
{
    if(h<24)
        Hour = h ;
    else
        throw invalid_argument ("Hour should be between 0-24!") ;
}

void Time::setMinute(unsigned int m)
{
    if(m<60)
        Minute = m ;
    else
        throw invalid_argument ("Minute should be between 0-60!") ;
}

unsigned int Time::getHour() const
{
    return Hour ;
}

unsigned int Time::getMinute() const
{
    return Minute ;
}

void Time::setTime(unsigned int h, unsigned int m)
{
    setHour(h) ;
    setMinute(m) ;
}

void Time::printTime() const
{
    cout << setfill('0') <<
            setw(2) << getHour() << ":" <<
            setw(2) << getMinute() << endl ;
}

void Time::readTime()
{
    cin >> setw(2) >> Hour ;
    cin.ignore() ;
    cin >> setw(2) >> Minute ;
    cin.ignore() ;
}

void Time::decreament()
{
    if(Minute!=0)
        Minute-- ;
    else
    {
        Minute = 59 ;
        Hour-- ;
    }
}

ostream &operator<<(ostream &Output, Time t)
{
    Output << setfill('0') <<
              setw(2) << t.getHour() << ":" <<
              setw(2) << t.getMinute()  ;
    return Output ;
}

istream &operator>>(istream &Input, Time &t)
{
    Input >> setw(2) >> t.Hour ;
    Input.ignore() ;
    Input >> setw(2) >> t.Minute ;
    Input.ignore() ;
    return Input ;
}

bool operator==(Time t1, Time t2)
{
    if(t1.getHour()==t2.getHour() && t1.getMinute()==t2.getMinute())
        return true ;
    else
        return false ;
}

bool operator>(Time t1, Time t2)
{
    if(t1.getHour() > t2.getHour())
        return true ;
    else if(t1.getHour() < t2.getHour())
        return false ;
    else if(t1.getMinute() > t2.getMinute())
        return true ;
    else
        return false ;
}

bool operator<(Time t1, Time t2)
{
    if(!(t1>t2))
        return true ;
    else
        return false ;
}

bool operator<=(Time t1, Time t2)
{
    if(t1<t2 || t1==t2)
        return true ;
    else
        return false ;
}

bool operator>=(Time t1, Time t2)
{
    if(t1>t2 || t1==t2)
        return true ;
    else
        return false ;
}

Time::~Time()
{

}
