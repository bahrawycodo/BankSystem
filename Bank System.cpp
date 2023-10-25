#include <iostream>
#include "Client.h";
int main()
{
	Client c(1, "mahmoud", "12345678",1500);
	Client c2(2, "mahmoud Elbahrawy", "12345678",2000);
	c2.transferTo(1000, c);
	c.Display();
	c2.Display();
}
