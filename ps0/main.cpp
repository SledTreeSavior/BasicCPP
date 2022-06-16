//Kyle Savoie
//In this program I have included the green circle from the
//tutorial and a custom sprite for which I chose an emoji.
//The sprite moves to a random location in the window any time
//that a key is pressed. This makes the sprite move and respond
//to keystrokes. My 'something else' feature makes the sprite 
//turn upside down and change colors to red whenever focus on
//the SFML window is lost.

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <random>

int main()
{
    //window
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML: Hello World!");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    //circle
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    //custom sprite texture
    sf::Texture texture;
    if (!texture.loadFromFile("./sprite.png"))
    {
	    return EXIT_FAILURE;
    }
    texture.setSmooth(true);

    //custom sprite
    sf::Sprite sprite(texture);
    sprite.setOrigin(240, 240);
    sprite.setPosition(400, 400);

    //running
    while (window.isOpen())
    {
	float x, y;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

	    if (event.type == sf::Event::KeyPressed)
	    {
		    std::random_device randomDevice;
		    std::mt19937 eng(randomDevice());
                    std::uniform_int_distribution<> distr(120, 680);
		    x = distr(eng);
		    y = distr(eng);
		    sprite.setPosition(sf::Vector2f(x, y));
	    }

	    if (event.type == sf::Event::LostFocus)
	    {
		sprite.setColor(sf::Color(255, 0, 0));
	        sprite.setRotation(180);
		texture.setSmooth(false);	
	    }
        }

	sprite.setScale(sf::Vector2f(0.5f, 0.5f));

        window.clear();
	window.draw(shape);
	window.draw(sprite);
        window.display();
    }

    return 0;
}
