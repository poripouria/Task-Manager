#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include <stdexcept>
using namespace std ;
#include "Task.h"


Task::Task()
{

}

Task::Task(string name, Date td, Time bt, Time ft)
{
    setTaskName(name) ;
    setTaskDate(td) ;
    setBeginTime(bt) ;
    setFinishTime(ft) ;
}

void Task::setTaskName(string name)
{
    TaskName = name ;
}

void Task::setTaskDate(Date td)
{
    TaskDate = td ;
}

void Task::setBeginTime(Time bt)
{
    BeginTime = bt ;
}

void Task::setFinishTime(Time ft)
{
    FinishTime = ft ;
}

string Task::getTaskName() const
{
    return TaskName ;
}

Date Task::getTaskDate() const
{
    return TaskDate ;
}

Time Task::getBeginTime() const
{
    return BeginTime ;
}

Time Task::getFinishTime() const
{
    return FinishTime ;
}

void Task::printTD() const
{
    cout << "\"" << TaskName << "\"\t\t" <<
            "[" << BeginTime << " - " << FinishTime << "]" << endl ;
}

ostream &operator<<(ostream &outp, Task t)
{
    outp << "\"" << t.getTaskName() << "\"\t\t" <<
            "[" << t.getBeginTime() << " - " << t.getFinishTime() << "]" ;
    return outp ;
}

Task::~Task()
{
}

bool operator<(Task &t1, Task &t2)
{
    if(t1.getFinishTime() < t2.getFinishTime())
        return true ;
    else
        return false ;
}

bool operator>(Task &t1, Task &t2)
{
    if(t1.getFinishTime() > t2.getFinishTime())
        return true ;
    else
        return false ;
}
