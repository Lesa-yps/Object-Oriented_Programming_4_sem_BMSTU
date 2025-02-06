#include "ModelStructure.h"

ModelStructure::ModelStructure(std::vector<Vertex> &vertexes, std::vector<Edge> &edges)
    : _center{ }, _vertexes(vertexes), _edges(edges)
{

};


ModelStructure::ModelStructure(std::vector<Vertex> &vertexes, std::vector<Edge> &edges, Vertex &center)
    : _center(center), _vertexes(vertexes), _edges(edges)
{

};

auto ModelStructure::getVertexes() const -> const std::vector<Vertex> &
{
    return _vertexes;
}

auto ModelStructure::getEdges() const -> const std::vector<Edge> &
{
    return _edges;
}

auto ModelStructure::getCenter() const -> const Vertex
{
    return _center;
}

void ModelStructure::addVertex(const Vertex &vertex)
{
    _vertexes.push_back(vertex);
    updateCenter();
}

void ModelStructure::addEdge(const Edge &edge)
{
    _edges.push_back(edge);
}

void ModelStructure::updateCenter()
{
    _center = Vertex(0, 0, 0);
    size_t count = 0;
    for (const auto &element : _vertexes)
    {
        _center = _center + element.getCenter();
        count++;
    }
    _center = Vertex(_center.getX() / count, _center.getY() / count, _center.getZ() / count);
}

void ModelStructure::moveVertexesToOrigin(const Vertex &center)
{
    Vertex diff = Vertex(0, 0, 0) - center;
    //Transformer mtr = Transformer(diff.getX(), diff.getY(), diff.getZ(), 1, 1, 1, 0, 0, 0);
    TransformerMove mtr(diff.getX(), diff.getY(), diff.getZ());
    transformVertexes(mtr);
    updateCenter();
}

void ModelStructure::moveVertexesToCenter(const Vertex &center)
{
    Vertex diff = center - Vertex(0, 0, 0);
    TransformerMove mtr(diff.getX(), diff.getY(), diff.getZ());
    //Transformer mtr = Transformer(diff.getX(), diff.getY(), diff.getZ(), 1, 1, 1, 0, 0, 0);
    transformVertexes(mtr);
    updateCenter();
}

void ModelStructure::transformVertexes(Transformer &mtr)
{
    for (auto &vertex : _vertexes)
        vertex.transform(mtr);
}

void ModelStructure::transform(Transformer &mtr, const Vertex &center)
{
    updateCenter();
    moveVertexesToOrigin(center);
    transformVertexes(mtr);
    moveVertexesToCenter(center);
}
