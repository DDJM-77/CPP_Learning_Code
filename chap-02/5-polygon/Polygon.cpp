#include "Polygon.h"

#include <string>

void Polygon::add_vertex(int x, int y)
{
    _vertices.push_back(Vertex(x, y));
}

const Vertex& Polygon::get_vertex(size_t indx) const
{
    return _vertices[indx];
}

std::ostream& operator<<(std::ostream& stream, const Polygon& polygon)
{
    for (const auto& v : polygon._vertices)
    {
        stream << "(" << v.first << "," << v.second << ") ";
    }

    return stream;
}