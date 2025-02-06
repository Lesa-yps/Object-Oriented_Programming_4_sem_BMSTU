#ifndef MY_BASE_VECTOR_H
#define MY_BASE_VECTOR_H

class My_Base_Vector
{
public:
    using size_type = int;

    // конструктор без параметров
    My_Base_Vector();
    // Чисто виртуальный деструктор
    virtual ~My_Base_Vector() = 0;
    // вектор пуст?
    bool is_empty() const noexcept;
    // размерность вектора
    int size() const noexcept;
protected:
    int count_axis = 0;
};

#include "my_base_vector.hpp"

#endif // MY_BASE_VECTOR_H
