#ifndef MY_BASE_ITERATOR_H
#define MY_BASE_ITERATOR_H

#include <iterator>
#include <memory>

#include "my_concepts.hpp"

using namespace std;

template <Data_concept T>
class My_Base_Iterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;


    // деструктор
    virtual ~My_Base_Iterator() = default;

    // перегружаем операторы * и ->
    const T& operator * () const;
    const T* operator -> () const;

    // перегрузка операторов сравнения
    bool operator == (const My_Base_Iterator<T> &other) const;
    bool operator != (const My_Base_Iterator<T> &other) const;

protected:
    // конструктор без параметров
    My_Base_Iterator() = default;

    int size = 0;
    int index = 0;

    // объект, на который указывает итератор ещё жив?
    void check_vector(int line) const;
    // проверка: индекс в пределах размера объекта?
    void check_iter(int line) const;
    // возвращает итератор по индексу
    T* get_ptr_cur() const;

    weak_ptr<T[]> piter;
};

#include "my_base_iterator.hpp"

#endif // MY_BASE_ITERATOR_H
