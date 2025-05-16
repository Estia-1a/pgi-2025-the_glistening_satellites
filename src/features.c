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
    printf("First pixel: %d, %d, %d\n", r, g, b);
}