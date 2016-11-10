#ifndef _FLOW_HPP
#define _FLOW_HPP

struct Flow{
  int flowID;
  int releaseTime;
  int finalTime;
  int waitTime;
  int numPackets;
  int startNodeID;
  int endNodeID;
  double slowdown;

  Flow(int id, int releaseT, int numPacks, int startID, int endID)
  {
    //inputs
    flowID = id;
    releaseTime = releaseT;
    numPackets = numPacks;
    startNodeID = startID;
    endNodeID = endID;

    //initialize everything else to 0 cuz im tired
    finalTime = 0;
    waitTime = 0;
    slowdown = 0.0;
  }
};

#endif //_FLOW_HPP
