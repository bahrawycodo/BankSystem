#include "Person.h"
#include "Employee.h"
#include "FileManager.h"
#include "FilesHelper.h"
#include <exception>
#include "validation.h"
#include "Shared.h"
Employee::Employee(){
	this->salary = 5000;
}
Employee::Employee(int id,string name, string password, double salary) : Person(id,name, password) {
	this->salary = 5000;
	this->setSalary(salary);
}
//Setters
void Employee::setData(string name, string password, double salary) {
	Person::setData( name, password);
	this->setSalary(salary);
}

void Employee::setSalary(double salary) {
	if (Validation::Salary(salary))
		this->salary = salary;
}
//Operator = Overloading
void Employee::operator = (Employee e) {
	this->setData(e.getName(), e.getPassword(), e.getSalary());
}
//getters
double Employee::getSalary() {
	return this->salary;
}
//Methods
void Employee::DisplayMainInfo() {
	Person::DisplayMainInfo();
	cout << this->salary << endl;
}
void Employee::Display() {
	Person::Display();
	cout << this->salary << endl;
}
void Employee::addClient(Client &client) {
	Shared::addClient(client);
}
Client* Employee::searchClient(int id) {
	return Shared::getClient(id);
}
void Employee::listClient() {
	Shared::printClients();
}
void Employee::editClient(int id, string name, string password, double balance) {
	Shared::editClient(id, name, password, balance);
}
void Employee::deleteClient(int id) {
	Shared::deleteClient(id);
}
