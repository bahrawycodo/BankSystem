#include "Validation.h"
string Validation::Name(string name){
    bool flag = false;
    for (int i = 0; i < name.size(); ++i) {
        if (isalpha(name[i])) {
            flag = true;
        }
        else { flag = false; }
    }
    if (name.length() >= 5 && name.length() <= 20 && flag)
        return name;
    throw NameException();
}
string Validation::Password(string password) {
    if (password.length() >= 8 && password.length() <= 20)
        return password;
    throw PasswordException();
}
double Validation::Balance(double balance) {
    if (balance >= 1500)
        return balance;
    throw BalanceException();
}
double Validation::Salary(double salary) {
    if (salary >= 5000)
        return salary;
    throw SalaryException();
}

const char*NameException:: what() const throw() {
    return "The name must be alphabetic chars and min size 5 and max size 20\n";
    }
const char* PasswordException:: what() const throw() {
    return "Password must be with min size 8 and max size 20\n";
}
const char* BalanceException:: what() const throw() {
    return "Min balance is 1500\n";
}
const char* SalaryException:: what() const throw() {
    return "Min Salary is 5000\n";
}