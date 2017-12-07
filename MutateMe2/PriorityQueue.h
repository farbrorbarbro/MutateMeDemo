#pragma once

#include "Array.h"
#include <memory.h>


template<class T>
class PriorityQueue
{
public:

	PriorityQueue() 
	{
		// insert dummy element at beginning
		heap.add(T());
	}

	void insert(T &&item)
	{
		heap.add(std::move(item));
		bubbleUp(heap.getSize() - 1);
	}

	T pop()
	{
		auto heapSize = getNum();

		T rootElement = getElementAt(1);

		// has more than 1 element?
		if (heapSize > 1)
		{
			// swap last element with root
			heap.swap(1, heapSize);

			// remove old root
			heap.removeLast();

			// bubble down new root element
			bubbleDown(1);
		}
		// this was the last element
		else
		{
			heap.removeLast();
		}

		return rootElement;
	}

	int32_t getNum() const
	{
		return heap.getSize() - 1;
	}

	bool isEmpty() const
	{
		return getNum() < 1;
	}

private:

	int32_t getParent(int32_t index)
	{
		return index / 2;
	}

	int32_t getLeftChild(int32_t index)
	{
		return index * 2;
	}

	int32_t getRightChild(int32_t index)
	{
		return index * 2 + 1;
	}

	bool isValidIndex(int32_t index)
	{
		// [1..size)
		return 0 < index && index < (int32_t)heap.getSize();
	}

	T& getElementAt(int32_t index)
	{
		return heap.getElementAt(index);
	}

	void bubbleDown(int32_t index)
	{
		int32_t leftChildIndex	= getLeftChild(index);
		int32_t rightChildIndex	= getRightChild(index);
		
		auto &currentObject = getElementAt(index);
		
		if (isValidIndex(leftChildIndex))
		{
			auto &leftItem = getElementAt(leftChildIndex);

			if (isValidIndex(rightChildIndex))
			{
				auto &rightItem = getElementAt(rightChildIndex);

				if (leftItem < rightItem)
				{
					if (leftItem < currentObject)
					{
						heap.swap(index, leftChildIndex);
						bubbleDown(leftChildIndex);
					}
				}
				else
				{
					if (rightItem < currentObject)
					{
						heap.swap(index, rightChildIndex);
						bubbleDown(rightChildIndex);
					}
				}
			} 
			else if (leftItem < currentObject)
			{
				heap.swap(index, leftChildIndex);
				bubbleDown(leftChildIndex);
			}
		}
	}

	void bubbleUp(int32_t index)
	{
		int32_t parentIndex = getParent(index);
		
		if (isValidIndex(parentIndex))
		{
			auto &currentElement	= getElementAt(index);
			auto &parentElement		= getElementAt(parentIndex);

			if(currentElement < parentElement)
			{
				heap.swap(index, parentIndex);
				bubbleUp(parentIndex);
			}
		}
	}

private:

	Array<T> heap;
};