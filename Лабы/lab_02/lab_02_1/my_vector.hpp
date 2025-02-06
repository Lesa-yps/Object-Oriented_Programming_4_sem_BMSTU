#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <iostream>
#include <memory>
#include <cmath>
#include <stdarg.h>

#include "my_vector.h"
#include "my_exception.h"
#include "my_iterator.h"
#include "my_citerator.hpp"
#include "my_concepts.hpp"

using namespace std;

#define EPS 1e-5
#define PI 3.14159

// конструкторы векторов
// без параметров vec_size()
template <Data_concept T>
My_Vector<T>::My_Vector()
{
    this->count_axis = 0;
    this->mem_alloc(this->count_axis, __LINE__);
}
// по размеру vec_size(3)
template <Data_concept T>
My_Vector<T>::My_Vector(const int &size)
{
    this->check_vec_size(size, __LINE__);
    this->count_axis = size;
    this->mem_alloc(this->count_axis, __LINE__);
}
// по списку инициализации vec_fill = {1, 2, 3}
template <Data_concept T>
template <Convert_Assig<T> U>
My_Vector<T>::My_Vector(initializer_list<U> arr)
{
    this->count_axis = arr.size();
    mem_alloc(this->count_axis, __LINE__);
    My_Iterator<T> iter = this->begin();
    for (auto &elem : arr)
    {
        *iter = elem;
        iter++;
    }
}
// по длине и массиву инициализации vec_len_fill1(3, arr)
template <Data_concept T>
template <Convert_Assig<T> U>
My_Vector<T>::My_Vector(int size, const U *arr)
{
    this->check_vec_size(size, __LINE__);
    this->check_arr_null(arr, __LINE__);
    this->count_axis = size;
    this->mem_alloc(this->count_axis, __LINE__);
    My_Iterator<T> iter = this->begin();
    for (int i = 0; i < size; i++)
    {
        *iter = arr[i];
        iter++;
    }
}
// по длине и элементам заполнения vec_len_fill2(3, 1.0, 2.1, 3.5)
template <Data_concept T>
template <Convert_Assig<T> U>
My_Vector<T>::My_Vector(int size, U elem, ...)
{
    this->check_vec_size(size, __LINE__);
    this->count_axis = size;
    this->mem_alloc(this->count_axis, __LINE__);
    My_Iterator<T> iter = this->begin();
    va_list args;
    va_start(args, elem);
    for (int i = 0; i < size; i++)
    {
        *iter = elem;
        elem = va_arg(args, U);
        iter++;
    }
    va_end(args);
}
// по двум итераторам
template <Data_concept T>
template <Forward_iterator Ti>
My_Vector<T>::My_Vector(Ti begin, Ti end)
{
    int size = 0;
    for (auto iter = begin; iter != end; iter++)
        size++;
    this->check_vec_size(size, __LINE__);
    this->count_axis = size;
    this->mem_alloc(this->count_axis, __LINE__);
    My_Iterator<T> iter = this->begin();
    auto iter1 = begin;
    for (int i = 0; i < size; i++)
    {
        *iter = *iter1;
        iter++;
        iter1++;
    }
}
// конструктор копирования
// по левой ссылке на другой вектор
template <Data_concept T>
My_Vector<T>::My_Vector(const My_Vector<T> &other)
{
    //cout << "tyt" << endl;
    this->count_axis = other.size();
    this->mem_alloc(this->count_axis, __LINE__);
    My_Iterator<T> iter = this->begin();
    for (auto iter1 = other.cbegin(); iter1 != other.cend(); iter1++)
    {
        *iter = *iter1;
        iter++;
    }
}
// конструктор переноса
// по правой ссылке на другой вектор
template <Data_concept T>
My_Vector<T>::My_Vector(My_Vector<T> &&other) noexcept
{
    //cout << "tyt1" << endl;
    this->count_axis = other.size();
    this->pvec = other.pvec;
    other.pvec.reset();
}
// преобразование из другого моего контейнера
template <Data_concept T>
template <Convert_Assig<T> T1>
My_Vector<T>::My_Vector(const My_Vector<T1> &other)
{
    this->count_axis = other.size();
    this->mem_alloc(this->count_axis, __LINE__);
    My_Iterator<T> iter = this->begin();
    for (auto iter1 = other.cbegin(); iter1 != other.cend(); iter1++)
    {
        *iter = *iter1;
        iter++;
    }
}
// преобразование из другого контейнера
template <Data_concept T>
template <typename Con>
    requires Valid_container<T, Con>
My_Vector<T>::My_Vector(const Con &other)
{
    this->count_axis = other.size();
    this->mem_alloc(this->count_axis, __LINE__);
    My_Iterator<T> iter = this->begin();
    for (auto iter1 = other.cbegin(); iter1 != other.cend(); iter1++)
    {
        *iter = *iter1;
        iter++;
    }
}

// нормализация вектора
template <Data_concept T>
decltype(auto) My_Vector<T>::to_single(void) const
{
    this->check_vec_size(this->count_axis, __LINE__);
    auto len_vec = this->len();
    check_div_zero(len_vec, __LINE__);
    My_Vector<decltype((*this)[0] / len_vec)> new_vec(*this);
    new_vec /= len_vec;
    return new_vec;
}
// нулевой ли вектор
template <Data_concept T>
bool My_Vector<T>::is_zero(void) const
{
    return this->len() < EPS;
}
// единичный ли вектор
template <Data_concept T>
bool My_Vector<T>::is_single(void) const
{
    return fabs(this->len() - 1) < EPS;
}
// длина вектора
template <Data_concept T>
decltype(auto) My_Vector<T>::len(void) const
{
    this->check_vec_size(this->count_axis, __LINE__);
    auto iter = this->begin();
    auto len_now = sqrt((*iter) * (*iter));
    for (iter += 1; iter != this->end(); iter++)
        len_now = sqrt(len_now * len_now + (*iter) * (*iter));
    return len_now;
}
// угол между векторами (в градусах)
template <Data_concept T>
template <typename Con>
    requires Valid_container<T, Con>
decltype(auto) My_Vector<T>::angle_betw(const Con &other) const
{
    this->check_vec_size(this->count_axis, __LINE__);
    this->check_size_equal(other.size(), __LINE__);
    auto angle = (*this & other) / (this->len() * other.len());
    return angle * 180 / PI;
}
// вектора коллинеарны?
template <Data_concept T>
template <typename Con>
    requires Valid_container<T, Con>
bool My_Vector<T>::is_collin(const Con &other) const
{
    return fabs(this->angle_betw(other)) < EPS;
}
// вектора ортогональны?
template <Data_concept T>
template <typename Con>
    requires Valid_container<T, Con>
bool My_Vector<T>::is_orthog(const Con &other) const
{
    return fabs(this->angle_betw(other) - 90) < EPS;
}

// изменить значение элемента вектора по индексу
template <Data_concept T>
template <Convert_Assig<T> U>
void My_Vector<T>::set_item(int ind, const U& elem)
{
    this->check_vec_size(this->count_axis, __LINE__);
    this->check_index(ind, __LINE__);
    this->get_item(ind) = elem;
}
// вывести элемент по индексу
template <Data_concept T>
T& My_Vector<T>::get_item(int ind)
{
    this->check_vec_size(this->count_axis, __LINE__);
    this->check_index(ind, __LINE__);
    My_Iterator<T> iter = this->begin();
    for (int i = 0; i < ind; i++)
        iter++;
    return *iter;
}
template <Data_concept T>
const T& My_Vector<T>::get_item(int ind) const
{
    this->check_vec_size(this->count_axis, __LINE__);
    this->check_index(ind, __LINE__);
    My_CIterator<T> iter = this->cbegin();
    for (int i = 0; i < ind; i++)
        iter++;
    return *iter;
}
// перегрузка []
template <Data_concept T>
T& My_Vector<T>::operator [] (int ind)
{
    return get_item(ind);
}
template <Data_concept T>
const T& My_Vector<T>::operator [] (int ind) const
{
    return get_item(ind);
}

// сложение векторов
template <Data_concept T>
template <Convert_Assig_Sum<T> T1>
decltype(auto) My_Vector<T>::operator + (const My_Vector<T1> &other) const
{
    this->check_vec_size(this->count_axis, __LINE__);
    this->check_size_equal(other.size(), __LINE__);
    My_Vector<decltype((*this)[0] + other[0])> new_vec(*this);
    My_Iterator<T> iter = new_vec.begin();
    My_CIterator<T1> iter1 = other.cbegin();
    for (; iter != new_vec.end(); iter++, iter1++)
        *iter += *iter1;
    return new_vec;
}
template <Data_concept T>
template <Convert_Assig_Sum<T> T1>
My_Vector<T>& My_Vector<T>::operator += (const My_Vector<T1> &other)
{
    *this = (My_Vector<T>) (*this + other);
    return *this;
}
template <Data_concept T>
template <Convert_Assig_Sum<T> T1>
decltype(auto) My_Vector<T>::vec_sum(const My_Vector<T1> &other) const
{
    return *this + other;
}
template <Data_concept T>
template <Convert_Assig_Sum<T> T1>
My_Vector<T>& My_Vector<T>::vec_sum_equate(const My_Vector<T1> &other)
{
    *this = (My_Vector<T>) (*this + other);
    return *this;
}
// сложение вектора и числа
template <Data_concept T>
template <Convert_Assig_Sum<T> T1>
decltype(auto) My_Vector<T>::operator + (const T1 &num) const
{
    this->check_vec_size(this->count_axis, __LINE__);
    My_Vector<decltype((*this)[0] + num)> new_vec(*this);
    My_Iterator<T> iter = new_vec.begin();
    for (; iter != new_vec.end(); iter++)
        *iter += num;
    return new_vec;
}
template <Data_concept T>
template <Convert_Assig_Sum<T> T1>
My_Vector<T>& My_Vector<T>::operator += (const T1 &num)
{
    *this = (My_Vector<T>) (*this + num);
    return *this;
}
template <Data_concept T>
template <Convert_Assig_Sum<T> T1>
decltype(auto) My_Vector<T>::num_sum(const T1 &num) const
{
    return *this + num;
}
template <Data_concept T>
template <Convert_Assig_Sum<T> T1>
My_Vector<T>& My_Vector<T>::num_sum_equate(const T1 &num)
{
    *this = (My_Vector<T>) (*this + num);
    return *this;
}

// число + вектор
template <typename T, Convert_Assig_Sum<T> T1>
decltype(auto) operator + (const T1 &num, const My_Vector<T> &vec)
{
    return vec + num;
}


// вычитание векторов
template <Data_concept T>
template <Convert_Assig_Diff<T> T1>
decltype(auto) My_Vector<T>::operator - (const My_Vector<T1> &other) const
{
    this->check_vec_size(this->count_axis, __LINE__);
    this->check_size_equal(other.size(), __LINE__);
    My_Vector<decltype((*this)[0] - other[0])> new_vec(*this);
    My_Iterator<T> iter = new_vec.begin();
    My_CIterator<T1> iter1 = other.cbegin();
    for (; iter != new_vec.end(); iter++, iter1++)
        *iter -= *iter1;
    return new_vec;
}
template <Data_concept T>
template <Convert_Assig_Diff<T> T1>
My_Vector<T>& My_Vector<T>::operator -= (const My_Vector<T1> &other)
{
    *this = (My_Vector<T>) (*this - other);
    return *this;
}
template <Data_concept T>
template <Convert_Assig_Diff<T> T1>
decltype(auto) My_Vector<T>::vec_sub(const My_Vector<T1> &other) const
{
    return *this - other;
}
template <Data_concept T>
template <Convert_Assig_Diff<T> T1>
My_Vector<T>& My_Vector<T>::vec_sub_equate(const My_Vector<T1> &other)
{
    *this = (My_Vector<T>) (*this - other);
    return *this;
}
// вычитание из вектора числа
template <Data_concept T>
template <Convert_Assig_Diff<T> T1>
decltype(auto) My_Vector<T>::operator - (const T1 &num) const
{
    this->check_vec_size(this->count_axis, __LINE__);
    My_Vector<decltype((*this)[0] - num)> new_vec(*this);
    My_Iterator<T> iter = new_vec.begin();
    for (; iter != new_vec.end(); iter++)
        *iter -= num;
    return new_vec;
}
template <Data_concept T>
template <Convert_Assig_Diff<T> T1>
My_Vector<T>& My_Vector<T>::operator -= (const T1 &num)
{
    *this = (My_Vector<T>) (*this - num);
    return *this;
}
template <Data_concept T>
template <Convert_Assig_Diff<T> T1>
decltype(auto) My_Vector<T>::num_sub(const T1 &num) const
{
    return *this - num;
}
template <Data_concept T>
template <Convert_Assig_Diff<T> T1>
My_Vector<T>& My_Vector<T>::num_sub_equate(const T1 &num)
{
    *this = (My_Vector<T>) (*this - num);
    return *this;
}

// умножение векторов поэлементное
template <Data_concept T>
template <Convert_Assig_Mul<T> T1>
decltype(auto) My_Vector<T>::operator * (const My_Vector<T1> &other) const
{
    this->check_vec_size(this->count_axis, __LINE__);
    this->check_size_equal(other.size(), __LINE__);
    My_Vector<decltype((*this)[0] * other[0])> new_vec(*this);
    My_Iterator<T> iter = new_vec.begin();
    My_CIterator<T1> iter1 = other.cbegin();
    for (; iter != new_vec.end(); iter++, iter1++)
    {
        *iter *= *iter1;
    }
    return new_vec;
}
template <Data_concept T>
template <Convert_Assig_Mul<T> T1>
My_Vector<T>& My_Vector<T>::operator *= (const My_Vector<T1> &other)
{
    *this = (My_Vector<T>) (*this * other);
    return *this;
}
template <Data_concept T>
template <Convert_Assig_Mul<T> T1>
decltype(auto) My_Vector<T>::elem_mul(const My_Vector<T1> &other) const
{
    return *this * other;
}
template <Data_concept T>
template <Convert_Assig_Mul<T> T1>
My_Vector<T>& My_Vector<T>::elem_mul_equate(const My_Vector<T1> &other)
{
    *this = (My_Vector<T>) (*this * other);
    return *this;
}
// векторное умножение векторов
template <Data_concept T>
template <Convert_Assig_Mul_Diff<T> T1>
decltype(auto) My_Vector<T>::operator ^ (const My_Vector<T1> &other) const
{
    this->check_size_vec_mul(this->count_axis, __LINE__);
    this->check_size_equal(other.size(), __LINE__);
    My_Vector<decltype((*this)[0] * other[0])> new_vec;
    // по формуле векторного умножения
    if (this->size() == 3)
    {
        decltype((*this)[0] * other[0]) cx = (*this)[1] * other[2] - (*this)[2] * other[1];
        decltype((*this)[0] * other[0]) cy = (*this)[2] * other[0] - (*this)[0] * other[2];
        decltype((*this)[0] * other[0]) cz = (*this)[0] * other[1] - (*this)[1] * other[0];
        new_vec = {cx, cy, cz};
    }
    else if (this->size() == 5)
    {
        decltype((*this)[0] * other[0]) cx = (*this)[1] * other[2] - (*this)[2] * other[1];
        decltype((*this)[0] * other[0]) cy = (*this)[2] * other[3] - (*this)[3] * other[2];
        decltype((*this)[0] * other[0]) cz = (*this)[3] * other[4] - (*this)[4] * other[3];
        decltype((*this)[0] * other[0]) cn = (*this)[4] * other[0] - (*this)[0] * other[4];
        decltype((*this)[0] * other[0]) cm = (*this)[0] * other[1] - (*this)[1] * other[0];
        new_vec = {cx, cy, cz, cn, cm};
    }
    else if (this->size() == 7)
    {
        decltype((*this)[0] * other[0]) cx = (*this)[1] * other[2] - (*this)[2] * other[1];
        decltype((*this)[0] * other[0]) cy = (*this)[2] * other[3] - (*this)[3] * other[2];
        decltype((*this)[0] * other[0]) cz = (*this)[3] * other[4] - (*this)[4] * other[3];
        decltype((*this)[0] * other[0]) cn = (*this)[4] * other[5] - (*this)[5] * other[4];
        decltype((*this)[0] * other[0]) cm = (*this)[5] * other[6] - (*this)[6] * other[5];
        decltype((*this)[0] * other[0]) cl = (*this)[6] * other[0] - (*this)[0] * other[6];
        decltype((*this)[0] * other[0]) ck = (*this)[0] * other[1] - (*this)[1] * other[0];
        new_vec = {cx, cy, cz, cn, cm, cl, ck};
    }
    return new_vec;
}
template <Data_concept T>
template <Convert_Assig_Mul_Diff<T> T1>
My_Vector<T>& My_Vector<T>::operator ^= (const My_Vector<T1> &other)
{
    *this = *this ^ other;
    return *this;
}
template <Data_concept T>
template <Convert_Assig_Mul_Diff<T> T1>
decltype(auto) My_Vector<T>::vec_mul(const My_Vector<T1> &other) const
{
    return *this ^ other;
}
template <Data_concept T>
template <Convert_Assig_Mul_Diff<T> T1>
My_Vector<T>& My_Vector<T>::vec_mul_equate(const My_Vector<T1> &other)
{
    *this = *this ^ other;
    return *this;
}
// умножение вектора на число
template <Data_concept T>
template <Convert_Assig_Mul<T> T1>
decltype(auto) My_Vector<T>::operator * (const T1 &num) const
{
    this->check_vec_size(this->count_axis, __LINE__);
    My_Vector<decltype((*this)[0] * num)> new_vec(*this);
    My_Iterator<T> iter = new_vec.begin();
    for (; iter != new_vec.end(); iter++)
        *iter *= num;
    return new_vec;
}
template <Data_concept T>
template <Convert_Assig_Mul<T> T1>
My_Vector<T>& My_Vector<T>::operator *= (const T1 &num)
{
    *this = (My_Vector<T>) (*this * num);
    return *this;
}
template <Data_concept T>
template <Convert_Assig_Mul<T> T1>
decltype(auto) My_Vector<T>::num_mul(const T1 &num) const
{
    return *this * num;
}
template <Data_concept T>
template <Convert_Assig_Mul<T> T1>
My_Vector<T>& My_Vector<T>::num_mul_equate(const T1 &num)
{
    *this = (My_Vector<T>) (*this * num);
    return *this;
}

// число * вектор
template <typename T, Convert_Assig_Sum<T> T1>
decltype(auto) operator * (const T1 &num, const My_Vector<T> &vec)
{
    return vec * num;
}

// скалярное умножение векторов
template <Data_concept T>
template <Convert_Assig_Mul_Sum<T> T1>
decltype(auto) My_Vector<T>::operator & (const My_Vector<T1> &other) const
{
    this->check_vec_size(this->count_axis, __LINE__);
    this->check_size_equal(other.size(), __LINE__);
    decltype((*this)[0] * other[0]) sum = 0;
    auto iter1 = other.begin();
    for (auto iter = this->begin(); iter != this->end(); iter++, iter1++)
        sum += (*iter * *iter1);
    return sum;
}
template <Data_concept T>
template <Convert_Assig_Mul_Sum<T> T1>
decltype(auto) My_Vector<T>::scal_mul(const My_Vector<T1> &other)
{
    return *this & other;
}

// деление вектора на число
template <Data_concept T>
template <Convert_Assig_Div<T> T1>
decltype(auto) My_Vector<T>::operator / (const T1 &num) const
{
    this->check_vec_size(this->count_axis, __LINE__);
    check_div_zero(num, __LINE__);
    My_Vector<decltype((*this)[0] / num)> new_vec(*this);
    My_Iterator<T> iter = new_vec.begin();
    for (; iter != new_vec.end(); iter++)
        *iter /= num;
    return new_vec;
}
template <Data_concept T>
template <Convert_Assig_Div<T> T1>
My_Vector<T>& My_Vector<T>::operator /= (const T1 &num)
{
    check_div_zero(num, __LINE__);
    *this = (My_Vector<T>) (*this / num);
    return *this;
}
template <Data_concept T>
template <Convert_Assig_Div<T> T1>
decltype(auto) My_Vector<T>::num_div(const T1 &num) const
{
    return *this / num;
}
template <Data_concept T>
template <Convert_Assig_Div<T> T1>
My_Vector<T>& My_Vector<T>::num_div_equate(const T1 &num)
{
    check_div_zero(num, __LINE__);
    *this = (My_Vector<T>) (*this / num);
    return *this;
}

// деление векторов поэлементное
template <Data_concept T>
template <Convert_Assig_Div<T> T1>
decltype(auto) My_Vector<T>::operator / (const My_Vector<T1> &other) const
{
    this->check_vec_size(this->count_axis, __LINE__);
    this->check_size_equal(other.size(), __LINE__);
    other.check_div_zero(other[0], __LINE__);
    My_Vector<decltype((*this)[0] / other[0])> new_vec(*this);
    My_Iterator<T> iter = new_vec.begin();
    My_CIterator<T1> iter1 = other.cbegin();
    for (; iter != new_vec.end(); iter++, iter1++)
    {
        other.check_div_zero(*iter1, __LINE__);
        *iter /= *iter1;
    }
    return new_vec;
}
template <Data_concept T>
template <Convert_Assig_Div<T> T1>
My_Vector<T>& My_Vector<T>::operator /= (const My_Vector<T1> &other)
{
    *this = (My_Vector<T>) (*this / other);
    return *this;
}
template <Data_concept T>
template <Convert_Assig_Div<T> T1>
decltype(auto) My_Vector<T>::elem_div(const My_Vector<T1> &other) const
{
    return *this / other;
}
template <Data_concept T>
template <Convert_Assig_Div<T> T1>
My_Vector<T>& My_Vector<T>::elem_div_equate(const My_Vector<T1> &other)
{
    *this = (My_Vector<T>) (*this / other);
    return *this;
}

// отрицание вектора (каждый элемент меняет знак)
template <Data_concept T>
My_Vector<T> My_Vector<T>::operator - (void)
{
    this->check_vec_size(this->count_axis, __LINE__);
    My_Vector<T> new_vec(*this);
    for (My_Iterator<T> iter = new_vec.begin(); iter != new_vec.end(); iter++)
        *iter = -(*iter);
    return new_vec;
}
template <Data_concept T>
My_Vector<T> My_Vector<T>::neg(void)
{
    return -(*this);
}

// перегрузка равенства / неравенства
template <Data_concept T>
template <typename Con>
    requires Valid_container<T, Con>
bool My_Vector<T>::operator == (const Con &other) const
{
    bool rc = this->count_axis == other.size();
    if (rc)
    {
        My_Iterator<T> iter = this->begin();
        for (auto iter1 = other.begin(); iter1 != other.end() && rc; iter1++)
        {
            if (fabc(*iter - *iter1) > EPS)
                rc = false;
            iter++;
        }
    }
    return rc;
}
template <Data_concept T>
template <typename Con>
    requires Valid_container<T, Con>
bool My_Vector<T>::operator != (const Con &other) const
{
    return !(*this == other);
}
template <Data_concept T>
template <typename Con>
    requires Valid_container<T, Con>
bool My_Vector<T>::is_equal(const Con &other) const
{
    return *this == other;
}

// перегрузка оператора равно
template <Data_concept T>
template <typename Con>
    requires Valid_container<T, Con>
My_Vector<T>& My_Vector<T>::operator = (const Con &other)
{
    this->count_axis = other.size();
    this->mem_alloc(this->count_axis, __LINE__);
    My_Iterator<T> iter = this->begin();
    for (auto iter1 = other.begin(); iter1 != other.end(); iter1++)
    {
        *iter = *iter1;
        iter++;
    }
    return *this;
}
template <Data_concept T>
template <typename Con>
    requires Valid_container<T, Con>
My_Vector<T>& My_Vector<T>::operator = (Con &&other) noexcept
{
    this->count_axis = other.size();
    this->mem_alloc(this->count_axis, __LINE__);
    this->pvec = other.pvec;
    other.pvec.reset();
    return *this;
}
template <Data_concept T>
template <Convertable<T> U>
My_Vector<T>& My_Vector<T>::operator = (initializer_list<U> arr)
{
    this->count_axis = arr.size();
    mem_alloc(this->count_axis, __LINE__);
    My_Iterator<T> iter = this->begin();
    for (auto &elem : arr)
    {
        *iter = elem;
        iter++;
    }
    return *this;
}

// возвращает мой итератор на начало вектора
template <Data_concept T>
My_Iterator<T> My_Vector<T>::begin(void) noexcept
{
    My_Iterator<T> iter(*this);
    return iter;
}
// возвращает мой итератор на конец вектора
template <Data_concept T>
My_Iterator<T> My_Vector<T>::end(void) noexcept
{
    My_Iterator<T> iter(*this);
    return iter + this->count_axis;
}
// возвращает мой константный итератор на начало вектора
template <Data_concept T>
My_CIterator<T> My_Vector<T>::begin(void) const noexcept
{
    My_CIterator<T> iter(*this);
    return iter;
}
// возвращает мой константный итератор на конец вектора
template <Data_concept T>
My_CIterator<T> My_Vector<T>::end(void) const noexcept
{
    My_CIterator<T> iter(*this);
    return iter + this->count_axis;
}
// возвращает мой константный итератор на начало вектора
template <Data_concept T>
My_CIterator<T> My_Vector<T>::cbegin(void) const noexcept
{
    My_CIterator<T> iter(*this);
    return iter;
}
// возвращает мой константный итератор на конец вектора
template <Data_concept T>
My_CIterator<T> My_Vector<T>::cend(void) const noexcept
{
    My_CIterator<T> iter(*this);
    return iter + this->count_axis;
}

// выделение памяти с проверкой
template <Data_concept T>
void My_Vector<T>::mem_alloc(const int &size, int line)
{
    try
    {
        pvec.reset(new T[size], std::default_delete<T[]>());
    }
    catch (bad_alloc &exc)
    {
        time_t time_now = time(NULL);
        throw Err_memory(__FILE__, line, typeid(*this).name(), ctime(&time_now));
    }
    // стартовое заполнение нулями
    //for (My_Iterator<T> iter(*this); iter != this->end(); iter++)
    //    *iter = 0;
}
// проверка размера вектора на положительность
template <Data_concept T>
void My_Vector<T>::check_vec_size(const int &size, int line) const
{
    if (size <= 0)
    {
        time_t time_now = time(NULL);
        throw Err_neg_size(__FILE__, line, typeid(*this).name(), ctime(&time_now));
    }
}
// проверка, что длина вектора равна 3/5/7 для векторного умножения
template <Data_concept T>
void My_Vector<T>::check_size_vec_mul(const int &size, int line) const
{
    if (size != 3 && size != 5 && size != 7)
    {
        time_t time_now = time(NULL);
        throw Err_size_vec_mul(__FILE__, line, typeid(*this).name(), ctime(&time_now));
    }
}
// проверка равенства размеров векторов
template <Data_concept T>
void My_Vector<T>::check_size_equal(const int &size, int line) const
{
    if (this->count_axis != size)
    {
        time_t time_now = time(NULL);
        throw Err_size_vec_not_equal(__FILE__, line, typeid(*this).name(), ctime(&time_now));
    }
}
// проверка массива на null
template <Data_concept T>
void My_Vector<T>::check_arr_null(const T *arr, int line) const
{
    if (! arr)
    {
        time_t time_now = time(NULL);
        throw Err_arr_null(__FILE__, line, typeid(*this).name(), ctime(&time_now));
    }
}
// проверка делителя-числа на нуль
template <Data_concept T>
void My_Vector<T>::check_div_zero(const T &num, int line) const
{
    if (! num)
    {
        time_t time_now = time(NULL);
        throw Err_zero_div(__FILE__, line, typeid(*this).name(), ctime(&time_now));
    }
}
// проверка индекса на попадание в размер массива
template <Data_concept T>
void My_Vector<T>::check_index(const int &index, int line) const
{
    if (index < 0 || index >= this->count_axis)
    {
        time_t time_now = time(NULL);
        throw Err_index_out_of_range(__FILE__, line, typeid(*this).name(), ctime(&time_now));
    }
}

// перегрузка оператора вывода
template <Data_concept T>
ostream& operator << (ostream &output, My_Vector<T> const &vector)
{
    if (vector.is_empty())
    {
        output << "empty vector";
    }
    else
    {
        My_CIterator<T> iter(vector);
        output << '(' << *iter;
        for (iter += 1; iter != vector.end(); iter++)
            output << ", " << *iter;
        output << ')';
    }
    return output;
}

#endif // MY_VECTOR_HPP
