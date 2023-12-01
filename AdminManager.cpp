#include "AdminManager.h"
#include "ClientManger.h"
#include "EmployeeManager.h"
#include "Validation.h"
#include "Shared.h"
#include "Admin.h"
#include "ReadData.h"
#include "Screens.h"
#include <windows.h>

void AdminManager::printAdminMenu(){
	cout << "(1) Display my info\n";
	cout << "(2) Update Password\n";
	cout << "(3) Add new client\n";
	cout << "(4) Search for client\n";
	cout << "(5) List all clients\n";
	cout << "(6) Edit client info\n";
	cout << "(7) Delete client\n";
	cout << "(8) Add new Employee\n";
	cout << "(9) Search for Employee\n";
	cout << "(10) List all Employees\n";
	cout << "(11) Edit Employee info\n";
	cout << "(12) Delete Employee\n";
	cout << "(13) Logout\n";
}
void printEmployeeEditMenu() {
	cout << "(1) Edit All Data\n";
	cout << "(2) Edit Name\n";
	cout << "(3) Edit Password\n";
	cout << "(4) Edit Salary\n";
	cout << "(5) Exit\n";
}
void AdminManager::newAdmin() {
	string name, password;
	double salary;
	ReadData::ReadName(name);
	ReadData::ReadPassword(password);
	ReadData::ReadSalary(salary);

	Admin *a = Admin::getAdmin();
	a->setId(1);
	a->setName(name);
	a->setPassword(password);
	a->setSalary(salary);
	Shared::addAdmin(a);
	system("cls");
	cout << "Admin Added Successfully\n";
}
void newEmployee(Admin* admin) {
	string name, password;
	double salary;
	ReadData::ReadName(name);
	ReadData::ReadPassword(password);
	ReadData::ReadSalary(salary);
	Employee e(0, name, password, salary);
	admin->addEmployee(e);
	system("cls");
	cout << "Employee Added Successfully\n";
}
void searchForEmployee(Admin* admin) {
	int id;
	Employee* e = ReadData::ReadEmployeeId(admin, id);
	e->DisplayMainInfo();
}
void editEmployee(Admin* admin) {
	int id;
	string name, password;
	double salary;
	ReadData::ReadEmployeeId(admin, id);
	ReadData::ReadName(name);
	ReadData::ReadPassword(password);
	ReadData::ReadSalary(salary);

	admin->editEmployee(id,name,password,salary);
	system("cls");
	cout << "Employee Data Edited Successfully\n";

}
void editEmployeeName(Admin* admin) {
	int id;
	string name;
	ReadData::ReadEmployeeId(admin, id);
	ReadData::ReadName(name);

	admin->editEmployee(id,name,"", NULL);
	system("cls");
	cout << "Employee Name Edited Successfully\n";

}
void editEmployeePassword(Admin* admin) {
	int id;
	string password;
	ReadData::ReadEmployeeId(admin, id);
	ReadData::ReadPassword(password,true);

	admin->editEmployee(id, "", password, NULL);
	system("cls");

	cout << "Employee Password Edited Successfully\n";

}
void editEmployeeSalary(Admin* admin) {
	int id;
	double salary;
	ReadData::ReadEmployeeId(admin, id);
	ReadData::ReadSalary(salary);

	admin->editEmployee(id, "", "", salary);
	system("cls");

	cout << "Employee Salary Edited Successfully\n";

}
void employeeEditOptions(Admin* admin, int choice) {
	switch (choice)
	{
	case 1:
		editEmployee(admin);
		system("pause");
		break;
	case 2:
		editEmployeeName(admin);
		system("pause");
		break;
	case 3:
		editEmployeePassword(admin);
		system("pause");
		break;
	case 4:
		editEmployeeSalary(admin);
		system("pause");
		break;
	case 5:
		break;
	default:
		cout << "\n\nWRONG INPUT!\n\n";
		break;
	}
}

void listAllEmployees(Admin* admin) {
	admin->listEmployee();
}
void deleteEmployee(Admin* admin) {
	if (Shared::getEmployees().size() == 0) {
		Validation::NoEmployees();
		return;
	}
	int id;
	ReadData::ReadClientId(admin, id);
	admin->deleteEmployee(id);
	cout << "Employee Deleted Successfully\n"; 
}
Admin* AdminManager::login(int id, string password){
	if (Shared::getAdmin()->getId() == 0)
		newAdmin();
	Admin* a = Shared::getAdmin();
	if (a->getId() == id && a->getPassword() == password)
		return a;
	return nullptr;
}
void employeeEditLoop(Admin* admin) {
	int choice = 0;
	system("cls");
	printEmployeeEditMenu();
	ReadData::yourChoice(choice);
	system("cls");
	employeeEditOptions(admin, choice);
	return;
}
void AdminManager::adminOptions(Admin* admin,int choice){
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
			EmployeeManager::clientEditLoop(admin);
			break;
		case 7:
			EmployeeManager::deleteClient(admin);
			break;
		case 8:
			newEmployee(admin);
			break;
		case 9:
			searchForEmployee(admin);
			break;
		case 10:
			listAllEmployees(admin);
			break;
		case 11:
			employeeEditLoop(admin);
			break;
		case 12:
			deleteEmployee(admin);
			break;
		case 13:
			break;
		default:
			cout << "\n\nWRONG INPUT!\n\n";
			break;
		}
}

