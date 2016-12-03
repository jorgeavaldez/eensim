#ifndef _GEN_HPP
#define _GEN_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/erdos_renyi_generator.hpp>
#include <boost/random/linear_congruential.hpp>
#include <boost/graph/graphviz.hpp>

//#include "graph.hpp"

class Gen {
  public:
    Gen();
    Gen(size_t verts, double connectProb);

    //Graph generateGraph();
    void writeDot(string fName);

    ~Gen();

  private:
    size_t numVertices;
    double connectionProbability;
}
