//Samuel Esparza
//Due October 15, 2026

//FILE FUCNTION - Declares the functions used to calculate the
// average RGB values and flip the pixels vertically.






#ifndef PIXEL_FUNCTIONS_H
#define PIXEL_FUNCTIONS_H


#include <vector>
#include "pixel.h"


// Calculates the average red, green, and blue values
void average_colors(std::vector<Pixel> &pixel_list);


//Flips all pixels vertically
void flip_vertically(std::vector<Pixel> &pixel_list);


#endif
