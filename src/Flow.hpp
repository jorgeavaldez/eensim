#ifndef _FLOW_HPP
#define _FLOW_HPP

#include <vector>

struct Flow {
public:
   int flowID;
   int releaseTime;
   int finalTime;
   int waitTime;
   int numPackets;
   int startNodeID;
   int endNodeID;
   int numReroutes; //this attribute is to multiply by our "cost" of reroute at the end to calculate slowdown
   double slowdown;
   int totalWeight;
   std::vector<int> path;

   Flow(){};
   Flow(int id, int releaseT, int numPacks, int startID, int endID) {
     //inputs
     flowID = id;
     releaseTime = releaseT;
     numPackets = numPacks;
     startNodeID = startID;
     endNodeID = endID;

     //initialize everything else to 0 cuz im tired
     numReroutes = 0;
     finalTime = 0;
     waitTime = 0;
     slowdown = 0.0;
   }
};

#endif //_FLOW_HPP
