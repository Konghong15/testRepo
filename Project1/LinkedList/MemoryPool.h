#pragma once

namespace dataStructure
{
	template <typename T>
	class MemoryPool
	{
	public:
		MemoryPool();
		~MemoryPool();
		MemoryPool(const MemoryPool&) = delete;
		MemoryPool& operator=(const MemoryPool&) = delete;

		T* Get();
		void Return(T* element);

	private:
		enum { MEMORY_SIZE = 128 };
		T** mMemory;
		size_t mCount;
	};

	template <typename T>
	MemoryPool<T>::MemoryPool()
		: mMemory(new T* [MEMORY_SIZE])
		, mCount(0)
	{
	}

	template <typename T>
	MemoryPool<T>::~MemoryPool()
	{
		for (unsigned int i = 0; i < mCount; ++i)
		{
			delete mMemory[i];
		}

		delete[] mMemory;
	}

	template <typename T>
	T* MemoryPool<T>::Get()
	{
		if (mCount == 0)
		{
			return new T;
		}

		return mMemory[--mCount];
	}

	template <typename T>
	void MemoryPool<T>::Return(T* element)
	{
		if (mCount == MEMORY_SIZE)
		{
			delete element;
		}

		mMemory[mCount++] = element;
	}
}