#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
using namespace std ;
#include "Employee.h"


Employee::Employee()
{

}

Employee::Employee(string name, string ssid, Date wd, Time st, Time et)
{
    setName(name) ;
    setSSID(ssid) ;
    setWorkDate(wd) ;
    setStartTime(st) ;
    setEndTime(et) ;
}

void Employee::setName(string name)
{
    Name = name ;
}

void Employee::setSSID(string ssid)
{
    SSID = ssid ;
}

void Employee::setTasks(Task t)
{
    Tasks = t ;
}

void Employee::setWorkDate(Date wd)
{
    WorkDate = wd ;
}

void Employee::setStartTime(Time st)
{
    StartTime =st ;
}

void Employee::setEndTime(Time et)
{
    EndTime = et ;
}

string Employee::getName() const
{
    return Name ;
}

string Employee::getSSID() const
{
    return SSID ;
}

Task Employee::getTasks() const
{
    return Tasks ;
}

Date Employee::getWorkDate() const
{
    return WorkDate ;
}

Time Employee::getStartTime() const
{
    return StartTime ;
}

Time Employee::getEndTime() const
{
    return EndTime ;
}

void Employee::printED() const
{
    cout << "Name:" << Name << ' ' << "SSID:" << '(' << SSID << ')'
         << ' ' << '[' << StartTime << " - " << EndTime << ']' << "\n\tTask:" << Tasks << endl ;
}

ostream &operator<<(ostream &outp, Employee e)
{
    outp << "Name:" << e.Name << ' ' << "SSID:" << '(' << e.SSID << ')'
         << ' ' << '[' << e.StartTime << " - " << e.EndTime << ']' << "\n\tTask:" << e.Tasks;
    return outp ;
}

Employee::~Employee()
{

}

bool operator<(Employee &e1, Employee &e2)
{
    if(e1.getName() < e2.getName())
        return true ;
    else
        return false ;
}

bool operator>(Employee &e1, Employee &e2)
{
    if(e1.getName() > e2.getName())
        return true ;
    else
        return false ;
}
