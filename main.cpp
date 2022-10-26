/**
 * Sample code for stb_image* (CS 150)
 * @author Steve G.
 */
#define STB_IMAGE_IMPLEMENTATION        // REQUIRED (loading)
#define STB_IMAGE_WRITE_IMPLEMENTATION  // (writing)
#include "stb_image.h"                  // "header-only" C libraries
#include "stb_image_write.h"
 
#include <iostream>
using namespace std;

int main()
{
    // Just some samples for class
    // 1. Load a jpg file using 4 bytes per pixel (bpp RGBA)
    int width, height, bpp, channels = 4;
    unsigned char * const pete = 
        stbi_load("pete.jpg",               // input file
                    &width, &height, &bpp,  // pointers (out)
                    channels);              // channels (in)
    
    // Now write it out in current folder as a 4-bytes-per-pixel PNG
    stbi_write_png("pete.png", width, height, channels, pete, 
                    width * channels);
    
    // IMPORTANT - free the memory
    stbi_image_free(pete);
    
    // 2. Load a png file using 1 byte per pixel (Gray scale)
    channels = 1;
    unsigned char * const stego = stbi_load("stegosaurus.png", 
                                        &width, &height, &bpp, channels);
    stbi_write_bmp("stego-bw.bmp", width, height, channels, stego);
    stbi_image_free(stego);
    
    // 3. Load a png file using 3 bytes (RGB only)
    channels = 3;
    int quality = 50; // medium quality jpg
    auto vermeer = stbi_load("Vermeer-Milkmaid.png", &width, &height, &bpp, channels);
    stbi_write_jpg("vermeer.jpg", width, height, channels, vermeer, quality);
    stbi_image_free(vermeer);
}
