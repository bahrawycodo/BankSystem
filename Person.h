#include <iostream>
#include <string>
using namespace std;
#pragma once
class Person
{
private:
	int id;
	string name, password;
public:
	//Constructors
	Person();
	Person(int id, string name, string password);
	//Getters
	int getId();
	string getName();
	string getPassword();
	//Setters
	void setId(int id);
	void setName(string name);
	void setPassword(string password);
	//Methods
	void Display();
	
};
