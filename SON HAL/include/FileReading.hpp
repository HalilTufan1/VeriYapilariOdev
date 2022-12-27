#ifndef FILEREADING_HPP
#define FILEREADING_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"

class FileReading
{
    private:
    std::string FileName;
    int lineCount();
    SatirListesi **lines;
    void readline();

    public:
    FileReading(std::string);
    ~FileReading();
    YoneticiListesi* GetFillYoneticiListesi();
};
#endif