#include "BaseModelBuilder.h"

BaseModelBuilder::BaseModelBuilder(std::shared_ptr<BaseCarcassModelReader> &reader)
    : _reader(reader) {}
