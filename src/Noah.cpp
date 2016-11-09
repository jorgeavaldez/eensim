#include "Snap.h"

#include <random>
#include <iostream>
#include <sstream>

int main() {
  int nodes = 5;
  int edges = 7;
  //full connected --- edges = nodes (nodes - 1) / 2
  int ubound = 20;

  //Create pointer to generated random undirected graph
  PUNGraph Graph = TSnap::GenRndGnm<PUNGraph>(nodes, edges, false);
  
  //Create pointer to a new undirected network
  PUndirNet Net = new TUndirNet(nodes, edges);

  //Traverse all nodes in the graph, add them to the network with the same ID
  for(TUNGraph::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++){
    TInt node =  NI.GetId();
    Net->AddNode(node);
  }

  //traverse all edges in the graph.
  //Get their endpoints and add them to corresponding nodes in network 
  for(TUNGraph::TEdgeI EI = Graph->BegEI(); EI < Graph->EndEI(); EI++){
    TInt src = EI.GetSrcNId();
    TInt dst = EI.GetDstNId();
    Net->AddEdge(src, dst);
  }


  //Print all nodes and their input and output degrees
  for(TUNGraph::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++){
    printf("%d %d %d\n", NI.GetId(), NI.GetOutDeg(), NI.GetInDeg());
  }

  //Print all edges (source, dest pairs)
  for(TUndirNet::TEdgeI EI = Net->BegEI(); EI < Net->EndEI(); EI++)
    printf("edge (%d, %d)\n", EI.GetSrcNId(), EI.GetDstNId());

  //Print # of edges
  printf("# edges: %d\n", Net->GetEdges());
  
  //Jorge's stuff
  //Make a graph
  //pick 2 random nodes on the graph
  //bfstree from start to end
  //print the every path
  //PNGRaph gout = TSnap::GetBfsTree(Net, 
  std::cout << "JORGE'S STUFF" << std::endl;
  PNGraph graph = TSnap::GetBfsTree(Net, Net->BegNI().GetId(),true, false);
  //TBreathFS<PNGraph> BFS(graph);
  //BFS.DoBfs(Net->BegNI().GetId(), true, false);
  TIntPrV aVector;
  std::cout << "TEST HOP PRINTING" << std::endl;
  std::cout << TSnap::GetNodesAtHops(graph, graph->BegNI().GetId(), aVector, false) << std::endl;
  for(auto begin = aVector.BegI(); begin != aVector.EndI(); begin++)
  { 
    std::cout << begin->GetVal1() << " " << begin->GetVal2() << std::endl;
  }
  std::cout << "DID IT WORK?" << std::endl;


  for(TNGraph::TNodeI nodeIter = graph->BegNI(); nodeIter < graph->EndNI(); nodeIter++){
	TInt id =  nodeIter.GetId();
        std::cout << "Node " << id;
  }
   	


  std::cout << "END OF JORGE'S STUFF" << std::endl;


  //Get the shortest #of hops from beginning to end
  //First create the TBreathFs object
  //honestly this part is kinda broken
  PNGraph gout = TSnap::GetBfsTree(Net, Net->BegNI().GetId(), true, false);
  // gout.GetHops(0,1);   
  TBreathFS<PNGraph> BFS(gout);
  BFS.DoBfs(Net->BegNI().GetId(), true, false);

  //this part is important  
  auto endNode = Net->EndNI()--;

  //ingore this shit its broken
  std::cout << "Minimum hops from start to end: " << BFS.GetHops(Net->BegNI().GetId(), endNode.GetId()) << std::endl;
 
  std::cout << "Minimum hops from start to 3: " << BFS.GetHops(Net->BegNI().GetId(), 3)<< std::endl;
 
  //this is the GOOD SHIT
  int shortestPathWeight = TSnap::GetShortPath(Net, Net->BegNI().GetId(), endNode.GetId());
  std::cout << "Shortest path : " << shortestPathWeight << std::endl;
  
  shortestPathWeight = TSnap::GetShortPath(Net, Net->BegNI().GetId(), 3);
  std::cout << "Shortest path to 3: " << shortestPathWeight << std::endl;

  return 0;
}
