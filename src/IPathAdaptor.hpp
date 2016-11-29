#ifndef _IPATHADAPTOR_HPP
#define _IPATHADAPTOR_HPP

#include "Flow.hpp"
#include "Network.hpp"

class IPathAdaptor{
  public:
    IPathAdaptor();

    virtual Flow getFlow(Network*, int, int) = 0;

    virtual ~IPathAdaptor() {};
};

#endif //_IPATHADAPTOR_HPP
