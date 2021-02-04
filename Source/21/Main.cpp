#include <iostream>
#include "Image.h"

int main(int argc, char *argv[]){

    unsigned int w = 256;
    unsigned int h = 128;
    Image img1(w,h);
    
    img1.ClearImage(200);

    int diff = 24;
    // img1.ResizeImage(w, h);
    img1.ResizeImage(w + diff, h);
    // img1.ResizeImage(w, h + diff);
    // img1.ResizeImage(w + diff, h + diff);

    img1.SaveImage("scene.bmp");
    
    return 0;
}
