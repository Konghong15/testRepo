#pragma once

namespace studentManager
{
	template <typename T>
	struct Node
	{
		T Data;
		std::shared_ptr<Node<T>> Next;
		std::weak_ptr<Node<T>> Previous;
	};
}