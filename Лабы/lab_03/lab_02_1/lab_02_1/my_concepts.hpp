#ifndef MY_CONCEPTS_HPP
#define MY_CONCEPTS_HPP

#include <concepts>
#include <iterator>
#include <cmath>

using namespace std;

// для вектора

template <typename From, typename To>
concept Convertable = convertible_to<From, To>;

template <typename From, typename To>
concept Assignable = requires(From fm, To to) { to = fm; };

template <typename T1, typename T2>
concept Divisable = requires(T1 a, T2 b) { a / b; };
template <typename T1, typename T2>
concept Multable = requires(T1 a, T2 b) { a * b; };
template <typename T1, typename T2>
concept Summable = requires(T1 a, T2 b) { a + b; };
template <typename T1, typename T2>
concept Differentable = requires(T1 a, T2 b) { a - b; };

template <typename T>
concept Unary_minus = requires(T t) { {-t} -> same_as<T>; };

template <typename T>
concept Sqrt_concept = requires(T t) { { sqrt(t * t) } -> convertible_to<T>; };

template <typename Type>
concept Data_concept = Assignable<Type, Type> &&
                       Summable<Type, Type> &&
                       Differentable<Type, Type> &&
                       Multable<Type, Type> &&
                       Divisable<Type, Type> &&
                       Unary_minus<Type> &&
                       Sqrt_concept<Type>;

template <typename Type>
concept Container = requires(Type t)
{
    typename Type::value_type;
    typename Type::size_type;
    typename Type::iterator;
    typename Type::const_iterator;

    { t.size() } noexcept -> same_as<typename Type::size_type>;

    { t.begin() } noexcept -> same_as<typename Type::iterator>;
    { t.end() } noexcept -> same_as<typename Type::iterator>;

    { t.cbegin() } noexcept -> same_as<typename Type::const_iterator>;
    { t.cend() } noexcept -> same_as<typename Type::const_iterator>;

};

// Концепт Valid_container
template<typename T, typename Con>
concept Valid_container = Container<Con> &&
                          Convertable<typename Con::value_type, T> &&
                          Assignable<typename Con::value_type, T>;

template <typename T, typename U>
concept Convert_Assig = Convertable<U, T> &&
                        Assignable<U, T>;

template <typename T, typename U>
concept Convert_Assig_Sum = Convert_Assig<U, T> &&
                            Summable<U, T>;

template <typename T, typename U>
concept Convert_Assig_Diff = Convert_Assig<U, T> &&
                            Differentable<U, T>;

template <typename T, typename U>
concept Convert_Assig_Mul = Convert_Assig<U, T> &&
                            Multable<U, T>;

template <typename T, typename U>
concept Convert_Assig_Mul_Sum = Convert_Assig_Mul<U, T> &&
                            Summable<U, T>;

template <typename T, typename U>
concept Convert_Assig_Mul_Diff = Convert_Assig_Mul<U, T> &&
                            Differentable<U, T>;

template <typename T, typename U>
concept Convert_Assig_Div = Convert_Assig<U, T> &&
                            Divisable<U, T>;


// для итератора

template <typename Type>
concept Iterator = requires(Type t)
{
    typename Type::value_type;
    typename Type::pointer;
    typename Type::reference;
    typename Type::difference_type;
};


// является ли первый тип производным от второго
template <typename T1, typename T2>
concept Type_derived_from = is_base_of<T1, T2>::value;

template<typename T>
concept Comparable = requires(T a, T b)
{
    { a == b } -> same_as<bool>;
    { a != b } -> same_as<bool>;
};

template <typename T>
concept Incrementable = requires(T a)
{
    { a++ } -> same_as<T>;
    { ++a } -> same_as<T&>;
};


template <typename T>
concept Input_iterator = Iterator<T> &&
                        requires { typename T::iterator_category; }&&
                        Comparable<T>&&
                        Type_derived_from<typename T::iterator_category, input_iterator_tag>;


template <typename T>
concept Forward_iterator = Input_iterator<T> &&
                          Incrementable<T> &&
                          Type_derived_from<typename T::iterator_category, forward_iterator_tag>;


#endif // MY_CONCEPTS_HPP
