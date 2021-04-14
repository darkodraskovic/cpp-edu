#include <algorithm>
#include <iostream>
#include <cstring>
#include <stdlib.h>

#include "Image.h"

Image::Image() :
    width_(0), height_(0),
    matrix_(GrayscaleMatrix(width_, std::vector<uchar>(height_, 0)))
{
    std::cout << "Empty image obj created." << "\n";
}

Image::Image(const unsigned int width, const unsigned int height)
 : width_(width), height_(height),
   matrix_(GrayscaleMatrix(width_, std::vector<uchar>(height_, 0)))
{
    std::cout << width_ << "x" << height <<" image obj created." << "\n";
}

Image::~Image() {
    std::cout << "Image obj destroyed." << "\n";
}

unsigned int Image::GetWidth() const { return width_; }

unsigned int Image::GetHeigh() const { return height_; }


void Image::SetWidth(unsigned int width) {
    width_ = width;
}
void Image::SetHeight(unsigned int height) {
    height_ = height;
}

void Image::ClearImage(uchar value) {
    // for (unsigned int x = 0; x < width_; ++x)
    // {
    //     for (unsigned int y = 0; y < height_; y++)
    //     {
    //         matrix_[x][y] = value;
    //     }
    // }
    for (auto& col : matrix_) {
        std::fill(col.begin(), col.end(), value);
    }
}

void Image::SetPixel(unsigned int x, unsigned int y, uchar value) {
    matrix_[x][y] = value;
}

void Image::ResizeImage(unsigned int width, unsigned int height) {
    // GrayscaleMatrix newMatrix = GrayscaleMatrix(width, std::vector<uchar>(height, 0));
    // int w = width < width_ ? width : width_;
    // int h = height < height_ ? height : height_;
    // for (unsigned int x = 0; x < w; ++x) {
    //     for (unsigned int y = 0; y < h; y++) {
    //         newMatrix[x][y] = matrix_[x][y];
    //     }
    // }
    // matrix_ = newMatrix;

    if (width_ != width) {
        matrix_.resize(width, std::vector<uchar>(height_, 0));
    }

    if (height_ != height) {
        for (auto& col : matrix_) {
            col.resize(height, 0);
        }
    }
    
    width_ = width;
    height_ = height;
}

void Image::SaveImage(const char *fileName) const {
    FILE* f;

    unsigned int numBytes = 3 * width_ * height_;
    uchar* img = (uchar*)(malloc(numBytes));
    memset(img, 0, numBytes);

    int filesize = 54 + numBytes;

    for (unsigned int x = 0; x < width_; ++x)
    {
        for (unsigned int y = 0; y < height_; y++)
        {
            img[(x + y * width_) * 3 + 2] = matrix_[x][y] % 256;
            img[(x + y * width_) * 3 + 1] = matrix_[x][y] % 256;
            img[(x + y * width_) * 3 + 0] = matrix_[x][y] % 256;
        }
    }

    uchar bmpfileheader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    uchar bmpinfoheader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
    uchar bmppad[3] = {0, 0, 0};

    bmpfileheader[2]    = (uchar)(filesize);
    bmpfileheader[3]    = (uchar)(filesize >> 8);
    bmpfileheader[4]    = (uchar)(filesize >> 16);
    bmpfileheader[5]    = (uchar)(filesize >> 24);

    bmpinfoheader[4]    = (uchar)(width_);
    bmpinfoheader[5]    = (uchar)(width_ >> 8);
    bmpinfoheader[6]    = (uchar)(width_ >> 16);
    bmpinfoheader[7]    = (uchar)(width_ >> 24);
    bmpinfoheader[8]    = (uchar)(height_);
    bmpinfoheader[9]    = (uchar)(height_ >> 8);
    bmpinfoheader[10]   = (uchar)(height_ >> 16);
    bmpinfoheader[11]   = (uchar)(height_ >> 24);

    f = fopen(fileName, "wb");
    fwrite(bmpfileheader, 1, 14, f);
    fwrite(bmpinfoheader, 1, 40, f);

    for (unsigned int i = 0; i < height_; i++)
    {
        fwrite(img + (width_ * (height_ - i - 1) * 3), 3, width_, f);
        fwrite(bmppad, 1, (4 - (width_ * 3) % 4) % 4, f);
    }

    fclose(f);
}
