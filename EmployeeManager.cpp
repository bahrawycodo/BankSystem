#include "EmployeeManager.h"
#include "Validation.h"
#include "Shared.h"
#include "ClientManger.h"
void EmployeeManager::printEmployeeMenu(){
	cout << "(1) Display my info\n";
	cout << "(2) Update Password\n";
	cout << "(3) Add new client\n";
	cout << "(4) Search for client\n";
	cout << "(5) List all clients\n";
	cout << "(6) Edit client info\n";
	cout << "(7) Logout\n";
}
void EmployeeManager::newClient(Employee* employee){
	string name, password;
	double balance;
chooseName:
	cout << "Write Client Name (between 5 to 20 chars)\n";
	cin.ignore();
	getline(cin, name);
	if (!Validation::Name(name)) {
		Validation::NameException();
		goto chooseName;
	}
choosePassword:
	cout << "Write Client Password (between 8 to 20)\n";
	getline(cin, password);
	if (!Validation::Password(password)) {
		Validation::PasswordException();
		goto choosePassword;
	}
chooseBalance:

	cout << "Write Client Balance (Min Balance = 1500)\n";
	cin >> balance;
	if (!Validation::Balance(balance))
	{
		Validation::BalanceException();
		goto chooseBalance;
	}
	Client c(0, name, password, balance);
	employee->addClient(c);


}
void EmployeeManager::listAllClients(Employee* employee){
	employee->listClient();
}
void EmployeeManager::searchForClient(Employee* employee){
	int id;
chooseId:
	cout << "Write Client Id ";
	cin >> id;
	Client* c = employee->searchClient(id);
	if (c == nullptr) {
		cout << "Please choose a valid Id \n";
		goto chooseId;
	}
	else {
		c->DisplayMainInfo();
	}
}
void EmployeeManager::editClientInfo(Employee* employee){
	int id;
	string name, password;
	double balance;
chooseId:
	cout << "Write Client Id you want to edit\n";
	cin >> id;
	if (employee->searchClient(id) == nullptr) {
		cout << "Please choose a valid Id \n";
		goto chooseId;
	}
chooseName:
	cout << "Write Client Name (between 5 to 20 chars)\n";
	cin.ignore();
	getline(cin, name);
	if (!Validation::Name(name)) {
		Validation::NameException();
		goto chooseName;
	}
choosePassword:
	cout << "Write Client Password (between 8 to 20)\n";
	getline(cin, password);
	if (!Validation::Password(password)) {
		Validation::PasswordException();
		goto choosePassword;
	}
chooseBalance:
	cout << "Write Client Balance (Min Balance = 1500)\n";
	cin >> balance;
	if (!Validation::Balance(balance))
	{
		Validation::BalanceException();
		goto chooseBalance;
	}
	employee->editClient(id, name, password, balance);

}
Employee* EmployeeManager::login(int id, string password) { 
	Employee* e = Shared::getEmployee(id);
	if (e != nullptr && e->getPassword() == password)
		return e;
	return nullptr;
}
bool EmployeeManager::employeeOptions(Employee* employee,int choice) { 
	bool flag = true;
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
		EmployeeManager::editClientInfo(employee);
		break;
	case 7:
		flag = false;
		break;
	default:
		cout << "\n\nWRONG INPUT!\n\n";
		break;
	}
	return flag;

}