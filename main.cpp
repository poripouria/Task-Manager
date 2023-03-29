//POURIA ALIMORADPOR
//Project for managing tasks in a company

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <stdexcept>
using namespace std ;
#include "Company.h"


int main()
{
    try
    {
        fstream EmployeeFile("EmployeeFile") ;
        fstream TaskFile("TaskFile") ;
        Company &c = Company::getObject() ;     //Only object of Company Class
        if(!EmployeeFile || !TaskFile)
        {
            cerr << "Error in file!" << endl ;
            return 0 ;
        }
        string command ;
        do
        {
            getline(cin, command) ;
            c.WhatToDo(command) ;
        }
        while (command != "done") ;
        c.WhatToDo("done") ;
        cout << "Number of Tasks    : " << c.NumberOfTasks << endl ;
        cout << "Number of employees: " << c.NumberOfEmployees << endl ;
    }
    catch(const exception &err)
    {
        cout << err.what() << endl ;
    }

    return 0;
}
