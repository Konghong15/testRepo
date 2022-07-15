#pragma once

#include <memory>

namespace dataStructure
{
	template <typename T>
	struct Node_v2
	{
		T Data;
		std::shared_ptr<Node_v2<T>> NextPtr;
		std::weak_ptr<Node_v2<T>> PrevPtr;
	};

	template <typename T>
	class LinkedList_v2
	{
	public:
		LinkedList_v2();
		~LinkedList_v2() = default;
		LinkedList_v2(const LinkedList_v2&) = delete;
		LinkedList_v2& operator=(const LinkedList_v2&) = delete;

		void	PushBack(T element);
		void	PushFront(T element);
		void	RemoveBack();
		void	RemoveFront();
		T		GetBack();
		T		GetFront();
		size_t	GetSize();
		bool	IsEmpty();

	private:
		std::shared_ptr<Node_v2<T>> mHeadPtr;
		std::shared_ptr<Node_v2<T>> mTailPtr;
		size_t mSize;
	};

	template <typename T>
	LinkedList_v2<T>::LinkedList_v2()
		: mHeadPtr(new Node_v2<T>)
		, mTailPtr(new Node_v2<T>)
		, mSize(0)
	{
		mHeadPtr->NextPtr = mTailPtr;
		mTailPtr->PrevPtr = mHeadPtr;
	}

	template <typename T>
	void LinkedList_v2<T>::PushBack(T element)
	{
		std::shared_ptr<Node_v2<T>> pPrevNode = mTailPtr->PrevPtr.lock();

		std::shared_ptr<Node_v2<T>> pNode(new Node_v2<T>);
		pNode->Data = element;

		mTailPtr->PrevPtr = std::shared_ptr<Node_v2<T>>(pNode);
		pNode->PrevPtr = pPrevNode;

		pPrevNode->NextPtr = pNode;
		pNode->NextPtr = mTailPtr;

		++mSize;
	}

	template <typename T>
	void LinkedList_v2<T>::PushFront(T element)
	{
		std::shared_ptr<Node_v2<T>> pNextNode = mHeadPtr->NextPtr;

		std::shared_ptr<Node_v2<T>> pNode(new Node_v2<T>);
		pNode->Data = element;

		mHeadPtr->NextPtr = pNode;
		pNode->NextPtr = pNextNode;

		pNextNode->PrevPtr = pNode;
		pNode->PrevPtr = mHeadPtr;

		++mSize;
	}

	template <typename T>
	void LinkedList_v2<T>::RemoveBack()
	{
		if (IsEmpty())
		{
			return;
		}

		std::shared_ptr<Node_v2<T>> pPrevNode = mTailPtr->PrevPtr.lock();
		std::shared_ptr<Node_v2<T>> pPrevPrevNode = pPrevNode->PrevPtr.lock();

		mTailPtr -> PrevPtr = pPrevPrevNode;
		pPrevPrevNode->NextPtr = mTailPtr;

		--mSize;
	}

	template <typename T>
	void LinkedList_v2<T>::RemoveFront()
	{
		if (IsEmpty())
		{
			return;
		}

		std::shared_ptr<Node_v2<T>> pNextNode = mHeadPtr->NextPtr;

		mHeadPtr->NextPtr = pNextNode->NextPtr;
		pNextNode->NextPtr->PrevPtr = mHeadPtr;

		--mSize;
	}

	template <typename T>
	T LinkedList_v2<T>::GetBack()
	{
		assert(!IsEmpty());

		return mTailPtr->PrevPtr.lock()->Data;
	}

	template <typename T>
	T LinkedList_v2<T>::GetFront()
	{
		assert(!IsEmpty());

		return mHeadPtr->NextPtr->Data;
	}

	template <typename T>
	size_t LinkedList_v2<T>::GetSize()
	{
		return mSize;
	}

	template <typename T>
	bool LinkedList_v2<T>::IsEmpty()
	{
		return mSize == 0;
	}
}