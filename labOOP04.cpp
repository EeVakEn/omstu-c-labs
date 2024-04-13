/*
2. Для строки символов реализовать  операции:
а) проверка в строке наличия заданного символа (операция +);
б) перевод указанного символа строки в код ASCII(операция %).
*/

// make run LAB=4
#include <iostream>
#include <string>

class StringOperator {
private:
    std::string str;
    char sym;

public:
    StringOperator(const std::string& s, char ch) : str(s), sym(ch) {}

    // Перегрузка оператора ! для проверки наличия заданного символа
    bool operator!() {
        for (char c : str) {
            if (c == sym) {
                return true;
            }
        }
        return false;
    }

    // Перегрузка оператора % для перевода символа строки в код ASCII
    int operator%(char ch) {
        return static_cast<int>(ch);
    }
};

int main() {
    std::string inputStr;
    char ch;
    std::cout << "Введите строку: ";
    std::cin >> inputStr;

    std::cout << "Введите символ для проверки наличия в строке: ";
    std::cin >> ch;


    StringOperator strOp(inputStr, ch);
    // Проверка наличия символа в строке с использованием оператора !
    if (!strOp) {
        std::cout << "Символ присутствует в строке.\n";
    } else {
        std::cout << "Символ отсутствует в строке.\n";
    }



    std::cout << "Введите символ для перевода в ASCII: ";
    std::cin >> ch;
    // Перевод указанного символа строки в код ASCII с использованием оператора %
    int asciiCode = strOp % ch;
    std::cout << "Код ASCII символа '" << ch << "': " << asciiCode << std::endl;

    return 0;
}