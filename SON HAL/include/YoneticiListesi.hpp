#ifndef YONETICILISTESI_HPP
#define  YONETICILISTESI_HPP

#include <iostream>

#include "SatirListesi.hpp"
#include "YoneticiListesiNode.hpp"
#include <stdlib.h>
#include <time.h>
#include "ListeYazdirma.hpp"


class YoneticiListesi 
{
    private:
        YoneticiListesiNode *head;
        int size;

        YoneticiListesiNode* FindPreviousByPosition(int index) ;
       

        YoneticiListesiNode* FindPosition(int index) ;
        

    public:

        YoneticiListesi();

        int count()const;

        bool isEmpty()const;

        void Add(SatirListesi*& item);

        void Insert(int index,SatirListesi*& item);

        SatirListesi*&  first() ;
        

        SatirListesi*&  last() ;
        

        int indexOf(SatirListesi*& item) ;
        

        void remove(SatirListesi*& item);

        void randomRemoveAtSatirListesi(int index, int inLineIndex);
       

        void CalculateAverage(int index);

        int randomGenerator(int index) ;
        

        void removeAt(int index);

        void moveNode(int from, int to) ;
       

        bool find(SatirListesi*& item);
        
        void sortByAverage();

        SatirListesi*& elementAt(int index) ;
       

        void clear();

        void printIndex(int index, int x, int y);

        ~YoneticiListesi();

};
#endif