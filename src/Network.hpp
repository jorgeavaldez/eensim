#ifndef _NETWORK_HPP
#define _NETWORK_HPP

#include "Snap.h"

#include <random>
#include <string>
#include <iostream>
#include <vector>
#include <tuple>

class Network{

  public:
    int numVerts;
    int numEdges;
    PUndirNet Net;

    Network();
    Network(int e, int v);

    void genNet(int ubound);

    void addEdge(int src, int dst);
    void addEdge(int src, int dst, int w);
    void labelEdge(int src, int dst, int w);
    int getWeight(int src, int dst);

    std::vector< std::tuple<int, int, int> > listEdges();
    std::vector<int> listVerts();

    void addVert(int v);
    std::vector<int> getConnectedVerts(int v);

    //use only with my fork of snap
    void makeGviz(std::string fName, std::string gName, bool weights=true);

    Network getBFS(int start);

    void printEdges();
    void printVerts();

    // Network getAStar(int src, int dst);
};

#endif
