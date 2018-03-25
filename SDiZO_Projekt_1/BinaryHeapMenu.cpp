#include "stdafx.h"
#include "BinaryHeapMenu.h"
#include "BinaryHeap.h"

BinaryHeapMenu::BinaryHeapMenu()
{
	this->heap = BinaryHeap();
}

BinaryHeapMenu::~BinaryHeapMenu()
{
}

void BinaryHeapMenu::showBinaryHeapMenu()
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
		heap.readDataFromFile();
		std::cout << "\nHeap read from file: " << std::endl;
		std::cout << heap << std::endl;
		showOperationsMenu();
		break;

	case 2:
		heap.readDataFromKeyboard();
		std::cout << "\nHeap read from keyboard: " << std::endl;
		std::cout << heap << std::endl;
		showOperationsMenu();
		break;

	default:
		std::cout << "Invalid command" << std::endl;
		break;
	}
}

void BinaryHeapMenu::showOperationsMenu()
{
	std::cout << "\nAvailable operations: " << std::endl;
	std::cout << "1 - add new element to the heap" << std::endl;
	std::cout << "2 - remove root element" << std::endl;
	std::cout << "3 - get root element" << std::endl;
	std::cout << "4 - exit" << std::endl;
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
			heap.addNewElement(userInput);
			std::cout << heap << std::endl;
			break;

		case 2:
			heap.deleteRoot();
			std::cout << heap << std::endl;
			break;

		case 3:
			std::cout << "Root: " << heap.getRoot() << std::endl;
			break;

		case 4:
			std::cout << "\nValue to find: ";
			std::cin >> userInput;
			heap.findValue(userInput);
			break;

		case 5:
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
