#pragma once

#include "Array.h"
#include "LinkedList.h"
#include "BinaryHeap.h"
#include <Windows.h>

class Efficiency_TESTS
{
private:
	Array array;
	LinkedList linkedList;
	BinaryHeap binaryHeap;

	LARGE_INTEGER li;
	double PCFreq = double(li.QuadPart) / 1000000.0;
	__int64 CounterStart = 0;

public:
	Efficiency_TESTS();
	~Efficiency_TESTS();

	void StartCounter();
	double GetCounter();

	void generateTestData(int);
	void run(int);
};

