#define _CRTDBG_MAP_ALLOC

#include <cassert>
#include <crtdbg.h>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

#include "Stack.h"
#include "Queue.h"
#include <stack>

void TestStack();
void TestQueue();

int main()
{
	TestStack();
	TestQueue();
	_CrtDumpMemoryLeaks();
	std::cin.get();
}



void TestStack()
{
	dataStructure::Stack<int> stack(10);

	for (int i = 1; i <= 10; ++i)
	{
		int value = i * 10;
		stack.Push(value);
		assert(stack.GetTop() == value);
		assert(stack.GetSize() == i);
	}
	assert(stack.IsFull());

	for (int i = 10; i >= 1; --i)
	{
		int value = i * 10;
		assert(stack.GetTop() == value);
		assert(stack.GetSize() == i);
		stack.Pop();
	}

	assert(stack.IsEmpty());
}

void TestQueue()
{
	dataStructure::Queue<int> queue(10);

	for (int i = 1; i <= 10; ++i)
	{
		int value = i * 10;
		queue.PushBack(value);
		assert(queue.GetBack() == value);
		assert(queue.GetSize() == i);
	}

	for (int i = 1; i <= 10; ++i)
	{
		int value = i * 10;
		assert(queue.GetFront() == value);
		queue.PopFront();
	}

	for (int i = 1; i <= 7; ++i)
	{
		int value = i * 10;
		queue.PushBack(value);
		assert(queue.GetBack() == value);
		assert(queue.GetSize() == i);
	}

	for (int i = 1; i <= 7; ++i)
	{
		int value = i * 10;
		assert(queue.GetFront() == value);
		queue.PopFront();
	}

	assert(queue.IsEmpty());
}