#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

/*
Вариант 2


Для заданных с клавиатуры значений переменных x и n вычислить
Z = 2 * 4 * 6 * 8 * ... * 20.

Вычислить значения двух функций в n равномерно распределенных в диапазоне а≤x≤b точках. Результаты оформить в виде таблицы.
a = 1
b = 2
n = 18
F1(x) = 1+2^(x+5)
F2(x) = (x-1)^3
*/
// make run LAB=03
void task1(){
    int n;

    cout << "Задание 1. Для заданных с клавиатуры значений переменных x и n вычислить" << endl << "Z = 2 * 4 * 6 * 8 * ... * 20. "<< endl << endl;
    cout << "Введите значение n: ";
    cin >> n;

    int Z = 1;
    for (int i = 1; i <= n; ++i) {
        Z *= (2 * i);
    }

    cout << "Значение Z: " << Z << endl << endl;
}

double F1(double x) {
    return 1 + pow(2, x + 5);
}

double F2(double x) {
    return pow(x - 1, 3);
}

void task2(){
    // Параметры
    double a = 1;
    double b = 2;
    int n = 18;

    double step = (b - a) / (n - 1);

    vector<double> x_values;
    vector<double> F1_values;
    vector<double> F2_values;

    for (int i = 0; i < n; ++i) {
        double x = a + i * step;
        x_values.push_back(x);
        F1_values.push_back(F1(x));
        F2_values.push_back(F2(x));
    }
    cout << "Вычислить значения двух функций в n равномерно распределенных в диапазоне а≤x≤b точках. Результаты оформить в виде таблицы. \n a = 1 \n b = 2 \n n = 18 \n F1(x) = 1+2^(x+5) \n F2(x) = (x-1)^3 \n";
    cout << "itetation | x      | F1(x)     | F2(x)" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < n; ++i) {
        cout << fixed << setprecision(2);
        cout << setw(9) << i + 1 << " | ";
        cout << setw(6) << x_values[i] << " | ";
        cout << setw(9) << F1_values[i] << " | ";
        cout << setw(6) << F2_values[i] << endl;
    }
}

int main(){
    task1();
    task2();
    return 0;
}