#include <iostream>
#include <fstream> 
#include <string>
#include "FilesHelper.h"
#include "Client.h"
#include "Employee.h"
#include "Parser.h"
using namespace std;
string toString(double value) {
	string v = to_string(value);
	v.erase(v.find_last_not_of('0') + 1, string::npos);
	v.erase(v.find_last_not_of('.') + 1, string::npos);
	return v;
}
void  FilesHelper::saveLast(string fileName, int id) {
	fstream File(fileName + ".txt", fstream::out | fstream::trunc);
	File << id;
	File.close();
}
int FilesHelper::getLast(string fileName) {
	fstream File(fileName + ".txt");
	int lId = 0;
	File >> lId;
	File.close();
	return lId ? int(lId) : 0;
};
void FilesHelper::saveOne(string fileName, string lastIdFile,string data ) {
	fstream File(fileName + ".txt", fstream::app);
	int id = FilesHelper::getLast(lastIdFile) + 1;
	File << id << "&" << data << endl;
	FilesHelper::saveLast(lastIdFile, id);
	File.close();
}
 
void FilesHelper::saveClient(Client c) {
	FilesHelper::saveOne("Clients", "lastClient", c.getName() + "&" + c.getPassword() + "&" + toString(c.getBalance()));
};
void FilesHelper::saveEmployee(string fileName, string lastIdFile, Employee e) {
	FilesHelper::saveOne(fileName, lastIdFile, e.getName() + "&" + e.getPassword() + "&" + toString(e.getSalary()));
};

void FilesHelper::getClients() {
	fstream File("Clients.txt", ios::in);
	vector<string> ss = Parser::split(File);
	for (int i = 0; i < ss.size(); ++i)
	{
		Client c(Parser::parseToClient(ss[i]));
		cout << "Id = " << c.getId() << endl;
		cout << "Name = " << c.getName() << endl;
		cout << "Balance = " << c.getBalance() << endl;
		cout << "========================================\n";
	}
	File.close();
};
void FilesHelper::getEmployees() {
	fstream File("Employees.txt", ios::in);
	vector<string> ss = Parser::split(File);
	for (int i = 0; i < ss.size(); ++i)
	{
		Employee e(Parser::parseToEmployee(ss[i]));
		cout << "Id = " << e.getId() << endl;
		cout << "Name = " << e.getName() << endl;
		cout << "Salary = " << e.getSalary() << endl;
		cout << "========================================\n";
	}
	File.close();
};
void FilesHelper::getAdmins() {
	fstream File("Admins.txt", ios::in);
	vector<string> ss = Parser::split(File);
	for (int i = 0; i < ss.size(); ++i)
	{
		Admin a(Parser::parseToAdmin(ss[i]));
		cout << "Id = " << a.getId() << endl;
		cout << "Name = " << a.getName() << endl;
		cout << "Salary = " << a.getSalary() << endl;
		cout << "========================================\n";
	}
	File.close();
};
void FilesHelper::clearFile(string fileName) {
	fstream File(fileName + ".txt", fstream::out | fstream::trunc);
	File << "";
	File.close();
}
void FilesHelper::clearFile(string fileName, string lastIdFile) {
	FilesHelper::clearFile(fileName);
	FilesHelper::clearFile(lastIdFile);
};

