#include "Employee.h"
#pragma once
class Admin:public Employee
{
public:
	Admin();
	Admin(int id, string name, string password, double salary);
	//Methods
	void addEmployee(Employee& employee);
	Employee* searchEmployee(int id);
	void editEmployee(int id, string name, string password, double salary);
	void listEmployee();
	void updatePassword(int id, string password);
};

