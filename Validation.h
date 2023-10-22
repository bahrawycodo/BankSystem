#include <iostream>
#include <string>
#include <exception>
using namespace std;
#pragma once
class Validation {
public:
    static string Name(string name);
    static string Password(string password);
    static double Balance(double balance);
    static double Salary(double salary);
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

