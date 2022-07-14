#pragma once

#include <cassert>
#include <memory>

namespace dataStructure
{
	template <typename T>
	class Queue
	{
	public:
		Queue(size_t size);
		~Queue() = default;
		Queue(const Queue&) = delete;
		Queue& operator=(const Queue&) = delete;

		void PushBack(T element);
		void PopFront();
		bool IsEmpty();
		bool IsFull();
		T GetFront();
		T GetBack();
		size_t GetMaxSize();
		size_t GetSize();

	private:
		std::unique_ptr<T[]> mArray;
		size_t mMaxCount;
		size_t mSize;
		size_t mFront;
		size_t mBack;
	};

	template <typename T>
	Queue<T>::Queue(size_t size)
		: mArray(new T[size])
		, mMaxCount(size)
		, mSize(0)
		, mFront(0)
		, mBack(0)
	{
	}

	template <typename T>
	void Queue<T>::PushBack(T element)
	{
		if (mSize >= mMaxCount)
		{
			return;
		}

		++mSize;
		mArray[mBack++] = element;
		mBack = mBack % mMaxCount;
	}

	template <typename T>
	void Queue<T>::PopFront()
	{
		if (mSize == 0)
		{
			return;
		}

		--mSize;
		mFront = ++mFront % mMaxCount;
	}

	template <typename T>
	bool Queue<T>::IsEmpty()
	{
		return mSize == 0;
	}

	template <typename T>
	bool Queue<T>::IsFull()
	{
		return mMaxCount == mSize;
	}

	template <typename T>
	T Queue<T>::GetFront()
	{
		assert(!IsEmpty());

		return mArray[mFront];
	}
	
	template <typename T>
	T Queue<T>::GetBack()
	{
		assert(!IsEmpty());
		
		int index = mBack - 1 % mMaxCount;

		if (index < 0)
		{
			index += mMaxCount;
		}

		return mArray[index];
	}
	
	template <typename T>
	size_t Queue<T>::GetMaxSize()
	{
		return mMaxCount;
	}
	
	template <typename T>
	size_t Queue<T>::GetSize()
	{
		return mSize;
	}
}