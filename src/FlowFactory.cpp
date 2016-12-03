#include "FlowFactory.hpp"

FlowFactory::FlowFactory(int fCap, Network* n){
  this->flowCap = fCap;
  this->net = n;
  this->rngeesus.seed(std::random_device()());
}

Flow FlowFactory::getRandomFlow(int rTimeUB, int nPacketUB){
  // std::uniform_int_distribution<std::mt19937::result_type> tDist(0, rTimeUB);
  std::uniform_int_distribution<std::mt19937::result_type> nPDist(1, nPacketUB);
  Flow f = initializeFlow(0, nPDist(this->rngeesus));
  return f;
}

Flow FlowFactory::getFlow(int rTime, int nPackets){
  Flow f = initializeFlow(rTime, nPackets);
  return f;
}

std::vector<Flow> FlowFactory::getFlowList(int rTimeUB, int nPacketUB, int nFlows){
  std::vector<Flow> outVec;
  // std::uniform_int_distribution<std::mt19937::result_type> tDist(0, rTimeUB);
  std::uniform_int_distribution<std::mt19937::result_type> nPDist(1, nPacketUB);

  for(int i = 0; i < nFlows; i++){
    Flow tempF = initializeFlow(0, nPDist(this->rngeesus));
    outVec.push_back(tempF);
  }
  return outVec;
}

Flow FlowFactory::initializeFlow(int rTime, int nPackets){
  if (this->sourceNodeId == -1 && this->sourceNodeId == -1){
    int srcNode = net->randVert();
    int dstNode;
  }

  while(srcNode == dstNode)
    dstNode = net->randVert();

  Flow f(flowCount, 0, nPackets, srcNode, dstNode);
  return f;
}
