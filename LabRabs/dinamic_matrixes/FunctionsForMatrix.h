#ifndef FUNCTIONSFORMATRIX_H_
#define FUNCTIONSFORMATRIX_H_
#include <random>
#include <iomanip>

const size_t MAX_SIZE = 100;

size_t InputSize();
int16_t SelectChoice();

template <typename T>
T InputSize(T** matrix) {
    T size{};
    std::cout << "������� ������: \n";
    std::cin >> size;
    if (std::cin.fail()) {
        throw std::invalid_argument("������: ������� �������� ��������, �������� �������� ��������");
    }
    return size;
}


template <typename T>
T** MakeMatrix(T type_indificator, size_t rows, size_t cols) {
    T** matrix = new T * [rows];
    for (size_t i{}; i < rows; ++i) {
        matrix[i] = new T[cols]{ 0 };
    }
    return matrix;
}


template <typename T>
void OutPutMatrix(T** matrix, size_t rows, size_t cols) {
    for (size_t i{}; i < rows; ++i) {
        for (size_t j{}; j < cols; ++j) {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


template <typename T>
void DeliteMatrix(T** matrix, size_t rows) {
    for (size_t i{}; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


template <typename T>
void FillMatrixByKeyboard(T* matrix, size_t rows, size_t cols) {
    std::cout << "������� �������� ������� (���������� ���������� ���������):\n";
    for (size_t i{}; i < rows; ++i) {
        for (size_t j{}; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}


template <typename T>
void FillMatrixByRandom(T** matrix, size_t rows, size_t cols, T min_value, T max_value) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <> dist(min_value, max_value);
    for (size_t i{}; i < rows; ++i) {
        for (size_t j{}; j < cols; ++j) {
            matrix[i][j] = dist(rd);
        }
    }
}

void FillMatrixByRandom(double**, size_t, size_t, double, double);


template <typename T>
int16_t IndexFirstMinimalRow(T** matrix, size_t rows, size_t cols) {
    int16_t min_row = 0;
    T min_value = matrix[0][0];
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (matrix[i][j] < min_value) {
                min_value = matrix[i][j];
                min_row = i;
            }
        }
    }
    return min_row;
}


template <typename T>
int16_t IndexFirstRowWithZero(T** matrix, size_t rows, size_t cols) {
    int16_t min_row = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                min_row = i;
                return min_row;
            }
        }
    }
    return -1;
}


template <typename T>
int32_t MeaningOfMinimalKForWhickAllElementsInRowAreLower(T** matrix, size_t rows, size_t cols) {
    T minimal_from_maximals_elements{};
    bool first_checking = true;
    for (size_t i = 0; i < rows; ++i) {
        T maximal_element_in_row{ matrix[i][0] };
        for (size_t j = 0; j < cols; ++j) {
           if (matrix[i][j] > maximal_element_in_row) {
              maximal_element_in_row = matrix[i][j];
           }
        }
        if (first_checking == true) {
            minimal_from_maximals_elements = maximal_element_in_row;
            first_checking = false;
        }
        if (maximal_element_in_row < minimal_from_maximals_elements) {
           minimal_from_maximals_elements = maximal_element_in_row;
        }
    }
    return ++minimal_from_maximals_elements;
}



template <typename T>
int16_t IndexFirstMaximalColumn(T** matrix, size_t rows, size_t cols) {
    size_t max_col = 0;
    T max_value = matrix[0][0];
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (matrix[i][j] > max_value) {
                max_value = matrix[i][j];
                max_col = j;
            }
        }
    }
    return max_col;
}


template <typename T>
int16_t IndexFirstMinimalColumn(T** matrix, size_t rows, size_t cols) {
    size_t min_col = 0;
    T min_value = matrix[0][0];
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (matrix[i][j] < min_value) {
                min_value = matrix[i][j];
                min_col = j;
            }
        }
    }
    return min_col;
}


template <typename T>
T ScalarCompositionOfColumnAndRow (T** matrix, size_t rows, size_t cols, size_t min_row, size_t max_col) {
    T result{};
    for (size_t i = 0, j = 0; i < rows; ++i, ++j) {
        result += matrix[min_row][i] * matrix[j][max_col];
    }
    return result;
}


template <typename T>
void FindingSaddlePointsOfMatrix(T** matrix, size_t rows, size_t cols) {
    bool is_saddle_point = true;
    for (size_t i = 0; i < rows; ++i) {
        T min_value_of_row = matrix[i][0];
        size_t column_index = 0;
        for (size_t j = 1; j < cols; ++j) {
            if (matrix[i][j] < min_value_of_row) {
                min_value_of_row = matrix[i][j];
                column_index = j;
            }
        }
        is_saddle_point = true;
        for (size_t k = 0; k < rows; ++k) {
            if (matrix[k][column_index] > min_value_of_row) {
                is_saddle_point = false;
                break;
            }
        }
        if (is_saddle_point) {
            std::cout << "[ " << ++i << " , " << ++column_index << " ] " << std::endl;
        }
    }
    if (!is_saddle_point){
        std::cout << "� ������� ��� �������� �����.\n";
    }
}


template <typename T>
void ActionsWithMatrix(T** matrix, size_t rows, size_t cols) {
    std::cout << "������ ���������� �������:\n";
    std::cout << "[1] - � ����������\n";
    std::cout << "[2] - ��������� ����������\n";
    int16_t choice_type_of_matrix{ SelectChoice() };
    switch (choice_type_of_matrix) {
    case 1:
       FillMatrixByKeyboard(matrix, rows, cols);
       break;
    case 2:
       std::cout << "������� ����������� ��������:\n";
       T min_value{ InputSize(matrix) };
       std::cout << "������� �a���������� ��������:\n";
       T max_value{ InputSize(matrix) };
       FillMatrixByRandom(matrix, rows, cols, min_value, max_value);
       break;
    }
    OutPutMatrix(matrix, rows, cols);
    if (rows = cols) {
             std::cout << "��������� ������������ ������ � ���������� ��������� ������� � ������� � ������������ ��������� ������� = " << ScalarCompositionOfColumnAndRow(matrix, rows, cols, IndexFirstMinimalRow(matrix, rows, cols), IndexFirstMaximalColumn(matrix, rows, cols)) << std::endl;
             std::cout << "���������� ����� ����� �, ��� �������� ���� �� � ����� ������ ��� �������� ����� ������ ��� = " << MeaningOfMinimalKForWhickAllElementsInRowAreLower(matrix, rows, cols) << std::endl;     
    }
    else {
        std::cout << "������� �� ����������\n";
    }
    int32_t index_or_row_with_zero { 1 + IndexFirstRowWithZero(matrix, rows, cols) };
    if (index_or_row_with_zero == 0) {
        std::cout << "� ������� ��� ������, � ������� ���������� ���� �� ���� ����\n";
    }
    else {
        std::cout << "����� ������, � ������� ���������� ���� �� ���� ����: " << index_or_row_with_zero << std::endl;
    }
    std::cout << "���������� �������� �����: ";
    FindingSaddlePointsOfMatrix(matrix, rows, cols);
    std::cout << std::endl;

}

#endif


// a b c d
// e f g h          ab + bf + cj + dn
// i j k l           
// m n o p