#include "task_manager.h"

error_t task_manager(const request_t &request)
{
    error_t rc = OK;
    // инициализация объекта
    static struct Thing obj = init_obj();
    switch (request.action)
    {
    case UPLOAD:
        // записывает данные об объекте в файл
        rc = upload_obj(obj, request.filename);
        break;
    case LOAD:
        // читает объект из файла
        rc = load_obj(obj, request.filename);
        break;
    case MOVE:
        // перенос
        brain_move_obj(obj, request.move);
        break;
    case SCALE:
        // масштабирование
        rc = brain_scale_obj(obj, request.scale);
        break;
    case TURN:
        // поворот
        brain_turn_obj(obj, request.turn);
        break;
    case DRAW:
        // перерисовка объекта
        rc = redraw_obj(obj, request.view);
        break;
    case QUIT:
        // освобождает память из-под объекта
        free_obj(obj);
        break;
    default:
        rc = ERR_TASK;
    }
    return rc;
}
