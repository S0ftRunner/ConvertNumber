#include <iostream>
#include <cmath>
using namespace std;
//----------------------
int ConvertBinaryToDec(int number);
int ConvertDecToBinary(int number);
//----------------------
int main()
{
    setlocale(LC_ALL, "ru"); //
    cout << "Салам алекум!\n";
    int number; // вводимое число
    char switcher; // переключатель

    do // простое меню
    {
        cout << "Выберите, из какой в какую систему вы хотите перевести число:\n";
        cout << "1. Из двоичной в десятичную\n";
        cout << "2. Из десятичной в двоичную\n";
        cout << "Для выхода нажмите 'q'\n\n";
        cin >> switcher;
        switch(switcher)
        {
            case '1' :
                cout << "Введите число: ";
                cin >> number;
                cout << number << " (binary) = " << ConvertBinaryToDec(number) << " (dec) \n\n";
                break;
            case '2' :
                cout << "Введите число: ";
                cin >> number;
                cout << number << " (dec) = " << ConvertDecToBinary(number) << " (binary) \n\n";
                break;
        }

    }while (switcher != 'q'); // если пользователь ввел q, то программа завершается

    return 0;
}
//----------------------
int ConvertBinaryToDec(int number) // перевод из двоичного в десятичный
{
    int DecimalNumber = 0, i = 0, remainder;

    while (number != 0)
    {
        remainder = number % 10; // берем число справа
        number /= 10; // "укорачиваем" число справа
        DecimalNumber += remainder * pow(2, i); // умножаем первое число справа на двойку в степени шага
        ++i; // счетчик повышается
    }

    return DecimalNumber;
}
//----------------------
int ConvertDecToBinary(int number) // перевод из десятичного в двоичный
{
    int BinaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (number != 0)
    {
        remainder = number % 2; // берем остаток от деления на двойку
        cout << "Шаг: " << step++ << ' ' << number << "/2, Остаток = " << remainder << ", Quotient = " << number / 2 << "\n";
        number /= 2; // делим наше число пополам
        BinaryNumber += remainder * i; // остаток умножаем на i
        i *= 10;
    }

    return BinaryNumber;
}
