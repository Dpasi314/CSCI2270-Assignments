#pragma once

#include <iostream>
#include <string>
#include <vector>

struct HashElem
{
	std::string title;
	int year;
	HashElem * next;
	HashElem * previous;
	HashElem(){};
	HashElem(std::string _title, int _year)
	{
		title = _title;
		year = _year;
		next = nullptr;
		previous = nullptr;
	}
};

class HashTable
{

public:
	HashTable();
	~HashTable();
	void printTableContents();
	void insertMovie(std::string name, int year);
	void deleteMovie(std::string name);
	void findMovie(std::string name);
	int hashSum(std::string x, int s);
private:
	//int hashSum(std::string x, int s);
	int tableSize = 10;
	HashElem * hashTable[10];
	HashElem * nullelem;
	
};
