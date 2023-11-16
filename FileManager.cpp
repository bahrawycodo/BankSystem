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
	return *FilesHelper::getClients();
};
vector<Employee> FileManager::getAllEmployees() {
	return *FilesHelper::getEmployees();
};
Admin* FileManager::getAllAdmins() {
	return FilesHelper::getAdmins();
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
