#pragma once
#include "Client.h"
#include "Employee.h"
class EmployeeManager
{
public:
	static void printClientMenu();
	static void newClient(Employee* employee);
	static void listAllClients(Employee* employee);
	static void searchForClient(Employee* employee);
	static void editClientInfo(Employee* employee);
	static Client* login(int id, string password);
	static bool employeeOptions(Client* client);
};

