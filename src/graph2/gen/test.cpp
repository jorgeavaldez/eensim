#include "gen.hpp"

int main(){
  boost::minstd_rand gen;

  int v = 43;
  double p = 0.65;

boostGraph g(ERGen(gen, v, p), ERGen(), v);

  std::pair<boostGraph::edge_iterator,
      boostGraph::edge_iterator> es = boost::edges(g);

    std::copy(es.first, es.second,
      std::ostream_iterator<boostGraph::edge_descriptor>{std::cout, "\n"});
  return 0;
}
