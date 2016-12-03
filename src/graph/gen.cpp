#include "gen.hpp"

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property, int> Graph;
typedef boost::erdos_renyi_iterator<boost::minstd_rand, Graph> ERGen;

Gen::Gen(){

}

Gen::Gen(int verts, int connectProb){
  numVertices = verts;
  connectionProbability = connectProb;
}

// Graph generateGraph(){
//   return void;
// }

void Gen::writeDot(string fName){
  boost::minstd_rand gen;

  ostream file(fName);

  Graph g(ERGen(gen, numVertices, connectionProbability), ERGen(), numVertices);
  if(file.is_open()){
  boost::write_graphviz(file, g, boost::default_writer(),
            boost::make_label_writer(boost::get(boost::edge_bundle,g)));
  }
  file.close();
}
