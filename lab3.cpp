/*
2. Создать класс-родитель «точка», его наследника – класс «отрезок», 
наследника выпуклого отрезка «четырехугольник» 
(нарисовать, стереть, закрасить, передвинуть, повернуть).
*/

// make run LAB=3

#include <iostream>
#include <cmath>
#include <windows.h>

// Класс "Точка"
class Point {
protected:
    double x, y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    void draw() const {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
        SetConsoleCursorPosition(hConsole, pos);
        std::cout << "*";
    }

    void erase() const {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
        SetConsoleCursorPosition(hConsole, pos);
        std::cout << " ";
    }

    void move(double dx, double dy) {
        x += dx;
        y += dy;
    }

    // Поворот точки относительно начала координат
    void rotate(double angle) {
        double newX = x * cos(angle) - y * sin(angle);
        double newY = x * sin(angle) + y * cos(angle);
        x = newX;
        y = newY;
    }
};

// Класс "Отрезок"
class Segment {
protected:
    Point start, end;

public:
    Segment(const Point& start, const Point& end) : start(start), end(end) {}

    void draw() const {
        start.draw();
        end.draw();
    }

    void erase() const {
        start.erase();
        end.erase();
    }

    void move(double dx, double dy) {
        start.move(dx, dy);
        end.move(dx, dy);
    }

    // Поворот отрезка относительно начала координат
    void rotate(double angle) {
        start.rotate(angle);
        end.rotate(angle);
    }
};

// Класс "Четырехугольник"
class Quadrilateral {
private:
    Point p1, p2, p3, p4;

public:
    Quadrilateral(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
        : p1(p1), p2(p2), p3(p3), p4(p4) {}

    void draw() const {
        p1.draw();
        p2.draw();
        p3.draw();
        p4.draw();
    }

    void erase() const {
        p1.erase();
        p2.erase();
        p3.erase();
        p4.erase();
    }

    void move(double dx, double dy) {
        p1.move(dx, dy);
        p2.move(dx, dy);
        p3.move(dx, dy);
        p4.move(dx, dy);
    }

    // Поворот четырехугольника относительно начала координат
    void rotate(double angle) {
        p1.rotate(angle);
        p2.rotate(angle);
        p3.rotate(angle);
        p4.rotate(angle);
    }
};

int main() {
    Point p1(10, 10);
    Point p2(20, 10);
    Point p3(20, 20);
    Point p4(10, 20);

    Segment s(p1, p2);
    Quadrilateral q(p1, p2, p3, p4);

    s.draw();
    q.draw();
    Sleep(2000);

    s.erase();
    q.erase();
    Sleep(2000);

    s.move(5, 5);
    q.move(5, 5);
    s.draw();
    q.draw();
    Sleep(2000);

    s.rotate(3.14159 / 2);
    q.rotate(3.14159 / 2);
    s.draw();
    q.draw();
    Sleep(2000);

    return 0;
}
