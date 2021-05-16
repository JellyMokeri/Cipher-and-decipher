#include "stdafx.h"
#include <fstream> // работа с файлами
#include <iostream> //вывод в консоль
#include <cstdlib> // для использования функции exit()
#include <stdio.h> //необходимо для printf
#include <string.h> //необходимо для puts
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

    using namespace std;

    int main()
    {
        setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

        /*инициализируем переменные*/

        int i = 0; // для массива словаря
        int n = 0; // для массива текста

        int k = 3; // шаг (ключ) для шифра Цезаря = 3
        int b = 4; // количество строк
        int c = 6; // количество стоблцов

        char alf[81] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяabcedfghijklmnopqrstuvwxyz0123456789.,!?@#$%^&*"; //словарь

        string buf = "папа мыл раму, мама пила"; // исходный текст
        printf("Исходный текст = ");
        cout << buf;

        printf("\n***Шифрование***");

        for (n = 0; n < 24; n++)
        {
            for (i = 0; i < 80; i++)
            {
                if (buf[n] == alf[i])
                {
                    if (i >= 81 - k + 1)
                        buf[n] = alf[i - 81 - k];
                    else
                        buf[n] = alf[i + k]; //сдвигаем вправо на показания шага ключа
                    break; //принудительно выходим из цикла
                }
            }
        }

        printf("\nШифр Цезаря зашифрованный = ");
        cout << buf; //выводим полученный шифр

        char massiv[24][24];

        int count = 0;

        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < c; j++)
            {
                massiv[i][j] = buf[count];
                count++;
            }
        }

        cout << "\nШифр перестановки зашифрованный = ";
        for (int j = 0; j < c; j++)
        {
            for (int i = 0; i < b; i++)
            {
                cout << massiv[i][j];
            }
        }

        printf("\n***Дешифрование***\n");

        int amaunt = 0;
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < c; j++)
            {
                buf[amaunt] = massiv[i][j];
                amaunt++;
            }
        }

        cout << "Шифр перестановки дешифрованный = ";
        for (int j = 0; j < c; j++)
        {
            for (int i = 0; i < b; i++)
            {
                cout << buf[amaunt];
            }
        }
        cout << buf;

        for (n = 0; n < 24; n++)
        {
            for (i = 0; i < 80; i++)
            {
                if (buf[n] == alf[i])
                {
                    if (i >= 81 - k + 1)
                        buf[n] = alf[i - 81 - k];
                    else
                        buf[n] = alf[i - k]; //сдвигаем влево на показания шага ключа
                    break; //принудительно выходим из цикла
                }
            }
        }
        printf("\nШифр Цезаря расшифрованный = ");
        cout << buf << endl; //выводим код


    system("pause");
    return 0;
    }
