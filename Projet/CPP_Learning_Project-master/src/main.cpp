
#include "tower_sim.hpp"

void test_generic_points()
{
	Point<int, 2> p1 {1, 2};
	Point<int, 2> p2 {1, 2};
	auto p3 = p1 + p2;
	p1 += p2;
	p1 *= 3;
	p3 *= 3;
}

int main(int argc, char** argv)
{
    TowerSimulation simulation { argc, argv };
	test_generic_points();
    simulation.launch();

    return 0;
}
