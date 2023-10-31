#include "Parser.h"
#include "FileManager.h"
#include "FilesHelper.h"
void FileManager::addClient(Client c) {
	FilesHelper::saveClient(c);
};
void FileManager::addEmployee(Employee e) {
	FilesHelper::saveEmployee("Employees","lastEmployee",e);
};
void FileManager::addAdmin(Employee a) {
	FilesHelper::saveEmployee("Admins", "lastAdmin", a);
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