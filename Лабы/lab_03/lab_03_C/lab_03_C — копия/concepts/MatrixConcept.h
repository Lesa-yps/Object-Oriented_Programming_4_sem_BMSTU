#ifndef MATRIX_CONCEPT_H
#define MATRIX_CONCEPT_H

#include <concepts>

using namespace std;

template <typename T>
concept TypeForMatrix = requires(T a, T b) {
    { a + b } -> same_as<T>;
    { a - b } -> same_as<T>;
    { a *b } -> same_as<T>;
    { a / b } -> same_as<T>;
    { a < b } -> convertible_to<bool>;
    { a > b } -> convertible_to<bool>;
    { a <= b } -> convertible_to<bool>;
    { a >= b } -> convertible_to<bool>;
    { a == b } -> convertible_to<bool>;
    { a != b } -> convertible_to<bool>;
    a = b;
};

template <typename From, typename To>
concept Convertable = convertible_to<From, To>;

template <typename From, typename To>
concept Assignable = requires(From fm, To t) {
    t = fm;
};

template <typename C>
concept Container = requires(C con) {
    typename C::value_type;
    typename C::size_type;
    typename C::iterator;
    typename C::const_iterator;

    { con.size() } noexcept -> same_as<typename C::size_type>;
    { con.end() } noexcept -> same_as<typename C::iterator>;
    { con.begin() } noexcept -> same_as<typename C::iterator>;
};

template <typename Con, typename T>
concept ContainerConvertableAssignable = Container<Con> &&
                                         Convertable<typename Con::value_type, T> &&
                                         Assignable<typename Con::value_type, T>;

#endif // MATRIX_CONCEPT_H
