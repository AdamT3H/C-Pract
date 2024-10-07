#include <iostream>
#include <list>

const int ROWS = 3;
const int COLS = 3;
int BigestOfSmollest = 0;

std::list<int> SmollestOfRows;

void printMatrix(int matrix[ROWS][COLS]) {
    std::cout << "Матриця:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void findRowMinima(int matrix[ROWS][COLS]){
  for (int i = 0; i < ROWS; i++) {
    int smollest = 100; 
    for (int j = 1; j < COLS; j++) {
      if (matrix[i][j] < smollest) {
          smollest = matrix[i][j];
      }
    }
    SmollestOfRows.push_back(smollest);
  }
}

void findBigestOutOfSmollest(){
  for (std::list<int>::iterator it = SmollestOfRows.begin(); it != SmollestOfRows.end(); ++it) {
    if (*it > BigestOfSmollest){
          BigestOfSmollest = *it;
    }
  }
}

int main() {
    int matrix[ROWS][COLS] = {
        {3, 2, 1},
        {4, 5, 3},
        {7, 6, 5}
    };

    findRowMinima(matrix);
    findBigestOutOfSmollest();
    
    std::cout << "Найбільше значення, серед найменших значень, кожного рядка, є: " << BigestOfSmollest << std::endl;

    std::cout << "Найменші значення в кожному ряді:\n";
    for (std::list<int>::iterator it = SmollestOfRows.begin(); it != SmollestOfRows.end(); ++it) {
        std::cout << *it << std::endl;
    }

    printMatrix(matrix);

    return 0;
}