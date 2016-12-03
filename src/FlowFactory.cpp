#include "FlowFactory.hpp"

FlowFactory::FlowFactory(Network* n, int fCap){
  this->flowCap = fCap;
  this->net = n;
  this->rngeesus.seed(std::random_device()());
  this->flowCount = 0;
  this->sourceNodeId = -1;
  this->endNodeId = -1;
}

FlowFactory::FlowFactory(Network* n, IPathAdaptor adaptor, int fCap){
  this->flowCap = fCap;
  this->net = n;
  this->rngeesus.seed(std::random_device()());
  this->flowCount = 0;
  this->sourceNodeId = -1;
  this->endNodeId = -1;
  this->pathGenerator = adaptor;
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

void FlowFactory::setPathAdaptor(IPathAdaptor adaptor) {
  this->pathGenerator = adaptor;
}

Flow FlowFactory::initializeFlow(int rTime, int nPackets){
  if (this->sourceNodeId == -1 && this->sourceNodeId == -1){
    int srcNode = net->randVert();
    int dstNode;
  }

  while(srcNode == dstNode)
    dstNode = net->randVert();

  // add the path as a vector of int at the end
  // that should come from the path adaptor, then we can sum up the cumulative
  // weights and set f.totalWeight to the cumulative sum
  Flow f(flowCount, 0, nPackets, srcNode, dstNode);

  f.path = this->pathGenerator(this->net, srcNode, dstNode);

  return f;
}
