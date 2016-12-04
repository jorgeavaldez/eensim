#include "Cortex.hpp"

Cortex::Cortex(){}

void Cortex::sortFlows() {
  std::sort(this->flows.begin(), this->flows.end(), [](Flow f1, Flow f2) {
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

void Cortex::resimulate(){

}

void Cortex::startSimulation() {

  auto tempFlows = this->flows;


  for(int i = 0; i < tempFlows.size(); i++) {
    this->flowCount[tempFlows[i].flowID] = 0;
  }

  int iter = 0;

  while(!flows.empty()) {
    for(int i = 0; i < tempFlows.size(); i++) {
      if(tempFlows[i].releaseTime <= iter){

        if(currPathPos + 1 < tempFlows[i].path.size()) {
          int currPathPos = flowCount[tempFlows[i].id];
          auto currEdge = std::make_tuple(tempFlows[i].path[currPathPos],
            tempFlows[i].path[currPathPos + 1]);

            if(this->flowMap.count(currEdge) < this->Network.getWeight(std::get<0>(currEdge),
            std::get<1>(currEdge)) + 1) {
              this->flowMap[currEdge] = &(tempFlows[i]);
            }

            else {
              std::cout << "Collision found" << std::endl;
              reroute(&flows[i], currEdge);
              this->flowCount[tempFlows[i].flowID] = 0;
              tempFlows[i].numReroutes++;
            }

            tempFlows[i].finalTime++;
          }

          else {
            std::cout << "This flow has ended" << std::endl;
            this->finishedFlows.push_back(tempFlows[i]);
            tempFlows.erase(tempFlows.begin() + i);
          }
        }
      }
    }
    iter++;
  }
