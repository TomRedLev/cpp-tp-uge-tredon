#include "aircraft_manager.hpp"

void AircraftManager::add_aircraft(const AircraftType& type_, const std::string_view& flight_number_, const Point3D& pos_,
		 const Point3D& speed_, Tower& control_)
{
	aircrafts.emplace_back(std::make_unique<Aircraft>( type_, flight_number_, pos_, speed_, control_ ));
}

void AircraftManager::move_aircrafts()
{

}
