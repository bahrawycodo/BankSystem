#include "ClientManger.h"
#include "FileManager.h"
void ClientManger::printClientMenu() {
	cout << "(1) Display my info\n";
	cout << "(2) Check balance\n";
	cout << "(3) Update Password\n";
	cout << "(4) Withdrow\n";
	cout << "(5) Deposit\n";
	cout << "(6) Transfer amount\n";
	cout << "(7) Logout\n";
}
void ClientManger::updatePassword(Client* client) {
	client->updatePassword(client->getId(), client->getPassword());
}
Client* ClientManger::login(int id, string password){
	return FileManager::clientLogin(id, password);
}
bool ClientManger::clientOptions(Client* client){
	if (client->getId()) {

	}
}