#include "Cortex.hpp"

Cortex::Cortex(){} //default constructor. all the stuff actually gets handled in
//initializeSimulation

void Cortex::sortFlows() { //magic lambda bullshit to sort flows
  std::sort(this->flows.begin(), this->flows.end(), [](Flow f1, Flow f2) {
    return f1.totalWeight < f2.totalWeight;
  });
}

void Cortex::reroute(Flow* f, std::tuple<int, int> edge){ //finds new paths for flows
  Network tempNet(*(this->network));
  int src, dst;
  std::tie(src, dst) = edge;
  tempNet.labelEdge(src, dst, std::numeric_limits<int>::max());
  f->path = this->adaptor->getFlow(*tempNet, f->startNodeID, f->endNodeID);
}

void Cortex::initializeSimulation(Network* n, IPathAdaptor* a, int fCap) { //initializes simulation vars
  if (!this->flowCount.empty()) this->flowCount.clear(); //clears flowCount from previous sims
  if (!this->flowMap.empty()) this->flowMap.clear(); //clears flowMap from previous sims
  this->network = n;
  this->adaptor = a;
  fFactory = FlowFactory(network, adaptor);
  this->flows = fFactory.getFlowList(0, 1, fCap);
  sortFlows();
}


void Cortex::simulate(std::vector<Flow> v){ //simulates
  std::vector<Flow> rerouted; //sets up vector of flows to route after the main simulation

  for(int i = 0; i < v.size(); i++) { //sets up hash map to keep track where each flow is in its path
    this->flowCount[v[i].flowID] = 0;
  }

  int iter = 0; //counts current iteration of simulation, used for starting flows
  //at their release time

  while(!v.empty()) { //while there are flows
    for(int i = 0; i < v.size(); i++) { //for all flows
      if(v[i].releaseTime <= iter){ //if they have been released

        // TODO: wtf is currPathPos? declare it
        if(currPathPos + 1 < v[i].path.size()) { //if they are still being simulated
          int currPathPos = flowCount[v[i].flowID]; //finds where they are on their path
          auto currEdge = std::make_tuple(v[i].path[currPathPos],
            v[i].path[currPathPos + 1]); //current edge the flow is on

            if(this->flowMap.count(currEdge) < this->network->getWeight(std::get<0>(currEdge),
            std::get<1>(currEdge)) + 1) {
              this->flowMap[currEdge] = &(v[i]); //puts flow on map if there is enough bandwidth for it
            }

            else {
              std::cout << "Collision found" << std::endl;
              reroute(&flows[i], currEdge); //gives the flow a new path
              this->flowCount[v[i].flowID] = 0; //resets the positon on path
              v[i].numReroutes++; //obv
              v[i].releaseTime = 0; //so that doesn't have to deal with release time on reroute
              rerouted.push_back(v[i]);
              v.erase(v.begin() + i);
            }

            v[i].finalTime++; //obv

            if(!rerouted.empty()){
              for(auto flow: rerouted) { flow.waitTime++; }; //increases rerouted flows wait time until they are put onto network
            }
          }

          else {
            std::cout << "This flow has ended" << std::endl;
            this->finishedFlows.push_back(v[i]); //this is where we pull our finished flows from for data
            v.erase(v.begin() + i);
          }
        }
      }
    }
    iter++;

    if(!rerouted.empty()) simulate(rerouted); //reruns any flows that were stopped
}

void Cortex::startSimulation() { //starts the simulation
  simulate(this->flows);
}

void Cortex::outputSimulation(std::ostream& os){
  //todo (Andrew): make csv dump
  os << "this finished." << std::endl;
}
