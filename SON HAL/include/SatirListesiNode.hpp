#ifndef SATIRLISTESINODE_HPP
#define SATIRLISTESINODE_HPP



#include <iostream>
using namespace std;

class SatirListesiNode
{
    public:
        int data;
        SatirListesiNode *nx;
        SatirListesiNode *prev;

        SatirListesiNode(const int data, SatirListesiNode *nx, SatirListesiNode *prev);
        SatirListesiNode(const int data, SatirListesiNode *nx);
        SatirListesiNode(const int data);
};
#endif