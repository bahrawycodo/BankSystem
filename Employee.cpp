#include "Person.h"
#include "Employee.h"
#include <exception>
#include "validation.h"
Employee::Employee(){
	this->salary = 5000;
}
Employee::Employee(int id, string name, string password, double salary) : Person(id, name, password) {
	this->salary = 5000;
	this->setSalary(salary);
}
//Setters
void Employee::setSalary(double salary) {
	try {
		this->salary = Validation::Salary(salary);
	}
	catch (exception& e) {
		cout << e.what();
	}
}
//getters
double Employee::getSalary() {
	return this->salary;
}
//Methods
void Employee::Display() {
	Person::Display();
	cout << this->salary << endl;
}
