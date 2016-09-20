#ifndef _GRAPH_HPP
#define _GRAPH_HPP

#include <string>
#include <vector>

// This struct serves as a representation of the Edges
// of our graph model, or the routes that a packet
// takes between two given Vertices
struct Edge {
  float Weight;
  unsigned long Distance;
  unsigned long Time;
};

// This struct serves as a representation of the Vertices
// of our graph model, or the routers that connect
// to form a route in a graph
struct Vertex {
  std::vector<Edge> ConnectingEdge;
  std::string Label;
};

class Graph {
  public:
    Graph();
    Graph(std::vector<Vertex>, std::vector<Edge>);

    ~Graph();

    std::vector<Vertex> getVertices();
    std::vector<Edge> getEdges();

  private:
    std::vector<Vertex> Vertices; 
    std::vector<Edge> Edges; 
};

#endif
