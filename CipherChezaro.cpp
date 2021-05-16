#include "stdafx.h"
#include <fstream> // работа с файлами
#include <iostream> //вывод в консоль
#include <cstdlib> // для использования функции exit()
#include <stdio.h> //необходимо для printf
#include <string.h> //необходимо для puts
    using namespace std;

    int main()
    {
        setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
        /*инициализируем переменные*/
            int i = 0; // для словаря
            int n = 0; // для текста
            int k; // для ключа
        char alf[81] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяabcedfghijklmnopqrstuvwxyz0123456789.,!?@#$%^&*"; //словарь
        string buf = "мама. мыла раму, папа пил!";
        printf("***Шифрование***");
        printf("\nВведите шаг для шифра Цезаря =  ");   
        cin >> k; //вводим ключ
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
        printf("\n***Дешифрование***\n");
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
