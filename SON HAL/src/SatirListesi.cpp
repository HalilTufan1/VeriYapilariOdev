#include "SatirListesi.hpp"
#include "ListeYazdirma.hpp"


   

    SatirListesiNode *SatirListesi::FindPreviousByPosition(int index)  
    {
        if(index<0||index>size) ;
        SatirListesiNode*prv = head;
        int i=1;
        for(SatirListesiNode*itr= head; i!= index;itr=itr->nx,i++)
        {
            prv = prv->nx;
        }
        return prv;
    }
    //Kurucu fonksiyon
    SatirListesi::SatirListesi()
    {
        head=NULL;
        size=0;
    }
    //eleman sayısı
    int SatirListesi::count()const
    {
        return size;
    }
    //listenin boş olup olmadığının kontrolü
    bool SatirListesi::isEmpty()const
    {
        return size==0;
    }
    //sona eleman ekleme
    void SatirListesi::Add(const int& item)
    {
        Insert(size,item);
    }
    //istenen yere eleman ekleme
    void SatirListesi::Insert(int index,const int& item)
    {
        if(index<0||index>size) cout<<"Belirtilen degerlerde deger giriniz";
        if(index==0)
       {
        head = new SatirListesiNode(item,head);
        if(head->nx != NULL) head->nx->prev = head;
        } 
        else
        {
            SatirListesiNode *prv=FindPreviousByPosition(index);
            prv->nx = new SatirListesiNode(item,prv->nx,prv);
            if(prv->nx->nx !=NULL)
            prv->nx->nx->prev = prv->nx;
        }
        size++;
    }
    //İlk eleman
    const int& SatirListesi::first() 
    {
        if(isEmpty()) cout<<"Belirtilen degerlerde deger giriniz" ;
        return head->data;
    }
       
    //Son eleman
    const int& SatirListesi::last()  
    {
         if(isEmpty()) cout<<"Liste bos"<<endl;
         return head->prev->data; //videodan anlamına bak!!!!!
    }

    //belirtilen elemanın sırasını getirme
     int SatirListesi::indexOf(const int& item)
     {
        int index=0;
        for(SatirListesiNode *itr=head;index<size;itr=itr->nx)
        {
            if(itr->data == item) return index;
        }
        
     }
        
    //sondan eleman silme
    void SatirListesi::remove(const int& item)
    {
        int index = indexOf(item);
        removeAt(index);
    }
    //belirtilen size dan eleman silme
    void SatirListesi::removeAt(int index)
    {
           if (index < 0 || index >= size) cout<<"Belirtilen degerlerde deger giriniz";
    SatirListesiNode *del;
    if (index == 0) {
        del = head;
        head = head->nx;
        if (head != NULL) head->prev = NULL;
    } else {
        SatirListesiNode *prv = FindPreviousByPosition(index);
        del = prv->nx;
        prv->nx = del->nx;
        if (del->nx != NULL)
            del->nx->prev = prv;
    }
    size--;
    delete del;
    }

    //girilen elemanın olup olmadığı kontrol etme
    bool SatirListesi::find(const int& item)
    {
        int index = 0;
        for(SatirListesiNode *itr=head;index<size;itr=itr->nx,index++)
        {
            if(itr->data==item) return true;
        }
        return false;
    }
    //girilen elemanın kaçıncı sırada olduğunu bulma
    const int&  SatirListesi::elementAt(int index) 
    {
        if(index<0||index>size) cout<<"Belirtilen degerlerde deger giriniz"; 
        
            
        
        if(index==0) return head->data;
        return FindPreviousByPosition(index)->nx->data;

    }
    //tüm elemanları siler
    void SatirListesi::clear()
    {
        while(!isEmpty())
        removeAt(0);
    }
    //ekrana yazdırma
    ostream& operator<<(ostream& screen, SatirListesi& right)
    {
        for(SatirListesiNode *itr =right.head; itr !=NULL; itr= itr->nx)
        {
            screen<<itr<<"\n";
            screen<<"----------\n";
            screen<<"|"<<setw(5)<<itr->data<<setw(5)<<"|"<<endl;
            screen<<"----------\n";
            screen<<"|"<<itr->nx<<setw(3)<<"|\n";
            screen<<"----------\n\n";
        }
        screen<< endl;
        return screen;
    }


    //satirlistesi yazdırma
    void SatirListesi::printSatirListesi(int x, int y)
    {
        int yIndex=y;
        ListeYazdirma.gotoxy(x,yIndex);
        cout<<"vvvvvvvvvvv\n";
        for(SatirListesiNode*itr= this->head; itr!=NULL; itr = itr->nx)
        {
            
            ListeYazdirma.gotoxy(x,++yIndex);
            ListeYazdirma.gotoxy(x,++yIndex);
            ListeYazdirma.gotoxy(x,++yIndex);
            cout<<"-----------\n";

            ListeYazdirma.gotoxy(x,++yIndex);
            
            cout<<"|"<< setw(2)<<itr<<setw(2)<<" |\n";


            ListeYazdirma.gotoxy(x,++yIndex);
            cout<<"-----------\n";

            ListeYazdirma.gotoxy(x,++yIndex);
            cout<<"|"<<setw(5)<<itr->data<<setw(5)<<"|"<<endl;

            ListeYazdirma.gotoxy(x,++yIndex);
            cout<<"-----------\n";

            ListeYazdirma.gotoxy(x,++yIndex);
            cout<<"|"<<setw(2)<<itr->nx<<setw(2)<<" |\n";

            ListeYazdirma.gotoxy(x,++yIndex);
            cout<<"-----------\n\n";

        }
        
    }
    //satir listesi yıkıcı fonksiyon
    SatirListesi::~SatirListesi()
    {
        clear();
    }