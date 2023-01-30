#pragma once

#include <ostream>
#include <utility>
#include <vector>

using Vertex = std::pair<int, int>;

class Polygon
{
public:
    void                 add_vertex(int x, int y);
    friend std::ostream& operator<<(std::ostream& stream, const Polygon& polygon);
    const Vertex&        get_vertex(size_t indx) const;

private:
    std::vector<Vertex> _vertices;
};
