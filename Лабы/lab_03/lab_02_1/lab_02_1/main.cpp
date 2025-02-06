#include <iostream>
#include <vector>

#include "my_vector.h"
#include "my_iterator.h"
#include "my_citerator.h"
#include "my_exception.h"

using namespace std;

void test_my_vector()
{
    cout << endl << "   TEST_MY_VECTOR" << endl;

    // инициализация векторов
    My_Vector<int> vec_len(3);
    cout << "Vector init by len: " << vec_len << endl;
    My_Vector<double> vec_fill = {1, 2, 3};
    cout << "Vector init by fill: "<< vec_fill << endl;
    My_Vector<double> vec_len_fill(3, 1.0, 2.1, 3.5);
    cout << "Vector init by len and fill: "<< vec_len_fill << endl;
    My_Vector<int> vec_empty; // то же что и vec_empty(0)
    cout << "Vector empty: "<< vec_empty << endl;
    // range
    std::vector<int> vec = {1, 2, 3, 4, 5};
    My_Vector<int> vec_range(vec);
    cout << "Vector (range): "<< vec_range << endl << endl;

    // вектора и число для тестирования
    My_Vector<int> vec1 = {2, 4, 0};
    My_Vector<int> vec2 = {3, 6, 0};
    My_Vector<int> vec3 = {5, -7, 2};
    My_Vector<int> vec4 = {-2, 1, 3};
    My_Vector<double> vec5 = {51.1, -27.0, 32.0};
    int num = 2;

    //My_Vector<string> vecs = {"Hello", "who", "are"};
    //vec1 + vecs; error (Summable(int, string) != true)
    //vec1.angle_betw(vecs); error

    //нормализация вектора
    cout << "Normalization vector: " << vec5 << " -> " << vec5.to_single() << endl;
    // нулевой ли вектор
    cout << "Is the vector zero? " << vec1 << " -> " << vec1.is_zero() << endl;
    // единичный ли вектор
    cout << "Is the vector single? " << vec2 << " -> " << vec2.is_single() << endl;
    // количество координат вектора
    cout << "Count coords of vector: " << vec3 << " -> " << vec3.size() << endl;
    // длина вектора
    cout << "Vector's length: " << vec2 << " -> " << vec2.len() << endl;
    // угол между векторами
    cout << "Angle between the vectors: " << vec1 << " & " << vec2 << " -> " << vec1.angle_betw(vec2) << endl << endl;

    // изменить значение элемента вектора по индексу
    vec3.set_item(1, 10);
    cout << "Set vector's second elem to 10: " << vec3 << endl;
    // вывести элемент по индексу
    cout << "Get vector's second elem: " << vec3 << " -> " << vec3.get_item(1) << endl << endl;

    // сложение векторов
    cout << "Addition of vectors: " << vec3 << " + " << vec2 << " -> " << vec3 + vec2 << endl;
    cout << "                     " << vec3 << ".vec_sum(" << vec2 << ")" << " -> " << vec3.vec_sum(vec2) << endl;
    cout << "                     " << vec3 << " += " << vec2 << " -> ";
    vec3 += vec2;
    cout << vec3 << endl;
    cout << "                     " << vec3 << ".vec_sum(" << vec2 << ")" << " -> " << vec3.vec_sum(vec2) << endl;
    cout << "                     " << vec3 << ".vec_sum_equate(" << vec2 << ")" << " -> ";
    vec3.vec_sum_equate(vec2);
    cout << vec3 << endl << endl;

    // сложение вектора и числа
    cout << "Addition of vector and number: " << vec3 << " + " << num << " -> " << vec3 + num << endl;
    cout << "                               " << num << " + " << vec3 << " -> " << num + vec3 << endl;
    cout << "                               " << vec3 << " += " << num << " -> ";
    vec3 += num;
    cout << vec3 << endl;
    cout << "                               " << vec3 << ".num_sum(" << num << ")" << " -> " << vec3.num_sum(num) << endl;
    cout << "                               " << vec3 << ".num_sum_equate(" << num << ")" << " -> ";
    vec3.num_sum_equate(num);
    cout << vec3 << endl << endl;

    // вычитание векторов
    cout << "Subtraction of vectors: " << vec3 << " - " << vec2 << " -> " << vec3 - vec2 << endl;
    cout << "                        " << vec3 << " -= " << vec2 << " -> ";
    vec3 -= vec2;
    cout << vec3 << endl;
    cout << "                        " << vec3 << ".vec_sub(" << vec2 << ")" << " -> " << vec3.vec_sub(vec2) << endl;
    cout << "                        " << vec3 << ".vec_sub_equate(" << vec2 << ")" << " -> ";
    vec3.vec_sub_equate(vec2);
    cout << vec3 << endl << endl;

    // вычитание из вектора числа
    cout << "Subtraction number from vector: " << vec3 << " - " << num << " -> " << vec3 - num << endl;
    cout << "                                " << vec3 << " -= " << num << " -> ";
    vec3 -= num;
    cout << vec3 << endl;
    cout << "                                " << vec3 << ".num_sub(" << num << ")" << " -> " << vec3.num_sub(num) << endl;
    cout << "                                " << vec3 << ".num_sub_equate(" << num << ")" << " -> ";
    vec3.num_sub_equate(num);
    cout << vec3 << endl << endl;

    // векторное умножение векторов
    cout << "Vector multy of vectors: " << vec3 << " ^ " << vec2 << " -> " << (vec3 ^ vec2) << endl;
    cout << "                         " << vec3 << " ^= " << vec2 << " -> ";
    vec3 ^= vec2;
    cout << vec3 << endl;
    cout << "                         " << vec3 << ".vec_mul(" << vec2 << ")" << " -> " << vec3.vec_mul(vec2) << endl;
    cout << "                         " << vec3 << ".vec_mul_equate(" << vec2 << ")" << " -> ";
    vec3.vec_mul_equate(vec2);
    cout << vec3 << endl << endl;

    vec3 = {5, -7, 2};
    // умножение вектора на число
    cout << "Multy of vector by number: " << vec3 << " * " << num << " -> " << vec3 * num << endl;
    cout << "                           " << num << " * " << vec3 << " -> " << num * vec3 << endl;
    cout << "                           " << vec3 << " *= " << num << " -> ";
    vec3 *= num;
    cout << vec3 << endl;
    cout << "                           " << vec3 << ".num_mul(" << num << ")" << " -> " << vec3.num_mul(num) << endl;
    cout << "                           " << vec3 << ".num_mul_equate(" << num << ")" << " -> ";
    vec3.num_mul_equate(num);
    cout << vec3 << endl << endl;

    vec3 = {5, -7, 2};
    // поэлементное умножение векторов
    cout << "Element-by-element multy of vectors: " << vec3 << " * " << vec2 << " -> " << vec3 * vec2 << endl;
    cout << "                         " << vec3 << " *= " << vec2 << " -> ";
    vec3 *= vec2;
    cout << vec3 << endl;
    cout << "                         " << vec3 << ".elem_mul(" << vec2 << ")" << " -> " << vec3.elem_mul(vec2) << endl;
    cout << "                         " << vec3 << ".elem_mul_equate(" << vec2 << ")" << " -> ";
    vec3.elem_mul_equate(vec2);
    cout << vec3 << endl << endl;

    vec3 = {5, -7, 2};
    // скалярное умножение векторов
    int res_mul = vec3 & vec2;
    cout << "Scalar multy of vectors: " << vec3 << " & " << vec2 << " -> " << res_mul << endl;
    cout << "                         " << vec3 << ".scal_mul(" << vec2 << ")" << " -> " << vec3.scal_mul(vec2) << endl;

    // деление вектора на число
    cout << "Divis of vector by number: " << vec3 << " / " << num << " -> " << vec3 / num << endl;
    cout << "                           " << vec3 << " /= " << num << " -> ";
    vec3 /= num;
    cout << vec3 << endl;
    cout << "                           " << vec3 << ".num_div(" << num << ")" << " -> " << vec3.num_div(num) << endl;
    cout << "                           " << vec3 << ".num_div_equate(" << num << ")" << " -> ";
    vec3.num_div_equate(num);
    cout << vec3 << endl << endl;

    vec3 = {52, -71, 28};
    // деление векторов поэлементное
    cout << "Element-by-element division of vectors: " << vec3 << " / " << vec4 << " -> " << vec3 / vec4 << endl;
    cout << "                     " << vec3 << " /= " << vec4 << " -> ";
    vec3 /= vec4;
    cout << vec3 << endl;
    cout << "                     " << vec3 << ".elem_div(" << vec4 << ")" << " -> " << vec3.elem_div(vec4) << endl;
    cout << "                     " << vec3 << ".elem_div_equate(" << vec4 << ")" << " -> ";
    vec3.elem_div_equate(vec4);
    cout << vec3 << endl << endl;

    // вектора коллинеарны?
    cout << "Vectors are collinear: " << vec1 << " & " << vec2 << " -> " << vec1.is_collin(vec2) << endl;
    cout << "Vectors not collinear: " << vec1 << " & " << vec4 << " -> " << vec1.is_collin(vec4) << endl << endl;
    // вектора ортогональны?
    //cout << "Vectors not orthogonal: " << vec1 << " & " << vec4 << " -> " << vec1.is_orthog(vec4) << endl;
    cout << "Vectors not orthogonal: " << vec1 << " & " << vec2 << " -> " << vec1.is_orthog(vec2) << endl << endl;

    // ошибочки генерируем и ловим
    cout << "Generate errors:" << endl;
    // инициализация векторов
    try
    {
        My_Vector<int> vec_mlen(-1);
    }
    catch (My_Base_Error &err)
    {
        cout << err.what() << endl;
    }
    // деление на нуль
    try
    {
        vec3 / 0;
    }
    catch (My_Base_Error &err)
    {
        cout << err.what() << endl;
    }
}

void test_my_iterator()
{
    cout << endl << "   TEST_MY_ITERATOR" << endl;

    // создаём объект вектор
    My_Vector<int> vec = {1, 2, 3, 4, 5};

    // создаём объект итератор вектора
    //My_Iterator<int> iter(vec.begin());

    // вывод не константный
    cout << "Elements in vector (by iter):   ";
    for (My_Iterator iter = vec.begin(); iter != vec.end(); ++iter)
        cout << *iter << "   ";
    cout << endl;

    // вывод константный
    cout << "Elements in vector (by const iter):   ";
    for (My_CIterator citer = vec.cbegin(); citer != vec.cend(); ++citer)
    {
        //*citer = 10; error (const)
        cout << *citer << "   ";
    }
    cout << endl;
}

int main(void)
{

    cout << endl << "----------- Start program ------------" << endl;
    test_my_vector();
    test_my_iterator();
    cout << endl << "----------- End program --------------" << endl;
    return 0;
}
