#include <string>
#include <vector>
#include <fstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#pragma once
class Parser
{
public:
	static vector<string> split(fstream &line);
	static Client parseToClient(string line);
	static Employee parseToEmployee(string line);
};

