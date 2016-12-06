#ifndef _IPATHADAPTOR_HPP
#define _IPATHADAPTOR_HPP

#include "Network.hpp"
#include <vector>

class IPathAdaptor{
  public:
    IPathAdaptor() {};
    //IPathAdaptor(Network* n, Node* startNode, Node* endNode);

    virtual std::vector<int> getFlow(Network*, int, int) = 0;

    virtual ~IPathAdaptor() {};
};

#endif //_IPATHADAPTOR_HPP
