#include "DataSourceInterface.h"
#pragma once
class FileManager: public DataSourceInterface
{
	static void addClient(Client c);
	static void addEmployee(Employee e);
	static void addAdmin(Employee a);
	static vector<Client> getAllClients();
	static vector<Employee> getAllEmployees();
	static vector<Admin> getAllAdmins();
	static void removeAllClients();
	static void removeAllEmployees();
	static void removeAllAdmins();
};

