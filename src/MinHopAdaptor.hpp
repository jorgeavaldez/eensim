#include "IPathAdaptor.hpp"
#include <vector>
#include <algorithm>

class MinHopAdaptor : public IPathAdaptor
{
    public:
      MinHopAdaptor();
      std::vector<int> getFlow(Network* net, int start, int end);
      int chooseNextNode(std::vector<std::tuple<int, int> > weights, std::vector<int> visited);    
};
