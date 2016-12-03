#include "Cortex.hpp"

Cortex::Cortex(){}

void Cortex::sortFlows() {
  std::sort(this->flows.begin(), this->flows.end(), [](const Flow& f1, const Flow& f2) {
    return f1.totalWeight < f2.totalWeight;
  });
}

void Cortex::reroute(Flow* f){
  // TODO: Andrew - need to implement rerouting based on the current adaptor
  // Needs to change the flow's path vector
  std::cout << "lmao" << std::endl;
}
void Cortex::initializeSimulation(Network* n, IPathAdaptor adaptor, int fCap) {
  network = n;
  fFactory(network, adaptor);
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
  while(inProgress) {
    for(int i = 0; i < this->flows.size(); i++) {

      // I think this should be a while where we check the current flow
      if(iter < this->flows[i].path.size()) {
        auto currEdge = std::make_tuple(this->flows[i].path[iter],
           this->flows[i].path[iter + 1]);

        if(this->flowMap.count(currEdge) > 0){
          std::cout << "Collision found" << std::endl;
          reroute(&flows[i]);
        }

        else{
          this->flowMap[currEdge] = &this->flows[i];
        }

      }
      
      else{
        std::cout << "This flow has ended" << std::endl;
      }
    }
    iter++;
  }
}
