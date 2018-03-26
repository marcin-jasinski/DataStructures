#include "stdafx.h"
#include "BinaryHeap.h"

#include <fstream>
#include <iostream>
#include <string>

// default heap constructor is empty
// no need to pre-initialize elements array
BinaryHeap::BinaryHeap() 
{
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
}

// default destructor
BinaryHeap::~BinaryHeap()
{
}

// reading data from a text file "testData.txt"
// first line sets array size (number of elements) 
void BinaryHeap::readDataFromFile()
{
	std::fstream file;
	file.open("testData.txt", std::ios::in);
	if (file.good() == true)
	{
		std::cout << "\nFile acces granted." << std::endl;
		std::string input;
		getline(file, input);
		int initialHeapSize = std::stoi(input);
	    this->heapElements = new Array();		// creating new integer array

		for (int i = 0; i < initialHeapSize && !file.eof(); i++) {
			input.clear();
			std::getline(file, input);
			this->addNewElement(std::stoi(input));
		}

		file.close();
	}
	else std::cout << "Error opening file!!!" << std::endl;
}

// reading data from keyboard input
void BinaryHeap::readDataFromKeyboard()
{
	std::cout << "\nSet initial heap size: ";
	int userSize;
	std::cin >> userSize;

	int initialHeapSize = userSize;
	this->heapElements = new Array();		// creating new integer array
	
	int userInput;
	for (int i = 0; i < userSize; i++) {
		std::cout << "Value at index [" << i << "] : ";
		std::cin >> userInput;
		this->addNewElement(userInput);
	}
}

// returns current size (number of heap elements)
int BinaryHeap::getSize()
{
	return heapElements->getSize();
}

// adding new element to the heap using already existing pushBack function from the Array class
// fixing heap up after adding new element
void BinaryHeap::addNewElement(int element)
{
	heapElements->pushBack(element);
	heapFix_UP(heapElements->getSize() - 1);
}

// deleting root element from the heap
void BinaryHeap::deleteRoot()
{
	if (heapElements->getSize() == 0)
	{
		std::cout << "Heap is empty" << std::endl;
		return;
	}

	heapElements->replaceValueOnIndex(0, heapElements->get(heapElements->getSize() - 1));		// copying last added element to the root node (on the top of the heap)
	heapElements->popBack();																	// deleting last added element 
	heapFix_DOWN(0);																			// fixing heap downwards
	std::cout << "Element Deleted" << std::endl;
}

// finding a value in the heap
// uses already implemented function from Array class
void BinaryHeap::findValue(int element)
{
	this->heapElements->findValue(element);
	return;
}

void BinaryHeap::display(std::string sp, std::string sn, int v)
{
	std::string s;

	if (v < this->heapElements->getSize())
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		display(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		std::cout << s << sn << this->heapElements->get(v) << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		display(s + cp, cl, 2 * v + 1);
	}
}

// returns current maximum element (root)
int BinaryHeap::getRoot()
{
	if (heapElements->getSize() == 0)
	{
		std::cout << "Heap is empty" << std::endl;
		return -1;
	}

	else return heapElements->get(0);
}

// returns left child index of the selected element
int BinaryHeap::get_left_child(int parentIndex)
{
	int l_childIndex = 2 * parentIndex + 1;									// calculating left child index
	if (l_childIndex < heapElements->getSize()) return l_childIndex;		// if it's index fits in the current array (heap) size
	else return -1;															// -1 indicates that parent element has no left child
}

// returns right child index of the selected element
int BinaryHeap::get_right_child(int parentIndex)
{
	int r_childIndex = 2 * parentIndex + 2;									// calculating left child index
	if (r_childIndex < heapElements->getSize()) return r_childIndex;		// if it's index fits in the current array (heap) size
	else return -1;															// -1 indicates that parent element has no right child
}	

// returns parent index for the selected child
int BinaryHeap::parent(int childIndex)
{
	int parentIndex = (childIndex - 1) / 2;									// calculating parent index
	if (childIndex == 0) return -1;											// if the selected element is root, return -1 (has no parent)
	else return parentIndex;
}

// fixing the heap upwards
// function compares current child element with its parent and if the parent element is smaller than it's child - swaps them
void BinaryHeap::heapFix_UP(int startIndex)
{
	if (startIndex >= 0 && parent(startIndex) >= 0 && heapElements->get(parent(startIndex)) < heapElements->get(startIndex))
	{
		int tempHold = heapElements->get(startIndex); // temporary holding parent element
		heapElements->replaceValueOnIndex(startIndex, heapElements->get(parent(startIndex)));
		heapElements->replaceValueOnIndex(parent(startIndex), tempHold);
		heapFix_UP(parent(startIndex));
	}
}

// fixing the heap downwards
// function compares current parent element with it's children
// if one of the children is bigger than it's parent - function swaps them
// if both children are bigger than their parent - function swaps parent element with bigger of it's children
void BinaryHeap::heapFix_DOWN(int startIndex)
{
	int first_child = get_left_child(startIndex);
	int second_child = get_right_child(startIndex);

	// if both children indexes are in the array and left child is smaller than right child - swap (but only in function, not in the heap itself)
	if (first_child >= 0 && second_child >= 0 && heapElements->get(first_child) < heapElements->get(second_child))
	{
		first_child = second_child;
	}

	// if parent element is smaller than it's current child - swap
	if (first_child > 0 && heapElements->get(startIndex) < heapElements->get(first_child))
	{
		int temp = heapElements->get(startIndex);	// temporary holding parent element
		heapElements->replaceValueOnIndex(startIndex, heapElements->get(first_child));
		heapElements->replaceValueOnIndex(first_child, temp);
		heapFix_DOWN(first_child);
	}
}

// overloaded operator for writing array contents to the output stream
std::ostream & operator<<(std::ostream & out, BinaryHeap & heap)
{
	if (heap.heapElements->getSize() == 0) {
		out << "[empty]" << std::endl;
		return out;
	}

	out << "[";
	for (int i = 0; i < heap.heapElements->getSize(); i++) {
		out << heap.heapElements->get(i);
		if (i == heap.heapElements->getSize() - 1) out << "]\n";
		else out << ",";
	}

	return out;
}
