#include "MovieTree.h"
#include <iostream>
#include <cassert>
#include <iomanip>
//Contructors
MovieTree::MovieTree()
{
	root = nullptr;
}

MovieTree::~MovieTree()
{

}

//Public functions
void MovieTree::printMovieInventory()
{
	printMovieInventory(root,0);
}
void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity)
{
	MovieNode * newNode = new MovieNode(ranking, title, releaseYear, quantity);
	MovieNode * temp = root;
	MovieNode * parent = nullptr;
	std::string parentTitle = "null";
	std::string newTitle = title;

	while(temp != nullptr)
	{
		parent = temp;
		if(newTitle < temp->title)
		{	
			temp = temp->leftChild;
		}
		else
		{
			temp = temp->rightChild;
		}	
		
	}
	
	if(parent == nullptr)
	{
		root = newNode;
		root->rightChild = nullptr;
		root->leftChild = nullptr;
		return;
	} 
	else if(newTitle <  parent->title)
	{
		parent->leftChild = newNode;
		newNode->parent = parent;
		newNode->leftChild = nullptr;
		newNode->rightChild = nullptr;
	}
	 else
	{
		parent->rightChild = newNode;
		newNode->parent = parent;
		newNode->leftChild = nullptr;
		newNode->rightChild = nullptr;
	}
}

void MovieTree::findMovie(std::string title)
{
	MovieNode * searchResult = nullptr;
	searchResult = search(title);
	if(searchResult == nullptr)
	{
		std::cout << "Movie not found." << std::endl;
		return;
		}
	std::cout << "Movie Info:" << std::endl;
	std::cout << "===========" << std::endl;
	std::cout << "Ranking:" << searchResult->ranking << std::endl;
	std::cout << "Title:" << searchResult->title << std::endl;
	std::cout << "Year:" << searchResult->year << std::endl;
	std::cout << "Quantity:" << searchResult->quantity << std::endl;
}

void MovieTree::rentMovie(std::string title)
{
	MovieNode * searchResult = nullptr;
	searchResult = search(title);
	if(searchResult == nullptr)
	{
		std::cout << "Movie not found." << std::endl;
		return;
	}
	
	int q = searchResult->quantity;
	if(!(q >= 1))
	{
		std::cout << "Movie out of stock." << std::endl;
		return;
	}

	searchResult->quantity -= 1;
	std::cout << "Movie has been rented." << std::endl;
	std::cout << "Movie Info:" << std::endl;
	std::cout << "===========" << std::endl;
	std::cout << "Ranking:" << searchResult->ranking << std::endl;
	std::cout << "Title:" << searchResult->title << std::endl;
	std::cout << "Year:" << searchResult->year << std::endl;
	std::cout << "Quantity:" << searchResult->quantity << std::endl;
}
//Private functions
void MovieTree::printMovieInventory(MovieNode * p, int indent= 0) 
{
    if(p != nullptr) {
        if(p->leftChild) printMovieInventory(p->leftChild, indent+4);
        if(p->rightChild) printMovieInventory(p->rightChild, indent+4);
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        std::cout<< p->title << "\n ";
    }
}

MovieNode * MovieTree::search(std::string title)
{
	MovieNode * temp = root;
	MovieNode * search = nullptr;
	if(root->title == title) return root;
	while(temp->title != title && temp != nullptr)
	{
		if(title < temp->title)
		{
			if(temp->leftChild == nullptr)
			{
				temp = nullptr;
				break;
			}
			temp = temp->leftChild;
		}	
		else
		{
			if(temp->rightChild == nullptr)
			{
				temp = nullptr;
				break;
			}
			temp = temp->rightChild;
			
		}
	}

	search = temp;
	return search;
	
}
