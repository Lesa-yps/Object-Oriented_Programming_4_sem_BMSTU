#ifndef CLASS_CONCEPT_H
#define CLASS_CONCEPT_H

#include <concepts>

using namespace std;

template <typename Type>
concept Abstract = is_abstract_v<Type>;

template <typename Type>
concept NotAbstract = !is_abstract_v<Type>;

template <typename Derived, typename Base>
concept Derivative = is_base_of_v<Base, Derived>;

template <typename Type, typename... Args>
concept Constructible = is_constructible_v<Type, Args...>;

template <typename T>
concept AbstractCLass = is_class_v<T> && is_abstract_v<T>;

template <typename T>
concept NotAbstractClass = is_class_v<T> && !is_abstract_v<T>;

template <typename T>
concept CopyConstructible = requires(T t) {
    T(t);
};

#endif // CLASS_CONCEPT_H
