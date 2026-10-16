//Samuel Esparza
//Due October 15, 2026

//Description - Reads pixel data from a file, calculates the average RGB
// values, flips the image vertically, and saves the flipped pixels to a new file.

//FILE FUCNTION - Reads pixel data, stores it in a vector, calls the
// processing functions, and saves the flipped data to flipped.dat.

//HOW TO USE PROGRAM -
//Compile using:
// g++ -o main main.cpp pixel_functions.cpp
//
// Run the program using:
// ./main pixels.dat
//
// The program will create a new file called flipped.dat.






#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "pixel.h"
#include "pixel_functions.h"



int main(int argc, char *argv[])
{
	//Make sure that the user provided a filename
	if (argc < 2)
	{
		std::cout << "Please enter a file name." << std::endl;
		return 1;
	}

	//Store the filename from our command line
	std::string filename = argv[1];

	//display file name
	std::cout << "File to read: " << filename << std::endl;

	//Open the File
	std::ifstream inputFile(filename);

	//make sure that file opened up OK
	if (!inputFile.is_open())
	{
		std::cout << "Error opening file." << std::endl;
		return 1;
	}


	//Vector that will store all pixels from the pixels.dat
	std::vector<Pixel> pixel_list;

	//String used to hold one line from the file
	std::string line;

//Read the file one line at a time
	while (std::getline(inputFile, line))
	{
		//Find the location of each comma
		size_t comma1 = line.find(',');
		size_t comma2 = line.find(',', comma1 + 1);
		size_t comma3 = line.find(',', comma2 + 1);
		size_t comma4 = line.find(',', comma3 + 1);

		//seperating the 5 values between the commas
		std::string xString = line.substr(0, comma1);

		std::string yString = line.substr(comma1 + 1, comma2 - comma1 - 1);

		std::string rString = line.substr(comma2 + 1, comma3 - comma2 - 1);

		std::string gString = line.substr(comma3 + 1, comma4 - comma3 - 1);


		std::string bString = line.substr(comma4 + 1);

		//Create one pixel
		Pixel pixel;

		//convert strings to integers and floats
		pixel.x = std::stoi(xString);
		pixel.y = std::stoi(yString);

		pixel.r = std::stof(rString);
		pixel.g = std::stof(gString);
		pixel.b = std::stof(bString);

		//Add the pixel to the vector
		pixel_list.push_back(pixel);

	}

	//Display how many pixels were read
	std::cout << "Total pixels read: " << pixel_list.size() <<std::endl;

	//Close the file
	inputFile.close();

	//Calculate and display the average RGB values
	average_colors(pixel_list);

	//Flip the pixels vertically
	flip_vertically(pixel_list);

	//Create the output file
	std::ofstream outputFile("flipped.dat");

	//Make sure the output file opened correctly
	if (!outputFile.is_open())
	{
		std::cout << "Error creating flipped.dat." << std::endl;
		return 1;
	}

	//Write all flipped pixels to the output file
	for (int row = 0; row < pixel_list.size(); row++)
	{
		outputFile << pixel_list[row].x << ","
				   << pixel_list[row].y << ","
				   << pixel_list[row].r << ","
				   << pixel_list[row].g << ","
				   << pixel_list[row].b << std::endl;
	}

	//Close the output file
	outputFile.close();

	std::cout << "Flipped pixels saved to flipped.dat" << std::endl;


	return 0;
}
