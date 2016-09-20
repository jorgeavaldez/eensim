#include <iostream>
#include <vector>
#include <string>

#include "graph/graph.hpp"

int main(int argc, char** argv) {
  std::cout << "Attempting to construct graph..." << std::endl;

  auto vertices = std::vector<Vertex>(2);
  auto edges = std::vector<Edge>(2);

  Graph g(vertices, edges);

  return 0;
}
