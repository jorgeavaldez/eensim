#include "cortex.hpp"

Cortex::Cortex(){} //default constructor. all the stuff actually gets handled in
//initializeSimulation

int Cortex::hash(std::tuple<int, int> t){
  int a, b;
  std::tie(a, b) = t;
  return a + 0x9e3779b9 + (b<<6) + (b>>2); //fuck c++
}

// void Cortex::sortFlows() { //magic lambda bullshit to sort flows
//   std::sort(this->flows.begin(), this->flows.end(), [](Flow f1, Flow f2) {
//     return f1.totalWeight < f2.totalWeight;
//   });
// }

void Cortex::reroute(Flow& f, std::tuple<int, int> edge){ //finds new paths for flows
  Network tempNet(this->network);
  int src, dst;
  std::tie(src, dst) = edge;
  tempNet.labelEdge(src, dst, 0);
  f.path = this->adaptor.getFlow(tempNet, f.startNodeID, f.endNodeID);
}

void Cortex::initializeSimulation(Network n, MinHopAdaptor a, int fCap) { //initializes simulation vars
  if (!this->flowCount.empty()) this->flowCount.clear(); //clears flowCount from previous sims
  if (!this->flowMap.empty()) this->flowMap.clear(); //clears flowMap from previous sims
  this->network = n;
  this->adaptor = a;
  fFactory = FlowFactory(network, adaptor);
  this->flows = fFactory.getFlowList(0, 1, fCap);
  // sortFlows();
}


void Cortex::simulate(std::vector<Flow> v){ //simulates
  std::vector<Flow> rerouted; //sets up vector of flows to route after the main simulation

  for(int i = 0; i < v.size(); i++) { //sets up hash map to keep track where each flow is in its path
    this->flowCount[v[i].flowID] = 0;
  }

  for(auto e : this->network.listEdges()){
    int src, dst, band;
    std::tie(src, dst, band) = e;
    EdgeState es;
    es.totalBandwidth = band;
    es.edgeID = std::make_tuple(src, dst);
    this->flowMap[hash(es.edgeID)] = es;
  }

  int iter = 0; //counts current iteration of simulation, used for starting flows
  //at their release time
  while(!v.empty()) { //while there are flows

    for(int i = 0; i < v.size(); i++) { //for all flows
      //std::cout << v[i].flowID << "," << v[i].releaseTime << "," << v[i].waitTime << "," << v[i].numReroutes;
      //std::cout << "," << v[i].startNodeID << "," << v[i].endNodeID << "," << v[i].slowdown << std::endl;
      if(v[i].releaseTime <= iter){ //if they have been released
        int currPathPos = flowCount[v[i].flowID]; //finds where they are on their path
        if(currPathPos + 1 < v[i].path.size()) { //if they are still being simulated

          auto currEdge = std::make_tuple(v[i].path[currPathPos], v[i].path[currPathPos + 1]); //current edge the flow is on

          v[i].finalTime += 1; //obv
          if(this->flowMap[hash(currEdge)].flows.size() < this->flowMap[hash(currEdge)].totalBandwidth)
          {
            this->flowMap[hash(currEdge)].flows.push_back(v[i]);
            this->flowCount[v[i].flowID]++;
          }
          else
          {
            //std::cout << "Collision found" << std::endl;
            reroute(v[i], currEdge); //gives the flow a new path
            this->flowCount[v[i].flowID] = 0; //resets the positon on path
            v[i].numReroutes++; //obv
            v[i].releaseTime = 0; //so that doesn't have to deal with release time on reroute
            rerouted.push_back(v[i]);
            v.erase(v.begin() + i);
          }

          // std::cout << "Finaltime " <<  v[i].finalTime << std::endl;
          if(!rerouted.empty()){
            for(auto& flow: rerouted) { flow.waitTime++; }; //increases rerouted flows wait time until they are put onto network
          }

        }

        else {
          // std::cout << "This flow has ended" << std::endl;
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
  os << "FlowID,releaseTime,finalTime,waitTime,numReroutes,startNodeID,endNodeID,slowdown" << std::endl;
  for(auto f : finishedFlows){
    f.slowdown = (f.finalTime + f.waitTime) / f.numPackets;
    os << f.flowID << "," << f.releaseTime << "," << f.finalTime << ","<< f.waitTime << "," << f.numReroutes;
    os << "," << f.startNodeID << "," << f.endNodeID << "," << f.slowdown << std::endl;
  }
}
