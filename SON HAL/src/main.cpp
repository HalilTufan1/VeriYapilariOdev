#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "ListeYazdirma.hpp"
#include "FileReading.hpp"
#include "KonsoldaGosterme.hpp"
#include <cstdlib>

using namespace std;

int main(int argc,char**argv)
{
FileReading * filereading = new FileReading("veriler.txt");

    YoneticiListesi *yoneticiListesi = filereading->GetFillYoneticiListesi();

    KonsoldaGosterme *console = new KonsoldaGosterme(yoneticiListesi);
    yoneticiListesi->sortByAverage();
    string karakter = "";
    do {
        console->printYoneticiListesi();
        cin>>karakter;
        if (karakter == "c") {
            Yon direction = up;
            console->setState(direction);
        } else if (karakter == "z") {
            Yon direction = down;
            console->setState(direction);
        } else if (karakter == "k") {
            int randomIndex = 0;
            try {
                randomIndex = console->DisplayRandomSelectedNode();
            } catch (...) {
                continue;

            }
            cin>>karakter;
            if (karakter == "k") {

                console->DeleteRandomSelectedNode(randomIndex);
                yoneticiListesi->sortByAverage();

            }
        } else if (karakter == "p") {
            console->DeleteYoneticiListesiNode();
        } else if (karakter == "d") {
            console->SetPage(upPage);
        } else if (karakter == "a") {
            console->SetPage(downPage);
        }


    } while (karakter != "q");



    return 0;



}