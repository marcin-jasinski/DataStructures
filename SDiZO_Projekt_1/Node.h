#pragma once
class Node
{
	friend class LinkedList;

private:
	Node* _leftPtr;
	Node* _rightPtr;
	int value;

public:
	Node();
	Node(Node* _leftPtrArg, Node* _rightPtrArg, int valueArg);
	~Node();
};


