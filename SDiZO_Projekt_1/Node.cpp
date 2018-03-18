#include "stdafx.h"
#include "Node.h"

// creates an empty node
Node::Node()
{
	this->_leftPtr = nullptr;
	this->_rightPtr = nullptr;
	this->value = 0;
}

// creates a Node element with specified value, left and right neighbour
Node::Node(Node* _leftPtrArg, Node* _rightPtrArg, int valueArg)
{
	this->_leftPtr = _leftPtrArg;
	this->_rightPtr = _rightPtrArg;
	this->value = valueArg;
}

// destructor sets current node neighbours to point at each other (so as if to "bypass" current node)
Node::~Node()
{
	if (_leftPtr != nullptr) _leftPtr->_rightPtr = this->_rightPtr;
	if (_rightPtr != nullptr) _rightPtr->_leftPtr = this->_leftPtr;
}
