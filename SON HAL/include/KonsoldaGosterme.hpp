#ifndef KONSOLDAGOSTERME_HPP
#define KONSOLDAGOSTERME_HPP

#include "YoneticiListesi.hpp"
#include "SatirListesi.hpp"


#define DisplayperOnePage 8
#define BeginOffset 0

enum Yon
{
    up=0,
    down=1,
    refresh=2,
};
enum SayfaYon
{
    upPage=0,
    downPage=1,
};

class KonsoldaGosterme
{
    private:
    YoneticiListesi *yonetici;
    int state;
    int beginOffset;
    int finishOffset;

    void setOffsets();

    public:
    void setState(Yon dr);
    void SetPage(SayfaYon prd);


    KonsoldaGosterme(YoneticiListesi* yonetici);

    void printYoneticiListesi();

    void printSelectedSatirListesi(int x, int y);

    int DisplayRandomSelectedNode();

    void DeleteYoneticiListesiNode();

    void DeleteRandomSelectedNode(int randomIndex);

};

#endif