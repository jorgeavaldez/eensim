#ifndef _MINHOPADAPTOR_HPP
#define _MINHOPADAPTOR_HPP


#include <vector>
#include <algorithm>
#include <iostream>

#include "Network.hpp"

class MinHopAdaptor
{
    public:
      MinHopAdaptor() {};
      std::vector<int> getFlow(Network net, int start, int end);
      int chooseNextNode(std::vector<std::tuple<int, int> > weights, std::vector<int> visited);
};

#endif //_MINHOPADAPTOR_HPP
