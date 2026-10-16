//Samuel Esparza
//Due October 15, 2026

//FILE FUCNTION - Contains the functions used to calculate the
// average RGB values and flip the pixels vertically.






#include <iostream>
#include <vector>
#include "pixel.h"
#include "pixel_functions.h"





// Calculate the average red, green, and blue values
void average_colors(std::vector<Pixel> &pixel_list)
{
    float redSum = 0.0;
    float greenSum = 0.0;
    float blueSum = 0.0;

    // Add all RGB values
    for (int i = 0; i < pixel_list.size(); i++)
    {
        redSum = redSum + pixel_list[i].r;
        greenSum = greenSum + pixel_list[i].g;
        blueSum = blueSum + pixel_list[i].b;
    }

    // Calculate averages
    float redAverage = redSum / pixel_list.size();
    float greenAverage = greenSum / pixel_list.size();
    float blueAverage = blueSum / pixel_list.size();

    // Display averages
    std::cout << "Average Red: " << redAverage << std::endl;
    std::cout << "Average Green: " << greenAverage << std::endl;
    std::cout << "Average Blue: " << blueAverage << std::endl;
}





//Flips all pixels vertically
void flip_vertically(std::vector<Pixel> &pixel_list)
{
    int height = 256;

    for (int x = 0; x < 512; x++)
    {
        for (int y = 0; y < height / 2; y++)
        {
            int top = x * height + y;
            int bottom = x * height + (height - 1 - y);

            float tempR = pixel_list[top].r;
            float tempG = pixel_list[top].g;
            float tempB = pixel_list[top].b;

            pixel_list[top].r = pixel_list[bottom].r;
            pixel_list[top].g = pixel_list[bottom].g;
            pixel_list[top].b = pixel_list[bottom].b;

            pixel_list[bottom].r = tempR;
            pixel_list[bottom].g = tempG;
            pixel_list[bottom].b = tempB;
        }
    }
}











