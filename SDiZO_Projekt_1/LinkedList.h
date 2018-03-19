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

	void pushToFront(int);
	void pushToBack(int);
	void popFromFront();
	void popFromBack();
	void insertValueOnIndex(int, int);
	void replaceValueOnIndex(int, int);
	void removeNode(int);
	int getValueFromIndex(int);
	void findValue(int);
	
	friend std::ostream & operator<<(std::ostream&, LinkedList&);
};

