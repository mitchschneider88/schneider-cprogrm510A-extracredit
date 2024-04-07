#include "DerivedShape.h"

Rectangle::Rectangle(const Point& p1, const Point& p2, std::ostream& canvas) 
: _upperLeft(p1), _lowerRight(p2), _canvas(canvas) 
{
    _color = Color::Red;
};

const Point& Rectangle::getUpperLeft() const
{
    return _upperLeft;
}

const Point& Rectangle::getLowerRight() const
{
    return _lowerRight;
};

void Rectangle::draw() const
{
    _canvas << "draw red rectangle: ";
    stream(_canvas);
}

void Rectangle::stream(std::ostream& os) const
{
    os << getUpperLeft() << "," << getLowerRight();
}

int Rectangle::meaningOfLife()
{
    return 42;
}

Color Rectangle::getColor() const
{
    return Color::Red;
}