#include "ModelBuilder.h"

ModelBuilder::ModelBuilder(std::shared_ptr<BaseCarcassModelReader> reader)
{
    _reader = reader;
    _model = std::make_shared<ModelStructure>();
}

std::size_t ModelBuilder::buildVertexes()
{
    std::vector<Vertex> vertexes = _reader->readVertexes();
    std::size_t countVertex = vertexes.size();
    for (std::size_t i = 0; i < countVertex; i++)
        _model->addVertex(vertexes[i]);
    return countVertex;
}

void ModelBuilder::buildEdges(std::size_t countVertex)
{
    std::vector<Edge> edges = _reader->readEdges(countVertex);
    int countEdge = edges.size();
    for (int i = 0; i < countEdge; i++)
        _model->addEdge(edges[i]);
}

std::shared_ptr<CarcassModel> ModelBuilder::get()
{
    return std::make_shared<CarcassModel>(CarcassModel(_model));
}
