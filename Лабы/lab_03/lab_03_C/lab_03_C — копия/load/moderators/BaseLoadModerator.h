#ifndef BASE_LOAD_MODERATOR_H
#define BASE_LOAD_MODERATOR_H

#include <memory>

#include "Object.h"

class BaseLoadModerator
{
public:
    BaseLoadModerator() = default;
    ~BaseLoadModerator() = default;

    virtual std::shared_ptr<Object> load(const std::string &fileName) = 0;
};

#endif // BASE_LOAD_MODERATOR_H
