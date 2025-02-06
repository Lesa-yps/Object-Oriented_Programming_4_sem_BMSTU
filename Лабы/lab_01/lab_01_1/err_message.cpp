#include "err_message.h"

// переводит код ошибки в строку с сообщением об ошибке
const char *err_code_to_str(const error_t &err_code)
{
    const char *err_mess;
    switch (err_code)
    {
    case ERR_OPEN_FILE:
        err_mess = "Ошибка открытия файла.";
        break;
    case ERR_CLOSE_FILE:
        err_mess = "Ошибка закрытия файла.";
        break;
    case ERR_READ_FILE:
        err_mess = "Ошибка чтения данных из файла.";
        break;
    case ERR_MEM:
        err_mess = "Ошибка выделения памяти.";
        break;
    case ERR_SCENE:
        err_mess = "Ошибка при попытке отрисовки объекта.";
        break;
    case ERR_COUNT_POINT:
        err_mess = "Количество точек объекта должно быть больше нуля.";
        break;
    case ERR_COUNT_LINE:
        err_mess = "Количество рёбер объекта должно быть больше нуля.";
        break;
    case ERR_END_LINE:
        err_mess = "Конец ребра указывает на несуществующую точку (номер больше количества точек).";
        break;
    case ERROR:
        err_mess = "Неизвестная ошибка.";
        break;
    case ZERO_OBJ:
        err_mess = "Коэффициенты масштабирования не должны равняться нулю.";
        break;
    default:
        err_mess = NULL;
    }
    return err_mess;
}

// по коду ошибки выводит сообщение пользователю
void echo_err_message(const error_t &err_code)
{
    const char *err_mess = err_code_to_str(err_code);
    if (err_mess != NULL)
        QMessageBox::critical(NULL, "Ошибка!", err_mess);
}
