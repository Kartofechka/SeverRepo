#include <iostream>
#include <cstdlib>  
#include <ctime>  

const size_t MAX_SIZE = 100;

// Функция проверки ввода размера массива
size_t InputSize() {
    size_t size;
    do {
        std::cout << "Введите размер массивa: \n";
        std::cin >> size;
        if (size < 1 || size > MAX_SIZE) {
            std::cout << "Размер должен быть в пределах от 1 до " << MAX_SIZE << ".\n";
        }
    } while (size < 1 || size > MAX_SIZE);
    return size;
}

// Функция заполнения массива с клавиатуры
template <typename T>
void FillArrayByKeyboard(T* array, size_t size) {
    std::cout << "Введите элементы массива:\n";
    for (size_t i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
}

// Функция заполнения массива случайными числами
template <typename T>
void FillArrayByRandom(T* array, size_t size, T min_value, T max_value) {
    srand(static_cast<unsigned>(time(0)));
    for (size_t i = 0; i < size; ++i) {
        array[i] = static_cast<T>(min_value + rand() % (max_value - min_value + 1));
    }
}

// Функция вывода массива
template <typename T>
void PrintArray(const T* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

// Реализация для статического массива
void StaticArray() {
    int array[MAX_SIZE];
    size_t size = InputSize();

    std::cout << "Выберите способ заполнения массива:\n";
    std::cout << "[1] - С клавиатуры\n";
    std::cout << "[2] - Случайные числа\n";
    std::string choice{};
    std::cin >> choice;

    if (choice == "1") {
        FillArrayByKeyboard(array, size);
    }
    else if (choice == "2") {
        int min_value, max_value;
        std::cout << "Введите минимальное значение:\n";
        std::cin >> min_value;
        std::cout << "Введите максимальное значение:\n";
        std::cin >> max_value;
        FillArrayByRandom(array, size, min_value, max_value);
    }
    else {
        std::cout << "Неверный выбор!\n";
        return;
    }

    PrintArray(array, size);
}

// Реализация для динамического массива
void DynamicArray() {
    size_t size = InputSize();
    int* array = new int[size]; 

    std::cout << "Выберите способ заполнения массива:\n";
    std::cout << "[1] - С клавиатуры\n";
    std::cout << "[2] - Случайные числа\n";
    std::string choice{};
    std::cin >> choice;

    if (choice == "1") {
        FillArrayByKeyboard(array, size);
    }
    else if (choice == "2") {
        int min_value, max_value;
        std::cout << "Введите минимальное значение: ";
        std::cin >> min_value;
        std::cout << "Введите максимальное значение: ";
        std::cin >> max_value;
        FillArrayByRandom(array, size, min_value, max_value);
    }
    else {
        std::cout << "Неверный выбор!\n";
        delete[] array;
        return;
    }

    PrintArray(array, size);
    delete[] array;
}

int main() {
    setlocale(LC_ALL, ".1251");
    std::cout << "Выберите тип массива:\n";
    std::cout << "[1] - Статический массив\n";
    std::cout << "[2] - Динамический массив\n";
    std::string choice{};
    std::cin >> choice;

    if (choice == "1") {
        StaticArray();
    }
    else if (choice == "2") {
        DynamicArray();
    }
    else {
        std::cout << "Неверный выбор!\n";
    }

    return 0;
}
