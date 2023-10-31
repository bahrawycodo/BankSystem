#include <iostream>
#include <string>
#include "Client.h"
#include "Employee.h"
using namespace std;
#pragma once
class FilesHelper
{
public:
	static void saveLast(string fileName, int id);
	static int getLast(string fileName);
	static void saveOne(string fileName, string lastIdFile, string data);
	static void saveClient(Client c);
	static void saveEmployee(string fileName, string lastIdFile, Employee e);
	static void getClients();
	static void getEmployees();
	static void getAdmins();
	static void clearFile(string fileName);
	static void clearFile(string fileName, string lastIdFile);
};

