#include "Employee.h"
#pragma once
class Admin:public Employee
{
private:	
	Admin();
	Admin(int id,string name, string password, double salary);
	//private static object
	static Admin* myAdmin;
public:
	//Public get instance method
	static Admin* getAdmin();
	//Methods
	void addEmployee(Employee& employee);
	Employee* searchEmployee(int id);
	void editEmployee(int id, string name, string password, double salary);
	void listEmployee();
};

