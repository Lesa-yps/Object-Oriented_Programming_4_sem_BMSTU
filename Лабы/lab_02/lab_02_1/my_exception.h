#ifndef MY_ERROR_H
#define MY_ERROR_H

#include "my_base_exception.h"

using namespace std;

// для контейнера

// ошибка выделения памяти для контейнера
class Err_memory : public My_Base_Container_Error
{
public:
    // конструктор
    Err_memory(const char * file_name, int line, const char * class_name, const char *time,
               const char * inf = "Memory allocation error!") :
        My_Base_Container_Error(file_name, line, class_name, time, inf) {};
};

// деление на нуль в контейнере
class Err_zero_div : public My_Base_Container_Error
{
public:
    // конструктор
    Err_zero_div(const char * file_name, int line, const char * class_name, const char *time,
                 const char * inf = "Division by zero!") :
        My_Base_Container_Error(file_name, line, class_name, time, inf) {};
};

// размерности векторов разные
class Err_size_vec_not_equal : public My_Base_Container_Error
{
public:
    // конструктор
    Err_size_vec_not_equal(const char * file_name, int line, const char * class_name, const char *time,
                           const char * inf = "Different vector sizes!") :
        My_Base_Container_Error(file_name, line, class_name, time, inf) {};
};

// отрицательныя размерность вектора
class Err_neg_size : public My_Base_Container_Error
{
public:
    // конструктор
    Err_neg_size(const char * file_name, int line, const char * class_name, const char *time,
                 const char * inf = "Size of vector is negative!") :
        My_Base_Container_Error(file_name, line, class_name, time, inf) {};
};

// индекс за пределами размера вектора
class Err_index_out_of_range : public My_Base_Container_Error
{
public:
    // конструктор
    Err_index_out_of_range(const char * file_name, int line, const char * class_name, const char *time,
                           const char * inf = "Index is out of range!") :
        My_Base_Container_Error(file_name, line, class_name, time, inf) {};
};

// нулевой указатель на массив, которым инициализируется контейнер
class Err_arr_null : public My_Base_Container_Error
{
public:
    // конструктор
    Err_arr_null(const char * file_name, int line, const char * class_name, const char *time,
                 const char * inf = "Null pointer to an array!") :
        My_Base_Container_Error(file_name, line, class_name, time, inf) {};
};

// для векторного умножения размерности векторов должны быть равны 3/5/7
class Err_size_vec_mul : public My_Base_Container_Error
{
public:
    // конструктор
    Err_size_vec_mul(const char * file_name, int line, const char * class_name, const char *time,
                     const char * inf = "The vector size for vector multiplication is not equal to 3/5/7!") :
        My_Base_Container_Error(file_name, line, class_name, time, inf) {};
};


// для итератора

// попытка работы с невалидным итератором
class Err_valid_iter : public My_Base_Iterator_Error
{
public:
    // конструктор
    Err_valid_iter(const char * file_name, int line, const char * class_name, const char *time,
             const char * inf = "Try to work with invalid iterator!") :
        My_Base_Iterator_Error(file_name, line, class_name, time, inf) {};
};

// попытка работы с удалённым объектом
class Err_del_vec : public My_Base_Iterator_Error
{
public:
    // конструктор
    Err_del_vec(const char * file_name, int line, const char * class_name, const char *time,
                 const char * inf = "Try to work with deleted object!") :
        My_Base_Iterator_Error(file_name, line, class_name, time, inf) {};
};

#endif // MY_ERROR_H
