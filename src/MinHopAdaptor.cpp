#include "MinHopAdaptor.hpp"

MinHopAdaptor::MinHopAdaptor(){
    
}

std::vector<int> MinHopAdaptor::getFlow(Network* net, int start, int end)
{
    std::vector<int> shortestPath;

    Network bfs = net->getBFS(start);
    
    bfs.makeGviz("bfs", "bfs");


    return shortestPath;
}