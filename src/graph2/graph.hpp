#ifndef _GRAPH_HPP
#define _GRAPH_HPP

#include <iostream>
#include <list>
#include <climits>
#include <cstdlib>

class Node {
  public:
    int v;
    int w;
    Node(int v1, int w1);
  };
  Node::Node(int v1, int w1) {
    v = v1;
    w = w1;
}

class Graph {
  int V;
  list < Node > * adj;
  public:
    Graph(int V);
    void addEdge(int v1, int v2, int w);
    void dijkstra(int s, int v);
    int min_dist(int dist[], bool visited[], int d);
};
