#include "redraw_obj.h"

// очистка холста
error_t clear_scene(const struct Graph_view &view)
{
    if (view.scene == NULL)
        return ERR_SCENE;
    view.scene->clear();
    return OK;
}

// находит индекс точки по линии
int find_point_ind(const struct Matrix &arr_line, int ind_line, int ind_point)
{
    if (ind_line >= arr_line.n)
        ind_line = arr_line.n - 1;
    if (ind_point >= arr_line.m)
        ind_point = arr_line.m - 1;
    return arr_line.mat[ind_line][ind_point];
}

// находит отрисовываемые координаты точки по её индексу
int *find_point_coords(const struct Matrix &arr_point, const int line_end)
{
    int *point = (int *)calloc(sizeof(int), arr_point.m);
    for (int i = 0; i < arr_point.m; i++)
        point[i] = arr_point.mat[line_end][i];
    return point;
}

// находит отрисовываемые координаты точки по линии
int *find_point(const struct Thing &obj, const int ind_line, const int ind_point)
{
    int line_end = find_point_ind(obj.arr_line, ind_line, ind_point);
    return find_point_coords(obj.arr_point, line_end);
}

// рисует объект
error_t draw_obj(const struct Thing &obj, const struct Graph_view &view)
{
    if (!view.scene)
        return ERR_SCENE;
    for (int i = 0; i < obj.arr_line.n; i++)
    {
        int *point1 = find_point(obj, i, 0);
        int *point2 = find_point(obj, i, 1);
        //printf("p1 = (%d, %d), p2 = (%d, %d)\n", point1[X_COORD], point1[Y_COORD], point2[X_COORD], point2[Y_COORD]);
        view.scene->addLine(point1[X_COORD], point1[Y_COORD], point2[X_COORD], point2[Y_COORD]);
        free(point1);
        free(point2);
    }
    return OK;
}

// перерисовывает объект
error_t redraw_obj(const struct Thing &obj, const struct Graph_view &view)
{
    error_t rc = clear_scene(view);
    //printf("rc = %d\n", rc);
    if (rc == OK)
        rc = draw_obj(obj, view);
    return rc;
}
