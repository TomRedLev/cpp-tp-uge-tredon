#pragma once

#include "GL/displayable.hpp"
#include "aircraft_types.hpp"
#include "config.hpp"
#include "geometry.hpp"
#include "tower.hpp"
#include "waypoint.hpp"

#include <string_view>
#include <vector>

class AircraftFactory
{
private :
	std::unordered_set<std::string_view> flight_num_list {};
	const std::array<std::string,8> airlines = { "AF", "LH", "EY", "DL", "KL", "BA", "AY", "EY" };
public:
	[[nodiscard]] std::unique_ptr<Aircraft> create_aircraft(const AircraftType& type, Tower& tower)
	{
		std::string flight_number = airlines[std::rand() % 8] + std::to_string(1000 + (rand() % 9000));
		while (!flight_num_list.insert(flight_number).second) {
			flight_number = airlines[std::rand() % 8] + std::to_string(1000 + (rand() % 9000));
		}
	    const float angle       = (rand() % 1000) * 2 * 3.141592f / 1000.f; // random angle between 0 and 2pi
	    const Point3D start     = Point3D { std::sin(angle), std::cos(angle), 0 } * 3 + Point3D { 0, 0, 2 };
	    const Point3D direction = (-start).normalize();
		return std::make_unique<Aircraft>(type, flight_number, start, direction, tower);
	}

	[[nodiscard]] std::unique_ptr<Aircraft> create_random_aircraft(Tower& tower)
	{
	    return create_aircraft(*(aircraft_types[rand() % 3]), tower);
	}

	const std::string get_airline(int num_airline) const
	{
		return airlines[num_airline];
	}
};
