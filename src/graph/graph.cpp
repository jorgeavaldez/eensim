#include "graph.hpp"

Graph::Graph() {
  this->Vertices = std::vector<Vertex>();
  this->Edges = std::vector<Edge>();
}

Graph::Graph(std::vector<Vertex> vertices, std::vector<Edge> edges) {
  this->Vertices = vertices;
  this->Edges = edges;
}

Graph::~Graph() {
}

std::vector<Vertex> Graph::getVertices() {
  return this->Vertices;
}

std::vector<Edge> Graph::getEdges() {
  return this->Edges;
}

