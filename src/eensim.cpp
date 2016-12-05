#include "cortex.hpp"
#include "Network.hpp"
#include "IPathAdaptor.hpp"

int main(int argc, char* argv[]) {
  vector<Network *> networks;

  // let's generate 10 random networks
  for (int i = 0; i < 10; i++) {
    Network* n = new Network();
    n->genNet(5);

    networks.push_back(n);
  }

  // now we're going to create the simulation
  Cortex sim;
  IPathAdaptor pathAdaptor;
  
  // basically, we can change the pathAdaptor, the network sets, and number of
  // flows for a simulation
  for (int i = 0; i < networks.size(); i++) {
    sim.initializeSimulation(networks[i], pathAdaptor, 5);
    sim.startSimulation();
  } 

  return 0;
}
