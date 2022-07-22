#pragma once

#include <memory>

#include "Node.h"

namespace studentManager
{
	template <typename T>
	class LinkedList
	{
	public:
		LinkedList();
		~LinkedList() = default;
		LinkedList(const LinkedList&) = delete;
		LinkedList& operator=(const LinkedList&) = delete;

		void	PushBack(T element);
		void	PushBack(size_t index, T element);
		void	PushFront(T element);
		void	RemoveBack();
		void	RemoveBack(size_t index);
		void	RemoveFront();
		void	Clear();

		T	GetBack() const;
		T	GetFront() const;
		size_t	GetSize() const;
		bool	IsEmpty() const;

		std::shared_ptr<Node<T>> GetBegin() const;
		std::shared_ptr<Node<T>> GetEnd() const;

	private:
		std::shared_ptr<Node<T>> mHead;
		std::shared_ptr<Node<T>> mTail;
		size_t mSize;
	};

	template <typename T>
	LinkedList<T>::LinkedList()
		: mHead(new Node<T>)
		, mTail(new Node<T>)
		, mSize(0)
	{
		mHead->Next = mTail;
		mTail->Previous = mHead;
	}

	template <typename T>
	void LinkedList<T>::PushBack(T element)
	{
		std::shared_ptr<Node<T>> pPrevNode = mTail->Previous.lock();

		std::shared_ptr<Node<T>> pNode(new Node<T>);
		pNode->Data = element;

		pPrevNode->Next = pNode;
		pNode->Next = mTail;

		mTail->Previous = std::shared_ptr<Node<T>>(pNode);
		pNode->Previous = pPrevNode;

		++mSize;
	}

	template <typename T>
	void LinkedList<T>::PushBack(size_t index, T element)
	{
		if (index >= mSize)
		{
			PushBack(element);

			return;
		}

		std::shared_ptr<Node<T>> pNode(new Node<T>);
		pNode->Data = element;
		
		std::shared_ptr<Node<T>> pCurNode = mHead;
		std::shared_ptr < Node<T>> pCurNext;
		for (unsigned int i = 0; i < index; ++i)
		{
			pCurNode = pCurNode->Next;
		}

		pCurNext = pCurNode->Next;

		pCurNode->Next = pNode;
		pNode->Next = pCurNext;

		pCurNext->Previous = pNode;
		pNode->Previous = pCurNode;

		++mSize;
	}

	template <typename T>
	void LinkedList<T>::PushFront(T element)
	{
		std::shared_ptr<Node<T>> pNextNode = mHead->Next;

		std::shared_ptr<Node<T>> pNode(new Node<T>);
		pNode->Data = element;

		mHead->Next = pNode;
		pNode->Next = pNextNode;

		pNextNode->Previous = pNode;
		pNode->Previous = mHead;

		++mSize;
	}

	template <typename T>
	void LinkedList<T>::RemoveBack()
	{
		if (IsEmpty())
		{
			return;
		}

		std::shared_ptr<Node<T>> pPrevNode = mTail->Previous.lock();
		std::shared_ptr<Node<T>> pPrevPrevNode = pPrevNode->Previous.lock();

		pPrevPrevNode->Next = mTail;
		mTail->Previous = pPrevPrevNode;

		--mSize;
	}

	template <typename T>
	void LinkedList<T>::RemoveBack(size_t index)
	{
		if (IsEmpty() || index >= mSize)
		{
			return;
		}

		std::shared_ptr<Node<T>> pCurNode = mHead->Next;
		std::shared_ptr < Node<T>> pCurPrev;
		std::shared_ptr < Node<T>> pCurNext;
		for (unsigned int i = 0; i < index; ++i)
		{
			pCurNode = pCurNode->Next;
		}

		pCurPrev = pCurNode->Previous.lock();
		pCurNext = pCurNode->Next;

		pCurPrev->Next = pCurNext;
		pCurNext->Previous = pCurPrev;

		--mSize;
	}

	template <typename T>
	void LinkedList<T>::RemoveFront()
	{
		if (IsEmpty())
		{
			return;
		}

		std::shared_ptr<Node<T>> pNextNode = mHead->Next;

		mHead->Next = pNextNode->Next;
		pNextNode->Next->Previous = mHead;

		--mSize;
	}

	template <typename T>
	void LinkedList<T>::Clear()
	{
		mHead->Next = mTail;
		mTail->Previous = mHead;
	}

	template <typename T>
	T LinkedList<T>::GetBack() const
	{
		assert(!IsEmpty());

		return mTail->Previous.lock()->Data;
	}

	template <typename T>
	T LinkedList<T>::GetFront() const
	{
		assert(!IsEmpty());

		return mHead->Next->Data;
	}

	template <typename T>
	size_t LinkedList<T>::GetSize() const
	{
		return mSize;
	}

	template <typename T>
	bool LinkedList<T>::IsEmpty() const
	{
		return mSize == 0;
	}

	template <typename T>
	std::shared_ptr<Node<T>> LinkedList<T>::GetBegin() const
	{
		return mHead;
	}

	template <typename T>
	std::shared_ptr<Node<T>> LinkedList<T>::GetEnd() const
	{
		return mTail;
	}
}