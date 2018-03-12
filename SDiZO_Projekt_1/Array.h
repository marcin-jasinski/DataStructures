#pragma once
#include <iostream>

class Array
{
private:
	int* _headPtr;
	int arraySize;

public:
	Array();
	Array(int, int*);
	~Array();

	int getSize() const;
	int* getHeadPtr();

	int operator[](int) const;
	friend std::ostream& operator << (std::ostream&, Array&);

	void pushToFront(int);
	void pushToBack(int);
	void popFromFront();
	void popFromBack();
	void insertValueOnIndex(int, int);
	void deleteValueFromIndex(int);
	bool findValue(int);
};

