#include "IPathAdaptor.hpp"
#include <vector>
#include <algorithm>

class MinHopAdaptor : public IPathAdaptor
{
    public:
        MinHopAdaptor();
        std::vector<int> getFlow(Network* net, int start, int end);
        
};