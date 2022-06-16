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
	//_radius_universe = radius_universe;
	_file_name = file_name;

	//load the image into an image object
	if (!_image.loadFromFile(file_name))
	{
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

void CelestialBody::set_forces(double xForce, double yForce)
{
	_for_x = xForce;
	_for_y = yForce;
}

double get_xForce(CelestialBody &body1, CelestialBody &body2)
{
	/*
	 * Formulas:
	 * F = (G * M1 * M2) / R^2
	 * R = given
	 * R^2 = R^2
	 * Δx = x2 - x1
	 * Δy = y2 - y1
	 */

	double dx = body2._pos_x - body1._pos_x;
	double dy = body2._pos_y - body1._pos_y;
	double R2 = pow(dx, 2) + pow(dy, 2);
	double R = sqrt(R2);
	double force = (gravity * body1._mass_obj * body2._mass_obj) / R2;
	double for_x = force * (dx / R);

	std::cout << "Body1 Filename: " << body1._file_name << "\n";
  	std::cout << "dx: " << dx << "\n";
  	std::cout << "dy: " << dy << "\n";
  	std::cout << "Force: " << force << "\n";
  	std::cout << "Force(x) " << for_x << "\n";
  	std::cout << "Gravity: " << gravity << "\n";
	std::cout << "body1 Mass: " << body1._mass_obj << "\n";
  	std::cout << "body2 Mass: " << body2._mass_obj << "\n\n";

	return for_x;
}

double get_yForce(CelestialBody &body1, CelestialBody &body2)
{
        /*
         * Formula:
	 * F = (G * M1 * M2) / R^2
         */

        double dx = body2._pos_x - body1._pos_x;
        double dy = body2._pos_y - body1._pos_y;
        double R2 = pow(dx, 2) + pow(dy, 2);
        double R = sqrt(R2);
        double force = (gravity * body1._mass_obj * body2._mass_obj) / R2;
        double for_y = force * (dy / R);

        std::cout << "Body1 Filename: " << body1._file_name << "\n";
        std::cout << "dx: " << dx << "\n";
        std::cout << "dy: " << dy << "\n";
        std::cout << "Force: " << force << "\n";
        std::cout << "Force(y) " << for_y << "\n";
        std::cout << "Gravity: " << gravity << "\n";
        std::cout << "body1 Mass: " << body1._mass_obj << "\n";
        std::cout << "body2 Mass: " << body2._mass_obj << "\n\n";

        return for_y;
}

void CelestialBody::step(double time_t)
{
	/*
	 * force ---> acceleration
	 *
	 * F = m * a
	 * Ax = Fx / m
	 * Ay = Fy / m
	 */

	_acc_x = _for_x / _mass_obj;
	_acc_y = _for_y / _mass_obj;

	/*
	 * calculate change in velocity
	 *
	  dvelx = (ax * time_step)
  	 * _velx = = _velx + (ax * time_step)
  	 *
  	 * (vx + Δt ax, vy + Δt ay)
  	 *
  	 */

	_vel_x = _vel_x + (_acc_x * time_t);
	_vel_y = _vel_y + (_acc_y * time_t);

	/*
   	* Body moves based on its velocity
   	*
   	* _xpos = _xpos + (_xvel * time_step)
   	*
   	* (px + Δt vx, py + Δt vy)
   	*
   	*/

	_pos_x = _pos_x + (_vel_x * time_t);
	_pos_y = _pos_y + (_vel_y * time_t);
}


//sets the position of the body
void CelestialBody::set_position()
{
	_pos_x = ((_pos_x / _radius_universe) * (window_side / 2)) + (window_side / 2);
	_pos_y = ((_pos_y / _radius_universe) * (window_side / 2)) + (window_side / 2);

	_sprite.setPosition(sf::Vector2f(_pos_x, _pos_y));
}

//get position
double CelestialBody::get_xPos()
{
	return _pos_x;
}	

double CelestialBody::get_yPos()
{
	return _pos_y;
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
