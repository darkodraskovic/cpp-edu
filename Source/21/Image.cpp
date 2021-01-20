#include "Image.h"
#include <iostream>

Image::Image() : width_(0), height_(0), matrix_(GrayscaleMatrix(width_, std::vector<uchar>(height_, 0)))
{
    std::cout << "Empty image obj created." << "\n";
}

Image::Image(const unsigned int &width, const unsigned int &height)
 : width_(width), height_(height), matrix_(GrayscaleMatrix(width_, std::vector<uchar>(height_, 0)))
{
    std::cout << width_ << "x" << height <<" image obj created." << "\n";
}

Image::~Image() {
    std::cout << "Image obj destroyed." << "\n";
}
