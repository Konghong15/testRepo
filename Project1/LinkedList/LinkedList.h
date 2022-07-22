#pragma once

#include <memory>

namespace dataStructure
{
	template <typename T>
	struct Node
	{
		T Data;
		Node* NextPtr;
		Node* PrevPtr;
	};

	template <typename T>
	class LinkedList
	{
	public:
		LinkedList();
		virtual ~LinkedList();
		LinkedList(const LinkedList&) = delete;
		LinkedList& operator=(const LinkedList&) = delete;

		void PushBack(T element);
		void PushFront(T element);
		void RemoveBack();
		void RemoveFront();
		T GetBack();
		T GetFront();
		size_t GetSize();
		bool IsEmpty();

	protected:
		virtual Node<T>* getNodeMalloc();
		virtual void deleteNode(Node<T>*);

	protected:
		Node<T> mHead;
		Node<T> mTail;
		size_t mSize;
	};

	template <typename T>
	LinkedList<T>::LinkedList()
		: mSize(0)
	{
		mHead.PrevPtr = nullptr;
		mHead.NextPtr = &mTail;
		mTail.PrevPtr = &mHead;
		mTail.NextPtr = nullptr;
	}

	template <typename T>
	LinkedList<T>::~LinkedList()
	{
		Node<T>* pNode = mHead.NextPtr;

		while (pNode != &mTail)
		{
			Node<T>* pNext = pNode->NextPtr;

			deleteNode(pNode);

			pNode = pNext;
		}
	}

	template <typename T>
	void LinkedList<T>::PushBack(T element)
	{
		Node<T>* pPrevNode = mTail.PrevPtr;

		Node<T>* paNode = getNodeMalloc();
		paNode->Data = element;

		mTail.PrevPtr = paNode;
		paNode->PrevPtr = pPrevNode;

		pPrevNode->NextPtr = paNode;
		paNode->NextPtr = &mTail;

		++mSize;
	}

	template <typename T>
	void LinkedList<T>::PushFront(T element)
	{
		Node<T>* pNextNode = mHead.NextPtr;

		Node<T>* paNode = getNodeMalloc();
		paNode->Data = element;

		mHead.NextPtr = paNode;
		paNode->NextPtr = pNextNode;

		pNextNode->PrevPtr = paNode;
		paNode->PrevPtr = &mHead;

		++mSize;
	}

	template <typename T>
	void LinkedList<T>::RemoveBack()
	{
		if (IsEmpty())
		{
			return;
		}

		Node<T>* pPrevNode = mTail.PrevPtr;

		mTail.PrevPtr = pPrevNode->PrevPtr;
		pPrevNode->PrevPtr->NextPtr = &mTail;

		deleteNode(pPrevNode);
		--mSize;
	}

	template <typename T>
	void LinkedList<T>::RemoveFront()
	{
		if (IsEmpty())
		{
			return;
		}

		Node<T>* pNextNode = mHead.NextPtr;

		mHead.NextPtr = pNextNode->NextPtr;
		pNextNode->NextPtr->PrevPtr = &mHead;

		deleteNode(pNextNode);
		--mSize;
	}

	template <typename T>
	T LinkedList<T>::GetBack()
	{
		assert(!IsEmpty());

		return mTail.PrevPtr->Data;
	}

	template <typename T>
	T LinkedList<T>::GetFront()
	{
		assert(!IsEmpty());

		return mHead.NextPtr->Data;
	}

	template <typename T>
	size_t LinkedList<T>::GetSize()
	{
		return mSize;
	}

	template <typename T>
	bool LinkedList<T>::IsEmpty()
	{
		return mSize == 0;
	}

	template <typename T>
	Node<T>* LinkedList<T>::getNodeMalloc()
	{
		return new Node<T>;
	}

	template <typename T>
	void LinkedList<T>::deleteNode(Node<T>* node)
	{
		delete node;
	}
}
