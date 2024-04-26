/*
Вариант 2

Задание 1
Модифицировать программу 3_2 для вычис­ления  функций F1(x) и F2 (x) с применением опе­ратора  цикла с постусловием. Выполнить ее и сравнить результаты с полученными ранее.

Задание 2
Вычислить  y = x - x2/2 + x3/3 - ... + (-1)n-1xn/n + ...             с точностью eps=0.00001,  где |x|<1. Сравнить результат с вычисленным через стандартную функцию значением y = LN(1+x).

Задание 3
Модифицировать программу 4_1 с использованием оператора цикла с постусловием do … while и сравнить с полученными результатами в работе 4.
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

double F1(double x) {
    return 1 + pow(2, x + 5);
}

double F2(double x) {
    return pow(x - 1, 3);
}

void task1() {
    // Параметры
    double a = 1;
    double b = 2;
    int n = 18;

    double step = (b - a) / (n - 1);

    vector<double> x_values;
    vector<double> F1_values;
    vector<double> F2_values;

    double x = a;
    do {
        x_values.push_back(x);
        F1_values.push_back(F1(x));
        F2_values.push_back(F2(x));
        x += step;
    } while (x < b);

    cout << "Задание 1 \n\n";
    cout << " itetation | x      | F1(x)     | F2(x)" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < n; ++i) {
        cout << fixed << setprecision(2); //выводим 2 знака после запятой
        cout << setw(9) << i + 1 << " | ";
        cout << setw(6) << x_values[i] << " | ";
        cout << setw(9) << F1_values[i] << " | ";
        cout << setw(6) << F2_values[i] << endl;
    }
}



double lnXplus1(double x, double eps) {
    double y = 0.0;
    double term = x;
    int n = 1;

    do {
        y += term;
        term *= -x * (n - 1) / n;
        n++;
    } while (fabs(term) >= eps);

    return y;
}

int task2() {
    double x, eps = 0.00001;

    cout << "Задание 2 \n\n";
    cout << "Введите значение x (-1 < x < 1): ";
    cin >> x;

    if (fabs(x) >= 1) {
        cout << "Ошибка: |x| должно быть меньше 1" << endl;
        return 1;
    }

    double y_series = lnXplus1(x, eps);
    double y_ln = log(1 + x);

    cout << fixed << setprecision(5); //выводим 5 знака после запятой
    cout << "Значение y, вычисленное по ряду: " << y_series << endl;
    cout << "Значение y, вычисленное через LN(1 + x): " << y_ln << endl;

    return 0;
}

double Z(double a, double x, double y) {
    return pow(sqrt(a * x * y * y), 1.0 / 5) + 1.3 * sin(x - 1.9);
}

void task3() {
    double step = 0.5;
    double a = 1.9;
    cout << "Задание 3 \n\n";
    cout << " x     |  y     |  Z" << endl;
    cout << "-----------------------" << endl;
    double x = 2;
    double y;
    do {
        y = -1;
        do {
            double result = Z(a, x, y);
            cout << fixed << setprecision(2);
            cout << setw(6) << x << " | ";
            cout << setw(6) << y << " | ";
            cout << setw(6) << result << endl;
            y += step;
        } while (y <= 1);
        x += step;
    } while (x <= 5);
}

int main() {
    task1();
    task2();
    task3();
    return 0;
}