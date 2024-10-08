#include <iostream>
#include <algorithm>
#include <string> 
#include <string.h> 

/* ЗАВДАННЯ: вивисти список українських команд, та поміняти місцями Динамо та Шахар*/

/*
[
    "Динамо",
    "Дніпро-1",
    "Зоря",
    "Ворскла",
    "Олександрія",
    "Колос",
    "Металіст",
    "Рух",
    "ЛНЗ",
    "Оболонь",
    "Верес",
    "Шахтар"
];

*/


int main(){
    setlocale(LC_ALL, "Ukr");
    
    int index_of_name1 = -111;
    int index_of_name2 = -111; // чому я тут не можу використати extern, точніше як його тут коректно використати
    
    const char* name1 = "Динамо";
    const char* name2 = "Шахтар";
    
    const char* list_of_all_clubs[] = {    
        "Динамо",
        "Шахтар",
        "Дніпро-1",
        "Зоря",
        "Ворскла",
        "Олександрія",
        "Колос",
        "Металіст",
        "Рух",
        "ЛНЗ",
        "Оболонь",
        "Верес",
    };
    
    int size_of_list = sizeof(list_of_all_clubs) / sizeof(list_of_all_clubs[0]);
    
    std::cout<< "Лист номер один:" << '\n' << std::endl;
    
    for (int i = 0; i < size_of_list; i++){
            std::cout<< list_of_all_clubs[i] << std::endl;
            
        if (strcmp(list_of_all_clubs[i], name1) == 0) {
            index_of_name1 = i;
        }

        if (strcmp(list_of_all_clubs[i], name2) == 0) {
            index_of_name2 = i;
        }
            
    };
    std::cout<< '\n' << std::endl;
    
    if (index_of_name1 != -111 && index_of_name2 != -111){
        list_of_all_clubs[index_of_name1] = name2;
        list_of_all_clubs[index_of_name2] = name1;
    } else {
        std::cout << "Один або обидва клуби не знайдено." << std::endl;
    }
    
        std::cout<< "Лист номер два:" << '\n' << std::endl;
    
    for (int i = 0; i < size_of_list; i++){
        std::cout<< list_of_all_clubs[i] << std::endl;
    };
    
    return 0;
}