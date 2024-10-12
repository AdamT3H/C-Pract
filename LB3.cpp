#include <iostream>
#include <cstring>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int main() {
    setlocale(LC_ALL, "Ukr");
    
    int index_shakhtar = -1; 
    int index_dynamo = -1;

    const char* teams[] = { "Динамо", "Шахтар", "Ворскла", "Карпати", "Зоря" };

    const int SIZE = ARRAY_SIZE(teams);

    std::cout << "Початковий список команд:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << teams[i] << std::endl;
    }

    for (int i = 0; i < SIZE; i++) {
        if (std::strcmp(teams[i], "Шахтар") == 0) {
            index_shakhtar = i;
        }
        if (std::strcmp(teams[i], "Динамо") == 0) {
            index_dynamo = i;
        }
    }

    if (index_shakhtar != -1 && index_dynamo != -1) {
        const char* temp = teams[index_shakhtar];
        teams[index_shakhtar] = teams[index_dynamo];
        teams[index_dynamo] = temp;
    } else {
        std::cout << "Не знайдено одну або обидві команди." << std::endl;
        return 1;
    }

    std::cout << "\nСписок після обміну:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << teams[i] << std::endl;
    }

    return 0;
}