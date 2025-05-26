#include <estia-image.h>

#include "utils.h"

#include <stdlib.h>
/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */
pixelRGB * get_pixel(unsigned char* data, const unsigned int w, const unsigned int h, const unsigned int n, const unsigned int x, const unsigned int y ) {
    if (data==NULL){
        return NULL;
    } 
    
    if ((x>=w) || (y>=h)){
        return NULL;
    }

    if ((y*w + x)*n + 2 >= w * h * n){
        return NULL;
    } 

    pixelRGB* pixel = malloc(sizeof(pixelRGB)) ;
    if (pixel == NULL) {
        return NULL;
    }

    pixel->R = data[(y*w + x)*n ] ;
    pixel->G = data[(y*w + x)*n + 1] ;
    pixel->B =data[(y*w + x)*n + 2] ;
 
    return pixel;
}
