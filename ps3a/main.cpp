#include "NBody.hpp"
#include "Universe.hpp"

int main(int argc, char* argv[])
{
	std::string num_planets, uni_radius;
	std::cin >> num_planets;
	std::cin >> uni_radius;

	int number_planets = atoi(num_planets.c_str());
	float radius_universe  = atof(uni_radius.c_str());

	//std::cout << "Number of Planets: " << number_planets << std::endl;
	//std::cout << "Radius of Universe: " << radius_universe << std::endl;

	//create universe of specified radius
	Universe universe = Universe(number_planets, radius_universe);

	//create window
        sf::RenderWindow window(sf::VideoMode(window_side, window_side), "The Solar System");

        window.setFramerateLimit(1);

        //background image extra credit
        sf::Image background_image;
        if (!background_image.loadFromFile("background.jpg"))
        {
                exit(1);
        }

        //load image into a texture
        sf::Texture background_texture;
        background_texture.loadFromImage(background_image);

        //load texture into a sprite
        sf::Sprite background_sprite;
        background_sprite.setTexture(background_texture);

        //set position
        //NOT DONE
	//window running
        while (window.isOpen())
        {
                sf::Event event;

                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                        {
                                window.close();
                        }
                }

		window.clear();
		window.draw(background_sprite);
		//display bodies
		std::vector<std::shared_ptr<CelestialBody>>::iterator it;
                for(it = universe.bodyCount.begin(); it != universe.bodyCount.end(); it++)
                {
                        window.draw(**it);
                }
		window.display();

         }

	return 0;
}
