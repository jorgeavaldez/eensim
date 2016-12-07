#ifndef _EDGESTATE_HPP
#define _EDGESTATE_HPP

#include <vector>
#include <tuple>
#include "Flow.hpp"

struct EdgeState{
  std::vector<Flow> flows;
  int totalBandwidth;
  std::tuple<int, int> edgeID;

  EdgeState(){
    flows = std::vector<Flow>();
  }

  EdgeState(std::vector<Flow> f, int tBand, std::tuple<int, int> eID){
    flows = f;
    totalBandwidth = tBand;
    edgeID = eID;
  }

  EdgeState(const EdgeState& e){
    flows = e.flows;
    totalBandwidth = e.totalBandwidth;
    edgeID = e.edgeID;
  }

  void operator= (EdgeState& e){
    flows = e.flows;
    totalBandwidth = e.totalBandwidth;
    edgeID = e.edgeID;
  }
};

#endif //_EDGESTATE_HPP
