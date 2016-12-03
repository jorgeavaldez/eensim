#include "Network.hpp"

Network::Network(Network& n){
  n.numVerts = v;
  n.numEdges = e;
  n.Net = n.Net;
}

Network::Network(int v, int e){
  this->numVerts = v;
  this->numEdges = e;
  this->Net = new TUndirNet(numVerts, numEdges);
}

void Network::genNet(int ubound){
  //sets up rng stuff
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> dist(1, ubound);

  //creates temp graph to generate the network
  PUNGraph Graph = TSnap::GenRndGnm<PUNGraph>(this->numVerts, this->numEdges, false, TInt::Rnd);

  //copies over nodes
  for(TUNGraph::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++){
    TInt node =  NI.GetId();
    this->Net->AddNode(node);
  }

  //copies over numEdges
  for(TUNGraph::TEdgeI EI = Graph->BegEI(); EI < Graph->EndEI(); EI++){
    TInt src = EI.GetSrcNId();
    TInt dst = EI.GetDstNId();
    this->Net->AddEdge(src, dst);
  }

  //randomly generates and adds numEdges
  for(TUndirNet::TEdgeI EI = this->Net->BegEI(); EI < this->Net->EndEI(); EI++){
    TInt src = EI.GetSrcNId();
    TInt dst = EI.GetDstNId();
    TStr id("weight");
    TInt w = dist(rng);
    this->Net->AddSAttrDatE(src, dst, id, w);
  }
}

void Network::addEdge(int src, int dst){
  this->Net->AddEdge(src, dst);
}

void Network::addEdge(int src, int dst, int w){
  this->Net->AddEdge(src, dst);
  TStr id("weight");
  TInt weight(w);
  this->Net->AddSAttrDatE(src, dst, id, weight);
}

void Network::labelEdge(int src, int dst, int w){
  TStr id("weight");
  TInt weight(w);
  this->Net->AddSAttrDatE(src, dst, id, weight);
}

int Network::getWeight(int src, int dst){
  TInt s(src);
  TInt d(dst);
  TStr id("weight");
  TInt w;
  this->Net->GetSAttrDatE(s, d, id, w);
  return w.Val;
}

std::vector< std::tuple<int, int, int> > Network::listEdges(){
  std::vector< std::tuple<int, int, int> > outVec;
  std::tuple<int, int, int> tempTup;

  for(TUndirNet::TEdgeI EI = this->Net->BegEI(); EI < this->Net->EndEI(); EI++){
    TInt src = EI.GetSrcNId();
    TInt dst = EI.GetDstNId();
    TStr id("weight");
    TInt val;
    this->Net->GetSAttrDatE(src, dst, id, val);
    tempTup = std::make_tuple(src, dst, val.Val);
    outVec.push_back(tempTup);
  }
  return outVec;
}

std::vector<int> Network::listVerts(){
  std::vector<int> outVec;
  for(TUndirNet::TNodeI NI = this->Net->BegNI(); NI < this->Net->EndNI(); NI++){
    TInt id = NI.GetId();
    outVec.push_back(id);
  }
  return outVec;
}

void Network::addVert(int v){
  this->Net->AddNode(v);
}

std::vector<int> Network::getConnectedVerts(int v){
  std::vector<int> outVec;
  auto node = Net->GetNI(v);
  for(int i = 0; i < node.GetDeg(); i++)
    outVec.push_back(node.GetOutNId(i));
  return outVec;
}

void Network::makeGviz(std::string fName, std::string gName = "", bool weights){
  fName = fName + ".gif";
  TStr file(fName.c_str());
  TStr graph(gName.c_str());
  if(weights)
    TSnap::DrawGViz2(this->Net, TGVizLayout(0), file, graph, true, true);
  else
    TSnap::DrawGViz(this->Net, TGVizLayout(0), file, graph, true);
}

Network Network::getBFS(int start){
  PNGraph temptree = TSnap::GetBfsTree(this->Net, start, true, false);
  Network outNet(temptree->GetNodes(), temptree->GetEdges());

  for(TNGraph::TNodeI NI = temptree->BegNI(); NI < temptree->EndNI(); NI++){
    TInt node =  NI.GetId();
    outNet.addVert(node);
  }

  for(TNGraph::TEdgeI EI = temptree->BegEI(); EI < temptree->EndEI(); EI++){
    TInt src = EI.GetSrcNId();
    TInt dst = EI.GetDstNId();
    TStr id("weight");
    TInt w;
    this->Net->GetSAttrDatE(src, dst, id, w);
    outNet.addEdge(src, dst, w);
  }
  return outNet;
}

void Network::printEdges(){
  for(TUndirNet::TEdgeI EI = this->Net->BegEI(); EI < this->Net->EndEI(); EI++){
    TInt src = EI.GetSrcNId();
    TInt dst = EI.GetDstNId();
    TStr id("weight");
    TInt val;
    this->Net->GetSAttrDatE(src, dst, id, val);
    printf("edge: %d--%d,  %s: %d.\n", src, dst, id.CStr(), val.Val);
  }
}

void Network::printVerts(){
  for (TUndirNet::TNodeI NI = this->Net->BegNI(); NI < this->Net->EndNI(); NI++)
    printf("id: %d, degree: %d \n", NI.GetId(), NI.GetOutDeg(), NI.GetInDeg());
}

// Network Network::getShortestPath(int src, int dst){
//   Network tempnet;
//   //todo
// }

int Network::randVert(){
  return Net->GetRndNId();
}

std::tuple<int, int, int> Network::randEdge(){
  int src = randVert();
  std::vector<int> connVerts = getConnectedVerts(src);
  std::tuple<int, int, int> outTup;
  int dst = connVerts[rand() % connVerts.size()];
  int w = getWeight(src, dst);
  outTup = std::make_tuple(src, dst, w);
  return outTup;
}
