#include "Cortex.hpp"

Cortex::Cortex(){}

void Cortex::sortFlows() {
  std::sort(this->flows.begin(), this->flows.end(), [](const Flow& f1, const Flow& f2) {
    return f1.totalWeight < f2.totalWeight;
  });
}

void Cortex::reroute(Flow* f, std::tuple<int, int> edge){
  Network tempNet(this->network);
  int src, dst;
  std::tie(src, dst) = edge;
  tempNet.labelEdge(src, dst, std::numeric_limits<int>::max());
  f->path = this->adaptor.getFlow(tempNet, f->startNodeID, f->endNodeID);
}

void Cortex::initializeSimulation(Network* n, IPathAdaptor a, int fCap) {
  this->network = n;
  this->adaptor = a;
  Factory(network, adaptor);
  this->flows = fFactory.getFlowList(0, 1, fCap);
  sortFlows();
}

// REVIEW
// - inProgess is always true
// - we need to begin output
//    - Maybe a way to specify the ostream?
// - Reroute should make change the path of the route but the next iteration
//      should run on the same route with the different path
void Cortex::startSimulation() {
  bool inProgress = true;
  int iter = 0;
  int flowCount = 0;
  while(inProgress) {
    for(auto flow : this->flows) {

      // I think this should be a while where we check the current flow
      if(iter < flow.path.size()) {
        auto currEdge = std::make_tuple(flow.path[iter],
           flow.path[iter + 1]);

        if(this->flowMap.count(currEdge) > 0){
          std::cout << "Collision found" << std::endl;
          reroute(&flows[i], currEdge);
          this->flowMap[currEdge] = &(flow);
        }

        else{
          this->flowMap[currEdge] = &(flow);
        }

      }

      else{
        std::cout << "This flow has ended" << std::endl;
        flowCount++;
      }
    }
    iter++;
    if(flowCount == this->flows.size()) inProgress = false;
  }
}
