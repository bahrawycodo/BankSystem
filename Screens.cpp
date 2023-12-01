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
#include "ReadData.h"

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
}


void login() {
	int choice = 0;
	Screens::loginOptions();
	ReadData::yourChoice(choice);
	Screens::loginScreen(choice);
}
void Screens::loginAdminLoop(Admin* admin) {
	int choice=0;
	for (;;)
	{
		system("cls");
		AdminManager::printAdminMenu();
		ReadData::yourChoice(choice);
		system("cls");
		 AdminManager::adminOptions(admin, choice);
		 if (choice == 6 || choice == 11)
			 continue;
		 else if (choice == 13)
		 {
			 login();
			 break;
		 }
		 else
			 system("pause");
	}
}
void Screens::loginEmployeeLoop(Employee* employee) {
	int choice=0;
	for (;;)
	{
		system("cls");
		EmployeeManager::printEmployeeMenu();
		ReadData::yourChoice(choice);
		system("cls");
		EmployeeManager::employeeOptions(employee, choice);
		if (choice == 6)
			continue;
		else if (choice == 8)
		{
			login();
			break;
		}
		else
			system("pause");
	}
}
void loginClientLoop(Client* client) {
	int choice = 0;
	for (;;)
	{
		system("cls");
		ClientManger::printClientMenu();
		ReadData::yourChoice(choice);
		system("cls");
		ClientManger::clientOptions(client, choice);
		if (choice == 7)
		{
			login();
			break;
		}
		else
			system("pause");
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
		ReadData::ReadLoginData(id, password);
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
		ReadData::ReadLoginData(id, password);
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
		ReadData::ReadLoginData(id,password);
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