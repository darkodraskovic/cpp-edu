#include "Image.h"

#include <stdlib.h>

#include <algorithm>
#include <cstring>
#include <iostream>

Image::Image() : matrix_(GrayscaleMatrix(0, std::vector<uchar>(0, 0))) {
  std::cout << "Empty image obj created."
            << "\n";
}

Image::Image(const unsigned int width, const unsigned int height)
    : matrix_(GrayscaleMatrix(width, std::vector<uchar>(height, 0))) {
  std::cout << width << "x" << height << " image obj created."
            << "\n";
}

Image::~Image() {
  std::cout << "Image obj destroyed."
            << "\n";
}

unsigned int Image::GetWidth() const { return (unsigned int)matrix_.size(); }
unsigned int Image::GetHeigh() const {
  if (matrix_.size())
    return (unsigned int)matrix_[0].size();
  else
    return 0;
}
void Image::SetWidth(unsigned int width) { ResizeImage(width, GetHeigh()); };
void Image::SetHeight(unsigned int height) { ResizeImage(GetWidth(), height); };

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

void Image::SetPixel(unsigned int x, unsigned int y, uchar value) { matrix_[x][y] = value; }
uchar Image::GetPixel(unsigned int x, unsigned int y) const { return matrix_[x][y]; }

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

  if (GetWidth() != width) {
    matrix_.resize(width, std::vector<uchar>(GetHeigh(), 0));
  }

  if (GetHeigh() != height) {
    for (auto& col : matrix_) {
      col.resize(height, 0);
    }
  }
}

void Image::SaveImage(const char* fileName) const {
  FILE* f;

  unsigned int width = GetWidth();
  unsigned int height = GetHeigh();

  unsigned int numBytes = 3 * width * height;
  uchar* img = (uchar*)(malloc(numBytes));
  memset(img, 0, numBytes);

  int filesize = 54 + numBytes;

  for (unsigned int x = 0; x < width; ++x) {
    for (unsigned int y = 0; y < height; y++) {
      img[(x + y * width) * 3 + 2] = matrix_[x][y] % 256;
      img[(x + y * width) * 3 + 1] = matrix_[x][y] % 256;
      img[(x + y * width) * 3 + 0] = matrix_[x][y] % 256;
    }
  }

  uchar bmpfileheader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
  uchar bmpinfoheader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
  uchar bmppad[3] = {0, 0, 0};

  bmpfileheader[2] = (uchar)(filesize);
  bmpfileheader[3] = (uchar)(filesize >> 8);
  bmpfileheader[4] = (uchar)(filesize >> 16);
  bmpfileheader[5] = (uchar)(filesize >> 24);

  bmpinfoheader[4] = (uchar)(width);
  bmpinfoheader[5] = (uchar)(width >> 8);
  bmpinfoheader[6] = (uchar)(width >> 16);
  bmpinfoheader[7] = (uchar)(width >> 24);
  bmpinfoheader[8] = (uchar)(height);
  bmpinfoheader[9] = (uchar)(height >> 8);
  bmpinfoheader[10] = (uchar)(height >> 16);
  bmpinfoheader[11] = (uchar)(height >> 24);

  f = fopen(fileName, "wb");
  fwrite(bmpfileheader, 1, 14, f);
  fwrite(bmpinfoheader, 1, 40, f);

  for (unsigned int i = 0; i < height; i++) {
    fwrite(img + (width * (height - i - 1) * 3), 3, width, f);
    fwrite(bmppad, 1, (4 - (width * 3) % 4) % 4, f);
  }

  fclose(f);
}
