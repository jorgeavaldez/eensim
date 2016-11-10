#ifndef _FLOWFACTORY_HPP
#define _FLOWFACTORY_HPP

#include "Network.hpp"
#include "Flow.hpp"

class FlowFactory {
  public:
    static int flowCount = 0;
    const static int flowCap;

    static int sourceNodeId = -1;
    static int endNodeId = -1;

    Network* net;

    FlowFactory(int fCap = 10000, Network* n);

    Flow getRandomFlow(int rTimeUB = 0, int nPacketUB = 10);

    Flow getFlow(int rTime, int nPackets);

    std::vector<Flow> getFlowList(int rTimeUB = 0, int nPacketUB = 10, int nFlows = 10000);

  private:
    Flow initializeFlow(int rTime, int nPackets);
    std::mt19937 rng;
};

#endif //_FLOWFACTORY_HPP
