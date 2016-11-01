#include<iostream>
#include<vector>

using namespace std;


//taken from https://www.quora.com/What-is-the-most-simple-efficient-C++-code-for-Dijkstras-shortest-path-algorithm
//user Steven Hao

//takes an adjacency list and the indeces of the start and target nodes as args
int dijkstra(int source, int target, int vector<vector<int>> adjList)
{
	
	int n = adjList.size();
	vector<int> weight;
	vector<bool> visited;
	FINAL int infinity = 999999999;

	//begin with all weights initialized to infinity
	for(int i = 0; i < n; i++)
	{
		weight[i] = infinity;
	}
	
	//intialize the starting point to zero
	weight[source] = 0;
	
	//loop through every node
	for(int i = 0; i < n; i++){
		
		int current = -1;
		
		//for each node, loop through each of its neighbors
		//Search for the node with the lowest weight that hasn't been visited already 
		//store its index in current
		for(int j = 0; j < n; j++)
		{
			//skip the nodes we've already visited
			if(visited[j]) continue;

			if (current == -1 || weight[j] < weight[current])
			{
				current = j;
			}
		}
		
		visited[current] = true;
		
		//Having found the lowest-cost neighbor of i,
		//add its weight 
		for(int j = 0; j < n; j++)
		{

			int path =  weight[current] + adjList[current][j];
			if(path < weight[j])
			{
				weight[j] = path;
			}
		}	

	}

		
	return weight[targe];
}
