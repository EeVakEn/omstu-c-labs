/*
Структуры


Дан список студентов и оценка каждого на экзамене (оценки на N экзаменах). 
Подсчитать количество удовлетворительных оценок, хороших, отличных и средний балл в группе. 
Напечатать фамилии неуспевающих студентов.

*/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

struct Student {
    string surname;
    vector<int> grades; // Оценки студента
};

void printUnsuccessfulStudents(const vector<Student>& students) {
    cout << "Неуспевающие студенты:" << endl;
    for (const auto& student : students) {
        int totalGrade = 0;
        for (int grade : student.grades) {
            totalGrade += grade;
        }
        double averageGrade = static_cast<double>(totalGrade) / student.grades.size();

        if (averageGrade < 3.0) { 
            cout << student.surname << endl;
        }
    }
    cout << endl;
}

void printStatistics(const vector<Student>& students) {
    int satisfactory = 0, good = 0, excellent = 0;
    double totalGrade = 0.0;
    int gradesCount = 0;

    for (const auto& student : students) {
        for (int grade : student.grades) {
            totalGrade += grade;
            gradesCount++;
        }
    }

    double averageGrade = totalGrade / gradesCount;

    for (const auto& student : students) {
        for (int grade : student.grades) {
            if (grade == 4) {
                good++;
            } else if (grade == 5) {
                excellent++;
            } else if (grade == 3) {
                satisfactory++;
            }
        }
    }
    cout << "Количество удовлетворительных оценок: " << satisfactory << endl;
    cout << "Количество хороших оценок: " << good << endl;
    cout << "Количество отличных оценок: " << excellent << endl;
    cout << "Средний балл в группе: " << averageGrade << endl;
}

void task1() {
    vector<Student> students = {
        {"Иванов", {4, 5, 2}},
        {"Петров", {2, 3, 4}},
        {"Сидоров", {5, 5, 5}},
        {"Смирнов", {3, 2, 3}},
        {"Кузнецов", {4, 2, 2}}
    };

    cout << "Задача 1 \n\n";
    printStatistics(students);
    printUnsuccessfulStudents(students);
}




void readStudents(const string& filename, vector<Student>& students) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла." << endl;
        return;
    }

    int n;
    file >> n;
    students.resize(n);

    for (int i = 0; i < n; ++i) {
        file >> students[i].surname;
        int grade;
        while (file >> grade) {
            students[i].grades.push_back(grade);
            char nextChar = file.peek();
            if (nextChar == '\n' || nextChar == EOF) {
                break; 
            }
        }
    }

    file.close();
}

void printStatistics(const vector<Student>& students, ofstream& file) {
    int satisfactory = 0, good = 0, excellent = 0;
    double totalGrade = 0.0;
    int gradesCount = 0;

    for (const auto& student : students) {
        for (int grade : student.grades) {
            totalGrade += grade;
            gradesCount++;
        }
    }

    double averageGrade = totalGrade / gradesCount;

    for (const auto& student : students) {
        for (int grade : student.grades) {
            if (grade == 4) {
                good++;
            } else if (grade == 5) {
                excellent++;
            } else if (grade == 3) {
                satisfactory++;
            }
        }
    }
    file << "Количество удовлетворительных оценок: " << satisfactory << endl;
    file << "Количество хороших оценок: " << good << endl;
    file << "Количество отличных оценок: " << excellent << endl;
    file << "Средний балл в группе: " << averageGrade << endl;
    file << endl;
}

void printUnsuccessfulStudents(const vector<Student>& students, ofstream& file) {
    file << "Неуспевающие студенты:" << endl;
    for (const auto& student : students) {
        int totalGrade = 0;
        for (int grade : student.grades) {
            totalGrade += grade;
        }
        double averageGrade = static_cast<double>(totalGrade) / student.grades.size();

        if (averageGrade < 3.0) { 
            file << student.surname << endl;
        }
    }
    file << endl;
}
void printStudents(const vector<Student>& students) {
    cout << "Список студентов:" << endl;
    for (const auto& student : students) {
        cout << "Фамилия: " << student.surname << ", Оценки: ";
        for (int grade : student.grades) {
            cout << grade << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int task2() {
    string defaultInputFilename = "files/lab12_task2_in.txt";
    string defaultOutputFilename = "files/lab12_task2_out.txt";

    string inputFilename, outputFilename;

    cout << "Введите название входного файла (Введите 0 чтобы использовать дефолтный files/lab12_task2_in.txt):" << endl;
    cin >> inputFilename;

    inputFilename = (inputFilename == "0") ? defaultInputFilename : "files/" + inputFilename;


    cout << "Введите название выходного файла  (Введите 0 чтобы использовать дефолтный files/lab12_task2_out.txt): " << endl;
    cin >> outputFilename;


    outputFilename = (outputFilename == "0") ? defaultOutputFilename : "files/" + outputFilename;
    
    vector<Student> students;
    readStudents(inputFilename, students);
    
    printStudents(students);

    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        cout << "Ошибка открытия файла для записи." << endl;
        return 1;
    }

    printStatistics(students, outputFile);
    printUnsuccessfulStudents(students, outputFile);

    cout << "Данные успешно обработаны и записаны в файл " << outputFilename << endl;

    outputFile.close();
    return 0;
}

int main(){
    task1();
    task2();
    return 0;
}