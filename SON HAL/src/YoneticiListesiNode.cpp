#include "YoneticiListesiNode.hpp"


YoneticiListesiNode::YoneticiListesiNode(SatirListesi* data, YoneticiListesiNode *nx, YoneticiListesiNode*prev)
{
this->data=data;
this->prev=prev;
this->nx=nx;
this->average = calculateAverage();
}
YoneticiListesiNode::YoneticiListesiNode(SatirListesi* data, YoneticiListesiNode *nx)
{
this->data=data;
this->prev=prev;
this->nx=nx;
this->average = calculateAverage();
}
YoneticiListesiNode::YoneticiListesiNode(SatirListesi* data)
{
this->data=data;
this->prev=prev;
this->nx=nx;
this->average = calculateAverage();
}

double YoneticiListesiNode::calculateAverage()
{
    double total = 0;
    if(this->data->isEmpty()) 
    return total;

    int count = this->data->count();
    for(int i =0; i<count;i++)
    {
        total += this->data->elementAt(i);
    }
    return total/count;
    
}
