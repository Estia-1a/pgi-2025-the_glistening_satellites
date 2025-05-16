#include <estia-image.h>

#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */
pixelRGB * get_pixel(unsigned char* data, const unsigned int w, const unsigned int h, const unsigned int n, const unsigned int x, const unsigned int y ) {
    if (data==NULL || x>=w || y>=h){
        return NULL;
    }

    return (pixelRGB *) &data[(y*w+x)*n] ;
}

void print_pixel(char *filename, int x, int y) {
