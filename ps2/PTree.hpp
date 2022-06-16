/*
 * PTree.hpp
 *
 *  Created on: Feb 13, 2020
 *      Author: Kyle Savoie
 */

#ifndef PTREE_HPP_
#define PTREE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

using namespace std;
using namespace sf;

class PTree : public sf::Drawable {
public:
	//constructor
	PTree(double L, int N);
	//overridden draw funct
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	//draw recurvie function
	void drawPTree(sf::RenderTarget& target, const int N, const sf::RectangleShape& parent);
	//draw 1st square function
	void drawPTree(sf::RenderTarget& target, const PTree tree);	
private:
	//a PTree holds a series of squares
	std::vector<sf::RectangleShape> squares;
	int length = 0;
  	int depth = 0;
};

#endif
