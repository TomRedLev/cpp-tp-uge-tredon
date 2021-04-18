#pragma once

#include "aircraft_manager.hpp"
#include "aircraft_factory.hpp"
class Airport;
struct AircraftType;

class TowerSimulation
{
private:
    bool help        = false;
    Airport* airport = nullptr;

	// TASK 1 :
	AircraftManager manager {};
	AircraftFactory factory {};

    TowerSimulation(const TowerSimulation&) = delete;
    TowerSimulation& operator=(const TowerSimulation&) = delete;

    [[nodiscard]] std::unique_ptr<Aircraft> create_aircraft(const AircraftType& type) const;
    [[nodiscard]] std::unique_ptr<Aircraft> create_random_aircraft() const;

    void create_keystrokes();
    void display_help() const;

    void init_airport();

public:
    TowerSimulation(int argc, char** argv);
    ~TowerSimulation();

    void launch();
};
