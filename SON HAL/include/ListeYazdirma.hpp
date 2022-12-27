#ifndef LISTEYAZDIRMA_HPP    
#define LISTEYAZDIRMA_HPP

#include <windows.h>

static class ListeYazdirma
{
    public:
       static void gotoxy(int x, int y)
        {
            COORD c;
            c.X = x;
            c.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
        }
} ListeYazdirma;

#endif