#include "dijkstra.hpp"
#include "../graph/graph.hpp"
#include <vector>
#include <string>

using namespace std;

void dijkstraV2(const string &source, const  string &destination, Graph &g)
{
	//copy all vertices into local vector
	vector<Vertex> nodes = g.getVertices();

	//create initial weights for all nodes
	//intial weight is 0 for source node, infinity for all others
	vector<int> weights (nodes.size(), 9999999);

	//Finding the source node and setting its 
	//algorithmic
	for(int i = 0; i < nodes.size(); i++)
		if(nodes[i].Label == source)
			weights[i] = 0;

	//Set of nodes that have already been visited
	//intially empty
	vector<string> visited;

	//loop through all nodes
	for(int i = 0; i < nodes.size(); i++)
	{
		//for the current node, consider all of its unvisted neighbors
		//in this case, just loop through all of the edges for this node
		//Be careful to ignore edges you've already looked at
		vector<Edge> temp = nodes.ConnectingEdge[i];
		for(int j = 0; j < temp.size(); j++)
		{

		}

	}	


}

