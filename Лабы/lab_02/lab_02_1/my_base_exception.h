#ifndef MY_BASE_ERROR_H
#define MY_BASE_ERROR_H

#include <exception>

using namespace std;

#define SIZE_OF_BUF 512

class My_Base_Error : public exception
{
public:
    // конструктор
    My_Base_Error(const char *file_name, int line, const char *class_name, const char *time, const char *inf = "Error!")
    {
        // Форматируем строку и сохраняем результат в буфере
        snprintf(inf_err, sizeof(inf_err), "\nInfo: %s\nFile: %s\nLine: %d\nClass: %s\nTime: %s", inf, file_name, line, class_name, time);
    }

    // возвращает информацию об ошибке
    virtual const char *what() const noexcept override
    {
        return inf_err;
    }
protected:
    // Буфер для хранения результирующей строки
    char inf_err[SIZE_OF_BUF];
};

// прослойка для ошибок контейнера
class My_Base_Container_Error : public My_Base_Error
{
public:
    My_Base_Container_Error(const char *file_name, int line, const char *class_name, const char *time, const char *inf = "Container error!")
        : My_Base_Error(file_name, line, class_name, time, inf) {}
};

// прослойка для ошибок итератора
class My_Base_Iterator_Error : public My_Base_Error
{
public:
    My_Base_Iterator_Error(const char *file_name, int line, const char *class_name, const char *time, const char *inf = "Iterator error!")
        : My_Base_Error(file_name, line, class_name, time, inf) {}
};

#endif // MY_BASE_ERROR_H
