#ifndef _FLOW_HPP
#define _FLOW_HPP

public struct Flow{
   public int flowID;
   public int releaseTime;
   public int finalTime;
   public int waitTime;
   public int numPackets;
   public int startNodeID;
   public int endNodeID;
   public double slowdown;

   public Flow(int id, int releaseT, int numPacks, int startID, int endID)
   {
     //inputs
     flowID = id;
     releastTime = releaseT;
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
