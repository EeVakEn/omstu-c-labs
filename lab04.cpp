/*
Программирование циклических алгоритмов с предусловием

Задание 1

Начертите структурную схему алгоритма, напишите и отладьте про­грамму для табуляции следующих функций
Z = (a * x * y ^ 2) ^ (1/5) + 1,3 sin(x-a)    при  2 <= x <= 5  с шагом 0.5,
a = 1.9,                                             -1 <= y <= 1  с шагом 0.5.

Задание 2

Модифицировать (изменить) программу 3_2 для вычисления функций F1(x) и F2(x) 
с применением вместо счетного цикла оператора цикла с предусловием. 
Выполнить ее и сравнить результаты с полученными в пре­дыдущей работе.

*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;


double Z(double a, double x, double y) {
    return pow(sqrt(a * x * y * y), 1 / 5) + 1.3 * sin(x - 1.9);
}

void task1(){
    double step = 0.5;
    double a = 1.9;
    cout << "Задание 1 \n\n";
    cout << " x     |  y     |  Z" << endl;
    cout << "-----------------------" << endl;
    double x = 2;
    while (x <= 5) {
        double y = -1;
        while (y <= 1) {
            double result = Z(a, x, y);
            cout << fixed << setprecision(2);
            cout << setw(6) << x << " | ";
            cout << setw(6) << y << " | ";
            cout << setw(6) << result << endl;
            y += step;
        }
        x += step;
    }

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

    // Цикл с предусловием для вычисления значений x
    double x = a;
    while (x <= b) {
        x_values.push_back(x);
        F1_values.push_back(F1(x));
        F2_values.push_back(F2(x));
        x += step;
    }

    // Вывод результатов в виде таблицы
    cout << "Задание 2. \n вычислить значения двух функций в n равномерно распределенных в диапазоне а≤x≤b точках. Результаты оформить в виде таблицы. \n a = 1 \n b = 2 \n n = 18 \n F1(x) = 1+2^(x+5) \n F2(x) = (x-1)^3 \n";
    cout << "iteration | x      | F1(x)     | F2(x)" << endl;
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