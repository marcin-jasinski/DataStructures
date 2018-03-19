#pragma once
#include "Array.h"

class Heap
{
private:
	Array heapElements;		// array holding all heap elements. Element at heapElements[0] is the root (maximum element in this case)
	int heapSize;			// holding current size of the heap

public:
	Heap();
	~Heap();

	void readDataFromFile();
	void readDataFromKeyboard();

	void addNewElement(int);
	void deleteRoot();

	void heapify();
	void fixHeap_UP();
	void fixHeap_DOWN();

	void findValue();

	friend std::ostream& operator << (std::ostream&, Array&);
};

