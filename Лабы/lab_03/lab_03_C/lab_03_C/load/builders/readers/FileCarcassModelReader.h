#ifndef FILE_CARCASS_MODEL_READER_H
#define FILE_CARCASS_MODEL_READER_H

#include <fstream>

#include "BaseCarcassModelReader.h"

class FileCarcassModelReader : public BaseCarcassModelReader
{
public:
    FileCarcassModelReader();
    explicit FileCarcassModelReader(const std::string &fileName);
    ~FileCarcassModelReader();

    virtual std::size_t readCount() override;
    virtual Vertex readVertex() override;
    virtual std::vector<Vertex> readVertexes() override;
    virtual std::vector<Edge> readEdges(std::size_t &vertexNum) override;

    static std::string _tag;

private:
    std::shared_ptr<std::ifstream> _file;
};

#endif // FILE_CARCASS_MODEL_READER_H
