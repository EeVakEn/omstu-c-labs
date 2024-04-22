#include "matrix_operations.h"
#include <iostream>

using namespace std;

double trace(const vector<vector<double>>& matrix) {
    double sum = 0;
    for (int i = 0; i < (int)matrix.size(); ++i) {
        sum += matrix[i][i]; // Диагональные элементы
    }
    return sum;
}

void printMatrix(const vector<vector<double>>& matrix) {
    for (int i = 0; i < (int)matrix.size(); ++i) {
        for (int j = 0; j < (int)matrix.size(); ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}