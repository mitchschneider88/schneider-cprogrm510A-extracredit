#pragma once

#include "Shape.h"
#include "Point.h"

class Rectangle : public Shape
{
public:
	Rectangle(
		const Point& upperLeft,
		const Point& lowerRight,
		std::ostream& canvas);

	const Point& getUpperLeft() const;
	const Point& getLowerRight() const;

	void draw() const override;

	void stream(std::ostream& os) const override;

	int meaningOfLife() override;

	Color getColor() const override;

private:

	Point _upperLeft {};
	Point _lowerRight {};
	std::ostream& _canvas;
};