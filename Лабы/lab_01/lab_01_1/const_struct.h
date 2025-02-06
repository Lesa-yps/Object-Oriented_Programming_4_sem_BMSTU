#ifndef CONST_STRUCT_H
#define CONST_STRUCT_H

// коды ошибок
enum Error_code
{
    OK,
    ERROR,
    ERR_OPEN_FILE,
    ERR_CLOSE_FILE,
    ERR_READ_FILE,
    ERR_MEM,
    ERR_TASK,
    ERR_SCENE,
    ZERO_OBJ,
    ERR_COUNT_POINT,
    ERR_COUNT_LINE,
    ERR_END_LINE
};
typedef enum Error_code error_t;
// координаты
#define COUNT_COORDS 3
enum Coords
{
    X_COORD,
    Y_COORD,
    Z_COORD,
};

struct Matrix
{
    int n;
    int m;
    int **mat;
    // Конструктор по умолчанию для инициализации значений структуры
    //Matrix() : n(0), m(0), mat(nullptr) {}
};
// структура хранит обрабатываемый объект (набор точек и линий их соединяющих) (нумерация точек с нуля)
struct Thing
{
    struct Matrix arr_point;
    struct Matrix arr_line;
};

#endif // CONST_STRUCT_H
