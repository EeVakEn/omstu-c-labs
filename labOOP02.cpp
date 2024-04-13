/*
2. Определите класс t_end_d, которому при его создании передается текущее системное время и дата 
в виде параметров конструктора.Этот класс должен включать функцию - член, выводящую время и дату 
на экран.(Для нахождения и вывода на экран этих данных воспользуйтесь стандартной библиотечной функцией.)
*/

// make run LAB=2

#include <iostream>
#include <ctime>
#include <string>

class t_end_d {
private:
    int hour;
    int minute;
    int second;
    int day;
    int month;
    int year;

    // Приватная функция для форматированного числа с ведущим нулем
    std::string formatWithLeadingZero(int value) {
        if (value < 10) {
            return "0" + std::to_string(value);
        }
        return std::to_string(value);
    }

public:
    // Конструктор класса, принимающий текущее системное время и дату
    t_end_d() {
        time_t now = time(nullptr);
        tm* local_time = localtime(&now);

        hour = local_time->tm_hour;
        minute = local_time->tm_min;
        second = local_time->tm_sec;
        day = local_time->tm_mday;
        month = local_time->tm_mon + 1;  // tm_mon начинается с 0
        year = local_time->tm_year + 1900;  // tm_year содержит год с 1900
    }

    // Функция-член для вывода времени и даты на экран
    void print() {
        std::cout << "Текущее время и дата: "
            << std::endl
            << formatWithLeadingZero(hour) << ":"
            << formatWithLeadingZero(minute) << ":"
            << formatWithLeadingZero(second) << " "
            << formatWithLeadingZero(day) << "."
            << formatWithLeadingZero(month) << "."
            << year << std::endl;
    }

    // Деструктор класса
    ~t_end_d() {
        std::cout << "Объект класса t_end_d уничтожен" << std::endl;
    }
};

int main() {
    // Создание объекта класса t_end_d
    t_end_d obj;

    // Вывод времени и даты на экран
    obj.print();

    return 0;
}
