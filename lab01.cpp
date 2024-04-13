/*
Вариант 2

Задание 1
y = (sin(x)/(sqrt(1 + a^2 * (sin(x))^2))) - c * ln(a * x)

Задание 2
Определить площадь трапеции с основаниями а, b, высотой h и объем усеченного конуса, если считать а, b - площадями оснований.


*/
// make run LAB=01
#include <iostream>
#include <cmath>

using namespace std;


void task1(){
    int x1 = 1;
    int x2 = 2;
    double a = 0.7;
    double c = 2.1;

    double y1 = sin(x1) / sqrt(1 + pow(a * sin(x1), 2)) - c * log(a * x1);
    double y2 = sin(x2) / sqrt(1 + pow(a * sin(x2), 2)) - c * log(a * x2);

    cout << "Задание 1" << endl << endl;
    cout << "y1 = " << y1 << endl;
    cout << "y2 = " << y2 << endl << endl;
}



double trapezoidArea(double a, double b, double h) {
    return (a + b) / 2.0 * h;
}

double truncatedConeVolume(double a, double b, double h) {
    return (1.0 / 3.0) * M_PI * (a + b + sqrt(a * b)) * h;
}

int task2() {
    double a, b, h; 

    cout << "Задание 2" << endl << endl;
    cout << "Площадь трапеции" << endl;
    cout << "Введите основание a: ";
    cin >> a;
    cout << "Введите основание b: ";
    cin >> b;
    cout << "Введите высоту трапеции h: ";
    cin >> h;

    // Вычисление площади трапеции
    double trapezoidAreaResult = trapezoidArea(a, b, h);
    cout << "Площадь трапеции: " << trapezoidAreaResult << endl;

    cout << "Объем усеченного конуса" << endl;
    cout << "Введите площадь основания a: ";
    cin >> a;
    cout << "Введите площадь основания b: ";
    cin >> b;
    cout << "Введите высоту h: ";
    cin >> h;

    // Вычисление объема усеченного конуса
    double truncatedConeVolumeResult = truncatedConeVolume(a, b, h);
    cout << "Объем усеченного конуса: " << truncatedConeVolumeResult << endl;

    return 0;
}


int main() {
    task1();
    task2();
    return 0;
}