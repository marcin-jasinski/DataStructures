#pragma once
#include "Node.h"
#include <string>

class LinkedList
{
private:
	Node* _headPtr; 
	Node* _tailPtr; 
	int listSize;

public:
	LinkedList();
	~LinkedList();

	int getSize() const;
	Node* getNodeFromIndex(int);

	void readDataFromFile();
	void readDataFromKeyboard();

	void pushFront(int);
	void pushBack(int);
	void popFront();
	void popBack();

	int getValueFromIndex(int);
	void insertValueOnIndex(int, int);
	void replaceValueOnIndex(int, int);
	void findValue(int);

	void removeNode(int);
	
	friend std::ostream & operator<<(std::ostream&, LinkedList&);
};

