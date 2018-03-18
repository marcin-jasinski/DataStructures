#include "stdafx.h"
#include "Menu.h"
#include "Array.h"
#include "ArrayMenu.h"

#include <iostream>
#include <cstdlib>


Menu::Menu()
{
	showMainMenu();
}

void Menu::showMainMenu()
{
	ArrayMenu arrayMenu = ArrayMenu();

	std::cout << "Start testing for:\n" << std::endl;
	std::cout << "1 - Array" << std::endl;
	std::cout << "2 - List" << std::endl;
	std::cout << "3 - Heap" << std::endl;
	std::cout << "4 - Red-Black Tree" << std::endl;
	std::cout << "_______________________\n" << std::endl;
	std::cout << "5 - Exit application\n" << std::endl;
	std::cout << "/> ";

	int userChoice;
	std::cin >> userChoice;

	switch (userChoice)
	{
	case 1:
		arrayMenu.showArrayMenu();
		break;
	case 2:
		//showListMenu();
		break;
	case 3:
		//showHeapMenu();
		break;
	case 4:
		//showRedBlackTreeMenu();
		break;
	case 5:
		std::cout << "Finishing...";
		break;
	default:
		break;
	}
}

