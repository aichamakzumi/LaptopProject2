#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <cstring>

using namespace std;

class CPU
{
private:
    char* model;
    double frequency;
    int cores;

public:
    CPU(const char* model, double frequency, int cores);
    CPU(const CPU& other);
    CPU& operator=(const CPU& other);
    ~CPU();

    void setModel(const char* model);
    const char* getModel() const;

    void setFrequency(double frequency);
    double getFrequency() const;

    void setCores(int cores);
    int getCores() const;

    void Print() const;
};

#endif
