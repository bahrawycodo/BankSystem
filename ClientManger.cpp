#include "ClientManger.h"
#include "FileManager.h"
#include "Validation.h"
#include "Shared.h"
#include "ReadData.h"
void checkBalance(Client* client) {
	client->checkBalance();
}
void Withdrow(Client* client) {
	if (client->getBalance() == 0) {
		Validation::LessZeroBalanceExeption();
	}
	else {
			double amount;
		chooseAmount:
			ReadData::ReadAmount(amount);

				bool success = client->withdraw(amount);
				if (!success) {

					goto chooseAmount;
				}
				else {
					cout << "Withdraw Completed Successfully\n";
				}
	}
}
void Deposit(Client* client) {
	double amount;
	ReadData::ReadAmount(amount);
	client->deposit(amount);
	cout << "Deposit Successfully\n";

}
void transferAmount(Client* client) {
	if (client->getBalance() == 0) {
		Validation::LessZeroBalanceExeption();
	}
	else {
			int id;
			double amount;

			Client* c = {};
			ReadData::ReadClientId(c, id);
	
		chooseAmount:
			ReadData::ReadAmount(amount);
			bool success = client->transferTo(amount, c);
			if (!success) {
				Validation::LessZeroBalanceExeption();
				goto chooseAmount;
			}
			else {
				cout << "Transfered Successfully\n";
			}
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
	ReadData::ReadPassword(password, true);
	 person->setPassword(password);
	cout << "Password Updated Successfully\n";
}
Client* ClientManger::login(int id, string password){
	Client* c = Shared::getClient(id);
	if (c != nullptr && c->getPassword() == password)
		return c;
	return nullptr;

}
void ClientManger::clientOptions(Client* client,int choice){
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
		break;
	default:
		cout << "\n\nWRONG INPUT!\n\n";
		break;
	}
}
