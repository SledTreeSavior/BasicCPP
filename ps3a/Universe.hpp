#ifndef UNIVERSE_HPP_
#define UNIVERSE_HPP_

#include "NBody.hpp"

//const int window_side = 500;

class Universe{
public:
        Universe();
        Universe(int number_planets, double radius_universe);
	std::vector<std::shared_ptr<CelestialBody>> bodyCount;
private:
	int _number_planets;
	double _radius_universe;
        //std::vector<std::shared_ptr<CelestialBody>> bodyCount;
};

#endif
