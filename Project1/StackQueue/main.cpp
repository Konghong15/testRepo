#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <cassert>
#include <iostream>

#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include "LinkedList_v2.h"
#include <stack>

void TestStack();
void TestQueue();
void TestLinkedList();
void TestLinkedList_v2();

int main()
{
	TestStack();
	TestQueue();
	TestLinkedList();
	TestLinkedList_v2();

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

	for (int i = 1; i <= 10; ++i)
	{
		list.PushFront(i);
		assert(list.GetFront() == i);
		assert(list.GetSize() == i);
	}

	// 社瑚切 持失
}

void TestLinkedList_v2()
{
	dataStructure::LinkedList_v2<int> list;

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

	// 社瑚切 持失
}