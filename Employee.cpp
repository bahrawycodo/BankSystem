#include "Person.h"
#include "Employee.h"
#include "FileManager.h"
#include "FilesHelper.h"
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
void Employee::setData(int id, string name, string password, double salary) {
	Person::setData(id, name, password);
	this->setSalary(salary);
}

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
void Employee::addClient(Client &client) {
	FileManager::addClient(client);
}
Client* Employee::searchClient(int id) {
	vector<Client> clients= FileManager::getAllClients();
	for (Client& client : clients)
	{
		if (client.getId() ==id) {
			return &client;
			break;
		}
	}
	return nullptr;
}
void Employee::listClient() {
	FilesHelper::getClients();
}
void Employee::editClient(int id, string name, string password, double balance) {
	vector<Client> clients = FileManager::getAllClients();
	FileManager::removeAllClients();
	for (Client& client : clients)
	{
		if (client.getId() == id) {
			client.setData(id,name,password,balance);
		}
		FileManager::addClient(client);
	}
}
void Client::updatePassword(int id, string password) {
	vector<Employee> employees = FileManager::getAllEmployees();
	FileManager::removeAllEmployees();
	for (Client& employee : employees)
	{
		if (employee.getId() == id) {
			employee.setPassword(password);
		}
		FileManager::addEmployee(employee);
	}
}