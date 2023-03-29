#include <iostream>
#include <iomanip>
#include <exception>
#include <stdexcept>
using namespace std ;
#include "Date.h"


const string Date::MonthName[13] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"} ;
const unsigned int Date::DayPerMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} ;

Date::Date()
{
    Month = 1 ;
    Day = 1 ;
}

Date::Date(unsigned int m, unsigned int d, unsigned int hh, unsigned int mm)
{
    setMonth(m) ;
    setDay(d) ;
    setTimeInDay(hh, mm) ;
}

Date::Date(const Date &dtc)
{
    setMonth(dtc.getMonth()) ;
    setDay(dtc.getDay()) ;
}

void Date::setMonth(unsigned int m)
{
    if(m>=1 && m<=12)
        Month = m ;
    else
        throw invalid_argument ("Month should be between 1-12!") ;
}

void Date::setDay(unsigned int d)
{
    if(checkDay(d))
        Day = d ;
    else
    {
        throw invalid_argument ("Invalid day for this month!") ;
    }
}

void Date::setTimeInDay(Time &t)
{
    TimeInDay = t ;
}

void Date::setTimeInDay(unsigned int hh, unsigned int mm)
{
    TimeInDay.setHour(hh) ;
    TimeInDay.setMinute(mm) ;
}

unsigned int Date::getMonth() const
{
    return Month ;
}

unsigned int Date::getDay() const
{
    return Day ;
}

Time Date::getTimeInDay() const
{
    return TimeInDay ;
}

void Date::setDate(unsigned int m, unsigned int d)
{
    setMonth(m) ;
    setDay(d) ;
}

void Date::printDate() const
{
    cout << setfill('0') <<
            setw(2) << getDay() << "-" <<
            setw(2) << getMonth() << endl ;
}

void Date::printDateAndTime() const
{
    cout << setfill('0') <<
            setw(2) << getDay() << "-" <<
            setw(2) << getMonth() << " " <<
            setw(2) << TimeInDay.getHour() << ":" <<
            setw(2) << TimeInDay.getMinute() << endl  ;
}

void Date::readDate()
{
    cin >> setw(2) >> Day ;
    cin.ignore() ;
    cin >> setw(2) >> Month ;
    cin.ignore() ;
}

void Date::readDateAndTime()
{
    readDate() ;
    TimeInDay.readTime() ;
}

bool Date::checkDay(unsigned int d) const
{
    if(d<=DayPerMonth[Month])
        return true ;
    else
        return false ;
}

bool Date::isEndOfMonth(unsigned int d) const
{
    return d==DayPerMonth[Month] ;
}

void Date::decreament()
{
    if(Day != 1)
        --Day ;
    else
    {
        --Month ;
        Day = DayPerMonth[Month] ;
    }
}

ostream &operator<<(ostream &Output, Date d)
{
    Output << setfill('0') <<
              setw(2) << d.getDay() << "-" <<
              setw(2) << d.getMonth()  ;
    return Output ;
}

istream &operator>>(istream &Input, Date &d)
{
    Input >> setw(2) >> d.Day ;
    Input.ignore() ;
    Input >> setw(2) >> d.Month ;
    Input.ignore() ;
    return Input ;
}

bool operator==(Date &d1, Date &d2)
{
    if(d1.getMonth()==d2.getMonth() && d1.getDay()==d2.getDay())
        return true ;
    else
        return false ;
}

Date::~Date()
{

}
