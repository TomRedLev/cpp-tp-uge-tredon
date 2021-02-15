#pragma once

#include "line.hpp"

class LineSegment: public Line {
protected:
	using Line::first;
	using Line::last;
public:
	using Line::Line;

	~LineSegment() = default;

	std::ostream& print(std::ostream& os) const override {
		return os << "line segment through " << first << " & " << last;
	}
};
