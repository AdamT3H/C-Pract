#include <iostream>

void outputMatr(int** matr, int n, int m) {
    for (int i = 0; i < n; ++i, std::cout << std::endl) {
        for (int j = 0; j < m; ++j) {
            std::cout << matr[i][j] << "\t";
        }
    }
    std::cout << std::endl;
}

void fillStaticMatr(int** matr, int n, int m) {
    int staticValues[3][3] = {
        {10, -2, 3},
        {2, -10, 9},
        {3, -4, -3}
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matr[i][j] = staticValues[i][j];
        }
    }
}

int findMaxOfRowMins(int** matr, int n, int m) {
    int rowMins[n];

    for (int i = 0; i < n; ++i) {
        int minVal = matr[i][0];
        for (int j = 1; j < m; ++j) {
            if (matr[i][j] < minVal) {
                minVal = matr[i][j];
            }
        }
        rowMins[i] = minVal;
    }

    int maxOfMins = rowMins[0];
    for (int i = 1; i < n; ++i) {
        if (rowMins[i] > maxOfMins) {
            maxOfMins = rowMins[i];
        }
    }

    return maxOfMins;
}

int main() {
    const int n = 3, m = 3;

    int** mas2d = new int*[n];
    for (int i = 0; i < n; ++i) { //виділення памяті для цієї матриці
        mas2d[i] = new int[m];
    }

    fillStaticMatr(mas2d, n, m);
    
    outputMatr(mas2d, n, m);

    int maxOfMins = findMaxOfRowMins(mas2d, n, m);
    std::cout << "максимум з мінімумів = " << maxOfMins << std::endl;

    return 0;
}
