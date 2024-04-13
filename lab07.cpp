/*

Дана матрица B[1..5,1..5] вещественных чисел. Найти для нее транспонированную матрицу.

Сформировать таблицу Пифагора.

Модифицировать программу 6_3 таким образом, чтобы значения X, F1 и F2 были представлены двумерным массивом, состоящим из трех строк.
*/
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void transposeMatrix(double B[][5], double B_transpose[][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            // Меняем местами элементы в строках и столбцах
            B_transpose[j][i] = B[i][j];
        }
    }
}

void task1(){
 double B[5][5] = {
        {1.1, 2.2, 3.3, 4.4, 5.5},
        {6.6, 7.7, 8.8, 9.9, 10.1},
        {11.1, 12.2, 13.3, 14.4, 15.5},
        {16.6, 17.7, 18.8, 19.9, 20.1},
        {21.1, 22.2, 23.3, 24.4, 25.5}
    };

    double B_transpose[5][5];

    transposeMatrix(B, B_transpose);

    cout << "Задача 1 \n\n";
    cout << "Транспонированная матрица B:" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << B_transpose[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void task2(){
    const int SIZE = 10;
    int pifagor[SIZE][SIZE];
    for (int i = 1; i <= SIZE; ++i) {
        for (int j = 1; j <= SIZE; ++j) {
            pifagor[i - 1][j - 1] = i * j;
        }
    }

    cout << "Задача 2 \n\n";
    cout << "Таблица Пифагора:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << pifagor[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

double F1(double x) {
    return 1 + pow(2, x + 5);
}

double F2(double x) {
    return pow(x - 1, 3);
}

void task3() {
    double a = 1;
    double b = 2;
    int n = 18;

    double step = (b - a) / (n - 1);

    double values[3][n];

    for (int i = 0; i < n; ++i) {
        double x = a + i * step;
        values[0][i] = x;         // Значения X
        values[1][i] = F1(x);     // Значения F1
        values[2][i] = F2(x);     // Значения F2
    }

    cout << "Задача 3 \n\n";
    cout << " itetation | x      | F1(x)     | F2(x)" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < n; ++i) {
        cout << fixed << setprecision(2);
        cout << setw(9) << i + 1 << " | ";
        cout << setw(6) << values[0][i] << " | ";
        cout << setw(9) << values[1][i] << " | ";
        cout << setw(6) << values[2][i] << endl;
    }
    cout << endl;
}

int main(){
    task1();
    task2();
    task3();
    return 0;
}