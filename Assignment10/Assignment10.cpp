#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void printMenu();
void parseData(string fileName, Graph * graph);
int main(int argc, char * argv[])
{
	int command = 0;
	string arg = "";
	string arg2 = "";
	printMenu();
	Graph graph;
	string fileName = argv[1];
	parseData(fileName, &graph);
	while(command!= 4)
	{
		cin >> command;
		switch(command)
		{
			case 1:
				// Print Veritcies
				graph.displayEdges();
				break;
			case 2:
				graph.assignDistricts();
				break;
			case 3:
				cin.ignore();
				cout << "Enter a starting city:" << endl;
				getline(cin, arg);
				cout << "Enter an ending city:" <<  endl;
				getline(cin, arg2);
				graph.shortestPath(arg, arg2);
				break;
			case 4:
				// Quit
				cout << "Goodbye!" << endl;
				return 0;
				break;
			default:
				cout << "The command you entered \"" << command << "\" wasn't recognized!" << endl;

		}
		printMenu();
	}
}

void parseData(string fileName, Graph * g)
{
	ifstream file(fileName);
	if(!file.is_open())
	{
		cout << "There was an error opening the file!" << endl;
		return;
	}	
	string line = "";
	getline(file, line);
	istringstream ss(line);
	string token = "";
	vector<string> tokens;
	vector<string> cities;
	while(getline(ss, token, ','))
	{
		if(token != "cities")
		{
			g->addVertex(token);
			cities.push_back(token);
		}
	}
	
	while(getline(file, line))
	{
		istringstream ss1(line);
		while(getline(ss1, token, ','))
		{
			tokens.push_back(token);
		}
		
		for(unsigned int i = 1; i < tokens.size(); i++)
		{
			// cities[i-1] Is the first city
			string s = tokens[i];
			if(atoi(tokens[i].c_str()) != -1 && atoi(tokens[i].c_str()) != 0)
			{
				g->addEdge(cities[i-1], tokens[0], 20);
			}
		}
		tokens.clear();
	}
	
}
void printMenu()
{
	cout << "======Main Menu======" << endl;
	cout << "1. Print vertices" << endl;
	cout << "2. Find districts" << endl;
	cout << "3. Find shortest path" << endl;
	cout << "4. Quit" << endl; 
}
