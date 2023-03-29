#ifndef COMPANY_H_INCLUDED
#define COMPANY_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std ;
#include "Task.h"
#include "Employee.h"

class Company
{
public:
    static Company &getObject() ;

    void WhatToDo(string) ;
    void fillVecs() ;
    void prntVecs() ;

    fstream TaskFile ;
    fstream EmployeeFile ;
    unsigned int NumberOfTasks=0 ;
    unsigned int NumberOfEmployees=0 ;
private:
    static string CommandsName[10] ;
    Task tsk ;
    Employee empl ;
    vector<Task> tVector ;
    vector<Employee> eVector ;

    void today() ;
    void month() ;
    void addTask() ;
    void findTime() ;
    void now() ;
    void free() ;
    void addEmployee() ;
    void assignTask() ;
    void schedule(unsigned int=0) ;
    void done() ;

    Company() {}
    Company(const Company &) = delete ;
    void operator=(const Company &) = delete ;
};


#endif // COMPANY_H_INCLUDED
