#include "MovieTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void printMenu();
void parseFile(string fileName, MovieTree * mt);
int main(int argc, char * argv[])
{
	MovieTree mt;
	parseFile(argv[1], &mt);
	int command = -1;
	string arg = "null";
	printMenu();
	while(command != 6)
	{
		cin >> command;
		switch(command)
		{
			case 1:
				// Find a movie
				cin.ignore();
				cout << "Enter title:" << endl;
				getline(cin, arg);
				mt.findMovie(arg);	
				break;
			case 2:
				// Rent a movie
				cin.ignore();
				cout << "Enter title:" << endl;
				getline(cin, arg);
				mt.rentMovie(arg);
				break;
			case 3:
				// Print the inventory
				mt.printMovieInventory();
				break;
			case 4:
				//Delete a movie
				cin.ignore();
				cout << "Enter title:" << endl;
				getline(cin, arg);
				mt.deleteMovieNode(arg);
				break;
			case 5:
				// Count the movies
				std::cout << "Tree contains: " << mt.countMovieNodes() << " movies." <<  std::endl;
				break;
			case 6:
				// Quit
				cout << "Goodbye!" << endl;
				return 0;
				break;
			default:
				cout << "Command not recognized" << endl;
				break;
		}
		printMenu();
	}
	return 0;
}

void parseFile(string fileName, MovieTree * mt)
{
	ifstream file(fileName);
	if(!file.is_open())
	{
		cout << "There was an error opening the file" << endl;
		return;
	}
	
	string temp = "";
	string token = "";
	int iToken = 0;
	int rating = -1, year = 0, quantity = 0;
	string title = "null";
	
	while(getline(file, token))
	{
		int commaFirst = token.find_first_of(',');
		int commaLast = token.find_last_of(',');
		int commaMiddle = (token.substr(commaFirst).find_first_of(',')); 

		rating = atoi(token.substr(0, commaFirst).c_str());

		temp = token.substr(commaFirst + 1);
		iToken = temp.find_first_of(',');
		title = temp.substr(0,temp.find_first_of(','));

		temp = token.substr((iToken + commaFirst) + 2, commaLast);
		year = atoi(temp.substr(0, temp.find_first_of(',')).c_str());
		
		quantity = atoi(token.substr(commaLast + 1).c_str());
		mt->addMovieNode(rating, title, year, quantity);
												
	}
}

void printMenu()
{
	cout << "======Main Menu======" << endl;
	cout << "1. Find a movie" << endl;
	cout << "2. Rent a movie" << endl;
	cout << "3. Print the inventory" << endl;
	cout << "4. Delete a movie" << endl;
	cout << "5. Count the movies" << endl;
	cout << "6. Quit" << endl;
}
