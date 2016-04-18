#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>
#include <queue>
struct vertex;

struct adjVertex{
        vertex *v;
        int weight;
	adjVertex(vertex *_v, int _w)
	{
		v = _v;
		weight = _w;
	}adjVertex(){};
};

struct vertex{
	int ID;
	std::string name;
	int district;
	bool visited;
	int distance;
	vertex * parent;
	std::vector<adjVertex> adj;
	vertex(int _ID, std::string _name, bool _vis, int _dist)
	{
		ID = _ID;
		name = _name;
		visited = _vis;
		distance = _dist;
		
	}vertex(){};
	

};

struct queueVertex{
	int distance;
	std::vector<vertex *> path;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void displayEdges();
        void assignDistricts();
        void BFTraversalLabel(std::string startingCity, int distID);
        void shortestPath(std::string startingCity,std::string endingCity);
        vertex * findVertex(std::string name);

    protected:
    private:
        std::vector<vertex> vertices;
	vertex * nullvertex;
	adjVertex * nullAdjVertex;
};

#endif // GRAPH_H
