#include "Person.h"
#include "Client.h"
#include <exception>
#include "validation.h"
#include <vector>
#include "FileManager.h"
Client::Client() {
	this->balance = 1500;
}
Client::Client(int id,string name, string password, double balance) : Person(id,name, password) {
	this->balance = 1500;
	this->setBalance(balance);
}
//Setters
void Client::setData(string name, string password, double balance) {
	Person::setData(name, password);
	this->balance = balance;
}
void Client::setBalance(double balance) {
	this->balance = balance;
}
//Operator = Overloading
void Client::operator = (Client c) {
	this->setData(c.getName(),c.getPassword(),c.getBalance() );
}

//getters
double Client::getBalance() {
	return this->balance;
}
//Methods
void Client::deposit(double amount) {
	this->balance=this->getBalance() + amount;
}
bool Client::withdraw(double amount) {
	if (Validation::NotorequalZero(this->getBalance() - amount)) {
		this->balance =this->getBalance() - amount;
		return true;
	}
	return false;
}
bool Client::transferTo(double amount, Client* recipient) {
	if(Validation::NotorequalZero(this->getBalance() - amount)){
		this->balance=this->getBalance()- amount;
		recipient->deposit(amount);
		return true;
	}
	return false;
}
void Client::checkBalance() {
	cout << this->balance << endl;
}
void Client::DisplayMainInfo() {
	Person::DisplayMainInfo();
	cout << this->balance << endl;
}
void Client::Display() {
	Person::Display();
	cout << this->balance << endl;
}