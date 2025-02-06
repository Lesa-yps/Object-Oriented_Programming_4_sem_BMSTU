#include "Exceptions.h"

BaseException::BaseException(const char *msg) : _msg(msg) {}

auto BaseException::what() const noexcept -> const char *
{
    return "Something went wrong!";
}

auto BaseException::getInfo() const noexcept -> const char *
{
    return _msg;
}

CameraException::CameraException(const char *msg) : BaseException(msg) {}

auto CameraException::what() const noexcept -> const char *
{
    return "Camera isn't added";
}

SourceException::SourceException(const char *msg) : BaseException(msg) {}

auto SourceException::what() const noexcept -> const char *
{
    return "Load error";
}

ModelException::ModelException(const char *msg) : BaseException(msg) {}

auto ModelException::what() const noexcept -> const char *
{
    return "Can't build model";
}
