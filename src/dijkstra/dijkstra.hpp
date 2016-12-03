//Name: Noah Mendoza
//Squad : Croixboyz
//Professor Engels, Networks CSE 4344
//dijkstra.cpp
#ifndef _DIJKSTRA_HPP
#define _DIJKSTRA_HPP

#include <string>
#include "../graph/graph.hpp"
using namespace std;

int dijkstra(int source, int target, vector<vector<int> > adjList);
void dijsktraV2(const string &source, const string &destination, Graph &g);

#endif
