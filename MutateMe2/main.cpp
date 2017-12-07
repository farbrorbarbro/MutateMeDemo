#include "PriorityQueue.h"
#include <iostream>
#include <stdint.h>
#include <chrono>
#include <fstream>
#include <vector>


void readTestData(const char *filename, PriorityQueue<int32_t> &priorityQueue);

void readTestData(const char *filename, PriorityQueue<int32_t> &priorityQueue)
{
	std::ifstream file(filename, std::ios::in);
	

	if (!file)
	{
		std::cout << "Failed to open file!" << std::endl;
		return;
	}

	int32_t number;

	while (file >> number)
	{
		priorityQueue.insert(std::move(number));
	}

	file.close();
}


int main(int argc, char *params[])
{
	PriorityQueue<int32_t> priorityQueue;

	readTestData("data.txt", priorityQueue);
	
	std::vector<int32_t> sortedNumbers;
	sortedNumbers.reserve(priorityQueue.getNum());


	auto startTime = std::chrono::high_resolution_clock::now();


	int64_t totalSum = 0;

	while (!priorityQueue.isEmpty())
	{
		int32_t poppedValue = priorityQueue.pop();

		sortedNumbers.push_back(poppedValue);
		
		totalSum += poppedValue;
	}


	auto endTime		= std::chrono::high_resolution_clock::now();


	std::cout << "first: "	<< sortedNumbers[0]							<< std::endl;
	std::cout << "half: "	<< sortedNumbers[sortedNumbers.size() / 2]	<< std::endl;
	std::cout << "last: "	<< sortedNumbers[sortedNumbers.size() - 1]	<< std::endl;

	std::cout << std::endl << "Total sum:" << totalSum << std::endl;

	std::chrono::duration<double> elapsedTime = endTime - startTime;
	std::cout << std::endl << "Time:" << elapsedTime.count() * 1000 << " ms" << std::endl;

	std::cout << std::endl << "Total numbers sorted: " << sortedNumbers.size() << std::endl;

	std::cin.clear();
	std::cin.get();

	return 0;
}