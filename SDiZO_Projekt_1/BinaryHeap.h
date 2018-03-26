#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "Array.h"

class BinaryHeap
{
private:

	std::string cr, cl, cp;

	// using alredy existing Array class with all it's functionality 
	Array* heapElements;			

	int get_left_child(int);
	int get_right_child(int);
	int parent(int);

	// private functions for fixing heapifying up and down after adding / deleting elements
	void heapFix_UP(int);
	void heapFix_DOWN(int);

public:

	BinaryHeap();
	~BinaryHeap();

	void readDataFromFile();
	void readDataFromKeyboard();

	int getRoot();
	int getSize();

	void addNewElement(int);
	void deleteRoot();
	void findValue(int);
	
	void display(std::string, std::string, int);

	friend std::ostream& operator << (std::ostream&, BinaryHeap&);
};

