#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension(char *source_path) {
    unsigned char* data = NULL;
    int w= 0, h= 0, n= 0;
    read_image_data(source_path, &data, &w, &h, &n);
    printf("dimension: %d, %d\n", w, h);
}

void first_pixel (char *source_path){
    unsigned char* data = NULL;
    int w= 0, h= 0, n= 0;
    int r, g, b;
    read_image_data(source_path, &data, &w, &h, &n);
    r=data[0]; 
    g=data[1]; 
    b=data[2];
    printf("first_pixel: %d, %d, %d\n", r, g, b);
}

void tenth_pixel (char *source_path){
    unsigned char* data = NULL;
    int w= 0, h= 0, n= 0;
    int r, g, b;
    read_image_data(source_path, &data, &w, &h, &n);
    r=data[27]; 
    g=data[28]; 
    b=data[29];
    printf("tenth_pixel: %d, %d, %d\n", r, g, b);
}

void second_line(char *source_path) {
    unsigned char* data = NULL;
    int w= 0, h= 0, n= 0;
    int r, g, b;
    read_image_data(source_path, &data, &w, &h, &n);
    r=data[3*w]; 
    g=data[3*w+1]; 
    b=data[3*w+2];
    printf("Second_line: %d,%d,%d\n", r, g, b);
}

void print_pixel(char *source_path, int x, int y){
    unsigned char* data = NULL;
    int w = 0, h = 0, n = 0;
    read_image_data(source_path, &data, &w, &h, &n);
    pixelRGB* pixel = get_pixel(data, w, h, n, x, y);

    if (pixel==NULL){
        printf("NULL");
        return;
    }
    
    printf("Print_Pixel (%d,%d): %d,%d,%d", x, y, pixel->R, pixel->G, pixel->B);
}

void max_pixel(char *source_path) {
    int max = 0 , i, j, s, R, G, B , x, y ;
    unsigned char* data = NULL ;
    int w = 0, h = 0, n = 0 ;
    read_image_data(source_path, &data, &w, &h, &n) ;
    for(j = 0; j < h; j++) {
        for(i = 0; i < w; i++) {
            pixelRGB* pixel = get_pixel(data, w, h, n, i, j) ;
            s = pixel->R + pixel->G + pixel->B ;
            if (s > max) {
                max = s ;
                x = i ; 
                y = j ;
                R = pixel->R ;
                G = pixel->G ;
                B = pixel->B ;
            }
        }
    }
    printf("max_pixel (%d,%d): %d,%d,%d", x, y, R, G, B) ;
}

void color_red(char *source_path){
    unsigned char* data = NULL ;
    int w = 0, h = 0, n = 0, i, t ;
    read_image_data(source_path, &data, &w, &h, &n) ;
    t = w*h ;
    for(i = 0; i < t; i++) {
        data[i*n +1] = 0 ;
        data[i*n +2] = 0 ;
    }
    write_image_data("image_out.bmp", data, w, h) ; 
}

void color_green(char *source_path){
    unsigned char* data = NULL ;
    int w = 0, h = 0, n = 0, i, t ;
    read_image_data(source_path, &data, &w, &h, &n) ;
    t = w*h ;
    for(i = 0; i < t; i++) {
        data[i*n] = 0 ;
        data[i*n +2] = 0 ;
    }
    write_image_data("image_out.bmp", data, w, h) ; 
}
 
void color_blue(char *source_path){
    unsigned char* data = NULL ;
    int w = 0, h = 0, n = 0, i, t ;
    read_image_data(source_path, &data, &w, &h, &n) ;
    t = w*h ;
    for(i = 0; i < t; i++) {
        data[i*n] = 0 ;
        data[i*n +1] = 0 ;
    }
    write_image_data("image_out.bmp", data, w, h) ; 
}     