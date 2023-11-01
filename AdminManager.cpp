#include "AdminManager.h"
#include "FileManager.h"
#include "Admin.h"
#include "Validation.h"
void AdminManager::printClientMenu(){
	
	int id = 0;
	string password;
newlogin:
	cout << "Enter Id";
	cin >> id;

	cout << "\nEnter Password";
	cin >> password;
	try
	{
		Admin* a = Validation::AdminLogin(AdminManager::login(id, password));
	}
	catch (exception& e) {
	{
		cout << e.what();
		goto newlogin;
	}

	//int choice = AdminManager::AdminOptions();

}
Admin* AdminManager::login(int id, string password){
	vector<Admin> admins = FileManager::getAllAdmins();
	for (Admin& admin : admins)
	{
		if (admin.getId() == id && admin.getPassword() == password) {
			return &admin;
			break;
		}
	}
	return nullptr;
}
bool AdminManager::AdminOptions(Admin* admin){
	int choice = 0;
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
	cin >> choice;
	return choice;
}