#ifndef BASE_CARCASS_MODEL_READER_H
#define BASE_CARCASS_MODEL_READER_H

#include <string>
#include <vector>

#include "Vertex.h"
#include "Edge.h"

class BaseCarcassModelReader
{
public:
    BaseCarcassModelReader() = default;
    ~BaseCarcassModelReader() = default;

    virtual std::size_t readCount() = 0;
    virtual Vertex readVertex() = 0;
    virtual std::vector<Vertex> readVertexes() = 0;
    virtual std::vector<Edge> readEdges(std::size_t &vertexNum) = 0;
};

#endif // BASE_CARCASS_MODEL_READER_H
