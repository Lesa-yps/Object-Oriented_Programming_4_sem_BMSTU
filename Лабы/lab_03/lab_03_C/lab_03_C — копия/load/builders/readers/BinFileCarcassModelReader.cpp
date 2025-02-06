#include "BinFileCarcassModelReader.h"
#include "Exceptions.h"

std::string BinFileCarcassModelReader::_tag = "bin";

BinFileCarcassModelReader::BinFileCarcassModelReader()
{
    _file = std::make_shared<std::ifstream>();
}

BinFileCarcassModelReader::BinFileCarcassModelReader(const std::string &fileName): BinFileCarcassModelReader()
{
    _file->open(fileName, std::ios::binary);
    if (!_file)
        throw SourceException("Error : File open");
}

BinFileCarcassModelReader::~BinFileCarcassModelReader()
{
    _file->close();
}

Vertex BinFileCarcassModelReader::readVertex()
{
    double x = 0, y = 0, z = 0;
    _file->read(reinterpret_cast<char*>(&x), sizeof(x));
    _file->read(reinterpret_cast<char*>(&y), sizeof(y));
    _file->read(reinterpret_cast<char*>(&z), sizeof(z));
    return {x, y, z};
}

auto BinFileCarcassModelReader::readVertexes() -> std::vector<Vertex>
{
    std::vector<Vertex> vertexes;
    std::size_t vertexNum = 0;
    _file->read(reinterpret_cast<char*>(&vertexNum), sizeof(vertexNum));
    if (vertexNum <= 0)
        throw SourceException("wrong vertex num");

    double x = 0, y = 0, z = 0;
    for (std::size_t i = 0; i < vertexNum; i++)
    {
        _file->read(reinterpret_cast<char*>(&x), sizeof(x));
        _file->read(reinterpret_cast<char*>(&y), sizeof(y));
        _file->read(reinterpret_cast<char*>(&z), sizeof(z));
        vertexes.emplace_back(x, y, z);
    }
    return vertexes;
}

auto BinFileCarcassModelReader::readEdges(std::size_t &vertexNum) -> std::vector<Edge>
{
    std::vector<Edge> edges;
    std::size_t edgesNum = 0;
    _file->read(reinterpret_cast<char*>(&edgesNum), sizeof(edgesNum));
    if (edgesNum <= 0)
        throw SourceException("wrong edges num");
    int vertex1Index = 0, vertex2Index = 0;
    for (std::size_t i = 0; i < edgesNum; ++i)
    {
        _file->read(reinterpret_cast<char*>(&vertex1Index), sizeof(vertex1Index));
        _file->read(reinterpret_cast<char*>(&vertex2Index), sizeof(vertex2Index));
        if (vertex1Index <= 0 || vertex2Index <= 0 ||
            vertex1Index > vertexNum || vertex2Index > vertexNum)
        {
            throw SourceException("wrong edges data");
        }
        edges.emplace_back(vertex1Index, vertex2Index);
    }
    return edges;
}

std::size_t BinFileCarcassModelReader::readCount()
{
    std::size_t count = 0;
    _file->read(reinterpret_cast<char*>(&count), sizeof(count));
    return count;
}
