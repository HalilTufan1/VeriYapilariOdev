#include "SatirListesiNode.hpp"


SatirListesiNode::SatirListesiNode(const int data, SatirListesiNode *nx, SatirListesiNode *prev)
{
this->data=data;
this->prev=prev;
this->nx=nx;
}

SatirListesiNode::SatirListesiNode(const int data, SatirListesiNode *nx)
{
this->data=data;
this->prev=prev;
this->nx=nx;
}

SatirListesiNode::SatirListesiNode(const int data)
{
this->data=data;
this->prev=prev;
this->nx=nx;
}