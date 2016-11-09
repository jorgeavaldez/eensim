#include "Snap.h"

void PrintGStats(const char s[], PUNGraph Graph) {
  printf("graph %s, nodes %d, edges %d, empty %s\n",
      s, Graph->GetNodes(), Graph->GetEdges(),
      Graph->Empty() ? "yes" : "no");
}

int main() {
  int nodes = 100;
  int edges = 200;
  PUNGraph UNGraph;
  UNGraph = TSnap::GenRndGnm<PUNGraph>(nodes, edges, false, TInt::Rnd);
  PrintGStats("GenerateRndGnmGraph:UNGraph", UNGraph);
  return 0;
}
