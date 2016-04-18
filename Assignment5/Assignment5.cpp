// Assignment5.cpp : Defines the entry point for the console application.
//
#include "Queue.h"
#include <sstream>


using namespace std;
void printMenu();
void enqueueSent(string sent, Queue * queue);
int main()
{

	int command = -1;
	std::string arg;
	printMenu();
	Queue queue(10);

	while (command != 5)
	{
		cin >> command;
		switch (command)
		{
		case 1:
			if (queue.queueIsFull())
			{
				cout << "Queue is full" << endl;
				break;
			}
			cout << "word: ";
			cin.ignore();
			getline(cin, arg);
			queue.enqueue(arg);
			break;
		case 2:
			queue.dequeue();
			break;
		case 3:
			queue.printQueue();
			break;
		case 4:
			cin.ignore();
			cout << "sentence: ";
			getline(cin, arg);
			enqueueSent(arg, &queue);
			break;
		case 5:
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

void enqueueSent(string s, Queue * queue)
{
	string word = "";
	stringstream ss(s);
	while (ss >> word)
	{
		(*queue).enqueue(word);
	}
}
void printMenu()
{
	cout << "======Main Menu=====" << endl;
	cout << "1. Enqueue word" << endl;
	cout << "2. Dequeue word" << endl;
	cout << "3. Print queue" << endl;
	cout << "4. Enqueue sentence" << endl;
	cout << "5. Quit" << endl;
}
