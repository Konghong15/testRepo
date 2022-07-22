#pragma once

#include <memory>

namespace assignment
{
	template <typename T>
	class Node
	{
	public:
		Node(std::unique_ptr<T> data);

	public:
		std::unique_ptr<T> Data;
		std::shared_ptr<Node<T>> Next;
		std::weak_ptr<Node<T>> Previous;
	};

	template <typename T>
	Node<T>::Node(std::unique_ptr<T> data)
		: Data(std::move(data))
	{
	}
}