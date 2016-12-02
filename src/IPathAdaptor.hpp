#ifndef _IPATHADAPTOR_HPP
#define _IPATHADAPTOR_HPP

#include "Flow.hpp"
#include "Network.hpp"

class IPathAdaptor{
  public:
    IPathAdaptor();

    //IPathAdaptor(Network* n, Node* startNode, Node* endNode);

    virtual Flow getFlow(Network*, int, int) = 0;

    virtual ~IPathAdaptor() {};
};

#endif //_IPATHADAPTOR_HPP
