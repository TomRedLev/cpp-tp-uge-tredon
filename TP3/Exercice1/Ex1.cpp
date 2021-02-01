#include <iostream>
#include <vector>

struct AbsolutePoint {
  double x = 0.0, y = 0.0;
};

AbsolutePoint default_origin;
AbsolutePoint default_shift {1.0, 1.0};

class RelativePoint {
  const AbsolutePoint& _origin;
  AbsolutePoint        _shift;
  
public:
  RelativePoint(const AbsolutePoint shift = default_shift, const AbsolutePoint& origin = default_origin) :
    _origin { origin },
    _shift { shift }
  {}

  double get_x() const { return _origin.x + _shift.x; }
  double get_y() const { return _origin.y + _shift.y; }
};

int main(int argc, char const *argv[])
{
    std::vector<RelativePoint>(3);
    return 0;
}
