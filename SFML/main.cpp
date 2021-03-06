#include <SFML/Graphics.hpp>

int main()
{
    int x = 0;
    int y = 0;
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Texture texture;
    if(!texture.loadFromFile("sprite.png"))
      return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    sprite.setPosition(x, y);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	      {
		sprite.move(5.f,0.f);
	      }
	    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	      {
		sprite.move(-5.f,0.f);
	      }
	    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	      {
		sprite.move(0.f,-5.f);
	      }
	    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	      {
		sprite.move(0.f,5.f);
	      }
		//image will rotate with space bar
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
              {
		sprite.rotate(10.f);
	      }
        }

        window.clear();
        window.draw(shape);
	window.draw(sprite);
        window.display();
    }

    return 0;
}
