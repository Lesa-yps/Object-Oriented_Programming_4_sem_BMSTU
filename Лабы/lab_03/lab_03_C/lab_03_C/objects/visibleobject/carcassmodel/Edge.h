#ifndef EDGE_H
#define EDGE_H

#include <cstddef>

class Edge
{
public:
    Edge() = default;
    Edge(const std::size_t firstVertex, const std::size_t secondVertex);
    Edge(const Edge &edge) = default;

    ~Edge() = default;

    [[nodiscard]] auto getFirst() const -> std::size_t;
    [[nodiscard]] auto getSecond() const -> std::size_t;

    void setFirst(const std::size_t index);
    void setSecond(const std::size_t index);

private:
    std::size_t _first;
    std::size_t _second;
};

#endif //EDGE_H
