#include "Laptop.h"

int Laptop::laptopCount = 0;

Laptop::Laptop(const char* name, double price, const char* color, 
               const CPU& cpu, const SSD& ssd, const VideoCard& videoCard, const RAM& ram)
    : cpu(cpu), ssd(ssd), videoCard(videoCard), ram(ram), name(nullptr), color(nullptr), price(price)
{
    setName(name);
    setColor(color);
    ++laptopCount;
}

Laptop::Laptop(const char* name, double price, 
               const CPU& cpu, const SSD& ssd, const VideoCard& videoCard, const RAM& ram)
    : Laptop(name, price, "Чорний", cpu, ssd, videoCard, ram)
{
}

Laptop::Laptop(const Laptop& other)
    : cpu(other.cpu), ssd(other.ssd), videoCard(other.videoCard), ram(other.ram),
      name(nullptr), color(nullptr), price(other.price)
{
    setName(other.name);
    setColor(other.color);
    ++laptopCount;
}

Laptop& Laptop::operator=(const Laptop& other)
{
    if (this != &other)
    {
        price = other.price;
        cpu = other.cpu;
        ssd = other.ssd;
        videoCard = other.videoCard;
        ram = other.ram;
        setName(other.name);
        setColor(other.color);
    }
    return *this;
}

Laptop::~Laptop()
{
    delete[] name;
    delete[] color;
    --laptopCount;
}

int Laptop::getLaptopCount()
{
    return laptopCount;
}

void Laptop::setName(const char* name)
{
    delete[] this->name;
    if (name != nullptr && strlen(name) > 0)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    else
    {
        this->name = new char[1];
        this->name[0] = '\0';
    }
}

const char* Laptop::getName() const
{
    return (name != nullptr) ? name : "";
}

void Laptop::setColor(const char* color)
{
    delete[] this->color;
    if (color != nullptr && strlen(color) > 0)
    {
        this->color = new char[strlen(color) + 1];
        strcpy(this->color, color);
    }
    else
    {
        this->color = new char[1];
        this->color[0] = '\0';
    }
}

const char* Laptop::getColor() const
{
    return (color != nullptr) ? color : "";
}

void Laptop::setPrice(double price)
{
    this->price = price;
}

double Laptop::getPrice() const
{
    return price;
}

void Laptop::setCPU(const CPU& cpu)
{
    this->cpu = cpu;
}

const CPU& Laptop::getCPU() const
{
    return cpu;
}

void Laptop::setSSD(const SSD& ssd)
{
    this->ssd = ssd;
}

const SSD& Laptop::getSSD() const
{
    return ssd;
}

void Laptop::setVideoCard(const VideoCard& videoCard)
{
    this->videoCard = videoCard;
}

const VideoCard& Laptop::getVideoCard() const
{
    return videoCard;
}

void Laptop::setRAM(const RAM& ram)
{
    this->ram = ram;
}

const RAM& Laptop::getRAM() const
{
    return ram;
}

void Laptop::Print() const
{
    cout << "---------------------------------------" << endl;
    cout << "Ноутбук: " << getName() << endl;
    cout << "Колір: " << getColor() << endl;
    cout << "Ціна: " << price << " грн." << endl;
    cout << "Характеристики складових:" << endl;
    cout << "  "; cpu.Print();
    cout << "  "; ssd.Print();
    cout << "  "; videoCard.Print();
    cout << "  "; ram.Print();
    cout << "---------------------------------------" << endl;
}
