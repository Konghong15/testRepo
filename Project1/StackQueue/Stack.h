#pragma once

#include <cassert>
#include <memory>

namespace dataStructure
{
	template <typename T>
	class Stack
	{
	public:
		Stack(size_t size);
		~Stack() = default;
		Stack(const Stack&) = delete;
		Stack& operator=(const Stack&) = delete;

		void Push(T element);
		void Pop();
		bool IsEmpty();
		bool IsFull();
		T GetTop();
		size_t GetMaxSize();
		size_t GetSize();

	private:
		std::unique_ptr<T[]> mArray;
		size_t mMaxCount;
		size_t mCount;
	};

	template <typename T>
	Stack<T>::Stack(size_t size)
		: mArray(new T[size])
		, mMaxCount(size)
		, mCount(0)
	{
	}

	template <typename T>
	void Stack<T>::Push(T element)
	{
		if (mCount >= mMaxCount)
		{
			return;
		}

		mArray[mCount++] = element;
	}

	template <typename T>
	void Stack<T>::Pop()
	{
		--mCount;
	}

	template <typename T>
	bool Stack<T>::IsEmpty()
	{
		return mCount == 0;
	}

	template <typename T>
	bool Stack<T>::IsFull()
	{
		return mMaxCount == mCount;
	}

	template <typename T>
	T Stack<T>::GetTop()
	{
		assert(!IsEmpty());

		return mArray[mCount - 1];
	}

	template <typename T>
	size_t Stack<T>::GetMaxSize()
	{
		return mMaxCount;
	}

	template <typename T>
	size_t Stack<T>::GetSize()
	{
		return mCount;
	}
}