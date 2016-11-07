#include "gen.hpp"
// #include <stdio>
// #include "graph.hpp"
// #include "gen/gen.hpp"
//
// using namespace std;

bool isParent(char c){
    if(c=='('){
      return true;
    }else if(c==')'){
      return true;
    }else{
      return false;
    }
}

int main() {

  // Graph bar(10);
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

  fuck::Graph bar(10);

  std::string line;
  while(std::getline(foo, line)){
    std::string data;

    int val1;
    int val2;
    boost::remove_erase_if(line, boost::is_any_of("()"));
    // std::cout << line << std::endl;
    boost::tokenizer<> tok(line);
    boost::tokenizer<>::iterator beg=tok.begin();
    val1 = std::atoi((*beg).c_str());
    ++beg;
    val2 = std::atoi((*beg).c_str());
    // for(boost::tokenizer<>::iterator beg=tok.begin(); beg!=tok.end();++beg){
    //   cout << *beg << "\n";
    // }
    std::cout << val1 << " " << val2 << std::endl;
    bar.addEdge(val1, val2, 10);
  }

  bar.dijkstra(1, 11);

  fuckthis.close();
  return 0;
}
