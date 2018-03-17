#include "stdafx.h"
#include "Array.h"
#include <fstream>
#include <string>
#include <iostream>
#include <conio.h>

// default constructor of an array
Array::Array()
{
	this->arraySize = 0;
	this->_headPtr = nullptr;
}

// constructor creating an array of a specified size
// assigns new dynamicly allocated array of integers to _headPtr
Array::Array(int arraySize, int *)
{
	this->arraySize = arraySize;
	this->_headPtr = new int[arraySize];
}

// default destructor
Array::~Array()
{
	this->arraySize = 0;
	delete[] this->_headPtr;
}

int Array::getSize() const
{
	return this->arraySize;
}

// returns pointer to the first element in an array (or nullptr if array was created with default constructor)
int * Array::getHeadPtr()
{
	return this->_headPtr;
}

// overloadad [] operator for array-like element acces
int Array::operator[](int index) const
{
	return _headPtr[index];
}

// read data from a text file "testData.txt"
// first line sets array size (number of elements)
void Array::readDataFromFile()
{
	std::fstream file;
	file.open("testData.txt", std::ios::in);
	if (file.good() == true)
	{	
		std::cout << "\nFile acces granted." << std::endl;
		std::string input;
		getline(file, input);
		this->arraySize = std::stoi(input);
		this->_headPtr = new int[arraySize];

		for (int i = 0; i < this->arraySize, !file.eof(); i++) {
			input.clear();
			std::getline(file, input);
			this->_headPtr[i] = std::stoi(input);
		}

		file.close();
	}
	else std::cout << "Error opening file!!!" << std::endl;
}

// reading data from keyboard input
void Array::readDataFromKeyboard()
{
	std::cout << "\nSet array size: ";
	int userSize;
	std::cin >> userSize;
	this->arraySize = userSize;
	this->_headPtr = new int[arraySize];

	int userInput;
	for (int i = 0; i < userSize; i++) {
		std::cout << "Value at index [" << i << "] : ";
		std::cin >> userInput;
		this->_headPtr[i] = userInput;
	}
}

// overloaded operator for writing array contents to the output stream
std::ostream & operator<<(std::ostream& out, Array& array)
{
	out << "[";
	for (int i = 0; i < array.getSize(); i++) {
		out << array[i];
		if (i == array.getSize() - 1) out << "]\n";
		else out << ",";
	}
	return out;
}

// inserts en element on the beginning of the array
void Array::pushToFront(int element)
{
	//if the array is empty
	if (this->arraySize == 0) {
		this->_headPtr = new int[1];
		this->_headPtr[0] = element;
		this->arraySize++;
	}
	else {
		int* _tempPtr = new int[this->arraySize + 1];
		memcpy(_tempPtr + 1, this->_headPtr, arraySize * sizeof(int));
		_tempPtr[0] = element;
		this->_headPtr = _tempPtr;
		this->arraySize++;
	}
}

// inserts an element on the end of the array
void Array::pushToBack(int element)
{
	// if the array is empty
	if (this->arraySize == 0) {
		this->_headPtr = new int[1];
		*_headPtr = element;
		this->arraySize++;
	}
	else {
		int* _tempPtr = new int[arraySize + 1];
		memcpy(_tempPtr, _headPtr, arraySize * sizeof(int));
		*(_tempPtr + arraySize) = element;
		_headPtr = _tempPtr;
		this->arraySize++;
	}
}
 
// deletes first array element
void Array::popFromFront()
{
	deleteValueFromIndex(0);
}

// deletes last array element
void Array::popFromBack()
{
	deleteValueFromIndex(this->arraySize - 1);
}

// inserts a specified value on a selected index in the array and relocates array with a new size
// elements originally placed after selected index are shifted by one index number up
void Array::insertValueOnIndex(int index, int element)
{
	// there is no point of inserting a value to a non-existant array
	if (this->arraySize == 0) return;
	
	int* _tempPtr = new int[this->arraySize + 1]; // buffer array for temporary element hold
	memcpy(_tempPtr, this->_headPtr, index * sizeof(int)); // copying to buffer
	*(_tempPtr + index) = element;
	memcpy(_tempPtr + index + 1, this->_headPtr + index, (this->arraySize - index) * sizeof(int)); // shifting the rest of the elements one index up
	this->_headPtr = _tempPtr;
	this->arraySize;
}

// deletes element from the specified index and relocates array with a new size
// elements originally placed after selected index are shifted by one index number down
void Array::deleteValueFromIndex(int index)
{
	// there is no point of deleting a value from a non-existant array
	if (arraySize == 0) return;

	int* _tempPtr = new int[arraySize - 1];
	memcpy(_tempPtr, _headPtr, index * sizeof(int));
	arraySize--;
	memcpy(_tempPtr + index, _headPtr + index + 1, (arraySize - index) * sizeof(int));
	_headPtr = _tempPtr;
}

// returns true if array contains specified value
void Array::findValue(int element)
{
	for (int i = 0; i < this->arraySize; i++) {
		if (*(this->_headPtr + i) == element) {
			std::cout << "Element found on position " << i << std::endl;
			return;
		}
	}
	std::cout << "Element not found." << std::endl;
	return;
}

