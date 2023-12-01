#pragma once
#include "Client.h"
#include "Employee.h"
class EmployeeManager
{
public:
	static void printEmployeeMenu();
	static void newClient(Employee* employee);
	static void listAllClients(Employee* employee);
	static void searchForClient(Employee* employee);
	static void editClientInfo(Employee* employee);
	static void editClientName(Employee* employee);
	static void editClientPassword(Employee* employee);
	static void editClientBalance(Employee* employee);
	static void deleteClient(Employee* employee);
	static Employee* login(int id, string password);
	static void employeeOptions(Employee* employee,int choice);
	static void clientEditLoop(Employee* employee);

};

