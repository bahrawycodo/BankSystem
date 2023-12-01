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
    static void ReadLoginData(int& id, string& password);
    static void yourChoice(int& choice);
    static Employee* ReadEmployeeId(Admin* admin,int &id);
    static Client* ReadClientId(Employee* employee,int &id);
    static void ReadClientId(Client* client,int &id);
    static void ReadName(string &name);
    static void ReadPassword(string &password);
    static void ReadPassword(string &password, bool fromOne);
    static void ReadBalance(double &balance);
    static void ReadSalary(double &salary);
    static void ReadAmount(double &amount);
};

