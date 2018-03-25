#include "stdafx.h"
#include "LinkedList.h"

#include <fstream>
#include <iostream>
#include <string>

// creates an empty linked list with one element value 0
LinkedList::LinkedList()
{
	this->_headPtr = nullptr;
	this->_tailPtr = nullptr;
	this->listSize = 0;
}

// LinkedList destructor deletes each element by iterating from the head to tail
LinkedList::~LinkedList()
{
	this->listSize = 0;
	delete this->_tailPtr;
	delete this->_headPtr;
}

// returning current list size (number of elements)
int LinkedList::getSize() const
{
	return this->listSize;
}

// fuction returns a Node element from specified index
// nullptr if specified index was out of bounds
Node* LinkedList::getNodeFromIndex(int index)
{
	// IndexOutOfBound
	if (index < 0 || index >= listSize) {
		std::cout << "No such index in the list." << std::endl;
		return nullptr;
	}

	Node* searchedNode = _headPtr;	// start searching from the head
	for (int i = 0; i != index; i++) searchedNode = searchedNode->_rightPtr; // move to the right until you've reached desired element

	return searchedNode;
}

// reading data from "testData.txt" file
// first line indicates list size
void LinkedList::readDataFromFile()
{
	std::fstream file;
	file.open("testData.txt", std::ios::in);
	if (file.good() == true)
	{
		std::cout << "\nFile acces granted." << std::endl;
		std::string input;
		getline(file, input);
		int listSize = std::stoi(input); 

		// getting elements and pushing them to the list
		for (int i = 0; i < listSize && !file.eof(); i++) {
			input.clear();
			std::getline(file, input);
			pushBack(std::stoi(input));
		}

		file.close();
	}
	else std::cout << "Error opening file!!!" << std::endl;
}

// reading data from keyboard input
// first entry sets list size
void LinkedList::readDataFromKeyboard() {

	std::cout << "\nSet list size: ";
	int userSize;
	std::cin >> userSize;
	
	int userInput;
	// getting elements and pushing them to the list
	for (int i = 0; i < userSize; i++) {
		std::cout << "Value at index [" << i << "] : ";
		std::cin >> userInput;
		pushBack(userInput);
	}
}

// function pushes element to the beginning of linked list
// each element being previously a head of the list now has assigned a left neighbour, thus is no longer a head
void LinkedList::pushFront(int element)
{
	// if the list is empty - create a new node
	if (listSize == 0) {
		_headPtr = new Node(nullptr, nullptr, element);
		_tailPtr = new Node(_headPtr, nullptr, 0);
		_headPtr->_rightPtr = _tailPtr;
		listSize++;
	}
	else {
		_headPtr->_leftPtr = new Node(nullptr, _headPtr, element); // create a new node with no left neighbour and right neighbour pointing to current head node
		_headPtr = _headPtr->_leftPtr; // assing list head pointer to newly created one
		listSize++;
	}
}

void LinkedList::pushBack(int element)
{
	// should the list be empty, insert element on the beginning of the list
	if (listSize == 0) pushFront(element);
	else {
		// set current tail element value and create an empty Node element which will be next tail
		// make current tails right pointer point to newly created tail element
		this->_tailPtr->value = element;
		this->_tailPtr->_rightPtr = new Node(this->_tailPtr, nullptr, 0);
		this->_tailPtr = this->_tailPtr->_rightPtr;
		listSize++;
	}
}

// function deletes an element from the beginning of the list
void LinkedList::popFront()
{
	if (listSize == 0) {
		std::cout << "List is empty." << std::endl;
		return; // no point of deleting a non-existent element
	}

	if (listSize == 1) {	   // if there is only one element - just nullify pointers and value
		_headPtr = nullptr;
		_tailPtr = nullptr;
		listSize = 0;
	}
	else {									
		_headPtr = _headPtr->_rightPtr; // move current head pointer to the next element (witch will be the new head)
		delete _headPtr->_leftPtr;		
		_headPtr->_leftPtr = nullptr;	// nullify current left pointer
		listSize--;
	}
}

// function deletes an element from the end of the list
void LinkedList::popBack()
{
	if (listSize == 1 || listSize == 0) popFront(); // if there is only one or zero elements (refer to popFromFront for handling listSize == 0 case)
	else {
		_tailPtr = _tailPtr->_leftPtr;	// move tail's left pointer to the previous element
		delete _tailPtr->_rightPtr;
		_tailPtr->_rightPtr = nullptr;	// nullify current right pointer
		listSize--;
	}
}

// inserting a specified value to the selected index and shifting other nodes to the left or right
void LinkedList::insertValueOnIndex(int index, int element)
{
	if (index == 0) {								// inserting on the beginning of the list
		pushFront(element); 
		return; 
	}						
	if (index == this->listSize - 1) {				// inserting on the end of the list 
		pushBack(element); 
		return; 
	}		

	Node* tempNode = getNodeFromIndex(index);
	if (tempNode == nullptr) {						// handling an invalid index 
		std::cout << "Index not found." << std::endl; 
		return;
	}

	Node* newNode = new Node(tempNode->_leftPtr, tempNode, element);   // "squeezing" new node between existing nodes
	(newNode->_leftPtr)->_rightPtr = newNode;						   // make previous element point the the new node
	tempNode->_leftPtr = newNode;									   // make next element point to the new node

	listSize++;
}

// replacing a value on an existing node
void LinkedList::replaceValueOnIndex(int index, int element)
{
	Node* toReplace = getNodeFromIndex(index);
	if (toReplace == nullptr) {											// handling an invalid index 
		std::cout << "Index not found." << std::endl;
		return;
	}

	toReplace->value = element;
}

// removing a whole selected node
void LinkedList::removeNode(int index)
{
	// removing from the beginning or the end of the list
	if (index == 0) { popFront(); return; }
	if (index == this->listSize - 1) { popBack(); return; }

	Node* toRemove = getNodeFromIndex(index);
	if (toRemove == nullptr) {											// handling an invalid index 
		std::cout << "Index not found." << std::endl;
		return;
	}

	(toRemove->_leftPtr)->_rightPtr = (toRemove->_rightPtr);		// make current node's left neighbour point to current right neighbour
	(toRemove->_rightPtr)->_leftPtr = (toRemove->_leftPtr);			// make currend node's right neighbour point to current left neighbour
	delete toRemove;												// delete node after reassigning pointers
	listSize--;
}

// returning a value (data) from desired node
int LinkedList::getValueFromIndex(int index)
{
	Node* node = getNodeFromIndex(index);
	if (node == nullptr) std::cout << "Index does not exist." << std::endl;
	else return node->value;
}

// iterating through the whole list and returning iterator's value after first apperance of specified value
// function iterates from both ends of the list towards it's middle node (for better performance)
void LinkedList::findValue(int element)
{
	Node* startingNode = _headPtr;				// assing starting node to the head of the list
	Node* endingNode = _tailPtr->_leftPtr;		// and ending node to it's last non-nullptr

	for (int i = 0; i <= listSize / 2; i++) {

		if ((startingNode->value == element) || (endingNode->value == element)) {
			std::cout << "Element found on position: " << i << std::endl;
			return;
		}

		startingNode = startingNode->_rightPtr;		// move starting node to the next on the right node
		endingNode = endingNode->_leftPtr;			// move ending node to the next on the left node
	}

	std::cout << "Element was not found on the list" << std::endl;
	return;
}

// overloaded << operator for easier list displaying
std::ostream & operator<<(std::ostream& out, LinkedList& list)
{
	if (list.listSize == 0) {
		out << "[empty]" << std::endl;
		return out;
	}

	out << "[";
	for (int i = 0; i < list.getSize(); i++) {
		out << list.getValueFromIndex(i);
		if (i == list.getSize() - 1) out << "]\n";
		else out << ",";
	}
	return out;
}
