#pragma	once

#include "GL/opengl_interface.hpp"
#include "aircraft.hpp"
#include <memory>
#include <vector>
#include <utility>

class AircraftManager : public GL::DynamicObject
{
	private :
		std::vector<std::unique_ptr<Aircraft>> aircrafts {};
		int crash_number           = 0;
	public :
		void add_aircraft(std::unique_ptr<Aircraft> aircraft)
		{
			aircrafts.emplace_back(std::move(aircraft));
		}

		bool update() override
		{
			// std::sort(aircrafts.begin(), aircrafts.end(),
			// 	[](std::unique_ptr<Aircraft> &a, std::unique_ptr<Aircraft> &b)
			// 	{
			// 		if (a->has_terminal() && !b->has_terminal())
			// 		{
			// 			return true;
			// 		}
			// 		else if (!a->has_terminal() && b->has_terminal())
			// 		{
			// 			return false;
			// 		}
			// 		if (a->get_fuel() < b->get_fuel())
			// 		{
			// 			return true;
			// 		}
			// 		return false;
			// 	});
			aircrafts.erase(std::remove_if(aircrafts.begin(), aircrafts.end(),
				[this](std::unique_ptr<Aircraft>& aircraft_it) {
					auto& aircraft = *aircraft_it;
					try
					{
						return !aircraft.update();
					}
					catch (const AircraftCrash& err)
					{
						std::cerr << err.what() << std::endl;
						crash_number++;
						return true;
					}
				}), aircrafts.end());
			return true;
		}

		int airlines_number(std::string airline)
		{
			auto counter = std::count_if(aircrafts.begin(), aircrafts.end(),
			[airline](std::unique_ptr<Aircraft>& aircraft_it) {
				auto& aircraft = *aircraft_it;
				auto& str = aircraft.get_flight_num();
				if (airline == str.substr(0, 2)){
					return true;
				}
				return false;
			});
			return counter;
		}

		int number_of_crash()
		{
			return crash_number;
		}
};
