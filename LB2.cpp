#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    
    int size_of_matrix = 3;
    
    int** matrix = new int*[size_of_matrix];
    for (int i = 0; i < size_of_matrix; i++){
        matrix[i] = new int[size_of_matrix];
    };
    
    for (int i=0; i < size_of_matrix; i++){
        for (int j = 0; j <size_of_matrix; j++){
            matrix[i][j] = std::rand()%21-10;
            std::cout<<matrix[i][j]<<"\t";
        };
        std::cout<<std::endl;
    };
    
    int* numbers = new int[size_of_matrix];

    int list_of_numbers[3] = {};
    
    for(int i =0; i< size_of_matrix; i++){
        numbers[i]=1;
        bool negative = false;
        
        for (int j = 0; j < size_of_matrix; j++){
            if(matrix[i][j] < 0){
                numbers[i] *= matrix[i][j];
                negative = true;
            }
        }
        
        if (!negative){
            numbers[i]=0;
        }

        list_of_numbers[i] = numbers[i];
        
        std::cout << "Добуток від'ємних елементів у рядку під номером  " << i+ 1<< ": " << numbers[i] << std::endl;
    }

    std::cout << "Список чисел: ";

    for (int i = 0; i < size_of_matrix; i++) {
        std::cout << list_of_numbers[i]<< " ";
    };
    
    return 0;
}