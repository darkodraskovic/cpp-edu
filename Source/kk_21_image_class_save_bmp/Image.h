#pragma once

#include <vector>

// typedef unsigned char uchar;
using uchar = unsigned char;
using GrayscaleMatrix = std::vector<std::vector<uchar>>;

class Image {
 public:
  Image();
  Image(const unsigned int width, const unsigned int height);
  ~Image();

  unsigned int GetWidth() const;
  unsigned int GetHeigh() const;
  void SetWidth(unsigned int width);
  void SetHeight(unsigned int height);

  void ClearImage(uchar value);
  void SetPixel(unsigned int x, unsigned int y, uchar value);
  uchar GetPixel(unsigned int x, unsigned int y) const;

  void ResizeImage(unsigned int width, unsigned int height);

  void SaveImage(const char *fileName) const;

 private:
  GrayscaleMatrix matrix_;
};
