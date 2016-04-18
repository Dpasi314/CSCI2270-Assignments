#include "Queue.h"

Queue::Queue(int size)
{
	queueSize = size;
	arrayQueue = new std::string[queueSize];
	queueHead = 0;
	queueTail = 0;
	queueCount = 0;
}

Queue::~Queue()
{

}

void Queue::enqueue(std::string toQueue)
{
	if (queueIsFull())
	{
		std::cout << "Queue is full." << std::endl;
		return;
	}

	arrayQueue[queueCount] = toQueue;
	queueTail = (queueTail + 1) % 10;
	std::cout << "E: " << toQueue << std::endl;
	std::cout << "H: " << queueHead << std::endl;
	std::cout << "T: " << ((queueTail == 10) ? 0 : queueTail) << std::endl;
	queueCount++;
}

std::string Queue::dequeue()
{
	if (queueIsEmpty()) 
	{
		std::cout << "Queue is empty." << std::endl;
		return "";
	}

	std::string word = arrayQueue[queueHead];
	arrayQueue[queueHead] = "null";
	queueHead = (queueHead + 1) % 10;
	std::cout << "H: " << queueHead << std::endl;
	std::cout << "T: " << ((queueTail == 10) ? 0 : queueTail) << std::endl;
	std::cout << "word: " << word << std::endl;
	queueCount--;
	return word;
}

void Queue::printQueue()
{
	if (queueIsEmpty())
	{
		std::cout << "Empty" << std::endl;
		return;
	}
	for (int i = queueHead; i < queueCount; i++)
	{
		/*if (arrayQueue[i] == "null" || arrayQueue[i] == "") 
		{
			i++;
			continue;
		}*/
		std::cout << i << ": " << arrayQueue[i] << std::endl;
	}
}

bool Queue::queueIsFull()
{
	return (queueCount == queueSize);
}

bool Queue::queueIsEmpty()
{
	return (queueCount == 0);
}
