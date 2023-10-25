#include "Employee.h"
#include "Admin.h"
Admin::Admin() {}
Admin::Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {};
