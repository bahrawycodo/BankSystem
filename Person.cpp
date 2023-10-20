#include "Person.h"
//Constructors
Person::Person() {
	this->id = 0;
}
Person::Person(int id, string name, string password) {
	this->id = id;
	this->name = name;
	this->password = password;
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
void Person::setId(int id) {
	this->id = id;
}
void Person::setName(string name) {
	this->name = name;
}
void Person::setPassword(string password) {
	this->password = password;
}
void Person::Display() {
	cout << this->id << endl;
	cout << this->name << endl;
	cout << this->password << endl;
}
