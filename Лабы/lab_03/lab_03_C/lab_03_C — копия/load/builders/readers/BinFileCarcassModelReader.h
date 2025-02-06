#ifndef BINFILECARCASSMODELREADER_H
#define BINFILECARCASSMODELREADER_H

#include <fstream>

#include "BaseCarcassModelReader.h"

class BinFileCarcassModelReader : public BaseCarcassModelReader
{
public:
    BinFileCarcassModelReader();
    explicit BinFileCarcassModelReader(const std::string &fileName);
    ~BinFileCarcassModelReader();

    virtual std::size_t readCount() override;
    virtual Vertex readVertex() override;
    virtual std::vector<Vertex> readVertexes() override;
    virtual std::vector<Edge> readEdges(std::size_t &vertexNum) override;

    static std::string _tag;

private:
    std::shared_ptr<std::ifstream> _file;
};

#endif // BINFILECARCASSMODELREADER_H
