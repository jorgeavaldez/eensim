#ifndef _CORTEX_HPP
#define _CORTEX_HPP

#include <list>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <tuple>

#include "FlowFactory.hpp"
#include "Network.hpp"

class Cortex{
  private:
    FlowFactory fFactory;
    void sortFlows();
    void reroute(Flow* f);

  public:
    std::vector<Flow> flows;
    std::unordered_map< tuple<int, int>, Flow* > flowMap;
    Network* network;

    Cortex();
    void initializeSimulation(Network* n, IPathAdaptor adaptor, int fCap = 10000);
    void startSimulation();
};

#endif //_CORTEX_HPP
