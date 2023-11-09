#pragma once
#include "Person.h"
#include "Client.h"
class ClientManger
{
public:
	static void printClientMenu();
	static void updatePassword(Person* person);
	static Client* login(int id, string password);
	static bool clientOptions(Client* client,int choice);
};

