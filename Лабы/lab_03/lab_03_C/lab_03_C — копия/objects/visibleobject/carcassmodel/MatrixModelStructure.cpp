#include "MatrixModelStructure.h"

MatrixModelStructure::MatrixModelStructure(const std::vector<Vertex> &vertexes, const Matrix<int> &adjMatrix) :
    _vertexes(vertexes), _adjMatrix(adjMatrix)
{
    updateCenter();
}

const std::vector<Vertex> &MatrixModelStructure::getVertexes() const
{
    return _vertexes;
}

const std::vector<Edge> &MatrixModelStructure::getEdges() const
{
    static std::vector<Edge> Edges;
    Edges.clear();
    for (size_t i = 0; i < _adjMatrix.get_rows(); ++i)
        for (size_t j = 0; j < _adjMatrix.get_cols(); ++j)
            if (_adjMatrix[i][j])
                Edges.emplace_back(i, j);
    return Edges;
}

const Vertex MatrixModelStructure::getCenter() const
{
    return _center;
}

void MatrixModelStructure::addVertex(const Vertex &vertex)
{
    _vertexes.push_back(vertex);
    size_t newSize = _adjMatrix.get_rows() + 1;
    _adjMatrix.resize(newSize, newSize);
    updateCenter();
}

void MatrixModelStructure::addEdge(const Edge &edge)
{
    _adjMatrix[edge.getFirst()][edge.getSecond()] = 1;
}

void MatrixModelStructure::updateCenter()
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

void MatrixModelStructure::moveVertexesToOrigin(const Vertex &center)
{
    Vertex diff = Vertex(0, 0, 0) - center;
    TransformerMove mtr(diff.getX(), diff.getY(), diff.getZ());
    //Transformer mtr = Transformer(diff.getX(), diff.getY(), diff.getZ(), 1, 1, 1, 0, 0, 0);
    transformVertexes(mtr);
    updateCenter();
}

void MatrixModelStructure::moveVertexesToCenter(const Vertex &center)
{
    Vertex diff = center - Vertex(0, 0, 0);
    TransformerMove mtr(diff.getX(), diff.getY(), diff.getZ());
    //Transformer mtr = Transformer(diff.getX(), diff.getY(), diff.getZ(), 1, 1, 1, 0, 0, 0);
    transformVertexes(mtr);
    updateCenter();
}

void MatrixModelStructure::transformVertexes(Transformer &mtr)
{
    for (auto &vertex : _vertexes)
        vertex.transform(mtr);
}

void MatrixModelStructure::transform(Transformer &mtr, const Vertex &center)
{
    updateCenter();
    moveVertexesToOrigin(center);
    transformVertexes(mtr);
    moveVertexesToCenter(center);
}
