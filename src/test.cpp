#include "Snap.h"

#include <random>
#include <iostream>
#include <sstream>

int main() {
  int nodes = 10;
  int edges = 15;
  int ubound = 20;

  PUNGraph Graph = TSnap::GenRndGnm<PUNGraph>(nodes, edges, false);
  PUndirNet Net = new TUndirNet(nodes, edges);

  for(TUNGraph::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++){
    TInt node =  NI.GetId();
    Net->AddNode(node);
  }

  for(TUNGraph::TEdgeI EI = Graph->BegEI(); EI < Graph->EndEI(); EI++){
    TInt src = EI.GetSrcNId();
    TInt dst = EI.GetDstNId();
    Net->AddEdge(src, dst);
  }



  for(TUNGraph::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++){
    printf("%d %d %d\n", NI.GetId(), NI.GetOutDeg(), NI.GetInDeg());
  }

  for(TUndirNet::TEdgeI EI = Net->BegEI(); EI < Net->EndEI(); EI++)
    printf("edge (%d, %d)\n", EI.GetSrcNId(), EI.GetDstNId());

  printf("# edges: %d\n", Net->GetEdges());
  return 0;
}
