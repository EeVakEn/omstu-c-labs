/*

Файлы

Выполнить  задачу из лабораторной работы 9, считывая исходные данные из одного файла и записывая полученные результаты в другой текстовый файл. 
Файл с исходными данными должен быть подготовлен предварительно.


В текстовом файле f1 записана последовательность чисел. Сформировать текстовый файл f 2, содержащий все числа в обратном порядке.


*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int* shiftArray(int arr[], int size, int shiftSize) {
    int* removedElements = new int[shiftSize]; // Массив для хранения выпавших элементов

    // Сохраняем выпавшие элементы
    for (int i = 0; i < shiftSize; ++i) {
        removedElements[i] = arr[size - shiftSize + i];
    }

    // Сдвигаем элементы массива
    for (int i = size - 1; i >= shiftSize; --i) {
        arr[i] = arr[i - shiftSize];
    }
    
    // Обнуляем освободившиеся элементы
    for (int i = 0; i < shiftSize; ++i) {
        arr[i] = 0;
    }

    return removedElements; // Возвращаем массив выпавших элементов
}

// Функция для печати массива
void printArray(ofstream& outFile, int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        outFile << arr[i] << " ";
    }
    outFile << endl;
}

void task1() {
    int A[5] = {1, 2, 3, 4, 5};
    int B[6] = {6, 7, 8, 9, 10, 11};
    int shiftSize = 2;

    ofstream outFile("files/lab11_task1.txt");

    cout << "Задача 1\n\n";
    cout << "Исходный массив A: ";
    printArray(outFile, A, 5);

    cout << "Исходный массив B: ";
    printArray(outFile, B, 6);

    int* removedA = shiftArray(A, 5, shiftSize);
    int* removedB = shiftArray(B, 6, shiftSize);

    cout << "Массив A после сдвига на " << shiftSize << " разряда(ов): ";
    printArray(outFile, A, 5);
    outFile << "Выпавшие элементы из массива A: ";
    printArray(outFile, removedA, shiftSize);

    cout << "Массив B после сдвига на " << shiftSize << " разряда(ов): ";
    printArray(outFile, B, 6);
    outFile << "Выпавшие элементы из массива B: ";
    printArray(outFile, removedB, shiftSize);
    cout << endl;
    outFile.close(); 
}





int task2() {
    string inputFile = "files/lab11_task2_f1.txt";
    string outputFile = "files/lab11_task2_f2.txt";

    cout << "Задача 2\n\n";
    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Невозможно открыть файл: " << inputFile << endl;
        return 1;
    }

    vector<int> numbers;
    int num;
    while (inFile >> num) {
        numbers.push_back(num);
    }
    inFile.close();

    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Невозможно открыть файл: " << outputFile << endl;
        return 1;
    }

    for (int i = numbers.size() - 1; i >= 0; --i) {
        outFile << numbers[i] << " ";
    }
    outFile.close();

    cout << "Числа из " << inputFile  << " записаны в " << outputFile << " в обратном порядке." << endl;

    return 0;
}


int main(){
    task1();
    task2();
    return 0;
}