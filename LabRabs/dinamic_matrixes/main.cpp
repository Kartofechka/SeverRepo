//7 13


#include <iostream>
#include "FunctionsForMatrix.h"
#include <cstdlib>  
#include <ctime>  
#include <algorithm>



int main() {
    try {
        setlocale(LC_ALL, ".1251");

        std::cout << "��� ���������:\n";
        std::cout << "[1] - ������������� ������\n";
        std::cout << "[2] - ������������ ������\n";
        int16_t choice_type_of_matrix{ SelectChoice() };
        std::cout << "������� ���-�� ����� �������:\n";
        size_t rows{ InputSize() };
        std::cout << "������� ���-�� �������� �������:\n";
        size_t cols{ InputSize() };
        switch (choice_type_of_matrix) {
        case 1: {
            int32_t** matrix = MakeMatrix(1, rows, cols);
            ActionsWithMatrix(matrix, rows, cols);
            DeliteMatrix(matrix, rows);
            break;
        }
        case 2: {
            double** matrix = MakeMatrix(1.0, rows, cols);
            ActionsWithMatrix(matrix, rows, cols);
            DeliteMatrix(matrix, rows);
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