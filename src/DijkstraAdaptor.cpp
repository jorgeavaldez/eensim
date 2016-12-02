#include "DijkstraAdaptor.h"

std::vector<int> DijkstraAdaptor::getFlow(Network* net, int start, int end)
{
  std::vector<int> visited;
  std::vector<int> shortestPath;
  std::vector<std::tuple<int,int> > weights;
  
  
  visited.push_back(start);

  int vertAmt = net.listVerts().size();
  for(int a = 0; a < vertAmt; a++)
  {
    weights.push_back(std::tuple<int,int>(a,INT_MAX);
  }
  

  int min_node;
  int cur = start;	
  std::vector<int> connectedVerts = net.getConnectedVerts(start);
  
  while(visited.size() <= vertAmt)
  {
    
    int min = INT_MAX;
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
    cur = min_node;
  }
  
  

  return shortestPath;
}
