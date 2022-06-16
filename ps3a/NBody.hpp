#ifndef NBODY_HPP_
#define NBODY_HPP_

#include <memory>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

const int window_side = 500;

class CelestialBody : public sf::Drawable{
public:
      	//default constructor
	CelestialBody();
	//constructor
	CelestialBody(double pos_x, double pos_y, double vel_x, double vel_y, 
		double mass_obj, double radius_universe, std::string file_name);
	//sets the universe radius
	void set_radius(float universe_radius);
	//sets the position of the body
	void set_position();
	friend std::istream& operator>>(std::istream &input, CelestialBody &currentCelestialBody);
	friend std::ostream& operator<<(std::ostream &output, CelestialBody &currentCelestialBody);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	//overridden draw function
        //void virtual draw(sf::RenderTarget& target, sf::RenderStates states, std::shared_ptr<CelestialBody>& spCelestialBody) const;

	double _pos_x, _pos_y;
	double _vel_x, _vel_y;
	double _mass_obj;
	double _radius_universe;
	std::string _file_name;

	sf::Image _image;
	sf::Texture _texture;
	sf::Sprite _sprite;
};

#endif
