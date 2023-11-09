#include "Person.h"
#include <exception>
#include "validation.h"
//Constructors
Person::Person() {
	this->id = 0;
}
Person::Person(int id,string name, string password) {
	this->setId(id);
	this->setName(name);
	this->setPassword(password);
}
//Getters
int Person::getId() {
	return this->id;
}
string Person::getName() {
	return this->name;
}
string Person::getPassword() {
	return this->password;
}
//Setters
void Person::setData(string name, string password) {
	this->setName(name);
	this->setPassword(password);
}
void Person::setId(int id) {
	this->id = id;
}
bool Person::setName(string name) {
	if (Validation::Name(name)) {
		this->name = name;
		return true;
	}
	return false;
}
bool Person::setPassword(string password) {
	if (Validation::Password(password))
	{
		this->password = password;
		return true;
	}
	return false;
}
void Person::DisplayMainInfo() {
	cout << this->id << endl;
	cout << this->name << endl;
}
void Person::Display() {
	Person::DisplayMainInfo();
	cout << this->password << endl;
}
