#ifndef MY_BASE_VECTOR_HPP
#define MY_BASE_VECTOR_HPP

#include "my_base_vector.h"

// конструктор без параметров
My_Base_Vector::My_Base_Vector()
{
    count_axis = 0;
}

// вектор пуст?
bool My_Base_Vector::is_empty() const noexcept
{
    return count_axis == 0;
}

// размерность вектора
int My_Base_Vector::size() const noexcept
{
    return count_axis;
}

// деструктор
My_Base_Vector::~My_Base_Vector() {}

#endif // MY_BASE_VECTOR_HPP
