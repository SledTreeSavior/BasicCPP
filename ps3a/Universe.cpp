#include "Universe.hpp"

//default constructor
Universe::Universe()
{
	return;
}

//constructor
Universe::Universe(int number_planets, double radius_universe)
{
	_number_planets = number_planets;
	_radius_universe = radius_universe;

	for (int i = 0; i < _number_planets; i++)
	{
		std::shared_ptr<CelestialBody> spCelestialBody(new CelestialBody());
		
		std::cin >> *spCelestialBody;

		spCelestialBody->set_radius(_radius_universe);
		spCelestialBody->set_position();

		bodyCount.push_back(spCelestialBody);

		//std::cout << *spCelestialBody;
	}	
}
