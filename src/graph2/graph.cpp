#include "graph.hpp"


Graph::Graph(int v) {
    V = v;
    adj = new std::list < Node > [V + 1];
}

void Graph::addEdge(int v1, int v2, int w) {
    Node n1(v2, w);
    Node n2(v1, w);
    adj[v1].push_back(n1);
    adj[v2].push_back(n2);
}
void Graph::dijkstra(int s, int d) {
    int dist[d];
    bool visited[d];

    for (int i = 0; i < d; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[s] = 0;

    for (int i = 0; i < d; i++) {
        int u = min_dist(dist, visited, d);
        visited[u] = true;
        std::list < Node > ::iterator ob;

        for (ob = adj[u].begin(); ob != adj[u].end(); ++ob) {
            int v = ( * ob).v;
            int w = ( * ob).w;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    //Printing the distances
    std::cout << "Vertex Distance from Source\n";

    for (int i = 0; i < V; i++)
        std::cout << i << "\t\t" << dist[i] << "\n";
}
int Graph::min_dist(int dist[], bool visited[], int len) {
    int min = INT_MAX, min_index = 1;

    for (int i = 0; i < len; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void Graph::genGraph(float p){
  /*
   * Full disclosure: this is the most janky abomination to the gods of C++
   * that I have ever written. It kinda works.
   * p is the probability that nodes will be connected. Refer to the
   * Wikipedia page for the Erdős–Rényi model, or back to discrete (loljk).
   */
  std::stringstream ss;

  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> dist(1,20);

  boost::minstd_rand gen;
  boostGraph g(ERGen(gen, V, p), ERGen(), V);

  std::pair<boostGraph::edge_iterator,
    boostGraph::edge_iterator> es = boost::edges(g);
  std::copy(es.first, es.second,
    std::ostream_iterator<boostGraph::edge_descriptor>{ss, "\n"});

  std::string line;

  while(std::getline(ss, line)){
    int vert1, vert2, weight;
    boost::remove_erase_if(line, boost::is_any_of("()"));
    boost::tokenizer<> tok(line);
    boost::tokenizer<>::iterator beg = tok.begin();
    vert1 = std::atoi((*beg).c_str());
    ++beg;
    vert2 = std::atoi((*beg).c_str());
    weight = dist(rng);
    this->addEdge(vert1, vert2, weight);
  }

}
