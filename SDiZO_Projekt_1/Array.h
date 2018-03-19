#pragma once
#include <iostream>

class Array
{
private:
	int* _headPtr;	// pointer to dynamic array of integers
	int arraySize;  // current number of elements in the array

public:
	Array();
	Array(int);
	~Array();

	int getSize() const;
	int* getHeadPtr();

	void readDataFromFile();
	void readDataFromKeyboard();

	void pushToFront(int);
	void pushToBack(int);
	void popFromFront();
	void popFromBack();
	void insertValueOnIndex(int, int);
	void deleteValueFromIndex(int);
	void replaceValueOnIndex(int, int);
	void findValue(int);

	int operator[](int) const;
	friend std::ostream& operator << (std::ostream&, Array&);
};

