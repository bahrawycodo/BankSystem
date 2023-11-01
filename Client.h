#include "Person.h"
#pragma once
class Client :public Person
{
private:
	double balance;
public:
	//Constructors
	Client();
	Client(int id, string name, string password, double balance);
	//Setters
	void setBalance(double balance);
	void setData(int id, string name, string password, double balance);
	//getters
	double getBalance();
	//Methods
	void deposit(double amount);
	void withdraw(double amount);
	void transferTo(double amount, Client& recipient);
	void checkBalance();
	void Display();
	void updatePassword(int id, string password);
};

