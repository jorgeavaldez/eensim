#include "cortex.hpp"
#include "Network.hpp"
// #include "IPathAdaptor.hpp"
#include "MinHopAdaptor.hpp"

int main(int argc, char* argv[]) {
  std::vector<Network* > networks;
<<<<<<< HEAD
  
=======

>>>>>>> 80d694b188b07a188f3a9849f9405ada8bce780c
  // let's generate 10 random networks
  for (int i = 0; i < 1; i++) {
    Network* n = new Network();
    n->genNet(5);
<<<<<<< HEAD
  
    networks.push_back(n);
  }
  
  // now we're going to create the simulation
  Cortex sim;
  IPathAdaptor* pathAdaptor = new MinHopAdaptor();
  
=======

    networks.push_back(n);
  }

  // now we're going to create the simulation
  Cortex sim;
  IPathAdaptor* pathAdaptor = new MinHopAdaptor();

>>>>>>> 80d694b188b07a188f3a9849f9405ada8bce780c
  // basically, we can change the pathAdaptor, the network sets, and number of
  // flows for a simulation
  for (int i = 0; i < networks.size(); i++) {
    sim.initializeSimulation(networks[i], pathAdaptor, 2);
    sim.startSimulation();
    sim.outputSimulation(std::cout);
  }

  return 0;
}
