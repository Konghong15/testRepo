#pragma once

#include <memory>

#include "LinkedList.h"
#include "MemoryPool.h"

namespace dataStructure
{
	template <typename T>
	class MemoryPoolLinkedList : public LinkedList<T>
	{
	public:
		MemoryPoolLinkedList();
		virtual ~MemoryPoolLinkedList();
		MemoryPoolLinkedList(const MemoryPoolLinkedList&) = delete;
		MemoryPoolLinkedList& operator=(const MemoryPoolLinkedList&) = delete;

		virtual void PushBack(T element);
		virtual void PushFront(T element);
		virtual void RemoveBack();
		virtual void RemoveFront();
		virtual T GetBack();
		virtual T GetFront();

	private:
		MemoryPool<Node<T>> mMemoryPool;
	};

	template <typename T>
	MemoryPoolLinkedList<T>::MemoryPoolLinkedList()
		: LinkedList<T>()
	{
	}

	template <typename T>
	MemoryPoolLinkedList<T>::~MemoryPoolLinkedList()
	{
		Node<T>* pNode = LinkedList<T>::mHead.NextPtr;

		while (pNode != &(LinkedList<T>::mTail))
		{
			Node<T>* pNext = pNode->NextPtr;

			mMemoryPool.Return(pNode);

			pNode = pNext;
		}
	}

	template <typename T>
	void MemoryPoolLinkedList<T>::PushBack(T element)
	{
		Node<T>* pPrevNode = LinkedList<T>::mTail.PrevPtr;

		Node<T>* paNode = mMemoryPool.Get();
		paNode->Data = element;

		pPrevNode->NextPtr = paNode;
		paNode->NextPtr = &(LinkedList<T>::mTail);

		LinkedList<T>::mTail.PrevPtr = paNode;
		paNode->PrevPtr = pPrevNode;

		++LinkedList<T>::mSize;
	}

	template <typename T>
	void MemoryPoolLinkedList<T>::PushFront(T element)
	{
		Node<T>* pNextNode = LinkedList<T>::mHead.NextPtr;

		Node<T>* paNode = mMemoryPool.Get();
		paNode->Data = element;

		LinkedList<T>::mHead.NextPtr = paNode;
		paNode->NextPtr = pNextNode;

		pNextNode->PrevPtr = paNode;
		paNode->PrevPtr = &(LinkedList<T>::mHead);

		++LinkedList<T>::mSize;
	}

	template <typename T>
	void MemoryPoolLinkedList<T>::RemoveBack()
	{
		if (LinkedList<T>::IsEmpty())
		{
			return;
		}

		Node<T>* pPrevNode = LinkedList<T>::mTail.PrevPtr;

		pPrevNode->PrevPtr->NextPtr = &(LinkedList<T>::mTail);
		LinkedList<T>::mTail.PrevPtr = pPrevNode->PrevPtr;

		mMemoryPool.Return(pPrevNode);
		--LinkedList<T>::mSize;
	}

	template <typename T>
	void MemoryPoolLinkedList<T>::RemoveFront()
	{
		if (LinkedList<T>::IsEmpty())
		{
			return;
		}

		Node<T>* pNextNode = LinkedList<T>::mHead.NextPtr;

		LinkedList<T>::mHead.NextPtr = pNextNode->NextPtr;
		pNextNode->NextPtr->PrevPtr = &(LinkedList<T>::mHead);

		mMemoryPool.Return(pNextNode);
		--LinkedList<T>::mSize;
	}

	template <typename T>
	T MemoryPoolLinkedList<T>::GetBack()
	{
		assert(!LinkedList<T>::IsEmpty());

		return LinkedList<T>::mTail.PrevPtr->Data;
	}

	template <typename T>
	T MemoryPoolLinkedList<T>::GetFront()
	{
		assert(!LinkedList<T>::IsEmpty());

		return LinkedList<T>::mHead.NextPtr->Data;
	}
}