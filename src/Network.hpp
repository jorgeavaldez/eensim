#ifndef _NETWORK_HPP
#define _NETWORK_HPP

#include "Snap.h"

#include <random>
#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <priority_queue>

class Network{

  public:
    int numVerts;
    int numEdges;
    PUndirNet Net;

    //default constructor
    Network(int e = 10, int v = 15);

    //generates random weights in range(1, ubound)
    void genNet(int ubound);


    /*
     * Edge operations
     * An edge is defined with 2 vertex ids
     */

    //adds edge without weight
    void addEdge(int src, int dst);
    //adds edge with weight
    void addEdge(int src, int dst, int w);
    //assigns weight to edge
    void labelEdge(int src, int dst, int w);
    //gets weight of edge
    int getWeight(int src, int dst);
    //gets random edge
    std::tuple<int, int, int> randEdge();


    /*
     * Vertex operations
     */

     //adds vert with id v
     void addVert(int v);
     //gives a vector of all the verts connected to v
     std::vector<int> getConnectedVerts(int v);
     //gives the degree of a vert
     int getDeg(int v);
     //gives random vert
     int randVert();


    /*
     * Vector functions
     */

    //gives a vector of all edges on the network in the following format:
    //tuple<0> = source vert
    //tuple<1> = dest vert
    //tuple<2> = weight
    //easy to unwrap with std::tie
    std::vector< std::tuple<int, int, int> > listEdges();
    //gives a vector of all verts on the network
    std::vector<int> listVerts();


    /*
     * Print functions
     */

    //prints all edges in network with weights
    void printEdges();
    //prints all verts in network with their degree
    void printVerts();


    /*
     * Shortest path operations
     */

    //creates a breadth-first-search tree from a start vert
    Network getBFS(int start);
    //gets number of hops from vert src to vert dst
    int getHops(Network bfsTree);
    //creates a shortest path with Dijkstra's between two
    Network getShortestPath(int src, int dst);
    //gets the length of a path from vert src to vert dst
    int getPathLen(int src, int dst);


    //Saves a dot representation of the network and renders gif image
    //with optional edge weight labeling
    //use only with my fork of snap
    //shameless plug: https://github.com/dacoconuttman/snap
    void makeGviz(std::string fName, std::string gName, bool weights=true);
};

#endif
