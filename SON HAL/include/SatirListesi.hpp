#ifndef SATIRLISTESI_HPP
#define SATIRLISTESI_HPP



#include "SatirListesiNode.hpp"
#include <iomanip>


class SatirListesi
{
    private:
        SatirListesiNode *head;
        int size;

        SatirListesiNode *FindPreviousByPosition(int index);
        
    
    public:
        SatirListesi();

        int count()const;

        bool isEmpty()const;

        void Add(const int& item);

        void Insert(int index,const int& item);

        const int& first() ;


        const int& last();
        

        int indexOf(const int& item); 
       

        void remove(const int& item);

        void removeAt(int index);

        bool find(const int& item);

        const int&  elementAt(int index) ;
      

        void clear();

        friend ostream& operator<<(ostream& screen, SatirListesi& right);

        void printNodeFromPositionInReverseOrder(int index) ;
      

        void printReverseOrder();

        void printSatirListesi(int x, int y);

        ~SatirListesi();

};
#endif
