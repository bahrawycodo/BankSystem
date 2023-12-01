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
void Person::setName(string name) {
	this->name = name;
}
void Person::setPassword(string password) {
	this->password = password;
}
void Person::DisplayMainInfo() {
	cout << this->id << endl;
	cout << this->name << endl;
}
void Person::Display() {
	Person::DisplayMainInfo();
	cout << this->password << endl;
}
