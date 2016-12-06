#ifndef _MINHOPADAPTOR_HPP
#define _MINHOPADAPTOR_HPP

#include "IPathAdaptor.hpp"
#include <vector>
#include <algorithm>

class MinHopAdaptor : public IPathAdaptor
{
    public:
      MinHopAdaptor();
      std::vector<int> getFlow(Network* net, int start, int end);
      int chooseNextNode(std::vector<std::tuple<int, int> > weights, std::vector<int> visited);
      ~MinHopAdaptor();
};

#endif //_MINHOPADAPTOR_HPP
