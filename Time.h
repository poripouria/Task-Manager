#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>
using namespace std ;

class Time
{
    friend ostream &operator<<(ostream &, Time) ;
    friend istream &operator>>(istream &, Time &) ;
    friend bool operator==(Time, Time) ;
    friend bool operator>=(Time, Time) ;
    friend bool operator<=(Time, Time) ;
    friend bool operator>(Time, Time) ;
    friend bool operator<(Time, Time) ;
public :
    Time() ;
    Time(const Time &) ;
    Time(unsigned int, unsigned int) ;
    ~Time() ;

    void setHour(unsigned int) ;
    void setMinute(unsigned int) ;
    unsigned int getHour() const ;
    unsigned int getMinute() const ;
    void setTime(unsigned int=0, unsigned int=0) ;

    void printTime() const ;
    void readTime() ;
private :
    unsigned int Hour ;
    unsigned int Minute ;

    void decreament() ;
};

#endif // TIME_H_INCLUDED
