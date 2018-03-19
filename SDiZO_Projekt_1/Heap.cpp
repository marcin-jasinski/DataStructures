#include "stdafx.h"
#include "Heap.h"
#include <fstream>
#include <string>


Heap::Heap()
{
	heapElements = Array();
	heapSize = 0;
}

Heap::~Heap()
{
	heapElements.~Array();
	heapSize = 0;
}

// reading data from a text file "testData.txt"
// first line sets heap size (number of elements)
void Heap::readDataFromFile()
{
	std::fstream file;
	file.open("testData.txt", std::ios::in);
	if (file.good() == true)
	{
		std::cout << "\nFile acces granted." << std::endl;
		std::string input;
		getline(file, input);
		this->heapSize = std::stoi(input);
		this->heapElements = Array(heapSize);	// creating new integer array representing heap elements 

		for (int i = 0; i < this->heapSize, !file.eof(); i++) {
			input.clear();
			std::getline(file, input);
			this->heapElements.pushToBack(std::stoi(input));
		}

		file.close();
	}
	else std::cout << "Error opening file!!!" << std::endl;
}

// reading data from keyboard input
void Heap::readDataFromKeyboard()
{
	std::cout << "\nSet heap size: ";
	int userSize;
	std::cin >> userSize;
	this->heapSize = userSize;
	this->heapElements = Array(heapSize);	// creating new integer array representing heap elements 

	int userInput;
	for (int i = 0; i < userSize; i++) {
		std::cout << "Value at index [" << i << "] : ";
		std::cin >> userInput;
		this->heapElements.pushToBack(userInput);
	}
}

