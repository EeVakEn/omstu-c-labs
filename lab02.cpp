/*
Вариант 2

Задание 1
Вычислить значение функции

Задание 2
По цифре, введенной с клавиатуры, напечатать название этой цифры.
*/
// make run LAB=02
#include <iostream>
#include <cmath>

using namespace std;

void task1() {
    double x, a;

    cout << "Задание 1" << endl << endl;
    cout << "Введите значение x: ";
    cin >> x;
    cout << "Введите значение a: ";
    cin >> a;
    if (x<0 || x>4){
        cout << "Ошибка: x должен находиться в интервале [0, 4]" << endl;
    }else if (x > 2) {
        cout << "Значение функции: " <<  sqrt(x + a) << endl;
    } else if (x > 0.3) {
        cout << "Значение функции: " <<  x << endl;
    } else if (x <= 0.3) {
        cout << "Значение функции: " <<  cos(x - a) << endl;
    }

    cout << endl;
}

void task2() {
    int digit;

    cout << "Задание 2. По цифре, введенной с клавиатуры, напечатать название этой цифры." << endl << endl;
    cout << "Введите цифру (от 0 до 9): ";
    cin >> digit;

    switch (digit) {
        case 0:
            cout << "Ноль" << endl;
            break;
        case 1:
            cout << "Один" << endl;
            break;
        case 2:
            cout << "Два" << endl;
            break;
        case 3:
            cout << "Три" << endl;
            break;
        case 4:
            cout << "Четыре" << endl;
            break;
        case 5:
            cout << "Пять" << endl;
            break;
        case 6:
            cout << "Шесть" << endl;
            break;
        case 7:
            cout << "Семь" << endl;
            break;
        case 8:
            cout << "Восемь" << endl;
            break;
        case 9:
            cout << "Девять" << endl;
            break;
        default:
            cout << "Вы ввели не цифру от 0 до 9" << endl;
            break;
    }

}

int main() {
    task1();
    task2();
    return 0;
}
