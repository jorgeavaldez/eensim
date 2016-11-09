#include "Snap.h"

#include <random>
#include <iostream>
#include <sstream>

int main() {
  int nodes = 10;
  int edges = 15;
  int ubound = 20;

  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> dist(1, ubound);

  PUNGraph Graph = TSnap::GenRndGnm<PUNGraph>(nodes, edges, false, TInt::Rnd);
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

  for(TUndirNet::TEdgeI EI = Net->BegEI(); EI < Net->EndEI(); EI++){
    TInt src = EI.GetSrcNId();
    TInt dst = EI.GetDstNId();
    TStr id("weight");
    TInt w = dist(rng);
    Net->AddSAttrDatE(src, dst, id, w);
  }

  for(TUndirNet::TEdgeI EI = Net->BegEI(); EI < Net->EndEI(); EI++){
    TInt src = EI.GetSrcNId();
    TInt dst = EI.GetDstNId();
    TStr id("weight");
    TInt val;
    Net->GetSAttrDatE(src, dst, id, val);
    printf("Edge %d->%d has attribute, with id %s, with value %d.\n", src, dst, id.CStr(), val.Val);  
    }

  // for(TUNGraph::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++){
  //   printf("%d %d %d\n", NI.GetId(), NI.GetOutDeg(), NI.GetInDeg());
  // }
  //
  // for(TUndirNet::TEdgeI EI = Net->BegEI(); EI < Net->EndEI(); EI++)
  //   printf("edge (%d, %d)\n", EI.GetSrcNId(), EI.GetDstNId());
  //
  // printf("# edges: %d\n", Net->GetEdges());
  return 0;
}
