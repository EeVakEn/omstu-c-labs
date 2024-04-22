/*

Для задач 8_3 и 9_2 разработать программы, скрыв подпрограммы  в отдельном файле (модуле), использовать ссылки на переменные, объявленные в другом модуле.

*/

#include "libs/matrix_operations.h"
#include "libs/array_operations.h"
#include <iostream>

using namespace std;

int SIZE = 6; // Размер матрицы

void task8_3() {
    vector<vector<double>> matrix1 = {
        {1.2, 2.2, 3.3, 4.4, 5.5, 6.6},
        {7.7, 8.8, 9.9, 10.1, 11.1, 12.2},
        {13.3, 14.4, 15.5, 16.6, 17.7, 18.8},
        {19.9, 20.1, 21.1, 22.2, 23.3, 24.4},
        {25.5, 26.6, 27.7, 28.8, 29.9, 30.1},
        {31.1, 32.2, 33.3, 34.4, 35.5, 36.6}
    };

    double trace1 = trace(matrix1);

    vector<vector<double>> matrix2 = {
        {36.6, 35.5, 34.4, 33.3, 32.2, 31.1},
        {30.1, 29.9, 28.8, 27.7, 26.6, 25.5},
        {24.4, 23.3, 22.2, 21.1, 20.1, 19.9},
        {18.8, 17.7, 16.6, 15.5, 14.4, 13.3},
        {12.2, 11.1, 10.1, 9.9, 8.8, 7.7},
        {6.6, 5.5, 4.4, 3.3, 2.2, 1.1}
    };

    double trace2 = trace(matrix2);

    // Вывод следов матриц
    cout << "Задача 8_3\n\n";

    cout << "След матрицы 1: " << trace1 << endl;
    cout << "След матрицы 2: " << trace2 << endl;

    // Находим и печатаем матрицу с наименьшим следом
    cout << "Матрица с наименьшим следом:" << endl;
    if (trace1 < trace2) {
        printMatrix(matrix1);
    } else {
        printMatrix(matrix2);
    }
}

void task9_2() {
    int shiftSize = 2;
    int size = 5;
    int A[size] = {1, 2, 3, 4, 5};
    int B[size + 1] = {6, 7, 8, 9, 10, 11};

    cout << "\nЗадача 9_2: \n \n";
    cout << "Исходный массив A: ";
    printArray(A, size);

    cout << "Исходный массив B: ";
    printArray(B, size + 1);

    int* removedA = shiftArray(A, size, shiftSize);
    int* removedB = shiftArray(B, size + 1, shiftSize);

    cout << "Массив A после сдвига на " << shiftSize << " разряда(ов): ";
    printArray(A, size);
    cout << "Выпавшие элементы из массива A: ";
    printArray(removedA, shiftSize);

    cout << "Массив B после сдвига на " << shiftSize << " разряда(ов): ";
    printArray(B, size + 1);
    cout << "Выпавшие элементы из массива B: ";
    printArray(removedB, shiftSize);
}




int main() {
    task8_3();
    task9_2();
    return 0;
}