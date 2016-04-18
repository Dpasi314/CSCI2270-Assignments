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
	DeleteAll(root);
}

//Public functions
void MovieTree::printMovieInventory()
{
	printMovieInventory(root);
	postorder(root, 0);

}
int MovieTree::countMovieNodes()
{
	int c = 0;
	countMovieNodes(root, &c);
	return c;
}
void MovieTree::DeleteAll(MovieNode * node)
{
	if(node != nullptr)
	{
		DeleteAll(node->leftChild);
		DeleteAll(node->rightChild);
		std::cout << "Deleting: " << node->title << std::endl;
		delete node;
		if(node->leftChild != nullptr)
			node->leftChild = nullptr;
		if(node->rightChild != nullptr)
			node->rightChild = nullptr;
		node = nullptr;
	}
}
void MovieTree::postorder(MovieNode* p, int indent)
{
    if(p != NULL) {
        if(p->rightChild) {
            postorder(p->rightChild, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->rightChild) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< p->title << "\n ";
        if(p->leftChild) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            postorder(p->leftChild, indent+4);
        }
    }
}
void MovieTree::deleteMovieNode(std::string title)
{
	MovieNode * node = nullptr;
	node = search(title);

	MovieNode * parent = nullptr;
	//If movie not found
	if(node == nullptr)
	{
		std::cout << "Movie not found." << std::endl;
		return;		
	}
	// var. node is now the pointer we want to delete
	// Needs to check if it has children

	//If no children
	parent = node->parent;
	if(node->rightChild == nullptr && node->leftChild == nullptr)
	{
		if(parent->leftChild == node)
			parent->leftChild = nullptr;
		else
			parent->rightChild = nullptr;
		
		delete node;
		return;
	}

	//printMovieInventory(root);
	// Has two children
	if(node->rightChild != nullptr && node->leftChild != nullptr)
	{
		MovieNode * temp = node->rightChild;
		if(temp->leftChild == nullptr && temp->rightChild == nullptr)
		{	
			bool rightChild = (parent->rightChild == node) ? true : false;
			MovieNode * leftSubTree = node->leftChild;
			MovieNode * rightSubTree = node->rightChild;
			
			node->title = temp->title;
			node->year = temp->year;
			node->quantity = temp->quantity;
			node->ranking = temp->ranking;
			delete temp;
			node->rightChild = nullptr;
			node->parent = parent;
			
			if(rightChild)
				parent->rightChild = node;
			else
				parent->leftChild = node;
			node->leftChild = leftSubTree;
			leftSubTree->parent = node;
		}
		else
		{
			if(node->rightChild->leftChild != nullptr)
			{	
				MovieNode * leftPtr = nullptr;
				MovieNode * leftParentPtr = nullptr;
				leftParentPtr = node->rightChild;
				leftPtr = node->rightChild->leftChild;
				while(leftPtr->leftChild != nullptr)
				{
					leftParentPtr = leftPtr;
					leftPtr = leftPtr->leftChild;
				}
				
				node->title = leftPtr->title;
				node->ranking = leftPtr->ranking;
				node->year = leftPtr->ranking;
				node->quantity = leftPtr->quantity;
				node = leftPtr;
				delete leftPtr;
				leftParentPtr->leftChild = nullptr;
				return;
			}
			 else
			{
				MovieNode * temp = nullptr;
				temp = node->rightChild;
				node->title = temp->title;
				node->ranking = temp->ranking;
				node->year = temp->year;
				node->quantity = temp->quantity;
				node->rightChild = temp->rightChild;
				node = temp;
				delete temp;
				return;
			}
			return;
		}
		return;
	}
	// Only has one child
	if(node->rightChild != nullptr || node->leftChild != nullptr)
	{
		if(node->rightChild != nullptr && node->leftChild == nullptr)
		{
			if(parent->leftChild == node)
			{
				parent->leftChild = node->rightChild;
				delete node;
			}
			else
			{
				parent->rightChild = node->rightChild;
				delete node;
			}
		}
		else
		{
			if(parent->leftChild == node)
			{
				parent->leftChild = node->leftChild;
				delete node;
			}
			else
			{
				parent->rightChild = node->leftChild;
				delete node;
			}
		}
		return;
	}

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
	if(searchResult->quantity == 0)
		deleteMovieNode(searchResult->title);
}
//Private functions
void MovieTree::printMovieInventory(MovieNode * node)
{
	  std::cout << "Movie: " << node->title << " " << node->quantity <<  std::endl;

	if(node->leftChild != nullptr)
		printMovieInventory(node->leftChild);
	//std::cout << "Movie: " << node->title << " " << node->quantity <<  std::endl;
	if(node->rightChild != nullptr)
		printMovieInventory(node->rightChild);
}

void MovieTree::countMovieNodes(MovieNode * node, int * c)
{
	if(node->leftChild != nullptr)
		countMovieNodes(node->leftChild, c);
	(*c)++;
	if(node->rightChild != nullptr)
		countMovieNodes(node->rightChild, c);
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
