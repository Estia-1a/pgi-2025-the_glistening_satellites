#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

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
void min_pixel(char *source_path) {
    int min = 10000, i, j, s, R, G, B , x, y ;
    unsigned char* data = NULL ;
    int w = 0, h = 0, n = 0 ;
    read_image_data(source_path, &data, &w, &h, &n) ;
    for(j = 0; j < h; j++) {
        for(i = 0; i < w; i++) {
            pixelRGB* pixel = get_pixel(data, w, h, n, i, j) ;
            s = pixel->R + pixel->G + pixel->B ;
            if (s < min) {
                min = s ;
                x = i ; 
                y = j ;
                R = pixel->R ;
                G = pixel->G ;
                B = pixel->B ;
            }
        }
    }
    printf("min_pixel (%d,%d): %d,%d,%d", x, y, R, G, B) ;
}

void max_component(char *source_path, char component){
    unsigned char* data = NULL ;
    int w = 0, h = 0, n = 0, x, y, i, j, value = 0;
    read_image_data(source_path, &data, &w, &h, &n) ;
    for(j = 0; j < h; j++) {
        for(i = 0; i < w; i++) {
            pixelRGB* pixel = get_pixel(data, w, h, n, i, j) ;
            if (component == 'R'){
                if(value<(pixel->R)){
                x=i;
                y=j;
                value = pixel->R;
                }
            }
            if (component == 'G'){
                if(value<(pixel->G)){
                x=i;
                y=j;
                value = pixel->G;
                }
            }
            if (component == 'B'){
                if(value<(pixel->B)){
                x=i;
                y=j;
                value = pixel->B;
                }
            }
            
        }
    }
    printf("max_component %c (%d, %d) : %d", component, x, y, value);
}

void min_component(char *source_path, char component){
    unsigned char* data = NULL ;
    int w = 0, h = 0, n = 0, x, y, i, j, value = 1000;
    read_image_data(source_path, &data, &w, &h, &n) ;
    for(j = 0; j < h; j++) {
        for(i = 0; i < w; i++) {
            pixelRGB* pixel = get_pixel(data, w, h, n, i, j) ;
            if (component == 'R'){
                if(value>(pixel->R)){
                x=i;
                y=j;
                value = pixel->R;
                }
            }
            if (component == 'G'){
                if(value>(pixel->G)){
                x=i;
                y=j;
                value = pixel->G;
                }
            }
            if (component == 'B'){
                if(value>(pixel->B)){
                x=i;
                y=j;
                value = pixel->B;
                }
            }
            
        }
    }
    printf("min_component %c (%d, %d) : %d", component, x, y, value);
}

void color_gray(char *source_path){
    unsigned char* data = NULL ;
    int w = 0, h = 0, n = 0, i, t, Gray ;
    read_image_data(source_path, &data, &w, &h, &n) ;
    t = w*h ;
    for(i = 0; i < t; i++) {
        Gray = (data[i*n] + data[i*n + 1] + data[i*n + 2])/3 ;
        data[i*n] = Gray ;
        data[i*n + 1] = Gray ;
        data[i*n + 2] = Gray ;
    }
    write_image_data("image_out.bmp", data, w, h) ; 
}

void color_gray_luminance(char *source_path){
    unsigned char* data = NULL ;
    int w = 0, h = 0, n = 0, i, t, Gray ;
    read_image_data(source_path, &data, &w, &h, &n) ;
    t = w*h ;
    for(i = 0; i < t; i++) {
        Gray = data[i*n]*0.21 + data[i*n + 1]*0.72 + data[i*n + 2]*0.07 ;
        data[i*n] = Gray ;
        data[i*n + 1] = Gray ;
        data[i*n + 2] = Gray ;
    }
    write_image_data("image_out.bmp", data, w, h) ; 
}

void color_invert(char *source_path){
    unsigned char* data = NULL ;
    int w = 0, h = 0, n = 0, i, t;
    read_image_data(source_path, &data, &w, &h, &n) ;
    t = w*h ;
    for(i = 0; i < t; i++) {
        data[i*n] = 255 - data[i*n] ;
        data[i*n + 1] = 255 - data[i*n + 1] ;
        data[i*n + 2] = 255 - data[i*n + 2] ;
    }
    write_image_data("image_out.bmp", data, w, h) ; 
}

void color_desaturate(char *source_path) {
    unsigned char* data = NULL ;
    int w = 0, h = 0, n = 0, i, j, t, max , min, new_value ;
    read_image_data(source_path, &data, &w, &h, &n) ;
    t = w*h ;
    for(i = 0; i < t; i++) {
        min = data[i*n] ;
        max =  data[i*n] ;
        for(j = 1; j < 3; j++) {
            if (data[i*n + j] < min ) {
                min = data[i*n + j] ;
            }     
            if (data[i*n + j] > max ) {
                max = data[i*n + j] ;
            }
        }
        new_value = (max + min)/2 ;
        data[i*n] = new_value ;
        data[i*n + 1] = new_value ;
        data[i*n + 2] = new_value ;
    }
    write_image_data("image_out.bmp", data, w, h) ;
}

void mirror_horizontal(char *source_path) {
    unsigned char* data = NULL ;
    int w = 0, h = 0, n = 0, i, j, l;
    read_image_data(source_path, &data, &w, &h, &n) ;

    for(i = 0; i < h; i++) {
        for(j = 0; j < w/2 ; j++) {
           int g = (i*w + j)*n;
           int d = (i*w + (w-1-j))*n;

           for(l = 0; l<n; l++){
                char t = data[g + l];
                data[g + l] = data[d + l];
                data[d + l] = t;
           }
        }
    }
    write_image_data("image_out.bmp", data, w, h) ;
}

void mirror_vertical(char *source_path) {
    unsigned char* data = NULL ;
    int w = 0, h = 0, n = 0;
    read_image_data(source_path, &data, &w, &h, &n) ;

    int r = w * n;
    for( int j = 0; j < h/2; j++) {
        int t = j * r;
        int b = (h - 1 - j) * r;

        for(int i = 0; i < r ; i++) {
            unsigned char u = data[t + i];
            data[t + i] = data[b + i];
            data[b + i] = u;
        }
    }
    write_image_data("image_out.bmp", data, w, h) ;
    free_image_data(data);
}

void mirror_total(char *source_path) {
    unsigned char* data = NULL ;
    int w = 0, h = 0, n = 0, l, i, j;
    read_image_data(source_path, &data, &w, &h, &n) ;

    for(j = 0; j < h/2; j++) {
        for(i = 0; i < w ; i++) {
            int a = (j * w + i)*n;
            int b = ((h - 1 - j)*w + (w -1 -i)) * n;

            for (l = 0; l<n; l++){
                unsigned char t = data[a + l];
                data[a + l] = data[b + l];
                data[b + l] = t;
            }
        }
    }

    if (h%2 == 1){
        int middle = h/2;
        for (i = 0; i<w/2; i++){
             int a = (middle * w + i) * n;
             int b = (middle * w + (w - 1 -i)) * n;

             for(l=0; l<n; l++){
                unsigned char t = data[a + l];
                data[a + l] = data[b + l];
                data[b + l] = t;
             }
        }
    }
    write_image_data("image_out.bmp", data, w, h) ;
    free_image_data(data);
}

void rotate_acw(char *source_path){
    unsigned char* data = NULL;
    int w, h, n, x, y;
    read_image_data(source_path, &data, &w, &h, &n);
    unsigned char* rotate_data = malloc(w * h * n);
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){      
            pixelRGB* current_pixel = get_pixel(data, w, h, n, x, y);
            int nouveau_x = y;
            int nouveau_y = w - 1 - x;
            pixelRGB* rotate_pixel = get_pixel(rotate_data, h, w, n, nouveau_x, nouveau_y);
            rotate_pixel->R = current_pixel->R;
            rotate_pixel->G = current_pixel->G;
            rotate_pixel->B = current_pixel->B;
        }
    }
    write_image_data("image_out.bmp", rotate_data, h, w);
}

void rotate_cw(char *source_path){
    unsigned char* data = NULL;
    int w, h, n, x, y;
    read_image_data(source_path, &data, &w, &h, &n);
    unsigned char* rotate_data = malloc(w * h * n);
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){      
            pixelRGB* current_pixel = get_pixel(data, w, h, n, x, y);
            int nouveau_x = h - 1 - y;
            int nouveau_y = x;
            pixelRGB* rotate_pixel = get_pixel(rotate_data, h, w, n, nouveau_x, nouveau_y);
            rotate_pixel->R = current_pixel->R;
            rotate_pixel->G = current_pixel->G;
            rotate_pixel->B = current_pixel->B;
        }
    }
    write_image_data("image_out.bmp", rotate_data, h, w);
}

void scale_crop(char *source_path, int c_x, int c_y, int crop_w, int crop_h) {
    unsigned char *data = NULL;
    int w, h, channel_count;
 
    read_image_data(source_path, &data, &w, &h, &channel_count);
 
    int start_x = c_x - crop_w / 2;
    int start_y = c_y - crop_h / 2;
 
    unsigned char *cropped_data = malloc(crop_w * crop_h * channel_count);
 
    for (int j = 0; j < crop_h; j++) {
        for (int i = 0; i < crop_w; i++) {
            int src_x = start_x + i;
            int src_y = start_y + j;
 
            for (int c = 0; c < channel_count; c++) {
                if (src_x >= 0 && src_x < w && src_y >= 0 && src_y < h) {
                    cropped_data[(j * crop_w + i) * channel_count + c] =
                        data[(src_y * w + src_x) * channel_count + c];
                } else {
                    // Remplir en noir si on sort de l'image
                    cropped_data[(j * crop_w + i) * channel_count + c] = 0;
                }
            }
        }
    }
 
    write_image_data("image_out.bmp", cropped_data, crop_w, crop_h);
}

void scale_nearest(char *source_path, float scale) {
    if (scale <= 0.0f) {
        printf("Un facteur d’échelle strictement positif est requis.\n");
        return;
    }
 
    unsigned char *data = NULL;
    int w = 0, h = 0, channel_count = 0;
 
    read_image_data(source_path, &data, &w, &h, &channel_count);
 
    int nouveau_w = (int)(w * scale);
    int nouveau_h = (int)(h * scale);
 
    unsigned char *n_data = malloc(nouveau_w * nouveau_h * channel_count);
    if (n_data == NULL) {
        printf("Allocation mémoire impossible.\n");
        return;
    }
 
    for (int nouveau_y = 0; nouveau_y < nouveau_h; nouveau_y++) {
        for (int nouveau_x = 0; nouveau_x < nouveau_w; nouveau_x++) {
            int ancien_x = (int)(nouveau_x / scale);
            int ancien_y = (int)(nouveau_y / scale);
 
            if (ancien_x >= w) ancien_x = w - 1;
            if (ancien_y >= h) ancien_y = h - 1;
 
            for (int c = 0; c < channel_count; c++) {
                n_data[(nouveau_y * nouveau_w + nouveau_x) * channel_count + c] =
                    data[(ancien_y * w + ancien_x) * channel_count + c];
            }
        }
    }
 
    write_image_data("image_out.bmp", n_data, nouveau_w, nouveau_h);
}