#pragma once

#include <memory>

#include "Node.h"

namespace assignment
{
	template <typename T>
	class LinkedList
	{
	public:
		LinkedList();
		~LinkedList() = default;
		LinkedList(const LinkedList&) = delete;
		LinkedList& operator=(const LinkedList&) = delete;

		void	PushFront(std::unique_ptr<T> element);
		void	PushBack(std::unique_ptr<T> element);

		bool	RemoveFront();
		bool	RemoveBack();
		
		std::shared_ptr<Node<T>> GetBackOrNull() const;
		std::shared_ptr<Node<T>> GetFrontOrNull() const;
		std::shared_ptr<Node<T>> operator[](size_t index);

		size_t	GetSize() const;
		bool	IsEmpty() const;

	private:
		std::shared_ptr<Node<T>> mHead;
		std::shared_ptr<Node<T>> mTail;
	};

	template <typename T>
	LinkedList<T>::LinkedList()
		: mHead(nullptr)
		, mTail(nullptr)
	{
		mHead->Next = mTail;
		mTail->Previous = mHead;
	}

	template <typename T>
	void LinkedList<T>::PushBack(std::unique_ptr<T> element)
	{
		std::shared_ptr<Node<T>> prevNode = mTail->Previous.lock();

		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(element);
		
		prevNode->Next = newNode;
		newNode->Next = mTail;

		mTail->Previous = newNode;
		newNode->Previous = prevNode;
	}

	template <typename T>
	void LinkedList<T>::PushFront(std::unique_ptr<T> element)
	{
		std::shared_ptr<Node<T>> nextNode = mHead->Next;

		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(element));

		mHead->Next = pNode;
		pNode->Next = pNextNode;

		pNextNode->Previous = pNode;
		pNode->Previous = mHead;
	}

	template <typename T>
	bool LinkedList<T>::RemoveBack()
	{
		if (mHead->Next == mTail)
		{
			return false;
		}

		std::shared_ptr<Node<T>> removeNode = mTail->Previous.lock();
		std::shared_ptr<Node<T>> prevNode = removeNode->Previous.lock();

		prevNode->Next = mTail;
		mTail->Previous = prevNode;

		return true;
	}

	template <typename T>
	bool LinkedList<T>::RemoveFront()
	{
		if (mHead->Next == mTail)
		{
			return false;
		}

		std::shared_ptr<Node<T>> removeNode = mHead->Next;
		std::shared_ptr<Node<T>> nextNode = removeNode->Next;

		mHead->Next = nextNode;
		nextNode->Previous = mHead;

		return true;
	}

	template <typename T>
	std::shared_ptr<Node<T>> LinkedList<T>::GetBackOrNull() const
	{
		if (IsEmpty)
		{
			return nullptr;
		}

		return mTail->Previous.lock();
	}

	template <typename T>
	std::shared_ptr<Node<T>> LinkedList<T>::GetFrontOrNull() const
	{
		if (IsEmpty)
		{
			return nullptr;
		}

		return mHead->Next;
	}

	template <typename T>
	std::shared_ptr<Node<T>> LinkedList<T>::operator[](size_t index)
	{
		if (index >= GetSize())
		{
			return nullptr;
		}

		std::shared_ptr<Node<T>> curNode = mHead->Next;

		for (int i = 0; i < index; ++i)
		{
			curNode = curNode->Next;
		}

		return curNode;
	}

	template <typename T>
	size_t LinkedList<T>::GetSize() const
	{
		size_t count = 0;
		std::shared_ptr<Node<T>> curNode = mHead->Next;
		
		while (curNode != mTail)
		{
			curNode = curNode->Next;
			++count;
		}

		return count;
	}

	template <typename T>
	bool LinkedList<T>::IsEmpty() const
	{
		return mHead->Next == mTail;
	}
}