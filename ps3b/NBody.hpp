#ifndef NBODY_HPP_
#define NBODY_HPP_

#include <math.h>
#include <memory>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

const int window_side = 1000;

const double gravity = 6.67e-11;

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

	//gets position
	double get_xPos();
	double get_yPos();

	//force functions
	friend double get_xForce(CelestialBody &body1, CelestialBody &body2);
	friend double get_yForce(CelestialBody &body1, CelestialBody &body2);
	void set_forces(double xForce, double yForce);

	//time
	void step(double time_t);

	//operator overrides
	friend std::istream& operator>>(std::istream &input, CelestialBody &currentCelestialBody);
	friend std::ostream& operator<<(std::ostream &output, CelestialBody &currentCelestialBody);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	//overridden draw function
        //void virtual draw(sf::RenderTarget& target, sf::RenderStates states, std::shared_ptr<CelestialBody>& spCelestialBody) const;

	//member vars
	double _pos_x, _pos_y;
	double _vel_x, _vel_y;
	double _acc_x, _acc_y;
	double _for_x, _for_y;
	double _mass_obj, _radius_obj;
	double _radius_universe;
	std::string _file_name;

	//image obj
	sf::Image _image;
	sf::Texture _texture;
	sf::Sprite _sprite;
};

#endif
