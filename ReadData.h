#include <iostream>
#include <string>
#include <fstream> 
#include <exception>
#include "Admin.h"
using namespace std;

#pragma once

class ReadData
{
public:
    static Employee* ReadEmployeeId(Admin* admin,int &id);
    static Client* ReadClientId(Employee* employee,int &id);
    static void ReadName(string &name);
    static void ReadPassword(string &password);
    static void ReadBalance(double &balance);
    static void ReadSalary(double &salary);
};

