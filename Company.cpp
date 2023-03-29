#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <exception>
#include <stdexcept>
#include <ctime>
using namespace std ;
#include "Company.h"
#include "Date.h"


string Company::CommandsName[10] = {"today", "month", "add task", "find time", "now", "free",
                                    "add employee", "assign task", "schedule", "done"} ;

Company &Company::getObject()
{
    static Company Object ;
    return Object ;
}

void Company::WhatToDo(string command)
{
    fillVecs() ;
    if(command == CommandsName[0])
        today() ;
    else if(command == CommandsName[1])
        month() ;
    else if(command == CommandsName[2])
        addTask() ;
    else if(command == CommandsName[3])
        findTime() ;
    else if(command == CommandsName[4])
        now() ;
    else if(command == CommandsName[5])
        free() ;
    else if(command == CommandsName[6])
        addEmployee() ;
    else if(command == CommandsName[7])
        assignTask() ;
    else if(command == CommandsName[8])
        schedule() ;
    else if(command == CommandsName[9])
        done() ;
    else
        throw invalid_argument("You entered wrong command!") ;
}

void Company::fillVecs()
{
    unsigned int i, j ;
    Task t[500] ;
    Employee e[500] ;

    tVector.clear() ;
    eVector.clear() ;
    TaskFile.open("TaskFile", ios::in) ;
    EmployeeFile.open("EmployeeFile", ios::in) ;
    for(i=0; !EmployeeFile.eof(); ++i)
    {
        getline(EmployeeFile, e[i].Name) ;
        getline(EmployeeFile, e[i].SSID) ;
        EmployeeFile >> e[i].StartTime >> e[i].EndTime ;
    }
    for(j=0; !TaskFile.eof(); ++j)
    {
        getline(TaskFile, t[j].TaskName) ;
        TaskFile >> t[j].TaskDate >> t[j].BeginTime >> t[j].FinishTime ;
    }
    EmployeeFile.close() ;
    TaskFile.close() ;
    NumberOfEmployees = i-1 ;
    NumberOfTasks = j-1 ;

    for(i=0; i<NumberOfTasks; ++i)
        tVector.push_back(t[i]) ;
    for(i=0; i<NumberOfEmployees; ++i)
        eVector.push_back(e[i]) ;

    sort(tVector.begin(), tVector.end()) ;
    sort(eVector.begin(), eVector.end()) ;
}

void Company::prntVecs()
{
    vector<Task>::iterator itrT ;
    vector<Employee>::iterator itrE ;

    sort(eVector.begin(), eVector.end()) ;
    sort(tVector.begin(), tVector.end()) ;

    cout << endl ;
    cout << "Tasks: " << endl ;
    for(itrT=tVector.begin(); itrT!=tVector.end(); ++itrT)
        cout << *itrT << endl ;
    cout << endl ;
    cout << "Employees: " << endl ;
    for(itrE=eVector.begin(); itrE!=eVector.end(); ++itrE)
        cout << *itrE << endl ;
    cout << endl ;
}

void Company::today()
{
    time_t currentTime = time(0) ;
    tm *localTime = localtime(&currentTime) ;
    unsigned int todayday = (localTime->tm_mday), todaymonth = (1+localTime->tm_mon) ;
    bool isTask = false ;
    int n=0 ;

    sort(tVector.begin(), tVector.end()) ;
    TaskFile.open("TaskFile", ios::in) ;
    vector<Task>::iterator itr ;
    for(itr=tVector.begin(); itr!=tVector.end(); ++itr)
    {
        if( (itr->TaskDate.getDay() == todayday) && (itr->TaskDate.getMonth() == todaymonth) )
        {
            isTask = true ;
            cout << '(' << ++n << ')' << ' ' ;
            itr->printTD() ;
        }
    }
    if(!isTask)
        cout << "No tasks for today!" << '(' << Date::MonthName[todaymonth] << ' ' << todayday << ')' << endl ;
    TaskFile.close() ;
}

void Company::month()
{
    time_t currentTime = time(0) ;
    tm *localTime = localtime(&currentTime) ;
    unsigned int todaymonth = (1+localTime->tm_mon) ;
    bool isTask = false ;
    int n=0 ;

    sort(tVector.begin(), tVector.end()) ;
    TaskFile.open("TaskFile", ios::in) ;
    vector<Task>::iterator itr ;
    for(itr=tVector.begin(); itr!=tVector.end(); ++itr)
    {
        if(itr->TaskDate.getMonth() == todaymonth)
        {
            isTask = true ;
            cout << '(' << ++n << ')' << ' ' ;
            itr->printTD() ;
        }
    }
    if(!isTask)
        cout << "No tasks for this month!" << '(' << Date::MonthName[todaymonth] << ')' << endl ;
    TaskFile.close() ;
}

void Company::addTask()
{
    string tt ;
    Time tbt , tft ;
    Date td ;

    cout << "Title is " ;
    getline(cin, tt) ;
    cout << "Starts at " ;
    td.readDate() ;
    tbt.readTime() ;
    cout << "Ends at " ;
    td.readDate() ;
    tft.readTime() ;

    tsk.setTaskName(tt) ;
    tsk.setTaskDate(td) ;
    tsk.setBeginTime(tbt) ;
    tsk.setFinishTime(tft) ;

    TaskFile.open("TaskFile", ios::app) ;
    TaskFile << tt << endl << td << endl << tbt << endl << tft << endl ;
    TaskFile.close() ;
}

void Company::findTime()
{

}

void Company::now()
{
    time_t currentTime = time(0) ;
    tm *localTime = localtime(&currentTime) ;

    cout << setfill('0') <<
            setw(2) << localTime->tm_mday << "-" <<
            setw(2) << 1+localTime->tm_mon << " " <<
            setw(2) << localTime->tm_hour << ":" <<
            setw(2) << localTime->tm_min << endl  ;
}

void Company::free()
{
    Date dtr ;
    Time ttr ;
    bool isTask = false ;

    dtr.readDate() ;
    ttr.readTime() ;

    TaskFile.open("TaskFile", ios::in) ;
    vector<Task>::iterator itr ;
    for(itr=tVector.begin(); itr!=tVector.end(); ++itr)
    {
        if( (itr->TaskDate == dtr) && (itr->BeginTime <= ttr) && (itr->FinishTime >= ttr) )
        {
            isTask = true ;
            tVector.erase(itr) ;
            break ;
        }
    }
    TaskFile.close() ;
    if(!isTask)
        cout << "there is not any task at this time!" << endl ;

    TaskFile.open("TaskFile", ios::out) ;
    for(itr=tVector.begin(); itr!=tVector.end(); ++itr)
    {
        TaskFile << itr->TaskName << endl << itr->TaskDate << endl <<
                    itr->BeginTime << endl << itr->FinishTime << endl ;
    }
    TaskFile.close() ;
}

void Company::addEmployee()
{
    string en ;
    string eid ;
    Time est , eet ;
    Date ewd(1, 1) ;

    cout << "Name is " ;
    getline(cin, en) ;
    cout << "SSID is " ;
    getline(cin, eid) ;
    cout << "Starts at " ;
    est.readTime() ;
    cout << "Ends at " ;
    eet.readTime() ;

    empl.setName(en) ;
    empl.setSSID(eid) ;
    empl.setStartTime(est) ;
    empl.setEndTime(eet) ;
    empl.setWorkDate(ewd) ;

    EmployeeFile.open("EmployeeFile", ios::app) ;
    EmployeeFile << en << endl << eid << endl << est << endl << eet << endl ;
    EmployeeFile.close() ;
}

void Company::assignTask()
{
    string eid ;
    string tt ;
    bool isTask = false ;
    bool isEmpl = false ;

    cout << "SSID is: " ;
    getline(cin, eid) ;
    cout << "Task is: " ;
    getline(cin, tt) ;

    TaskFile.open("TaskFile", ios::in) ;
    EmployeeFile.open("EmployeeFile", ios::in) ;
    vector<Task>::iterator itrT ;
    vector<Employee>::iterator itrE ;
    for(itrT=tVector.begin(); itrT!=tVector.end(); ++itrT)
    {
        if(itrT->TaskName == tt)
        {
            isTask = true ;
            tsk = *itrT ;
        }
    }
    for(itrE=eVector.begin(); itrE!=eVector.end(); ++itrE)
    {
        if(itrE->SSID == eid)
        {
            isEmpl = true ;
            itrE->setTasks(tsk) ;
        }
    }
    if(!isTask)
        cout << "There is not any task called " << tt << endl ;
    if(!isEmpl)
        cout << "There is not any employee with id " << eid << endl ;
    EmployeeFile.close() ;
    TaskFile.close() ;
}

void Company::schedule(unsigned int i)      //greedy algorithm
{
    sort(tVector.begin(), tVector.end()) ;
    auto m = ++i;
    while(m<=NumberOfTasks && tVector[m].getBeginTime()<tVector[i].getFinishTime())
        m++ ;
    if(m<=NumberOfTasks)
    {
        empl.setTasks(tVector[m]) ;
        schedule(m) ;
    }
    else
        cout << "Error in schedule!" << endl ;
}

void Company::done()
{
    EmployeeFile.close() ;
    TaskFile.close() ;
}
