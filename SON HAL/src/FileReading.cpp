#include "FileReading.hpp"

YoneticiListesi* FileReading::GetFillYoneticiListesi()
{
    readline();
    YoneticiListesi*tmp= new YoneticiListesi();
    int count=lineCount();
    for(int i=0;i<count;++i)
    {
        tmp->Add(this->lines[i]);
    }
    return tmp;
}


FileReading::FileReading(std::string FileName)
{
    this->FileName=FileName;


    int numlines = lineCount();
    this->lines = new SatirListesi*[numlines];
    for(int i=0;i<numlines;++i)
    {
        this->lines[i] = new SatirListesi();
    }
}

int FileReading::lineCount()
{
    int counter =0;
    std::ifstream file(this->FileName);
    std::string unused;
    while(std::getline(file, unused))
    ++counter;

    file.close();
    return counter;
}

void FileReading::readline()
{
    std::string token;
    std::ifstream file(this->FileName);
    std::string str;
    int index =0;
    while(std::getline(file, token))
    {
        std::istringstream ss(token);

        while(std::getline(ss,str,' '))
        {
            this->lines[index]->Add(stoi(str));
        }
        index++;
    }
    file.close();
}

FileReading::~FileReading()
{
    if(lines!=0)
    {
        int count = lineCount();
        for(int i=0;i<count;++i)
        {
            if(lines[i]!=0) delete lines[i];
        }
        delete[] lines;
    }
}