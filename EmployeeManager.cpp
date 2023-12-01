#include "EmployeeManager.h"
#include "Validation.h"
#include "Shared.h"
#include "ClientManger.h"
#include "ReadData.h"
void EmployeeManager::printEmployeeMenu(){
	cout << "(1) Display my info\n";
	cout << "(2) Update Password\n";
	cout << "(3) Add new client\n";
	cout << "(4) Search for client\n";
	cout << "(5) List all clients\n";
	cout << "(6) Edit client info\n";
	cout << "(7) Delete client\n";
	cout << "(8) Logout\n";
}
void printClientEditMenu(){
	cout << "(1) Edit All Data\n";
	cout << "(2) Edit Name\n";
	cout << "(3) Edit Password\n";
	cout << "(4) Edit Balance\n";
	cout << "(5) Exit\n";
}
void EmployeeManager::newClient(Employee* employee){
	string name,password;
	double balance;
	ReadData::ReadName(name);
	ReadData::ReadPassword(password);
	ReadData::ReadBalance(balance);
	Client c(0,name , password,balance);
	employee->addClient(c);
	system("cls");
	cout << "Client Added Successfully\n";
}
void EmployeeManager::listAllClients(Employee* employee){
	employee->listClient();
}
void EmployeeManager::searchForClient(Employee* employee){
	int id;
	Client* c = ReadData::ReadClientId(employee, id);
	c->DisplayMainInfo();
}
void EmployeeManager::editClientInfo(Employee* employee){
	int id;
	string name, password;
	double balance;
	ReadData::ReadClientId(employee, id);
	ReadData::ReadName(name);
	ReadData::ReadPassword(password);
	ReadData::ReadBalance(balance);

	employee->editClient(id, name, password, balance);
	system("cls");
	cout << "Client Data Edited Successfully\n";
}
void EmployeeManager::editClientName(Employee* employee) {
	int id;
	string name;
	ReadData::ReadClientId(employee, id);
	ReadData::ReadName(name);

	employee->editClient(id, name, "", NULL);
	system("cls");
	cout << "Client Name Edited Successfully\n";
}
void EmployeeManager::editClientPassword(Employee* employee) {
	int id;
	string password;
	ReadData::ReadClientId(employee, id);
	ReadData::ReadPassword(password,true);

	employee->editClient(id, "", password, NULL);
	system("cls");
	cout << "Client Password Edited Successfully\n";
}
void EmployeeManager::editClientBalance(Employee* employee) {
	int id;
	double balance;
	ReadData::ReadClientId(employee, id);
	ReadData::ReadBalance(balance);

	employee->editClient(id, "", "", balance);
	system("cls");
	cout << "Client Balance Edited Successfully\n";
}
void EmployeeManager::deleteClient(Employee* employee) {
	if (Shared::getClients().size() == 0) {
		Validation::NoClients();
		return;
	}
	int id;
	ReadData::ReadClientId(employee, id);
	employee->deleteClient(id);
	system("cls");
	cout << "Client Deleted Successfully\n";
}
Employee* EmployeeManager::login(int id, string password) { 
	Employee* e = Shared::getEmployee(id);
	if (e != nullptr && e->getPassword() == password)
		return e;
	return nullptr;
}
void clientEditOptions(Employee* employee, int choice) {
	switch (choice)
	{
	case 1:
		EmployeeManager::editClientInfo(employee);
		system("pause");
		break;
	case 2:
		EmployeeManager::editClientName(employee);
		system("pause");
		break;
	case 3:
		EmployeeManager::editClientPassword(employee);
		system("pause");
		break;
	case 4:
		EmployeeManager::editClientBalance(employee);
		system("pause");
		break;
	case 5:

		break;
	default:
		cout << "\n\nWRONG INPUT!\n\n";
		break;
	}

}

void EmployeeManager::clientEditLoop(Employee* employee) {
		int choice = 0;	
		system("cls");
		printClientEditMenu();
		ReadData::yourChoice(choice);
		system("cls");
		 clientEditOptions(employee, choice);
		return;
}
void EmployeeManager::employeeOptions(Employee* employee,int choice) { 
	switch (choice)
	{
	case 1:
		employee->Display();
		break;
	case 2:
		ClientManger::updatePassword(employee);
		break;
	case 3:
		EmployeeManager::newClient(employee);
		break;
	case 4:
		EmployeeManager::searchForClient(employee);
		break;
	case 5:
		EmployeeManager::listAllClients(employee);
		break;
	case 6:
		EmployeeManager::clientEditLoop(employee);
		break;
	case 7:
		EmployeeManager::deleteClient(employee);
		break;
	case 8:
		break;
	default:
		cout << "\n\nWRONG INPUT!\n\n";
		break;
	}
}

