#ifndef _NETWORK_HPP
#define _NETWORK_HPP

#include "Snap.h"

#include <random>
#include <string>
#include <iostream>

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

    std::vector< std::tuple<int, int, int> > listEdges();
    std::vector<int> listVerts();

    void addVert(int v);

    void makeGviz(std::string fName, std::string gName);

    Network getBFS(int start);
    // Network getShortestPath(int src, int dst);

    void printEdges();
    void printVerts();
};

#endif
