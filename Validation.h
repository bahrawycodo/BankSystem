#include <iostream>
#include <string>
#include <fstream> 
#include <exception>
#include "Admin.h"
using namespace std;
#pragma once
class Validation {
public:
    static bool Name(string name);
    static bool Password(string password);
    static bool Balance(double balance);
    static bool Salary(double salary);
    static bool AllInOne(string name, string password, double balance, double salary);
    static bool NotorequalZero(double num);
    static bool LargerthanZero(double num);
    static void NameException();
    static void PasswordException();
    static void BalanceException();
    static void SalaryException();
    static void LoginException();
    static void LessZeroBalanceExeption();
};
