#include "DrawCarcassModelAdapter.h"

void DrawCarcassModelAdapter::setCamera(std::shared_ptr<Camera> camera)
{
    _camera = camera;
}

void DrawCarcassModelAdapter::setDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    _drawer = drawer;
}

auto DrawCarcassModelAdapter::getProjection(const Vertex &vertex) -> Vertex
{
    Vertex projection = vertex;
    projection.setX(projection.getX() + _camera->_location.getX());
    projection.setY(projection.getY() + _camera->_location.getY());
    return projection;
}

void DrawCarcassModelAdapter::request()
{
    if (_adaptee && _camera && _drawer)
    {
        auto vertexes = _adaptee->_modelStructure->getVertexes();
        auto edges = _adaptee->_modelStructure->getEdges();
        auto center = _adaptee->_modelStructure->getCenter();

        for (auto edge : edges)
            _drawer->drawLine(getProjection(vertexes.at(edge.getFirst() - 1)).getAbsVertex(center), getProjection(vertexes.at(edge.getSecond() - 1)).getAbsVertex(center));
    }
}
