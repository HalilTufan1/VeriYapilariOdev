#ifndef YONETICILISTESINODE_HPP
#define YONETICILISTESINODE_HPP

#include "SatirListesi.hpp"


class YoneticiListesiNode 
{
    public:
        SatirListesi *data;
        double average;
        YoneticiListesiNode *nx;
        YoneticiListesiNode *prev;

        YoneticiListesiNode(SatirListesi *data, YoneticiListesiNode *nx, YoneticiListesiNode *prev);
        YoneticiListesiNode(SatirListesi *data, YoneticiListesiNode *nx);
        YoneticiListesiNode(SatirListesi *data);
        double calculateAverage();


};
#endif