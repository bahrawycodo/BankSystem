#include "ClientManger.h"
#include "FileManager.h"
#include "Validation.h"
#include "Shared.h"
void checkBalance(Client* client) {
	client->checkBalance();
}
void Withdrow(Client* client) {
	double amount;
chooseAmount:
	cout << "Write Amount you want\n";
	cin >> amount;

	bool success = client->withdraw(amount);
	if (!success) {
		Validation::LessZeroBalanceExeption();
		goto chooseAmount;
	}
	else {
		cout << "Withdraw Completed Successfully\n";
	}

}
void Deposit(Client* client) {
	double amount;
	cout << "Write Amount you want\n";
	cin >> amount;
	client->deposit(amount);
	cout << "Deposit Successfully\n";

}
void transferAmount(Client* client) {
	int id;
	double amount;
chooseId:
	cout << "Write Client Id that you want  to transfer to\n";
	cin >> id;
	Client* c = Shared::getClient(id);
	if (c == nullptr) {
		cout << "Please choose a valid Id \n";
		goto chooseId;
	}
chooseAmount:
	cout << "Write Amount you want\n";
	cin >> amount;

	bool success = client->transferTo(amount, c);
	if (!success) {
		Validation::LessZeroBalanceExeption();
		goto chooseAmount;
	}
	else {
		cout << "Transfered Successfully\n";
	}
}
void ClientManger::printClientMenu() {
	cout << "(1) Display my info\n";
	cout << "(2) Check balance\n";
	cout << "(3) Update Password\n";
	cout << "(4) Withdrow\n";
	cout << "(5) Deposit\n";
	cout << "(6) Transfer amount\n";
	cout << "(7) Logout\n";
}
void ClientManger::updatePassword(Person* person) {
	string password;
	cout << "Enter Password\n";
	cin >> password;
	bool flag = person->setPassword(password);
	if (!flag) {
		Validation::PasswordException();
	}
}
Client* ClientManger::login(int id, string password){
	Client* c = Shared::getClient(id);
	if (c != nullptr && c->getPassword() == password)
		return c;
	return nullptr;

}
bool ClientManger::clientOptions(Client* client,int choice){
	bool flag = true;
	switch (choice)
	{
	case 1:
		client->Display();
		break;
	case 2:
		checkBalance(client);
		break;
	case 3:
		ClientManger::updatePassword(client);
		break;
	case 4:
		Withdrow(client);
		break;
	case 5:
		Deposit(client);
		break;
	case 6:
		transferAmount(client);
		break;
	case 7:
		flag = false;
		break;
	default:
		cout << "\n\nWRONG INPUT!\n\n";
		break;
	}
	return flag;
}
