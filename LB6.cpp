// 17. Шляхом перестановки елементів квадратної матриці добитися того, щоб її
// максимальний елемент перебував в лівому верхньому кутку, наступний за величиною - в
// позиції (2,2), наступний за величиною - в позиції (3,3) і т. Д., Заповнивши таким чином всю
// головну діагональ.
#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void readFromFile(const char* inputFileName, int& n, int matrix[MAX_SIZE][MAX_SIZE]){
    std::ifstream inputFile(inputFileName);
    if (!inputFile){
        std::cerr << "Файл не відкрито" << std::endl;
        return;
    }

    inputFile >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> matrix[i][j];
        }
    }

    inputFile.close();
}

void writeToFile(const char* outputFileName, int& n, int matrix[MAX_SIZE][MAX_SIZE]){
    std::ofstream outputFile(outputFileName);

    if (!outputFile){
        std::cerr << "Файл не заповнено" << std::endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            outputFile << matrix[i][j] << " ";
        }
        outputFile << std::endl;
    }

    outputFile.close();
}

void exchangeMatrix(const char* outputFileName, int& n, int matrix[MAX_SIZE][MAX_SIZE]){

    int sorted[n * n];
    int index = 0;

    for (int i = 0; i < n; ++i) { // запис елементів в масив
        for (int j = 0; j < n; ++j) {
            sorted[index++] = matrix[i][j];
        }
    } 

    bubbleSort(sorted, n * n);
    int tempOldNumber = 0; //4
    int positionForIinMatrix = 0; //3
    int positionForJinMatrix = 0; //1


    for (int i = 0; i < n; ++i) {
        tempOldNumber = matrix[i][i]; // шукаємо число, якезнаходиться на першій позиції в головній діагоналі
        int bigestNumberInSortedList = sorted[n * n - 1 - i];

        for (int q = 0; q < n; ++q) {
            for (int j = 0; j < n; ++j) {
                if (matrix[q][j] == bigestNumberInSortedList){
                    positionForIinMatrix = q;
                    positionForJinMatrix = j;

                } // шукаємо позицію в матриці, найбільшого числа в матриці та забираємо це число з сортованого масиву
            } 
        }


        // міняємо число перше в діагоналі, на найбільше число, а замість найбільшого, ми ставимо число, яке стояло на діагоналі
        matrix[i][i] = bigestNumberInSortedList;
        matrix[positionForIinMatrix][positionForJinMatrix] = tempOldNumber;
    }

}



int main() {
    int n;
    int matrix[MAX_SIZE][MAX_SIZE];

    const char* inputFileName = "input.txt";
    const char* outputFileName = "output.txt";

    readFromFile(inputFileName, n, matrix);

    exchangeMatrix(inputFileName, n, matrix);

    if (n > 0) {
        writeToFile(outputFileName, n, matrix);
    }

    return 0;
}