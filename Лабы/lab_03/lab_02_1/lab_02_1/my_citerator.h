#ifndef MY_CONST_ITERATOR_H
#define MY_CONST_ITERATOR_H

#include <memory>

#include "my_base_iterator.h"

using namespace std;

template <Data_concept T>
class My_Vector;

// мой класс итератора
template <Data_concept T>
class My_CIterator: public My_Base_Iterator<T>
{
public:
    // конструктор без параметров
    My_CIterator() = default;
    // конструктор по константному итератору
    My_CIterator(const My_CIterator<T> &iter);
    // конструктор по итератору
    My_CIterator(const My_Iterator<T> &iter);
    // конструктор по контейнеру
    My_CIterator(const My_Vector<T> &vec);
    // деструктор
    ~My_CIterator() = default;

    // перегрузка оператора равно
    My_CIterator<T>& operator = (const My_CIterator<T> &other);
    // перегрузка
    My_CIterator<T> operator + (const int i) const;
    My_CIterator<T>& operator += (const int i);
    // перегрузка инкремента
    My_CIterator<T>& operator ++ (); // ++iter
    My_CIterator<T> operator ++ (int); // iter++
};

#include "my_citerator.hpp"

#endif // MY_CONST_ITERATOR_H
