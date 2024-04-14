/*
Программирование с возвратом из функций нескольких значений

Написать и отладить программу для задачи из лабораторной работы 7 с выделением алгоритма обработки или формирования массива. 
Организовать вызов процедуры с параметрами-массивами для двух наборов исходных данных. (Для ускорения отладки массив можно задать  константой).


2. Даны массивы A [1..5], B [1..6]. Получить новые  массивы путем сдвига элементов в массивах   
на два разряда вправо, освободившиеся слева элементы обнулить. 
Сдвиг элементов в массиве оформить подпрограммой, из подпрограммы вернуть выпавшие справа разряды.
*/
#include <iostream>

using namespace std;


void transposeMatrix(double B[][5], double B_transpose[][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            // Меняем местами элементы в строках и столбцах
            B_transpose[j][i] = B[i][j];
        }
    }
}

// Функция для печати матрицы
void printMatrix(double matrix[][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void task1() {
    double B1[5][5] = {
        {1.1, 2.2, 3.3, 4.4, 5.5},
        {6.6, 7.7, 8.8, 9.9, 10.1},
        {11.1, 12.2, 13.3, 14.4, 15.5},
        {16.6, 17.7, 18.8, 19.9, 20.1},
        {21.1, 22.2, 23.3, 24.4, 25.5}
    };

    double B2[5][5] = {
        {0.1, 0.2, 0.3, 0.4, 0.5},
        {0.6, 0.7, 0.8, 0.9, 1.0},
        {1.1, 1.2, 1.3, 1.4, 1.5},
        {1.6, 1.7, 1.8, 1.9, 2.0},
        {2.1, 2.2, 2.3, 2.4, 2.5}
    };

    double B1_transpose[5][5];
    double B2_transpose[5][5];

    transposeMatrix(B1, B1_transpose);
    transposeMatrix(B2, B2_transpose);

    cout << "Задача 1 \n\n";
    cout << "Транспонированная матрица B1:" << endl;
    printMatrix(B1_transpose);

    cout << "Транспонированная матрица B2:" << endl;
    printMatrix(B2_transpose);
}




int* shiftArray(int arr[], int size, int shiftSize) {
    int* removedElements = new int[shiftSize]; // Массив для хранения выпавших элементов

    // Сохраняем выпавшие элементы
    for (int i = 0; i < shiftSize; ++i) {
        removedElements[i] = arr[size - shiftSize + i];
    }

    // Сдвигаем элементы массива
    for (int i = size - 1; i >= shiftSize; --i) {
        arr[i] = arr[i - shiftSize];
    }
    
    // Обнуляем освободившиеся элементы
    for (int i = 0; i < shiftSize; ++i) {
        arr[i] = 0;
    }

    return removedElements; // Возвращаем массив выпавших элементов
}


// Функция для печати массива
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void task2() {
    int A[5] = {1, 2, 3, 4, 5};
    int B[6] = {6, 7, 8, 9, 10, 11};
    int shiftSize = 2; // Размер сдвига

    cout << "Исходный массив A: ";
    printArray(A, 5);

    cout << "Исходный массив B: ";
    printArray(B, 6);

    int* removedA = shiftArray(A, 5, shiftSize);
    int* removedB = shiftArray(B, 6, shiftSize);

    cout << "Массив A после сдвига на " << shiftSize << " разряда(ов): ";
    printArray(A, 5);
    cout << "Выпавшие элементы из массива A: ";
    printArray(removedA, shiftSize);

    cout << "Массив B после сдвига на " << shiftSize << " разряда(ов): ";
    printArray(B, 6);
    cout << "Выпавшие элементы из массива B: ";
    printArray(removedB, shiftSize);
}


int main() {
    task1();
    task2();
    return 0;
}