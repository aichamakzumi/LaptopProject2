#ifndef LAPTOP_H
#define LAPTOP_H

#include <iostream>
#include <cstring>
#include "CPU.h"
#include "SSD.h"
#include "VideoCard.h"
#include "RAM.h"

using namespace std;

class Laptop
{
private:
    char* name;
    char* color;
    double price;

    CPU cpu;
    SSD ssd;
    VideoCard videoCard;
    RAM ram;

    static int laptopCount;

public:
    Laptop(const char* name, double price, const char* color, 
           const CPU& cpu, const SSD& ssd, const VideoCard& videoCard, const RAM& ram);

    Laptop(const char* name, double price, 
           const CPU& cpu, const SSD& ssd, const VideoCard& videoCard, const RAM& ram);

    Laptop(const Laptop& other);
    Laptop& operator=(const Laptop& other);
    ~Laptop();

    static int getLaptopCount();

    void setName(const char* name);
    const char* getName() const;

    void setColor(const char* color);
    const char* getColor() const;

    void setPrice(double price);
    double getPrice() const;

    void setCPU(const CPU& cpu);
    const CPU& getCPU() const;

    void setSSD(const SSD& ssd);
    const SSD& getSSD() const;

    void setVideoCard(const VideoCard& videoCard);
    const VideoCard& getVideoCard() const;

    void setRAM(const RAM& ram);
    const RAM& getRAM() const;

    void Print() const;
};

#endif
