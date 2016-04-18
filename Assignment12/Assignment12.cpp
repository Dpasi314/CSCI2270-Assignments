#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

void printMenu();

int main(int argc, char * argv[])
{
	string arg = "null";
	printMenu();
	
	getline(cin, arg);
	

	HashTable h;

	int command = atoi(arg.c_str());
	string arg1 = "null";
	string arg2 = "null";
	while(command != -1)
	{
		switch(command)
		{
			case 1:
				//Insert Movie
				cout << "Enter title:" << endl;
				getline(cin, arg1);
				
				cout << "Enter year:" << endl;
				getline(cin, arg2);
				h.insertMovie(arg1, atoi(arg2.c_str()));						
				break;
			case 2:
				//Delete Movie
				cout << "Enter title:" << endl;
				getline(cin, arg1);
				h.deleteMovie(arg1);
				break;
			case 3:
				//Find Movie
				cout << "Enter title:" << endl;
				getline(cin, arg1);
				h.findMovie(arg1);
				break;
			case 4:
				//Print table contents
				h.printTableContents();
				break;
			case 5:
				cout << "Goodbye!" << endl;
				return 0;
				break;
			default:
				cout << "The command \"" << command << "\" wasn't recognized" << endl;
				break;
		}
		printMenu();
		getline(cin, arg);
                command = atoi(arg.c_str());
	}
}

void printMenu()
{
	cout << "======Main Menu======" << endl;
	cout << "1. Insert movie" << endl;
	cout << "2. Delete movie" << endl;
	cout << "3. Find movie" << endl;
	cout << "4. Print table contents" << endl;
	cout << "5. Quit" << endl; 
}
