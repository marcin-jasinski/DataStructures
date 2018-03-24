#include "stdafx.h"
#include "Menu.h"
#include "ArrayMenu.h"
#include "LinkedListMenu.h"
#include "BinaryHeapMenu.h"

#include <iostream>
#include <cstdlib>

Menu::Menu()
{
	showMainMenu();
}

void Menu::showMainMenu()
{
	ArrayMenu arrayMenu = ArrayMenu();
	LinkedListMenu linkedListMenu = LinkedListMenu();
	BinaryHeapMenu binaryHeapMenu = BinaryHeapMenu();
	
	std::cout << "Start testing for:\n" << std::endl;
	std::cout << "1 - Array" << std::endl;
	std::cout << "2 - List" << std::endl;
	std::cout << "3 - Heap" << std::endl;
	std::cout << "_______________________\n" << std::endl;
	std::cout << "4 - Exit application\n" << std::endl;
	std::cout << "/> ";

	int userChoice;
	std::cin >> userChoice;

	switch (userChoice)
	{
	case 1:
		arrayMenu.showArrayMenu();
		break;
	case 2:
		linkedListMenu.showLinkedListMenu();
		break;
	case 3:
		binaryHeapMenu.showBinaryHeapMenu();
		break;
	case 4:
		std::cout << "Finishing...";
		break;
	default:
		break;
	}
}

