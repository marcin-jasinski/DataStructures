#include "stdafx.h"
#include "LinkedListMenu.h"
#include <iostream>


LinkedListMenu::LinkedListMenu()
{
	this->linkedList = LinkedList();
}

LinkedListMenu::~LinkedListMenu(){}

void LinkedListMenu::showLinkedListMenu()
{
	system("cls");
	std::cout << "Select data source: " << std::endl;
	std::cout << "1 - read data from \"testData.txt\" " << std::endl;
	std::cout << "2 - read data from keyboard input" << std::endl;
	std::cout << "\\> ";
	int userChoice;
	std::cin >> userChoice;

	switch (userChoice)
	{
	case 1:
		linkedList.readDataFromFile();
		std::cout << "\nArray read from file: " << std::endl;
		std::cout << linkedList << std::endl;
		showOperationsMenu();
		break;

	case 2:
		linkedList.readDataFromKeyboard();
		std::cout << "\nArray read from keyboard: " << std::endl;
		std::cout << linkedList << std::endl;
		showOperationsMenu();
		break;

	default:
		std::cout << "Invalid command" << std::endl;
		break;
	}
}

void LinkedListMenu::showOperationsMenu()
{
	std::cout << "\nAvailable operations: " << std::endl;
	std::cout << "1 - add element to the beginning of the list" << std::endl;
	std::cout << "2 - add element to the end of the list" << std::endl;
	std::cout << "3 - add element on a specified index" << std::endl;
	std::cout << "4 - remove element from the beginning of the list" << std::endl;
	std::cout << "5 - remove element from the end of the list" << std::endl;
	std::cout << "6 - remove node from a specified index" << std::endl;
	std::cout << "7 - find value in the list" << std::endl;
	std::cout << "8 - replace value on selected index" << std::endl;
	std::cout << "9 - exit." << std::endl;
	std::cout << "\\> ";
	int userChoice;
	std::cin >> userChoice;

	int userInput;
	int userIndex;

	while (userChoice != 9) {
		switch (userChoice) {
		case 1:
			std::cout << "\nValue to add: ";
			std::cin >> userInput;
			linkedList.pushFront(userInput);
			std::cout << linkedList << std::endl;
			break;

		case 2:
			std::cout << "\nValue to add: ";
			std::cin >> userInput;
			linkedList.pushBack(userInput);
			std::cout << linkedList << std::endl;
			break;

		case 3:
			std::cout << "\nIndex: ";
			std::cin >> userIndex;
			std::cout << "Value to add: ";
			std::cin >> userInput;
			linkedList.insertValueOnIndex(userIndex, userInput);
			std::cout << linkedList << std::endl;
			break;

		case 4:
			linkedList.popFront();
			std::cout << linkedList << std::endl;
			break;

		case 5:
			linkedList.popBack();
			std::cout << linkedList << std::endl;
			break;

		case 6:
			std::cout << "\nIndex: ";
			std::cin >> userIndex;
			linkedList.removeNode(userIndex);
			std::cout << linkedList << std::endl;
			break;

		case 7:
			int userValueToFind;
			std::cout << "\nValue to find: ";
			std::cin >> userValueToFind;
			linkedList.findValue(userValueToFind);
			break;

		case 8:
			std::cout << "\nIndex: ";
			std::cin >> userIndex;
			std::cout << "Value to add: ";
			std::cin >> userInput;
			linkedList.replaceValueOnIndex(userIndex, userInput);
			std::cout << linkedList << std::endl;
			break;
		case 9:
			std::cout << "Press ENTER to exit.";
			break;

		default:
			std::cout << "Invalid command" << std::endl;
			break;
		}

		std::cout << "\\>";
		std::cin >> userChoice;
	}
}
