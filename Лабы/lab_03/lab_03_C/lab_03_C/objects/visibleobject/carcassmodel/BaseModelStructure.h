#ifndef BASEMODELSTRUCTURE_H
#define BASEMODELSTRUCTURE_H

#include <vector>

#include "Vertex.h"
#include "Transformer.h"
#include "Edge.h"
#include "Matrix.h"

class BaseModelStructure
{
public:
    virtual ~BaseModelStructure() = default;

    virtual void addVertex(const Vertex &vertex) = 0;
    virtual void addEdge(const Edge &edge) = 0;
    virtual void updateCenter() = 0;

    virtual const std::vector<Vertex> &getVertexes() const = 0;
    virtual const std::vector<Edge> &getEdges() const = 0;
    virtual const Vertex getCenter() const = 0;

    virtual void moveVertexesToOrigin(const Vertex &center) = 0;
    virtual void moveVertexesToCenter(const Vertex &center) = 0;
    virtual void transformVertexes(Transformer &mtr) = 0;
    virtual void transform(Transformer &mtr, const Vertex &center) = 0;
};

#endif // BASEMODELSTRUCTURE_H
