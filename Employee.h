#include "Person.h"
#include "Client.h"
#pragma once
class Employee :public Person
{
private:
	double salary;
public:
	//Constructors
	Employee();
	Employee(int id, string name, string password, double salary);
	//Setters
	void setData(int id, string name, string password, double salary);
	void setSalary(double salary);
	//getters
	double getSalary();
	//Methods
	void Display();
	void addClient(Client& client);
	Client* searchClient(int id);
	void listClient();
	void editClient(int id, string name, string password, double balance);
	void updatePassword(int id, string password);
};

