#include <iostream>
#include <cstdlib>  
#include <ctime>  

const size_t MAX_SIZE = 100;

// ������� �������� ����� ������� �������
size_t InputSize() {
    size_t size;
    do {
        std::cout << "������� ������ ������a: \n";
        std::cin >> size;
        if (size < 1 || size > MAX_SIZE) {
            std::cout << "������ ������ ���� � �������� �� 1 �� " << MAX_SIZE << ".\n";
        }
    } while (size < 1 || size > MAX_SIZE);
    return size;
}

// ������� ���������� ������� � ����������
template <typename T>
void FillArrayByKeyboard(T* array, size_t size) {
    std::cout << "������� �������� �������:\n";
    for (size_t i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
}

// ������� ���������� ������� ���������� �������
template <typename T>
void FillArrayByRandom(T* array, size_t size, T min_value, T max_value) {
    srand(static_cast<unsigned>(time(0)));
    for (size_t i = 0; i < size; ++i) {
        array[i] = static_cast<T>(min_value + rand() % (max_value - min_value + 1));
    }
}

// ������� ������ �������
template <typename T>
void PrintArray(const T* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

// ���������� ��� ������������ �������
void StaticArray() {
    int array[MAX_SIZE];
    size_t size = InputSize();

    std::cout << "�������� ������ ���������� �������:\n";
    std::cout << "[1] - � ����������\n";
    std::cout << "[2] - ��������� �����\n";
    std::string choice{};
    std::cin >> choice;

    if (choice == "1") {
        FillArrayByKeyboard(array, size);
    }
    else if (choice == "2") {
        int min_value, max_value;
        std::cout << "������� ����������� ��������:\n";
        std::cin >> min_value;
        std::cout << "������� ������������ ��������:\n";
        std::cin >> max_value;
        FillArrayByRandom(array, size, min_value, max_value);
    }
    else {
        std::cout << "�������� �����!\n";
        return;
    }

    PrintArray(array, size);
}

// ���������� ��� ������������� �������
void DynamicArray() {
    size_t size = InputSize();
    int* array = new int[size]; 

    std::cout << "�������� ������ ���������� �������:\n";
    std::cout << "[1] - � ����������\n";
    std::cout << "[2] - ��������� �����\n";
    std::string choice{};
    std::cin >> choice;

    if (choice == "1") {
        FillArrayByKeyboard(array, size);
    }
    else if (choice == "2") {
        int min_value, max_value;
        std::cout << "������� ����������� ��������: ";
        std::cin >> min_value;
        std::cout << "������� ������������ ��������: ";
        std::cin >> max_value;
        FillArrayByRandom(array, size, min_value, max_value);
    }
    else {
        std::cout << "�������� �����!\n";
        delete[] array;
        return;
    }

    PrintArray(array, size);
    delete[] array;
}

int main() {
    setlocale(LC_ALL, ".1251");
    std::cout << "�������� ��� �������:\n";
    std::cout << "[1] - ����������� ������\n";
    std::cout << "[2] - ������������ ������\n";
    std::string choice{};
    std::cin >> choice;

    if (choice == "1") {
        StaticArray();
    }
    else if (choice == "2") {
        DynamicArray();
    }
    else {
        std::cout << "�������� �����!\n";
    }

    return 0;
}
