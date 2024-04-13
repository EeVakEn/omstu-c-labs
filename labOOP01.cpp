// 2. Создайте класс по имени Rational для выполнения арифметических действий с дробями. Напишите программу драйвера для  вашего класса.
// Используйте целые переменные для представления закрытых данных класса – числителя и знаменателя. Создайте функцию-конструктор, кото­рая позволяет объекту этого класса принимать начальные значения при его объявлении. Конструктор должен содержать значения по умолчанию на случай от­сутствия заданных начальных значений и должен хранить дроби в сокра­щенном виде (т.е. дробь 2/4 должна храниться в объекте как 1 в числи­теле и 2 в знаменателе). Создайте открытые функции-элементы для каждо­го из следующих случаев:
// a) сложения двух чисел Rational (результат должен храниться в сокращенной форме);
// б) вычитания двух чисел Rational;
// в) перемножения двух чисел Rational;
// г) деления двух чисел Rational;
// д)   печати чисел Rational в форме a / b, где а – числитель, b – знаменатель.
// е)   печати чисел Rational в форме с плавающей точкой.

// make run LAB=1

#include <iostream>
#include <algorithm>

class Rational {
private:
    int numerator;
    int denominator;

    // Функция для нахождения наибольшего общего делителя
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Функция для сокращения дроби
    void reduce() {
        if (denominator == 0) {
            return;
        }
        int common = gcd(std::abs(numerator), std::abs(denominator));
        numerator /= common;
        denominator /= common;
    }

public:
    // Конструктор по умолчанию
    Rational(int num = 0, int den = 1) : numerator(num), denominator(den) {
        reduce();
    }

    // Функция сложения
    Rational add(const Rational& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    // Функция вычитания
    Rational subtract(const Rational& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    // Функция умножения
    Rational multiply(const Rational& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    // Функция деления
    Rational divide(const Rational& other) const {
        if (other.numerator == 0) {
            std::cerr << "Error: division by zero\n";
            return Rational();
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Rational(num, den);
    }

    // Функция печати в форме a / b
    void printFraction() const {
        std::cout << numerator << " / " << denominator;
    }

    // Функция печати в форме с плавающей точкой
    void printFloatingPoint() const {
        double result = static_cast<double>(numerator) / denominator;
        std::cout << result;
    }
};

int main() {
    Rational a(1, 3); // 1/3
    Rational b(4, 6); // 1/3

    std::cout << "A = ";
    a.printFraction();
    std::cout << " = ";
    a.printFloatingPoint();
    std::cout << std::endl;
    
    std::cout << "B = ";
    b.printFraction();
    std::cout << " = ";
    b.printFloatingPoint();
    std::cout << std::endl;


    Rational sum = a.add(b);
    Rational difference = a.subtract(b);
    Rational product = a.multiply(b);
    Rational quotient = a.divide(b);

    std::cout << "A + B = ";
    sum.printFraction();
    std::cout << " = ";
    sum.printFloatingPoint();
    std::cout << std::endl;

    std::cout << "A - B = ";
    difference.printFraction();
    std::cout << " = ";
    difference.printFloatingPoint();
    std::cout << std::endl;

    std::cout << "A * B = ";
    product.printFraction();
    std::cout << " = ";
    product.printFloatingPoint();
    std::cout << std::endl;

    std::cout << "A / B = ";
    quotient.printFraction();
    std::cout << " = ";
    quotient.printFloatingPoint();
    std::cout << std::endl;

    return 0;
}
