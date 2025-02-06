#include "work_with_file.h"

// Освобождение памяти из-под матрицы
void free_mat(struct Matrix &matrix)
{
    if (matrix.mat != NULL)
    {
        for (int i = 0; i < matrix.n; ++i)
            free(matrix.mat[i]);
        free(matrix.mat);
    }
}

// Выделение памяти для матрицу
error_t create_mat(struct Matrix &matrix)
{
    error_t rc = OK;
    matrix.mat = (int**) calloc(matrix.n, sizeof(int*));
    if (matrix.mat == NULL)
        rc = ERR_MEM;
    else
    {
        for (int i = 0; i < matrix.n && rc == OK; ++i)
        {
            matrix.mat[i] = (int*) calloc(matrix.m, sizeof(int));
            if (matrix.mat[i] == NULL)
            {
                rc = ERR_MEM;
                free_mat(matrix);
            }
        }
    }
    return rc;
}

// читает матрицу из файла
error_t read_mat(struct Matrix &matrix, FILE *file, const int m)
{
    error_t rc = OK;
    matrix.m = m;
    if (fscanf(file, "%d", &(matrix.n)) != 1)
        rc = ERR_READ_FILE;
    else if ((rc = create_mat(matrix)) == OK)
    {
        for (int i = 0; i < matrix.n && rc == OK; i++)
            for (int j = 0; j < matrix.m && rc == OK; j++)
                if (fscanf(file, "%d", &(matrix.mat[i][j])) != 1)
                {
                    free_mat(matrix);
                    rc = ERR_READ_FILE;
                }
    }
    return rc;
}

// освобождает память из-под объекта
void free_obj(struct Thing &obj)
{
    free_mat(obj.arr_point);
    free_mat(obj.arr_line);
}

// копирует матрицу
error_t copy_mat(struct Matrix &matrix_copy, const struct Matrix &matrix)
{
    matrix_copy.n = matrix.n;
    matrix_copy.m = matrix.m;
    error_t rc = create_mat(matrix_copy);
    if (rc == OK)
    {
        matrix_copy.n = matrix.n;
        for (int i = 0; i < matrix.n; i++)
            for (int j = 0; j < matrix.m; j++)
                matrix_copy.mat[i][j] = matrix.mat[i][j];
    }
    return rc;
}

// копирует объект
error_t copy_obj(struct Thing &obj_copy, const struct Thing &obj)
{
    error_t rc = copy_mat(obj_copy.arr_point, obj.arr_point);
    if (rc == OK)
    {
        rc = copy_mat(obj_copy.arr_line, obj.arr_line);
        if (rc != OK)
            free_mat(obj_copy.arr_point);
    }
    return rc;
}

// проверяет валидность структур загружаемого объекта
error_t check_load_obj(const struct Matrix &arr_point, const struct Matrix &arr_line)
{
    error_t rc = OK;
    if (arr_point.n <= 0)
        rc = ERR_COUNT_POINT;
    else if (arr_line.n <= 0)
        rc = ERR_COUNT_LINE;
    else
    {
        for (int i = 0; i < arr_line.n && rc == OK; i++)
            for (int j = 0; j < arr_line.m && rc == OK; j++)
                if (arr_line.mat[i][j] >= arr_point.n)
                    rc = ERR_END_LINE;
    }
    return rc;
}

error_t load_obj(struct Thing &obj_start, const char *file_name)
{
    setbuf(stdout, NULL);
    struct Thing obj;
    error_t rc = OK;
    FILE *file = fopen(file_name, "r");
    //FILE *file = fopen("F:\\OOP\\STH.txt", "r");
    if (file == NULL)
    {
        rc = ERR_OPEN_FILE;
    }
    else
    {
        rc = read_mat(obj.arr_point, file, COUNT_COORDS);
        if (rc == OK)
        {
            rc = read_mat(obj.arr_line, file, 2);
            if (rc != OK)
                free_mat(obj.arr_point);
        }
        if (fclose(file) == EOF)
            rc = ERR_CLOSE_FILE;
    }
    if (rc == OK)
    {
        rc = check_load_obj(obj.arr_point, obj.arr_line);
        if (rc == OK)
        {
            free_obj(obj_start);
            rc = copy_obj(obj_start, obj);
            free_obj(obj);
        }
    }
    //upload_obj(obj_start, "f:\\NEW.txt");
    return rc;
}

// записывает матрицу в файл
void print_mat(FILE *file, const struct Matrix &matrix)
{
    fprintf(file, "%d\n", matrix.n);
    for (int i = 0; i < matrix.n; i++)
    {
        for (int j = 0; j < matrix.m; j++)
            fprintf(file, "%d ", matrix.mat[i][j]);
        fprintf(file, "\n");
    }
}

// записывает данные об объекте в файл
error_t upload_obj(const struct Thing &obj, const char *file_name)
{
    error_t rc = OK;
    FILE *file = fopen(file_name, "w");
    //printf("%s\n", file_name);
    if (file == NULL)
        rc = ERR_OPEN_FILE;
    else
    {
        print_mat(file, obj.arr_point);
        print_mat(file, obj.arr_line);
        if (fclose(file) == EOF)
            rc = ERR_CLOSE_FILE;
    }
    return rc;
}
