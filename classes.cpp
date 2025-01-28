#include "classes.h"
#include <iostream>
#include <exception>
using namespace  std;

MyException::MyException(string message) : _message(message)
{
}
string MyException::getErrorMessage() const
{
    return _message;
}
const char* MyException::what() const noexcept
{
    return "Мое сообщение об ошибке!\n";
}

const char* Bad_Range::what() const noexcept
{
    return "Выход за пределы диапазона!\n";
}

const char* Bad_Length::what() const noexcept
{
    return "Неверная длина массива.\n";
}
