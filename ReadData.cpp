#include "ReadData.h"
#include "Validation.h"


Employee* ReadData::ReadEmployeeId(Admin* admin, int& id) {
chooseId:
	cout << "Write Employee Id you want\n";
	cin >> id;
	Employee* employee = admin->searchEmployee(id);
	if (employee == nullptr) {
		cout << "Please choose a valid Id \n";
		goto chooseId;
	}
return employee;
};
Client* ReadData::ReadClientId(Employee* employee,int& id) {
chooseId:
	cout << "Write Client Id you want\n";
	cin >> id;
	Client* c = employee->searchClient(id);
	if (c == nullptr) {
		cout << "Please choose a valid Id \n";
		goto chooseId;
	}
	return c;
};
void ReadData::ReadName(string &name) {
chooseName:
	cout << "Write Name (between 5 to 20 chars)\n";
	cin.ignore();
	getline(cin,name);

	if (!Validation::Name(name)) {
		Validation::NameException();
		goto chooseName;
	}
};
void ReadData::ReadPassword(string &password) {
choosePassword:
	cout << "Write Client Password (between 8 to 20)\n";
	getline(cin, password);
	if (!Validation::Password(password)) {
		Validation::PasswordException();
		goto choosePassword;
	}
};
void ReadData::ReadPassword(string& password, bool fromOne) {
	if(fromOne)
		cin.ignore();
	ReadData::ReadPassword(password);
};
void ReadData::ReadBalance(double &balance) {
chooseBalance:
	cout << "Write Client Balance (Min Balance = 1500)\n";
	cin >> balance;
	if (!Validation::Balance(balance))
	{
		Validation::BalanceException();
		goto chooseBalance;
	}
};
void ReadData::ReadSalary(double& salary){

}
