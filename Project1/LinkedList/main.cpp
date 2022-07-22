#define _CRTDBG_MAP_ALLOC

#include <cassert>
#include <crtdbg.h>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

#include "LinkedList.h"
#include "MemoryPoolLinkedList.h"
#include "SmartLinkedList.h"

void TestLinkedList();
void TestSmartLinkedList(void);
void TestMemoryPoolLinkedList();
void TestCompareTime();

class StudentList;

int main()
{
	dataStructure::Node<int>* h2;

	TestLinkedList();
	TestSmartLinkedList();
	int* a = new int(10);

	_CrtDumpMemoryLeaks();
	std::cin.get();
}

void TestLinkedList()
{
	dataStructure::LinkedList<int> list;

	for (int i = 1; i <= 10; ++i)
	{
		list.PushBack(i);
		assert(list.GetBack() == i);
		assert(list.GetSize() == i);
	}
	for (int i = 10; i >= 1; --i)
	{
		assert(list.GetBack() == i);
		assert(list.GetSize() == i);
		list.RemoveBack();
	}

	assert(list.IsEmpty());

	for (int i = 1; i <= 10; ++i)
	{
		list.PushFront(i);
		assert(list.GetFront() == i);
		assert(list.GetSize() == i);
	}
	for (int i = 10; i >= 1; --i)
	{
		assert(list.GetFront() == i);
		assert(list.GetSize() == i);
		list.RemoveFront();
	}

	assert(list.IsEmpty());

	for (int i = 1; i <= 5; ++i)
	{
		list.PushFront(i);
		assert(list.GetFront() == i);
		assert(list.GetSize() == i);
	}

	// ¼Ò¸êÀÚ°¡ ¸¶Áö¸· 5 ÀÎÀÚ¸¦ Áö¿öÁÜ
}

void TestMemoryPoolLinkedList()
{
	dataStructure::MemoryPoolLinkedList<int> list;

	for (int i = 1; i <= 10; ++i)
	{
		list.PushBack(i);
		assert(list.GetBack() == i);
		assert(list.GetSize() == i);
	}
	for (int i = 10; i >= 1; --i)
	{
		assert(list.GetBack() == i);
		assert(list.GetSize() == i);
		list.RemoveBack();
	}

	assert(list.IsEmpty());

	for (int i = 1; i <= 10; ++i)
	{
		list.PushFront(i);
		assert(list.GetFront() == i);
		assert(list.GetSize() == i);
	}
	for (int i = 10; i >= 1; --i)
	{
		assert(list.GetFront() == i);
		assert(list.GetSize() == i);
		list.RemoveFront();
	}

	assert(list.IsEmpty());

	for (int i = 1; i <= 5; ++i)
	{
		list.PushFront(i);
		assert(list.GetFront() == i);
		assert(list.GetSize() == i);
	}

	// ¼Ò¸êÀÚ
}

void TestSmartLinkedList(void)
{
	dataStructure::SmartLinkedList<int> list;

	for (int i = 1; i <= 10; ++i)
	{
		list.PushBack(i);
		assert(list.GetBack() == i);
		assert(list.GetSize() == i);
	}
	for (int i = 10; i >= 1; --i)
	{
		assert(list.GetBack() == i);
		assert(list.GetSize() == i);
		list.RemoveBack();
	}

	assert(list.IsEmpty());

	for (int i = 1; i <= 10; ++i)
	{
		list.PushFront(i);
		assert(list.GetFront() == i);
		assert(list.GetSize() == i);
	}
	for (int i = 10; i >= 1; --i)
	{
		assert(list.GetFront() == i);
		assert(list.GetSize() == i);
		list.RemoveFront();
	}

	assert(list.IsEmpty());

	for (int i = 1; i <= 10; ++i)
	{
		list.PushFront(i);
		assert(list.GetFront() == i);
		assert(list.GetSize() == i);
	}
	// ¼Ò¸êÀÚ
}

void TestCompareTime()
{
	dataStructure::LinkedList<int> BLL;
	dataStructure::MemoryPoolLinkedList<int> LL;

	using namespace std;
	using namespace chrono;
	
	nanoseconds nanoBLL = nanoseconds::zero();
	nanoseconds nanoLL = nanoseconds::zero();

	for (int k = 0; k < 100; ++k) {
		system_clock::time_point startTime = system_clock::now();
		for (int i = 0; i < 10000; ++i)
		{
			for (int j = 0; j < 128; ++j)
			{
				BLL.PushFront(j);
			}
			for (int i = 0; i < 128; ++i)
			{
				BLL.RemoveBack();
			}
			for (int j = 0; j < 128; ++j)
			{
				BLL.PushBack(j);
			}
			for (int i = 0; i < 128; ++i)
			{
				BLL.RemoveFront();
			}
		}
		system_clock::time_point endTime = system_clock::now();
		nanoseconds nano = endTime - startTime;
		nanoBLL += nano;

		cout << setw(30) << left << "LinkedList" << setw(10) << right << nano.count() << "ns" << endl;

		startTime = system_clock::now();
		for (int i = 0; i < 10000; ++i)
		{
			for (int j = 0; j < 128; ++j)
			{
				LL.PushFront(j);
			}
			for (int i = 0; i < 128; ++i)
			{
				LL.RemoveBack();
			}
			for (int j = 0; j < 128; ++j)
			{
				LL.PushBack(j);
			}
			for (int i = 0; i < 128; ++i)
			{
				LL.RemoveFront();
			}
		}
		endTime = system_clock::now();

		nano = endTime - startTime;
		nanoLL += nano;
		cout << setw(30) << left << "MemoryPoolLinkedList" << setw(10) << right << nano.count() << "ns" << endl;
	}
	
	cout << endl << endl;
	cout << setw(30) << left << "BasicPoolLinkedList average" << setw(10) << right << nanoBLL.count() / 100 << "ns" << endl;
	cout << setw(30) << left << "MemoryPoolLinkedList average" << setw(10) << right << nanoLL.count() / 100 << "ns" << endl;
}