<<<<<<< HEAD
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
=======
#include "Snap.h"

// #include "testclass.hpp"

#include <iostream>

// void PrintGStats(const char s[], PUNGraph Graph) {
//   printf("graph %s, nodes %d, edges %d, empty %s\n",
//       s, Graph->GetNodes(), Graph->GetEdges(),
//       Graph->Empty() ? "yes" : "no");
// }

int main() {
  int nodes = 100;
  int edges = 200;
  int ubound = 20;
  // PUNGraph UNGraph;
  PUNGraph Graph = TSnap::GenRndGnm<PUNGraph>(nodes, edges, false, TInt::Rnd);
  // PrintGStats("GenerateRndGnmGraph:UNGraph", UNGraph);
  for (TUNGraph::TEdgeI EI = Graph->BegEI(); EI < Graph->EndEI(); EI++)
   printf("edge (%d, %d)\n", EI.GetSrcNId(), EI.GetDstNId());


  std::cout << "test.cpp main hello world" << std::endl;
  return 0;
}
>>>>>>> 9a3634e97a61e21aaef3016ef074eec08a8d904f
