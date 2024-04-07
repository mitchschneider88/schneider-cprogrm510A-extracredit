#pragma once

#include <ostream>

class Point
{
public:
    Point() = default;
    Point(float x, float y);

    float getX() const;
    float getY() const;

    void setX(float coordinate);
    void setY(float coordinate);

private:
    float _x {};
    float _y {};

};

std::ostream& operator<<(std::ostream& stream, const Point& p);