#include <cassert>
#include <iostream>

#include "Image.h"

struct Rect {
  unsigned int x;
  unsigned int y;
  unsigned int w;
  unsigned int h;
};

void assert_size(const Image& image, unsigned int w, unsigned int h) {
  assert(image.GetWidth() == w);
  assert(image.GetHeigh() == h);
}

void assert_clear(const Image& image, uchar clearCol, const Rect& rect) {
  for (unsigned int x = rect.x; x < rect.w; ++x) {
    for (unsigned int y = rect.y; y < rect.h; y++) {
      assert(image.GetPixel(x, y) == clearCol);
    }
  }
}

int main(int argc, char* argv[]) {
  unsigned int w = 256;
  unsigned int h = 128;
  uchar clearCol = 200;

  Image emptyImage;
  assert_size(emptyImage, 0, 0);
  emptyImage.ResizeImage(0, 0);
  assert_size(emptyImage, 0, 0);
  emptyImage.ResizeImage(w, h);
  emptyImage.ClearImage(clearCol);
  assert_clear(emptyImage, clearCol, Rect{0, 0, w, h});

  Image img1(w, h);
  assert_size(img1, w, h);

  img1.ClearImage(clearCol);
  assert_clear(img1, clearCol, Rect{0, 0, w, h});

  int diff = 24;
  img1.ResizeImage(w, h);
  assert_size(img1, w, h);

  img1.ResizeImage(w + diff, h);
  assert_size(img1, w + diff, h);

  img1.ResizeImage(w, h + diff);
  assert(img1.GetWidth() == w);
  assert_size(img1, w, h + diff);

  img1.ResizeImage(w + diff, h + diff);
  assert_size(img1, w + diff, h + diff);
  assert_clear(img1, clearCol, Rect{0, 0, w, h});
  assert_clear(img1, 0, Rect{w, h, w + diff, h + diff});

  img1.SaveImage("scene.bmp");

  return 0;
}
