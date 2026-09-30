#ifndef VIDEOCARD_H
#define VIDEOCARD_H

#include <iostream>
#include <cstring>

using namespace std;

class VideoCard
{
private:
    char* model;
    int vramGB;

public:
    VideoCard(const char* model, int vramGB);
    VideoCard(const VideoCard& other);
    VideoCard& operator=(const VideoCard& other);
    ~VideoCard();

    void setModel(const char* model);
    const char* getModel() const;

    void setVramGB(int vramGB);
    int getVramGB() const;

    void Print() const;
};

using GPU = VideoCard;

#endif
