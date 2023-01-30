#pragma once

#include <ostream>

class Rectangle
{
public:
    Rectangle(float length, float width);
    /*Rectangle(float length, float width)
        : _length { length }
        , _width { width }
    {}*/

    float get_length() const { return _length; }
    float get_width() const { return _width; }

    void scale(float ratio);
    /*void scale(float ratio)
    {
        _length *= ratio;
        _width *= ratio;
    }*/

    Rectangle(float board);

    Rectangle();

    static void set_default_size(float size);

private:
    float        _length;
    float        _width;
    static float _default_size;
};

std::ostream& operator<<(std::ostream& stream, const Rectangle& rect);
