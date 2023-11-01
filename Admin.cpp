#include "Employee.h"
#include "Admin.h"
#include "FileManager.h"
#include "FilesHelper.h"
Admin::Admin() {}
Admin::Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {};
//Methods
void Admin::addEmployee(Employee& employee) {
	FileManager::addEmployee(employee);
}
Employee* Admin::searchEmployee(int id) {
	vector<Employee> employees = FileManager::getAllEmployees();
	for (Employee& employee : employees)
	{
		if (employee.getId() == id) {
			return &employee;
			break;
		}
	}
	return nullptr;
}
void Admin::editEmployee(int id, string name, string password, double salary) {
	vector<Employee> employees = FileManager::getAllEmployees();
	FileManager::removeAllEmployees();
	for (Employee& employee : employees)
	{
		if (employee.getId() == id) {
			employee.setData(id, name, password, salary);
		}
		FileManager::addEmployee(employee);
	}
}
void Admin::listEmployee() {
	FilesHelper::getEmployees();
}
void Admin::updatePassword(int id, string password) {
	vector<Admin> admins = FileManager::getAllAdmins();
	FileManager::removeAllAdmins();
	for (Admin& admin : admins)
	{
		if (admin.getId() == id) {
			admin.setPassword(password);
		}
		FileManager::addAdmin(admin);
	}
}