#include <SFML/Window.hpp>
#include <math.h>
#include "PTree.hpp"

PTree::PTree(double L, int N)
{
	length = L;
	depth = N;
}

void PTree::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = squares.size() - 1; i >= 0; i--)
	{
		target.draw(squares[i]);
	}
}

void PTree::drawPTree(sf::RenderTarget& target, const int N, const sf::RectangleShape& parent)
{
	//right triangle constant
	//static const float halfSqrt2 = sqrt(2.f) / 2;
	
	//30/60/90 triangle constant
	static const float Sqrt3 = sqrt(3.f) / 2;
	static const float half = 0.5;

	if (N < 1) return;
	squares.push_back(parent);

	auto const& size = parent.getSize();
	auto const& transformation = parent.getTransform();

	//right triangle
	/*
	auto leftChild = parent;					//copy parent
	leftChild.setSize(size * halfSqrt2);				//resize
	leftChild.setOrigin(0, leftChild.getSize().y);			//bottom left corner
	leftChild.setPosition(transformation.transformPoint({0, 0}));	//reposition
	leftChild.rotate(-45);
	leftChild.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	drawPTree(target, N - 1, leftChild);
	*/

	//30/60/90 triangle
	auto leftChild = parent;
	leftChild.setSize(size * Sqrt3);
	leftChild.setOrigin(0, leftChild.getSize().y);
	leftChild.setPosition(transformation.transformPoint({0, 0}));
	leftChild.rotate(-30);
	leftChild.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	drawPTree(target, N - 1, leftChild);

	//right triangle
	/*
	auto rightChild = parent;                           			//copy parent
        rightChild.setSize(size * halfSqrt2);                 			//resize
        rightChild.setOrigin(rightChild.getSize());        			//bottom left corner
        rightChild.setPosition(transformation.transformPoint({sz.x, 0}));  	//reposition
        rightChild.rotate(45);
	rightChild.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
        drawPTree(target, N - 1, rightChild);
	*/

	//30/60/90 triangle
	auto rightChild = parent;
        rightChild.setSize(size * half);
        rightChild.setOrigin(rightChild.getSize());
        rightChild.setPosition(transformation.transformPoint({size.x, 0}));
        rightChild.rotate(60);
        rightChild.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
        drawPTree(target, N - 1, rightChild);
}

void PTree::drawPTree(sf::RenderTarget& target, const PTree tree)
{
	//static const float Sqrt3 = sqrt(3.f) / 2;
	float length = tree.length;
	sf::RectangleShape firstRect{{length, length}};
	//set origin to center of the rect, easier to center position on screen
	firstRect.setOrigin(firstRect.getSize() / 2.f);
	firstRect.setPosition(target.getSize().x / 2.f, target.getSize().y - tree.length / 2.f);
	firstRect.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	drawPTree(target, tree.depth, firstRect);
}
