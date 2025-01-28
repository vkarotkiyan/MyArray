#include "classes.h"
#include <iostream>
#include <windows.h> // Закомментировать для Linux
using namespace  std;

int main(int argc, char* argv[])
{
    SetConsoleOutputCP( 65001 ); // Закомментировать для Linux
    //setlocale(LC_ALL, ""); // Закомментировать для Windows

    try
    {
        // double /////////////////////////////////////////////////////////////
        cout << "-------------------- Тип double --------------------" << endl;
        // Инициализация объекта array типа MyArray
        MyArray<double> array(10);
        double arr[10] = { 5.31,7.02,12.356,56.021,34.11,9.34,11.07,23.0,17.61,8.234 };
        for (int i = 0; i < 10; ++i)
            array[i] = arr[i];

        cout << "Массив array:\n";
        for (int i = 0; i < array.getLength(); ++i)
            cout << array[i] << ' ';
        cout << '\n';

        MyArray<double> b{ array };
        cout << "Массив b инициализируем массивом array: \n";
        for (int i = 0; i < b.getLength(); ++i)
            cout << b[i] << ' ';
        cout << '\n';

        array.resize(12); // Изменение длины
        cout << "Увеличение длины массива array на 2: \n";
        for (int i = 0; i < array.getLength(); ++i)
            cout << array[i] << ' ';
        cout << '\n';

        array.resize(8); // Изменение длины
        cout << "Уменьшение длины массива array на 4: \n";
        for (int i = 0; i < array.getLength(); ++i)
            cout << array[i] << ' ';
        cout << '\n';

        try
        {
            array.insertBefore(222.77, 5); // Вставка элемента
        }
        catch (MyException& ex)
        {
            cout << ex.getErrorMessage() << endl;
        }
        try
        {
            array.remove(3); // Удаление элемента
        }
        catch (MyException& ex)
        {
            cout << ex.what() << endl;
        }
        array.insertAtEnd(333.11); // Вставка в конец
        array.insertAtBeginning(444.88); // Вставка в начало

        cout << "Массив array после удаления одного и добавления трех элементов: \n";
        for (int i = 0; i < array.getLength(); ++i)
            cout << array[i] << ' ';
        cout << '\n';

        try
        {
            cout << "Элемент с индексом 5: " << array[5] << endl; // Доступ к элементу по индексу
        }
        catch (Bad_Range& ex)
        {
            cout << ex.what() << endl;
        }

        b = array; // Копирование
        cout << "Массив b поcле копирования (b = array): \n";
        for (int i = 0; i < b.getLength(); ++i)
            cout << b[i] << ' ';
        cout << '\n';

        b = b;
        array = array;

        array.findValue(9.34); // Поиск элемента
        array.findValue(107);


        // string /////////////////////////////////////////////////////////////
        cout << endl << "-------------------- Тип string --------------------" << endl;
        // Инициализация объекта array типа MyArray
        MyArray<string> array1(10);
        string arr1[10] = { "Ноль","Один","Два","Три","Четыре","Пять","Шесть","Семь","Восемь","Девять" };
        for (int i = 0; i < 10; ++i)
            array1[i] = arr1[i];

        cout << "Массив array1:\n";
        for (int i = 0; i < array1.getLength(); ++i)
            cout << array1[i] << ' ';
        cout << '\n';

        MyArray<string> b1{ array1 };
        cout << "Массив b1 инициализируем массивом array1: \n";
        for (int i = 0; i < b1.getLength(); ++i)
            cout << b1[i] << ' ';
        cout << '\n';

        array1.resize(12); // Изменение длины
        cout << "Увеличение длины массива array1 на 2: \n";
        for (int i = 0; i < array1.getLength(); ++i)
            cout << array1[i] << ' ';
        cout << '\n';

        array1.resize(8); // Изменение длины
        cout << "Уменьшение длины массива array1 на 4: \n";
        for (int i = 0; i < array1.getLength(); ++i)
            cout << array1[i] << ' ';
        cout << '\n';

        try
        {
            array1.insertBefore("Вставка", 5); // Вставка элемента
        }
        catch (MyException& ex)
        {
            cout << ex.getErrorMessage() << endl;
        }
        try
        {
            array1.remove(3); // Удаление элемента
        }
        catch (MyException& ex)
        {
            cout << ex.what() << endl;
        }
        array1.insertAtEnd("Конец"); // Вставка в конец
        array1.insertAtBeginning("Начало"); // Вставка в начало

        cout << "Массив array1 после удаления одного и добавления трех элементов: \n";
        for (int i = 0; i < array1.getLength(); ++i)
            cout << array1[i] << ' ';
        cout << '\n';

        try
        {
            cout << "Элемент с индексом 5: " << array1[5] << endl; // Доступ к элементу по индексу
        }
        catch (Bad_Range& ex)
        {
            cout << ex.what() << endl;
        }

        b1 = array1; // Копирование
        cout << "Массив b1 поcле копирования (b1 = array1): \n";
        for (int i = 0; i < b.getLength(); ++i)
            cout << b1[i] << ' ';
        cout << '\n';

        b1 = b1;
        array1 = array1;

        array1.findValue("Семь"); // Поиск элемента
        array1.findValue("Двенадцать");

    }
    catch (Bad_Range& ex)
    {
        cout << ex.what() << endl;
    }
    catch (MyException& ex)
    {
        cout << ex.getErrorMessage() << ex.what() << endl;
    }

    return 0;
}
