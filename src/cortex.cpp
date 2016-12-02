#include "Cortex.hpp"

Cortex::Cortex(){}

void Cortex::initializeSimulation(Network* n, IPathAdaptor adaptor, int fCap){
  network = n;
  fFactory(network, adaptor);
  this->flows = fFactory.getFlowList(0, 1, fCap);
  sortFlows();
}

void Cortex::sortFlows(){
  std::sort(this->flows.begin(), this->flows.end(), [](const Flow& f1, const Flow& f2){
    return f1.totalWeight < f2.totalWeight;
  });
}

void Cortex::reroute(Flow* f){
  //todo(Andrew) need to implement rerouting based on the current adaptor
  std::cout << "lmao" << std::endl;
}

void Cortex::startSimulation(){
  for(int i = 0; i < this->flows.size(); i++){
    
  }
}
