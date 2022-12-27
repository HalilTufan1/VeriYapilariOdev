#include "YoneticiListesi.hpp"
#include "SatirListesi.hpp"
//Bir önceki elemanı bulma
YoneticiListesiNode* YoneticiListesi::FindPreviousByPosition(int index) 
{
    if(index<0||index>size) cout<<"Belirtilen degerlerde deger giriniz";
    YoneticiListesiNode *prev=head;
    int i = 1;
    for(YoneticiListesiNode*itr=head; itr->nx !=NULL && i != index;itr=itr->nx,i++)
    {
        prev=prev->nx;
    }
    return prev;
}
        
//elemanın bulunduğu konumu getirme
YoneticiListesiNode* YoneticiListesi::FindPosition(int index)
{
    if(index<0||index>=size) cout<<"Belirtilen degerlerde deger giriniz";
    return this->FindPreviousByPosition(index+1);
}

//Kurucu Fonksiyon
YoneticiListesi::YoneticiListesi()
{
    head=NULL;
    size=0;
}
//listenin uzunluğunu getirme
int YoneticiListesi::count()const
{
    return size;
}
//listenin boş olup olmadığını kontrol etme
bool YoneticiListesi::isEmpty()const
{
    return size==0;
}

//listeye sondan eleman ekleme
void YoneticiListesi::Add(SatirListesi*& item)
{
    Insert(size,item);
}

//listeye belirtilen indexten eleman ekleme
void YoneticiListesi::Insert(int index,SatirListesi*& item)
{
    if(index<0||index>size) cout<<"Index out of range";
    if(index==0)
    {
        head = new YoneticiListesiNode(item,head);
        if(head->nx !=NULL)
        {
            head->nx->prev=head;
        }
    }
        else
        {
            YoneticiListesiNode *prv= FindPreviousByPosition(index);
            prv->nx = new YoneticiListesiNode(item, prv->nx, prv);
            if(prv->nx->nx != NULL)
            {
                prv->nx->nx->prev = prv->nx;
            }
        }
        size++;
    
}

//listenin ilk elemanını getirme
SatirListesi*&  YoneticiListesi::first() 
{
    if(isEmpty()) cout<<"Belirtilen degerlerde deger giriniz";
    return head->data;
}


//listenin son elemanını getirme
SatirListesi*&  YoneticiListesi::last() 
{
    if(isEmpty()) cout<<"Belirtilen degerlerde deger giriniz";
    return FindPreviousByPosition(size)->data;
}


//girilen elemanın indexini getirme
int YoneticiListesi::indexOf(SatirListesi*& item) 
{
    int index=0;
    for(YoneticiListesiNode *itr=head;itr!=NULL; itr= itr->nx)
    {
      if(itr->data == item) return index;
      index++;  
    }
    cout<<"Belirtilen degerlerde deger giriniz";
}


//belirtilen elemanı silme
void YoneticiListesi::remove(SatirListesi*& item)
{
    int index = indexOf(item);
    removeAt(index);
}
//belirtilen indexten eleman silme
void YoneticiListesi::removeAt(int index)
{
     if(index<0||index>=size) cout<<"Index out of range";
     YoneticiListesiNode *del;
     if(index==0)
     {
        del = head;
        head = head->nx;
        if(head!=NULL)  head->prev = NULL;
     }
        
           
        
    else
        {
            YoneticiListesiNode *prv = FindPreviousByPosition(index);
            del= prv->nx;
            prv->nx = del->nx;
            if(del->nx !=NULL)
            {
                del->nx->prev = prv;
            }
        }
        size--;
        delete del;
     
}
//satir listesinden random eleman seçme
void YoneticiListesi::randomRemoveAtSatirListesi(int index, int inlineIndex)
{
    int count = this->count();
    if(index<0||index>=count) cout<<"Index out of range";

    SatirListesi* satirlistesi= this->elementAt(index);

    satirlistesi->removeAt(inlineIndex);
    CalculateAverage(index);
    
    if(satirlistesi->isEmpty()){
        this->removeAt(index);
    }
}


//Yönetici listesinde ortalama gösterme
void YoneticiListesi::CalculateAverage(int index)
{
    YoneticiListesiNode* yoneticilistesiN= this->FindPosition(index);
    if(yoneticilistesiN==NULL)
    {
        throw "ERROR";
    }

    float total=0;
    if (yoneticilistesiN->data->isEmpty())
    {
        yoneticilistesiN->average = total;
        return;
    }
    int count = yoneticilistesiN->data->count();
    for(int i=0;i<count;i++)
    {
        total+= yoneticilistesiN->data->elementAt(i);
    }
    yoneticilistesiN->average = total/count;
    
}

//satir listesinden random eleman seçme
int YoneticiListesi::randomGenerator(int index) 
{
    int count=this->count();

    if(index<0||index>=count) cout<<"Index out of range"; 

    srand(time(NULL));
    SatirListesi* satirlistesi = this->elementAt(index);

    int range=satirlistesi->count();
    if(range==0) cout<<"Belirtilen degerlerde deger giriniz";

    int inlineIndex=rand()%range;
    return inlineIndex;
}

//düğümler arasında dolaşma
void YoneticiListesi::moveNode(int from, int to) 
{
    if(from<0||from>=size) cout<<"Index out of range";
    YoneticiListesiNode *del;
    if(from==0)
    {
        del = head;
        head= head->nx;
        if(head!=NULL)
        {
            head->prev=NULL;
        }
    }
    else
    {
        YoneticiListesiNode *prv= FindPreviousByPosition(from);
        del=prv->nx;
        prv->nx=del->nx;
        if(del->nx!=NULL)
        {
            del->nx->prev=prv;
        }
    }
    size--;
    if(to<0||to>=size) cout<<"Index out of range";
    if(to==0)
    {
        del->nx=head;
        del->prev=NULL;
        head=del;
        if(head->nx !=NULL)
        {
            head->nx->prev=head;
        }
    }
    else
    {
        YoneticiListesiNode *prv=FindPreviousByPosition(to);
        del->nx=prv->nx;
        del->prev=prv;
        prv->nx=del;
        if(prv->nx->nx !=NULL)
        {
            prv->nx->nx->prev=prv->nx;
        }
    }
    size++;
}


//girilen elemanı olup olmadığını kontrol etme
bool YoneticiListesi::find(SatirListesi*& item)
{
    for(YoneticiListesiNode *itr=head;itr!=NULL; itr= itr->nx)
    {
        if(itr->data==item) return true;
    }
    return false;
}

/*
void YoneticiListesi::reverse()
{
    
}
*/
//Ortalamaya göre sıralama
void YoneticiListesi::sortByAverage()
{
  if(this->size<=1)
  return;
  for(int adim=0;adim<size;++adim)
  {
    for(int i=0;i<size-adim-1;++i)
    {
        YoneticiListesiNode *tmp = this->FindPosition(i);
        YoneticiListesiNode *tmp2= tmp->nx;
        if(tmp->average >tmp2->average)
        {
            this->moveNode(i+1,i);
        }
    }
  }  
}

//girilen indexteki elemanı döndürür
SatirListesi*& YoneticiListesi::elementAt(int index)
{
    if(index<0||index>=size) cout<<"Belirtilen degerlerde deger giriniz";
    if(index==0) return head->data;
    return FindPreviousByPosition(index)->nx->data;
}



void YoneticiListesi::clear()
{
   while(!isEmpty())
   removeAt(0); 
}


void YoneticiListesi::printIndex(int index, int x, int y)
{
    YoneticiListesiNode *dugum=this->FindPosition(index);
    ListeYazdirma.gotoxy(x,y);
    cout<<fixed<<setprecision(2);
    cout<<dugum<<"\n";
    ListeYazdirma.gotoxy(x,y+1);
    cout<<"-----------\n";
    ListeYazdirma.gotoxy(x,y+2);
    cout<<"|"<<dugum->prev<<setw(3)<<"|\n";
    ListeYazdirma.gotoxy(x,y+3);
    cout<<"-----------\n";
    ListeYazdirma.gotoxy(x,y+4);
    cout<<"|"<<setw(3)<<dugum->average<<setw(5)<<"|"<<endl;
    ListeYazdirma.gotoxy(x,y+5);
    cout<<"-----------\n";
    ListeYazdirma.gotoxy(x,y+6);
    cout<<"|"<<dugum->nx<<setw(3)<<"|\n";
    ListeYazdirma.gotoxy(x,y+7);
    cout<<"-----------\n";






    
}


YoneticiListesi::~YoneticiListesi()
{
    clear();
}
        