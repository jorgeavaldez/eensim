#include "IPathAdaptor.hpp"
#include <vector>

public class DijkstraAdaptor extends IPathAdaptor
{
    public:
        DijkstraAdaptor();
        std::vector<int> getFlow(Network* net, int start, int end);
}
