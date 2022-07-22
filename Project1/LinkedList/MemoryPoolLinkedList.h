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
		MemoryPoolLinkedList() = default;
		virtual ~MemoryPoolLinkedList() = default;
		MemoryPoolLinkedList(const MemoryPoolLinkedList&) = delete;
		MemoryPoolLinkedList& operator=(const MemoryPoolLinkedList&) = delete;

	protected:
		virtual Node<T>* getNodeMalloc();
		virtual void deleteNode(Node<T>*);

	private:
		MemoryPool<Node<T>> mMemoryPool;
	};

	template <typename T>
	Node<T>* MemoryPoolLinkedList<T>::getNodeMalloc()
	{
		return mMemoryPool.Get();
	}
	
	template <typename T>
	void MemoryPoolLinkedList<T>::deleteNode(Node<T>* node)
	{
		mMemoryPool.Return(node);
	}
}