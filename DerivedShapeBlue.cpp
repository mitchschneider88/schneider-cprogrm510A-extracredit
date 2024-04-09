#include "DerivedShape.h"

Rectangle::Rectangle(const Point& p1, const Point& p2, std::ostream& canvas) 
: _upperLeft(p1), _lowerRight(p2), _canvas(canvas) 
{
    _color = Color::Blue;
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
    _canvas << "draw blue rectangle: ";
    stream(_canvas);
}

void Rectangle::stream(std::ostream& os) const
{
    os << getUpperLeft() << "," << getLowerRight();
}

int Rectangle::meaningOfLife()

{
    return 43;
}

Color Rectangle::getColor() const
{
    return Color::Blue;
}

extern "C" Shape* create()
{
    std::stringstream ss;
    return new Rectangle({1.5,1.2}, {2.2,2.3}, ss);
}

extern "C" void destroy(Shape* s)
{
    delete s;
}