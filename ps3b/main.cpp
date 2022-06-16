#include "NBody.hpp"
#include "Universe.hpp"

int main(int argc, char* argv[])
{
	//check args
	if(argc != 3)
	{
		std::cout << "Format: ./NBody [simulation time] [step time] < planets.txt\n";
		return -1;
	}

	//get cmd args
	double simulation_time;
	simulation_time = atof(argv[1]);

	double step_time;
	step_time = atof(argv[2]);

	double current_simulation_time = 0;

	//test cmd args
	std::cout << "simulation_time: " << simulation_time << std::endl;
	std::cout << "step_time: " << step_time << std::endl;

	//get numbers from text file
	std::string num_planets, uni_radius;

	//redirect input
	std::cin >> num_planets;
	std::cin >> uni_radius;

	//convert
	int number_planets = atoi(num_planets.c_str());
	float radius_universe  = atof(uni_radius.c_str());

	//test cin args
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

	//load font
	sf::Font time_font;
	time_font.loadFromFile("Ubuntu-B.ttf");

	//create text
	sf::Text time_text;

	//choose font
	time_text.setFont(time_font);

	//set font size
	time_text.setCharacterSize(16);

	//set font color
	time_text.setFillColor(sf::Color::White);
	time_text.setOutlineColor(sf::Color::White);

	//music?
	//
	
	std::vector<std::shared_ptr<CelestialBody>>::iterator it;
	std::vector<std::shared_ptr<CelestialBody>>::iterator x, y;

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
		
		//draw bg
		window.draw(background_sprite);

		//update time
		time_text.setString("Time: " + std::to_string(current_simulation_time));

		//show text
		window.draw(time_text);

		//TRYING
		number_planets = universe.get_number_planets();
		x = universe.bodyCount.begin();
		double xForce, yForce;

		for(int a = 0; a < number_planets; a++)
		{
			y = universe.bodyCount.begin();
			xForce = 0;
			yForce = 0;

			for(int b = 0; b < number_planets; b++)
			{
				if(a != b)
				{
					xForce += get_xForce(**x, **y);
					yForce += get_yForce(**x, **y);
				}
				y++;
			}
			(**x).set_forces(xForce, yForce);
			x++;
		}

		//display bodies
		std::vector<std::shared_ptr<CelestialBody>>::iterator it;
                for(it = universe.bodyCount.begin(); it != universe.bodyCount.end(); it++)
                {
                        window.draw(**it);

			(**it).step(step_time);
			(**it).set_position();
                }

		window.display();

		current_simulation_time += step_time;

		if(current_simulation_time == simulation_time)
		{
			break;
		}
         }

	return 0;
}
