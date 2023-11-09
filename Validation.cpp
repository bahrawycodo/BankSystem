#include "Validation.h"
#include "Client.h"
bool Validation::Name(string name){
    bool flag = false;
    for (int i = 0; i < name.size(); ++i) {
        if (isalpha(name[i])) {
            flag = true;
        }
        else { flag = false; }
    }
    if (name.length() >= 5 && name.length() <= 20 && flag)
        return true;
    return false;
}
bool Validation::Password(string password) {
    if (password.length() >= 8 && password.length() <= 20)
        return true;
    return false;
}
bool Validation::Balance(double balance) {
    if (balance >= 1500)
        return true;
    return false;
}
bool Validation::Salary(double salary) {
    if (salary >= 5000)
        return true;
    return false;
}
bool Validation::AllInOne(string name, string password, double balance = NULL, double salary = NULL) {
    bool flag = false;
    if (Validation::Name(name) && Validation::Password(password) && salary == NULL && balance == NULL)
        return true;
    else if (Validation::Name(name) && Validation::Password(password) && salary != NULL && Validation::Salary(salary))
        return true;
    else if (Validation::Name(name) && Validation::Password(password) && balance != NULL && Validation::Balance(balance))
        return true;
    
    if (!Validation::Name(name))
        Validation::NameException();

    if (!Validation::Password(password))
        Validation::PasswordException();

    if (balance != NULL && !Validation::Balance(balance))
        Validation::BalanceException();

    if (salary != NULL && !Validation::Salary(salary))
        Validation::SalaryException();

    return false;
}
bool Validation::NotorequalZero(double num) {
    if (num >= 0)
        return true;
    return false;
}
bool Validation::LargerthanZero(double num) {
    if (num > 0)
        return true;
    return false;
}
void Validation::NameException() {
    cout << "The name must be alphabetic chars and min size 5 and max size 20\n";
}
void Validation::PasswordException() {
    cout << "Password must be with min size 8 and max size 20\n";
}
void Validation::BalanceException() {
    cout << "Min balance is 1500\n";
}
void Validation::SalaryException() {
    cout << "Min Salary is 5000\n";
}
void Validation::LoginException() {
    cout << "Incorrect id or password\n";
}
void Validation::LessZeroBalanceExeption() {
    cout << "Balance can't be less zero\n";
}