#include "Network.hpp"
#include "DijkstraAdaptor.hpp"

int main() {
  Network myNet(15, 25);

  myNet.genNet(10);

  DijkstraAdaptor dadapt = DijkstraAdaptor();
  dadapt.getFlow(&myNet, 0, 10);
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

  /**std::vector<int> nodeVec = myNet.listVerts();
  for(int i = 0; i < nodeVec.size(); i++)
    printf("Node: %d\n", nodeVec[i]);

  std::cout << std::endl;

  std::vector<int> connNodes = myNet.getConnectedVerts(0);
  printf("Verts connected to 0:\n");
  for(int i = 0; i < connNodes.size(); i++)
    printf("%d\n", connNodes[i]);*/

  myNet.makeGviz("dix", "dix");

  /**printf("\nEdge weight between 0 and 2: %d\n", myNet.getWeight(0, 2));

  std::cout << std::endl;
  Network mst = myNet.getBFS(2);

  mst.printEdges();
  std::cout << std::endl;
  mst.printVerts();

  mst.makeGviz("mst", "mst");
  */
  return 0;
}
