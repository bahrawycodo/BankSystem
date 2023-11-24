#include <Windows.h>
#include <conio.h> 
#include <iostream>
#include <ctime>
#include "Screens.h"
#include "AdminManager.h"
#include "EmployeeManager.h"
#include "ClientManger.h"
#include "Validation.h"
#include "Shared.h"

using namespace std;
void Screens::bankName() {
	cout << "	   	@@         @@   @@@@@@@         #######    ########  ####     ##   ##   ##\n";
	cout << "           	@@    @    @@   @@              ##    ##   ##    ##  ## ##    ##   ##  ##\n";
	cout << "           	@@   @@@   @@   @@@@@@@         #######    ########  ##  ##   ##   ## #\n";
	cout << "           	@@  @@ @@  @@   @@              ##    ##   ##    ##  ##   ##  ##   ##  ##\n";
	cout << "           	@@@       @@@   @@@@@@@         #######    ##    ##  ##    ####    ##   ##\n";
}
void Screens::welcomePrint() {
	cout << "\n\n\n\n\n\n           ##         ##   #######    ##        #######    ########    ####    ####    #######\n";
	cout << "           ##    #    ##   ##         ##        ##         ##    ##    ##  #  #  ##    ##\n";
	cout << "           ##   ###   ##   #######    ##        ##	   ##    ##    ##   ##   ##    #######\n";
	cout << "           ##  ## ##  ##   ##         ##        ##	   ##    ##    ##        ##    ##\n";
	cout << "           ###       ###   #######    ######    #######    ########    ##        ##    #######\n\n\n";
}
void Screens::welcomeScreen() {
	system("color 97");
	Screens::welcomePrint();
	Screens::bankName();
	Sleep(5000);
	system("cls");
	system("color 7");
}

void Screens::loginOptions() {
	cout << "(1) Admin\n";
	cout << "(2) Employee\n";
	cout << "(3) Client\n";
	cout << "(4) Exit\n";
	cout << "Login as: ";
}
int Screens::yourChoice() {
	int choice;
	cin >> choice;
	return choice;
}

void Screens::invalid(int c) {

}
void Screens::logout() {

}
void login() {
	Screens::loginOptions();
	Screens::loginScreen(Screens::yourChoice());
}
void Screens::loginAdminLoop(Admin* admin) {
	bool flag = true;
	while (flag) {
		system("cls");
		AdminManager::printAdminMenu();
		int choice = Screens::yourChoice();
		system("cls");
		flag = AdminManager::adminOptions(admin, choice);
		if (flag) {
			system("pause");
		}
		else {
			login();
		}
	}
}
void Screens::loginEmployeeLoop(Employee* employee) {
	bool flag = true;
	while (flag) {
		system("cls");
		EmployeeManager::printEmployeeMenu();
		int choice = Screens::yourChoice();
		system("cls");
		flag = EmployeeManager::employeeOptions(employee, choice);
		if (flag) {
			system("pause");
		}
		else {
			login();
		}
	}
}
void loginClientLoop(Client* client) {
	bool flag = true;
	while (flag) {
		system("cls");
		ClientManger::printClientMenu();
		int choice = Screens::yourChoice();
		system("cls");
		flag = ClientManger::clientOptions(client, choice);
		if (flag) {
			system("pause");
		}
		else {
			login();
		}
	}
}
void  loginAdmin() {
	if (Shared::getAdmin() == nullptr) {
		Validation::NoAdmin();
		AdminManager::newAdmin();
		system("cls");
		login();
	}
	else {
		int id;
		string password;
	ChooseData:
		cout << "Write your Id\n";
		cin >> id;
		cout << "Write your Password\n";
		cin >> password;
		Admin* admin = AdminManager::login(id, password);
		if (admin == nullptr) {
			system("cls");
			Validation::LoginException();
			goto ChooseData;
		}
		else {
			Screens::loginAdminLoop(admin);
		}
	}
}
void loginEmployee() {
	if (Shared::getEmployees().size() == 0) {
		Validation::LogNoEmployees();
		login();
	}
	else {
		int id;
		string password;
	ChooseData:
		cout << "Write your Id\n";
		cin >> id;
		cout << "Write your Password\n";
		cin >> password;
		Employee* employee = EmployeeManager::login(id, password);
		if (employee == nullptr) {
			system("cls");
			Validation::LoginException();
			goto ChooseData;
		}
		else {
			Screens::loginEmployeeLoop(employee);
		}
	}
}
void loginClient() {
	if (Shared::getEmployees().size() == 0) {
		Validation::LogNoClients();
		login();
	}
	else {
		int id;
		string password;
	ChooseData:
		cout << "Write your Id\n";
		cin >> id;
		cout << "Write your Password\n";
		cin >> password;
		Client* client = ClientManger::login(id, password);
		if (client == nullptr) {
			system("cls");
			Validation::LoginException();
			goto ChooseData;
		}
		else {
			loginClientLoop(client);
		}
	}
}

void Screens::loginScreen(int c) {
	system("cls");
	switch (c)
	{
	case 1:
		loginAdmin();
		break;
	case 2:
		loginEmployee();
		break;
	case 3:
		loginClient();
		break;
	case 4:
		exit;
		break;
	default:
		break;
	}
	
}

void Screens::runApp() {
	Shared::FirstLoad();
	welcomeScreen();
	login();
	atexit(Shared::OnEnd);
}