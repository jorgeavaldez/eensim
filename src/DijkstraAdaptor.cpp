#include "DijkstraAdaptor.h"

std::vector<int> DijkstraAdaptor::getFlow(Network* net, int start, int end)
{
  //vector containing ID's in order of the shortest path from s to d  
  std::vector<int> shortestPath;
  
  //visited set. Initially empty. Should be full at finish
  std::vector<int> visited;

  //contains tuple of ID and cost to get to start 
  //for each node
  //all values are initially assigned to <node ID, cost to A>
  std::vector<std::tuple<int,int> > weights;
  int vertAmt = net.listVerts().size();
  for(int a = 0; a < vertAmt; a++)
  {
    weights.push_back(std::tuple<int,int>(a,INT_MAX));
  }
  
  //start node's cost to itself is 0
  std::get<1>(weights[start]) = 0;

  //adds the start node to the set
  visted.push_back(start);
  
  //temporary values to hode the n
  int min_node;
  int min;
  int cur;	
  std::vector<int> connectedVerts;
  

  while(visited.size() <= vertAmt)
  {
    //here we should be choosing the next node*****
    cur = chooseNextNode(weights);

    //get all the neighbors of the current node
    connectedVerts = net.getConnectedVerts(cur);
    
    //this shit is fucked up, were not doing comparisons here
    //just updating
    min = INT_MAX;
    for(int i = 0; i < net.getDeg(cur); i++)
    {
      if(net.getWeight(cur,connectedVerts[i]) <= min)
      {
        min = net.getWeight(cur,connectedVerts[i]);
        min_node = connectedVerts[i];

      }

      weights[connectedVerts[i]] = std::tuple<int,int>(connectedVerts[i],min);

    }

    visited.push_back(min_node);

    shortestPath.push_back(min_node);
    
    //FIX THIS--- you have to choose the next node
    //out of all of the nodes in the graph
    //not just current neighbors
    cur = min_node;
  }
  

  return shortestPath;
}


int chooseNextNode(std::vector<std::tuple<int, int> > weights){
   int nextNodeID;
   int numNodes = weights.size();
   int min = INT_MAX;
   for(int i = 0; i < numNodes; i++)
   {
      //visted contains weights[i]
      if(std::get<1>(weights[i]) >= min || std::find(visited.begin(), visited.end(), i) != visited.end())
        continue;
      else  
        nextNodeID = i;
   }

   return nextNodeID;
}
