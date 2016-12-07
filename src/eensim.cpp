#include "cortex.hpp"
#include "Network.hpp"
#include "MinHopAdaptor.hpp"

#include <random>
#include <fstream>

int main(int argc, char* argv[]) {
  // std::vector<Network> networks;

  // std::mt19937 rngeesus;
  // std::uniform_int_distribution<std::mt19937::result_type> randE(40, 100);
  // std::uniform_int_distribution<std::mt19937::result_type> randV(25, 30);

  // let's generate 10 random networks
  // for (int i = 0; i < 1; i++) {
  Network network(2, 1);
  network.genNet(1);
  // networks.push_back(n);
  // }

  // now we're going to create the simulation
  Cortex sim;
  MinHopAdaptor pathAdaptor;

  std::ofstream ofile;
  ofile.open("dump.txt");

  // basically, we can change the pathAdaptor, the network sets, and number of
  // flows for a simulation
  // for (int i = 0; i < networks.size(); i++) {
  std::cout << "Simulation starting up..." << std::endl;
  sim.initializeSimulation(network, pathAdaptor, 10);
  std::cout << "Simulation initialzied." << std::endl;
  sim.startSimulation();
  std::cout << "Simulation completed" << std::endl;
  sim.outputSimulation(ofile);
  ofile.close();
  // }

  return 0;
}
