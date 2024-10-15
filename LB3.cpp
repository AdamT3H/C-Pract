#include <iostream>
#include <string.h>

int main() {
    char teams[200] = "Динамо, Шахтар, Карпати, Зоря, Ворскла";
    std::cout << "Рядок до заміни: " << teams << std::endl;
    char shachtar[] = "Шахтар";
    char dunamo[] = "Динамо";
    char* find_shachtar = strstr(teams, shachtar);
    char* find_dunamo = strstr(teams, dunamo);

    if (find_shachtar && find_dunamo) {
        char temp[100];
        strcpy(temp, shachtar);
        strncpy(find_shachtar, dunamo, strlen(dunamo));
        strncpy(find_dunamo, temp, strlen(temp));
    }

    std::cout << "Рядок після заміни: " << teams << std::endl;
    return 0;
}
