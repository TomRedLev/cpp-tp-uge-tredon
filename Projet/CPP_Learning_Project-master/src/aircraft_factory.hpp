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
	std::vector<std::string_view> flight_num_list {};
public:
    [[nodiscard]] std::unique_ptr<Aircraft> createAircraft(const AircraftType& type_, const std::string_view& flight_number_, const Point3D& pos_,
             const Point3D& speed_, Tower& control_) const
			 {
				//addNum(flight_number_);
				return std::make_unique<Aircraft>(type_, flight_number_, pos_, speed_, control_);
			 }

	// bool addNum(const std::string_view flight_number_) const
	// {
	// 			 flight_num_list.emplace_back(flight_number_);
	// 			 return true;
	// }
};
