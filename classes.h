#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <algorithm>

template<typename T>class MyArray
{
public:
    MyArray() = default;
    MyArray(int); // Создание массива
    ~MyArray();
    void erase(); // Удаление массива
    T& operator[](int); // Доступ к элементу
    int getLength() const; // Получение длины массива
    void reallocate(int); // Уничтожение массива и выделение памяти под новый размер
    void resize(int); // Изменение размера массива
    MyArray(const MyArray&); // Копирование
    MyArray& operator=(const MyArray&); // Перегрузка =
    void insertBefore(T, int); // Вставка элемента перед
    void remove(int); // Удаление элемента
    void insertAtBeginning(T); // Вставка элемента в начало
    void insertAtEnd(T); // Вставка элемента в конец
    void findValue(T); // Поиск элемента
private:
    int _length;
    T* _data;
};


class MyException : public std::exception
{
public:
    MyException(std::string);
    std::string getErrorMessage() const;
    virtual const char* what() const noexcept override;
private:
    std::string _message;
};

class Bad_Range : public std::exception
{
public:
    virtual const char* what() const noexcept override;
};

class Bad_Length : public std::exception
{
public:
    virtual const char* what() const noexcept override;
};



template<typename T> MyArray<T>::MyArray(int length) : _length(length)
{
    if (_length < 0)
    {
        throw MyException("Длина массива не может быть меньше 0! (1)\n");
    }
    _data = new T[length];
    //std::cout << "Массив создан!" << std::endl;
}

template<typename T> MyArray<T>::~MyArray()
{
    delete[] _data;
    //std::cout << "Массив уничтожен!" << std::endl;
}

template<typename T> void MyArray<T>::erase()
{
    delete[] _data;
    _data = nullptr; // указывает в никуда
    _length = 0;
}

template<typename T> T& MyArray<T>::operator[](int index)
{
    if (index < 0 || index >= _length)
    {
        throw Bad_Range(); // Для соответствия заданию
    }
    return _data[index];
}

template<typename T> int MyArray<T>::getLength() const
{
    return _length;
}

template<typename T> void MyArray<T>::reallocate(int newLength)
{
    erase();
    if (newLength <= 0)
        return;
    _data = new T[newLength];
    _length = newLength;
}

template<typename T> void MyArray<T>::resize(int newLength)
{
    if (newLength < 0)
    {
        throw MyException("Длина массива не может быть меньше 0! (2)\n");
    }
    if (newLength == _length)
        return;
    if (newLength <= 0)
    {
        erase();
        return;
    }
    T* data = new T[newLength];
    if (_length > 0)
    {
        int elementsToCopy{ (newLength > _length) ? _length : newLength };
        std::copy_n(_data, elementsToCopy, data);
    }
    for (int i = _length; i < newLength; i++)
        data[i] = data[_length - 1];
    delete[] _data;
    _data = data;
    _length = newLength;
}

template<typename T> MyArray<T>::MyArray(const MyArray& a) : MyArray(a.getLength())
{
    std::copy_n(a._data, _length, _data);
}

template<typename T> MyArray<T>& MyArray<T>::operator=(const MyArray& a)
{
    if (&a == this) // Самопроверка
        return *this;
    reallocate(a.getLength());
    std::copy_n(a._data, _length, _data);
    return *this;
}

template<typename T> void MyArray<T>::insertBefore(T value, int index)
{
    if (index < 0 || index > _length)
    {
        throw MyException("Неверный индекс. (2)\n");
    }
    T* data = new T[_length + 1];
    std::copy_n(_data, index, data);
    data[index] = value;
    std::copy_n(_data + index, _length - index, data + index + 1);
    delete[] _data;
    _data = data;
    ++_length;
}

template<typename T> void MyArray<T>::remove(int index)
{
    if (index < 0 || index >= _length)
    {
        throw MyException("Неверный индекс. (3)\n");
    }
    if (_length == 1)
    {
        erase();
        return;
    }
    T* data = new T[_length - 1];
    std::copy_n(_data, index, data);
    std::copy_n(_data + index + 1, _length - index - 1, data + index);
    delete[] _data;
    _data = data;
    --_length;
}

template<typename T> void MyArray<T>::insertAtBeginning(T value)
{
    insertBefore(value, 0);
}

template<typename T> void MyArray<T>::insertAtEnd(T value)
{
    insertBefore(value, _length);
}

template<typename T> void MyArray<T>::findValue(T value)
{
    for (int i = 0; i < _length; i++)
    {
        if (_data[i] == value)
        {
            std::cout << "Индекс элемента " << value << ": " << i << std::endl;
            return;
        }
    }
    std::cout << "Элемент " << value << " не найден." << std::endl;
}



