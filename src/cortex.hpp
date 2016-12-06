#ifndef _CORTEX_HPP
#define _CORTEX_HPP

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <limits>
#include <string>

#include "FlowFactory.hpp"
#include "Flow.hpp"
#include "Network.hpp"
#include "MinHopAdaptor.hpp"

class Cortex{
  private:
    FlowFactory fFactory;
    //IPathAdaptor* adaptor;
    MinHopAdaptor adaptor;
    // void sortFlows();
    void reroute(Flow* f, std::tuple<int, int> edge);
    void simulate(std::vector<Flow> v);
    int hash(std::tuple<int, int> t);

  public:
    std::vector<Flow> flows;
    std::vector<Flow> finishedFlows;
    std::unordered_map<int, Flow*> flowMap;
    std::unordered_map<int, int> flowCount;
    Network network;

    Cortex();
    void initializeSimulation(Network n, MinHopAdaptor adaptor, int fCap = 10000);
    void startSimulation();
    void outputSimulation(std::ostream& os);
};

#endif //_CORTEX_HPP
