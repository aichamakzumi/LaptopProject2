#include "VideoCard.h"

VideoCard::VideoCard(const char* model, int vramGB)
    : model(nullptr), vramGB(vramGB)
{
    setModel(model);
}

VideoCard::VideoCard(const VideoCard& other)
    : model(nullptr), vramGB(other.vramGB)
{
    setModel(other.model);
}

VideoCard& VideoCard::operator=(const VideoCard& other)
{
    if (this != &other)
    {
        vramGB = other.vramGB;
        setModel(other.model);
    }
    return *this;
}

VideoCard::~VideoCard()
{
    delete[] model;
}

void VideoCard::setModel(const char* model)
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

const char* VideoCard::getModel() const
{
    return (model != nullptr) ? model : "";
}

void VideoCard::setVramGB(int vramGB)
{
    this->vramGB = vramGB;
}

int VideoCard::getVramGB() const
{
    return vramGB;
}

void VideoCard::Print() const
{
    cout << "Відеокарта: " << getModel() << " (" << vramGB << " ГБ VRAM)" << endl;
}
