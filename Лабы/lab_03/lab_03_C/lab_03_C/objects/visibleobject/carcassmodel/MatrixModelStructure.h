#ifndef MATRIXMODELSTRUCTURE_H
#define MATRIXMODELSTRUCTURE_H

#include <vector>

#include "Vertex.h"
#include "BaseModelStructure.h"
#include "Matrix.h"
#include "transformermove.h"


class MatrixModelStructure : public BaseModelStructure
{
public:
    MatrixModelStructure() = default;
    MatrixModelStructure(const std::vector<Vertex> &vertexes, const Matrix<int> &adjMatrix);
    ~MatrixModelStructure() override = default;

    void addVertex(const Vertex &vertex) override;
    void addEdge(const Edge &edge) override;
    void updateCenter() override;

    const std::vector<Vertex> &getVertexes() const override;
    const std::vector<Edge> &getEdges() const override;
    const Vertex getCenter() const override;

    void moveVertexesToOrigin(const Vertex &center) override;
    void moveVertexesToCenter(const Vertex &center) override;
    void transformVertexes(Transformer &mtr) override;
    void transform(Transformer &mtr, const Vertex &center) override;

private:
    void updateAdjMatrix();

    Vertex _center;
    std::vector<Vertex> _vertexes;
    Matrix<int> _adjMatrix;
};


#endif // MATRIXMODELSTRUCTURE_H
