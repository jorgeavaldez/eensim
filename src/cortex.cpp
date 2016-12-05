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
  if (!this->flowCount.empty()) this->flowCount.clear();
  if (!this->flowMap.empty()) this->flowMap.clear();
  this->network = n;
  this->adaptor = a;
  Factory(network, adaptor);
  this->flows = fFactory.getFlowList(0, 1, fCap);
  sortFlows();
}


void Cortex::simulate(vector<Flow> v){
  vector<Flow> rerouted;

  for(int i = 0; i < v.size(); i++) {
    this->flowCount[v[i].flowID] = 0;
  }

  int iter = 0;

  while(!v.empty()) {
    for(int i = 0; i < v.size(); i++) {
      if(v[i].releaseTime <= iter){

        if(currPathPos + 1 < v[i].path.size()) {
          int currPathPos = flowCount[v[i].id];
          auto currEdge = std::make_tuple(v[i].path[currPathPos],
            v[i].path[currPathPos + 1]);

            if(this->flowMap.count(currEdge) < this->Network.getWeight(std::get<0>(currEdge),
            std::get<1>(currEdge)) + 1) {
              this->flowMap[currEdge] = &(v[i]);
            }

            else {
              std::cout << "Collision found" << std::endl;
              reroute(&flows[i], currEdge);
              this->flowCount[v[i].flowID] = 0;
              v[i].numReroutes++;
              rerouted.push_back(v[i]);
              v.erase(v.begin() + i);
            }

            v[i].finalTime++;

            if(!rerouted.empty()){
              for(auto flow: rerouted) { flow.waitTime++; };
            }
          }

          else {
            std::cout << "This flow has ended" << std::endl;
            this->finishedFlows.push_back(v[i]);
            v.erase(v.begin() + i);
          }
        }
      }
    }
    iter++;

    if(!rerouted.empty()) simulate(rerouted);
}

void Cortex::startSimulation() {
  simulate(this->flows);
}

void Cortex::outputSimulation(){

}
