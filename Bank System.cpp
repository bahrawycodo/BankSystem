#include <iostream>
#include "Shared.h"
#include "AdminManager.h"
#include "Screens.h"
int main()
{
	Shared::FirstLoad();
	Screens::runApp();
	atexit(Shared::OnEnd );
}
