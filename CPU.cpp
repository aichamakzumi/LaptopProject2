#include "CPU.h"

CPU::CPU(const char* model, double frequency, int cores)
    : model(nullptr), frequency(frequency), cores(cores)
{
    setModel(model);
}

CPU::CPU(const CPU& other)
    : model(nullptr), frequency(other.frequency), cores(other.cores)
{
    setModel(other.model);
}

CPU& CPU::operator=(const CPU& other)
{
    if (this != &other)
    {
        frequency = other.frequency;
        cores = other.cores;
        setModel(other.model);
    }
    return *this;
}

CPU::~CPU()
{
    delete[] model;
}

void CPU::setModel(const char* model)
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

const char* CPU::getModel() const
{
    return (model != nullptr) ? model : "";
}

void CPU::setFrequency(double frequency)
{
    this->frequency = frequency;
}

double CPU::getFrequency() const
{
    return frequency;
}

void CPU::setCores(int cores)
{
    this->cores = cores;
}

int CPU::getCores() const
{
    return cores;
}

void CPU::Print() const
{
    cout << "CPU: " << getModel() << " (" << cores << " ядер, " << frequency << " ГГц)" << endl;
}
