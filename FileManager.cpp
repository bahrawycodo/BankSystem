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
Admin* FileManager::getAllAdmins() {
	vector<string> ss = FilesHelper::split("Admins");
	Admin* a = Admin::getAdmin();
	if (ss.size()) {
		Employee e(Parser::parseToEmployee(ss[0]));
		a->setId(e.getId());
		a->setData(e.getName(), e.getPassword(), e.getSalary());
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
