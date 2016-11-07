nclude <iostream>
#include <list>
#include <climits>
#include <cstdlib>
void printSolution(int[], int);
using namespace std;
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

     	    Graph::Graph(int v) {
	    V = v;
            adj = new list < Node > [V + 1];
	}
	void Graph::addEdge(int v1, int v2, int w) {
        Node n1(v2, w);
        Node n2(v1, w);
        adj[v1].push_back(n1);
        adj[v2].push_back(n2);
 	}
									void Graph::dijkstra(int s, int d) {
									    int dist[d + 1];
									        bool visited[d + 1];

										    for (int i = 1; i <= d; i++) {
										            dist[i] = INT_MAX;
											            visited[i] = 0;
												        }

													    dist[s] = 0;

													        for (int i = 1; i <= d; i++) {
														        int u = min_dist(dist, visited, d);
															        visited[u] = true;
																        list < Node > ::iterator ob;

																	        for (ob = adj[u].begin(); ob != adj[u].end(); ++ob) {
																		            int v = ( * ob).v;
																			                int w = ( * ob).w;

																					            if (!visited[v] && dist[u] + w < dist[v]) {
																						                    dist[v] = dist[u] + w;
																								                }
																										        }
																											    }

																											        //Printing the distances
																												    cout << "Vertex Distance from Source\n";

																												        for (int i = 1; i <= V; i++)
																													        cout << i << "\t\t" << dist[i] << "\n";
																														}
																														int Graph::min_dist(int dist[], bool visited[], int len) {
																														    int min = INT_MAX, min_index = 1;

																														        for (int i = 1; i <= len; i++) {
																															        if (!visited[i] && dist[i] < min) {
																																            min = dist[i];
																																	                min_index = i;
																																			        }
																																				    }

																																				        return min_index;
																																					}

																																					int main() {
																																					    Graph g(6);
																																					        g.addEdge(1, 2, 1);
																																						    g.addEdge(1, 5, 2);
																																						        g.addEdge(2, 5, 2);
																																							    g.addEdge(2, 3, 2);
																																							        g.addEdge(3, 6, 3);
																																								    g.addEdge(5, 4, 3);
																																								        g.addEdge(3, 4, 4);
																																									    g.dijkstra(1, 6);
																																									    }
