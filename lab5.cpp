/*
2. Даны два массива (классы множества чисел). Написать функцию, сор­тирующую эти массивы как единый методом перестановок.
*/

// make run LAB=4
#include <iostream>
#include <vector>

class NumberSet {
private:
    std::vector<int> numbers;

public:
    NumberSet() {}

    // Добавление числа в множество
    void addNumber(int num) {
        numbers.push_back(num);
    }

    // Вывод множества
    void display() const {
        for (int num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    // Сортировка множества методом перестановок
    void bubbleSort() {
        int n = numbers.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (numbers[j] > numbers[j + 1]) {
                    std::swap(numbers[j], numbers[j + 1]);
                }
            }
        }
    }

    // Дружественная функция для объединения двух множеств в одно
    friend NumberSet mergeSets(const NumberSet& set1, const NumberSet& set2);
};

// Функция для объединения двух множеств в одно
NumberSet mergeSets(const NumberSet& set1, const NumberSet& set2) {
    NumberSet mergedSet;
    mergedSet.numbers = set1.numbers;
    mergedSet.numbers.insert(mergedSet.numbers.end(), set2.numbers.begin(), set2.numbers.end());
    return mergedSet;
}

int main() {
    NumberSet set1, set2;

    // Добавление чисел в первое множество
    set1.addNumber(5);
    set1.addNumber(2);
    set1.addNumber(9);

    // Добавление чисел во второе множество
    set2.addNumber(7);
    set2.addNumber(1);
    set2.addNumber(4);

    std::cout << "Исходные множества:" << std::endl;
    std::cout << "Множество 1: ";
    set1.display();
    std::cout << "Множество 2: ";
    set2.display();

    // Объединение множеств
    NumberSet mergedSet = mergeSets(set1, set2);

    // Сортировка объединенного множества методом перестановок
    mergedSet.bubbleSort();

    std::cout << "Отсортированное объединенное множество:" << std::endl;
    mergedSet.display();

    return 0;
}