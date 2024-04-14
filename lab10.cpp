/*
Обработка символьных и строковых данных

2. Вывести на печать все строчные, а затем все прописные буквы русского и латинского алфавитов.


2. Дана строка, содержащая сорок латинских букв. Подсчитать все вхождение «abc» в строку и их удалить. 
Вывести на экран два варианта полученных строк, заполняя образовавшую «дыру» последующими буквами  
с добавлением в конце пробелов, и, оставляя на месте удаленных символов пробелы.
*/

#include <iostream>
#include <locale>
#include <ctype.h>
#include <wchar.h>


using namespace std;

void task1() {
    wcout << L"Задание 1 \n\n";
    wcout << L"Строчные буквы русского алфавита:" << endl;
    for (wchar_t ch = L'а'; ch <= L'я'; ++ch) {
        wcout << ch << L" ";
    }
    wcout << endl << endl;

    wcout << L"Прописные буквы русского алфавита:" << endl;
    for (wchar_t ch = L'А'; ch <= L'Я'; ++ch) {
        wcout << ch << L" ";
    }
    wcout << endl << endl;


    wcout << L"Строчные буквы латинского алфавита:" << endl;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        wcout << ch << " ";
    }
    wcout << endl << endl;

    wcout << L"Прописные буквы латинского алфавита:" << endl;
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        wcout << ch << " ";
    }
    wcout << endl << endl;
}

int main(){
    setlocale(LC_ALL, "ru_RU.utf8");
    task1();
    return 0;
}