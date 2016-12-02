#ifndef _FLOW_HPP
#define _FLOW_HPP

struct Flow{
   public:
      int flowID;
      int releaseTime;
      int finalTime;
      int waitTime;
      int numPackets;
      int startNodeID;
      int endNodeID;
      double slowdown;

      Flow(int id, int releaseT, int numPacks, int startID, int endID, std::vector<int> p)
      {
      //inputs
      flowID = id;
      releaseTime = releaseT;
      numPackets = numPacks;
      startNodeID = startID;
      endNodeID = endID;
      this.path = p;

      //initialize everything else to 0 cuz im tired
      finalTime = 0;
      waitTime = 0;
      slowdown = 0.0;
      }

      std::vector<int> getPath(){
	return this.path;
      }

      void setPath(std::vector<int> p){
	this.path = p;
      }

   private:
      std::vector<int> path;
};

#endif //_FLOW_HPP
