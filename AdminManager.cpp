#include "AdminManager.h"
#include "ClientManger.h"
#include "EmployeeManager.h"
#include "Validation.h"
#include "Shared.h"
#include "Admin.h"
#include <exception>
#include "validation.h"

void AdminManager::printAdminMenu(){
	cout << "(1) Display my info\n";
	cout << "(2) Update Password\n";
	cout << "(3) Add new client\n";
	cout << "(4) Search for client\n";
	cout << "(5) List all clients\n";
	cout << "(6) Edit client info\n";
	cout << "(7) Add new Employee\n";
	cout << "(8) Search for Employee\n";
	cout << "(9) List all Employees\n";
	cout << "(10) Edit Employee info\n";
	cout << "(11) Logout\n";
	cout << "Your choise is: ";
}
void AdminManager::newAdmin() {
	string name, password;
	double salary;
chooseName:
	cout << "Write Admin Name (between 5 to 20 chars)\n";
	cin.ignore();
	getline(cin, name);
	if (!Validation::Name(name)) {
		Validation::NameException();
		goto chooseName;
	}
choosePassword:
	cout << "Write Admin Password (between 8 to 20)\n";
	getline(cin, password);
	if (!Validation::Password(password)) {
		Validation::PasswordException();
		goto choosePassword;
	}
chooseBalance:
	cout << "Write Admin Salary (Min Salary = 5000)\n";
	cin >> salary;
	if (!Validation::Salary(salary))
	{
		Validation::SalaryException();
		goto chooseBalance;
	}
	Admin *a = Admin::getAdmin();
	a->setId(1);
	a->setName(name);
	a->setPassword(password);
	a->setSalary(salary);
	Shared::addAdmin(a);

}
void newEmployee(Admin* admin) {
	string name, password;
	double salary;
chooseName:
	cout << "Write Employee Name (between 5 to 20 chars)\n";
	cin.ignore();
	getline(cin, name);
	if (!Validation::Name(name)) {
		Validation::NameException();
		goto chooseName;
	}
choosePassword:
	cout << "Write Employee Password (between 8 to 20)\n";
	getline(cin, password);
	if (!Validation::Password(password)) {
		Validation::PasswordException();
		goto choosePassword;
	}
chooseBalance:
	cout << "Write Employee Salary (Min Salary = 5000)\n";
	cin >> salary;
	if (!Validation::Salary(salary))
	{
		Validation::SalaryException();
		goto chooseBalance;
	}
	Employee e(0, name, password, salary);
	admin->addEmployee(e);

}
void searchForEmployee(Admin* admin) {
	int id;
	chooseId:
	cout << "Write Employee Id ";
	cin >> id;
	Employee* e = admin->searchEmployee(id);
	if (e == nullptr) {
		cout << "Please choose a valid Id \n";
		goto chooseId;
	}
	else {
		e->DisplayMainInfo();
	}
}
void editEmployee(Admin* admin) {
	int id;
	string name, password;
	double salary;
	chooseId:
	cout << "Write Employee Id you want to edit\n";
	cin >> id;
	if (admin->searchEmployee(id) == nullptr) {
		cout << "Please choose a valid Id \n";
		goto chooseId;
	}
chooseName:
	cout << "Write Employee Name (between 5 to 20 chars)\n";
	cin.ignore();
	getline(cin, name);
	if (!Validation::Name(name)) {
		Validation::NameException();
		goto chooseName;
	}
choosePassword:
	cout << "Write Employee Password (between 8 to 20)\n";
	getline(cin, password);
	if (!Validation::Password(password)) {
		Validation::PasswordException();
		goto choosePassword;
	}
chooseBalance:
	cout << "Write Employee Salary (Min Salary = 5000)\n";
	cin >> salary;
	if (!Validation::Salary(salary))
	{
		Validation::SalaryException();
		goto chooseBalance;
	}
		admin->editEmployee(id,name,password,salary);
}
void listAllEmployees(Admin* admin) {
	admin->listEmployee();
}
Admin* AdminManager::login(int id, string password){
	if (Shared::getAdmin()->getId() == 0)
		newAdmin();
	Admin* a = Shared::getAdmin();
	if (a->getId() == id && a->getPassword() == password)
		return a;
	return nullptr;
}
bool AdminManager::adminOptions(Admin* admin,int choice){
	bool flag = true;
	switch (choice)
		{
		case 1:
			admin->Display();
			break;
		case 2:
			ClientManger::updatePassword(admin);
			break;
		case 3:
			EmployeeManager::newClient(admin);
			break;
		case 4:
			EmployeeManager::searchForClient(admin);
			break;
		case 5:
			EmployeeManager::listAllClients(admin);
			break;
		case 6:
			EmployeeManager::editClientInfo(admin);
			break;
		case 7:
			newEmployee(admin);
			break;
		case 8:
			searchForEmployee(admin);
			break;
		case 9:
			listAllEmployees(admin);
			break;
		case 10:
			editEmployee(admin);
			break;
		case 11:
			flag = false;
			break;
		default:
			cout << "\n\nWRONG INPUT!\n\n";
			break;
		}
	return flag;
}
void addNewEmployee() {
	string name, password;
	double salary;
	cout << "Write Employee Name (between 5 and 20 chars)\n";
	cin >> name;
	cout << "Write Employee Password (between 8 and 20 chars)\n";
	cin >> password;
	cout << "Write Employee Salary (Min Salary is 5000)\n";
	cin >> salary;
	Employee e( 0,name,password,salary );
	Shared::addEmployee(e);
}