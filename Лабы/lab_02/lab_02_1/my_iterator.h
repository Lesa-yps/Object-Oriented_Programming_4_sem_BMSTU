#ifndef MY_ITERATOR_H
#define MY_ITERATOR_H

#include <memory>

#include "my_base_iterator.h"

using namespace std;

template <Data_concept T>
class My_Vector;

// мой класс итератора
template <Data_concept T>
class My_Iterator: public My_Base_Iterator<T>
{
public:
    // конструктор без параметров
    My_Iterator() = default;
    // конструктор по итератору
    My_Iterator(const My_Iterator<T> &iter);
    // конструктор по контейнеру
    My_Iterator(const My_Vector<T> &vec);
    // деструктор
    ~My_Iterator() = default;

    // перегрузка оператора равно
    My_Iterator<T>& operator = (const My_Iterator<T> &other);
    // перегружаем операторы * и ->
    T& operator * ();
    T* operator -> ();
    // перегрузка +
    My_Iterator<T> operator + (const int i) const;
    My_Iterator<T>& operator += (const int i);
    // перегрузка инкремента
    My_Iterator<T>& operator ++ (); // ++iter
    My_Iterator<T> operator ++ (int); // iter++
};

#include "my_iterator.hpp"

#endif // MY_ITERATOR_H
