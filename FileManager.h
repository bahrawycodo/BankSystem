#include "DataSourceInterface.h"
#pragma once
class FileManager: public DataSourceInterface
{
public:
	static void addClient(Client client);
	static void addEmployee(Employee employee);
	static void addAdmin(Admin admin);
	static vector<Client> getAllClients();
	static vector<Employee> getAllEmployees();
	static vector<Admin> getAllAdmins();
	static void removeAllClients();
	static void removeAllEmployees();
	static void removeAllAdmins();
	static Employee* employeeLogin(int id, string password);
	static Admin* adminLogin(int id, string password);
};

