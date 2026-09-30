#ifndef RAM_H
#define RAM_H

#include <iostream>
#include <cstring>

using namespace std;

class RAM
{
private:
    char* type;
    int sizeGB;

public:
    RAM(const char* type, int sizeGB);
    RAM(const RAM& other);
    RAM& operator=(const RAM& other);
    ~RAM();

    void setType(const char* type);
    const char* getType() const;

    void setSizeGB(int sizeGB);
    int getSizeGB() const;

    void Print() const;
};

#endif
