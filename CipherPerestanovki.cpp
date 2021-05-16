#include <conio.h>
#include <locale.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

    using namespace std;

    int main()
    {
        setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
        string buf = "папа мыл раму, мама пила";
        char massiv[24][24];
        int b, c;
        int count = 0;
        cout << "\nВведите кол-во столбцов: ";
        cin >> c;
        b = 4;

        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < c; j++)
            {
                massiv[i][j] = buf[count];
                count++;
            }
        }

        cout << "Шифр перестановки зашифрованный: " << endl;
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

        cout << "Шифр Цезаря дешифрованный: " << endl;
        for (int j = 0; j < c; j++)
        {
            for (int i = 0; i < b; i++)
            {
                cout << buf[amaunt];
            }
        }

        cout << buf;


    system("pause");
    return 0;
    }
