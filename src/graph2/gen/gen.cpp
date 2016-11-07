#include "gen.hpp"


Gen::Gen(){}

boostGraph Gen::genGraph(int v, double p){
  boost::minstd_rand gen;

  boostGraph g(ERGen(gen, v, p), ERGen(), v);
  return g;
  // graph_traits<boostGraph>::vertex_iterator vi, vi_end, next;
  // boost::tie(vi, vi_end) = vertices(g);
  // for (next = vi; vi != vi_end; vi = next) {
  //
  //   next++;
  // }

}


void genDot(int v, double p, std::string f){
  boost::minstd_rand gen;
  std::ofstream out;

  out.open(std::string f);

  boostGraph g(ERGen(gen, v, p), ERGen(), v);
  boost::write_graphviz(out, g, boost::default_writer(),
            boost::make_label_writer(boost::get(boost::edge_bundle,g)));

  out.close();
}
