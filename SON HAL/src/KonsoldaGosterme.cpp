#include "KonsoldaGosterme.hpp"
#include "SatirListesi.hpp"

KonsoldaGosterme::KonsoldaGosterme(YoneticiListesi* yonetici) {
   
    this->yonetici = yonetici;
    if (this->yonetici->count() < DisplayperOnePage) {
        this->finishOffset = this->yonetici->count();
    } else {
        this->finishOffset = DisplayperOnePage;
    }

    this->beginOffset = BeginOffset;

}

void KonsoldaGosterme::setOffsets() {
    int page = state / DisplayperOnePage;
    this->beginOffset = DisplayperOnePage*page;
    this->finishOffset = DisplayperOnePage * (page + 1);
    if (this->finishOffset >= this->yonetici->count()) {
        this->finishOffset = this->yonetici->count();

    }
}

void KonsoldaGosterme::setState(Yon dr) {

    if (dr == up) {
        if (state >= this->yonetici->count() - 1) {
            return;
        }
        ++state;
        setOffsets();
    } else if (dr == down) {
        if (state <= 0) {

            return;
        }
        --state;
        setOffsets();
    } else if (dr == refresh) {
        setOffsets();
    }

}

void KonsoldaGosterme::SetPage(SayfaYon pdr) {
    if (pdr == downPage) {
        for (int i = 0; i < DisplayperOnePage; ++i) {
            this->setState(down);
        }
    } else if (pdr == upPage) {
        for (int i = 0; i < DisplayperOnePage; ++i) {
            this->setState(up);
        }
    }
}

void KonsoldaGosterme::printYoneticiListesi() {

    int count = yonetici->count();
    system("cls");
    if (count == 0) {
        cout << "Goruntulenecek bir Yonetici listesi yok\n";
        exit(1);
        return;
    }


    ListeYazdirma.gotoxy(0, 0);
    if (this->beginOffset == 0) {
        cout << "<--ilk--";
    } else {
        cout << "<---geri--";
    }


    int showingNodeCount = this->finishOffset - this->beginOffset;
    showingNodeCount *= 13;


    ListeYazdirma.gotoxy(showingNodeCount, 0);


    if (this->finishOffset == yonetici->count()) {
        cout << "--son-->";
    } else {
        cout << "--ileri-->";
    }
    for (int i = this->beginOffset; i<this->finishOffset; ++i) {


        int mod = i % DisplayperOnePage;
        this->yonetici->printIndex(i, 15 * mod, 1);

    }
    this->printSelectedSatirListesi((this->state % DisplayperOnePage) *15, 9);
}

 void KonsoldaGosterme::printSelectedSatirListesi(int x, int y) {
        this->yonetici->elementAt(this->state)->printSatirListesi(x, y);

    }
  int KonsoldaGosterme::DisplayRandomSelectedNode() {

        int randomSelected = this->yonetici->randomGenerator(this->state);
        int xPosition = ((this->state % DisplayperOnePage) + 1)*15;
        int yPosition = (randomSelected)*6;
        yPosition += 12;
        ListeYazdirma.gotoxy(xPosition, yPosition);
        cout << "<--silinecek";
        yPosition = this->yonetici->elementAt(this->state)->count()*6 + 12;

        ListeYazdirma.gotoxy(0, yPosition - 1);


        return randomSelected;

    }
  void KonsoldaGosterme::DeleteYoneticiListesiNode() {
        this->yonetici->removeAt(this->state);
        this->setState(refresh);
       
      
        if(this->state==this->finishOffset){
            this->state--;
        }
         this->setState(refresh);

   

    }

   
  void KonsoldaGosterme::DeleteRandomSelectedNode(int randomIndex){
        this->yonetici->randomRemoveAtSatirListesi(this->state, randomIndex);
        
    }