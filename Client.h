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
	void setData( string name, string password, double balance);
	//Operator = Overloading
	void operator = (Client c);
	//getters
	double getBalance();
	//Methods
	void deposit(double amount);
	bool withdraw(double amount);
	bool transferTo(double amount, Client* recipient);
	void checkBalance();
	void DisplayMainInfo();
	void Display();
};

