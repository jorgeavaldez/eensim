#ifndef _GEN_HPP
#define _GEN_HPP

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/erdos_renyi_generator.hpp>
#include <boost/random/linear_congruential.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm_ext/erase.hpp>
#include<boost/tokenizer.hpp>

#include <sstream>
#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <iterator>
#include <stdlib.h>

#include "../graph.hpp"

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, boost::no_property, int> boostGraph;
typedef boost::erdos_renyi_iterator<boost::minstd_rand, boostGraph> ERGen;

class Gen{
  public:
    Gen(); //self-explanatory. refer back to cse1342
    boostGraph genGraph(int v, double p); //generates graph with v verts and p prob of connecting them
    void genDot(int v, double p, std::string f); //same as above, but provides a .gv file of name f
    fuck::Graph dotToGraph(std::string f); //converts .gv to Graph
    void graphToDot(std::string f);//converts Graph to .gv
};

#endif
