#include "Employee.h"
#pragma once
class Admin:public Employee
{
public:
	Admin();
	Admin(int id, string name, string password, double salary);
};

