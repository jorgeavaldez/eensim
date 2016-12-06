#ifndef _CORTEX_HPP
#define _CORTEX_HPP

#include <list>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <limits>
#include <vector>

#include "FlowFactory.hpp"
#include "Flow.hpp"
#include "IPathAdaptor.hpp"

class Cortex{
  private:

    void sortFlows();
    void reroute(Flow* f, std::tuple<int, int> edge);
    void simulate(std::vector<Flow> v);
    int hash(std::tuple<int, int> t);

  public:
    std::vector<Flow> flows;
    std::vector<Flow> finishedFlows;
    std::unordered_map<int, Flow*> flowMap;
    std::unordered_map<int, int> flowCount;
    Network* network;
    FlowFactory* fFactory;
    IPathAdaptor* adaptor;

    Cortex();
    void initializeSimulation(Network* n, IPathAdaptor* adaptor, int fCap = 10000);
    void startSimulation();
    void outputSimulation(std::ostream& os);
};

#endif //_CORTEX_HPP
