#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <memory>

#include "my_base_vector.h"
#include "my_iterator.h"
#include "my_citerator.hpp"
#include "my_concepts.hpp"

using namespace std;

// мой класс вектор
template <Data_concept T>
class My_Vector: public My_Base_Vector
{
public:
    using value_type = T;
    using iterator = My_Iterator<T>;
    using const_iterator = My_CIterator<T>;

    friend class My_Iterator<T>;
    friend class My_CIterator<T>;

    // конструкторы векторов
    // без параметров vec_size()
    My_Vector();
    // по размеру vec_size(3)
    explicit My_Vector(const int &size);
    // по списку инициализации vec_fill = {1, 2, 3}
    template <Convert_Assig<T> U>
    My_Vector(initializer_list<U> arr);
    // по длине и массиву инициализации vec_len_fill1(3, arr)
    template <Convert_Assig<T> U>
    My_Vector(int size, const U *arr);
    // по длине и элементам заполнения vec_len_fill2(3, 1.0, 2.1, 3.5)
    template <Convert_Assig<T> U>
    My_Vector(int size, U elem, ...);
    // по двум итераторам
    template <Forward_iterator Ti>
    My_Vector(Ti begin, Ti end);
    // конструктор копирования
    // по левой ссылке на другой вектор
    explicit My_Vector(const My_Vector<T> &other);
    // конструктор переноса
    // по правой ссылке на другой вектор
    My_Vector(My_Vector<T> &&other) noexcept;
    // деструктор по умолчанию
    virtual ~My_Vector() = default;
    // преобразование из другого моего контейнера
    template <Convert_Assig<T> T1>
    My_Vector(const My_Vector<T1> &other);
    // преобразование из другого контейнера
    template <typename Con>
        requires Valid_container<T, Con>
    My_Vector(const Con &other);

    // нормализация вектора
    decltype(auto) to_single(void) const;
    // нулевой ли вектор
    bool is_zero(void) const;
    // единичный ли вектор
    bool is_single(void) const;
    // длина вектора
    decltype(auto) len(void) const;
    // угол между векторами
    template <typename Con>
        requires Valid_container<T, Con>
    decltype(auto) angle_betw(const Con &other) const;
    // вектора коллинеарны?
    template <typename Con>
        requires Valid_container<T, Con>
    bool is_collin(const Con &other) const;
    // вектора ортогональны?
    template <typename Con>
        requires Valid_container<T, Con>
    bool is_orthog(const Con &other) const;

    // изменить значение элемента вектора по индексу
    template <Convert_Assig<T> U>
    void set_item(int ind, const U& elem);
    // вывести элемент по индексу
    T& get_item(int ind);
    const T& get_item(int ind) const;
    // перегрузка []
    T& operator [] (int ind);
    const T& operator [] (int ind) const;

    // сложение векторов
    template <Convert_Assig_Sum<T> T1>
    decltype(auto) operator + (const My_Vector<T1> &other) const;
    template <Convert_Assig_Sum<T> T1>
    My_Vector<T>& operator += (const My_Vector<T1> &other);
    template <Convert_Assig_Sum<T> T1>
    decltype(auto) vec_sum(const My_Vector<T1> &other) const;
    template <Convert_Assig_Sum<T> T1>
    My_Vector<T>& vec_sum_equate(const My_Vector<T1> &other);
    // сложение вектора и числа
    template <Convert_Assig_Sum<T> T1>
    decltype(auto) operator + (const T1 &num) const;
    template <Convert_Assig_Sum<T> T1>
    My_Vector<T>& operator += (const T1 &num);
    template <Convert_Assig_Sum<T> T1>
    decltype(auto) num_sum(const T1 &num) const;
    template <Convert_Assig_Sum<T> T1>
    My_Vector<T>& num_sum_equate(const T1 &num);

    // вычитание векторов
    template <Convert_Assig_Diff<T> T1>
    decltype(auto) operator - (const My_Vector<T1> &other) const;
    template <Convert_Assig_Diff<T> T1>
    My_Vector<T>& operator -= (const My_Vector<T1> &other);
    template <Convert_Assig_Diff<T> T1>
    decltype(auto) vec_sub(const My_Vector<T1> &other) const;
    template <Convert_Assig_Diff<T> T1>
    My_Vector<T>& vec_sub_equate(const My_Vector<T1> &other);
    // вычитание из вектора числа
    template <Convert_Assig_Diff<T> T1>
    decltype(auto) operator - (const T1 &num) const;
    template <Convert_Assig_Diff<T> T1>
    My_Vector<T>& operator -= (const T1 &num);
    template <Convert_Assig_Diff<T> T1>
    decltype(auto) num_sub(const T1 &num) const;
    template <Convert_Assig_Diff<T> T1>
    My_Vector<T>& num_sub_equate(const T1 &num);

    // умножение векторов поэлементное
    template <Convert_Assig_Mul<T> T1>
    decltype(auto) operator * (const My_Vector<T1> &other) const;
    template <Convert_Assig_Mul<T> T1>
    My_Vector<T>& operator *= (const My_Vector<T1> &other);
    template <Convert_Assig_Mul<T> T1>
    decltype(auto) elem_mul(const My_Vector<T1> &other) const;
    template <Convert_Assig_Mul<T> T1>
    My_Vector<T>& elem_mul_equate(const My_Vector<T1> &other);
    // векторное умножение векторов
    template <Convert_Assig_Mul_Diff<T> T1>
    decltype(auto) operator ^ (const My_Vector<T1> &other) const;
    template <Convert_Assig_Mul_Diff<T> T1>
    My_Vector<T>& operator ^= (const My_Vector<T1> &other);
    template <Convert_Assig_Mul_Diff<T> T1>
    decltype(auto) vec_mul(const My_Vector<T1> &other) const;
    template <Convert_Assig_Mul_Diff<T> T1>
    My_Vector<T>& vec_mul_equate(const My_Vector<T1> &other);
    // умножение вектора на число
    template <Convert_Assig_Mul<T> T1>
    decltype(auto) operator * (const T1 &num) const;
    template <Convert_Assig_Mul<T> T1>
    My_Vector<T>& operator *= (const T1 &num);
    template <Convert_Assig_Mul<T> T1>
    decltype(auto) num_mul(const T1 &num) const;
    template <Convert_Assig_Mul<T> T1>
    My_Vector<T>& num_mul_equate(const T1 &num);
    // скалярное умножение векторов
    template <Convert_Assig_Mul_Sum<T> T1>
    decltype(auto) operator & (const My_Vector<T1> &other) const;
    template <Convert_Assig_Mul_Sum<T> T1>
    decltype(auto) scal_mul(const My_Vector<T1> &other);

    // деление вектора на число
    template <Convert_Assig_Div<T> T1>
    decltype(auto) operator / (const T1 &num) const;
    template <Convert_Assig_Div<T> T1>
    My_Vector<T>& operator /= (const T1 &num);
    template <Convert_Assig_Div<T> T1>
    decltype(auto) num_div(const T1 &num) const;
    template <Convert_Assig_Div<T> T1>
    My_Vector<T>& num_div_equate(const T1 &num);
    // деление векторов поэлементное
    template <Convert_Assig_Div<T> T1>
    decltype(auto) operator / (const My_Vector<T1> &other) const;
    template <Convert_Assig_Div<T> T1>
    My_Vector<T>& operator /= (const My_Vector<T1> &other);
    template <Convert_Assig_Div<T> T1>
    decltype(auto) elem_div(const My_Vector<T1> &other) const;
    template <Convert_Assig_Div<T> T1>
    My_Vector<T>& elem_div_equate(const My_Vector<T1> &other);

    // отрицание вектора
    My_Vector<T> operator - (void);
    My_Vector<T> neg(void);



    // перегрузка равенства / неравенства
    template <typename Con>
        requires Valid_container<T, Con>
    bool operator == (const Con &other) const;
    template <typename Con>
        requires Valid_container<T, Con>
    bool operator != (const Con &other) const;
    template <typename Con>
        requires Valid_container<T, Con>
    bool is_equal(const Con &other) const;

    // перегрузка оператора равно
    template <typename Con>
        requires Valid_container<T, Con>
    My_Vector<T>& operator = (Con &&other) noexcept;
    template <Convertable<T> U>
    My_Vector<T>& operator = (initializer_list<U> arr);
    template <typename Con>
        requires Valid_container<T, Con>
    My_Vector<T>& operator = (const Con &other);

    // возвращает мой итератор на начало вектора
    My_Iterator<T> begin(void) noexcept;
    // возвращает мой итератор на конец вектора
    My_Iterator<T> end(void) noexcept;
    // возвращает мой константный итератор на начало вектора
    My_CIterator<T> begin(void) const noexcept;
    // возвращает мой константный итератор на конец вектора
    My_CIterator<T> end(void) const noexcept;
    // возвращает мой константный итератор на начало вектора
    My_CIterator<T> cbegin(void) const noexcept;
    // возвращает мой константный итератор на конец вектора
    My_CIterator<T> cend(void) const noexcept;

protected:
    // выделение памяти с проверкой
    void mem_alloc(const int &size, int line);
    // проверка размера вектора на положительность
    void check_vec_size(const int &size, int line) const;
    // проверка, что длина вектора равна 3 для векторного умножения
    void check_size_vec_mul(const int &size, int line) const;
    // проверка равенства размеров векторов
    void check_size_equal(const int &size, int line) const;
    // проверка массива на null
    void check_arr_null(const T *arr, int line) const;
    // проверка делителя-числа на нуль
    void check_div_zero(const T &num, int line) const;
    // проверка индекса на попадание в размер массива
    void check_index(const int &index, int line) const;
private:
    shared_ptr<T[]> pvec;
};

#include "my_vector.hpp"

#endif // MY_VECTOR_H
