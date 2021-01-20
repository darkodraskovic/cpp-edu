#pragma once

#include <vector>

// typedef unsigned char uchar;
using uchar = unsigned char;
using GrayscaleMatrix = std::vector<std::vector<uchar>>;

class Image
{
public:
    Image();
    Image(const unsigned int& width, const unsigned int& height);
    ~Image();
    
private:
    unsigned int width_;
    unsigned int height_;
    GrayscaleMatrix matrix_;
}; 
