#include "init_obj.h"

// инициализация матрицы
void init_mat(struct Matrix &arr)
{
    arr.mat = NULL;
    arr.n = 0;
    arr.m = 0;
}

// инициализация объекта
struct Thing init_obj(void)
{
    struct Thing obj;
    init_mat(obj.arr_point);
    init_mat(obj.arr_line);
    return obj;
}
