#ifndef _GRAPH_HPP
#define _GRAPH_HPP

#include <list>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <iterator>
#include <stdlib.h>
#include <random>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/erdos_renyi_generator.hpp>
#include <boost/random/linear_congruential.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm_ext/erase.hpp>
#include <boost/tokenizer.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, boost::no_property, int> boostGraph;
typedef boost::erdos_renyi_iterator<boost::minstd_rand, boostGraph> ERGen;

//almost like a js project lol

struct Node {
  public:
    int v;
    int w;
    Node(int v1, int w1) {
      v = v1;
      w = w1;
    }
};

class Graph {
  int V;
  std::list < Node > * adj;
  std::vector <int> *path; // path list of lists

  public:
    Graph(int V);
    void addEdge(int v1, int v2, int w);
    void dijkstra(int s, int v);
    int min_dist(int dist[], bool visited[], int d);
    void genGraph(float p);
};

#endif
