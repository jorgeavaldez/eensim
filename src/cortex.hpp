#ifndef _CORTEX_HPP
#define _CORTEX_HPP

#include <list>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <limits>

#include "FlowFactory.hpp"
#include "Network.hpp"
#include "IPathAdaptor.hpp"

class Cortex{
  private:
    FlowFactory fFactory;
    IPathAdaptor adaptor;
    void sortFlows();
    void reroute(Flow* f, std::tuple<int, int> edge);

  public:
    std::vector<Flow> flows;
    std::vector<Flow> rerouted;
    std::unordered_map< tuple<int, int>, Flow* > flowMap;
    Network* network;

    Cortex();
    void initializeSimulation(Network* n, IPathAdaptor adaptor, int fCap = 10000);
    void startSimulation();
};

#endif //_CORTEX_HPP
