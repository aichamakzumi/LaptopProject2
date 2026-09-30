#include "RAM.h"

RAM::RAM(const char* type, int sizeGB)
    : type(nullptr), sizeGB(sizeGB)
{
    setType(type);
}

RAM::RAM(const RAM& other)
    : type(nullptr), sizeGB(other.sizeGB)
{
    setType(other.type);
}

RAM& RAM::operator=(const RAM& other)
{
    if (this != &other)
    {
        sizeGB = other.sizeGB;
        setType(other.type);
    }
    return *this;
}

RAM::~RAM()
{
    delete[] type;
}

void RAM::setType(const char* type)
{
    delete[] this->type;
    if (type != nullptr && strlen(type) > 0)
    {
        this->type = new char[strlen(type) + 1];
        strcpy(this->type, type);
    }
    else
    {
        this->type = new char[1];
        this->type[0] = '\0';
    }
}

const char* RAM::getType() const
{
    return (type != nullptr) ? type : "";
}

void RAM::setSizeGB(int sizeGB)
{
    this->sizeGB = sizeGB;
}

int RAM::getSizeGB() const
{
    return sizeGB;
}

void RAM::Print() const
{
    cout << "RAM: " << getType() << " (" << sizeGB << " ГБ)" << endl;
}
