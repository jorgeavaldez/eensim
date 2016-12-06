#include "cortex.hpp"
#include "Network.hpp"
// #include "IPathAdaptor.hpp"
#include "MinHopAdaptor.hpp"

int main(int argc, char* argv[]) {
  std::vector<Network* > networks;
  
  // let's generate 10 random networks
  for (int i = 0; i < 1; i++) {
    Network* n = new Network();
    n->genNet(5);
  
    networks.push_back(n);
  }
  
  // now we're going to create the simulation
  Cortex sim;
  IPathAdaptor* pathAdaptor = new MinHopAdaptor();
  
  // basically, we can change the pathAdaptor, the network sets, and number of
  // flows for a simulation
  for (int i = 0; i < networks.size(); i++) {
    sim.initializeSimulation(networks[i], pathAdaptor, 2);
    sim.startSimulation();
    sim.outputSimulation(std::cout);
  }

  return 0;
}
