#include "SSD.h"

SSD::SSD(const char* model, int capacityGB)
    : model(nullptr), capacityGB(capacityGB)
{
    setModel(model);
}

SSD::SSD(const SSD& other)
    : model(nullptr), capacityGB(other.capacityGB)
{
    setModel(other.model);
}

SSD& SSD::operator=(const SSD& other)
{
    if (this != &other)
    {
        capacityGB = other.capacityGB;
        setModel(other.model);
    }
    return *this;
}

SSD::~SSD()
{
    delete[] model;
}

void SSD::setModel(const char* model)
{
    delete[] this->model;
    if (model != nullptr && strlen(model) > 0)
    {
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
    }
    else
    {
        this->model = new char[1];
        this->model[0] = '\0';
    }
}

const char* SSD::getModel() const
{
    return (model != nullptr) ? model : "";
}

void SSD::setCapacityGB(int capacityGB)
{
    this->capacityGB = capacityGB;
}

int SSD::getCapacityGB() const
{
    return capacityGB;
}

void SSD::Print() const
{
    cout << "SSD: " << getModel() << " (" << capacityGB << " ГБ)" << endl;
}
