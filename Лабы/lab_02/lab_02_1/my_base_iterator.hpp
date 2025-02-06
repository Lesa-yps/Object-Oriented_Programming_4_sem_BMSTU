#ifndef MY_BASE_ITERATOR_HPP
#define MY_BASE_ITERATOR_HPP

#include <ctime>

#include "my_base_iterator.h"
#include "my_exception.h"

// перегружаем операторы * и ->
template <Data_concept T>
const T& My_Base_Iterator<T>::operator * () const
{
    check_iter(__LINE__);
    check_vector(__LINE__);
    return *get_ptr_cur();
}
template <Data_concept T>
const T* My_Base_Iterator<T>::operator -> () const
{
    check_iter(__LINE__);
    check_vector(__LINE__);
    return get_ptr_cur();
}

// перегрузка операторов сравнения
template <Data_concept T>
bool My_Base_Iterator<T>::operator == (const My_Base_Iterator<T> &other) const
{
    check_vector(__LINE__);
    return this->index == other.index;
}
template <Data_concept T>
bool My_Base_Iterator<T>::operator != (const My_Base_Iterator<T> &other) const
{
    check_vector(__LINE__);
    return this->index != other.index;
}


// вспомогательные функции
// объект, на который указывает итератор ещё жив?
template <Data_concept T>
void My_Base_Iterator<T>::check_vector(int line) const
{
    if (this->piter.expired())
    {
        time_t time_now = time(NULL);
        throw Err_del_vec(__FILE__, line, typeid(*this).name(), ctime(&time_now));
    }
}
template <Data_concept T>
// проверка: индекс в пределах размера объекта?
void My_Base_Iterator<T>::check_iter(int line) const
{
    if (this->index >= this->size)
    {
        time_t time_now = time(NULL);
        throw Err_index_out_of_range(__FILE__, line, typeid(*this).name(), ctime(&time_now));
    }
}
// возвращает итератор по индексу
template <Data_concept T>
T* My_Base_Iterator<T>::get_ptr_cur() const
{
    shared_ptr<T[]> piter_shared = this->piter.lock();
    // Используем метод get() shared_ptr для получения указателя на текущий элемент
    return piter_shared.get() + this->index;
}

#endif // MY_BASE_ITERATOR_HPP
