#include "Parser.h"
#include "FileManager.h"
#include "FilesHelper.h"
void FileManager::addClient(Client client) {
	FilesHelper::saveClient(client);
};
void FileManager::addEmployee(Employee employee) {
	FilesHelper::saveEmployee("Employees","lastEmployee", employee);
};
void FileManager::addAdmin(Admin admin) {
	FilesHelper::saveEmployee("Admins", "lastAdmin", admin);
};
vector<Client> FileManager::getAllClients() {
	vector<string> ss = FilesHelper::split("Clients");
	vector<Client> c;
	for (int i = 0; i < ss.size(); ++i)
	{
		c.push_back(Parser::parseToClient(ss[i]));
	}
	return c;
};
vector<Employee> FileManager::getAllEmployees() {
	vector<string> ss = FilesHelper::split("Employees");
	vector<Employee> e;
	for (int i = 0; i < ss.size(); ++i)
	{
		e.push_back(Parser::parseToEmployee(ss[i]));
	}
	return e;
};
vector<Admin> FileManager::getAllAdmins() {
	vector<string> ss = FilesHelper::split("Admins");
	vector<Admin> a;
	for (int i = 0; i < ss.size(); ++i)
	{
		a.push_back(Parser::parseToAdmin(ss[i]));
	}
	return a;

};
void FileManager::removeAllClients() {
	FilesHelper::clearFile("Clients", "lastClient");
};
void FileManager::removeAllEmployees() {
	FilesHelper::clearFile("Employees", "lastEmployee");
};
void FileManager::removeAllAdmins() {
	FilesHelper::clearFile("Admins", "lastAdmin");
};
Employee* employeeLogin(int id, string password){
	vector<Employee> employees = FileManager::getAllEmployees();
	for (Employee& employee : employees)
	{
		if (employee.getId() == id && employee.getPassword() == password) {
			return &employee;
			break;
		}
	}
	return nullptr;
}
Admin* adminLogin(int id, string password){
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