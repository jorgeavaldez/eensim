#include "graph.hpp"

int main(){
  Graph foo(10);
  Graph bar(50);

  foo.genGraph(0.8);
  bar.genGraph(0.5);

  foo.dijkstra(0, 10);
  bar.dijkstra(0, 50);

  return 0;
}
