#include "CarcassModelReaderFactory.h"

CarcassModelReaderFactory::CarcassModelReaderFactory()
{
    readerCreators[FileCarcassModelReader::_tag] = [](const std::string &fileName) -> std::shared_ptr<BaseCarcassModelReader> {
        return std::make_shared<FileCarcassModelReader>(fileName);
    };
    readerCreators[BinFileCarcassModelReader::_tag] = [](const std::string &fileName) -> std::shared_ptr<BaseCarcassModelReader> {
        return std::make_shared<BinFileCarcassModelReader>(fileName);
    };
}


std::shared_ptr<BaseCarcassModelReader> CarcassModelReaderFactory::createReader(const std::string& fileName)
{
    std::string extension = getFileExtension(fileName);
    auto it = readerCreators.find(extension);
    if (it != readerCreators.end())
        return it->second(fileName);
    else
        throw SourceException("Unsupported file extension");
}

std::string CarcassModelReaderFactory::getFileExtension(const std::string& fileName)
{
    size_t pos = fileName.find_last_of('.');
    if (pos != std::string::npos)
        return fileName.substr(pos + 1);
    return "";
}
