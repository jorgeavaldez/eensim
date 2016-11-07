#include "graph.hpp"

void printSolution(int[], int);
using namespace std;

Graph::Graph(int v) {
    V = v;
    adj = new list < Node > [V + 1];
    path = new vector<int>[V+1]; // path list
}

void Graph::addEdge(int v1, int v2, int w) {
    Node n1(v2, w);
    Node n2(v1, w);
    adj[v1].push_back(n1);
    adj[v2].push_back(n2);
}
void Graph::dijkstra(int s, int d) {
    
    //arrays to hold the visited nodes
    //as well as distances from s to the other nodes
    int dist[d + 1];
    bool visited[d + 1];


    //intialize the 
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
                path[v] = path[u];
                path[v].insert(path[v].begin(),u);
            }
        }
    }

    //Printing the distances
    cout << "Vertex Distance from node " << s << "\n";

    for (int i = 1; i <= V; i++){
        //cout << "Node " << i << "\t\t" << dist[i] << "\n";
        cout << i << "\t\t" << dist[i] << "\n";
	}
   
    for(int i = 1; i <= V; i++)
    {
      cout << i << ": ";
      for(int j=0;j<path[i].size();j++)
        cout<<path[i][j]<<"-> ";
      cout<<endl;
     
    }

}

//Takes the inclusive set of nodes between the source and destination as inputs
//Len is the size of that set
int Graph::min_dist(int dist[], bool visited[], int len) {
    int min = INT_MAX, min_index = 1;

    for (int i = 1; i <= len; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    
//    cout << "Minmum distance from" << endl; 
    return min_index;
}

int main() {
    //graph with 6 nodes
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
