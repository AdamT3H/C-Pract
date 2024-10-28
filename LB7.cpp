#include <iostream>
#include <vector>
#include "LB7_solutions_macros.h"

int main() {
    double mas[N];
	double new_mas[N];
    double smallest;
    std::vector<int> indexes;
    int count = 0;
	int a = 0;
	int b = 0;

 	INPUT_ARRAY(mas); 
    LIST(mas); 
    FIND_SMALLEST(mas, smallest);
	std::cout << "Найменше число: " << smallest << std::endl;
    BETWEN_MINUSES_INDEXES(mas, indexes, count);
 	BETWEN_MINUSES(mas, indexes, count);
	NEW_LIST(mas, new_mas);

    return 0;
}
