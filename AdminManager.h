#pragma once
#include <string>
#include "Client.h"
#include "Admin.h"
class AdminManager
{
public:
	static void printAdminMenu();
	static Admin* login(int id, string password);
	static void newAdmin();
	static void adminOptions(Admin* admin,int choice);

};

