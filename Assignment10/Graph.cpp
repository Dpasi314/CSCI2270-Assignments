#include "Graph.h"
Graph::Graph() 
{
	nullvertex = new vertex(-1, "null", false, 0);
} 

void Graph::addEdge(std::string v1, std::string v2, int weight)
{
	for(unsigned int i = 0; i < vertices.size(); i++)
	{
		if(vertices[i].name == v1)
		{
			for(unsigned int j = 0; j < vertices.size(); j++)
			{
				if(vertices[j].name == v2 && i != j)
				{
					adjVertex av;
					av.v = &vertices[j];
					av.weight = weight;
					vertices[i].adj.push_back(av);
					
					adjVertex av2;
					av2.v = &vertices[i];
					av2.weight = weight;
					vertices[j].adj.push_back(av2);
				}
			}
		}
	}
}

void Graph::addVertex(std::string name){
    	bool found = false;
	for(unsigned int i = 0; i < vertices.size(); i++)
	{
        	if(vertices[i].name == name)
		{
        		found = true;
        		std::cout<<vertices[i].name<<" found."<<std::endl;
        	}
    	}

	if(found == false)
	{
        	vertex v;
        	v.name = name;
		v.district = -1;
		vertices.push_back(v);
	}
}

void Graph::displayEdges()
{
	for(unsigned int i = 0; i < vertices.size(); i++)
	{
		std::cout << vertices[i].district << ":" << vertices[i].name << "-->";
		for(unsigned int j = 0; j < vertices[i].adj.size(); j++)
		{
			if(vertices[i].adj[j].v->visited == false)
			{
				bool b = vertices[i].adj[j].v->name == vertices[i].adj[vertices[i].adj.size() - 1].v->name;
				std::cout << vertices[i].adj[j].v->name << ((b) ? "" : "***");
				vertices[i].adj[j].v->visited = true;
			}
		
		}
		for(unsigned int i = 0; i < vertices.size(); i++)
		{
			vertices[i].visited = false;
		}
	
	std::cout << std::endl;
	}
}

void Graph::assignDistricts()
{
	int distID = 1;
	int index = 0;
	vertex last = vertices[vertices.size() - 1];
	vertex * v = nullvertex;
	// Iterate through all of the vertices
	for(int i = 0; i < vertices.size(); i++)
	{
		// If the vertice in the vector is currently district-less
		if(vertices[i].district == -1)
		{
			// Assign the district its values initally
			vertices[i].district = distID;
			vertices[i].visited = true;
			// Look through ALL of the adjacent vertices
			for(int j = 0; j < vertices[i].adj.size(); j++)
			{
				
				// If the vertex hasn't already been visited
				if(!vertices[i].adj[j].v->visited && vertices[i].adj[j].v->district == -1)
				{
					// Assign it's values
					vertices[i].adj[j].v->visited = true;
					vertices[i].adj[j].v->district = distID;
				
				
				}
				for(int k = 0; k < vertices[i].adj[j].v->adj.size(); k++)
				{
					if(!vertices[i].adj[j].v->adj[k].v->visited && vertices[i].adj[j].v->adj[k].v->district == -1)
					{
						vertices[i].adj[j].v->adj[k].v->visited = true;
						vertices[i].adj[j].v->adj[k].v->district = distID;
					}
				}
			}
			distID++;
		}
	}



	for(unsigned int i = 0; i < vertices.size(); i++)
         {
        	vertices[i].visited = false;
         }

}

// This sahould be private
void Graph::BFTraversalLabel(std::string startingCity, int distId)
{

}

void Graph::shortestPath(std::string startingCity, std::string endingCity)
{
        vertex * v = findVertex(startingCity);
	vertex * end = findVertex(endingCity);
	std::queue<vertex*> q;
	std::vector<vertex*> path;

        vertex * n = nullvertex;
        if(v == nullvertex)
        {
                std::cout << "One or more cities doesn't exist" << std::endl;
                return;
        }

        if(v->district != end->district)
        {
                std::cout << "No safe path between cities" << std::endl;
                return;
        }

	for(int i = 0; i < vertices.size(); i++)
		vertices[i].visited = false;
	
	q.push(v);
	v->visited = true;
	v->distance = 0;
	v->parent = nullptr;
	int currentDist = 0;
	//path.push_back(v);
	
	while(!q.empty())
	{
		n = q.front();
		q.pop();
		
		for(int i = 0; i < n->adj.size(); i++)
		{
			if(n->adj[i].v->visited == false)
			{
				q.push(n->adj[i].v);
				n->adj[i].v->distance = n->distance + 1;
				n->adj[i].v->visited = true;
				n->adj[i].v->parent = n;
				if(n->adj[i].v->name == endingCity)
					break;
			}
		}
	}
	
	vertex * v1 = end;
	while(v1->parent != nullptr)
	{
		path.push_back(v1);
		v1 = v1->parent;
	}
	path.push_back(v);
	std::cout << path.size() - 1 << ",";
	for(int i = path.size() - 1; i != -1; i--)
	{
		if(i == 0)
		{
			std::cout << path[i]->name << std::endl;
			return;
		}
		std::cout << path[i]->name << ",";
	}
	
}

// This should be private 
vertex * Graph::findVertex(std::string name)
{
	//Look through the vertices vector
	for(unsigned int i = 0; i < vertices.size(); i++)
	{
		if(vertices[i].name == name)
			return &vertices[i];
	}

	return nullvertex;
}

Graph::~Graph()
{

}
