/*

Программирование алгоритмов обработки одномерных массивов


Задание 1

2. Дан массив из N чисел (10<N<15). Найти максимальное значение.


Задание 2

Модифицировать программу 3_2 для функций F1(x) и F2 (x) таким образом, чтобы результаты были сформированы в виде трех одномерных массивов. 
Выполнить ее и сравнить результаты с полученными в лабора­торных работах 3 и 4.
*/

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int findMax(int arr[], int size) {
    int maxVal = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    return maxVal;
}

void task1() {
    const int N = 12; 
    int arr[N] = {10, 5, 7, 15, 20, 3, 18, 12, 8, 9, 11, 14};

    int maxVal = findMax(arr, N); 

    cout << "Задача 1 \n\n";
    cout << "Максимальное значение в массиве: " << maxVal << endl << endl;
}

double F1(double x) {
    return 1 + pow(2, x + 5);
}

double F2(double x) {
    return pow(x - 1, 3);
}

void task2() {
    double a = 1;
    double b = 2;
    int n = 18;

    double step = (b - a) / (n - 1);

    double x_values[n];
    double F1_values[n];
    double F2_values[n];

    for (int i = 0; i < n; ++i) {
        double x = a + i * step;
        x_values[i] = x;
        F1_values[i] = F1(x);
        F2_values[i] = F2(x);
    }

    cout << "Задача 2 \n\n";
    cout << " itetation | x      | F1(x)     | F2(x)" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < n; ++i) {
        cout << fixed << setprecision(2);
        cout << setw(9) << i + 1 << " | ";
        cout << setw(6) << x_values[i] << " | ";
        cout << setw(9) << F1_values[i] << " | ";
        cout << setw(6) << F2_values[i] << endl;
    }
}


int main() {
    task1();
    task2();
    return 0;
}