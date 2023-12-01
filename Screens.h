#include "Employee.h"
#include "Admin.h"
#pragma once
class Screens
{
public:
	static void bankName();
	static void welcomePrint();
	static void welcomeScreen();
	static void loginOptions();
	static void loginAdminLoop(Admin* admin);
	static void loginEmployeeLoop(Employee* employee);
	static int yourChoice();
	static void loginScreen(int c);
	static void runApp();
};

