#include "stdafx.h"
#include "ArrayMenu.h"


ArrayMenu::ArrayMenu()
{
	this->array = Array();
}

ArrayMenu::~ArrayMenu()
{
}

void ArrayMenu::showArrayMenu()
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
		array.readDataFromFile();
		std::cout << "\nArray read from file: " << std::endl;
		std::cout << array << std::endl;
		showOperationsMenu();
		break;

	case 2:
		array.readDataFromKeyboard();
		std::cout << "\nArray read from keyboard: " << std::endl;
		std::cout << array << std::endl;
		showOperationsMenu();
		break;

	default:
		break;
	}
}

void ArrayMenu::showOperationsMenu()
{
	std::cout << "\nAvailable operations: " << std::endl;
	std::cout << "1 - add element to the beginning of the array" << std::endl;
	std::cout << "2 - add element to the end of the array" << std::endl;
	std::cout << "3 - add element on a specified index" << std::endl;
	std::cout << "4 - remove element from the beginning of the array" << std::endl;
	std::cout << "5 - remove element from the end of the array" << std::endl;
	std::cout << "6 - remove element from a specified index" << std::endl;
	std::cout << "7 - find value in the array" << std::endl;
	std::cout << "8 - exit." << std::endl;
	std::cout << "\\> ";
	int userChoice;
	std::cin >> userChoice;

	int userInput;
	int userIndex;

	while (userChoice != 8) {
		switch (userChoice) {
		case 1:
			std::cout << "\nValue to add: ";
			std::cin >> userInput;
			array.pushToFront(userInput);
			std::cout << array << std::endl;
			break;

		case 2:
			std::cout << "\nValue to add: ";
			std::cin >> userInput;
			array.pushToBack(userInput);
			std::cout << array << std::endl;
			break;

		case 3:
			std::cout << "\nIndex: ";
			std::cin >> userIndex;
			std::cout << "Value to add: ";
			std::cin >> userInput;
			array.insertValueOnIndex(userIndex, userInput);
			std::cout << array << std::endl;
			break;

		case 4:
			array.popFromFront();
			std::cout << array << std::endl;
			break;

		case 5:
			array.popFromBack();
			std::cout << array << std::endl;
			break;

		case 6:
			std::cout << "\nIndex: ";
			std::cin >> userIndex;
			array.deleteValueFromIndex(userIndex);
			std::cout << array << std::endl;
			break;

		case 7:
			int userValueToFind;
			std::cout << "\nValue to find: ";
			std::cin >> userValueToFind;
			array.findValue(userValueToFind);
			break;
		case 8:
			std::cout << "Press ENTER to exit.";
			break;

		default:
			break;
		}

		std::cout << "\\>";
		std::cin >> userChoice;
	}
}
