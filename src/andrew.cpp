#include "Network.hpp"

int main() {
  Network myNet(10, 15);

  myNet.genNet(20);
  myNet.printEdges();
  std::cout << std::endl;
  myNet.printVerts();
  std::cout << std::endl;

  auto edgeVec = myNet.listEdges();
  for(int i = 0; i < edgeVec.size(); i++){
    int src, dst, w;
    std::tie(src, dst, w) = edgeVec[i];
    printf("Source: %d, Dest: %d, Weight: %d\n", src, dst, w);
  }
  std::cout << std::endl;

  std::vector<int> nodeVec = myNet.listVerts();
  for(int i = 0; i < nodeVec.size(); i++)
    printf("Node: %d\n", nodeVec[i]);

  std::cout << std::endl;

  myNet.makeGviz("test", "test");

  Network mst = myNet.getBFS(2);

  mst.printEdges();
  std::cout << std::endl;
  mst.printVerts();

  mst.makeGviz("mst", "mst");


  return 0;
}
