#ifndef LB7_SOLUTIONS_MACROS_H
#define LB7_SOLUTIONS_MACROS_H

#include <iostream>
#include <list>
#include <vector>
#include <cmath>

#define N 10

#define INPUT_ARRAY(mas) { \
    std::cout << "Введіть " << N << " елементів масиву: "; \
    for (int i = 0; i < N; i++) { \
        std::cin >> mas[i]; \
    } \
}

#define LIST(mas) { \
    for(int i = 0; i < N; i++) { \
        std::cout << mas[i] << std::endl; \
    } \
}

#define FIND_SMALLEST(mas, sm) { \
    sm = mas[0]; \
    for (int i = 1; i < N; i++) { \
        if (mas[i] < sm) { \
            sm = mas[i]; \
			count += 1; \
        } \
    } \
	std::cout << "COUNT: " << count << std::endl; \
}

#define BETWEN_MINUSES_INDEXES(mas, indexes, count) { \
	for (int i = 0; i < N; i++) { \
        if (mas[i] < 0) { \
            indexes.push_back(i);\
        } \
    } \
	std::cout << "Позиції чисел з мінусами" << std::endl; \
    for (std::vector<int>::iterator it = indexes.begin(); it != indexes.end(); ++it) { \
        std::cout << *it << std::endl; \
    }; \
}

#define BETWEN_MINUSES(mas, indexes, count){ \
	for (int i = 0; i < count - 1; i++) { \
		double sum = 0; \
		a = indexes[i]; \
		b = indexes[i + 1]; \
		for (int j = a + 1; j < b; j++) { \
			sum += mas[j]; \
			std::cout << "Номер що додадуть до суми: " << mas[j] << std::endl; \
		}; \
		std::cout << "Сума між відємними: " << sum << std::endl; \
	}; \
}

#define NEW_LIST(mas, new_mas){ \
    int new_mas_index = 0; \
    for (int i = 0; i < N; i++) { \
        if (fabs(mas[i]) < 1) { \
            new_mas[new_mas_index++] = mas[i]; \
        } \
    } \
    for (int i = 0; i < N; i++) { \
        if (fabs(mas[i]) > 1) { \
            new_mas[new_mas_index++] = mas[i]; \
        } \
    } \
    std::cout << "Новий масив: " << std::endl; \
    for (int i = 0; i < N; i++) { \
        std::cout << new_mas[i] << std::endl; \
    } \
 \
}

#endif // LB7_SOLUTIONS_MACROS_H