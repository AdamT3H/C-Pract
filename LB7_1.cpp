#include <iostream>

struct TRAIN{
    char destination[30];
    int number;
    char time[6];
};

int main() {
    TRAIN train1 = {"Київ", 1234, "12:30"};
    std::cout << "Пункт презначення: " << train1.destination << std::endl;
    std::cout << "Номер потягу: " << train1.number << std::endl;
    std::cout << "Час відправлення: " << train1.time << std::endl;
    return 0;
}