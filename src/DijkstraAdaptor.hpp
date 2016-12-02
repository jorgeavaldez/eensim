#include "IPathAdaptor.hpp"


public class DijkstraAdaptor extends IPathAdaptor
{
    public:
        DijkstraAdaptor();
        Flow getFlow(Network* net, int start, int end);
	virtual DijkstraAdaptr(){};



}
