#include <iostream>
#include <vector>
#include "Client.h";
#include "Employee.h"
#include "Admin.h"
#include "FilesHelper.h"
#include "FileManager.h"

using namespace std;
#pragma once
class Shared
{
public:	

	//First Time Load
	static void FirstLoad();
	//Last Time
	static void OnEnd();
	//Getters Methods
	static vector<Client> getClients();
	static vector<Employee> getEmployees();
	static Admin* getAdmin();
	//Getters By Id
	static Client* getClient(int id);
	static Employee* getEmployee(int id);
	//Reload
	static void reloadClients();
	static void reloadEmployees();

	//Addition Methods
	static void addClient(Client &c);
	static void addEmployee(Employee &e);
	static void addAdmin(Admin* a);
	//Delete Methids
	static void deleteClient(int id);
	static void deleteEmployee(int id);

	//Edit Methods
	static void editClient(int id, string name, string password,double balance);
	static void editClientName(int id, string name);
	static void editClientPassword(int id, string password);
	static void editClientBalance(int id, double balance);

	static void editEmployee(int id, string name, string password,double salary);
	static void editEmployeeName(int id, string name);
	static void editEmployeePassword(int id,  string password);
	static void editEmployeeSalary(int id, double salary);

	static void editAdmin(int id, string name, string password, double salary);
	static void editAdminName(int id, string name);
	static void editAdminPassword(int id,string password);
	static void editAdminSalary(int id,double salary);
	//Display Methods
	static void printClients();
	static void printEmployees();
	static void printAdmin();
};

