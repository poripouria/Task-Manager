#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
using namespace std ;
#include "Time.h"

class Date
{
    friend ostream &operator<<(ostream &, Date) ;
    friend istream &operator>>(istream &, Date &) ;
    friend bool operator==(Date &, Date &) ;
public :
    Date() ;
    Date(const Date &) ;
    Date(unsigned int, unsigned int, unsigned int=0, unsigned int=0) ;
    ~Date() ;

    void setMonth(unsigned int) ;
    void setDay(unsigned int) ;
    void setTimeInDay(Time &) ;
    void setTimeInDay(unsigned int=0, unsigned int=0) ;
    unsigned int getMonth() const ;
    unsigned int getDay() const ;
    Time getTimeInDay() const ;
    void setDate(unsigned int=1, unsigned int=1) ;

    static const string MonthName[13] ;
    static const unsigned int DayPerMonth[13] ;

    void printDate() const ;
    void printDateAndTime() const ;
    void readDate() ;
    void readDateAndTime() ;
private :
    unsigned int Day ;
    unsigned int Month ;
    Time TimeInDay ;

    bool checkDay(unsigned int) const ;
    bool isEndOfMonth(unsigned int) const ;
    void decreament() ;
};

#endif // DATE_H_INCLUDED
