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
vector<string> FilesHelper::split(string fileName) {
	fstream File(fileName + ".txt", ios::in);
	vector<string> ss = Parser::split(File);
	File.close();
	return ss;
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
//void FilesHelper::saveAdmin(Admin* admin) {
//	fstream File("Admins.txt", fstream::app);
//	File << 1 << "&" << "&" << admin->getName() << "&" << admin->getPassword() << "&" << admin->getSalary() << endl;
//	File.close();
//}
void FilesHelper::getClients() {
	Client c;
	vector<string> ss = FilesHelper::split("Clients");
	for (int i = 0; i < ss.size(); ++i)
	{
		c = Parser::parseToClient(ss[i]);
		c.DisplayMainInfo();
		cout << "========================================\n";
	}
};
void FilesHelper::getEmployees() {
	vector<string> ss = FilesHelper::split("Employees");
	Employee e;
	for (int i = 0; i < ss.size(); ++i)
	{
		e= Parser::parseToEmployee(ss[i]);
		e.DisplayMainInfo();
		cout << "========================================\n";
	}
};
void FilesHelper::getAdmins() {
	vector<string> ss = FilesHelper::split("Admins");
	Employee e = Parser::parseToEmployee(ss[0]);
	Admin* a = Admin::getAdmin();

	a->setId(e.getId());
	a->setData(e.getName(), e.getPassword(), e.getSalary());
	a->DisplayMainInfo();
	cout << "========================================\n";
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

