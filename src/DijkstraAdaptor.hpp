#include "IPathAdaptor.hpp"


class DijkstraAdaptor:public IPathAdaptor
{
    public:
        DijkstraAdaptor();
        Flow getFlow(Network* net, int start, int end);
	virtual ~DijkstraAdaptor(){};



};
