#pragma once

#include <cstring>
#include <memory>


template<class T>
class Array
{
public:

	Array() 
	{
		resize(10);
	}
	
	void add(T &&newValue)
	{
		if (currentSize >= maxSize)
		{
			resize(maxSize * 2);
		}

		arrayData[currentSize] = std::move(newValue);
		++currentSize;
	}

	void swap(uint32_t indexA, uint32_t indexB)
	{
		T temp				= arrayData[indexA];
		arrayData[indexA]	= arrayData[indexB];
		arrayData[indexB]	= temp;
	}

	void removeLast()
	{
		--currentSize;
	}

	T& getElementAt(uint32_t index)
	{
		return arrayData[index];
	}

	uint32_t getSize() const
	{
		return currentSize;
	}

private:

	void resize(uint32_t newSize)
	{
		std::unique_ptr<T[]> newArrayData(new T[newSize]);
		maxSize = newSize;

		if (arrayData)
		{
			auto *oldArray = arrayData.get();
			auto *newArray = newArrayData.get();

			// shrink if not enough room
			if (currentSize > newSize)
			{
				currentSize = newSize;
			}

			memcpy(newArray, oldArray, currentSize * sizeof(T));
		}

		arrayData = std::move(newArrayData);
	}

private:

	uint32_t currentSize				= 0;
	uint32_t maxSize					= 0;
	std::unique_ptr<T[]> arrayData;
};