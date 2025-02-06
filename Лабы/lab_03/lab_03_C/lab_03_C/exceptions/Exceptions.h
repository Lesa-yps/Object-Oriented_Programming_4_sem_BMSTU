#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class BaseException : public std::exception
{
public:
    explicit BaseException(const char *msg);
    [[nodiscard]] auto what() const noexcept -> const char * override;
    [[nodiscard]] auto getInfo() const noexcept -> const char *;

protected:
    const char *_msg;
};

class CameraException : public BaseException
{
public:
    explicit CameraException(const char *msg);
    [[nodiscard]] auto what() const noexcept -> const char * override;
};

class SourceException : public BaseException
{
public:
    explicit SourceException(const char *msg);
    [[nodiscard]] auto what() const noexcept -> const char * override;
};

class ModelException : public BaseException
{
public:
    explicit ModelException(const char *msg);
    [[nodiscard]] auto what() const noexcept -> const char * override;
};

#endif // EXCEPTIONS_H
