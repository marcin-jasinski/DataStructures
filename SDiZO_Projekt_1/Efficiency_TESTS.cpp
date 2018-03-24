#include "stdafx.h"
#include "Efficiency_TESTS.h"

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

Efficiency_TESTS::Efficiency_TESTS(){}

Efficiency_TESTS::~Efficiency_TESTS(){}

void Efficiency_TESTS::StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li)) std::cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}

double Efficiency_TESTS::GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}

void Efficiency_TESTS::generateTestData(int testRange)
{
	// generating testData.txt file as a data source for all tests
	std::fstream file;
	file.open("testData.txt", std::ios::out | std::ios::trunc);
	if (file.good() == true)
	{
		file << testRange << std::endl;
		int number, neg_rng;

		for (int i = 1; i <= testRange; i++) {
			number = (std::rand() % INT32_MAX);
			neg_rng = (std::rand() % INT32_MAX);
			if (neg_rng % 2 == 1) number = number * (-1);

			file << number << std::endl;
			file.flush();
		}

		file.close();
	}
}

void Efficiency_TESTS::run(int testRange)
{

	/* 
	
	std::fstream file;
	file.open("benchmark.txt", std::ios::out | std::ios::app);
	if (file.good())
	{
		std::cout << "Benchmark file opened, ready for input data." << std::endl;
		file << "\nTesting for " << testRange << " elements." << std::endl;
	}
	else
	{
		std::cout << "Error opening benchmark file, abort." << std::endl;
		return;
	}

	int number, neg_rng;
	double endTime;

	// +++++++ ARRAY TESTS +++++++++++

	system("cls");
	file << "\nArray - pushFront" << std::endl;
	for (int i = 1; i <= 100; i++) {
		
		generateTestData(testRange);
		array.readDataFromFile();

		number = (std::rand() % INT32_MAX);
		neg_rng = (std::rand() % INT32_MAX);
		if (neg_rng % 2 == 1) number = number * (-1);

		StartCounter();
		array.pushFront(number);
		endTime = GetCounter();
		std::cout << "Array pushFront " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		array.~Array();
	}

	system("cls");
	file << "\nArray - pushBack" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		array.readDataFromFile();

		number = (std::rand() % INT32_MAX);
		neg_rng = (std::rand() % INT32_MAX);
		if (neg_rng % 2 == 1) number = number * (-1);

		StartCounter();
		array.pushBack(number);
		endTime = GetCounter();
		std::cout << "Array pushBack " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		array.~Array();
	}

	system("cls");
	file << "\nArray - insertValueOnIntex" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		array.readDataFromFile();

		number = (std::rand() % INT32_MAX);
		neg_rng = (std::rand() % INT32_MAX);
		if (neg_rng % 2 == 1) number = number * (-1);

		int position = (std::rand() % testRange-10) + 10;

		StartCounter();
		array.insertValueOnIndex(position, number);
		endTime = GetCounter();
		std::cout << "Array insertValueOnIntex " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		array.~Array();
	}

	system("cls");
	file << "\nArray - replaceValueOnIntex" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		array.readDataFromFile();

		number = (std::rand() % INT32_MAX);
		neg_rng = (std::rand() % INT32_MAX);
		if (neg_rng % 2 == 1) number = number * (-1);

		int position = (std::rand() % testRange - 10) + 10;

		StartCounter();
		array.replaceValueOnIndex(position, number);
		endTime = GetCounter();
		std::cout << "Array replaceValueOnIntex " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		array.~Array();
	}

	system("cls");
	file << "\nArray - popFront" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		array.readDataFromFile();

		StartCounter();
		array.popFront();
		endTime = GetCounter();
		std::cout << "Array popFront " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		array.~Array();
	}

	system("cls");
	file << "\nArray - popBack" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		array.readDataFromFile();

		StartCounter();
		array.popBack();
		endTime = GetCounter();
		std::cout << "Array popBack " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		array.~Array();
	}

	system("cls");
	file << "\nArray - deleteValueFromIndex" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		array.readDataFromFile();

		int position = (std::rand() % testRange - 10) + 10;

		StartCounter();
		array.deleteValueFromIndex(position);
		endTime = GetCounter();
		std::cout << "Array deleteValueFromIndex " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		array.~Array();
	}

	system("cls");
	file << "\nArray - findValue" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		array.readDataFromFile();

		number = (std::rand() % INT32_MAX);
		neg_rng = (std::rand() % INT32_MAX);
		if (neg_rng % 2 == 1) number = number * (-1);

		StartCounter();
		array.findValue(number);
		endTime = GetCounter();
		std::cout << "Array findValue " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		array.~Array();
	}

	// +++++++ LINKED LIST TESTS ++++++++++++

	system("cls");
	file << "\nLinkedList - pushFront" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		linkedList.readDataFromFile();

		number = (std::rand() % INT32_MAX);
		neg_rng = (std::rand() % INT32_MAX);
		if (neg_rng % 2 == 1) number = number * (-1);

		StartCounter();
		linkedList.pushFront(number);
		endTime = GetCounter();
		std::cout << "LinkedList pushFront " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		linkedList.~LinkedList();
	}

	system("cls");
	file << "\nLinkedList - pushBack" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		linkedList.readDataFromFile();

		number = (std::rand() % INT32_MAX);
		neg_rng = (std::rand() % INT32_MAX);
		if (neg_rng % 2 == 1) number = number * (-1);

		StartCounter();
		linkedList.pushBack(number);
		endTime = GetCounter();
		std::cout << "LinkedList pushBack " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		linkedList.~LinkedList();
	}

	system("cls");
	file << "\nLinkedList - insertValueOnIntex" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		linkedList.readDataFromFile();

		number = (std::rand() % INT32_MAX);
		neg_rng = (std::rand() % INT32_MAX);
		if (neg_rng % 2 == 1) number = number * (-1);

		int position = (std::rand() % testRange - 10) + 10;

		StartCounter();
		linkedList.insertValueOnIndex(position, number);
		endTime = GetCounter();
		std::cout << "LinkedList insertValueOnIntex " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		linkedList.~LinkedList();
	}

	system("cls");
	file << "\nLinkedList - replaceValueOnIntex" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		linkedList.readDataFromFile();

		number = (std::rand() % INT32_MAX);
		neg_rng = (std::rand() % INT32_MAX);
		if (neg_rng % 2 == 1) number = number * (-1);

		int position = (std::rand() % testRange - 10) + 10;

		StartCounter();
		linkedList.replaceValueOnIndex(position, number);
		endTime = GetCounter();
		std::cout << "LinkedList replaceValueOnIntex " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		linkedList.~LinkedList();
	}

	system("cls");
	file << "\nLinkedList - popFront" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		linkedList.readDataFromFile();

		StartCounter();
		linkedList.popFront();
		endTime = GetCounter();
		std::cout << "LinkedList popFront " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		linkedList.~LinkedList();
	}

	system("cls");
	file << "\nLinkedList - popBack" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		linkedList.readDataFromFile();

		StartCounter();
		linkedList.popBack();
		endTime = GetCounter();
		std::cout << "LinkedList popBack " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		linkedList.~LinkedList();
	}

	system("cls");
	file << "\nLinkedList - removeNode" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		linkedList.readDataFromFile();

		int position = (std::rand() % testRange - 10) + 10;

		StartCounter();
		linkedList.removeNode(position);
		endTime = GetCounter();
		std::cout << "LinkedList removeNode " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		linkedList.~LinkedList();
	}

	system("cls");
	file << "\nLinkedList - findValue" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		linkedList.readDataFromFile();

		number = (std::rand() % INT32_MAX);
		neg_rng = (std::rand() % INT32_MAX);
		if (neg_rng % 2 == 1) number = number * (-1);

		StartCounter();
		linkedList.findValue(number);
		endTime = GetCounter();
		std::cout << "LinkedList findValue " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		linkedList.~LinkedList();
	}


	// +++++++ HEAP TESTS +++++++++++++

	system("cls");
	file << "\nHeap - add new element" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		binaryHeap.readDataFromFile();

		number = (std::rand() % INT32_MAX);
		neg_rng = (std::rand() % INT32_MAX);
		if (neg_rng % 2 == 1) number = number * (-1);

		StartCounter();
		binaryHeap.addNewElement(number);
		endTime = GetCounter();
		std::cout << "Heap add new element " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		binaryHeap.~BinaryHeap();
	}

	system("cls");
	file << "\nHeap - delete root" << std::endl;
	for (int i = 1; i <= 100; i++) {

		generateTestData(testRange);
		binaryHeap.readDataFromFile();

		StartCounter();
		binaryHeap.deleteRoot();
		endTime = GetCounter();
		std::cout << "Heap delete root " << i << " -> " << endTime << std::endl;

		file << endTime << std::endl;

		binaryHeap.~BinaryHeap();
	}

	*/
}

