#ifndef _FLOWFACTORY_HPP
#define _FLOWFACTORY_HPP

#include "Network.hpp"
#include "Flow.hpp"

class FlowFactory {
  public:
    static int flowCount = 0;
    const static int flowCap;
    Network* net;

    FlowFactory(fCap = 10000, Network* n);

    Flow getRandomFlow(int rTimeUB = 0, int nPacketUB = 10);

    Flow getFlow(int rTime, int nPackets);

    std::vector getFlowList(int rTimeUB, int nPacketUB, int nFlows);

  private:
    Flow initializeFlow(int rTime, int nPackets);

};

#endif
