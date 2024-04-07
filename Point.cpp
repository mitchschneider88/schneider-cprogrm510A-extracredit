#include "Point.h"

Point::Point(float x, float y) : _x(x), _y(y)
{}

float Point::getX() const
{
    return _x;
}

float Point::getY() const
{
    return _y;
}

void Point::setX(float coordinate)
{
    _x = coordinate;
}

void Point::setY(float coordinate)
{
    _y = coordinate;
}

std::ostream& operator<<(std::ostream& stream, const Point& p)
{
    stream << p.getX() << "," << p.getY();
    return stream;
}