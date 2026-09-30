#ifndef SSD_H
#define SSD_H

#include <iostream>
#include <cstring>

using namespace std;

class SSD
{
private:
    char* model;
    int capacityGB;

public:
    SSD(const char* model, int capacityGB);
    SSD(const SSD& other);
    SSD& operator=(const SSD& other);
    ~SSD();

    void setModel(const char* model);
    const char* getModel() const;

    void setCapacityGB(int capacityGB);
    int getCapacityGB() const;

    void Print() const;
};

#endif
