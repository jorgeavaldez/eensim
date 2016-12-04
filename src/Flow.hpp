#ifndef _FLOW_HPP
#define _FLOW_HPP

#include <vector>

public struct Flow{
   public int flowID;
   public int releaseTime;
   public int finalTime;
   public int waitTime;
   public int numPackets;
   public int startNodeID;
   public int endNodeID;
   public int numReroutes; //this attribute is to multiply by our "cost" of reroute at the end to calculate slowdown
   public double slowdown;
   public int totalWeight;
   public vector<int> path;

   public Flow(int id, int releaseT, int numPacks, int startID, int endID,
     vector<int> p)
   {
     //inputs
     flowID = id;
     releaseTime = releaseT;
     numPackets = numPacks;
     startNodeID = startID;
     endNodeID = endID;
     path = p;

     //initialize everything else to 0 cuz im tired
     numReroutes = 0;
     finalTime = 0;
     waitTime = 0;
     slowdown = 0.0;
   }
};

#endif //_FLOW_HPP
