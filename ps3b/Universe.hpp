#ifndef UNIVERSE_HPP_
#define UNIVERSE_HPP_

#include "NBody.hpp"


class Universe{
public:
        Universe();
        Universe(int number_planets, double radius_universe);
	std::vector<std::shared_ptr<CelestialBody>> bodyCount;
	double get_number_planets();
private:
	int _number_planets;
	double _radius_universe;
        //std::vector<std::shared_ptr<CelestialBody>> bodyCount;
};

#endif
