#include "Person.h"
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
	void setSalary(double salary);
	//getters
	double getSalary();
	//Methods
	void Display();

};

