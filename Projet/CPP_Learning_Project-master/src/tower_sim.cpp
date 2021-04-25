#include "tower_sim.hpp"

#include "GL/opengl_interface.hpp"
#include "aircraft.hpp"
#include "aircraft_manager.hpp"
#include "aircraft_factory.hpp"
#include "airport.hpp"
#include "config.hpp"
#include "img/image.hpp"
#include "img/media_path.hpp"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std::string_literals;

TowerSimulation::TowerSimulation(int argc, char** argv) :
    help { (argc > 1) && (std::string { argv[1] } == "--help"s || std::string { argv[1] } == "-h"s) }
{
    MediaPath::initialize(argv[0]);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    GL::init_gl(argc, argv, "Airport Tower Simulation");

    create_keystrokes();

	GL::move_queue.emplace(&manager);
}

TowerSimulation::~TowerSimulation()
{
    delete airport;
}

[[nodiscard]] std::unique_ptr<Aircraft> TowerSimulation::create_aircraft(const AircraftType& type)
{
    assert(airport); // make sure the airport is initialized before creating aircraft
	return factory.create_aircraft(type, airport->get_tower());

}

[[nodiscard]] std::unique_ptr<Aircraft> TowerSimulation::create_random_aircraft()
{
	assert(airport);
    return factory.create_random_aircraft(airport->get_tower());
}

void TowerSimulation::create_keystrokes()
{
    GL::keystrokes.emplace('x', []() { GL::exit_loop(); });
    GL::keystrokes.emplace('q', []() { GL::exit_loop(); });
    GL::keystrokes.emplace('c', [this]() { manager.add_aircraft(create_random_aircraft()); });
    GL::keystrokes.emplace('+', []() { GL::change_zoom(0.95f); });
    GL::keystrokes.emplace('-', []() { GL::change_zoom(1.05f); });
    GL::keystrokes.emplace('f', []() { GL::toggle_fullscreen(); });
	// ADDED
	GL::keystrokes.emplace('p', []() { GL::pause = !GL::pause; });
	GL::keystrokes.emplace('z', []() { GL::ticks_per_sec = std::max(GL::ticks_per_sec - 1u, 1u); });
	GL::keystrokes.emplace('a', []() { GL::ticks_per_sec = std::min(GL::ticks_per_sec + 1u, 180u); });
	// TASK 2 :
	for (auto i = '0'; i < '8'; i++) {
        GL::keystrokes.emplace(i, [this, i]() { std::cout << factory.get_airline(i - '0') << " : " << manager.airlines_number(factory.get_airline(i - '0')) << std::endl; });
    }

	GL::keystrokes.emplace('m', [this]() { std::cout << manager.number_of_crash() << std::endl;});
}

void TowerSimulation::display_help() const
{
    std::cout << "This is an airport tower simulator" << std::endl
              << "the following keysstrokes have meaning:" << std::endl;

    for (const auto& [key, value]: GL::keystrokes)
    {
        std::cout << key << ' ';
    }

    std::cout << std::endl;
}

void TowerSimulation::init_airport()
{
    airport = new Airport { one_lane_airport, Point3D { 0, 0, 0 },
                            new img::Image { one_lane_airport_sprite_path.get_full_path() } };

    GL::move_queue.emplace(airport);
}

void TowerSimulation::launch()
{
    if (help)
    {
        display_help();
        return;
    }

    init_airport();
    init_aircraft_types();

    GL::loop();
}
