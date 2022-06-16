#include "NBody.hpp"

//default constructor
CelestialBody::CelestialBody()
{
	return;
}
//constructor
CelestialBody::CelestialBody(double pos_x, double pos_y, double vel_x, double vel_y,
double mass_obj, double radius_universe, std::string file_name)
{
	//set memeber variables
	_pos_x = pos_x;
	_pos_y = pos_y;
	_vel_x = vel_x;
	_vel_y = vel_y;
	_mass_obj = mass_obj;
	_radius_universe = radius_universe;
	_file_name = file_name;

	//load the image into an image object
	if (!_image.loadFromFile(file_name))
	{
		//return;
		return;
	}

	//load image into a texture
	_texture.loadFromImage(_image);

	//load texture into a sprite
	_sprite.setTexture(_texture);

	//set position
	_sprite.setPosition(sf::Vector2f(_pos_x, _pos_y));
}

//sets universe radius
void CelestialBody::set_radius(float radius_universe)
{
	_radius_universe = radius_universe;
	return;
}

//sets the position of the body
void CelestialBody::set_position()
{
	_pos_x = ((_pos_x / _radius_universe) * (window_side / 2)) + (window_side / 2);
	_pos_y = ((_pos_y / _radius_universe) * (window_side / 2)) + (window_side / 2);

	_sprite.setPosition(sf::Vector2f(_pos_x, _pos_y));
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite);
}

//overridden draw function
//void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states, std::shared_ptr<CelestialBody>& spCelestialBody) const
//{
//	target.draw(*spCelestialBody);
//}

//overridden >> function for file input
std::istream& operator>>(std::istream &input, CelestialBody &currentCelestialBody)
{
	//this could be wrong, so watch this part
	
	//read file input into the object
	input >> currentCelestialBody._pos_x >> currentCelestialBody._pos_y;
	input >> currentCelestialBody._vel_x >> currentCelestialBody._vel_y;
	input >> currentCelestialBody._mass_obj >> currentCelestialBody._file_name;

	//set up images
	
	//load image into an image object
	if (!currentCelestialBody._image.loadFromFile(currentCelestialBody._file_name))
	{
		return input;
	}

	//load the image into a texture
	currentCelestialBody._texture.loadFromImage(currentCelestialBody._image);

	//load texture into a sprite
	currentCelestialBody._sprite.setTexture(currentCelestialBody._texture);

	//set the initial position
	
	return input;
}

/*
std::ostream& operator<<(std::ostream &output, CelestialBody &currentCelestialBody)
{
	// For debugging, output all the data stored in the object.
  	output << "Filename: " << currentCelestialBody._file_name << std::endl;
  	output << "Pos (x): " << currentCelestialBody._pos_x << std::endl;
  	output << "Pos (y): " << currentCelestialBody._pos_y << std::endl;
  	output << "Vel (x): " << currentCelestialBody._vel_x << std::endl;
  	output << "Vel (y): " << currentCelestialBody._vel_y << std::endl;
  	output << "Mass: " << currentCelestialBody._mass_obj << std::endl << std::endl;

  	return output;
}
*/
