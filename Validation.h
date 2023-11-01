#include <iostream>
#include <string>
#include <fstream> 
#include <exception>
#include "Admin.h"
using namespace std;
#pragma once
class Validation {
public:
    static string Name(string name);
    static string Password(string password);
    static double Balance(double balance);
    static double Salary(double salary);
    static Client* ClientLogin(Client* client);
    static Employee* EmployeeLogin(Employee* employee);
    static Admin* AdminLogin(Admin* admin);

};
class NameException :public exception {
    virtual const char* what() const throw();
};
class PasswordException :public exception {
    virtual const char* what() const throw();
};
class BalanceException :public exception {
    virtual const char* what() const throw();
};
class SalaryException :public exception {
    virtual const char* what() const throw();
};
class LoginException :public exception {
    virtual const char* what() const throw();
};

