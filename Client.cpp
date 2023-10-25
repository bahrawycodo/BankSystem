#include "Person.h"
#include "Client.h"
#include <exception>
#include "validation.h"
Client::Client() {
	this->balance = 1500;
}
Client::Client(int id, string name, string password, double balance) : Person(id, name, password) {
	this->balance = 1500;
	this->setBalance(balance);
}
//Setters
void Client::setBalance(double balance) {
	try {
		this->balance = Validation::Balance(balance);
	}
	catch (exception& e) {
		cout << e.what();
	}
}
//getters
double Client::getBalance() {
	return this->balance;
}
//Methods
void Client::deposit(double amount) {
	this->setBalance(this->getBalance() + amount);
}
void Client::withdraw(double amount) {
	this->setBalance(this->getBalance() - amount);
}
void Client::transferTo(double amount, Client& recipient) {
	try {
		this->balance=Validation::Balance(this->getBalance()- amount);
		recipient.setBalance(recipient.getBalance() + amount);
	}
	catch (exception& e) {
		cout << e.what();
	}
}
void Client::checkBalance() {
	cout << this->balance;
}
void Client::Display() {
	Person::Display();
	cout << this->balance << endl;
}
