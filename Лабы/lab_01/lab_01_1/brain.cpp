#include "brain.h"

#define PI 3.14159265
#define EPS 0.00001
// переводит градусы в радианы
double radians(const double angle)
{
    return angle * (PI / 180.0);
}
// сравнивает вещественное число с нулём
int is_zero(const double num)
{
    return fabs(num) < EPS;
}

// перенос по координате
void move_points_x(struct Matrix &arr_point, const double ds)
{
    for (int i = 0; i < arr_point.n; i++)
        arr_point.mat[i][X_COORD] += ds;
}
void move_points_y(struct Matrix &arr_point, const double ds)
{
    for (int i = 0; i < arr_point.n; i++)
        arr_point.mat[i][Y_COORD] += ds;
}
void move_points_z(struct Matrix &arr_point, const double ds)
{
    for (int i = 0; i < arr_point.n; i++)
        arr_point.mat[i][Z_COORD] += ds;
}
// перенос
void brain_move_obj(struct Thing &obj, const struct Move &move_data)
{
    move_points_x(obj.arr_point, move_data.coord_d[X_COORD]);
    move_points_y(obj.arr_point, move_data.coord_d[Y_COORD]);
    move_points_z(obj.arr_point, move_data.coord_d[Z_COORD]);
}



// проверка коэффициентов масштабирования на нуль
error_t check_coord_k(const double *coord_k)
{
    error_t rc = OK;
    if (is_zero(coord_k[X_COORD]) || is_zero(coord_k[Y_COORD]) || is_zero(coord_k[Z_COORD]))
        rc = ZERO_OBJ;
    return rc;
}
// перенос по координате
void scale_points_x(struct Matrix &arr_point, const struct Scale &scale_data)
{
    for (int i = 0; i < arr_point.n; i++)
        arr_point.mat[i][X_COORD] = scale_data.central_point[X_COORD] + (arr_point.mat[i][X_COORD] - scale_data.central_point[X_COORD])\
                                                                            * scale_data.coord_k[X_COORD];
}
void scale_points_y(struct Matrix &arr_point, const struct Scale &scale_data)
{
    for (int i = 0; i < arr_point.n; i++)
        arr_point.mat[i][Y_COORD] = scale_data.central_point[Y_COORD] + (arr_point.mat[i][Y_COORD] - scale_data.central_point[Y_COORD])\
                                                                            * scale_data.coord_k[Y_COORD];
}
void scale_points_z(struct Matrix &arr_point, const struct Scale &scale_data)
{
    for (int i = 0; i < arr_point.n; i++)
        arr_point.mat[i][Z_COORD] = scale_data.central_point[Z_COORD] + (arr_point.mat[i][Z_COORD] - scale_data.central_point[Z_COORD])\
                                                                            * scale_data.coord_k[Z_COORD];
}
// масштабирование
error_t brain_scale_obj(struct Thing &obj, const struct Scale &scale_data)
{
    error_t rc = check_coord_k(scale_data.coord_k);
    if (rc == OK)
    {
        scale_points_x(obj.arr_point, scale_data);
        scale_points_y(obj.arr_point, scale_data);
        scale_points_z(obj.arr_point, scale_data);
    }
    return rc;
}



// поворот по оси
void turn_around_x(struct Matrix &arr_point, const struct Turn &turn_data)
{
    const double angle_rad = radians(turn_data.angle);
    for (int i = 0; i < arr_point.n; i++)
    {
        int old_y = arr_point.mat[i][Y_COORD];
        arr_point.mat[i][Y_COORD] = turn_data.central_point[Y_COORD] + (arr_point.mat[i][Y_COORD] - turn_data.central_point[Y_COORD])\
                                * cos(angle_rad) + (arr_point.mat[i][Z_COORD] - turn_data.central_point[Z_COORD]) * sin(angle_rad);
        arr_point.mat[i][Z_COORD] = turn_data.central_point[Z_COORD] - (old_y - turn_data.central_point[Y_COORD])\
                                * sin(angle_rad) + (arr_point.mat[i][Z_COORD] - turn_data.central_point[Z_COORD]) * cos(angle_rad);
    }
}
void turn_around_y(struct Matrix &arr_point, const struct Turn &turn_data)
{
    const double angle_rad = radians(turn_data.angle);
    for (int i = 0; i < arr_point.n; i++)
    {
        int old_x = arr_point.mat[i][X_COORD];
        arr_point.mat[i][X_COORD] = turn_data.central_point[X_COORD] + (arr_point.mat[i][X_COORD] - turn_data.central_point[X_COORD])\
                                * cos(angle_rad) + (arr_point.mat[i][Z_COORD] - turn_data.central_point[Z_COORD]) * sin(angle_rad);
        arr_point.mat[i][Z_COORD] = turn_data.central_point[Z_COORD] - (old_x - turn_data.central_point[X_COORD])\
                                * sin(angle_rad) + (arr_point.mat[i][Z_COORD] - turn_data.central_point[Z_COORD]) * cos(angle_rad);
    }
}
void turn_around_z(struct Matrix &arr_point, const struct Turn &turn_data)
{
    const double angle_rad = radians(turn_data.angle);
    for (int i = 0; i < arr_point.n; i++)
    {
        int old_x = arr_point.mat[i][X_COORD];
        arr_point.mat[i][X_COORD] = turn_data.central_point[X_COORD] + (arr_point.mat[i][X_COORD] - turn_data.central_point[X_COORD])\
                                * cos(angle_rad) + (arr_point.mat[i][Y_COORD] - turn_data.central_point[Y_COORD]) * sin(angle_rad);
        arr_point.mat[i][Y_COORD] = turn_data.central_point[Y_COORD] - (old_x - turn_data.central_point[Y_COORD])\
                                * sin(angle_rad) + (arr_point.mat[i][Y_COORD] - turn_data.central_point[Y_COORD]) * cos(angle_rad);
    }
}
// поворот
void brain_turn_obj(struct Thing &obj, const struct Turn &turn_data)
{
    if (turn_data.numb_coord == X_COORD)
        turn_around_x(obj.arr_point, turn_data);
    else if (turn_data.numb_coord == Y_COORD)
        turn_around_y(obj.arr_point, turn_data);
    else
        turn_around_z(obj.arr_point, turn_data);
}
