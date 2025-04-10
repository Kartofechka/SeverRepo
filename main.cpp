#include <iostream>
#include <cstdlib>  
#include <ctime>  
#include <random>
#include "Functions.h"
#include <algorithm>
#include <vector>


int main() {
    try {
        setlocale(LC_ALL, ".1251");
        std::cout << "Тип массива:\n";
        std::cout << "[1] - Статический массив\n";
        std::cout << "[2] - Динамический массив\n";
        int16_t choice_type_of_array{ 10 * SelectChoice() };
        std::cout << "Тип элементов:\n";
        std::cout << "[1] - Целочисленный массив\n";
        std::cout << "[2] - Вещественный массив\n";
        choice_type_of_array += SelectChoice();
        switch (choice_type_of_array) {
        case 11: {
            int32_t array[MAX_SIZE];
            size_t size{ InputSize() };
            ActionsWithArray(array, size);
            break;
        }
        case 12: {
            double array[MAX_SIZE];
            size_t size{ InputSize() };
            ActionsWithArray(array, size);
            break;
        }
        case 21: {
            size_t size{ InputSize() };
            int* array = new int[size];
            ActionsWithArray(array, size);
            delete[] array;
            break;
        }
        case 22: {
            size_t size{ InputSize() };
            double* array = new double[size];
            ActionsWithArray(array, size);
            delete[] array;
            break;
        }
        return 0;
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}