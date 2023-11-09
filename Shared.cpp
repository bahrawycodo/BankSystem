#include "Shared.h"
#include"Client.h"
#include <vector>
vector<Client> clients;
vector<Employee> employees;
Admin* admin;

//First Load
void Shared::FirstLoad() {
	clients = FileManager::getAllClients();
	employees = FileManager::getAllEmployees();
	admin = FileManager::getAllAdmins();
}
//Last Load

void saveClients() {
	FileManager::removeAllClients();
	for (Client c : clients) {
		FileManager::addClient(c);
	}
}
void saveEmployees() {
	FileManager::removeAllEmployees();
	for (Employee e : employees) {
		FileManager::addEmployee(e);
	}
}
void saveAdmin() {
	FileManager::removeAllAdmins();
	FileManager::addAdmin(*admin);
}
void saveAll() {
	saveClients();
	saveEmployees();
	saveAdmin();
}
void endMessage() {
	cout << "\n\nGOODBYE\n\n";
}
void Shared::OnEnd() {
	saveAll();
	endMessage();
}
//Getters Methods
vector<Client> Shared::getClients() {
	return clients;
};
vector<Employee> Shared::getEmployees() {
	return employees;
};

//void Shared::reloadClients() {
//	for (int i = 0; i < clients.size(); i++)
//	{
//		clients[i].setId(i);
//	}
//}
//void Shared::reloadEmployees() {
//	for (int i = 0; i < employees.size(); i++)
//	{
//		employees[i].setId(i);
//	}
//}


//Getters By Id
Client* Shared::getClient(int id) {
	if(id <= clients.size())
		return &clients[id-1];
	return nullptr;
};
Employee* Shared::getEmployee(int id) {
	if (id <= employees.size())
		return &employees[id-1];
	return nullptr;

};
Admin* Shared::getAdmin() {
	if (admin->getId())
		return admin;
	return nullptr;
};

//Addition Methods
void Shared::addClient(Client &c) {
	c.setId(clients.size()+1);
	clients.push_back(c);
};
void Shared::addEmployee(Employee &e) {
	e.setId(employees.size()+1);
	employees.push_back(e);
};
void Shared::addAdmin(Admin *a) {
	admin = a;
	a->setId(1);
};
//Delete Methods
//void Shared::deleteClient(int id) {
//	clients.erase(clients.begin()+id-1);
//	Shared::reloadClients();
//}
//void Shared::deleteEmployee(int id) {
//	employees.erase(employees.begin() + id - 1);
//	Shared::reloadEmployees();
//}
//Edit Methods
void Shared::editClient(int id, string name, string password, double balance) {
	clients[id-1].setData(name, password, balance == NULL ? clients[id].getBalance() : balance);
};
void Shared::editEmployee(int id, string name, string password, double salary) {
	employees[id-1].setData(name, password, salary == NULL ? employees[id].getSalary() : salary);
};
void Shared::editAdmin(int id, string name, string password, double salary) {
	admin->setData(name, password, salary == NULL ? admin->getSalary() : salary);
};
//Display Methods
void Shared::printClients() {
	for (Client c: clients)
	{
		c.DisplayMainInfo();
		cout << "========================================\n";
	}
};
void Shared::printEmployees() {
	for (Employee e :employees)
	{
		e.DisplayMainInfo();
		cout << "========================================\n";
	}
};
void Shared::printAdmin() {
		admin->DisplayMainInfo();
};