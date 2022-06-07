#include "shape.h"

//These are the operators you will be overloading
Point Point::operator + (const Point& p) const
{
    return Point(x + p.x, y + p.y);
}

Point& Point::operator += (const Point& p)
{
    x += p.x;
    y += p.y;

    return *this;
}

bool Point::operator == (const Point& p) const
{
    return (x == p.x && y == p.y)
}

ostream& operator << (ostream& out, const Point& p)
{
    
    out << "(" << p.x << "," << p.y << ")";

    return out;
}

Shape& Shape::operator = (const Shape& s)
{
    if (this == &s)
        return *this;

    center = s.center;
    color = s.color;

    return *this;
}

Shape& Shape::operator += (const Point& p)
{
    center += p;

    return *this;    
}

ostream& operator << (ostream& out, const Shape& s)
{
    //out << "Center: " << s.center << '\t'
    //    << "Color: " << s.color;
    //
    out << s.display();
    
    return out;

}

Shape Shape::operator + (const Shape & s) const
{
    Shape temp(s);

    temp.center += center;

    return temp;
}

Point operator + (const Point& p, const Shape& s)
{
    Point temp;

    temp = p + s.center;

    return temp;
}

Point operator + (const Shape& s, const Point& p)
{
    Point temp;

    temp = s.center + p;

    return temp;
}

Circle operator + (const Point& p, const Circle& c)
{
    Circle temp(c);

    temp += p;

    return temp;
}

Circle operator + (const Circle& c, const Point& p)
{

    return p + c;
}

Circle& Circle::operator = (const Circle& c)
{
    if (this == &c)
        return *this;

    this->Shape::operator=(c);

    radius = c.radius;

    return *this;
}


