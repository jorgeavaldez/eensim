#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/erdos_renyi_generator.hpp>
#include <boost/random/linear_congruential.hpp>
#include <boost/graph/graphviz.hpp>

#include <iostream>
#include <fstream>

// typedef boost::adjacency_list<> Graph;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property, int> Graph;
typedef boost::erdos_renyi_iterator<boost::minstd_rand, Graph> ERGen;

int main()
{
  boost::minstd_rand gen;
  std::ofstream out;
  out.open("graph.gv");
  // Create graph with 100 nodes and edges with probability 0.05
  Graph g(ERGen(gen, 50, 0.75), ERGen(), 50);
  // std::cout << g << std::endl;
  boost::write_graphviz(out, g, boost::default_writer(),
            boost::make_label_writer(boost::get(boost::edge_bundle,g)));

  out.close();
  return 0;
}
