#pragma once
#include "BinaryHeap.h"

class BinaryHeapMenu
{
private:
	BinaryHeap heap;

public:
	BinaryHeapMenu();
	~BinaryHeapMenu();

	void showBinaryHeapMenu();
	void showOperationsMenu();
};

