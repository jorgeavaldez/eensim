#include "IPathAdaptor.hpp"
#include <vector>

class DijkstraAdaptor : public IPathAdaptor
{
    public:
        DijkstraAdaptor();
        std::vector<int> getFlow(Network* net, int start, int end);
	int chooseNextNode(std::vector<std::tuple<int, int> > weights, std::vector<int> visited);
};
