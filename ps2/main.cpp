#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "PTree.hpp"

int main(int argc, char *argv[])
{
        //check for correct number of arguments
        if (argc != 3)
        {
		std::cout << "Incorrect command line argument format.\n Use the format:\n % tree size_of_base_square depth_of_recursion" << std::endl;
                return EXIT_FAILURE;
        }

	//initialize arguments
	unsigned int L = 0.0;
	unsigned int N = 0;


	//pull command lind arguments for length and recrusive depth
        L = atoi(argv[1]);
        N = atol(argv[2]);

	//create PTree
	PTree tree(L, N);

	//45/45/90 window
	//sf::RenderWindow standardWindow{{6*L, 4*L}, "Pythagoras Tree"};

	//30/60/90
	sf::RenderWindow standardWindow{{9*L, 5*L}, "Pythagoras Tree"};

	//extra feature music
	sf::Music music;

	if (!music.openFromFile("music.ogg"))
	{
		std::cout << "Music file failed to open" << std::endl;
		return EXIT_FAILURE;
	}

	music.play();

        //running
        while (standardWindow.isOpen())
        {
                sf::Event event;
                //close window
                while (standardWindow.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
			{
				music.stop();
				standardWindow.close();
			}
                }

                //window display
                standardWindow.clear(sf::Color::Black);
		tree.drawPTree(standardWindow, tree);
		standardWindow.draw(tree);
                standardWindow.display();
        }

        return 0;
}

