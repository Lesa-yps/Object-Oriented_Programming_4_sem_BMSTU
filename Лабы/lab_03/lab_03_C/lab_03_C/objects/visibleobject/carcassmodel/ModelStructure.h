#ifndef MODEL_STRUCTURE_H
#define MODEL_STRUCTURE_H

#include <vector>

#include "BaseModelStructure.h"
#include "Vertex.h"
#include "Edge.h"
#include "transformermove.h"

class ModelStructure : public BaseModelStructure
{
public:
    ModelStructure() = default;
    ModelStructure(std::vector<Vertex> &vertexes, std::vector<Edge> &edges);
    ModelStructure(std::vector<Vertex> &vertexes, std::vector<Edge> &edges, Vertex &center);

    ~ModelStructure() override = default;

    const std::vector<Vertex> &getVertexes() const override;
    const std::vector<Edge> &getEdges() const override;
    const Vertex getCenter() const override;

    void addVertex(const Vertex &vertex) override;
    void addEdge(const Edge &edge) override;
    void updateCenter() override;

    void moveVertexesToOrigin(const Vertex &center) override;
    void moveVertexesToCenter(const Vertex &center) override;
    void transformVertexes(Transformer &mtr) override;
    void transform(Transformer &mtr, const Vertex &center) override;

private:
    Vertex _center;

    std::vector<Vertex> _vertexes;
    std::vector<Edge> _edges;
};

#endif // MODEL_STRUCTURE_H
