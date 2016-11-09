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
