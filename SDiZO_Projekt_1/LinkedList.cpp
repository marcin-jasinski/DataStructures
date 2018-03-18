#include "stdafx.h"
#include "LinkedList.h"

#include <fstream>
#include <iostream>
#include <string>

// creates an empty linked list
LinkedList::LinkedList()
{
	this->_headPtr = nullptr;
	this->_tailPtr = nullptr;
	this->listSize = 0;
}

// LinkedList destructor deletes each element from the head to tail
LinkedList::~LinkedList()
{
	while (_headPtr != _tailPtr) {
		_headPtr = _headPtr->_rightPtr;
		delete _headPtr->_leftPtr;
	}

	delete this->_tailPtr;
}

int LinkedList::getSize() const
{
	return this->listSize;
}

// fuction returns a Node from specified index
Node * LinkedList::getNodeFromIndex(int index)
{
	// IndexOutOfBound
	if (index < 0 || index >= listSize) return nullptr;

	Node* searchedNode = _headPtr;
	for (int i = 0; i != index; i++) searchedNode = searchedNode->_rightPtr;

	return searchedNode;
}

// reading data from "testData.txt" file
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

		for (int i = 0; i < listSize, !file.eof(); i++) {
			input.clear();
			std::getline(file, input);
			pushToBack(std::stoi(input));
		}

		file.close();
	}
	else std::cout << "Error opening file!!!" << std::endl;
}

void LinkedList::pushToFront(int element)
{
	if (listSize == 0) {
		_headPtr = new Node(nullptr, nullptr, element);
		_tailPtr = new Node(_headPtr, nullptr, 0);
		_headPtr->_rightPtr = _tailPtr;
		listSize++;
	}
	else {
		_headPtr->_leftPtr = new Node(nullptr, _headPtr, element);
		_headPtr = _headPtr->_leftPtr;
		listSize++;
	}
}

void LinkedList::pushToBack(int element)
{
	// should the list be empty, insert element on the beginning of the list
	if (listSize == 0) pushToFront(element);
	else {
		// set current tail element value and create an empty Node element which will be next tail
		// make current tails right pointer point to newly created tail element
		this->_tailPtr->value = element;
		this->_tailPtr->_rightPtr = new Node(this->_tailPtr, nullptr, 0);
		this->_tailPtr = this->_tailPtr->_rightPtr;
		listSize++;
	}
}

void LinkedList::popFromFront()
{
	if (listSize == 0) return;
	if (listSize == 1) {
		_headPtr = nullptr;
		_tailPtr = nullptr;
		listSize = 0;
	}
	else {
		_headPtr = _headPtr->_rightPtr;
		delete _headPtr->_leftPtr;
		_headPtr->_leftPtr = nullptr;
		listSize--;
	}
}

void LinkedList::popFromBack()
{
	if (listSize == 1 || listSize == 0) popFromFront();
	else {
		_tailPtr = _tailPtr->_leftPtr;
		delete _tailPtr->_rightPtr;
		listSize--;
	}
}

void LinkedList::insertValueOnIndex(int index, int element)
{
	Node* _tempNode = getNodeFromIndex(index);
	if (_tempNode == nullptr) std::cout << "Index not found." << std::endl;

	Node* newNode = new Node(_tempNode->_leftPtr, _tempNode, element);
	(newNode->_leftPtr)->_rightPtr = newNode;
	_tempNode->_leftPtr = newNode;

	listSize++;
}

void LinkedList::replaceValueOnIndex(int index, int element)
{
	Node* toReplace = getNodeFromIndex(index);
	toReplace->value = element;
}

void LinkedList::removeNode(int index)
{
	Node* toRemove = getNodeFromIndex(index);
	delete toRemove;
	listSize--;
}

int LinkedList::getValueFromIndex(int index)
{
	Node* node = getNodeFromIndex(index);
	if (node == nullptr) std::cout << "Index does not exist." << std::endl;
	else return node->value;
}

void LinkedList::findValue(int element)
{
	Node* node_back = _tailPtr->_leftPtr;
	Node* node_front = _headPtr;
	for (int i = 0; i <= listSize / 2; i++) {

		if ((node_front->value == element) || (node_back->value == element)) std::cout << "Element found on position: " << i << std::endl;

		node_front = node_front->_rightPtr;
		node_back = node_back->_leftPtr;
	}
	return;
}

std::ostream & operator<<(std::ostream& out, LinkedList& list)
{
	out << "[";
	for (int i = 0; i < list.getSize(); i++) {
		out << list.getValueFromIndex(i);
		if (i == list.getSize() - 1) out << "]\n";
		else out << ",";
	}
	return out;
}
