#include "HashTable.h"

HashTable::HashTable()
{
	nullelem = new HashElem("null", -1);
	for(int i = 0; i < tableSize; i++)
	{
		hashTable[i] = nullelem;
	}
}

void HashTable::printTableContents()
{
	HashElem * temp = nullptr;
	int check = 0;
	for(int i = 0; i < tableSize; i++)
		if(hashTable[i]->title == nullelem->title)
			check++;

	if(check == 10)
	{
		std::cout << "empty" << std::endl;
		return;
	}

	for(int i = 0; i < tableSize; i++)
	{
		while(hashTable[i]->title == nullelem->title) 
		{
			
			if(i == tableSize)
				return;
			else
				i++;
		}
		
		std::cout << hashTable[i]->title << ":" << hashTable[i]->year  << std::endl;
		temp = hashTable[i];
		while(temp->next != nullptr)
		{
			temp = temp->next;
			std::cout  << temp->title << ":" << temp->year << std::endl;
		}
	}
}

void HashTable::insertMovie(std::string name, int year)
{
	HashElem * newElem = new HashElem(name, year);
	HashElem * nextElem = nullptr;
	int index = hashSum(name, tableSize);
	if(hashTable[index]->title == nullelem->title)
	{
		hashTable[index] = newElem;
	}
	else
	{
		nextElem = hashTable[index];
		while(nextElem->next != nullptr)
		{
			nextElem = nextElem->next;
		}
		
		nextElem->next = newElem;
		newElem->previous = nextElem;
	}	
}

void HashTable::deleteMovie(std::string name)
{
	int index = hashSum(name, tableSize);
	HashElem * toDelete = hashTable[index];
	HashElem * prev = nullptr;
	HashElem * next = nullptr;
	
	while(toDelete->title != name)
	{
		toDelete = toDelete->next;
	}
	
	// This is if it's a single node
	if(toDelete->previous == nullptr && toDelete->next == nullptr)
	{
		hashTable[index] = nullelem;
		delete toDelete;
	}
	// If it's a node that is the start node, but has children
	else if(toDelete->previous == nullptr && toDelete->next != nullptr) 
	{
		next = toDelete->next;
		hashTable[index] = next;
		next->previous = nullptr;
		delete toDelete;
	}
	// If it's a node at the end
	else if(toDelete->previous != nullptr && toDelete->next == nullptr)
	{
		prev = toDelete->previous;
		prev->next = nullptr;
		delete toDelete;
	}
	else if(toDelete->previous != nullptr && toDelete->next != nullptr)
	{
		prev = toDelete->previous;
		next = toDelete->next;
		
		prev->next = next;
		next->previous = prev;
		
		delete toDelete;
	}	
}

void HashTable::findMovie(std::string name)
{
	HashElem * temp = nullptr;
	for(int i = 0; i < tableSize; i++)
	{
		temp = hashTable[i];
		if(temp->title == name)
		{
			std::cout << i << ":" << temp->title << ":" << temp->year << std::endl;
			return;
		}
		while(temp != nullptr)
		{
			if(temp->title == name)
			{
				std::cout << i << ":" << temp->title << ":" << temp->year << std::endl;
				return;
			}
			temp = temp->next;
		}
	}	
}

/* Private Methods */
int HashTable::hashSum(std::string x, int s)
{
	int sum = 0;
	for(int i = 0; i < x.size(); i++)
		sum += x[i];
	sum = sum % s;
	return sum;
}

HashTable::~HashTable(){ }
