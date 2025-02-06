#ifndef MY_CITERATOR_HPP
#define MY_CITERATOR_HPP

#include <iostream>

#include "my_vector.h"
#include "my_citerator.h"

// конструктор по константному итератору
template <Data_concept T>
My_CIterator<T>::My_CIterator(const My_CIterator<T> &iter)
{
    this->size = iter.size;
    this->index = iter.index;
    this->piter = iter.piter;
}
// конструктор по итератору
template <Data_concept T>
My_CIterator<T>::My_CIterator(const My_Iterator<T> &iter)
{
    this->size = iter.size;
    this->index = iter.index;
    this->piter = iter.piter;
}
// конструктор по контейнеру
template <Data_concept T>
My_CIterator<T>::My_CIterator(const My_Vector<T> &vec)
{
    this->size = vec.size();
    this->index = 0;
    this->piter = vec.pvec;
}

// перегрузка оператора равно
template <Data_concept T>
My_CIterator<T>& My_CIterator<T>::operator = (const My_CIterator<T> &other)
{
    this->check_vector(__LINE__);
    this->size = other.size;
    this->index = other.index;
    this->piter = other.piter;
    return *this;
}

// перегрузка +
template <Data_concept T>
My_CIterator<T> My_CIterator<T>::operator + (const int i) const
{
    this->check_vector(__LINE__);
    My_CIterator<T> new_iter(*this);
    new_iter.index += i;
    return new_iter;
}
template <Data_concept T>
My_CIterator<T>& My_CIterator<T>::operator += (const int i)
{
    this->check_vector(__LINE__);
    this->index += i;
    return *this;
}
// перегрузка инкремента
template <Data_concept T>
My_CIterator<T>& My_CIterator<T>::operator ++ ()
{
    this->check_iter(__LINE__);
    this->check_vector(__LINE__);
    (this->index)++;
    return *this;
}
template <Data_concept T>
My_CIterator<T> My_CIterator<T>::operator ++ (int)
{
    this->check_iter(__LINE__);
    this->check_vector(__LINE__);
    ++(this->index);
    return *this;
}

#endif // MY_CITERATOR_HPP
