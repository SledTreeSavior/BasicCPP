#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include "FibLFSR.hpp"

void transform(sf::Image& output_file, FibLFSR* input_seed);

int main(int argc, char *argv[])
{
	//check for correct number of arguments
	if (argc != 4)
	{
		std::cout << "Incorrect command line argument format.\n Use the format:\n % Photomagic input-file.png output-file.png 1011011000110110" << std::endl;
		return EXIT_FAILURE;
	}
	
	//create FibLFSR from input seed (CORRECTLY GETS SEED)
	FibLFSR input_seed(argv[3]);
	//std::cout << input_seed << std::endl;

	//load input-image file from disk (CORRECTLY LOADS IMAGE)
	sf::Image input_file;
	if(!input_file.loadFromFile(argv[1]))
		return EXIT_FAILURE;

	//load output-image file from disk (CORRECTLY LOADS IMAGE)
	sf::Image output_file;
	if(!output_file.loadFromFile(argv[1]))
		return EXIT_FAILURE;

	//get image size as Vector2u (CORRECTLY GETS IMAGE SIZE)
	sf::Vector2u size = input_file.getSize();
	
	//transform
	FibLFSR* input_seed_pointer = &input_seed;
	transform(output_file, input_seed_pointer);
	output_file.saveToFile(argv[2]);

	//create window of correct size for input-file
	sf::RenderWindow input_window(sf::VideoMode(size.x, size.y), "Input File...");

	//create window of correct size for output-file
	sf::RenderWindow output_window(sf::VideoMode(size.x, size.y), "Output File...");

	//create texture with input-file
	sf::Texture input_file_texture;
	if (!input_file_texture.loadFromFile("./input-file.png"))
	{
		return EXIT_FAILURE;
	}

	//create texture with output-file
	sf::Texture output_file_texture;
	if (!output_file_texture.loadFromFile("./output-file.png"))
	{
		return EXIT_FAILURE;
	}

	//create sprite with input-file texture
	sf::Sprite input_file_sprite(input_file_texture);

	//create sprite with output-file texture
	sf::Sprite output_file_sprite(output_file_texture);

	//running
	while (input_window.isOpen() && output_window.isOpen())
	{
		sf::Event event;
		//close both windows when one is closed
		while (input_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				input_window.close();
		}

		while (output_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				output_window.close();
		}

		//input_window display
        	input_window.clear();
        	input_window.draw(input_file_sprite);
        	input_window.display();

        	//output_window display
        	//input_window display
        	output_window.clear();
        	output_window.draw(output_file_sprite);
        	output_window.display();
	}

	if (!output_file.saveToFile(argv[2]))
		return EXIT_FAILURE;

	return 0;
}

void transform(sf::Image& output_file, FibLFSR* input_seed)
{
	sf::Color pixel_rgb;
	//get image size as Vector2u (CORRECTLY GETS IMAGE SIZE)
        sf::Vector2u size = output_file.getSize();

	//loop through every pixel in the input_image
	//XOR the r, g, and b values
	//set the output_image pixels to the modified r, g, and b values
	//using unsigned ints for the loop for a higher max value
	//because there will never exist a negative number of pixels
	for (unsigned int x = 0; x < size.x; x++)
	{
		for (unsigned int y = 0; y < size.y; y++)
		{
			pixel_rgb = output_file.getPixel(x, y);
			pixel_rgb.r = pixel_rgb.r ^ input_seed->generate(8);
			pixel_rgb.g = pixel_rgb.g ^ input_seed->generate(8);
			pixel_rgb.b = pixel_rgb.b ^ input_seed->generate(8);
			output_file.setPixel(x, y, pixel_rgb);
		}
	}
}
