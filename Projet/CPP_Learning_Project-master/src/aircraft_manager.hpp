#pragma	once

#include "aircraft.hpp"
#include "aircraft_types.hpp"
#include "config.hpp"
#include "geometry.hpp"

class AircraftManager
{
	private :
		std::vector<std::unique_ptr<Aircraft>> aircrafts;
	public :
		void add_aircraft();
		void move_aircrafts();
}
