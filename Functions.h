#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <random>

const size_t MAX_SIZE = 100;

size_t InputSize();
int16_t SelectChoice();

template <typename T>
void FillArrayByKeyboard(T* array, size_t size) {
    std::cout << "Введите элементы массива:\n";
    for (size_t i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
}


template <typename T>
void FillArrayByRandom(T* array, size_t size, T min_value, T max_value) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <> dist(min_value, max_value);
    for (size_t i = 0; i < size; ++i) {
        array[i] = dist(rd);
    }
}


void FillArrayByRandom(double*, size_t, double, double);


template <typename T>
void PrintArray(const T* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}


template <typename T>
void FindLocalMinima(T* array, size_t size) {
    std::cout << "Номера локальных минимумов массива:\n";
    for (size_t i = 1; i < size; ++i) {
        if (array[i] <= array[i - 1] && i < size - 1 && array[i] <= array[i + 1]) {
            std::cout << ++i << std::endl;
        }
    }
}


template <typename T>
int16_t IndexFirstMinimalElement(T* array, size_t size) {
    size_t min_index = 0;
    T min_value{ array[min_index] };
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i; j < size; ++j) {
            if (array[j] < min_value) {
                min_value = array[j];
                min_index = j;
            }
        }
    }
    return min_index;
}


template <typename T>
int16_t IndexLastMaximalElement(T* array, size_t size) {
    size_t max_index = 0;
    T max_value{ array[max_index] };
    for (size_t i = size; i > 0; --i) {
        for (size_t j = i; j > 0; --j) {
            if (array[j] > max_value) {
                max_value = array[j];
                max_index = j;
            }
        }
    }
    return max_index;
}


template <typename T>
T SumAfterFirstMinimalElement(T * array, size_t size) {
    T sum{};
    for (size_t i = IndexFirstMinimalElement(array, size) + 1; i < size; ++i) {
        sum += array[i];
    }
    return sum;
}

template <typename T>
T CompositionBetwenFirstMinAndLasnMaxElement(T* array, size_t size) {
    T sum{1};
    for (size_t i = IndexFirstMinimalElement(array, size) + 1; i < IndexLastMaximalElement(array, size); ++i) {
        sum *= array[i];
    }
    return sum;
}


template <typename T>
std::vector <T> DelliteDuplicateElements(T* array, size_t size) {
    std::vector<T> vec;
    for (size_t i = 0; i <= size; ++i) {
        for (size_t j = i + 1; j <= size; ++j) {
            if (array[i] != array[j]) {
                vec.push_back(array[i]);
                break;
                }
            ++i;
            }
        }
    return vec;
}

template <typename T>
void PrintElementsOfVector(const std::vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
}

template <typename T>
void BubbleSortingArray(T* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (array[i] > array[j]) {
                std::swap(array[i], array[j]);
            }
       }
    }
}


template <typename T>
void SortingElementsInArrayDependingOnTheSign(T* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (array[i] > 0 && array[j] > 0 && array[i] > array[j]) {
                std::swap(array[i], array[j]);
            }
        }
    }

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (array[i] < 0 && array[j] < 0 && array[i] < array[j]) {
                std::swap(array[i], array[j]);
            }
        }
    }
}

template <typename T>
void SortingElementsWithParityNumsInArray(T* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if ((i + 1) % 2 == 0) {
            for (size_t j = i + 1; j < size; ++j) {
                if (((j + 1) % 2 == 0) && array[i] < array[j]) {
                    std::swap(array[i], array[j]);
                }
            }
        }
    }
}



template <typename T>
void CallFunctions(T* array, size_t size) {
    PrintArray(array, size);
    std::cout << "Выполнение функций для варианта:\n";
    std::cout << "[1] - 11 вариант\n";
    std::cout << "[2] - 15 вариант\n";
    int16_t choice{ SelectChoice() };
    switch (choice) {
    case 1:
        FindLocalMinima(array, size);
        std::cout << "Сумма элементов после первого минимального = " << SumAfterFirstMinimalElement(array, size) << std::endl;
        SortingElementsInArrayDependingOnTheSign(array, size);
        std::cout << "Массив после сортировки (все положительные элементы массива расположить по возрастанию...):\n";
        PrintArray(array, size);
        break;
    case 2:
        BubbleSortingArray(array, size);
        std::cout << "Упорядоченный массив: ";
        PrintArray(array, size); 
        std::cout << std::endl;
        std::cout << "Строго возрастающий массив: ";
        PrintElementsOfVector(DelliteDuplicateElements(array, size));
        std::cout << std::endl;
        std::cout << "Произведение элементов между первым минимальным и последним максимальным = " << CompositionBetwenFirstMinAndLasnMaxElement(array, size) << std::endl;
        SortingElementsWithParityNumsInArray(array, size);
        std::cout << "Массив после сортировки (элементы массива c четными номерами расположить по возрастанию...):\n";
        PrintArray(array, size);
        break;
    }
}


template <typename T>
void ActionsWithArray(T* array, size_t size) {
    std::cout << "Способ ввода элементов:\n";
    std::cout << "[1] - С клавиатуры\n";
    std::cout << "[2] - Случайные числа\n";
    int16_t choice{ SelectChoice() };
    switch (choice) {
    case 1:
        FillArrayByKeyboard(array, size);
        CallFunctions(array, size);
    case 2:
        T min_value{};
        T max_value{};
        std::cout << "Введите минимальное значение:\n";
        std::cin >> min_value;
        std::cout << "Введите максимальное значение:\n";
        std::cin >> max_value;
        if (std::cin.fail()) {
            throw std::invalid_argument("Ошибка: неверно заданный параметр");
        }
        if (max_value < min_value) {
            throw std::invalid_argument("Неверно заданные значения");
        }
        FillArrayByRandom(array, size, min_value, max_value);
        CallFunctions(array, size);
    }
}


#endif FUNCTIONS_H_
