#include "Employee.h"
#include "Admin.h"
#include "FileManager.h"
#include "Shared.h"
Admin* Admin::myAdmin = nullptr;
Admin::Admin() {}
Admin::Admin(int id,string name, string password, double salary) : Employee(id,name, password, salary) {};
//Methods
Admin* Admin::getAdmin() {
	if (myAdmin == nullptr) {
		myAdmin = new Admin;
	}
	return myAdmin;
}
void Admin::addEmployee(Employee& employee) {
	Shared::addEmployee(employee);
}
Employee* Admin::searchEmployee(int id) {
	return Shared::getEmployee(id);
}
void Admin::editEmployee(int id, string name, string password, double salary) {
	Shared::editEmployee(id, name, password, salary);
}
void Admin::listEmployee() {
	Shared::printEmployees();
}