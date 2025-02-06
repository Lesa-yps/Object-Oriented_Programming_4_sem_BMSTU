#ifndef ERR_MESSAGE_H
#define ERR_MESSAGE_H

#include <QMessageBox>
#include "const_struct.h"

// по коду ошибки выводит сообщение пользователю
void echo_err_message(const error_t &err_code);

#endif // ERR_MESSAGE_H
