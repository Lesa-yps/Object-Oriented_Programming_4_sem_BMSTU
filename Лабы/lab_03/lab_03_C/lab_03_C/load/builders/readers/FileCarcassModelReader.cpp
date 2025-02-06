#include "FileCarcassModelReader.h"
#include "Exceptions.h"

std::string FileCarcassModelReader::_tag = "txt";

FileCarcassModelReader::FileCarcassModelReader()
{
    _file = std::make_shared<std::ifstream>();
}

FileCarcassModelReader::FileCarcassModelReader(const std::string &fileName) : FileCarcassModelReader()
{
    _file->open(fileName);
    if (!_file)
        throw SourceException("Error : File open");
}

FileCarcassModelReader::~FileCarcassModelReader()
{
    _file->close();
}

Vertex FileCarcassModelReader::readVertex()
{
    double x = 0, y = 0, z = 0;
    *_file >> x >> y >> z;
    return {x, y, z};
}

auto FileCarcassModelReader::readVertexes() -> std::vector<Vertex>
{
    std::vector<Vertex> vertexes;
    int vertexNum = 0;
    *_file >> vertexNum;
    if (vertexNum <= 0)
        throw SourceException("Wrong vertex num");

    double x = 0, y = 0, z = 0;
    for (int i = 0; i < vertexNum; i++)
    {
        *_file >> x >> y >> z;
        vertexes.emplace_back(x, y, z);
    }
    return vertexes;
}

auto FileCarcassModelReader::readEdges(std::size_t &vertexNum) -> std::vector<Edge>
{
    std::vector<Edge> edges;
    int edgesNum = 0;
    *_file >> edgesNum;
    if (edgesNum <= 0)
        throw SourceException("Wrong edges num");

    int vertex1Index = 0, vertex2Index = 0;
    for (int i = 0; i < edgesNum; i++)
    {
        *_file >> vertex1Index >> vertex2Index;
        if (vertex1Index <= 0 or vertex2Index <= 0 or vertex1Index > vertexNum or vertex2Index > vertexNum)
            throw SourceException("wrong edges data");

        edges.emplace_back(vertex1Index, vertex2Index);
    }
    return edges;
}

std::size_t FileCarcassModelReader::readCount()
{
    std::size_t count = 0;
    *_file >> count;
    return count;
}
