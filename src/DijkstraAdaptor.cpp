#include "DijkstraAdaptor.hpp"

DijkstraAdaptor::DijkstraAdaptor() {

}

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
  int vertAmt = net->listVerts().size();
  for(int a = 0; a < vertAmt; a++)
  {
    weights.push_back(std::tuple<int,int>(a,INT_MAX));
  }
  
  //start node's cost to itself is 0
  std::get<1>(weights[start]) = 0;
 
  //adds the start node to the set
 // visited.push_back(start);
  
  //temporary values to hode the n
  int min_node;
  int temp;
  int cur;	
  std::vector<int> connectedVerts;
  

  while(visited.size() < vertAmt)
  {
    //here we should be choosing the next node*****
    cur = chooseNextNode(weights, visited);
    std::cout << "CURRRRRR" << cur << std::endl;

    //get all the neighbors of the current node
    connectedVerts = net->getConnectedVerts(cur);
    
    //this shit is fucked up, were not doing comparisons here
    //just updating
    
    for(int i = 0; i < connectedVerts.size(); i++)
    {
    //  std::cout << "Neighbor " << i << " of " << cur << ":: " <<  std::get<1>(weights[connectedVerts[i]]) << std::endl;
    //  std::cout << "Neighbor " << i << " weight " << net->getWeight(cur, connectedVerts[i]) << std::endl;
      temp = std::get<1>(weights[cur]) + net->getWeight(cur, connectedVerts[i]);      
      if(temp < std::get<1>(weights[connectedVerts[i]]))
      {
        std::get<1>(weights[connectedVerts[i]]) = temp;

      }
      
     // std::cout << "Temp: " << temp <<  std::endl;            
    }
    

    //at the end of the loop push the 
    visited.push_back(cur);
    
    std::cout << "VISITED: ";
    for(size_t i = 0; i < visited.size();i++)
    	std::cout << " " << visited[i];
    std::cout << std::endl;
    //shortestPath.push_back(min_node);
    
  }
  for(int x = 0; x < weights.size(); x++)
  {
    std::cout<< x << "Node: " <<  std::get<0>(weights[x]) << " weight =  " << std::get<1>(weights[x]) << std::endl;
  }
  
  std::cout << "SHORTEST PATH ";
  int cheapestNeighborWeight = INT_MAX;
  int bCur = end;
  int tempNodeID;
  while(bCur != start)
  {
    for(int b = 0; b < net->getConnectedVerts(bCur).size(); b++)
    {
      if(std::get<1>(weights[net->getConnectedVerts(bCur)[b]]) < cheapestNeighborWeight )
      {
        cheapestNeighborWeight = std::get<1>(weights[net->getConnectedVerts(bCur)[b]]); 
        tempNodeID = net->getConnectedVerts(bCur)[b];      
      }
    }
    shortestPath.insert(shortestPath.begin(), bCur);
    bCur = tempNodeID;
  }
  shortestPath.insert(shortestPath.begin(), start);

  for(int c = 0; c < shortestPath.size(); c++)
  {
    std::cout << " " << shortestPath[c] << " ";
  }
 

  return shortestPath;
}

//given the set of visited nodes and the table of nodeID,weight pairs
//return the node in the network with the lowest cost 
int DijkstraAdaptor::chooseNextNode(std::vector<std::tuple<int, int> > weights, std::vector<int> visited){
   int nextNodeID;
   int numNodes = weights.size();
   int min = INT_MAX;
   //bool isLessThanMin;
   //bool inVisited;
   for(int i = 0; i < numNodes; i++)
   {
      
      //if i has not been visited and is less than the current minimum,
      //that i's weight becomes new minium and it should be the next node
      //isLessThanMin = std::get<1>(weights[i]);
      //inVisited = std::find(visited.begin(),visited.end(), i) != visited.end();
      if(std::get<1>(weights[i]) <= min && !(std::find(visited.begin(), visited.end(), i) != visited.end())) 
      {
        min = std::get<1>(weights[i]);
	nextNodeID = i;
       // std::cout << "minInIf" << i << ": " << min << std::endl;
      }
       // std::cout << "minOutIf" << i << ": " << min << std::endl;
   }

   return nextNodeID;
}
