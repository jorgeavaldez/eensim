#include <stdio>
#include "graph.hpp"
#include "gen/gen.hpp"

using namespace std;

int main() {

  Graph bar(10);
  boost::minstd_rand gen;

  int v = 10;
  double p = 0.65;

  std::ofstream fuckthis;
  std::stringstream foo;
  fuckthis.open("shit.txt");

  boostGraph g(ERGen(gen, v, p), ERGen(), v);

  std::pair<boostGraph::edge_iterator,
  boostGraph::edge_iterator> es = boost::edges(g);

  std::copy(es.first, es.second,
    std::ostream_iterator<boostGraph::edge_descriptor>{foo, "\n"});

  std::string line;
  while(std::getline(foo, line)){
    std::stringstream linestream(line);
    std::string data;
    int val1;
    int val2;
    boost::erase_all(line, '(');
    boost::erase_all(line, ')');
    std::getline(linestream, data, ',');
    linestream >> val1 >> val2;
    print(val1 + " " + val2);
  }

  fuckthis.close();
  return 0;
}
