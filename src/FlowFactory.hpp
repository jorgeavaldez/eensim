#ifndef _FLOWFACTORY_HPP
#define _FLOWFACTORY_HPP

#include "Network.hpp"
#include "Flow.hpp"
#include "MinHopAdaptor.hpp"

#include <string>
#include <iostream>

class FlowFactory {
  public:
    int flowCount;
    int flowCap;

    int sourceNodeId;
    int endNodeId;

    Network net;

    FlowFactory();
    FlowFactory(Network n, int fCap = 10000);
    FlowFactory(Network n, MinHopAdaptor adaptor, int fCap = 10000);

    Flow getRandomFlow(int rTimeUB = 0, int nPacketUB = 10);

    Flow getFlow(int rTime, int nPackets);

    std::vector<Flow> getFlowList(int rTimeUB = 0, int nPacketUB = 10,
      int nFlows = 10000);

    // void setPathAdaptor(MinHopAdaptor adaptor);

  private:
    Flow initializeFlow(int rTime, int nPackets);
    std::mt19937 rngeesus;

    MinHopAdaptor pathGenerator;
};

#endif //_FLOWFACTORY_HPP
