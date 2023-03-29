#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

#include <iostream>
using namespace std ;
#include "Date.h"
#include "Time.h"

class Task
{
    friend ostream &operator<<(ostream &, Task) ;
    friend bool operator<(Task &, Task &) ;
    friend bool operator>(Task &, Task &) ;
    friend class Company ;
public :
    Task() ;
    Task(string, Date, Time, Time) ;
    ~Task() ;

    void setTaskName(string) ;
    void setTaskDate(Date) ;
    void setBeginTime(Time) ;
    void setFinishTime(Time) ;
    string getTaskName() const ;
    Date getTaskDate() const ;
    Time getBeginTime() const ;
    Time getFinishTime() const ;

    void printTD() const ;
private:
    string TaskName ;
    Date TaskDate ;
    Time BeginTime ;
    Time FinishTime ;
};

#endif // TASK_H_INCLUDED
