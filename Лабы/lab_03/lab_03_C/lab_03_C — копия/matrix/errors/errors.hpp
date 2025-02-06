
#ifndef errors_hpp
#define errors_hpp

#include <exception>
#include <string>
#include <string.h>

class Matrix_Exception : public std::exception {
public:
    Matrix_Exception(const char* file, int line, const char* time, const char* msg) {
        sprintf(err_str, "file: %s, line: %-3d, time: %s, error: %s", file, line, time, msg);
    }

    virtual ~Matrix_Exception() = default;

    virtual const char* what() const noexcept override;

protected:
    char err_str[1024]; // Строка ошибки
};


class Index_Out_Of_Range_Exception : public Matrix_Exception
{
public:
    Index_Out_Of_Range_Exception(const char* file, int line, const char* time, const char* msg);
    
    virtual const char *what() const noexcept override;
    
    virtual ~Index_Out_Of_Range_Exception() = default;
    
};

class Access_Non_Existing_Exception : public Matrix_Exception
{
public:
    Access_Non_Existing_Exception(const char* file, int line, const char* time, const char* msg);
    
    virtual const char *what() const noexcept override;
    
    virtual ~Access_Non_Existing_Exception() = default;
    
};

class Memory_Allocation_Exception : public Matrix_Exception
{
public:
    Memory_Allocation_Exception(const char* file, int line, const char* time, const char* msg);
    
    virtual const char *what() const noexcept override;
    
    virtual ~Memory_Allocation_Exception() = default;
    
};

class Wrong_Init_List_Exception : public Matrix_Exception
{
public:
    Wrong_Init_List_Exception(const char* file, int line, const char* time, const char* msg);
    
    virtual const char *what() const noexcept override;
    
    virtual ~Wrong_Init_List_Exception() = default;
    
};

class Sizes_Differ_Exception : public Matrix_Exception
{
public:
    Sizes_Differ_Exception(const char* file, int line, const char* time, const char* msg);

    virtual const char *what() const noexcept override;

    virtual ~Sizes_Differ_Exception() = default;

};
#endif /* errors_hpp */
