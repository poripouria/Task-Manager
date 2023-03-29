#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>
using namespace std ;
#include "Task.h"
#include "Date.h"
#include "Time.h"

class Employee
{
    friend ostream &operator<<(ostream &, Employee) ;
    friend bool operator<(Employee &, Employee &) ;
    friend bool operator>(Employee &, Employee &) ;
    friend class Company ;
public:
    Employee() ;
    Employee(string, string, Date, Time, Time) ;
    ~Employee() ;

    void setName(string) ;
    void setSSID(string) ;
    void setTasks(Task) ;
    void setWorkDate(Date) ;
    void setStartTime(Time) ;
    void setEndTime(Time) ;
    string getName() const ;
    string getSSID() const ;
    Task getTasks() const ;
    Date getWorkDate() const ;
    Time getStartTime() const ;
    Time getEndTime() const ;

    void printED() const ;
private:
    string Name ;
    string SSID ;
    Task Tasks ;
    Date WorkDate ;
    Time StartTime ;
    Time EndTime ;
};

#endif // EMPLOYEE_H_INCLUDED
