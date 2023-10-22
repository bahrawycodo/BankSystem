#include "Person.h"
#include <exception>
#include "validation.h"
//Constructors
Person::Person() {
	this->id = 0;
}
Person::Person(int id, string name, string password) {
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
void Person::setId(int id) {
	this->id = id;
}
void Person::setName(string name) {
	try{	
		this->name = Validation::Name(name);
	}
	catch (exception& e) {
		cout << e.what();
	}
}
void Person::setPassword(string password) {
	try {
		this->password = Validation::Password(password);
	}
	catch (exception& e) {
		cout << e.what();
	}
}
void Person::Display() {
	cout << this->id << endl;
	cout << this->name << endl;
	cout << this->password << endl;
}
