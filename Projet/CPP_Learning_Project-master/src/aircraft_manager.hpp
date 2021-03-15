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
	public :
		void add_aircraft(std::unique_ptr<Aircraft> aircraft)
		{
			aircrafts.emplace_back(std::move(aircraft));
		}

		bool update() override
		{
			for (auto aircraft_it = aircrafts.begin(); aircraft_it != aircrafts.end();)
			{
				auto& aircraft = **aircraft_it;
				if (aircraft.update())
				{
					++aircraft_it;
				}
				else
				{
					aircraft_it = aircrafts.erase(aircraft_it);
				}
			}
			return true;
		}
};
