#pragma once

#include <memory>

namespace dataStructure
{
	template <typename T>
	struct SmartNode
	{
		T Data;
		std::shared_ptr<SmartNode<T>> NextPtr;
		std::weak_ptr<SmartNode<T>> PrevPtr;
	};

	template <typename T>
	class SmartLinkedList
	{
	public:
		SmartLinkedList();
		~SmartLinkedList() = default;
		SmartLinkedList(const SmartLinkedList&) = delete;
		SmartLinkedList& operator=(const SmartLinkedList&) = delete;

		void	PushBack(T element);
		void	PushFront(T element);
		void	RemoveBack();
		void	RemoveFront();
		T	GetBack();
		T	GetFront();
		size_t	GetSize();
		bool	IsEmpty();

	private:
		std::shared_ptr<SmartNode<T>> mHeadPtr;
		std::shared_ptr<SmartNode<T>> mTailPtr;
		size_t mSize;
	};

	template <typename T>
	SmartLinkedList<T>::SmartLinkedList()
		: mHeadPtr(new SmartNode<T>)
		, mTailPtr(new SmartNode<T>)
		, mSize(0)
	{
		mHeadPtr->NextPtr = mTailPtr;
		mTailPtr->PrevPtr = mHeadPtr;
	}

	template <typename T>
	void SmartLinkedList<T>::PushBack(T element)
	{
		std::shared_ptr<SmartNode<T>> pPrevNode = mTailPtr->PrevPtr.lock();

		std::shared_ptr<SmartNode<T>> pNode(new SmartNode<T>);
		pNode->Data = element;

		pPrevNode->NextPtr = pNode;
		pNode->NextPtr = mTailPtr;

		mTailPtr->PrevPtr = std::shared_ptr<SmartNode<T>>(pNode);
		pNode->PrevPtr = pPrevNode;

		++mSize;
	}

	template <typename T>
	void SmartLinkedList<T>::PushFront(T element)
	{
		std::shared_ptr<SmartNode<T>> pNextNode = mHeadPtr->NextPtr;

		std::shared_ptr<SmartNode<T>> pNode(new SmartNode<T>);
		pNode->Data = element;

		mHeadPtr->NextPtr = pNode;
		pNode->NextPtr = pNextNode;

		pNextNode->PrevPtr = pNode;
		pNode->PrevPtr = mHeadPtr;

		++mSize;
	}

	template <typename T>
	void SmartLinkedList<T>::RemoveBack()
	{
		if (IsEmpty())
		{
			return;
		}

		std::shared_ptr<SmartNode<T>> pPrevNode = mTailPtr->PrevPtr.lock();
		std::shared_ptr<SmartNode<T>> pPrevPrevNode = pPrevNode->PrevPtr.lock();

		pPrevPrevNode->NextPtr = mTailPtr;
		mTailPtr -> PrevPtr = pPrevPrevNode;

		--mSize;
	}

	template <typename T>
	void SmartLinkedList<T>::RemoveFront()
	{
		if (IsEmpty())
		{
			return;
		}

		std::shared_ptr<SmartNode<T>> pNextNode = mHeadPtr->NextPtr;

		mHeadPtr->NextPtr = pNextNode->NextPtr;
		pNextNode->NextPtr->PrevPtr = mHeadPtr;

		--mSize;
	}

	template <typename T>
	T SmartLinkedList<T>::GetBack()
	{
		assert(!IsEmpty());

		return mTailPtr->PrevPtr.lock()->Data;
	}

	template <typename T>
	T SmartLinkedList<T>::GetFront()
	{
		assert(!IsEmpty());

		return mHeadPtr->NextPtr->Data;
	}

	template <typename T>
	size_t SmartLinkedList<T>::GetSize()
	{
		return mSize;
	}

	template <typename T>
	bool SmartLinkedList<T>::IsEmpty()
	{
		return mSize == 0;
	}
}