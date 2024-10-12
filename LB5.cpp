#include <iostream>

void outputMatr(int* matr, int n, int m) {
    for (int i = 0; i < n; ++i, std::cout << std::endl) {
        for (int j = 0; j < m; ++j) {
            std::cout << matr[i * m + j] << "\t";
        }
    }
    std::cout << std::endl;
}

void fillStaticMatr(int* matr, int n, int m) {
    int staticValues[3][3] = {
        {10, -2, 3},
        {2, -10, 9},
        {3, -4, -3}
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matr[i * m + j] = staticValues[i][j];
        }
    }
}

int findMaxOfRowMins(int* matr, int n, int m) {
    int rowMins[n];

    for (int i = 0; i < n; ++i) {
        int minVal = matr[i * m];
        for (int j = 1; j < m; ++j) {
            if (matr[i * m + j] < minVal) {
                minVal = matr[i * m + j];
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
    int mas2d[n][m];

    fillStaticMatr(&mas2d[0][0], n, m);
    
    outputMatr(&mas2d[0][0], n, m);

    int maxOfMins = findMaxOfRowMins(&mas2d[0][0], n, m);
    std::cout << "Maximum of row minimums = " << maxOfMins << std::endl;

    return 0;
}
